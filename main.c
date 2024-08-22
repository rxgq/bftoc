#include <stdio.h>
#include <string.h>

int main() {
    char *bf = "++++++++++[>+++++++>++++++++++>+++>+<<<<-]>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>.";
    FILE *f = fopen("out.c", "w");
    fprintf(f, "#include<stdio.h>\n\nint main(){char t[256]={0};char*p=t;\n");
    
    for (int i = 0; i < strlen(bf); i++) {
        if (bf[i] == '+') fprintf(f, "++*p;\n");
        else if (bf[i] == '-') fprintf(f, "--*p;\n");
        else if (bf[i] == '<') fprintf(f, "p--;\n");
        else if (bf[i] == '>') fprintf(f, "p++;\n");
        else if (bf[i] == '.') fprintf(f, "putchar(*p);\n");
        else if (bf[i] == ',') fprintf(f, "*p=getchar();\n");
        else if (bf[i] == '[') fprintf(f, "while(*p){\n");
        else if (bf[i] == ']') fprintf(f, "}\n");
    }
    
    fprintf(f, "return 0;\n}");
    fclose(f);
    return 0;
}
