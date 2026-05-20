import shutil
import sys
import time
import json
import queue
import threading

CURSOR_HOME = "\x1b[H"
CLEAR_SCREEN = "\x1b[2J"
HIDE_CURSOR = "\x1b[?25l"
SHOW_CURSOR = "\x1b[?25h"
RESET_STYLE = "\x1b[0m"
BG_BLUE = "\x1b[44m"
FG_CYAN = "\x1b[96m"
GREEN = "\x1b[42m\x1b[30m"
RED = "\x1b[41m\x1b[30m"


with open("quiz.json", "r") as sub:
	data = json.load(sub)


class Question:
	def __init__(self, question: str, answers: list[str], correct: int):
		self.question = question
		self.answers = answers
		self.correct = correct


class QuestionManager:
	def __init__(self):
		self.questions = []
		self.current_index = 0

	def load(self, data):
		self.questions = [
			Question(item["question"], item["answers"], item["correctanswer"])
			for item in data["questions"]]

	def get_current(self):
		return self.questions[self.current_index]

	def next(self):
		self.current_index += 1


def place_centered_text(lines, row, text, color=None):
	if row <= 0 or row >= len(lines) - 1:
		return

	inner_width = len(lines[row]) - 2
	text = text[:inner_width]
	start = 1 + max(0, (inner_width - len(text)) // 2)

	for i, c in enumerate(text):
		lines[row][start + i] = c

	lines[row].insert((start + len(text)) % len(lines[row]), BG_BLUE)
	lines[row].insert((start - 1) % len(lines[row]), color or "")


def show_end_screen(score, total):
	percent = score / total * 100

	sys.stdout.write(CLEAR_SCREEN + CURSOR_HOME)

	print("\n" * 3)
	print("===== QUIZ FINISHED =====")
	print(f"Score: {score}/{total}")
	print(f"Percent: {percent:.1f}%")

	input("\nPress Enter...")


def colorize_line(line):
	return BG_BLUE + FG_CYAN + "".join(line) + RESET_STYLE


def input_worker(q):
	while True:
		q.put(input())


def build_screen(width, height, caption, question, correct=None, user_answer=None):

	width = max(width, 4)
	height = max(height, 4)

	inner_width = width - 21

	lines = [list("+" + "-" * inner_width + "+")]

	for _ in range(height - 2):
		lines.append(list("|" + " " * inner_width + "|"))

	lines.append(list("+" + "-" * inner_width + "+"))

	place_centered_text(lines, 1, caption)
	place_centered_text(lines, 4, question.question)

	start_row = (height // 2) - (len(question.answers) // 2)

	for i, ans in enumerate(question.answers):
		text = f"{i + 1}. {ans}"
		color = FG_CYAN
		if correct is not None:
			if i == correct:
				color = GREEN
			elif user_answer == i :
				color = RED

		place_centered_text(lines, start_row + i, text, color)


	return "\n".join(colorize_line(line) for line in lines)


def render_loop():
	manager = QuestionManager()
	manager.load(data)

	score = 0
	q = queue.Queue()

	threading.Thread(target=input_worker, args=(q,), daemon=True).start()

	sys.stdout.write(CLEAR_SCREEN + CURSOR_HOME + HIDE_CURSOR)
	sys.stdout.flush()

	try:
		while True:
			question = manager.get_current()

			start_time = time.time()
			duration = 10
			answered = False
			user_answer = None

			while True:
				width, height = shutil.get_terminal_size(fallback=(80, 24))


				screen = build_screen(width, height, "QUIZ", question, correct = None)
				sys.stdout.write(CURSOR_HOME + screen)


				sys.stdout.flush()
				
				answer = input("your answer: ")
				try:
					user_answer = int(answer.strip())-1

				except:
					user_answer = -1
				

				if user_answer < len(question.answers) and user_answer >= 0:
					answered = True

					break

			if answered:

				correct = question.correct

				if user_answer == correct:
					if time.time() - start_time <= 10:
						score += 1
					else:
						score += 0.5
				else:
					score -= 0.5

				end = time.time() + 2
				while time.time() < end:
					width, height = shutil.get_terminal_size(fallback=(80, 24))

					screen = build_screen(
						width,
						height,
						"RESULT",
						question,
						correct=correct,
						user_answer=user_answer
					)

					sys.stdout.write(CURSOR_HOME + screen)
					sys.stdout.flush()
					time.sleep(0.1)

			else:
				end = time.time() + 3
				while time.time() < end:
					width, height = shutil.get_terminal_size(fallback=(80, 24))

					screen = build_screen(width, height, "TIMEOUT", question, 0)
					sys.stdout.write(CURSOR_HOME + screen)
					sys.stdout.flush()
					time.sleep(0.1)

			manager.next()

			if manager.current_index >= len(manager.questions):

				width, height = shutil.get_terminal_size(fallback=(80, 24))

				percent = score / len(manager.questions) * 100

				lines = [list("+" + "-" * (width - 21) + "+")]

				for _ in range(height - 2):
					lines.append(list("|" + " " * (width - 21) + "|"))

				lines.append(list("+" + "-" * (width - 21) + "+"))

				place_centered_text(lines, 3, "QUIZ FINISHED")
				place_centered_text(lines, 6, f"Score: {score}/{len(manager.questions)}")
				place_centered_text(lines, 8, f"Percent: {percent:.1f}%")

				if percent >= 80:
					place_centered_text(lines, 10, "nice", GREEN)
				elif percent >= 50:
					place_centered_text(lines, 10, "good", GREEN)
				else:
					place_centered_text(lines, 10, "try again", RED)

				screen = "\n".join(colorize_line(line) for line in lines)

				sys.stdout.write(CURSOR_HOME + screen)
				sys.stdout.flush()

				input("\nenter")
				break



	
	except KeyboardInterrupt:
		pass

	finally:
		sys.stdout.write(RESET_STYLE + SHOW_CURSOR + CURSOR_HOME)
		sys.stdout.flush()


if __name__ == "__main__":
	render_loop()



