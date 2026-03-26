# Repository Guidelines

## Project Structure & Module Organization
This repository is a topic-organized competitive programming template library. Core code lives in folders such as `DataStructure/`, `Graph/`, `Math/`, `String/`, `Geometry/`, `IO/`, and `Algebra/`. Most entries are standalone `.cpp` or `.py` snippets named after the algorithm, for example `Graph/Dijkstra.cpp` or `String/KMP.py`.

`Algebra/Fundamentals/` contains deeper subfolders grouped by concept. Top-level `.pdf` and `.md` files are reference material, not build inputs. There is currently no dedicated `tests/` or `src/` directory.

## Build, Test, and Development Commands
There is no project-wide build system; compile or run files directly.

- `g++ -std=c++17 -O2 -Wall Graph\\Dijkstra.cpp -o dijkstra.exe` compiles a single C++ template.
- `python String\\KMP.py` runs a Python snippet for quick checks.
- `git status --short` reviews pending edits before committing.

Use commands from the repository root so relative paths stay consistent.

## Coding Style & Naming Conventions
Follow the existing repository style: 4-space indentation in Python, braces on the same line in C++, and compact competitive-programming friendly implementations. Keep each file focused on one algorithm or data structure.

Preserve current naming patterns. File names usually use `Pascal_Case.cpp`, spaced names like `Disjoint Set Union.cpp`, or descriptive suffixes in parentheses such as `SegmentTree(lazy_tag)(modify_range).cpp`. Match the surrounding folder rather than inventing a new scheme.

## Testing Guidelines
There is no automated test harness yet. For new templates, verify them with a minimal local driver or sample input before committing. When practical, include a short usage example or keep a temporary main/test case locally while validating edge cases such as empty input, 1-indexing, and overflow behavior.

## Commit & Pull Request Guidelines
Current git history uses short, direct subjects such as `update DSU`. Keep commit messages imperative and focused on one algorithm or module, for example `add suffix automaton template` or `fix Fenwick indexing`.

Pull requests should state:
- what algorithm or template changed
- which language files were touched
- how the change was validated
- any expected complexity or API differences

Keep unrelated algorithm edits in separate commits when possible.
