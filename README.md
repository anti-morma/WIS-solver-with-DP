# Weighted Interval Scheduling Solver

A C implementation of the Weighted Interval Scheduling problem using **Bottom-Up Dynamic Programming**.

This project solves the problem of selecting a non-overlapping subset of activities to maximize the total duration (weight), with a time complexity of `O(N^2)`.

## Project Philosophy

This code was written for **educational purposes** to deeply understand Dynamic Programming mechanics and to refine a personal C coding style.

Inspired by the coding style of **Antirez (Salvatore Sanfilippo)**, the project follows these pragmatic principles:
* **Minimal Abstraction:** Wrappers and getters/setters are avoided unless strictly necessary. Struct fields are accessed directly.
* **Logic Visibility:** The core DP algorithm resides in `main.c` rather than being hidden behind a generic API. This keeps the business logic front-and-center.
* **Pragmatic Modularity:** `activities.c` handles only generic sorting and compatibility tools, acting as a library, while the specific problem solver remains in the main flow.
* **Manual Memory Management:** Explicit allocation and freeing of resources.

*Note: This project was developed with the assistance of AI to explore optimization techniques and code styling nuances.*

## Build & Run

To compile the project using Make:

```bash
make
