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
	printf("���� ���α׷�\n���Ḧ ���ϸ� \"999\" �� �Է�\n[���� ���̺�]\n");
	printTables(SCORES, GRADES, NUMBER_OF_GRADES);

	bool keep = true;

	while (keep)
	{
		int score;
		printf("������ �Է��ϼ��� (0~100) ");
		scanf("%d", &score);


		if (score == 999) keep = false;


		while (score < 0 || score > 100) {           // Ű���忡�� �Է¹��� ���� (0~100)�� ��ȿ���� üũ

			if (score == 999) goto EXIT;
			printf("** %d ������ �ùٸ��� �Է��ϼ���. ������ 0 ~ 100 �Դϴ�.\n", score);
			printf("������ �Է��ϼ��� (0~100) ");
			scanf("%d", &score);
		}
		calculateGrade(score, SCORES, GRADES, NUMBER_OF_GRADES);
	}


EXIT:
	printf("���� ���α׷��� �����մϴ�.\n");
	return 0;
}

void printTables(const int target_scores[], const char *target_grades[], const int length) {

	printf("���� : ");
	for (int i = 0; i < length; i++) {
		printf("%d\t", target_scores[i]);
	}
	printf("\n���� : ");
	for (int i = 0; i < length; i++) {
		printf("%s\t", target_grades[i]);
	}
	printf("\n");
}

void calculateGrade(int score, const int target_scores[], const char *target_grades[], const int length) {

	for (int i = 0; i < length; i++) {
		if (score >= target_scores[i]) {
			printf("������ %s �Դϴ�.\n", target_grades[i]);
			break;
		}
	}
}
