# 🧵 Singly Linked List Program in C

This program allows you to **create**, **insert**, and **delete** nodes in a **singly linked list** using a simple menu-driven approach in C.

---

## 📌 Features

- Create a singly linked list with user-defined size
- Insert at:
  - Beginning
  - End
  - Any specific position
- Delete by:
  - Index
  - Value
- Display the linked list after every operation
- Menu-driven and interactive CLI interface

---
## 🧠 Data Structure Used

```c
struct node {
    int value;
    struct node *next;
};
```
## Program Flow

1. Ask user for initial number of nodes and values.
2. Create the list.
3. Display options:
   - Insert at first (`f`)
   - Insert at last (`l`)
   - Insert in between (`i`)
   - Delete by index (`x`)
   - Delete by value (`v`)
   - Exit (`e`)
4. Loop until user exits.
