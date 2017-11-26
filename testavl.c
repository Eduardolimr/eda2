#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
  char palavra[45];
  int altura;
  struct node* left;
  struct node* right;
}Node;

int checkAltura(Node* raiz){
  int altDir, altEsq;
  if(raiz==NULL){
    return 0;
  }
  if(raiz->left == NULL){
    altEsq = 0;
  }
  else{
    altEsq = 1 + raiz->left->altura;
  }
  if(raiz->right == NULL){
    altDir = 0;
  }
  else{
    altDir = 1 + raiz->right->altura;
  }
  if(altEsq>altDir){
    return altEsq;
  }
  else{
    return altDir;
  }
}

int checkFB(Node* raiz){
  int altDir, altEsq;
  if(raiz==NULL){
    return 0;
  }
  if(raiz->left == NULL){
    altEsq = 0;
  }
  else{
    altEsq = 1 + raiz->left->altura;
  }
  if(raiz->right == NULL){
    altDir = 0;
  }
  else{
    altDir = 1 + raiz->right->altura;
  }
    return altEsq-altDir;
}

Node * rotDir(Node *x)
{
    Node *y;
    y=x->left;
    x->left=y->right;
    y->right=x;
    x->altura = checkAltura(x);
    y->altura = checkAltura(y);
    return(y);
}

Node * rotEsq(Node *x)
{
    Node *y;
    y=x->right;
    x->right=y->left;
    y->left=x;
    x->altura = checkAltura(x);
    y->altura = checkAltura(y);

    return(y);
}

Node * RR(Node *T)
{
    T=rotEsq(T);
    return(T);
}

Node * LL(Node *T)
{
    T=rotDir(T);
    return(T);
}

Node * LR(Node *T)
{
    T->left=rotEsq(T->left);
    T=rotDir(T);

    return(T);
}

Node * RL(Node *T)
{
    T->right=rotDir(T->right);
    T=rotEsq(T);
    return(T);
}

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
  }
  else{
    if(compare(nome,root->palavra)>0){
      root->left = insert(root->left, nome);
      if(checkFB(root)==2){
        if(compare(nome,root->left->palavra)>0){
          root=RR(root);
        }
        else{
          root=RL(root);
        }
      }
    }
    else if(compare(nome,root->palavra)<0){
      root->right = insert(root->right, nome);
      if(checkFB(root)==-2){
        if(compare(nome,root->left->palavra)<0){
          root=LL(root);
        }
        else{
          root=LR(root);
        }
      }
    }
  }
  root->altura = checkAltura(root);
  return root;
}

Node *imprimeArvore(Node *raiz){
  if(raiz->right != NULL){
    raiz->right = imprimeArvore(raiz->right);
  }
  printf("%s.%d ", raiz->palavra, raiz->altura);
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
