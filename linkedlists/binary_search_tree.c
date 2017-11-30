#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include<assert.h>

typedef struct key {
int key_Num;
}Key;

typedef struct node {
Key value;
struct node *left;
struct node *right;
}Node, *NodePtr;

typedef struct tree {NodePtr node_ptr;}Tree, *TreePtr;




int main(int argc, char *argv[])
{
int number;
void insertNode(TreePtr, Key);
NodePtr  searchNode(int);
int heightOfTreeRootedAt(NodePtr );
int heightOgTree(TreePtr);
void printKeysPreOrder(NodePtr);
void printKeysInOrder(NodePtr);
void printKeysPostOrder(NodePtr);  
  
printf("Enter the numbers for the tree terminated by ctrl +c: \n");
TreePtr root = (TreePtr)malloc(sizeof(Tree));
root->node_ptr = NULL;
Key value;
scanf("%d",&number);
while(number!= 0)
{
 value.key_Num = number; 
 insertNode( root, value);
 scanf("%d",&number);
}
 printKeysInOrder(root->node_ptr);
return 0;
} 

void  insertNode (TreePtr root, Key value)
{
NodePtr newNode;
newNode = (NodePtr)malloc(sizeof(*newNode));
newNode->value = value;
newNode->left = NULL;
newNode->right = NULL;
NodePtr temp = root->node_ptr;
if(temp==NULL) root->node_ptr = newNode;
else{
while(1){
if(temp->value.key_Num > value.key_Num)
		{
	
		if (temp->left == NULL)
		 {	temp->left = newNode;
			break;
		}
		else
			temp = temp->left;
		}
	else{  if(temp->right==NULL){
			temp->right = newNode;
	       		break;
		}
		else	
		temp = temp->right;
}}

}


 //return root;
}

void printKeysInOrder(NodePtr root)
{

if(root->left != NULL)
printKeysInOrder(root->left);
printf(" %d ",root->value.key_Num);
if(root->right != NULL)
printKeysInOrder(root->right);



}

