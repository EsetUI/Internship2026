## Day 3 - Shared Task 1: Temperature Converter

Day 3 gives both interns the same assignment. One implementation is in Python and the other is in C++.

### Goals

Students should practice:

* implementing the same behavior in two different languages
* validating input and error cases
* separating logic into clear functions
* keeping output clear and comparable
* explaining changes clearly in a pull request

### Suggested Exercises

Use these files from [../python-exercises/README.md](../python-exercises/README.md):

* `02_temperature_converter.py`
* and the matching C++ file `../cpp-exercises/02_temperature_converter.cpp`

### Shared Requirements

Both implementations should:

* ask for a numeric temperature value
* ask whether the unit is `C` or `F`
* convert to the opposite unit
* reject invalid numeric input
* reject invalid unit input

### Practical Task

1. Implement the same requirements in Python and C++.
2. Test both versions with the same normal and invalid input cases.
3. Compare whether the output and error handling are consistent.
4. Commit and open a pull request for each language version.

### Good Improvement Ideas

* add stronger input validation
* support a repeated menu loop
* add another conversion option
* improve output formatting and help text
* extract parsing or formatting into helper functions

### Deliverables

* one Python implementation and one C++ implementation of the same task
* two reviewable pull requests with comparable behavior

