# 📊 Push_swap (42 Project)

`Push_swap` is a 42 project focused on **sorting integers using two stacks** with a minimal set of operations. The main objective is to sort a list of numbers efficiently while respecting the constraints of stack operations.

<img width="512" height="512" alt="unnamed" src="https://github.com/user-attachments/assets/27dad990-bfed-401f-8a09-4d6fc5f6841f" />

---

## 🚀 Project Overview

The program takes a list of integers as input via the command line and sorts them using two stacks (A and B) and the following allowed operations:

- `sa` / `sb`: Swap the first two elements of stack A or B.
- `pa` / `pb`: Push the top element from one stack to the other.
- `ra` / `rb`: Rotate stack A or B upwards.
- `rra` / `rrb`: Rotate stack A or B downwards.

The goal is to output a sequence of operations that sorts the numbers in ascending order while **minimizing the total number of moves**.

---

## 🔑 Key Concepts

- **Stacks and Operations**: Master two-stack manipulation using limited operations.
- **Algorithm Optimization**: Choose the most efficient sequence of moves.
- **Input Validation**: Handle invalid numbers, duplicates, or empty input.
- **Memory Management**: Allocate and free memory correctly to prevent leaks.

---

## ⚙️ Requirements

- Must read integers from command-line arguments.
- Must output a valid sequence of operations to sort the input.
- Must handle small lists (2–5 elements) efficiently.
- Must optimize operations for larger lists (100+ elements).
- Must correctly handle edge cases like already sorted input or duplicates.

---

## 📝 Example Usage

```bash
./push_swap 3 2 1
```
Output (example for 3 elements):
```
sa
ra
```

This sequence sorts the numbers in ascending order.

---

## 🎯 Learning Outcomes

- Deep understanding of **stack-based algorithms**.
- Experience in **algorithm optimization**.
- Proper handling of **input validation and edge cases**.
- Strengthened **C programming skills**, including dynamic memory management.

---

## ✅ Status

✔️ Project completed and validated at 42
