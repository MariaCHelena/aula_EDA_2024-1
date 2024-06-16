#include <stdio.h>
#include <stdlib.h>

int buscaSequencialDesordenada(int *v, int n, int chave){
  int p, posic = -1;
  for(p = 0; p < n; p++)
    if(chave == v[p])
      posic = p;
  return posic;
}

int buscaSequecialOrdenada(int *v, int n, int chave){
  int p=0, posic = -1;
  while (p < n && chave <= v[p]){
    if(v[p] == chave){
      posic = p;
      break;
    }
    p++;
  }
  return posic;
}

int buscaBinaria(int *v, int n, int chave){
  int p, inicio, final, meio;
  inicio = 0;
  final = n - 1;
  while(inicio <= final){
    meio = (inicio + final)/2;
    if(chave == v[meio])
      return meio;
    if (chave < v[meio])
      final = meio - 1;
    else
      inicio = meio + 1;
  }
  return -1;
}

int main(){

}
