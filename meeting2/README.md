# Introduction to C

### Pointers and Arrays

Let's start with a review of pointers and arrays in C. Open `ptr_arr` and look at `ptr_arr.c`. Read through it and try the challenge.

### Strings and Memory

Go into the `str_mem` directory and look at `str_mem.c` in a code editor. Read through it and try the challenge.

### Structs

Go into the `struct` directory and look at `struct.c` in a code editor. Read through it and try the challenge.

### Methods

C has idioms that resemble methods (functions that act on structures). Open the `methods` folder and read through `methods.c`. Try the challenge.

### Headers and Modularization

How do you break your source code into more than one file? Let's find out. Open `modules` and read through `modules.c`

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
