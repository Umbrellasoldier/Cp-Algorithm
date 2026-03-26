# Repository Guidelines

## Project Structure & Module Organization

`Code/` holds active problem solutions and language templates, including `Code/GO/` for Go examples and tests. `Template/` is the main algorithm library, grouped by topic such as `DataStructure/`, `Graph/`, `Math/`, and `String/`. `Pair beat/` contains brute-force checking workflows for C++ and Python. Large reference assets such as PDF, ZIP, MP4, logs, and local caches are intentionally excluded by `.gitignore`.

## Build, Test, and Development Commands

- `go test ./Code/GO` runs the Go unit tests in `Code/GO/`.
- `python Code/algo.py < input.txt` runs the Python template locally.
- `g++ -std=c++17 -O2 Code/algo.cpp -o algo` builds the C++ template.
- `Pair beat\\py\\pb.bat` runs Python stress testing with generated data.
- `Pair beat\\cpp\\pair beat.bat` runs C++ stress testing by comparing `std.cpp` and `bf.cpp`.

There is no single repo-wide build script; run commands from the repository root in PowerShell or `cmd`.

## Coding Style & Naming Conventions

Use 4-space indentation in Python, C++, and Go source files. Keep existing competitive-programming structure: a small `solve()` function plus a minimal `main` or driver loop. Prefer concise, standard library-based implementations over heavy abstractions. Use `snake_case` for Python helpers, keep C++ aliases short (`i64`, `u64`), and let Go files pass `gofmt`. Contest solution files may use short names like `A.py`; reusable templates should use descriptive topic-based names such as `Suffix_Array.cpp`.

## Testing Guidelines

Go tests follow the standard `*_test.go` pattern and should be runnable with `go test`. Python and C++ quick checks often use adjacent `__tests`, `.out`, or generated `data.in` files; keep new fixtures close to the solution they verify. For algorithm changes, add at least one deterministic sample and, when practical, a stress-test path in `Pair beat/`.

## Commit & Pull Request Guidelines

History is currently minimal, so use short imperative commit messages in English, for example `Add Fenwick tree template` or `Fix Go rect tests`. Keep each commit focused on one topic. Pull requests should summarize the affected directories, list the commands you ran, and note any excluded large assets. Screenshots are unnecessary unless the change is documentation with rendered output differences.

## Repository Hygiene

Do not commit generated binaries, editor caches, or large study materials. If you add new local tooling output, extend `.gitignore` in the same change.
