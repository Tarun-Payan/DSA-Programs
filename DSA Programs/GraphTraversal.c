#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *refer[7];
    int visitedNode;
    int explorationNode;
};

struct Node* createnode(int inpdata){
    struct Node *node;
    node = (struct Node*) malloc (sizeof(struct Node));
    node->data = inpdata;
    node->visitedNode = 0;
    node->explorationNode = 0;
    return node;
}

void traversGraph(struct Node*);

int main(){
    struct Node *node1, *node2, *node3, *node4, *node5, *node6, *node7;
    node1 = createnode(5);
    node2 = createnode(10);
    node3 = createnode(15);
    node4 = createnode(20);
    node6 = createnode(25);
    node7 = createnode(30);
    
    //linking the nodes
    node1->refer[0] = node2;
    node1->refer[1] = node3;
    node1->refer[2] = node4;
    node1->refer[3] = NULL;
    
    node2->refer[0] = node1;
    node2->refer[1] = node3;
    node2->refer[2] = NULL;
    
    node3->refer[0] = node1;
    node3->refer[1] = node2;
    node3->refer[2] = node4;
    node3->refer[3] = node5;
    node3->refer[4] = NULL;
    
    node4->refer[0] = node1;
    node4->refer[1] = node3;
    node4->refer[2] = node5;
    node4->refer[3] = NULL;
    
    node5->refer[0] = node4;
    node5->refer[1] = node3;
    node5->refer[2] = node6;
    node5->refer[3] = node7;
    node5->refer[4] = NULL;
    
    node6->refer[0] = node5;
    node6->refer[1] = NULL;
    
    node7->refer[0] = node5;
    node7->refer[1] = NULL;
    
    //Travers the graph
    traversGraph(node1);
    return 0;
}

void traversGraph(struct Node *node){
    if(node != NULL){
        if(node->visitedNode == 0){
            printf("%d\t",node->data);
            node->visitedNode = 1;
        }
        
        if(node->explorationNode == 0){
            node->explorationNode = 1;
            int i = 0;
            while(node->refer[i] != NULL){
                traversGraph(node->refer[i]);
                i++;
            }
        }
    }
}