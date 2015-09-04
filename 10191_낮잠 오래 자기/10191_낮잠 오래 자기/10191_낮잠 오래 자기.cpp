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
		while (testcase--) {														//하루 스케쥴 등록
			gets(schedule);
			tempToken = strtok(schedule, ":");
			change_to_minute(atoi(strtok(NULL, ": ")), atoi(strtok(NULL, ": ")), atoi(strtok(NULL, ": ")), atoi(tempToken));		//하나의 스케쥴 등록
		}

		cout << "Day #" << i << ": the longest nap starts at ";					//출력형식에 맞춰 출력
		check_schedule();														//하루 스케쥴등록이 끝나면 최대낮잠시간 검사
		init_schedule();														//검사후 초기화
		i++;
	}
	return 0;
}

void init_schedule() {															// MINUTE 배열 초기화
	memset(time_table, 0, sizeof(time_table));
	time_table[480] = 1;
}
int change_to_minute(int e_minute, int e_hour, int s_minute, int s_hour) {		//시간 -> 분으로 변경
	int s_time = (s_hour * 60 + s_minute) - 600;
	int e_time = (e_hour * 60 + e_minute) - 600;
	new_schedule(s_time, e_time);
	return 0;
}
void new_schedule(int s_time, int e_time) {										//분 -> MINUTE 배열에 적용
																				//memset(&time_table[s_time], 1, e_time*sizeof(int));						//memset으로 초기화하고 싶은데 안됨
																				//cout << time_table[2] << endl;
	for (s_time; s_time < e_time; s_time++) {
		time_table[s_time] = 1;
	}
}
void check_schedule() {															//가장 긴 분 찾아서 출력형식에 맞춰서 출력
	int sleep_time = 0;															//임시 낮잠시간 저장변수
	int temp_start_time = 0;													//임시 낮잠 시작시간 저장변수
	int max_sleep_time = 0;														//최대 낮잠시간 저장변수
	int start_time = 0;															//최대 낮잠 시작시간 저장변수

	for (int i = 0; i < 481; i++) {
		if (time_table[i] == 0)
			sleep_time++;														//임시 낮잠시간 증가
		else {
			if (sleep_time > max_sleep_time) {
				max_sleep_time = sleep_time;									//최대값 갱신
				start_time = temp_start_time;									//최대값 갱신
			}
			sleep_time = 0;														//초기화
			temp_start_time = i + 1;												//임시 낮잠시작 시간 갱신
		}
	}

	//출력형식에 맞춰 출력
	cout << (start_time / 60) + 10 << ":";
	if (start_time % 60 < 10)
		cout << "0";
	cout << start_time % 60;

	cout << " and will last for ";
	if (max_sleep_time / 60 != 0)
		cout << max_sleep_time / 60 << " hours and ";

	cout << max_sleep_time % 60 << " minutes." << endl;
}
