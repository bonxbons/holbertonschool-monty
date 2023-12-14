#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 1000

typedef struct {
    int stack[STACK_SIZE];
    int top;
} Stack;

void push(Stack *stack, int value);
void pall(Stack *stack);

#endif /* MONTY_H */

// monty.c
#include "monty.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    Stack stack;
    stack.top = -1; // Initialize an empty stack
    int line_number = 1; // Initialize line number

    char opcode[100];
    int value;

    while (fscanf(file, "%s", opcode) == 1) {
        if (strcmp(opcode, "push") == 0) {
            if (fscanf(file, "%d", &value) != 1) {
                fprintf(stderr, "L%d: Error: Usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            push(&stack, value);
        } else if (strcmp(opcode, "pall") == 0) {
            pall(&stack);
        } else {
            fprintf(stderr, "L%d: Error: Unknown opcode %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }

        line_number++; // Increment line number for the next iteration
    }

    fclose(file);
    return 0;
}
