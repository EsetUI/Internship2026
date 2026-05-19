import shutil
import sys
import time
from datetime import datetime


CURSOR_HOME = "\x1b[H"
CLEAR_SCREEN = "\x1b[2J"
HIDE_CURSOR = "\x1b[?25l"
SHOW_CURSOR = "\x1b[?25h"
RESET_STYLE = "\x1b[0m"
BG_BLUE = "\x1b[44m"
FG_CYAN = "\x1b[96m"

def place_centered_text(lines: list[list[str]], row: int, text: str) -> None:
	if row <= 0 or row >= len(lines) - 1:
		return

	inner_width = len(lines[row]) - 2
	trimmed_text = text[:inner_width]
	start = 1 + max(0, (inner_width - len(trimmed_text)) // 2)
	for index, char in enumerate(trimmed_text):
		lines[row][start + index] = char


def colorize_line(line: list[str], row: int, height: int) -> str:
	colored_parts: list[str] = []
	for index, char in enumerate(line):
		style = BG_BLUE + FG_CYAN
		colored_parts.append(f"{style}{char}")
	colored_parts.append(RESET_STYLE)
	return "".join(colored_parts)


def build_screen(width: int, height: int, caption: str, body: str) -> str:
	width = max(width, 4)
	height = max(height, 4)
	inner_width = width - 2

	lines = [list("+" + "-" * inner_width + "+")]
	for _ in range(height - 2):
		lines.append(list("|" + " " * inner_width + "|"))
	lines.append(list("+" + "-" * inner_width + "+"))

	place_centered_text(lines, 1, caption)
	place_centered_text(lines, height // 2, body)

	return "\n".join(colorize_line(line, row, height) for row, line in enumerate(lines))


def render_loop() -> None:

	last_size: tuple[int, int] | None = None

	sys.stdout.write(CLEAR_SCREEN + CURSOR_HOME + HIDE_CURSOR)
	sys.stdout.flush()

	try:
		while True:
			width, height = shutil.get_terminal_size(fallback=(80, 24))
			clock_text = datetime.now().strftime("%H:%M:%S")
			screen = build_screen(width, height, "TUI Demo", clock_text)

			prefix = CURSOR_HOME
			if last_size != (width, height):
				prefix = CLEAR_SCREEN + CURSOR_HOME
			sys.stdout.write(prefix + screen)
			sys.stdout.flush()


			last_size = (width, height)
			time.sleep(max(0.05, 1 - (time.time() % 1)))
	except KeyboardInterrupt:
		pass
	finally:
		sys.stdout.write(RESET_STYLE + SHOW_CURSOR + CURSOR_HOME)
		sys.stdout.flush()


if __name__ == "__main__":
	render_loop()
