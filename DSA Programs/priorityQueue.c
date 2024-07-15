#include<stdio.h>

void insertElement(int arr[], int size, int *rear);
void deleteElement(int arr[], int *rear);
void showElements(int arr[], int *rear);
void heapify(int arr[], int, int);

int main(){
    int arr[10];
    int size = 10;
    int rear = -1;
    int ch, i = 1;

    while(i == 1){
        printf("\n1. Insert Element");
        printf("\n2. Delete Element");
        printf("\n3. Show Elements");
        printf("\n4. Exit");
        printf("\nChoose operation : ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                insertElement(arr, size, &rear);
            break;
            case 2:
                deleteElement(arr, &rear);
            break;
            case 3:
                showElements(arr, &rear);
            break;
            case 4:
                i = 0;
            break;
            default:
                printf("\nWrong operation, please choose currect operation :");
        }
    }

    return 0;
}

void heapify(int arr[], int size, int root){
    int l = (root * 2) + 1;
    int r = (root * 2) + 2;
    int largest = root;

    if(l < size && arr[l] > arr[largest])
        largest = l;
    if(r < size && arr[r] > arr[largest])
        largest = r;

    if(largest != root){
        int temp = arr[largest];
        arr[largest] = arr[root];
        arr[root] = temp;

        heapify(arr, size, largest);
    }
}

void insertElement(int arr[], int size, int *rear){
    int element, parent, child, temp;
    
    // We are checking that there is size -1 element or not in Priority Queue
    // because if there is size-1 element only then we can insert element or not
    if(*rear < size-1){
        printf("Enter an element to insert in Priority Queue : ");
        scanf("%d", &element);
        *rear = *rear+1;
        arr[*rear] = element;
        
        child = *rear;
        parent = (child-1)/2;// this is a formula to find parent node of any node;

        // following loop is for mantain max heap of Priority Queue
        while(parent >= 0 && arr[parent] < arr[child]){
            temp = arr[parent];
            arr[parent] = arr[child];
            arr[child] = temp;

            if(parent > 0){// if parent is 0 mean root then we don't need to cmpare it with its parent node
                child = parent;
                parent = (child-1)/2;
            }
        }
    }
    else  
        printf("Priority Queue is full of Elements\n");
}

void deleteElement(int arr[], int *rear){
    int temp;

    if(*rear != -1){
        //We swap first element with last element to delete first element
        temp = arr[*rear];
        arr[*rear] = arr[0];
        arr[0] = temp;   

        *rear = *rear-1;
        heapify(arr, *rear, 0);
        printf("Deleted element is %d from Priority Queue\n", arr[*rear+1]);
    }
    else    
        printf("There is no elements to delete in Priority Queue\n");
}

void showElements(int arr[], int *rear){
    if(*rear == -1)
        printf("There is no elements in the Priority Queue\n");

    else{
        printf("Elements of Priority Queue :\n");
        for(int i = 0; i <= *rear; i++){
            printf("%d\t", arr[i]);
        }
    }
}