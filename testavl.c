#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
  char palavra[45];
  struct node* left;
  struct node* right;
}Node;

int compare(char *str1, char *str2){
  while ( *str1 != '\0' && *str1 == *str2 )
  {
   ++str1;
   ++str2;
 }
return (*str1 - *str2);
}

Node* insert(Node* root, char *nome){
  int i=0;
  if(root == NULL){
    Node* novo = (Node*)malloc(sizeof(Node));
    strcpy(novo->palavra, nome);
    printf("%s\n", novo->palavra);
    novo->left = NULL;
    novo->right = NULL;
    root = novo;
    return root;
  }
  else{
    if(compare(nome,root->palavra)>0){
      root->left = insert(root->left, nome);
    }
    else if(compare(nome,root->palavra)<0){
      root->right = insert(root->right, nome);
    }
  }
}

Node *imprimeArvore(Node *raiz){
  if(raiz->right != NULL){
    raiz->right = imprimeArvore(raiz->right);
  }
  printf("%s ", raiz->palavra);
  if(raiz->left != NULL){
    raiz->left = imprimeArvore(raiz->left);
  }
  return raiz;
}

Node *destroiArvore(Node *raiz){
  if(raiz->right != NULL){
    raiz->right = destroiArvore(raiz->right);
  }
  if(raiz->left != NULL){
    raiz->left = destroiArvore(raiz->left);
  }
  printf("Destruindo...\n");
  free(raiz);
  return NULL;
}



int main(){
  Node* root = NULL;
  root = insert(root,"ba");
  root = insert(root,"aa");
  root = insert(root,"ab");
  root = insert(root,"bb");
  root = insert(root,"ca");
  root = insert(root,"bc");

  root = imprimeArvore(root);
  printf("\n");
  destroiArvore(root);
  return 0;
}
