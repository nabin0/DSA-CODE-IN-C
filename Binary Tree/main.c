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
int main()
{

    //--------------------------creating nodes using function--------------------------
    struct node *root = createNode(12);
    struct node *n1 = createNode(32);
    struct node *n2 = createNode(54);
    struct node *n11 = createNode(45);
    struct node *n12 = createNode(122);
    struct node *n21 = createNode(87);
    struct node *n22 = createNode(9);
    //                 12
    //               /    \
    //             /        \
    //           32          54
    //         /    \       /  \
    //      45     122    9    87
    //    /    \  /    \  / \  / \
    //    ------  8*(NULL)-------

    //--------------------------linking nodes--------------------------
    root->left = n1;
    root->right = n2;
    n1->left = n11;
    n1->right = n12;
    n2->right = n21;
    n2->left = n22;

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