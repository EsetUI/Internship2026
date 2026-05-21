import json
import os
import sys                             # apka sa ma spravat ako git


class Task:
    def __init__(self, text:str, done:bool = False):
        self.text = text
        self.done = done

class TaskManager:
    def __init__(self):
        self.tasks = []
        self.load()


    def run(self):
        while True:
            command = input("Enter command (list, add, done, rm, dl, ndl, exit): ").strip().lower()
            parts = command.split()
            if not parts:
                continue
            command = parts[0]
            if command == "list":
                self.list()
            elif command == "add":
                text = " ".join(parts[1:])
                if not text:
                    print("Please provide a task description.")
                    continue
                self.add(text)
            elif command == "done":
                # index = int(input("Enter task number to mark as done: ")) - 1
                try:
                    index = int(parts[1]) - 1
                    self.done(index)
                except:
                    print("Please provide a valid task number to mark as done.")
            elif command == "rm":
                # index = int(input("Enter task number to remove: ")) - 1
                try:
                    index = int(parts[1]) - 1
                    self.rm(index)
                except (IndexError, ValueError):
                    print("Please provide a valid task number to remove.")
            elif command == "dl":
                for i, t in enumerate(self.tasks):
                    if t.done:
                        print(f"{i + 1}. {t.text} [x]")
            elif command == "ndl":
                for i, t in enumerate(self.tasks):
                    if not t.done:
                        print(f"{i + 1}. {t.text} [ ]")
            elif command == "exit":
                print("Exiting task manager...")
                break
            else:
                print("Unknown command. Please try again.")

    def load(self):
        if not os.path.exists("day 8/taskmanager.json"):
            self.tasks = []
            return

        with open("day 8/taskmanager.json", "r") as subf:
            try:
                data = json.load(subf)
            except json.JSONDecodeError:
                print("Error: taskmanager.json is corrupted. Starting with an empty task list.")
                self.tasks = []
                return
            
        
        self.tasks = [Task(t["text"], t["done"]) for t in data["tasks"]]



    def save(self):
        with open("day 8/taskmanager.json", "w") as subchange:
            json.dump(
                {
                    "tasks": [
                        {"text": t.text, "done": t.done} for t in self.tasks
                    ]
                },
                subchange,
                indent=2
            )


    def add(self, text:str):                                    # ked uzivatel da add tak nech za to napise text a tak to bude fungvat ako v git
        self.tasks.append(Task(text))
        self.save()


    def list(self):
        for i, t in enumerate(self.tasks):
            status = "[x]" if t.done else "[ ]"
            print(f"{i + 1}. {status} {t.text}")


    def rm(self, index:int):
        if 0 <= index < len(self.tasks):
            self.tasks.pop(index)
            self.save()


    def done(self, index:int):
        self.tasks[index].done = True
        self.save()