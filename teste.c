#include <stdio.h>
#include <stdlib.h>

#define TAM_DICIO 10
#define dicio "dicioTeste.txt"

int contaPalavrasDic(void){
  FILE *fd;
  char temp[45];
  int i;

  i = 0;
  fd = fopen(dicio, "r");
  if(fd != NULL){
    while(fgets(temp, 45, fd)){
      i++;
    }
    fclose(fd);
    return i;
  }
  return 0;
}


int main(void){
  int qtdePalavras;
  int i;
  FILE *fd;
  const char *dicionario[TAM_DICIO];
  char temp[46];

  i = 0;
  fd = fopen(dicio, "r");
  if(fd != NULL){
    while(fgets(temp, 46, fd)){
      dicionario[i] = temp;
      printf("%i %s", i, dicionario[i]);
      i++;
    }
  }
  return 0;
}
