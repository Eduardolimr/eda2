#include<stdio.h>
#include<string.h>

int compare(char *str1, char *str2){
  while ( *str1 != '\0' && *str1 == *str2 )
  {
   ++str1;
   ++str2;
 }
return (*str1 - *str2);
}

int main(){
  char str1[30],str2[30];
  scanf("%s", str1);
  scanf("%s", str2);


printf ("%d\n", compare(str1, str2));

printf("%d\n", 'a'-'z');
  return 0;
}
