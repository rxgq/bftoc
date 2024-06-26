#include <stdio.h>
#include <stdlib.h>

const int SIZE = 30000;
#define INCR '+'
#define DECR '-'
#define PREV '<'
#define NEXT '>'
#define OUTC '.'
#define INPC ','
#define LOOP_START '['
#define LOOP_END ']'

void interpret(const char* code) {
    char tape[SIZE];
    int ptr = 0;
    int loop_stack[SIZE];
    int loop_index = 0;

    for (int i = 0; code[i] != '\0'; ++i) {
        switch (code[i]) {
            case NEXT: ptr++; break;
            case PREV: ptr--; break;
            case INCR: tape[ptr]++; break;
            case DECR: tape[ptr]--; break;
            case OUTC: putchar(tape[ptr]); break;
            case INPC: tape[ptr] = getchar(); break;
            case LOOP_START:
                if (!tape[ptr]) {
                    int count = 1;
                    while (count) {
                        count += (code[++i] == LOOP_START) - (code[i] == LOOP_END);
                    }
                } else {
                    loop_stack[loop_index++] = i;
                }
                break;
            case LOOP_END:
                if (tape[ptr]) {
                    i = loop_stack[loop_index - 1];
                } else {
                    loop_index--;
                }
                break;
            default:
                break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path_to_bf_file>\n", argv[0]);
        return 1;
    }

    FILE *fptr;
    if ((fptr = fopen(argv[1], "r")) == NULL) {
        perror("Error opening file");
        return 1;
    }

    fseek(fptr, 0, SEEK_END);
    long file_size = ftell(fptr);
    rewind(fptr);

    char *code = (char *) malloc(file_size + 1);
    fread(code, 1, file_size, fptr);
    fclose(fptr);
    code[file_size] = '\0';

    interpret(code);

    free(code);
    return 0;
}