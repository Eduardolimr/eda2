// C program to insert a node in AVL tree
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// An AVL tree node
struct Node
{
    char nome[45];
    struct Node *left;
    struct Node *right;
    int height;
};

int compare(char *str1, char *str2){
  while ( *str1 != '\0' && *str1 == *str2 )
  {
   ++str1;
   ++str2;
 }
return (*str1 - *str2);
}

// A utility function to get maximum of two integers
int max(int a, int b);

// A utility function to get height of the tree
int height(struct Node *N)
{
    if (N == NULL){
        return 0;
    }
    return N->height;
}

// A utility function to get maximum of two integers
int max(int a, int b){
  if(a>b){
    return a;
  }
    return b;
}

/* Helper function that allocates a new node with the given key and
    NULL left and right pointers. */
struct Node* newNode(char* palavra)
{
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    strcpy(node->nome, palavra);
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}

// Get Balance factor of node N
int getBalance(struct Node *N)
{
    if (N == NULL){
        return 0;
    }
    return height(N->left) - height(N->right);
}

// Recursive function to insert key in subtree rooted
// with node and returns new root of subtree.
struct Node* insert(struct Node* node, char* palavra)
{
    /* 1.  Perform the normal BST insertion */
    if (node == NULL)
        return(newNode(palavra));

    if (compare(palavra, node->nome)<0){
        node->left  = insert(node->left, palavra);
    }
    else if (compare(palavra, node->nome)>0){
        node->right = insert(node->right, palavra);
    }
    else {// Equal keys are not allowed in BST
        return node;
    }
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left),
                           height(node->right));

    /* 3. Get the balance factor of this ancestor
          node to check whether this node became
          unbalanced */
    int balance = getBalance(node);

    // If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && compare(palavra, node->left->nome)<0){
        return rightRotate(node);
    }
    // Right Right Case
    if (balance < -1 && compare(palavra, node->right->nome)>0){
        return leftRotate(node);
    }
    // Left Right Case
    if (balance > 1 && compare(palavra, node->left->nome)>0)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && compare(palavra, node->right->nome)<0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;
}

// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%s ", root->nome);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct Node *root)
{
    if(root != NULL){
        inOrder(root->left);
          printf("%s ", root->nome);
        inOrder(root->right);
    }
}

struct Node *destroiArvore(struct Node *raiz){
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

/* Drier program to test above function*/
int main(){
  struct Node *root = NULL;

  /* Constructing tree given in the above figure */
  root = insert(root, "ba");
  root = insert(root, "aa");
  root = insert(root, "ab");
  root = insert(root, "bb");
  root = insert(root, "ca");
  root = insert(root, "bc");

  printf("In order traversal of the constructed AVL tree is \n\n");
  inOrder(root);
  printf("\n");
  destroiArvore(root);
  return 0;
}
