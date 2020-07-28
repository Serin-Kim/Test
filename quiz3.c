#include <stdio.h>
#include <cs50.h>
#define Q_MAX 10

int queue[Q_MAX];


void add(int *rear);
void pop(int *front, int rear);
void display(int front, int rear);

int main(void) 
{
    int front = -1;   // add()
    int rear = -1;    // pop()

    int number;       // 사용자 입력
    bool keep = true;    // while 반복문 탈출하기 위해
    
    printf("부스트코스 은행입니다. 번호를 선택하세요.\n");


    while(keep) {
        printf("1 : 대기표 뽑기     2 : 대기인원 호출     3: 대기인원 조회     4: 종료  >> ");
        scanf("%d", &number);

    switch(number) {
        case 1 :        // 1 : 대기표 뽑기
        add(&rear);     // 변경시킬 값을 &로 전달
        break;
 
        case 2 :        // 2 : 대기인원 호출          
        pop(&front, rear);
        break;
 
        case 3:         // 3 : 대기인원 조회
        display(front, rear);
        break;

        case 4:         // Quit
        printf("종료합니다.\n");
        keep = false;
        break;
    }
    } 
}

void add(int *rear) {
    if (*rear == Q_MAX - 1){   // queue 가 꽉 찼을 경우
        printf("Queue가 꽉 찼습니다.\n");
        return;
    }
    queue[++*rear] = *rear + 1; 
    printf("%d번 고객입니다.\n", queue[*rear]+1);  // 고객은 1번 ~ 10번
}

void pop(int *front, int rear) {
    if (*front == rear) {    // queue가 공백인 경우
        printf("Queue가 비었습니다.\n");
        return;
    }
    else 
    printf("%d번 고객을 호출합니다.\n", queue[++*front]+1);
}

void display(int front, int rear) {
    printf("대기인원은 %d명입니다.\n", rear-front);
    for (int i = front ; i < rear; i++) {
        printf("%d번 고객\t", i+2);
    }
}
