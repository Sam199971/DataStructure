#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node{
	int ID;
	int type;
	int amount;
	struct node *next;
	struct node *prev;
}Node;

void Create(Node* head, Node* c){
	
	for(int i = 0; i<10; i++){
		c = (Node *)malloc(sizeof(struct node));
		c->ID = (int)(rand()%(999999-100000)+100000);
		c->type = rand()%90 + 10;
		c->amount = rand()%9000000000 + 1000000000;
		if(head->next == head){
			head->next = c;
			head->prev = c;
			c->prev = head;
			c->next = head;
		}
		else{
			(head->prev)->next=c;
			c->prev = head->prev;
			c->next = head;
			head->prev = c;
		}
	}
}

void Print(Node* head, Node* curr){
	curr = head->next;
	while(curr!=head){
		printf("Id : %d\n",curr->ID);
		printf("type: %d\n",curr->type);
		printf("amount: %d\n",curr->amount);
		printf("\n");
		curr = curr->next;
	}
}

void Rank(Node* head, Node* curr){
	Node* tmp;
	for(curr = head->next; curr != head; curr = curr->next){
		for(tmp = curr->next; tmp != head; tmp  = tmp->next){
			if(curr->ID > tmp->ID){
				(curr->prev)->next = tmp;
				(tmp->next)->prev = curr;
				tmp->prev = curr->prev;
				curr->prev = tmp;
				curr->next = tmp->next;
				tmp->next = curr;
			}else{
				curr = curr->next;
			}
		}
	}
}

void Insert(Node* head, Node* curr){
	Node* newstr = (Node *)malloc(sizeof(Node));
	newstr -> ID = rand()%900000 + 100000;
	newstr->type = rand()%90 + 10;
	newstr->amount = rand()%9000000000 + 1000000000;
	for(curr = head->next; curr != head; curr = curr->next){
		while(newstr->ID == curr->ID){
			newstr->ID = rand()%900000 + 100000;
		}
	}
	(head->prev)->next = newstr;
	newstr->prev = (head->prev);
	newstr->next = head;
	head->prev = newstr;
}

void  Search(Node* head, Node* curr, int ID){
	int number = 1;
	for(curr = head->next; curr != head; curr = curr->next){
		if(ID == curr->ID){
			printf("congratulation the ID you searched is at your %d Data\n",number);
			printf("type: %d\n",curr->type);
			printf("amount: %d\n",curr->amount);
			printf("Id : %d\n",curr->ID);
			break;
		}else{
			number++;
		}
	}
	if(curr == head){
		printf("The ID you search is does not exist\n");
	}
}

void Delete(Node* head, Node* curr, int ID){
	int number = 1;
	for(curr = head->next; curr != head; curr = curr->next){
		if(ID == curr->ID){
			printf("the ID you want to delete is in %d Data\n",number);
			printf("type: %d\n",curr->type);
			printf("amount: %d\n",curr->amount);
			printf("Id : %d\n",curr->ID);
			(curr->prev)->next = curr->next;
			(curr->next)->prev = curr->prev;
			free(curr);
			break;
		}else{
			number++;
		}
	}
	if(curr == head){
		printf("The ID does not exist\n");
	}
}


int main(){
	int ser,del;	
	Node *c,*head;
	srand(time(NULL));
	
	head=(Node *)malloc(sizeof(Node));
	head->next = head;
	head->prev = head;
	
	Create(head,c);
	Rank(head,c);
	
	Print(head,c);
	
	printf("--------------------------------------\n\n");
	
	for(int i = 0; i<3; i++){
		Insert(head,c);
		Rank(head,c);
		Print(head,c);
		printf("--------------------------------------\n\n");
	}
	
	for(int i = 0; i<2; i++){
		printf("print witch id do you want to search: ");
		scanf("%d",&ser);
		Search(head,c,ser);
		printf("--------------------------------------\n\n");
	}
	
	for(int i = 0; i<2; i++){
		printf("print witch id do you want to delete: ");
		scanf("%d",&del);
		Delete(head,c,del);
		Print(head,c);
		printf("--------------------------------------\n\n");
	}

	for(int i = 0; i<2; i++){
		Insert(head,c);
		Rank(head,c);
		Print(head,c);
		printf("--------------------------------------\n\n");
	}

	return 0;
}
 
