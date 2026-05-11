# Two-Student Mixed-Skill Plan

This plan is for a small internship group with:

* one student already comfortable with Python
* one student already comfortable with C++

The goal is to avoid wasting time on syntax they already know and focus instead on delivery skills.

## Principles

* do not repeat language basics unless a specific gap appears
* keep Git, pull requests, code review, and communication shared
* let each student spend most implementation time in their stronger language
* use cross-review for behavior, edge cases, naming, and usability
* optimize for finished work, not maximum feature count

## Recommended Day Split

| Day | Python-Proficient Student | C++-Proficient Student | Shared Goal |
| - | - | - | - |
| 1 | Setup and first branch | Setup and first branch | Environment and GitHub workflow |
| 2 | Small Git task and PR | Small Git task and PR | Team workflow |
| 3 | Implement a Python improvement | Review requirements, run the Python tool, give feedback | Applied Python work |
| 4 | Extend or refactor the Python tool | Review edge cases or prepare mini-project scope | Problem solving and review |
| 5 | Review C++ task behavior and output | Implement a C++ improvement | Applied C++ work |
| 6 | Review C++ branch and fix Python review findings | Review Python branch and fix C++ review findings | Debugging and code review |
| 7 | Choose mini-project in strongest language | Choose mini-project in strongest language | Scope definition |
| 8 | Build project | Build project | Delivery |
| 9 | Polish and document project | Polish and document project | Finish quality |
| 10 | Demo project | Demo project | Presentation |

## Recommended Rules

### Language-Focused Days

On a Python-focused or C++-focused day:

* the stronger student owns implementation
* the other student acts as tester, reviewer, and requirements checker
* both students should still comment on pull requests

### Review Focus

The non-owner should review:

* whether the program output is clear
* whether invalid input is handled well
* whether the commit and pull request are understandable
* whether the code structure is readable even without deep language-specific knowledge

### Mini-Projects

The simplest model is:

* Python student builds a Python project
* C++ student builds a C++ project

If you want one shared project, split responsibilities clearly. For example:

* Python student owns scripting, parsing, and fast iteration
* C++ student owns performance-sensitive or structured console parts

Only use a shared project if the scope stays small.

## Good Tasks For Proficient Students

Use tasks that emphasize:

* input validation
* refactoring duplicated logic
* clearer function boundaries
* better naming
* better console output and help text
* testing with incorrect input
* writing reviewable pull requests

Avoid spending full sessions on:

* variable syntax
* simple loops
* trivial function definitions
* copy-paste tutorial examples

## Done Definition

This setup is working well when:

* neither student sits through repeated language basics
* both students still produce reviewable work every day
* both students participate in pull requests and review
* the internship ends with finished projects and clear demos
