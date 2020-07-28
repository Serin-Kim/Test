#define _CRT_SECURE_NO_WARNINGS
#define NUMBER_OF_GRADES 9
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



const int SCORES[NUMBER_OF_GRADES] = { 95, 90, 85, 80, 75, 70, 65, 60, 0 };
const char *GRADES[NUMBER_OF_GRADES] = { "A+", "A", "B+", "B", "C+", "C", "D+", "D", "F" };

void printTables(const int target_scores[], const char *target_grades[], const int length);
void calculateGrade(int score, const int target_scores[], const char *target_grades[], const int length);

int main(void)
{
	printf("학점 프로그램\n종료를 원하면 \"999\" 를 입력\n[학점 테이블]\n");
	printTables(SCORES, GRADES, NUMBER_OF_GRADES);

	bool keep = true;

	while (keep)
	{
		int score;
		printf("성적을 입력하세요 (0~100) ");
		scanf("%d", &score);


		if (score == 999) keep = false;


		while (score < 0 || score > 100) {           // 키보드에서 입력받은 성석 (0~100)의 유효성을 체크

			if (score == 999) goto EXIT;
			printf("** %d 성적을 올바르게 입력하세요. 범위는 0 ~ 100 입니다.\n", score);
			printf("성적을 입력하세요 (0~100) ");
			scanf("%d", &score);
		}
		calculateGrade(score, SCORES, GRADES, NUMBER_OF_GRADES);
	}


EXIT:
	printf("학점 프로그램을 종료합니다.\n");
	return 0;
}

void printTables(const int target_scores[], const char *target_grades[], const int length) {

	printf("점수 : ");
	for (int i = 0; i < length; i++) {
		printf("%d\t", target_scores[i]);
	}
	printf("\n학점 : ");
	for (int i = 0; i < length; i++) {
		printf("%s\t", target_grades[i]);
	}
	printf("\n");
}

void calculateGrade(int score, const int target_scores[], const char *target_grades[], const int length) {

	for (int i = 0; i < length; i++) {
		if (score >= target_scores[i]) {
			printf("학점은 %s 입니다.\n", target_grades[i]);
			break;
		}
	}
}
