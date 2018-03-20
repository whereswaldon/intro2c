# Introduction to C

This repository is the workshop materials for the Linux@App Introduction to C
event.

## Using this Repo

This repository is intended to teach the following skills:

* Basic C compiler usage
* Basic C preprocessor tricks
* Basic C types
* Basic functions
* Basic structures
* How to get help with and use the C standard library

## Prerequisites

You need a UNIX machine with `gcc` and some kind of text editor. Basic programming
experience in another language is also important.

## Getting started

This repository contains a series of makefiles that operate on different files to
automate compilation. Use these as a reference to learn the various flags that the
`gcc` command accepts.

### Hello world
First, cd into the `first` directory and run `make first-all`. The outputs that are generated
are the results from each stage of the c compilation pipeline:

* `first.E` is the result of running the preprocessor. You should look at this, as it will help make sense of what #include actually does
* `first.s` is the compiled version of the code. It is presented in human-readable assembly language.
* `first.o` is the assembled version of the code. It is a binary file, so view it with `xxd` or similar. Ordinarily, several object files are combined to form an executable, which is the stage after assembling in the compilation pipeline.
* `first` is an executable file built by linking `first.o`. Try it with `./first`.

### C Types

Go into the `types` directory and look at `types.c` in a code editor (syntax highlighting will be nice). Read through it and try the challenges.

### Functions

Go into the `funcs` directory and look at `funcs.c` in a code editor. Read through it and try the challenge.
