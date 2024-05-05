#include <stdio.h>

int main(){
  FILE *fp;
  char ch;
  int car = 0, esp = 0, tab = 0, nl = 0;
  fp = fopen("POEM.TXT", "r");
  while(1){
    ch = fgetc(fp);
    if(ch == EOF)
      break;
    if(ch == 9){
      tab++;
    } else if (ch == 32){
      esp++;
    } else if (ch == 10){
      nl++;
    } else {
      car++;
    }

    printf("%c", ch);
  }
  fclose(fp);

  printf("Caracteres: %d, Espacos: %d, Tabs: %d, New Lines: %d\n", car, esp, tab, nl);

  return 0;
}
