# Mentor Guide

This repository works both for beginners and for students who already know one language reasonably well. Mentors should optimize for clarity, practical feedback, and the right level of challenge.

## Mentor Priorities

Focus on:

* small steps with visible outcomes
* short demonstrations before individual work
* frequent check-ins
* code review as a teaching tool
* finishing tasks, not chasing unnecessary complexity

## Two-Student Mixed-Skill Mode

Use this variant when:

* one student is already comfortable with Python
* one student is already comfortable with C++
* you do not want to spend time re-explaining language basics

Recommended approach:

* keep Days 1 and 2 shared for setup and Git workflow
* make Days 3 and 4 Python-focused implementation days for the Python student
* make Day 5 a C++-focused implementation day for the C++ student
* use Day 6 for cross-review, debugging, and refactoring
* let each student use their stronger language for the mini-project unless there is a strong reason to combine them

What the other student does during a language-focused day:

* review the task requirements
* run the program and try edge cases
* give feedback on behavior, readability, and output
* check pull request quality and commit hygiene

This keeps both students engaged without turning the day into a syntax lesson they do not need.

## Suggested Daily Rhythm

1. Introduce the daily goal in 10 to 15 minutes.
2. Demonstrate one example live.
3. Let students work independently.
4. Review blockers quickly.
5. End the day with a recap and short demo of completed work.

## Review Style

Prefer comments like:

* `Rename this variable so the intent is clearer.`
* `This block works, but can you extract it into a function?`
* `What happens if the input is empty?`

Avoid solving the whole task for the student unless they are completely blocked.

If the student already knows the language basics, avoid explaining variables, loops, or simple functions again. Move directly to input validation, structure, error handling, naming, review comments, and delivery quality.

## What To Evaluate

Mentors should mainly evaluate:

* understanding of the task
* ability to run and test code
* Git and GitHub workflow usage
* code readability
* communication quality

## Common Student Failure Modes

Watch for:

* copying code without understanding it
* committing large unrelated changes
* not running the code before pushing
* silently getting stuck instead of asking for help
* choosing a mini-project that is too large

## Mini-Project Scope Rule

The project is the right size if a student can explain:

* what the program does
* what the minimum working version is
* what features are optional stretch goals

If they cannot explain the minimum version clearly, the project is probably too large.

The concrete two-student plan is in [two-student-track.md](two-student-track.md).

