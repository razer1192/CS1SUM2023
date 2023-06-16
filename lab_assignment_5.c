#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int tmp = 0;
	node *tempHead = head;
	if((tempHead == NULL) || (tempHead->next == NULL)){
		return tmp;
	}
	tmp++;
	while(tempHead->next != NULL){
		tmp++;
		tempHead = tempHead->next;
	}
	return tmp;
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	node *tmp = head;
	int size = length(head);
	char *tmpArray = (char*)malloc(sizeof(char)*size);
	for(int i = 0; i < size; i++){
		tmpArray[i] = tmp->letter;
		tmp = tmp->next;
	}
	return tmpArray;

}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	struct node *newNode = malloc(sizeof(struct node));
	struct node *t = malloc(sizeof(struct node));
	newNode->letter = c;
	newNode->next = NULL;

	if(*pHead == NULL){
		*pHead = newNode;
	}
	else{
		t = *pHead;
		while(t->next != NULL){
			t = t->next;
			//*pHead = *pHead->next;
		}
		t->next = newNode;
		//*pHead = t;
	}
	

}

// deletes all nodes in the linkedList.
void deleteList(node** pHead){
	node* current = *pHead;
	while(current != NULL){
		node* next = current->next;
		free(current);
		current = next;
	}
	*pHead = NULL;
}
/*
void deleteList(node** pHead)
{
	int size = length(*pHead);
	struct node *curr;
	struct node *prev;
	while(pHead != NULL){
		struct node *curr = *pHead;
		while (curr->next != NULL){
			curr = curr->next;
			if(curr->next != NULL)
				prev = curr;
			
		}
		prev->next = NULL;
		free(curr);

	}
	struct node *curr = *pHead;
	if((curr != NULL) && (curr->next == NULL)){
		free(curr);
	}
	struct node *curr;
	struct node *prev;
	if(*pHead != NULL){
		curr = *pHead;
		prev = curr;
		if(curr->next != NULL){
			//curr = curr->next;
			while(curr != NULL){
				if(curr->next != NULL){
					struct node *tmp = curr;
					curr = curr->next;
					free(tmp);

				}
				free(curr);
			}
		}
		else{
			free(*pHead);
		}

	}
		

}
*/

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}