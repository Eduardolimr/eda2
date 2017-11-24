#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
  char palavra[45];
  struct node* left;
  struct node* right;
}Node;

char* compare(char* l, char* r) {
    return strcmp(l, r);
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
    return novo;
  }
  else{
    while(nome[i]==root->palavra[i]){
      printf("f");
      i++;
    }
    if((nome[i]) < root->palavra[i]){
      printf("g");
      root->left = insert(root->left, nome);
    }
    else{
      printf("h");
      root->right = insert(root->right, nome);
    }
  }
}

Node *imprimeArvore(Node *raiz){
  if(raiz->right != NULL){
    raiz->right = imprimeArvore(raiz->right);
  }
  if(raiz->left != NULL){
    raiz->left = imprimeArvore(raiz->left);
  }
  printf("%s ", raiz->palavra);
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
  printf("%s\n", compare("ba","bb"));
  root = imprimeArvore(root);
  printf("\n");
  destroiArvore(root);
  return 0;
}
