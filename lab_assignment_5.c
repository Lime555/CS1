#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int l = 0;
	while (head != NULL && head->next != NULL){
		l++;
		head = head->next;
	}
	return(l);
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int l = length(head);
	char *s = (char*)malloc(sizeof(char) * (l+1));
	s[0] = head->letter;
	for(int i = 1; i <= l; i++){
		head = head->next;
		s[i] = head->letter;
	}
	return(s);
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* head = *pHead;
	if (head == NULL){
		node* new = (node*)malloc(sizeof(node));
		new->letter = c;
		new->next = NULL;
		*pHead = new;
	}
	else{
		while (head != NULL && head->next != NULL){
			head = head->next;
		}
		node* new = (node*)malloc(sizeof(node));
		new->letter = c;
		new->next = NULL;
		head->next = new;
	}
	
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* current = *pHead;
	while (current != NULL){
		*pHead = current->next;
		free(current);
		current = *pHead;
	}
}

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