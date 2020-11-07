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

	printf("%d번째 학생 이름: ", *count);
	scanf("%s", p_node->name);

	printf("국어 점수: ");
	scanf("%d", &p_node->korean);

	printf("영어 점수: ");
	scanf("%d", &p_node->english);

	printf("수학 점수: ");
	scanf("%d", &p_node->math);

	p_node->total = p_node->korean + p_node->english + p_node->math;
	p_temp_node = *pp_head;
	p_prev_node = NULL;

	while (p_temp_node != NULL && p_node->total < p_temp_node->total) {
		p_prev_node = p_temp_node;
		p_temp_node = p_temp_node->p_next;
	}

	if (*pp_head == NULL) { //연결리스트에 처음 노드를 추가하는 경우
		*pp_head = p_node;
		*pp_tail = *pp_head;
		(*pp_tail)->p_next = NULL;
	}

	else if (p_temp_node == *pp_head) { //연결리스트 가장 앞에 노드를 추가하는 경우
		p_node->p_next = *pp_head;
		*pp_head = p_node;
	}

	else if (p_temp_node == NULL) { //연결리스트 가장 마지막에 노드를 추가하는 경우
		(*pp_tail)->p_next = p_node;
		*pp_tail = (*pp_tail)->p_next;
		(*pp_tail)->p_next = NULL;
	}

	else { //연결리스트 중간에 노드를 추가하는 경우
		p_node->p_next = p_prev_node->p_next;
		p_prev_node->p_next = p_node;
	}
	(*count)++;
}
void printgrade(NODE** pp_head) {
	printf("--------------------------------------------\n");
	printf(" 이름    국어  영어  수학  총점  평균  등수 \n");
	printf("--------------------------------------------\n");
	NODE* p_node = *pp_head;
	char rank = 1;
	while (p_node != NULL) {
		printf("%-8s %4d %5d %5d %5d %5.0f %3d등\n", p_node->name, p_node->korean, p_node->english, p_node->math, p_node->total, (p_node->total) / 3.0f, rank);
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
		printf("1. 성적 입력\n");
		printf("2. 성적 확인\n");
		printf("3. 종료\n");
		printf("------------------\n");
		printf("선택 (1~3): ");
		scanf("%d", &menu);
		if (menu == 1)
			addgrade(&p_head, &p_tail, &count);
		else if (menu == 2)
			printgrade(&p_head);
		else if (menu == 3)
			break;
		else {
			rewind(stdin);  //입력 버퍼 초기화
			printf("다시 입력하세요");
		}
		printf("\n");
	}
	delete_all_node(p_head);
}