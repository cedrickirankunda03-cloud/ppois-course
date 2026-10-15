# ppois-course

Laboratory assignments for the "Design of Intelligent Systems Software" course.

## Lab 1 — Dictionary and Unordered Cantor Set

Two independent implementations under lab1/:

- *Dictionary* (lab1/Dictionary/) — binary-search-tree–based associative container
- *Set* (lab1/Set/) — unordered Cantor set implementation

Both come with GoogleTest unit tests (target: >90% coverage), a console CLI for interactive demonstration, and a CMake build system.

## Build & Test

```bash
cmake -S lab1/Dictionary -B build
cmake --build build --config Release
ctest --test-dir build -C Release --output-on-failure
