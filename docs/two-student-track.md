# Two-Student Mixed-Skill Plan

This plan is for a small internship group with:

* one student working mainly in Python
* one student working mainly in C++

The goal is for both interns to solve the same daily task, but in different languages.

## Principles

* do not repeat language basics unless a specific gap appears
* keep the daily problem statement shared
* use one acceptance criteria list for both implementations
* keep Git, pull requests, code review, and communication shared
* compare behavior, edge cases, naming, and usability across languages
* optimize for finished work, not maximum feature count

## Recommended Day Split

| Day | Shared Task | Python Student | C++ Student |
| - | - | - | - |
| 1 | Environment and GitHub | Setup and first branch | Setup and first branch |
| 2 | Git workflow and teamwork | Small Git task and PR | Small Git task and PR |
| 3 | Temperature converter | Build Python version | Build C++ version |
| 4 | Number statistics tool | Build Python version | Build C++ version |
| 5 | Text summary tool | Build Python version | Build C++ version |
| 6 | Cross-language review and fixes | Review C++ branch and fix Python branch | Review Python branch and fix C++ branch |
| 7 | One shared mini-project brief | Plan Python version from shared spec | Plan C++ version from shared spec |
| 8 | Same project, different language | Build Python version | Build C++ version |
| 9 | Same test cases, same polish pass | Align behavior and docs | Align behavior and docs |
| 10 | Demo and comparison | Demo Python version | Demo C++ version |

## Recommended Rules

### Same Task, Different Language

On implementation days:

* start from one written task description
* agree on input, output, and error-handling expectations first
* let one student implement in Python and the other in C++
* compare the results against the same checklist at the end of the day
* keep both pull requests reviewable and separate

### Review Focus

Each student should review the other implementation for:

* whether it matches the shared requirements
* whether the program output is clear
* whether invalid input is handled well
* whether the commit and pull request are understandable
* whether the code structure is readable even without deep language-specific knowledge

### Mini-Projects

Use one shared project brief.

Recommended model:

* both students implement the same core features
* one implementation is in Python and one is in C++
* both versions should be demoable with the same scenario
* differences in internal structure are fine, but user-facing behavior should stay comparable

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

* both students work on the same problem each day
* neither student sits through repeated language basics
* both students still produce reviewable work every day
* both students participate in pull requests and review
* the internship ends with two finished implementations of the same project brief
