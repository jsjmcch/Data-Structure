// linkedList.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAVE_FILE "tm.txt"

typedef struct _telephone {
	char *name;
	char *phone_num;
	struct _telephone *Next;
	struct _telephone *Prev;
} tManager;

// 생성
tManager * createNode( char *name, char *phone_num ) {
	// 메모리 생성
	tManager *tm = (tManager *)malloc(sizeof(tManager));
	if (tm == NULL) {
		printf("Memory allocation is failed\n");
		return NULL;
	}
	tm->name = strdup(name);
	tm->phone_num = strdup(phone_num);

	tm->Next = NULL;
	tm->Prev = NULL;

	return tm;	// 해당 포인터 리턴
}

void insertNode(tManager **head, tManager *newNode) {
	if ((*head) == NULL) {	// 최초 입력인 경우
		*head = newNode;
	}
	else {		// 값이 있는 경우
		tManager *Curr = *head;
		while (Curr->Next != NULL) {
			Curr = Curr->Next;
		}

		Curr->Next = newNode;
		newNode->Prev = Curr;
	}
}

// 검색 by index
tManager * getNodeAt(tManager *head, int index) {
	tManager *Curr = head;
	int count = 0;

	while (Curr != NULL) {
		if (count++ == index) {
			return Curr;
		}
		Curr = Curr->Next;
	}

	return NULL;
}

// 검색 by name
tManager * getPhoneAddr(tManager *head, char *name) {
	tManager *Curr = head;
	
	while (Curr != NULL) {
		if ( strcmp(Curr->name, name) == 0 ) {
			return Curr;
		}
		Curr = Curr->Next;
	}

	return NULL;
}

// 검색 by phone
tManager * getName(tManager *head, char *phone) {
	tManager *Curr = head;

	while (Curr != NULL) {
		if (strcmp(Curr->phone_num, phone) == 0) {
			return Curr;
		}
		Curr = Curr->Next;
	}

	return NULL;
}

// 데이터 카운트
int countNode(tManager *head) {
	int count = 0;
	tManager *Curr = head;

	while (Curr != NULL) {
		Curr = Curr->Next;
		count++;
	}
	return count;
}

void insertAfter(tManager* Current, tManager* newNode) {
	// head
	if ( Current->Next == NULL && Current->Prev == NULL ) {
		Current->Next = newNode;
	}
	// not head
	// if tail
	else if ( Current->Next == NULL ) {
		Current->Next = newNode;
		newNode->Prev = Current;
	}
	else {
		Current->Next->Prev = newNode;
		newNode->Prev = Current;
		newNode->Next = Current->Next;
		Current->Next = newNode;
	}
}

// 메모리 해제
void deleteNode(tManager *Curr) {
	free(Curr->name);
	free(Curr->phone_num);
	free(Curr);
}

// 삭제
void removeNode(tManager** head, tManager* remove) {
	// head
	if ( *head == remove) {
		*head = remove->Next;
	}
	// when remove has next link to go
	if ( remove->Next != NULL ) {
		remove->Next->Prev = remove->Prev;
	}

	// when remove has prev link to go
	if (remove->Prev != NULL) {
		remove->Prev->Next = remove->Next;
	}

	deleteNode(remove);
}

void removeAllNode(tManager* head) {
	tManager *del;

	while (head != NULL) {
		del = head;
		head = head->Next;

		deleteNode(del);
	}
}

char* f_gets(char *st, int n, FILE *fp) {
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, fp);
	if (ret_val) {
		find = strchr(st, '\r');
		if (find)
			*find = '\0';
		find = strchr(st, '\n');
		if (find)
			*find = '\0';
	}
	return ret_val;
}

int read_file(tManager **root, const char *filename) {
	tManager *tmp;

	char buf_name[100];
	char buf_phone[100];

	FILE *fp = NULL;

	if ((fp = fopen(filename, "rt")) == NULL) {
		printf("read_file can't open %s\n", filename);
		return 0;
	}

	while (1) {
		f_gets(buf_name, sizeof(buf_name), fp);
		f_gets(buf_phone, sizeof(buf_phone), fp);

		if (feof(fp)) break;

		tmp = createNode(buf_name, buf_phone);
		if (tmp != NULL)
			insertNode(root, tmp);
	}

	fclose(fp);
	return 1;
}

int write_file(tManager *root, const char *filename) {
	FILE *fp = NULL;
	if (root == NULL) return 0;

	if ((fp = fopen(filename, "wt")) == NULL) {
		printf("write file can't open %s\n", filename);
		return 0;
	}

	while (root != NULL) {
		fprintf(fp, "%s\n%s\n", root->name, root->phone_num);
		root = root->Next;
	}

	fclose(fp);
	return 1;
}

void eatline(void) {
	while (getchar() != '\n')
		continue;
}

int main()
{
	int i = 0;
	int count = 0;
	int num = 0;
	char name[30] = { 0, };
	char phone[50] = { 0, };

	tManager* List = NULL;
	tManager* newNode = NULL;
	tManager* Curr = NULL;
	tManager* delNode = NULL;
	tManager* searchNode = NULL;

	setbuf(stdout, NULL);

	read_file(&List, SAVE_FILE);

	while (1) {
		printf(" choose one : ");
		printf("********* MENU *********\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. PirntAll\n");
		printf("5. FreeAllNode\n");
		printf("0. Exit\n");
		scanf("%d", &num);

		switch (num) {
			case 1: {
				printf("이름과 전화번호를 입력하세요\n");
				scanf("%s", name);
				scanf("%s", phone);
				newNode = createNode(name, phone);
				insertNode(&List, newNode);
				write_file(List, SAVE_FILE);

				break;
			}

			case 2: {
				printf("삭제하고 싶은 이름을 입력하세요\n");
				scanf("%s", name);
				delNode = getPhoneAddr(List, name);
				if (delNode == NULL) {
					printf("검색되지 않음\n");
					break;
				}
				removeNode(&List, delNode);
				write_file(List, SAVE_FILE);

				break;
			}

			case 3: {
				printf("검색하고 싶은 이름을 입력하세요\n");
				scanf("%s", name);
				searchNode = getPhoneAddr(List, name);
				if (searchNode == NULL) {
					printf("검색되지 않음\n");
					break;
				}
				printf("전화번호 : %s\n", searchNode->phone_num);

				break;
			}

			case 4: {
				printf("전체 출력\n");
				count = countNode(List);
				for (i = 0; i < count; i++) {
					searchNode = getNodeAt(List, i);
					printf("name : %s, phone : %s\n", searchNode->name, searchNode->phone_num);
				}

				break;
			}

			case 5: {
				printf("전체 메모리 해제\n");
				removeAllNode(List);

				break;
			}

			default:
				exit(0);
		}
	}

    return 0;
}
