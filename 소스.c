#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node* link;
}node;
void makeList(node**);
void viewList(node*);
node* findLast(node*);
int findPosition(node*, node**, node**, int);
void insertList(node**, node*, int);
void deleteList(node**, node*, node*);
void main() {
	node* head = NULL;
	node* pre = NULL;
	node* targetPtr = NULL;
	int newData, target;
	int found;
	// Make list
	makeList(&head);
	// list maked
	viewList(head);
	fflush(stdin);
	//데이터 삽입
	printf("Enter data to insert : \n");
	scanf_s("%d", &newData);
	printf("어디 다음에 삽입할까요:ㅣ<첫음에 입력을 원하면 -1 입력>\n");
	scanf_s("%d", &target);
	if (target == -1) {
		targetPtr == NULL;
		insertList(&head, targetPtr, newData);
	}
	else {
		found = 0;
		found = findPosition(head, &pre, &targetPtr, target);
		if (found == 1)
			insertList(&head, targetPtr, newData);
		else
			printf("There is no %d in the list\n", target);
	}
	viewList(head);
	//delete list
	printf("Enter data to delete from list\n");
	scanf_s("%d", &target);
	printf("targeted data is %d\n", target);
	found = 0;
	found = findPosition(head, &pre, &targetPtr, target);
	if (targetPtr!=NULL) {
		printf("data is %d in the list", found);
		printf("found data is %d\n", targetPtr->data);
	}
	if (found == 1)
		deleteList(&head, pre, targetPtr);
	else
		printf("There is no %d in the list\n", target);
	// View list data
	viewList(head);
	system("pause");
}
node* findLast(node* hptr) {
	if (hptr != NULL)
		while (hptr->link != NULL)
			hptr = hptr->link;
	return hptr;
}
int findPosition(node* hptr, node** pre, node** targetPtr, int data) {
	*pre = NULL;
	*targetPtr = NULL;
	while (hptr != NULL && hptr->data != data) {
		*pre = hptr;
		hptr = hptr->link;
		if (hptr->data == data)	{
			*targetPtr = hptr;
			return 1;
		}
		else
			return 0;
	}
}
void insertList(node** hptr, node* pptr, int data) {
	node* newNode;
	newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->link = NULL;
	if (*hptr == NULL) {
		*hptr = newNode;
	}
	else {
		if (pptr == NULL) {
			newNode->link = *hptr;
			*hptr = newNode;
		}
		else {
			newNode->link = pptr->link;
			pptr->link = newNode;
		}
	}
}
void deleteList(node** hptr, node* pre, node* target) {
	if (pre == NULL) {
		*hptr = target->link;
	}
	else {
		pre->link = target->link;
	}
	free(target);
}
void makeList(node** hptr) {
	node* pre = NULL;
	node* newNode = NULL;
	int data;
	pre = findLast(*hptr);
	printf("enter data to make list < enter -1 to end>\n");
	scanf_s("%d", &data);
	while (data != -1) {
		printf("data is %d\n", data);
		insertList(hptr, pre, data);
		pre = findLast(*hptr);
		printf("Enter data again\n");
		scanf_s("%d", &data);
	}
}
void viewList(node* ptr) {
	while (ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
}
