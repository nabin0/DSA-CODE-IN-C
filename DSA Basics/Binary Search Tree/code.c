#include <stdio.h>
#include <malloc.h>


struct node
{
    int data;
    struct node *left;
    struct node *right;
};


struct node *createNode(int d)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = d;
    n->left = NULL;
    n->right = NULL;
    return n;
}


void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}


void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}


void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}


int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && prev->data >= root->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}


struct node* searchingInBST(struct node *root, int key)
{
    if (root != NULL)
    {
        if (key == root->data)
        {
            return root;
        }

        if (key < root->data)
        {
            return searchingInBST(root->left, key);
        }
        else if (key > root->data)
        {
            return searchingInBST(root->right, key);
        }
    }
    else
    {
        return NULL;
    }
}


struct node* searchItr(struct node *root, int key)
{
  while (root!=NULL)
  {
      if (key == root->data){
          return root;
      }
      else if (key < root->data)
      {
          root = root->left;
      }
      else{
          root = root->right;
      }
  }
  return NULL;
}

void insert(struct node * root, int data){
    struct node *prevNode;
    while (root!=NULL)
    {
        prevNode = root;
        if (data == root->data)
        {
            return; 
        }
        else if (data < root->data)
        {
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    struct node *newNode = createNode(data);
    if (data < prevNode->data)
    {
        prevNode->left = newNode;
    }
    else{
        prevNode->right = newNode;
    }
    

    
}

int main()
{

    //creating nodes using function

    struct node *root = createNode(12);
    struct node *n1 = createNode(5);
    struct node *n2 = createNode(15);
    struct node *n11 = createNode(3);
    struct node *n12 = createNode(7);
    struct node *n21 = createNode(13);
    struct node *n22 = createNode(21);


    //Diagram for used tree
    //                 12
    //               /    \
    //             /        \
    //           5          15
    //         /    \       /  \
    //      3        7    13    21
    //    /    \  /    \  / \  / \
    //    ------  8*(NULL)-------


    //linking nodes

    root->left = n1;
    root->right = n2;
    n1->left = n11;
    n1->right = n12;
    n2->left = n21;
    n2->right = n22;


    // --------------Is BST or not----------------------------

    if (isBST(root))
    {
        printf("This is Binary Search Tree \n");
    }
    else
    {
        printf("This is not a BST \n");
    }


    // ------------------Search in BSt------------------------

    struct node *pt = searchingInBST(root, 15);
    if (pt != NULL)
    {
        printf("%d is Found", pt->data);
    }
    else
    {
        printf("Element Not Found");
    }


    // ------------------searchItration method in BSt------------------------

    struct node *pntr = searchItr(root, 15);
    if (pntr != NULL)
    {
        printf("%d is Found By Iterative Search\n", pntr->data);
    }
    else
    {
        printf("Element Not Found By Iterative Search\n");
    }


    // ----------------Insertion in BST--------------------------
    insert(root,14);
    printf("\n%d is added here \n\n", root->right->left->right->data);


    // ----------------Traversrl in BST--------------------------

    // Preorder Traversel in Tree

    printf("\nPreOrder of Binary Tree\n");
    preOrder(root);

    // PostOrder Traversel

    printf("\nPostOrder  of Binary Tree\n");
    postOrder(root);

    // Inorder Traversel

    printf("\nInOrder of Binary Tree\n");
    inOrder(root);

    return 0;
}