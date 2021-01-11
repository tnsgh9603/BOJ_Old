#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <limits.h>

static int menu;
#define Trial 300
#define Cache_size 8
typedef struct {
	int word[4];   //워드
	int tag;      //태그
	int count;      //접근 회수
	int valid;      //유효 비트
	int access_time;   //접근 시간
} block_type;

typedef struct {
	int count; // 최근 접근 시간 계산용
	block_type line[Cache_size];   //캐시메모리 블록
} cache;

void time_count(cache* c, int access) {  // 최근 접근 시간 갱신
	//캐시의 블록 교체가 이루어졌을 경우 기존 캐시블록들의 최근 접근시간 갱신
	int i;
	for (i = 0; i < Cache_size; i++) {
		if (access < c->line[i].access_time) {
			c->line[i].access_time--;
		}
	}
}

init_cache(cache* c) { //캐시 초기화
	int i;
	c->count = 0;
	for (i = 0; i < Cache_size; i++) {
		c->line[i].tag = 0;
		c->line[i].valid = 0;
		c->line[i].count = 0;
		c->line[i].access_time = 0;
	}
}

int cache_check(int tag, cache* c) { //캐시의 태그메모리 비교
	int i, j;
	//태그 비교
	for (i = 0; i < Cache_size; i++) {
		if (tag == c->line[i].tag) {
			if (menu == 1) {	//FIFO일때
				c->line[i].count++;
				printf("적중-> %d\n", c->line[i].tag);
				return 1;
			}
			else {	//LRU일때
				c->line[i].count++;
				time_count(c, c->line[i].access_time);
				c->line[i].access_time = c->count - 1;
				printf("적중-> %d\n", c->line[i].tag);
				return 1;
			}
		}
	}
	return 0;
}

//LRU 방식
void LRU_method(cache* c, int tag) {
	//FIFO 구현
	int min_access_time = INT_MAX, cnt, min_cnt = INT_MAX;
	for (int i = 0; i < Cache_size; i++) {
		if (min_cnt > c->line[i].count) {
			min_cnt = min(c->line[i].count, min_cnt);
			cnt = i;
		}
	}
	for (int i = 0; i < Cache_size; i++) {
		if (min_cnt == c->line[i].count && min_access_time > c->line[i].access_time) {
			min_access_time = min(c->line[i].access_time, min_access_time);
			cnt = i;
		}
	}
	for (int i = 0; i < Cache_size; i++) {
		if (i == cnt) {
			continue;
		}
		if (c->line[cnt].access_time < c->line[i].access_time) {
			c->line[i].access_time--;
		}
	}
	c->line[cnt].tag = tag;   
	c->line[cnt].count = 1;
	c->line[cnt].access_time = 7; 
}


//FIFO 방식
void FIFO_method(cache* c, int tag) {
	//FIFO 구현
	int min_access_time = INT_MAX, cnt;
	for (int i = 0; i < Cache_size; i++) {
		if (min_access_time > c->line[i].access_time) {
			min_access_time = min(c->line[i].access_time, min_access_time);
			cnt = i;
		}
	}
	c->line[cnt].tag = tag;  
	c->line[cnt].access_time = 7;
	for (int i = 0; i < Cache_size; i++) {
		if (i == cnt) {
			continue;
		}
		c->line[i].access_time--;
	}
}

void memory_load(int tag, cache* c) {           //메모리에서 명령어 블록 읽어오기
	int i, j, temp, valid = 0;
	FILE* memory = fopen("memory.txt", "r+");      //메모리 오픈
	if (memory == NULL) {
		// 파일이 존재하지 않을시 프로그램 종료
		printf("파일 오픈 실패! 프로그램을 종료합니다.\n");
		return;
	}
	for (i = 0; i < 512; i++) {        // EX) 512Byte 메모리 가정
		fscanf(memory, "%d", &temp);   //메모리의 블록 번호 추출
		if (temp == tag) {  //캐시의 태그와 메모리 블록 번호가 일치하는 블록
			for (j = 0; j < Cache_size; j++) {
				if (c->line[j].valid == 0) { //캐시의 유효비트 확인 후 0이면 사용가능
					c->line[j].valid = 1;   //유효비트 갱신
					c->line[j].tag = temp;   //메모리 블록 번호 캐시에 사상
					c->line[j].count++;   //LRU를 위한 접근 횟수 갱신
					c->line[j].access_time = j; //LRU 및 FIFO 방식을 위한 접근 시간 갱신
					valid = 1;
					c->count++;   //접근 시간 갱신 변수
					break;
				}
			}
			if (valid == 0) {
				if (menu == 1) {
					FIFO_method(c, tag);// FIFO 방식 블록 교체
				}
				else if (menu == 2) {
					LRU_method(c, tag);   // LRU 방식 블록 교체   
				}
				else {
					printf("잘못 선택하셨습니다.");
				}
			}
			printf("캐쉬라인|	Tag	|	count	|	access	|	유효비트|\n");
			for (j = 0; j < Cache_size; j++) {
				printf("캐쉬 %d:	|	%d	|	%d	|	%d	|	%d	|\n", j, c->line[j].tag, c->line[j].count, c->line[j].access_time, c->line[j].valid);
			}
		}
	}
}
void input_data(FILE* input, cache* c) {
	int temp;
	int i, j, k;
	int hit = 0;
	for (i = 0; i < Trial; i++) { //명령어 수 만큼 반복
		fscanf(input, "%d", &temp);
		printf("캐시 확인 : %d\n", temp);
		if (cache_check(temp, c)) { //캐시 내에 명령어 태그가 있는지 확인
			hit++;  //캐시 적중
			printf("캐쉬라인|	Tag	|	count	|	access	|	유효비트|\n");
			for (j = 0; j < Cache_size; j++) {
				printf("캐쉬 %d:	|	%d	|	%d	|	%d	|	%d	|\n", j, c->line[j].tag, c->line[j].count, c->line[j].access_time, c->line[j].valid);
			}
		}
		else {    //캐시 내에 명령어 태그가 없을 경우
			printf("실패\n");
			memory_load(temp, c);  //메모리에서 명령어 블록 읽어오기
		}
	}
	printf("적중 : %d 회\n", hit);
}
int main() {
	cache c;
	FILE* input = fopen("input.txt", "r+");
	if (input == NULL) {
		// 파일이 존재하지 않을시 프로그램 종료
		printf("파일 오픈 실패! 프로그램을 종료합니다.\n");
		return 0;
	}
	while (1) {
		printf("1. FIFO 방식\n2. LRU 방식\n방식을 선택해주세요:");
		scanf("%d", &menu);
		if (menu == 1 || menu == 2) {
			break;
		}
	}
	init_cache(&c);  //캐시 초기화
	input_data(input, &c); //데이터 입력
	system("pause");
}