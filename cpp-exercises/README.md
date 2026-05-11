# C++ Exercises

These exercises are small console programs. The core tasks are mirrored with Python so two interns can solve the same problem in different languages on the same day.

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

## Core Shared Task Files

Use these mirrored files for the shared daily tasks:

* `02_temperature_converter.cpp`
* `03_number_stats.cpp`
* `04_text_summary.cpp`

## Exercise List

| File | Focus | Suggested Extension |
| - | - | - |
| `01_hello_internship.cpp` | input, output, functions | ask more questions and print a summary |
| `02_temperature_converter.cpp` | arithmetic, conditionals | add Kelvin support or retry on invalid input |
| `03_number_stats.cpp` | parsing, vectors, validation | add median or sorted output |
| `04_text_summary.cpp` | strings and helper functions | count sentences or most common letters |
| `05_guess_number.cpp` | loops, conditions, randomness | count attempts and add replay support |

## Mirrored Daily Task Pairs

These pairs are intended for shared daily tasks:

* `02_temperature_converter.cpp` and `../python-exercises/02_temperature_converter.py`
* `03_number_stats.cpp` and `../python-exercises/03_number_stats.py`
* `04_text_summary.cpp` and `../python-exercises/04_text_summary.py`

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
* comparison against the matching Python version of the same task

Good challenge directions:

* handle bad input without crashing
* move logic into helper functions
* improve prompts and output formatting
* reduce duplication in the program flow


