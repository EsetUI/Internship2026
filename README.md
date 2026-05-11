# 2-Week Practical Programming Internship

This repository is a complete starter package for a 2-week programming internship for Slovak secondary school students during maturita practice.

It combines:

* a day-by-day internship plan
* parallel Python and C++ exercise tracks built around the same daily tasks
* mentor support material
* Git and GitHub workflow guidance
* mini-project briefs for the second week

The goal is not only to teach syntax. The goal is to show how real software work is organized: setup, coding, commits, pull requests, code review, debugging, communication, and final presentation.

## Internship Overview

**Duration:** 2 weeks  
**Target group:** secondary school students during practical maturita preparation  
**Main focus:** Git, GitHub, Python, C++, teamwork, and software delivery  
**Format:** guided practice, individual tasks, review, and a small final project

## Learning Outcomes

By the end of the internship, each student should be able to:

* prepare a working development environment
* use a code editor and terminal with confidence
* clone a repository and work in their own branch
* create commits with clear messages
* push changes and open a pull request
* respond to review comments and improve code
* write and run simple Python programs
* compile and run basic C++ programs
* explain their implementation and tradeoffs
* present a small finished mini-project

## Recommended Tools

The internship assumes access to:

* Git
* GitHub account
* Visual Studio Code or another editor
* Python 3.11 or newer
* a C++ compiler such as MSVC or MinGW g++
* terminal access in Windows PowerShell or another shell

Setup details are in [docs/setup-guide.md](docs/setup-guide.md).

If the interns already know Python and C++ basics, skip syntax walkthroughs and use the same-task parallel plan in [docs/two-student-track.md](docs/two-student-track.md).

## Suggested 2-Week Roadmap

| Day | Focus | Main Output |
| - | - | - |
| 1 | Environment and GitHub | Verified setup, first branch, first pull request |
| 2 | Git workflow and teamwork | Practice with commits, pulls, merges, and review |
| 3 | Shared Task 1 | Temperature converter in Python and C++ |
| 4 | Shared Task 2 | Number statistics tool in Python and C++ |
| 5 | Shared Task 3 | Text summary tool in Python and C++ |
| 6 | Cross-language review | Both implementations reviewed and improved |
| 7 | Mini-project planning | One shared brief, two language-specific implementations |
| 8 | Mini-project build | First usable Python and C++ versions |
| 9 | Testing and polish | Aligned behavior, docs, and demo readiness |
| 10 | Demo and retrospective | Compare both implementations and explain tradeoffs |

Daily plans live in the day folders:

* [day-01/readme.md](day-01/readme.md)
* [day-02/readme.md](day-02/readme.md)
* [day-03/readme.md](day-03/readme.md)
* [day-04/readme.md](day-04/readme.md)
* [day-05/readme.md](day-05/readme.md)
* [day-06/readme.md](day-06/readme.md)
* [day-07/readme.md](day-07/readme.md)
* [day-08/readme.md](day-08/readme.md)
* [day-09/readme.md](day-09/readme.md)
* [day-10/readme.md](day-10/readme.md)

## How To Use This Repository

### Students

1. Read the daily plan for the current day.
2. Complete the assigned task or exercise.
3. Run the code locally.
4. Commit your work with a clear message.
5. Push your branch and open or update a pull request.
6. Ask for review when you are blocked or finished.

### Mentors

1. Start each day with a short live demonstration.
2. Keep tasks small and concrete.
3. Review code frequently and give practical comments.
4. Prefer explanation over simply fixing the student's code.
5. Use the mini-project stage to teach planning, scope control, and finishing work.

Mentor guidance is in [docs/mentor-guide.md](docs/mentor-guide.md).

## Mixed-Skill Variant

For a two-student internship with one Python student and one C++ student:

* keep the daily problem statement shared
* define one common requirement set for both interns
* let one intern implement the task in Python and the other in C++
* compare outputs, edge cases, and user experience at the end of the day
* use cross-review to compare behavior and quality rather than reteach syntax
* use one shared mini-project brief with separate Python and C++ implementations

Use [docs/two-student-track.md](docs/two-student-track.md) as the mentor playbook for this setup.

## Repository Structure

```text
Internship2026/
├── README.md
├── day-01/
├── day-02/
├── day-03/
├── day-04/
├── day-05/
├── day-06/
├── day-07/
├── day-08/
├── day-09/
├── day-10/
├── python-exercises/
├── cpp-exercises/
├── mini-projects/
└── docs/
```

## Exercise Areas

* [python-exercises/README.md](python-exercises/README.md) contains the Python side of the mirrored daily tasks plus bonus Python challenges.
* [cpp-exercises/README.md](cpp-exercises/README.md) contains the C++ side of the mirrored daily tasks plus bonus C++ challenges.
* [mini-projects/README.md](mini-projects/README.md) contains project briefs and starter templates.

## Workflow Expectations

Students should practice the full workflow during the internship:

* use branches instead of working directly on the main branch
* write small, reviewable commits
* explain changes in pull requests
* react to feedback and push follow-up commits
* keep code readable, simple, and tested manually

The most useful reference for daily Git commands is [docs/git-cheatsheet.md](docs/git-cheatsheet.md).

## Assessment

This internship is practical. Students should be evaluated mainly on:

* ability to set up and use tools
* ability to complete tasks independently after explanation
* quality and clarity of submitted code
* use of Git and GitHub workflow
* communication, responsiveness, and presentation

A simple rubric is available in [docs/evaluation-rubric.md](docs/evaluation-rubric.md).

## Recommended Preparation Before Day 1

Students should have:

* a laptop with charger
* access to email and GitHub
* permission to install required tools
* basic willingness to ask questions and work in a team

Useful but not required:

* basic Python experience
* basic C++ experience
* some terminal familiarity

## Final Deliverable

Each student or pair should finish the internship with:

* at least one reviewed pull request
* several completed exercise files
* one shared mini-project brief implemented in Python and C++
* a short final presentation or demo comparing both versions

This repository is designed to support shared tasks across languages. If a student already knows a language, use the same problem statement, require stronger input handling and code quality, and compare the two implementations at the end of the day.



