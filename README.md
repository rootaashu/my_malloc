# Simple Malloc Implementation (C)

A minimal implementation of memory allocation using low-level system calls like `sbrk` and `brk`.

## Description

This project demonstrates how dynamic memory allocation works internally by implementing a basic version of `malloc`.

## Features

* Custom `own_malloc()` using `sbrk`
* Heap reset using `brk`
* Demonstrates heap memory behavior

## How to Run

```bash
gcc -g src/my_malloc.c -o main
./main
```

## Learning Goals

* Understand heap memory
* Learn how `malloc` works internally
* Work with low-level system calls

