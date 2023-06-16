#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head){
	int counter = 0;
	for (node* x = head; x != NULL; x = x->next) 
		counter++;

	return counter;
}

// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head) {
	char* String = (char*)calloc(length(head) + 1, sizeof(char));
	if (String == NULL)
		return 1;

	int index = 0;
	for (node* x = head; x != NULL; x = x->next)
		String[index++] = x->letter;
	
	
	
	return String;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c){
	node* newNode = (node*)malloc(sizeof(node));
	if (newNode == NULL)
		return 2;

	newNode->letter = c;
	newNode->next = NULL;

	if (*pHead == NULL) {
		*pHead = newNode;
		return;
	}

	node* current = *pHead;
	while (current->next != NULL) {
		current = current->next;
	}

	current->next = newNode;
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead){
	node* current = *pHead;
	node* prev;

	while (current->next != NULL) {
		prev = current;
		current = current->next;
		free(prev);
	}

	free(current);
	*pHead = NULL;	
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt", "r");
	fscanf(inFile, " %d\n", &numInputs);
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile, " %c", &c);
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
