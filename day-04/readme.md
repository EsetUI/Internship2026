## Day 4 - Shared Task 2: Number Statistics

Day 4 keeps the interns on the same assignment again, this time building matching number statistics tools in Python and C++.

### Goals

Students should practice:

* working from one shared task description
* splitting logic into functions
* parsing and validating input
* working with lists and strings
* printing readable results
* improving maintainability without changing the core goal

### Suggested Exercises

Use these files from [../python-exercises/README.md](../python-exercises/README.md):

* `03_number_stats.py`
* and the matching C++ file `../cpp-exercises/03_number_stats.cpp`

### Shared Requirements

Both implementations should:

* accept numbers separated by commas or semicolons
* reject empty input
* reject invalid numeric input
* print count, minimum, maximum, sum, and average
* keep numeric output easy to compare

### Practical Task

1. Implement the same number statistics behavior in Python and C++.
2. Test at least three matching inputs, including one invalid case, in both versions.
3. Compare whether the results and error messages are aligned.
4. Open a pull request for each language version and ask for review.

### Stretch Ideas

* sort the numbers before printing
* allow repeated execution in one run
* support input from a file later
* separate parsing and display logic more clearly

### Deliverables

* one Python implementation and one C++ implementation of the same task
* review feedback addressed in both branches

