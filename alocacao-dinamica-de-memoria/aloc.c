#include <stdio.h>
#include <stdlib.h>

#define MALLOC(ptr, size){\
	ptr = malloc(size); \
	if (ptr = NULL) { \
		fprintf(stderr, "memoria insuficiente\n"); \
		exit(1); \
	} \
}

void *malloc_s(size_t size){
	void *p;
	p = malloc(size);
	if (p == NULL){
		fprintf(stderr, "memoria insuficiente\n");
		exit(1);
	}
	return p;
}

int main(int argc, char **argv){

	int *p;

	p = malloc_s(5 * sizeof(int));
	
	// MALLOC(p, sizeof(int));
	
	*p = 9;
	*(p + 1) = 43;

	printf("%d\n", *p);
	printf("%d\n", *(p + 1));

	free(p);

	return 0;
}
