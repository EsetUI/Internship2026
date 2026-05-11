# C++ Exercises

These exercises are small console programs that can be used either as starters or as refactoring tasks for a student who already knows C++ basics.

## How To Compile And Run

### With g++

```powershell
g++ cpp-exercises/01_hello_internship.cpp -std=c++17 -o hello
.\hello.exe
```

### With Visual C++

Use a Visual Studio Developer PowerShell and run:

```powershell
cl /EHsc cpp-exercises\01_hello_internship.cpp
01_hello_internship.exe
```

## Exercise List

| File | Focus | Suggested Extension |
| - | - | - |
| `01_hello_internship.cpp` | input, output, functions | ask more questions and print a summary |
| `02_number_stats.cpp` | loops, vectors, functions | add median or sorted output |
| `03_guess_number.cpp` | loops, conditions, randomness | count attempts and add replay support |
| `04_text_summary.cpp` | strings and helper functions | count sentences or most common letters |

## Suggested Teaching Pattern

1. Compile the starter file.
2. Run it from the terminal.
3. Change one part of the behavior.
4. Recompile and run again.
5. Commit the improvement.

## Proficient Student Mode

If the student already knows C++ basics, skip syntax review and require:

* one feature improvement
* one robustness or readability improvement
* one incorrect-input run
* one reviewable pull request

Good challenge directions:

* handle bad input without crashing
* move logic into helper functions
* improve prompts and output formatting
* reduce duplication in the program flow

