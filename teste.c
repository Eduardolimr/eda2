#include <stdio.h>
#include <stdlib.h>

#define TAM_DICIO 100000
#define TAM_MAX 46
#define dicio "dicioPadrao"

unsigned int RSHash(const char* str, unsigned int length)
{
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;
   unsigned int i    = 0;

   for (i = 0; i < length; ++str, ++i)
   {
      hash = hash * a + (*str);
      a    = a * b;
   }

   return hash;
}

int contaPalavrasDic(void){
  FILE *fd;
  char temp[TAM_MAX];
  int i;

  i = 0;
  fd = fopen(dicio, "r");
  if(fd != NULL){
    while(fgets(temp, TAM_MAX, fd)){
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
  char temp[TAM_MAX];

  fd = fopen(dicio, "r");
  if(fd != NULL){
    while(fgets(temp, TAM_MAX, fd)){
      i = RSHash(temp, TAM_MAX)/103811;
      dicionario[i] = temp;
      printf("%i %s", i, dicionario[i]);
    }
  }
  return 0;
}
