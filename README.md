# Data Structures in C

I created this project practice implementing
some of the most widespread data structures from scratch in C
language, for educational purposes.

This study is based on the book _Data Structures Using C_, Second Edition by Yedidyah Langsam, Moshe J. Augenstein
and Aaron M. Tenenbaum:

```bibtex
@book {
    title = "Data Structures Using C",
    authors = {
        "Yedidyah Langsam",
        "Moshe J. Augenstein",
        "Aaron M. Tenenbaum"
    },
    edition = "2nd",
    year = 1996
}
```

## Repository structure

This repository has three main directories:

- `examples/`: this directory stores small applications that use the data structure to test them.
- `include/`: this directory stores the header files, `.h`, of each data structure.
- `structures/`: this directory stores the implementations of each data structure.

Inside these directories, each data structure is stored inside its corresponding directory.

A `Makefile` was also defined to ease the process of compiling the code.

## Implemented Data Structures

### Array

As this data structure is natively implemented in C, it can be implemented. Nevertheless, a data structure to store and manage strings was implemented through an array of characters.

To build the code correspondant to the string data structure, run:

```bash
make strings
```

To run the testing code:

```bash
./build/examples/array/strings/array_strings.out
```

### Stack

This data structure has been implemented twice: one using an array and one using a linked list.

To build the code correspondant to the array stack data structure, run:

```bash
make array_stack
```

To run the testing code:

```bash
./build/examples/stack/array_stack.out
```

To build the code correspondant to the linked stack data structure, run:

```bash
make linked_stack
```

To run the testing code:

```bash
./build/examples/stack/linked_stack.out
```

To build all the stacks:

```bash
make stacks
```

## Author

Pablo Regodón - pablo.regodon@hotmail.com
