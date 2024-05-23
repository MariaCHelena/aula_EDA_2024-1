#include <stdio.h>

int main(){
  int count = 2;
  FILE *f;
  char file[50], ch;
  printf("Digite qual arquivo que deseja ler:\n");
  scanf("%s", file);

  f = fopen(file, "r");

  while(1){
     ch = fgetc(f);
     if(ch == EOF)
       break;
     putchar(ch);
     if(ch == 10){
	     count++;
     }
  }

  fclose(f);
  puts("");

  printf("%d\n", count);

  return 0;
}
