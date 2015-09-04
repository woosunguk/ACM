#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

void init_schedule();
int change_to_minute(int s_minute, int s_hour, int e_minute, int e_hour);
void new_schedule(int s_time, int e_time);
void check_schedule();

int time_table[481];

int main() {
	int testcase;
	int i = 1;
	char schedule[500];
	char* tempToken;


	init_schedule();
	while (scanf("%d", &testcase) != EOF) {

		getchar();
		while (testcase--) {														//�Ϸ� ������ ���
			gets(schedule);
			tempToken = strtok(schedule, ":");
			change_to_minute(atoi(strtok(NULL, ": ")), atoi(strtok(NULL, ": ")), atoi(strtok(NULL, ": ")), atoi(tempToken));		//�ϳ��� ������ ���
		}

		cout << "Day #" << i << ": the longest nap starts at ";					//������Ŀ� ���� ���
		check_schedule();														//�Ϸ� ���������� ������ �ִ볷��ð� �˻�
		init_schedule();														//�˻��� �ʱ�ȭ
		i++;
	}
	return 0;
}

void init_schedule() {															// MINUTE �迭 �ʱ�ȭ
	memset(time_table, 0, sizeof(time_table));
	time_table[480] = 1;
}
int change_to_minute(int e_minute, int e_hour, int s_minute, int s_hour) {		//�ð� -> ������ ����
	int s_time = (s_hour * 60 + s_minute) - 600;
	int e_time = (e_hour * 60 + e_minute) - 600;
	new_schedule(s_time, e_time);
	return 0;
}
void new_schedule(int s_time, int e_time) {										//�� -> MINUTE �迭�� ����
																				//memset(&time_table[s_time], 1, e_time*sizeof(int));						//memset���� �ʱ�ȭ�ϰ� ������ �ȵ�
																				//cout << time_table[2] << endl;
	for (s_time; s_time < e_time; s_time++) {
		time_table[s_time] = 1;
	}
}
void check_schedule() {															//���� �� �� ã�Ƽ� ������Ŀ� ���缭 ���
	int sleep_time = 0;															//�ӽ� ����ð� ���庯��
	int temp_start_time = 0;													//�ӽ� ���� ���۽ð� ���庯��
	int max_sleep_time = 0;														//�ִ� ����ð� ���庯��
	int start_time = 0;															//�ִ� ���� ���۽ð� ���庯��

	for (int i = 0; i < 481; i++) {
		if (time_table[i] == 0)
			sleep_time++;														//�ӽ� ����ð� ����
		else {
			if (sleep_time > max_sleep_time) {
				max_sleep_time = sleep_time;									//�ִ밪 ����
				start_time = temp_start_time;									//�ִ밪 ����
			}
			sleep_time = 0;														//�ʱ�ȭ
			temp_start_time = i + 1;												//�ӽ� ������� �ð� ����
		}
	}

	//������Ŀ� ���� ���
	cout << (start_time / 60) + 10 << ":";
	if (start_time % 60 < 10)
		cout << "0";
	cout << start_time % 60;

	cout << " and will last for ";
	if (max_sleep_time / 60 != 0)
		cout << max_sleep_time / 60 << " hours and ";

	cout << max_sleep_time % 60 << " minutes." << endl;
}
