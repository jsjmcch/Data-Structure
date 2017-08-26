* ex1)
수식이 주어질 때 같은 짝의 괄호의 위치를 찾는 문제이다. stack을 활용하여 문제를 풀어주세요.
(a*(b+c)+d) 
이 경우에는 3 과 7 , 0 과 10 이 한 쌍의 괄호이다. 

입력 
입력은 공백없이 입력된다. 입력되는 문자는 소문자,소괄호,(+,-,*,/)이다. 
문자열의 길이는 최대 50 까지이다. 

출력 
왼쪽에서 오른쪽을 가면서 먼저 짝이 맞는 (여는 괄호 위치, 닫는 괄호 위치) 순으로 출력하고, 짝이 맞지 않는 수식은 not match 를 출력한다. 

입 출력 예
입력
(a*(b+c)+d)
출력
3 7
0 10
 
* answer

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 30

typedef struct _susik {
    int buf[MAX_SIZE];
    int top;
} susik;

susik sk;

bool is_empty() {
    if (sk.top == -1) return true;
    else return false;
}

bool is_full() {
    if (sk.top >= MAX_SIZE - 1) return true;
    else return false;
}

bool push(int num) {
    if(is_full()) {
        printf("stack is full!\n");
        return false;
    }
    else {
        sk.top++;
        sk.buf[sk.top] = num;
        return true;
    }
}

int pop() {
    int num;
    if(is_empty()) {
        printf("stack is empty!\n");
        return false;
    }

    num = sk.buf[sk.top];
    sk.top = sk.top - 1;

    return num;
}


int main(void) {
    int i,j;
    char array[50];
    int num;

    sk.top = -1;
    memset(sk.buf, 0x0, sizeof(sk.buf));

    printf("insert susik :\n");
    fgets(array, sizeof(array), stdin);

    //printf("array = %s\n", array);

    for(i=0; i<strlen(array); i++) {
        if (array[i] == '(')
            push(i);
        else if (array[i] == ')') {
            num = pop();
            printf(" %d %d\n", num, i);
        }
    }

    if (is_empty() != true) {
        printf("it's not match.\n");
    }


    return 0;
}
 
