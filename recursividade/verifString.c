#include <stdio.h>
#include <stdlib.h>

int verifstring(int *a, int *b, position){
	if(a[position] == b[position]){
		if (position == 0){
			return 0;
		}
	}
	return 0;
}

int main(){
	char a[] = "teste" , b[] = "teste";
	printf("%s\n", a);
	printf("%s\n", b);
	result = verifstrig(a, b, sizeof(a) - 1);
	return 0;
}


