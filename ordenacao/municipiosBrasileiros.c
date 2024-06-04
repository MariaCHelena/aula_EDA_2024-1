#include <stdio.h>
#include <stdlib.h>

int smallerIndex(int *vet, int tam, int ini){
	int min = ini, j;
	for(j=ini+1; j<tam; j++){
		if(vet[min] > vet[j])
			min = j;
	}
	return min;
}

int selectionSort(int *vet, int tam){
	int i, min, aux;
	for(i = 0; i < tam; i++){
		min = smallerIndex(vet, tam, i);
		aux = vet[i];
		vet[i] = vet[min];
		vet[min] = aux;
	}
}

int printVet(int *vet, int tam, char *label){
	printf("%s\n", label);
	for(int i = 0; i < tam; i++){
		printf("%d ", vet[i]);
	}
	puts(" ");

}

int getField(int *vet, FILE *file){
	char ch;
	int temp = 0, count = 0, pos = 0;
	while(1){
		ch = fgetc(file);
		if(ch == EOF)
			break;
		if(count < 4){
			if(ch == 59)
				count++;
		} else {
			if(ch == 10){
				pos++;
				count = 0;
			} else {
				vet[pos] = vet[pos] * 10 + (ch - '0');
			}
		}
	}
}

int main(){
	int vet[5570], tam, count, pos, countPV = 0;
	FILE *f;
	char ch, line[1024];

 	f = fopen("data.csv", "r");

	/*
	while(1){
		ch = fgetc(f);
		if(ch == EOF)
			break;
		if(ch == 10){
			tam++;
		}
	}
	vet =  malloc(6000 * sizeof(int));

	*/

	int temp = 0, isFirst = 0;
	pos = -1;
	count = 0;
	while(1){
		ch = fgetc(f);
		if(ch == EOF)
			break;
		if(count < 4){
			if(ch == 59)
				count++;
		} else {
			if(ch == 10){
				count = 0;
				if(pos != -1){
					isFirst = 1;
				}
				if(isFirst){
					vet[pos] = temp;
//					printf("%d\n", temp);
				}
				temp = 0;
				pos++;
			} else {
				int char_int = ch - '0';
				if(char_int >= 0)
					temp = temp * 10 + char_int;
			}
		}
	}

//	printf("%d\n", pos);
//	printf("%d", vet[0]);

	printVet(vet, tam, "Vetor dos bagulho lah tlg");

	fclose(f);

	/*
		printVet(vet, tam, "Vetor desordenado");

		selectionSort(vet, tam);

		printVet(vet, tam, "Vetor ordenado");
	*/

	return 0;
}
