#include<stdio.h>

void printArr(int arr[], int n)
{
    int i = 0;
    for (; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

void HeapSort(int a[], int n){
    int heap[n];
    int n2 = n-1;
    //following for loop is for put array elements in the heap
    for(int i = 0; i < n; i++){
        heap[i] = a[i];
        int cp = i;
       
        while(a[cp/2] < a[cp] && cp != 0){
            int temp = a[cp];
            a[cp] = a[cp/2];
            a[cp/2] = temp;
            cp /= 2;
        }
    }
   
    while(n2 > 0){
        int temp = a[0];
        int leftChild, rightchild;
        int parent = 0;
        
        a[0] = a[n2];
        a[n2] = temp;
        n2 = n2 - 1;

        while(1){
           leftChild = parent * 2;
           rightchild = (parent * 2)+1;

           if(leftChild > n2){
                break;
           }
           else if(leftChild == n2){
                if(a[leftChild] > a[parent]){
                    temp = a[leftChild];
                    a[leftChild] = a[parent];
                    a[parent] = temp;
                    break;
                }
                else
                    break;
           }

            if(a[leftChild] > a[rightchild]){
                if(a[leftChild] > a[parent]){
                    temp = a[leftChild];
                    a[leftChild] = a[parent];
                    a[parent] = temp;
                    parent = leftChild;
                }
                else
                    break;
           }
           else{
                if(a[rightchild] > a[parent]){
                    temp = a[rightchild];
                    a[rightchild] = a[parent];
                    a[parent] = temp;
                    parent = rightchild;  
                }
                else
                    break;
           }
        }
    }
}

int main()
{
    int a[] = {3, 24, 65, 23, 61, 55, 78, 91};
    int n = sizeof(a)/sizeof(a[0]);

    printf("Printing elements before sorting :\n");
    printArr(a, n);

    printf("\nPrinting elements after sorting :\n");
    HeapSort(a, n);
    printArr(a, n);

    return 0;
}