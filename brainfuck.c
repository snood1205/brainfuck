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
    for (pointer = 0; pointer < SIZE; pointer++) {
        cells[pointer] = 0;
    }
    pointer = 0;
}

void execute(char a) {
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
    }
}

void parse() {
    initialize();
    char a;
    do {
        a = getchar();
        execute(a);
    } while (1);
}

void increment_pointer() {
    pointer++;
}

void decrement_pointer() {
    pointer--;
}

void increment_cell() {
    cells[pointer]++;
}

void decrement_cell() {
    cells[pointer]--;
}

void output() {
    printf("%c", cells[pointer]);
}

void input() {
    scanf("%c", & cells[pointer]);
}

void forward() {
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
    ;
}