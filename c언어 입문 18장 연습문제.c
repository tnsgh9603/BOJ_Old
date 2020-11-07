#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	char name[16];
	int korean;
	int english;
	int math;
	int total;
	struct node* p_next;
}NODE;

void addgrade(NODE** pp_head, NODE** pp_tail, int* count) {

	NODE* p_node = (NODE*)malloc(sizeof(NODE)), * p_temp_node, * p_prev_node;

	printf("%d��° �л� �̸�: ", *count);
	scanf("%s", p_node->name);

	printf("���� ����: ");
	scanf("%d", &p_node->korean);

	printf("���� ����: ");
	scanf("%d", &p_node->english);

	printf("���� ����: ");
	scanf("%d", &p_node->math);

	p_node->total = p_node->korean + p_node->english + p_node->math;
	p_temp_node = *pp_head;
	p_prev_node = NULL;

	while (p_temp_node != NULL && p_node->total < p_temp_node->total) {
		p_prev_node = p_temp_node;
		p_temp_node = p_temp_node->p_next;
	}

	if (*pp_head == NULL) { //���Ḯ��Ʈ�� ó�� ��带 �߰��ϴ� ���
		*pp_head = p_node;
		*pp_tail = *pp_head;
		(*pp_tail)->p_next = NULL;
	}

	else if (p_temp_node == *pp_head) { //���Ḯ��Ʈ ���� �տ� ��带 �߰��ϴ� ���
		p_node->p_next = *pp_head;
		*pp_head = p_node;
	}

	else if (p_temp_node == NULL) { //���Ḯ��Ʈ ���� �������� ��带 �߰��ϴ� ���
		(*pp_tail)->p_next = p_node;
		*pp_tail = (*pp_tail)->p_next;
		(*pp_tail)->p_next = NULL;
	}

	else { //���Ḯ��Ʈ �߰��� ��带 �߰��ϴ� ���
		p_node->p_next = p_prev_node->p_next;
		p_prev_node->p_next = p_node;
	}
	(*count)++;
}
void printgrade(NODE** pp_head) {
	printf("--------------------------------------------\n");
	printf(" �̸�    ����  ����  ����  ����  ���  ��� \n");
	printf("--------------------------------------------\n");
	NODE* p_node = *pp_head;
	char rank = 1;
	while (p_node != NULL) {
		printf("%-8s %4d %5d %5d %5d %5.0f %3d��\n", p_node->name, p_node->korean, p_node->english, p_node->math, p_node->total, (p_node->total) / 3.0f, rank);
		rank++;
		p_node = p_node->p_next;
	}
}
void delete_all_node(NODE* p_head) {
	NODE* p_node;
	while (p_head != NULL) {
		p_node = p_head;
		p_head = p_head->p_next;
		free(p_node);
	}
}
void main() {
	NODE* p_head = NULL, * p_tail = NULL;
	int menu, count = 1;
	while (1) {
		printf("[Menu]\n");
		printf("1. ���� �Է�\n");
		printf("2. ���� Ȯ��\n");
		printf("3. ����\n");
		printf("------------------\n");
		printf("���� (1~3): ");
		scanf("%d", &menu);
		if (menu == 1)
			addgrade(&p_head, &p_tail, &count);
		else if (menu == 2)
			printgrade(&p_head);
		else if (menu == 3)
			break;
		else {
			rewind(stdin);  //�Է� ���� �ʱ�ȭ
			printf("�ٽ� �Է��ϼ���");
		}
		printf("\n");
	}
	delete_all_node(p_head);
}