#include<stdio.h>

void main() {
    FILE*f=fopen("o.c","w"),*in=fopen("c.bf","r");char b[1024];
    fprintf(f, "#include<stdio.h>\nchar t[1<<24],*p=t;\nvoid main(){"); 
    while(fgets(b,sizeof(b),in)) for(char*c=b;*c;c++)
        fprintf(f,*c=='+'?"++*p;":*c=='-'?"--*p;":*c=='<'?"p--;":*c=='>'?"p++;":*c=='.'?"putchar(*p);":*c==','?"*p=getchar();":*c=='['?"while(*p){":*c==']'?"}":"");
    fprintf(f,"}");
}