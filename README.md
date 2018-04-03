# Introduction to C

This repository is the workshop materials for the Linux@App Introduction to C workshops.

Each workshop meeting has its own subdirectory with the materials for that meeting. Each
subdirectory contains a README.md like this one with instructions for using the materials.

Hopefully, the materials are sufficiently verbose that you can read through them to get the
same content as attending a workshop.

Pull requests and suggestions welcome!

## Content

This repository is intended to teach the following skills:
* Meeting 1
  * Basic C compiler usage
  * Basic C preprocessor tricks
  * Basic C types
  * Basic functions
  * C strings and memory management
  * How to get help with and use the C standard library
* Meeting 2
  * Pointers and Arrays (review)
  * Memory and Strings (review)
  * Basic structures
  * Methods
  * Header files & Modularization

## Prerequisites

You need a UNIX machine with `gcc`, `git`, `make`, and some kind of text editor. You should know how
to run programs in a terminal. Basic programming experience in another language is also important.

## Getting started

This repository contains a series of makefiles that operate on different files to
automate compilation. Use these as a reference to learn the various flags that the
`gcc` command accepts.

Acquire a copy of the files:
```
git clone https://github.com/whereswaldon/intro2c.git
```

Then dive in to the `meeting` directories in ascending order.
