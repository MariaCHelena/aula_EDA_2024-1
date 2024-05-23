#include <stdio.h>

int smallerIndex(int *vet, int tam, int ini){
	int min = ini, j;
	for(j=ini+1; j<tam; j++){
		if(vet[min] > vet[j])
			min = j;
	}
	return min;
}

void selectionSort(int *vet, int tam){
	int i, min, aux;
	for(i = 0; i < tam; i++){
		min = smallerIndex(vet, tam, i);
		aux = vet[i];
		vet[i] = vet[min];
		vet[min] = aux;
	}
}

void printVet(int *vet, int tam, char *label){
	printf("%s\n", label);
	for(int i = 0; i < tam; i++){
		printf("%d ", vet[i]);
	}
	puts(" ");

}

int main(){
	int vet[] = {20, 3, 1, 81, 50, 4}, tam = 6;
	printVet(vet, tam, "Vetor desordenado");
	selectionSort(vet, tam);
	printVet(vet, tam, "Vetor ordenado");
	return 0;
}
