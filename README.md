# C++ Programming Coursework

C++ laboratory exercises and a console-based vending-machine application. The repository retains its original name, `MicroController`; the files here primarily demonstrate desktop C++ programming.

## Start here

[Vending-machine source](VendingMachine/VendingMachine.cpp) demonstrates a class hierarchy, virtual functions, standard-library containers, inventory, purchase handling and sales tracking.

| Directory | Contents |
| --- | --- |
| `VendingMachine/` | Integrated console application |
| `lab1/`, `lab2/` | Introductory programming exercises |
| `Lab3/`, `Lab4/` | Further C++ assignments |
| `PracticeExercises/` | Pointers, classes, inheritance, polymorphism and other practice |

## Suggested build

From the repository root, with a C++ compiler installed:

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -Wpedantic VendingMachine/VendingMachine.cpp -o build/vending-machine
./build/vending-machine
```

This is a suggested command, not a verified build result. Each exercise is generally a separate program; do not link all source files together.

## Current limitations

- The vending-machine constructor does not initialize `balance` and `totalEarnings`. Correct this before relying on transaction results.
- Add checks for negative restock quantities and end-of-input behavior.
- The repository contains historical Windows executables; build from source for review.
- Coursework examples are learning artifacts, not production software.

## Next improvements

Initialize transaction state, demonstrate purchase/change/restock scenarios, and document the results. Keep generated binaries in `build/`. Add an example console session after the behavior has been verified.

See the [electronics portfolio](https://github.com/MahmoodMoh/MahmoodMoh.github.io).
