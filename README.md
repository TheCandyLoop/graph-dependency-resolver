# Graph Dependency Resolver (C)

## Overview

This project implements a **graph-based dependency resolver** using the C programming language. It models tasks and their dependencies as a **directed graph**, detects cyclic dependencies, and determines a valid execution order using **Depth First Search (DFS)** and **Topological Sorting**.

This mirrors how real-world systems such as **build tools, package managers, and task schedulers** resolve dependencies before execution.

---

## Key Features

* Models dependencies using a directed graph
* Uses adjacency lists for efficient storage
* Detects cycles in dependencies (invalid execution)
* Produces a valid execution order for tasks (DAG)
* Pure C implementation with strong DSA focus

---

## Data Structures & Algorithms Used

* Graph (Directed)
* Adjacency List
* Depth First Search (DFS)
* Cycle Detection using DFS states
* Stack-based Topological Sort
* DAG Processing

---

## Project Structure

```
.
├── dependency_resolver.c
└── README.md
```

---

## How It Works (Simple Explanation)

1. Each task is represented as a node in a graph
2. A dependency is represented as a directed edge
3. DFS is used to traverse the graph
4. If a cycle is detected, execution is not possible
5. If no cycle exists, tasks are printed in a valid execution order

---

## Compilation & Execution

### Compile

```bash
gcc dependency_resolver.c -o dependency_resolver
```

### Run

```bash
./dependency_resolver
```

---

## Sample Output

```
5 4 0 1 2 3
```

This output represents a valid order in which tasks can be executed while respecting all dependencies.

---

## Cycle Detection Example

If a circular dependency is introduced, the program outputs:

```
Cycle detected
```

This ensures invalid dependency graphs are safely rejected.

---

## Real-World Relevance

This project demonstrates concepts used in:

* Build systems (Maven, Gradle)
* Package managers (npm, apt)
* Task schedulers
* Compiler pipelines

---

## Interview Summary

You can describe this project as:

> "I implemented a dependency resolver in C using graph theory. The system detects cyclic dependencies using DFS and generates a valid execution order using topological sorting, similar to real build systems."

---

## Future Enhancements

* Accept user input for tasks and dependencies
* Use task names instead of numeric IDs
* Implement BFS-based topological sorting (Kahn’s Algorithm)
* Read dependencies from a file
* Modularize into multiple source/header files

---

## Author
Pankti 

Built as a DSA-focused systems project using C.
