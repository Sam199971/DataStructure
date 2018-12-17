#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int Heap[3000];
int Array[3000] = {0};
int size = 0;

void Initial(int array[],int k){
	for(int i = 0; i < k; i++){
		array[i] = rand()%100;
		printf("%d  ",array[i]);
	}
}

void HUp(){
	int i = size-1;

    while(1){ // 
        int parent = i/2;
        if (parent > -1 && Heap[parent] > Heap[i]){
            int t = Heap[parent];
            Heap[parent] = Heap[i];
            Heap[i]=t;
            i = parent;
        } else {
            break;
        }
    }
}


void Increase(int array[]){
	for(int i = 0; i < 10; i++){
		Heap[size++] = array[i];
		HUp();
	}
}

int Delete(){
	
	
	int t = Heap[0];
    Heap[0] = Heap[size-1];
    size = size - 1;
    
    
	int i = 0;

    while(i<size){
        int c1 = 2*(i+1);
        int c2 = 2*(i+1) + 1;
        int t;
        if (c1 <= size) {
            t = c1;
        } else {
            break;
        }
        if (c2 <= size && Heap[c1] > Heap[c2]){
            t = c2;
        }

        if(Heap[i] >= Heap[t]) break;

        int temp = Heap[i];
        Heap[i] = Heap[t];
        Heap[t] = temp;
        i = t;
    }
    
    return t;
}



int main(){
	srand(time(NULL));
	
	Initial(Array,10);
	
	Increase(Array);
	
	
	for(int i = 0; i < 10; i++){
		printf("\n%d \n",Heap[i]);
	}
	printf("\n\n");
	
	for(int i = 0; i < 10; i++){
		printf("\n%d \n",Delete());
	}
	
	
	return 0;
} 
