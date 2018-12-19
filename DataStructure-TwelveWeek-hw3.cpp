#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int Heap[3000],Array[3000], size = 0;
clock_t start, finish;    
double t;


void HUp(int k){
    
    if(k == 0){
		return ;
	}
	else if(Heap[k/2] < Heap[k]){
		return ;
	}
	else{
		int m = Heap[k];
		Heap[k] = Heap[k/2];
		Heap[k/2] = m;
		HUp(k/2);
	}
    
}




void HeapDownSort(int s){
	int k;
	if(Heap[2*s] == 0 && Heap[2*s+1] == 0){
		return ;
	}else if(Heap[2*s] == 0 && Heap[2*s+1] != 0){
		if(Heap[2*s+1] > Heap[s]){
			return ;
		}else{
			k = Heap[s*2+1];
			Heap[2*s+1] = Heap[s];
			Heap[s] = k;
			HeapDownSort(2*s+1);
		}
	}else if(Heap[2*s] != 0 && Heap[2*s+1] == 0){
		if(Heap[2*s] > Heap[s]){
			return ;
		}else{
			k = Heap[s*2];
			Heap[2*s] = Heap[s];
			Heap[s] = k;
			HeapDownSort(2*s);
		}
	}else{
		if(Heap[s*2] > Heap[s*2+1]){
			if(Heap[s*2+1] > Heap[s]){
				return ;
			}else{
				k = Heap[s*2+1];
				Heap[2*s+1] = Heap[s];
				Heap[s] = k;
				HeapDownSort(2*s+1);
			}
		}else{
			if(Heap[2*s] > Heap[s]){
				return ;
			}else{
				k = Heap[s*2];
				Heap[2*s] = Heap[s];
				Heap[s] = k;
				HeapDownSort(2*s);
			}
		}
	}
}



void Delete(){
	if(size == 0){
		return ;
	}else{
		printf("\n%d\n",Heap[1]);
  		Heap[1] = Heap[size];
  		Heap[size] = 0;
    	size -= 1;
		HeapDownSort(1);
	}
}

void Increase(int a){
	size++;
	
	if(size == 1){
		Heap[size] = a;
	}else{
		Heap[size] = a;
		HUp(size);
	}
	
	
	
}

void Initial(int array[],int k,int s){
	for(int i = k; i < s; i++){
		array[i] = rand()%55536 + 10000;
		Increase(array[i]);
	}
	
	printf("Add %d new data\n\n",size);
	
	for(int i = s-1; i > 0; i--){
		Delete();
		
	}
	
}


int main(){
	srand(time(NULL));
	int b = rand()%600 + 600;
	
	Initial(Array,1,601);
	printf("\n\n\n");
	
	for(int i = 1; i < 601; i++){
		Heap[i] = Array[i];
	}
	
	Initial(Array,601,601+b+1);

	return 0;
} 
