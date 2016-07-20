//
// Created by Eli David Sadoff on 7/19/16.
//

#ifndef BRAINFUCK_BRAINFUCK_H
#define BRAINFUCK_BRAINFUCK_H

#include "stdio.h"

void initialize();

void execute(char);

void parse();

void increment_pointer();

void decrement_pointer();

void increment_cell();

void decrement_cell();

void output();

void input();

void forward();

void backward();

#endif //BRAINFUCK_BRAINFUCK_H
