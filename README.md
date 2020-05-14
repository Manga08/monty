 # <a href="https://www.holbertonschool.com"><img src="https://camo.githubusercontent.com/04a8a9a456b8ecafad2eb4f2cff6803cd0194496/687474703a2f2f7777772e686f6c626572746f6e7363686f6f6c2e636f6d2f686f6c626572746f6e2d6c6f676f2e706e67" alt="Sin-ti-tulo-1" width="200" height="70" border="0"></a>Stacks, Queues - LIFO, FIFO

<img alt="Love" src=https://pbs.twimg.com/media/CFYYWy6UEAE9Ow-.png>

 # <a href="https://www.holbertonschool.com"><img src="https://www.holbertonschool.com/holberton-logo-simple-200s.png" alt="Sin-ti-tulo-1" width="50" height="50" border="0"></a> Documentation

## Table of contents
* [About](#about)
* [Requirements](#requirements)
* [Instalation](#instalation)
* [Compilation](#compilation)
* [Written in](#written-in)
* [Commands](#commands)
* [Example of use](#example-of-use)
* [Examples](#examples)
* [Files and functions](#files-and-functions)
* [Authors](#authors)

## About
The goal of this project is to create an interpreter for Monty ByteCodes files.

## Requirements
* Ubuntu 14.04 LTS
* gcc version 4.8.4

## Instalation
*  Clone this repository:
```sh
git clone https://github.com/Manga08/monty.git
```
* Inside the repository, compile.
* Execute:
```sh
./monty
```

## Compilation
```sh
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
## Written in
* GNU Emacs 24.3.1
* C language

## Commands

| **Opcode** | **Description** |
|--|--|
| push | Pushes an element to stack |
| pall | Prints all elements in stack |
| pint | Prints first stack node |
| pop | Removes removes last stack node |
| swap | Inverts stack nodes positions |
| nop | Doesn’t do anything |
| sub | Subtracts top two stack elements |
| div | Divides top two stack elements |
| mul | Multiplies top two stack elements |
| mod | Computes division remainder from top two stack elements |
| # | Comments instruction |
| pchar | Prints first stack element in ascii value |
| pstr | Prints all stack elements in ascii value |
| rotl | Sends first stack element to last position |
| rotr | Send last stack element to first position |
| stack | Sets stack format to LIFO (Last In First Out) |
| queue | Sets stack format to FIFO (First In, First Out) |

## Example of use

* Execute the monty file with a ```.m ``` file:
```
$ ./monty <yourfile.m>
```
* Execute like this:
```
$ cat <yourfile.m>
push 1
push 2
push 3
pall
$ ./executable_file <yourfile.m>
3
2
1
```
##  Examples

```
$ cat -e 01.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
```

```
$ ./execuablte_file 01.m
3
2
1
0
4
3
2
1
0
6

```

```
$ cat 02.m
push 1
push 2
push 3
pall
pop
pall
$ ./executable_file 02.m
3
2
1
2
1

```

```
$ cat 03.m
push 1
push 2
push 3
pall
swap
pall
$ ./executable_file 03.m
3
2
1
2
3
1

```

```
$ cat 04.m
push 1
push 2
push 3
pall
add
pall
$ ./executable_file 04.m
3
2
1
5
1
```

## Files and functions
* [get_op.c](get_op.c) - Get the different operations in the monty file and validates them.
  * `free_function` - Free the memory of the linked list.
  * `valid_num` - Validate the token.
  * `get_op` - Get the different operations in the monty file.
* [main.c](main.c) - Read the file and tokenize the content of the file.
  * `tokenize` - Tokenize a line in to tokens, only get two first tokens.
  * `enterfile` - Enter and read the monty file.
  * `main` - Main function.
* [monty.h](monty.h) - The header file
* [op_functions.c](op_functions.c) - List of the fucntions of the commands.
  * `push_op` - Pushes an element to the stack.
  * `pall_op` - Prints all the values on the stack.
  * `pint_op` - Prints the value at the top of the stack.
  * `pop_op` - Removes the top element of the stack.
  * `swap_op` - Swaps the top two elements of the stack.
* [op_functions2.c](op_functions2.c) - List of another fucntions of the commands.
  * `add_op` - Adds the top two elements of the stack.
  * `nop_op` - Doesn’t do anything.
  * `sub_op` - Subtracts the top element of the stack.
  * `div_op` - Divides the top two elements of the stack.
  * `mul_op` - Multiplies the top two elements of the stack.
* [op_functions3.c](op_functions3.c) - List of another fucntions of the commands.
  * `mod_op` - Computes division remainder from top two stack elements.
  * `pchar_op` - Prints the char at the top of the stack.
  * `pstr_op` - Prints the string starting at the top of the stack.
  * `rotl_op` - Rotates the stack to the top.
  * `rotr_op` - Rotates the stack to the bottom.

## Authors
### - Manuel Acero 
Github: [Manga08](https://github.com/Manga08) Twitter: [@MangaAcero](https://twitter.com/MangaAcero)

### - Juan David Suarez
Github: [juandsuarezz](https://github.com/juandsuarezz) Twitter: [@juandsuarezz1](https://twitter.com/juandsuarezz1)