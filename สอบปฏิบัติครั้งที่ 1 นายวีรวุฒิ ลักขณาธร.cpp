// Weerawut Lukkanatorn 655432078-9 sec3 
// URL : https://www.youtube.com/watch?v=82KscTd2PE0
#include <stdio.h>

struct Node {
    int data;
    struct Node *next; 
};

void ShowAll( struct Node *walk );
struct Node *AddNode( struct Node **walk, int data );
void UpdateNode(struct Node **walk, int data_1, int data_2);
struct Node *ShowBack(struct Node *walk);
void SwapNode(struct Node **walk, int data_1, int data_2);

int main(){
    struct Node *start, *back;
    start = NULL;
    AddNode( &start, 11 ); 
    AddNode( &start, 22 );
    AddNode( &start, 33 ); 
    AddNode( &start, 44 ); 
    ShowAll(start);
    UpdateNode( &start, 33, 99 ); 
    ShowAll(start);
    start = ShowBack(start); 
    back = start; 
    ShowAll(start);
    SwapNode(&start, 99, 44);
    ShowAll(start);
    return 0;
}

void ShowAll( struct Node *walk ){
    while (walk != NULL){
        printf("%d ", walk->data); 
        walk = walk->next; 
    } 
    printf("\n");
} 
struct Node *AddNode(struct Node **walk, int data){ 
    while(*walk != NULL){
        walk = &(*walk)->next;
    }
    *walk = new struct Node;
    (*walk)->data = data;
    (*walk)->next = NULL;
    return *walk;
}

void UpdateNode(struct Node **walk, int data_1, int data_2) {
    struct Node *now = *walk;
    while (now != NULL) {
        if (now->data == data_1) {
        	now->data = data_2;
        }
        now = now->next;
    }
}

struct Node *ShowBack(struct Node *walk){
	struct Node *before = NULL;
	struct Node *next = NULL;
	while(walk != NULL) {
		next = walk->next;
		walk->next = before;
		before = walk;
		walk = next;
	}
	walk = before;
	return walk;
}

void SwapNode(struct Node **walk, int data_1, int data_2){
    struct Node *temp1 = *walk;
    struct Node *temp2 = *walk;

    struct Node *before1 = NULL;
    while(temp1 && temp1->data != data_1){
        before1 = temp1;
        temp1 = temp1->next;
    }
    struct Node *before2 = NULL;
    while(temp2 && temp2->data != data_2){
        before2 = temp2;
        temp2 = temp2->next;
    }
    if (before1 == NULL) {
        *walk = temp2;
    } else {
        before1->next = temp2;
    }
    if (before2 == NULL) {
        *walk = temp1;
    } else {
        before2->next = temp1;
        
    }
    struct Node *now = temp2->next;
    temp2->next = temp1->next;
    temp1->next = now;
}
