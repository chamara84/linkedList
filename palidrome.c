#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<assert.h>
typedef struct node {
char character;
struct node *next;
} Node, *NodePtr;




int main (int argc, char *argv[])
{
NodePtr getString(char *); 
NodePtr reverseList(char *);
int compare (NodePtr, NodePtr);
NodePtr orig, reverse;
assert(argc==2);
assert(strlen(argv[1])>=2); 
if(argc>=2 && strlen(argv[1])<=2) {printf("Enter a word of length more than one character");
exit(1);
}
orig = getString(argv[1]);
reverse = reverseList(argv[1]);
if(compare(orig, reverse)==0){
printf("The word %s is a Palindrome \n", argv[1]);

}
else printf("The word is not a palindrome \n");
return 0;
}

NodePtr getString(char *word)
{
NodePtr top = NULL;
NodePtr prev = NULL, current;
char * i = word;
while(*i!='\0')
{
if(isalpha(*i)){

current = (NodePtr) malloc(sizeof(Node));
current->character = tolower(*i);
current->next = NULL;
if(top == NULL) {top = current;}
else prev->next = current;
prev = current;
}
i++;


}
return top;
}

NodePtr reverseList(char * word)
{
NodePtr top = NULL;
NodePtr prev = NULL, current;
char * i =  word;
while(*i!='\0')
{
if(isalpha(*i)){
current = (NodePtr) malloc(sizeof(Node));
current->character = tolower(*i);
current->next = NULL;
if(top == NULL) top = current;
else current->next = prev;
prev = current;
i++;

}
}
return current;
} 

int compare(NodePtr orig, NodePtr reverse)
{
int result = 2;
while(orig->character == reverse->character)
{
	
if(orig->next != NULL || reverse->next != NULL){
orig = orig->next;
reverse = reverse->next;

} 
else if (orig->next == NULL || reverse->next == NULL){
return 0;
}
else return 2;

}

}
