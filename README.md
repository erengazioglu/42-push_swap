# PUSH SWAP

_This project has been created as part of the 42 curriculum by egaziogl._

## Description

An array sorting exercise with strict rules: a stack with random integers to be sorted, another empty stack to use for sorting operations, a handful of permitted moves (swap, rotate, push), and an upper limit.

### Algorithm

Initially I wanted to use Radix Sort or Quick Sort, but I noticed that the limitations are too specific and I needed something greedier and more optimistic. I was recommended the Turk Sort; I don't know what specific moves it does in detail, so I took the core idea (calculate insertion costs & greedily sort the stack).

Some particular implementation details:  
- My interpretation of stacks is a sort of a linked list. For the operations I'm doing, **I decided to make it a doubly-linked list with a reference to both ends,** while also keeping min, max, and count variables always updated so that I can calculate costs precisely.
- I created a "strict atoi" for parsing arguments.
- The core of the algorithm runs until 5 nodes remain in the stack A, and then the stack A is sorted _almost in-place_ (using only the top of the stack B).
- When checking for whether a stack is ordered or not, the algorithm _wraps around the edges in a circular manner,_ so the max and min values can be offset.

## Instructions

### Compilation

Clone the repository & run `make`.

### Use

You can pass either any number of integers as arguments, or a single string with numbers separated by spaces:
- `./push_swap 1 4 9 78`
- `./push_swap "29 83 751 2 9"`

## Resources

- **Peer learning:** I asked lots of fellow 42 students about what the main idea is and common pitfalls. I was recommended to either learn and apply Radix, or the infamous "Turk Sort" which is thought up specifically for this project.
- **AI:**
    - I ask questions related to git and debugging to AI (e.g. _git workflow for managing branches and tags, how to use gdb to print to another tty..._).
