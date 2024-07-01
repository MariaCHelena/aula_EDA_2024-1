#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long int insercao(int n, int v[])
{
   long int sum = 0;
   for (int j = 1; j < n; ++j) {
      int x = v[j];
      int i;
      for (i = j-1; i >= 0 && v[i] > x; --i){
         v[i+1] = v[i];
         sum++;
      }
      v[i+1] = x;
   }
   return sum;
}

long int bs(int n, int *vetor) {
  long int count = 0;
	int c = 0, d, troca, trocou = 1;
	while ((c < (n - 1)) & trocou) {
		trocou = 0;
		for (d = 0; d < n - c - 1; d++)
			if (vetor[d] > vetor[d + 1]) {
				troca = vetor[d];
				vetor[d] = vetor[d + 1];
				vetor[d + 1] = troca;
				trocou = 1;
        count++;
			}
		c++;
	}
  return count;
}

int bubbleSort(int tam, int vet[]){
  int count = 0;
	int i, j, temp, trocou = 1;
	for(i = tam-1; i > 0; i--){
		trocou = 0;
		for(j = 0; j < i; j++)
			if(vet[j] > vet[j+1]){
				temp = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = temp;
				trocou = 1;
        count++;
			}
    if(trocou)
      break;
	}
  return count;
}

int insertionSort(int n, int list[]){
  int count = 0;
	int i, j;
	int next;
	for (i=1; i < n; i++){
		next = list[i];
		for (j = i - 1; j >= 0 && next < list[j]; j--)
			list[j+1] = list[j];
      count++;
		list[j+1] = next;
	}
  return count;
}

void printMenu(char *ptr){

  puts("==========================================");
  puts("");
  puts("COMPLEXIDADE DE CODIGO");
  puts("");
  puts("==========================================");
  puts("");
  puts("T - gerar arquivo esforcocomputacional.txt;");
  puts("R - ler arquivo gerado e contabilizar dados;");
  puts("S - sair");
  puts("");

  char c;

  scanf("%c", &c);

  *ptr = c;

  getchar();
}

void printInfo(int n, long int vet[], char *label){
  long int maior = 0, menor = 0, media = 0;
  char string[128];
  for (int i = 0; i < n; i++)
  {
    if(i == 0)
      menor = vet[i];
    if(vet[i] > maior)
      maior = vet[i];
    if(vet[i] < menor)
      menor = vet[i];
    media += vet[i];
  }

  sprintf(string, "%s: %d, %d, %d", label, media/n, menor, maior);
  puts(string);
}

int main(){
  char escolha, *ptr, ch;
  int pos = 0, tam = 0, count, *arquivo;
  long int *opsIns, *opsBs;
  FILE *f, *f2;
  srand(time(NULL));
	clock_t ti, tf;

  f = fopen("testes.txt", "r");
  f2 = fopen("testes.txt", "r");

  ptr = &escolha;

  while(1){
    if(escolha == 83)
      break;
    printMenu(ptr);
    switch (escolha){
    case 'T':
      while(1){
        ch = fgetc(f);
        if(ch == EOF){
          tam++;
          break;
        }
        if(ch == 10){
          tam++;
        }
      }

      arquivo = malloc(tam * sizeof(int));
      opsIns = malloc(tam * sizeof(int));
      opsBs = malloc(tam * sizeof(int));
      int temp = 0;

      while(1){
        ch = fgetc(f2);
        if(ch == EOF){
          arquivo[pos] = temp;
          break;
        }
        if(ch == 10){
          arquivo[pos] = temp;
          temp = 0;
          pos++;
        } else {
          int char_int = ch - '0';
          temp = temp * 10 + char_int;
        }
      }

      FILE *nf;

      nf = fopen("esforcocompucaional.txt", "a");

      for (int i = 0; i < tam; i++)
      {
        char string[128];
        int *cp, *vet;
        vet = (int *)malloc(arquivo[i] * sizeof(int));
        cp = (int *)malloc(arquivo[i] * sizeof(int));
        for (int j = 0; j < arquivo[i]; j++)
        {
          int r = rand();
          vet[j] = r;
          cp[j] = r;
        }

        opsIns[i] = insercao(arquivo[i], vet)/arquivo[i];
        opsBs[i] = bs(arquivo[i], cp)/arquivo[i];

        sprintf(string, "[%d,%d,%d],", arquivo[i], opsBs[i], opsIns[i]);
        fputs(string, nf);
        fputs("\n", nf);
        free(vet);
        free(cp);
      }

      fclose(nf);
    break;

    case 'R':
      printInfo(tam, opsBs, "Dados eB");
      printInfo(tam, opsIns, "Dados eI");
    break;

    case 'S':
      fclose(f);
      fclose(f2);
      free(arquivo);
      free(opsIns);
      free(opsBs);
    break;

    default:
      break;
    }
  }


  return 0;
}
