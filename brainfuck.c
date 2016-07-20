/////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2016 Eli David Sadoff                                         //
//                                                                             //
// Permission is hereby granted, free of charge, to any person obtaining a     //
// copy of this software and associated documentation files (the "Software"),  //
// to deal in the Software without restriction, including without limitation   //
// the rights to use, copy, modify, merge, publish, distribute, sublicense,    //
// and/or sell copies of the Software, and to permit persons to whom the       //
// Software is furnished to do so, subject to the following conditions:        //
//                                                                             //
// The above copyright notice and this permission notice shall be included in  //
// all copies or substantial portions of the Software.                         //
//                                                                             //
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  //
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,    //
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL     //
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  //
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING     //
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER         //
// DEALINGS IN THE SOFTWARE.                                                   //
/////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////
// File: brainfuck.c                                                           //
// Author: Eli D. Sadoff                                                       //
// Contact:                                                                    //
// - Email: snood1205@gmail.com                                                //
// License: MIT License                                                        //
// Since: July 20, 2016                                                        //
/////////////////////////////////////////////////////////////////////////////////
#include "brainfuck.h"

#define SIZE 30000

static char cells[SIZE];
static unsigned int pointer;

int main() {
    /////////////////////////////////////////////////////////////////////////////
    // This method is the main method for the program.                         //
    /////////////////////////////////////////////////////////////////////////////

    parse();
    return 0;
}

void initialize() {
    /////////////////////////////////////////////////////////////////////////////
    // This method initializes the array cells of constant #SIZE and sets the  //
    // value of each cell to 0. Additionally it sets the the value of pointer  //
    // to 0.                                                                   //
    /////////////////////////////////////////////////////////////////////////////

    for (pointer = 0; pointer < SIZE; pointer++) {
        cells[pointer] = 0;
    }
    pointer = 0;
    printf("$ ");
}

void execute(char a) {
    /////////////////////////////////////////////////////////////////////////////
    // This method executes each character provided to it:                     //
    // - '>' -> increments the pointer by 1                                    //
    // - '<' -> decrements the pointer by 1                                    //
    // - '+' -> increments the value of the cell pointed to by 1               //
    // - '-' -> decrements the value of the cell pointed to by 1               //
    // - '.' -> outputs the ASCII char value of the cell                       //
    // - ',' -> accepts one ASCII char value of input                          //
    // - '[' -> creates a while loop, runs what is inside '[]' until the value //
    // of the cell pointed to is 0                                             //
    // - ']' -> closing brace of while loop                                    //
    // - '\n' -> goes to the next line                                         //
    // Parameter:                                                              //
    // - a (char) -> the character to execute                                  //
    /////////////////////////////////////////////////////////////////////////////

    if (a == '>') {
        increment_pointer();
    } else if (a == '<') {
        decrement_pointer();
    } else if (a == '+') {
        increment_cell();
    } else if (a == '-') {
        decrement_cell();
    } else if (a == '.') {
        output();
    } else if (a == ',') {
        input();
    } else if (a == '[') {
        forward();
    } else if (a == ']') {
        backward();
    } else if (a == '\n') {
        printf("\n$ ");
    }
}

void parse() {
    /////////////////////////////////////////////////////////////////////////////
    // This parses the input and runs a while loop until the program is        //
    // aborted.                                                                //
    /////////////////////////////////////////////////////////////////////////////

    initialize();
    char a;
    do {
        a = getchar();
        execute(a);
    } while (1);
}

void increment_pointer() {
    /////////////////////////////////////////////////////////////////////////////
    // This increments the pointer by 1. This means that the cell that is      //
    // being pointed to is moved forward.                                      //
    /////////////////////////////////////////////////////////////////////////////

    pointer++;
}

void decrement_pointer() {
    /////////////////////////////////////////////////////////////////////////////
    // This decrements the pointer by 1. This means that the cell that is      //
    // being pointed to is moved backwards.                                    //
    /////////////////////////////////////////////////////////////////////////////

    pointer--;
}

void increment_cell() {
    /////////////////////////////////////////////////////////////////////////////
    // This increments the value of the cell by 1.                             //
    /////////////////////////////////////////////////////////////////////////////

    cells[pointer]++;
}

void decrement_cell() {
    /////////////////////////////////////////////////////////////////////////////
    // This decrements the value of the cell by 1.                             //
    /////////////////////////////////////////////////////////////////////////////

    cells[pointer]--;
}

void output() {
    /////////////////////////////////////////////////////////////////////////////
    // This prints the ASCII char value of the cell being pointed to.          //
    /////////////////////////////////////////////////////////////////////////////

    printf("%c", cells[pointer]);
}

void input() {
    /////////////////////////////////////////////////////////////////////////////
    // This set the value of the cell being pointed to as the ASCII char       //
    // input.                                                                  //
    /////////////////////////////////////////////////////////////////////////////

    scanf("%c", & cells[pointer]);
}

void forward() {
    /////////////////////////////////////////////////////////////////////////////
    // This creates a while loop, which runs until the cell being pointed to   //
    // has a value of 0.                                                       //
    /////////////////////////////////////////////////////////////////////////////

    static char buffer[SIZE];
    int i, p, max;
    char a;
    a = getchar();
    p = pointer;
    for (i = 0; a != ']'; i++) {
        buffer[i] = a;
        a = getchar();
    }
    max = i;
    for (i = 0; cells[p] != 0; i++) {
        if (i == max) {
            i = 0;
        }
        a = buffer[i];
        execute(a);
    }
}


void backward() {
    /////////////////////////////////////////////////////////////////////////////
    // This has no function, but exists just to exist.                         //
    /////////////////////////////////////////////////////////////////////////////

    ;
}
