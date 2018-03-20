# Introduction to C

This repository is the workshop materials for the Linux@App Introduction to C
event.

## Using this Repo

This repository is intended to teach the following skills:

* Basic C compiler usage
* Basic C preprocessor tricks
* Basic C types
* Basic functions
* C strings and memory management
* Basic structures
* How to get help with and use the C standard library

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

### Hello world
First, cd into the `first` directory and run `make first-all`. The outputs that are generated
are the results from each stage of the c compilation pipeline:

* `first.E` is the result of running the preprocessor. You should look at this, as it will help make sense of what #include actually does
* `first.s` is the compiled version of the code. It is presented in human-readable assembly language.
* `first.o` is the assembled version of the code. It is a binary file, so view it with `xxd` or similar. Ordinarily, several object files are combined to form an executable, which is the stage after assembling in the compilation pipeline.
* `first` is an executable file built by linking `first.o`. Try it with `./first`.

### Preprocessor

Go into the `cond` directory and look at `cond.c`. This file demonstrates how you can implement
conditional logic with the preprocessor. If the symbol `YES` is defined when it is compiled, it
will print one thing. Otherwise, it will print another.

Try:
```
$ gcc -DYES=1 -o cond cond.c
$ ./cond
```

Then, try:
```
$ gcc -o cond cond.c
$ ./cond
```

The output is different because the preprocessor literally rewrote the code depending on whether the
symbol `YES` was defined. As you can see, the `-D` flag to the compiler lets us define a preprocessor
symbol on the compiler command line.

We can also define symbols in our code with:
```c
#define YES 1
```
Note that we are not assigning with a `=` symbol. The symbol name and value are separated by a space.

### C Types

Go into the `types` directory and look at `types.c` in a code editor (syntax highlighting will be nice). Read through it and try the challenges.

### Functions

Go into the `funcs` directory and look at `funcs.c` in a code editor. Read through it and try the challenge.

### Strings and Memory

Go into the `str_mem` directory and look at `str_mem.c` in a code editor. Read through it and try the challenge.

### Structs

Go into the `struct` directory and look at `struct.c` in a code editor. Read through it and try the challenge.

### Getting help with the C standard library

Most languages have a source of documentation that we consult on the internet, but doing that for C
can be quite frustrating. The documentation is out there, but it can be hard to find. This is because
most C programmers don't need to go to the internet to find it. Linux systems actually already have
all of the documentation for the C standard library. You just need to know how to find it.

If you want to get help with a subject like strings, try the following:
```
$ apropos string | less
```
The `apropos` command searches the installed documentation for information relevant to the keywords
that you provided.

```
<output truncated>
stpcpy (3)           - copy a string returning a pointer to its end
stpncpy (3)          - copy a fixed-size string, returning a pointer to its end
strcasecmp (3)       - compare two strings ignoring case
strcasestr (3)       - locate a substring
strcat (3)           - concatenate two strings
strchr (3)           - locate character in string
strchrnul (3)        - locate character in string
strcmp (3)           - compare two strings
strcoll (3)          - compare two strings using the current locale
strcpy (3)           - copy a string
<output truncated>
```

Each line of output is a documentation page related to your keyword. To view that documentation,
you can type:
```
man <paren-num> <first-word>
```
So to view `strcmp (3) ...`, I would type `man 3 strcmp`.
