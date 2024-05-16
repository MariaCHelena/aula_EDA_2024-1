#include <stdio.h>

void imprime(char *s){
	while (*s)
		putchar(*s++);
}

int main(){
	char s[] = "maria";
	char *t = "maria";

	imprime(s);
	puts("");
	return 0;
}
