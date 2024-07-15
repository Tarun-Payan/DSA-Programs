#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int data){
    struct Node *node;
    node = (struct Node*) malloc (sizeof(struct Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void createBinaryTree(struct Node *node, int parent){
    int data;
    printf("Enter value for node %d: ", parent);
    scanf("%d", &node->data);

    if(node->data != 0){
        node->left = (struct Node*)malloc(sizeof(struct Node));
        node->right = (struct Node*)malloc(sizeof(struct Node));

        createBinaryTree(node->left, (parent*2)+1);
        createBinaryTree(node->right, (parent*2)+2);
    }
}

void printBinaryTree(struct Node *node, int parent){
    if(node->data != 0){
        printf("Value of node %d : %d\n", parent, node->data);
        printBinaryTree(node->left, (parent*2)+1);
        printBinaryTree(node->right, (parent*2)+2);
    }
}

int main(){
    struct Node *node;
    node = (struct Node*) malloc (sizeof(struct Node));
    printf("Enter values in Binary Tree : \n");
    createBinaryTree(node, 0);

    printf("Printing the values of Binary Tree : \n");
    printBinaryTree(node, 0);

    return 0;
}