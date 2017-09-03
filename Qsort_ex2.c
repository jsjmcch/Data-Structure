#include <stdio.h>
#include <stdlib.h>

int compare_up(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int compare_down(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main()
{
    int values[] = {40, 10, 100, 90, 20, 25};
    int n;

    qsort(values, 6, sizeof(int), compare_up);
    for(n=0; n<6; n++) printf("%d ", values[n]);
    printf("\n");

    qsort(values, 6, sizeof(int), compare_down);
    for(n=0; n<6; n++) printf("%d ", values[n]);
    printf("\n");

    return 0;
}
=================================================================
#include <stdio.h>
#include <stdlib.h>

char compare_up(const void *a, const void *b) {
    return (char) (*(char *)a - *(char *)b);
}

char compare_down(const void *a, const void *b) {
    return (char) (*(char *)b - *(char *)a);
}

int main(void) {
    char values[] = { 'b', 't', 'j', 'c', 'a', 'e', 'd'};
    int n;

    qsort(values, 7, sizeof(char), compare_up);
    for(n=0; n<7; n++) printf("%c ", values[n]);
    printf("\n");

    qsort(values, 7, sizeof(char), compare_down);
    for(n=0; n<7; n++) printf("%c ", values[n]);
    printf("\n");

    return 0;
}
=================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort_function_up( const void *a, const void *b);
int sort_function_down( const void *a, const void *b);

char list[5][4] = {"cat", "car", "cab", "cap", "can"};

int main(void) {
    int x;
    printf("=======down->up=====\n");
    qsort((void *)list, 5, sizeof(list[0]), sort_function_up);

    for(x=0; x<5; x++)
        printf("%s\n", list[x]);

    printf("=======up->down=====\n");

    qsort((void *)list, 5, sizeof(list[0]), sort_function_down);

    for(x=0; x<5; x++)
        printf("%s\n", list[x]);

    return 0;
}

int sort_function_up( const void *a, const void *b) {
    return (strcmp((char *)a, (char *)b));
}

int sort_function_down( const void *a, const void *b) {
    return (strcmp((char *)b, (char *)a));
}
=================================================================
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REC 5

struct record {
    char name[5];
    char number[4];
};

int cmp(struct record *a, struct record *b)
{
    return strncmp(a->number, b->number, 3);
}

int cmpbyname(struct record *a, struct record *b)
{
    return strncmp(a->name, b->name, 3);
}

int main()
{
    int i;
    struct record data[REC] = {{"kim", "312"}, {"lee", "300"}, {"park", "213"}, {"kang", "915"}, {"dong", "318"}};

    printf("=============sort by number==============\n");
    qsort((void *)data, REC, sizeof(struct record), cmp);

    for (i=0; i<REC; i++) {
        printf("%s %s\n", data[i].name, data[i].number);
    }

    printf("=============sort by name==============\n");
    qsort((void *)data, REC, sizeof(struct record), cmpbyname);

    for (i=0; i<REC; i++) {
        printf("%s %s\n", data[i].name, data[i].number);
    }
    return 0;
}

=================================================================
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _score {
    char name[20];
    int jumsu;
    char phonenum[50];
} score;

#if 0
// 문자열
int compare_name(const void *a, const void *b) {
    const score *sc1 = (const score *) a;
    const score *sc2 = (const score *) b;
    return strcmp(sc1->name, sc2->name);
}

// 숫자
int compare_jumsu(const void *a, const void *b) {
    const score *sc1 = (const score *) a;
    const score *sc2 = (const score *) b;
    return sc1->jumsu - sc2->jumsu;
}

// 문자열
int compare_phonenum(const void *a, const void *b) {
    const score *sc1 = (const score *) a;
    const score *sc2 = (const score *) b;
    return strcmp(sc1->phonenum, sc2->phonenum);
}
#else
// 문자열
int compare_name(const score *sc1, const score *sc2) {
    return strcmp(sc1->name, sc2->name);
}

// 숫자
int compare_jumsu(const score *sc1, const score *sc2) {
    return sc1->jumsu - sc2->jumsu;
}

// 문자열
int compare_phonenum(const score *sc1, const score *sc2) {
    return strcmp(sc1->phonenum, sc2->phonenum);
}
#endif

int main(void) {
    int i,j;
    int len;

    score sc[5] = {{"cho-chang-hoon", 20, "010-5710-2000"},
                    {"hong-kil-dong", 50, "010-2323-5343"},
                    {"kim-chul-su", 70, "010-5642-3829"},
                    {"shin-dong-kil", 100, "010-7654-7898"},
                    {"lee-myoung-dong", 10, "010-7682-1091"}};


    len = sizeof(sc) / sizeof(score);

    printf("[원본]\n");
    for (i=0; i < len; i++) {
        printf("%s | ", sc[i].name);
        printf("%d |", sc[i].jumsu);
        printf("%s\n", sc[i].phonenum);
    }
    printf("\n\n");

    printf("[by name]\n");
    qsort(&sc, len, sizeof(score), compare_name);

    for (i=0; i < len; i++) {
        printf("%s | ", sc[i].name);
        printf("%d |", sc[i].jumsu);
        printf("%s\n", sc[i].phonenum);
    }
    printf("\n");

    printf("[by jumsu]\n");
    qsort(&sc, len, sizeof(score), compare_jumsu);

    for (i=0; i < len; i++) {
        printf("%s | ", sc[i].name);
        printf("%d |", sc[i].jumsu);
        printf("%s\n", sc[i].phonenum);
    }
    printf("\n");

    printf("[by phonenum]\n");
    qsort(&sc, len, sizeof(score), compare_phonenum);

    for (i=0; i < len; i++) {
        printf("%s | ", sc[i].name);
        printf("%d |", sc[i].jumsu);
        printf("%s\n", sc[i].phonenum);
    }

    return 0;
}


