#include <stdio.h>
#include <stdlib.h>

typedef struct dataNode{
    int id;
}DataNode;

typedef struct node{
    DataNode data;
    struct node* next;
}Node;

typedef struct list{
    int size;
    Node* head;
}List;

List* createList();
void push(List* list, DataNode data);
void pull(List* list, DataNode data);
void pop(List* list);
void popPull(List* list);
int indexOf(List* list, Node* node);
Node* atPos(List* list, int index);
void erase(List* list, int index);

List* createList(){

    List* list = (List*) malloc(sizeof(List));

    list->head = NULL;
    list->size = 0;

    return list;
}

void push(List* list, DataNode data){

    Node* node = (Node*)malloc(sizeof(Node));

    node->data = data;
    node->next = list->head;
    list->head = node;
    list->size++;
}

void pull(List* list, DataNode data){

    if(list->head == NULL){
        push(list,data);
    }else{
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = data;

        node->next = NULL;
        Node* pointer = list->head;

        while(pointer->next != NULL)
            pointer = pointer->next;

        pointer->next = node;
        list->size++;
    }
}

void pop(List* list){ 

    if(list->head != NULL){
        Node* pointer = list->head;

        list->head = pointer->next;
        free(pointer);
        list->size--;
    }
}

void popPull(List* list){

    if(list->size == 1){
        pop(list);
    }else{
        Node* pointer = list->head;

        while(pointer->next->next != NULL){
            pointer = pointer->next;
        }

        Node* fool = pointer->next;
        pointer->next = NULL;
        free(fool);
        list->size--;
    }

}

void printList(List* list){ 

    if(list->head == NULL){
        printf(" --- LIST EMPTY");
        return;
    }

    Node* pointer = list->head;

    while(pointer != NULL){
        printf("%d ", pointer->data.id);
        pointer = pointer->next;
    }
    printf("\n");
}

int indexOf(List* list, Node* node){

    if(node != NULL){
        Node* pointer = list->head;
        int index = 0;

        while(pointer != node && pointer != NULL){
            pointer = pointer->next;
            index++;
        }
        if(pointer != NULL){
            return index;
        }
    }

    printf("No Nao pertence a lista");
    return -1;
}

Node* atPos(List* list, int index){

    int i = 0;

    if((index >= 0) && ( index < list->size)){
        Node* pointer = list->head;

        for(i=0; i < index; i++)
            pointer = pointer->next;

        return pointer;
    }
    return NULL;
}

void erase(List* list, int index){

    if(index == 0){
        pop(list);
    }else{
        Node* current = atPos(list,index);

        if(current != NULL){
            Node* previous = atPos(list, index-1);

            previous->next = current->next;

            free(current);
            list->size--;
        }
    }
}

void insert(List* list, DataNode data, int index){

    if(index == 0){
        push(list,data);
    }else{

        Node* current = atPos(list,index);

        if(current != NULL){

            Node* newNode = (Node*) malloc(sizeof(Node));
            newNode->data = data;

            newNode->next = current->next;
            current->next = newNode;

            list->size++;
        }

    }

}

Node* WhereNode(List* list,DataNode data){

    Node* pointer = list->head;

    while(pointer->data.id != data.id)
        pointer = pointer->next;

    return pointer;
}

int verifica(List* list, DataNode start, DataNode end){

    Node* startt = WhereNode(list,start);
    Node* endd = WhereNode(list,end);

    int cont=0;
    if(start.id == end.id){
        return -1;
    }else if(endd->next == startt){
        return 0;
    }else{

        Node* pointer;

        if(startt->next == NULL){
                pointer = list->head;
        }else{
            pointer = startt->next;
        }

        while(pointer != endd){
            cont ++;
            if(pointer->next == NULL)
                pointer = list->head;

            pointer = pointer->next;
        }
        return cont;
    }
}

int main(){

    int contt=0;

    List* list = createList();
    DataNode insere;
    DataNode lugar;
    DataNode excluir;
    Node* atual;
    Node* exclui;

    int tam,i;
    char caracter = ' ';
    scanf("%d", &tam);
    DataNode data;

    for(i=0; i <tam; i++){
        scanf("%d", &data.id);
        pull(list,data);
    }

    scanf("%c", &caracter);

    for( ; ; ){

        if(caracter == 'Q'){
                scanf("%d %d",&insere.id, &lugar.id);
                printf("%d\n", verifica(list,insere,lugar));

        }else if(caracter == 'I'){
                scanf("%d %d",&insere.id, &lugar.id);
                atual = WhereNode(list,lugar);
                int index = indexOf(list,atual);
                insert(list,insere,index);
                printList(list);
        }else if(caracter == 'R'){
                scanf("%d", &excluir.id);
                exclui = WhereNode(list,excluir);
                int indexx = indexOf(list,exclui);
                erase(list,indexx);
                 printList(list);
        }else if(caracter == 'F') break;

        //setbuf(stdin,NULL);
        scanf("%c", &caracter);
    }
   // getchar();
}
