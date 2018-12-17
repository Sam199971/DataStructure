#include <stdio.h>
#include <stdlib.h>

#define max 100

int heap[max];
int size = 0;

void heapifyUp(){ // last element
    int i = size;

    while(1){ // 
        int parent = i/2;
        if (parent > 0 && heap[parent] > heap[i]){
            int t = heap[parent];
            heap[parent] = heap[i];
            heap[i]=t;
            i = parent;
        } else {
            break;
        }
    }
}

void heapifyDown(){ // top element
    int i = 1;

    while(i<size){
        int c1 = 2*i;
        int c2 = 2*i + 1;
        int t;
        if (c1 <= size) {
            t = c1;
        } else {
            break;
        }
        if (c2 <= size && heap[c1] > heap[c2]){
            t = c2;
        }

        if(heap[i] >= heap[t]) break;

        int temp = heap[i];
        heap[i] = heap[t];
        heap[t] = temp;
        i = t;
    }
}

void insert(int key){
    size = size + 1;
    heap[size] = key;
    heapifyUp();
}

int returnMin(){
    return heap[1];
}

int deleteMin(){
    int t = heap[1];
    heap[1] = heap[size];
    size = size - 1;
    heapifyDown();
    return t;
}

void printHeap(){
    int i = 1;
    while(i <= size){
        printf("%d ", heap[i]);
        i++;
    }
    printf("\n");
}

int main()
{
    insert(10);
    insert(20);
    insert(11);
    insert(7);
    insert(18);
    insert(3);

    printHeap();
    printf("%d\n",deleteMin());

    insert(110);
    insert(-7);
    insert(15);

    printHeap();
    printf("%d\n",deleteMin());
    return 0;
}
