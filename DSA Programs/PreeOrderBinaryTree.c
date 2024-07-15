#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int);

void preorder(struct Node*);

int main(){
    struct Node *n1 = createNode(1);
    struct Node *n2 = createNode(9);
    struct Node *n3 = createNode(2);
    struct Node *n4 = createNode(7);
    struct Node *n5 = createNode(18);
    struct Node *n6 = createNode(54);
    //Our tree is look like
    //      1
    //     / \
    //    9   2
    //   / \   \
    //  7   18  54

    //Linking nodes
    n1->left = n2;
    n1->right = n3;

    n2->left = n4;
    n2->right = n5;

    n3->right = n6;

    //Traverse and printing the tree by Preorder BinaryTree Method
    preorder(n1);

    return 0;
}

struct Node* createNode(int data){
    struct Node *node;
    node = (struct Node*) malloc (sizeof(struct Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void preorder(struct Node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}