#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int SIZE = 30000;

void interpret(const char* code) {
    char memory[SIZE];
    int pointer = 0;

    int loop_stack[SIZE];
    int loop_index = 0;

    for (int i = 0; code[i] != '\0'; i++) {
        switch (code[i]) {
            case '>':
                pointer++;
                break;
            case '<':
                pointer--;
                break;
            case '+':
                memory[pointer]++;
                break;
            case '-':
                memory[pointer]--;
                break;
            case '.':
                putchar(memory[pointer]);
                break;
            case ',':
                char c = getchar();
                memory[pointer] = c;
                break;
            case '[':
                if (memory[pointer] == 0) {
                    int count = 1;
                    while (count > 0) {
                        i++;
                        if (code[i] == '[') {
                            count++;
                        } else if (code[i] == ']') {
                            count--;
                        }
                    }
                } else {
                    loop_stack[loop_index++] = i;
                }
                break;
            case ']':
                if (memory[pointer] != 0) {
                    i = loop_stack[loop_index - 1];
                } else {
                    loop_index--;
                }
                break;
            default:
                break;
        }

        if (pointer < 0) {
            pointer = 0;
        } else if (pointer >= SIZE) {
            pointer = SIZE - 1;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <file_path_to_txt_file>\n", argv[0]);
        return 1;
    }

    const char* file_path = argv[1];

    FILE *fptr = fopen(file_path, "r");
    if (fptr == NULL) {
        perror("Error opening file");
        return 1;
    }

    fseek(fptr, 0, SEEK_END);
    long file_size = ftell(fptr);
    rewind(fptr);

    char *code = (char *) malloc(file_size + 1);
    size_t bytes_read = fread(code, sizeof(char), file_size, fptr);
    code[file_size] = '\0';

    fclose(fptr);

    interpret(code);

    free(code);
    return 0;
}