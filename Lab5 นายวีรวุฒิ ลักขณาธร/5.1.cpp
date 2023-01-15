#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void ShowAll( struct studentNode *walk );
struct studentNode *AddNode( struct studentNode **startNode, char n[], int a, char s, float g );
void InsNode( struct studentNode *Node, char n[], int a, char s, float g );
void DelNode( struct studentNode *Node );

int main(){
    struct studentNode *start, *now;
    start = NULL;
    now = AddNode(&start, "one", 6, 'M', 3.11); 
	ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22); 
	ShowAll(start);
    InsNode(now, "three", 10, 'M', 3.33); 
	ShowAll(start);
    InsNode(now, "four", 12, 'F', 3.44); 
	ShowAll(start);
    DelNode(now); ShowAll(start);
    return 0;
} // end function

void ShowAll( struct studentNode *walk )
{
    while (walk != NULL)
    {
        printf("%s ", walk->name);
        walk = walk->next;
    } // end while
    printf(" ");
} // end function

struct studentNode *AddNode( struct studentNode **startNode, char n[], int a, char s, float g ){
    struct studentNode *newNode = new studentNode;
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;
    newNode->next = (*startNode);
    if (*startNode == NULL){
        *startNode = newNode;
    } 
    else{
        newNode->next = *startNode;
        *startNode = newNode;
    }
    return newNode;
} // end function

void InsNode( struct studentNode *Node, char n[], int a, char s, float g ){
    struct studentNode *newNode = new studentNode;
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = Node->next;
    Node->next = newNode;
} 

void DelNode( struct studentNode *Node ){
    struct studentNode *delNode = Node->next;
    Node->next = delNode->next;
} 

