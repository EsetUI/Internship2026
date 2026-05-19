#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <thread>
#include <utility>
#include <vector>
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <iostream>
#include <fstream>
#include <ctime>
#include <format>
#include "json.hpp"

struct Question
{
    std::string question;
    std::vector<std::string> answers;
    int correctAnswer{};
    int timeout{};
    int difficulty{};
};

namespace {

    constexpr const char* kCursorHome = "\x1b[H";
    constexpr const char* kClearScreen = "\x1b[2J";
    constexpr const char* kHideCursor = "\x1b[?25l";
    constexpr const char* kShowCursor = "\x1b[?25h";
    constexpr const char* kResetStyle = "\x1b[0m";
    constexpr const char* kBlueBackgroundCyanText = "\x1b[44m\x1b[96m";
    constexpr const char* kCyanText = "\033[96m";
    constexpr const char* kGreenText = "\033[32m";
    constexpr const char* kRedText = "\033[31m";

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
            return { std::max(width, 4), std::max(height, 4) };
        }

        return { 80, 24 };
    }
    void FormatCenteredText(std::vector<std::string>& lines, int row, const std::string& text, std::string color) {
        if (row <= 0 || row >= static_cast<int>(lines.size()) - 1) {
            return;
        }
        const int innerWidth = static_cast<int>(lines[row].size()) - 2;
        lines[row] = "|" + color + std::format("{:^{}}", text, innerWidth) + kBlueBackgroundCyanText + "|";
    }

    void PlaceCenteredText(std::vector<std::string>& lines, int row, const std::string& text,std::string color) {
        if (row <= 0 || row >= static_cast<int>(lines.size()) - 1) {
            return;
        }
        
        std::string& line = lines[row];
        const int innerWidth = static_cast<int>(line.size()) - 2;
        const std::string trimmed = color + text.substr(0, static_cast<std::size_t>(innerWidth)) + kBlueBackgroundCyanText;
        const int start = 1 + std::max(0, (innerWidth - static_cast<int>(trimmed.size())) / 2);

        for (std::size_t index = 0; index < trimmed.size(); ++index) {
            line[static_cast<std::size_t>(start) + index] = trimmed[index];
        }
    }

    std::string BuildScreen(int width, int height, const Question &question, int answer, bool onTime) {
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
        size_t size = question.answers.size();
        FormatCenteredText(lines, 1, question.question, "");
        if (height > height / 2 + size) {
            for (int i = 0; i < size;i++) {
                if (i == answer && answer != question.correctAnswer) {
                    FormatCenteredText(lines, height / 2 + i, std::format("{}: {}", i + 1, question.answers[i]), kRedText);
                }
                else if (i == question.correctAnswer && answer != -1) {
                    FormatCenteredText(lines, height / 2 + i, std::format("{}: {}", i + 1, question.answers[i]), kGreenText);
                }
                else {
                    FormatCenteredText(lines, height / 2 + i, std::format("{}: {}", i + 1, question.answers[i]), "");
                }
            }
            if (!onTime) {
                FormatCenteredText(lines, height / 2 + size, std::format("This question was not answered in time"), kRedText);
            }
        }
        
        

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


class QuestionManager {
    std::vector<Question> m_questions;
    int size{};
public:
    QuestionManager() = default;
    ~QuestionManager() = default;

    int get_size() { return size; }
    Question get_random_question();

   
    bool load(const std::string& path);
    void clean();
};

Question QuestionManager::get_random_question() {
    if (size <= 0) return {};
    size_t rnd_index = rand() % size;
    Question temp = m_questions[rnd_index];
    std::swap(m_questions[rnd_index], m_questions[size-1]);
    m_questions.pop_back();
    size--;
    return temp;
}

void QuestionManager::clean() {
    m_questions.clear();
    m_questions.shrink_to_fit();
}

bool QuestionManager::load(const std::string& path) {
    clean();
    std::ifstream fin(path);
    if (!fin) return false;
    nlohmann::json data;
    try {
        fin >> data;
    }
    catch (const nlohmann::json::parse_error& e)
    {
        // output exception information
        std::cout << "message: " << e.what() << '\n'
            << "exception id: " << e.id << '\n'
            << "byte position of error: " << e.byte << std::endl;
        return false;
    }
    auto questions = data["questions"];
    size = questions.size();
    m_questions.reserve(size);
    Question temp;
    for (auto question : questions) {
        temp.question = question["question"];
        temp.answers = question["answers"];
        temp.correctAnswer = question["correctanswer"];
        temp.difficulty = question["difficulty"];
        temp.timeout = question["timeout"];
        m_questions.push_back(temp);
    }
    return true;
}

int get_valid_input(int);

int main() {
    QuestionManager manager;
    manager.load("quiz.json");

    ConsoleSession consoleSession;
    std::pair<int, int> lastSize{ -1, -1 };
    int question_count = manager.get_size();
    int correct_count{};
    int answer{};
    bool highlight = false;
    std::chrono::system_clock::time_point before;
    Question current;
    bool on_time = true;
    while (true) {
        const auto [width, height] = GetTerminalSize();
        if (!highlight) {
            current = manager.get_random_question();
        }
        if (current.question.empty()) {
            current.question = std::format("{}/{} you got {:.2f}%", correct_count, question_count, question_count != 0? correct_count/static_cast<double>(question_count)*100 : 0);
        }
        before = std::chrono::system_clock::now();
        
        
        const std::string screen = BuildScreen(width, height,current,highlight? answer-1 : -1,on_time);
        const bool resized = lastSize.first != width || lastSize.second != height;
        std::cout << (resized ? std::string(kClearScreen) + kCursorHome : std::string(kCursorHome));
        std::cout << screen;
        std::cout.flush();

        if (!highlight) {
            answer = get_valid_input(current.answers.size());
            auto after = std::chrono::system_clock::now();
            auto diff = std::chrono::duration_cast<std::chrono::seconds>(after - before);

            if (diff.count() > 10) {
                on_time = false;
            }
            else {
                if (answer - 1 == current.correctAnswer) {
                    correct_count++;
                }
                on_time = true;
            }
        }
        else {
            //const auto now = std::chrono::system_clock::now();
            //const auto nextTick = std::chrono::time_point_cast<std::chrono::seconds>(now) + std::chrono::seconds(3);
            //std::this_thread::sleep_until(nextTick);
            std::cin.get();
            on_time = true;
        }
        highlight = !highlight;
        
        lastSize = { width, height };
        
    }
}

int get_valid_input(int num_of_answers) {
    int temp{};
    while (true) {
        if (!(std::cin >> temp)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else {
            if (temp > 0 && temp < num_of_answers) {
                if (std::cin.peek() != EOF) {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                return temp;
            }
        }
    }
}