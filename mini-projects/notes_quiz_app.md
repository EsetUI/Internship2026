
# QUIZ APP




# Requirements

* console window tui for displaying the quiz app

* the quiz app will ask the user 5 questions and keep track of their score

* 3 to 5 answers per question

* the questions will be randomly selected from a list

* the quiz will ask the user one question at a time

* checking answers (if correct then green, if not then red and mark the right answer with green)

* at the end of the quiz it will display the user's score and percentage




# Steps

* step 1 - create a list of questions and answers


* step 2 - create a console display for the quiz app


* step 3 - create a function to ask the user a question and check their answer


* step 4 - create a function to keep track of the user's score and display it at the end of the quiz


* step 5 - add the coloring for correct and incorrect answers


* step 6 - add a timer to skip to the next question after 5 seconds


* step 7 - add a score percentage display at the end of the quiz




# Optional

* add an optional timer for each question

* add multiple categories for the quiz (e.g. history, sports, english)

* after answering it will skip to another in 5 seconds




# File Format

```
{
  "questions": [
    {
      "question": "si student?",
      "answers": [
        "ano",
        "nie",
        "mozno",
        "ako kedy"
      ],
      "correctanswer": 0,
      "notetimeout": "in seconds, 0 means timeout",
      "timeout": 10,
      "notedifficutly": "difficulty has a range 1-3",
      "difficulty": 3
    }
  ]
}
```

