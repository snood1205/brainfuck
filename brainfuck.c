//
// Created by Eli David Sadoff on 7/19/16.
//

#include "brainfuck.h"

#define SIZE 30000

static char cells[SIZE];
static unsigned int pointer;

int main() {
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