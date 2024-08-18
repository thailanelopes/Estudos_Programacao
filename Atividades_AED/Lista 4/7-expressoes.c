#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char str[10000];


typedef struct data_node {
	char x;
}data_node;

typedef struct _no {
	data_node data;
	struct _no *previous, *next;
}node;

typedef struct _stack {
	int size;
	node *start, *end;
}stack;

stack* createStack();
bool emptyStack(stack *header);
void push(stack *header, data_node info);
void pop(stack *header);
bool eraseStack(stack *header);
void printStack(stack *header);

int main(){
	int caseTeste, flag;
	int i;
	char c;
	stack *chave, *colchete, *parentese;
	data_node temp;

	
	chave = createStack();
	colchete = createStack();
	parentese = createStack();


	scanf("%d", &caseTeste);
	while(caseTeste--){
		flag = 1;
		
		scanf("%s", str);
		for( i = 0; i < strlen(str); i++){
			c = str[i];
			if(c == '('){
				
				temp.x = c;
				push(parentese, temp);
			} else if(c == ')'){
				
				if(!emptyStack(parentese)){
					pop(parentese);
				} else {
					flag = 0;
					break;
				}
			} else if(c == '{'){
				
				temp.x = c;
				push(chave, temp);
			} else if(c == '}'){
				
				if(!emptyStack(chave)){
					pop(chave);
				} else {
					flag = 0;
					break;
				}
			} else if(c == '['){
				//empilha em colchete
				temp.x = c;
				push(colchete, temp);
			} else if ( c == ']'){
				
				if(!emptyStack(colchete)){
					pop(colchete);
				} else {
					flag = 0;
					break;
				}
			}
		}
		if(emptyStack(parentese) && emptyStack(colchete) && emptyStack(chave) && flag == 1){
			printf("S\n");
		} else {
			printf("N\n");
		}
			
		eraseStack(parentese);
		eraseStack(chave);
		eraseStack(colchete);
	}
	return 0;
}


stack* createStack(){
	stack *start = (stack*) malloc(sizeof(stack));
	if(start != NULL){
		start->size = 0;
		start->start = NULL;
		start->end = NULL;
	}
}
bool emptyStack(stack *header){
	if(header==NULL){
		return false;
	}
	return (header->start == NULL);
}
void push(stack *header, data_node info){
	
	node *new_node = (node*) malloc(sizeof(node));
	if(new_node == NULL || header == NULL){
		return ;
	}
	new_node->data = info;
	new_node->next = NULL; 
	if(emptyStack(header)){
		
		header->start = new_node;
		header->end = new_node;
		new_node->previous = NULL;
	} else {
		new_node->previous = header->end; 
		header->end->next = new_node;
		header->end = new_node;
	}
	header->size++;
}

void pop(stack *header){
	node *delet;
	if(emptyStack(header)){
		return ;
	}
	if(header->size == 1){

		delet = header->start;
		header->start = NULL;
		header->end = NULL;
		free(delet);
		header->size--;
	} else {
		delet = header->end;
		header->end = header->end->previous;
		header->end->next = NULL;
		free(delet);
		delet = NULL;
		header->size--;	
	}
	
}

bool eraseStack(stack *header){
	node *temp;
	while(!emptyStack(header)){
		pop(header);
	}
	if(!emptyStack(header)){
		return true;
	} else {
		return false;
	}
}

void printStack(stack *header){
	node *temp;
	temp = header->start;
	while(temp != NULL){
		printf("%c ", temp->data.x);
		temp = temp->next;

	}
}