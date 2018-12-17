#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node{
	int id;
	char gender;
	int phone[10];
	struct node* left;
	struct node* right;
}Node;

/*Node *search(Node* tree, int id){
	
	if(tree->id == id){
		return tree;
	}else if(tree == NULL){
		return NULL;
	}else if(id > tree->id){
		return search(tree->right,id);
	}else{
		return search(tree->left,id);
	}
}*/

void RandGender(Node* tree){
	tree -> gender = rand()%2 ? 'M' :'F' ;
	
}

void RandPhone(Node* tree){
	tree->phone[0] = 0;
	tree->phone[1] = rand()%9+1;
	for(int i = 2; i < 10; i++){
		tree -> phone[i] = rand()%10;
	}
}

void PrintPhone(Node* tree){
	int i;
	char str[10];
	printf("phone: ");
	for(i=0;i<10;i++){
		sprintf(str, "%d", tree -> phone[i]);
		printf("%s",str);
	}
	printf("\n");
}


int search(Node* tree, int id){
	
	if(tree == NULL){
		return 0;
	}else if(id > tree->id){
		search(tree->right,id);
	}else if(id < tree->id){
		search(tree->left,id);
	}else{
		return 1;
	}
}

void insert(Node* tree,Node* curr){
	if(curr->id > tree->id){
		if(tree->right == NULL){
			tree->right = curr;
			return ;
		}
		else{
			insert(tree->right,curr);
		}
	}
	if(curr->id < tree->id){
		if(tree->left == NULL){
			tree->left = curr;
			return ;
		}
		else{
			insert(tree->left,curr);
		}
	}
}

void printLVR(Node* tree){
	if(tree == NULL){
		return ;
	}else{
		printLVR(tree->left);
		printf("%d ",tree->id);
		printf(" %c ",tree->gender);
		PrintPhone(tree);
		printLVR(tree->right);
	}
}

void printVLR(Node* tree){
	
	if(tree == NULL){
		return ;
	}else{
		printf("%d ",tree->id);
		printf(" %c ",tree->gender);
		PrintPhone(tree);
		printVLR(tree->left);
		printVLR(tree->right);
	}
}



void WantSearch(Node* tree,int ID[]){
	int k=0;
	for(int i = 0; i < 25; i++){
		if(k == 1){
			printf("\nWant search: ");
			printf("%d ",65535);
			if(search(tree,65535)){
				printf(" %d is in number %d",65535,i+1);
			}else {
				printf("65535 is not exist");	
			}
			k++;
		}else if(k == 4){
			printf("\nWant search: ");
			printf("%d ",31570);
			if(search(tree,31570)){
				printf(" %d is in number %d",31570,i+1);
			}else {
				printf("31570 is not exist");	
			}
			k++;
		}
		if(i == 5 || i == 1 || i == 8){
			printf("\nWant search: ");
			printf("%d",ID[i]);
			if(search(tree,ID[i])){
				printf(" %d is in number %d",ID[i],i+1);
			}else {
				printf("Not exist");	
			}
			k++;
		}
	}
}


void WantSearch2(Node* tree,int ID[]){
	int k=5;
	for(int i = 0; i < 25; i++){
		if(k == 6){
			printf("\nWant search: ");
			printf("%d ",65535);
			if(search(tree,65535)){
				printf(" %d is in number %d",65535,i+1);
			}else {
				printf("65535 is not exist");	
			}
			k++;
		}else if(k == 9){
			printf("\nWant search: ");
			printf("%d ",31570);
			if(search(tree,31570)){
				printf(" %d is in number %d",31570,i+1);
			}else {
				printf("31570 is not exist");	
			}
			k++;
		}
		if(i == 16 || i == 19 || i == 22){
			printf("\nWant search: ");
			printf("%d",ID[i]);
			if(search(tree,ID[i])){
				printf(" %d is in number %d",ID[i],i+1);
			}else {
				printf("Not exist");	
			}
			k++;
		}
	}
}



Node* Creat(int k, int n, Node* root, Node* tmp,int ID[]){
	char str[10];
	for(int i = k; i < n; i++){
		tmp = (Node *)malloc(sizeof(Node)); 
		tmp->id = rand()%90000 + 10000;
		RandGender(tmp);
		RandPhone(tmp);
		tmp->left=NULL;
		tmp->right=NULL; 
		
		if(i == 0){
			ID[i] = tmp->id;
			root = tmp;
		}
		else{
			ID[i] = tmp->id;
			while(search(root,tmp->id)){
				tmp->id = rand()%90000+10000;
			}
		}
		printf("%d ID = %d  ",i+1,tmp->id);
		printf("phone: ");
		for(int i=0;i<10;i++){
			sprintf(str, "%d",  tmp->phone[i]);
			printf("%s",str);
		}
		printf("\n");
	}
	return root;
}


int main(){
	
	printf("Hello World\n\n");
	
	srand(time(NULL));
	Node* root,*tmp;
	int ID[25] = {0};
	
	root = (Node *)malloc(sizeof(Node));
	root->left = root->right = NULL;
	
	for(int i =0; i < 12; i++){
		tmp = (Node *)malloc(sizeof(Node)); 
		tmp->id = rand()%90000 + 10000;
		RandGender(tmp);
		RandPhone(tmp);
		tmp->left=NULL;
		tmp->right=NULL; 
		
		if(i == 0){
			ID[i] = tmp->id;
			root = tmp;
		}
		else{
			ID[i] = tmp->id;
			while(search(root,tmp->id)){
				tmp->id = rand()%90000+10000;
			}
			insert(root,tmp);
		}
				
		printf("%d ID = %d  ",i+1,tmp->id);
		PrintPhone(tmp);
	}
	
	printf("LVR: \n");
	printLVR(root);
	printf("\nVLR :\n");
	printVLR(root);	

	
	WantSearch(root,ID);
	printf("\n\n");
	
	for(int i =12; i < 23; i++){
		tmp = (Node *)malloc(sizeof(Node)); 
		tmp->id = rand()%90000 + 10000;
		RandGender(tmp);
		RandPhone(tmp);
		tmp->left=NULL;
		tmp->right=NULL; 
		

		ID[i] = tmp->id;
		while(search(root,tmp->id)){
			tmp->id = rand()%90000+10000;
		}
		insert(root,tmp);
		printf("%d ID = %d\n",i+1,tmp->id);
		PrintPhone(tmp);
	}
	
	printf("LVR: \n");
	printLVR(root);
	printf("\nVLR :\n");
	printVLR(root);	
	
	
	WantSearch2(root,ID);
	
	
	
	
	return 0;
}

 
