Brainfuck
=============================

Purpose:
-----------------------------
The purpose of this project is to create a brainfuck interpreter in C.
Currently, all this is is a REPL (Read-Evaluate-Print-Loop) interpreter
and does not yet compile brainfuck files.

Installation:
-----------------------------
1. Download the git repository from github using these steps:
    * `git clone git@github.com:snood1205/brainfuck.git`
2. Change into the repository
    * `cd brainfuck`
3. Compile the program
    * `make brainfuck`
4. Run the REPL
    * `./brainfuck`

Usage:
-----------------------------
Once the REPL is running you can use the following 8 commands which make up
any brainfuck program. A brainfuck program, for all intents and purposes,
is compromised of an array of at least 30,000 byte sized cells. Each cell
is initialized to 0 and the pointer is pointed to the first cell.

Commands:
* `+` &rarr; Increments the value of the cell being pointed to.
* `-` &rarr; Decrements the value of the cell being pointed to.
* `>` &rarr; Points to the next cell.
* `<` &rarr; Points to the previous cell.
* `.` &rarr; Outputs the ASCII value of the current cell.
* `,` &rarr; Sets the value of the cell being pointed to, to the ASCII
value inputted.
* `[` &rarr; Creates a while loop and executes what is within the braces
until the value of the cell being pointed to has the value 0.
* `]` &rarr; Closes the while loop.

The prompt is '$'.

Example:
-----------------------------
Hello World:
```brainfuck
$ ++>++++++++++[<+++++++>-]
$ +>++++++++++[<++++++++++>-]
$ ++++++++>++++++++++[<++++++++++>-]
$ ++++++++>++++++++++[<++++++++++>-]
$ +>++++++++++[<+++++++++++>-]
$ ++>++++++++++[<+++>-]
$ +++++++>++++++++++[<++++++++>-]
$ +>++++++++++[<+++++++++++>-]
$ ++++>++++++++++[<+++++++++++>-]
$ ++++++++>++++++++++[<++++++++++>-]
$ >++++++++++[<++++++++++>-]
$ <<<<<<<<<<<<
$ >.>.>.>.>.>.>.>.>.>.
```
License:
-----------------------------
Copyright (c) 2016 Eli David Sadoff

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Contact:
-----------------------------
Author: Eli Sadoff
Email: snood1205@gmail.com
