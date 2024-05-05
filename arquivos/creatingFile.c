#include <stdio.h>

int main(){
  FILE *nf, *cp;
  char newFile[50], copyFile[50], ch;
  printf("Digite o nome do arquivo que deseja criar:\n");
  scanf("%s", &newFile);
  printf("Digite qual arquivo que deseja copiar:\n");
  scanf("%s", &copyFile);

  nf = fopen(newFile, "a");
  cp = fopen(copyFile, "r");

  while(1){
     ch = fgetc(cp);
     if(ch == EOF)
       break;
     fputc(ch, nf);
  }

  fclose(nf);
  fclose(cp);

  return 0;
}
