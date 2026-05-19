#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

namespace {

constexpr const char* kCursorHome = "\x1b[H";
constexpr const char* kClearScreen = "\x1b[2J";
constexpr const char* kHideCursor = "\x1b[?25l";
constexpr const char* kShowCursor = "\x1b[?25h";
constexpr const char* kResetStyle = "\x1b[0m";
constexpr const char* kBlueBackgroundCyanText = "\x1b[44m\x1b[96m";

bool EnableAnsiProcessing() {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (handle == INVALID_HANDLE_VALUE || handle == nullptr) {
        return false;
    }

    DWORD mode = 0;
    if (GetConsoleMode(handle, &mode) == 0) {
        return false;
    }

    return SetConsoleMode(handle, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING) != 0;
}

std::pair<int, int> GetTerminalSize() {
    CONSOLE_SCREEN_BUFFER_INFO info{};
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    if (handle != INVALID_HANDLE_VALUE && handle != nullptr && GetConsoleScreenBufferInfo(handle, &info) != 0) {
        const int width = info.srWindow.Right - info.srWindow.Left + 1;
        const int height = info.srWindow.Bottom - info.srWindow.Top + 1;
        return {std::max(width, 4), std::max(height, 4)};
    }

    return {80, 24};
}

void PlaceCenteredText(std::vector<std::string>& lines, int row, const std::string& text) {
    if (row <= 0 || row >= static_cast<int>(lines.size()) - 1) {
        return;
    }

    std::string& line = lines[row];
    const int innerWidth = static_cast<int>(line.size()) - 2;
    const std::string trimmed = text.substr(0, static_cast<std::size_t>(innerWidth));
    const int start = 1 + std::max(0, (innerWidth - static_cast<int>(trimmed.size())) / 2);

    for (std::size_t index = 0; index < trimmed.size(); ++index) {
        line[static_cast<std::size_t>(start) + index] = trimmed[index];
    }
}

std::string BuildScreen(int width, int height, const std::string& caption, const std::string& body) {
    width = std::max(width, 4);
    height = std::max(height, 4);
    const int innerWidth = width - 2;

    std::vector<std::string> lines;
    lines.reserve(static_cast<std::size_t>(height));
    lines.emplace_back("+" + std::string(static_cast<std::size_t>(innerWidth), '-') + "+");

    for (int row = 0; row < height - 2; ++row) {
        lines.emplace_back("|" + std::string(static_cast<std::size_t>(innerWidth), ' ') + "|");
    }

    lines.emplace_back("+" + std::string(static_cast<std::size_t>(innerWidth), '-') + "+");

    PlaceCenteredText(lines, 1, caption);
    PlaceCenteredText(lines, height / 2, body);

    std::ostringstream screen;
    screen << kBlueBackgroundCyanText;
    for (std::size_t index = 0; index < lines.size(); ++index) {
        screen << lines[index];
        if (index + 1 < lines.size()) {
            screen << '\n';
        }
    }
    screen << kResetStyle;
    return screen.str();
}

std::string CurrentTimeString() {
    const auto now = std::chrono::system_clock::now();
    const std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    std::tm localTime{};
    localtime_s(&localTime, &currentTime);

    std::ostringstream output;
    output << std::put_time(&localTime, "%H:%M:%S");
    return output.str();
}

void RestoreConsole() {
    std::cout << kResetStyle << kShowCursor << kCursorHome;
    std::cout.flush();
}

BOOL WINAPI ConsoleHandler(DWORD signal) {
    switch (signal) {
        case CTRL_C_EVENT:
        case CTRL_BREAK_EVENT:
        case CTRL_CLOSE_EVENT:
        case CTRL_LOGOFF_EVENT:
        case CTRL_SHUTDOWN_EVENT:
            RestoreConsole();
            return FALSE;
        default:
            return FALSE;
    }
}

class ConsoleSession {
public:
    ConsoleSession() {
        EnableAnsiProcessing();
        SetConsoleCtrlHandler(ConsoleHandler, TRUE);
        std::cout << kClearScreen << kCursorHome << kHideCursor;
        std::cout.flush();
    }

    ~ConsoleSession() {
        RestoreConsole();
    }

    ConsoleSession(const ConsoleSession&) = delete;
    ConsoleSession& operator=(const ConsoleSession&) = delete;
};

}  // namespace

int main() {
    ConsoleSession consoleSession;
    std::pair<int, int> lastSize{-1, -1};

    while (true) {
        const auto [width, height] = GetTerminalSize();
        const std::string screen = BuildScreen(width, height, "TUI Demo", CurrentTimeString());

        const bool resized = lastSize.first != width || lastSize.second != height;
        std::cout << (resized ? std::string(kClearScreen) + kCursorHome : std::string(kCursorHome));
        std::cout << screen;
        std::cout.flush();

        lastSize = {width, height};

        const auto now = std::chrono::system_clock::now();
        const auto nextTick = std::chrono::time_point_cast<std::chrono::seconds>(now) + std::chrono::seconds(1);
        std::this_thread::sleep_until(nextTick);
    }
}