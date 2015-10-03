#include <iostream>

using namespace std;

int store[2][100];
int left_store = 0;
int right_store = 0;
int wait_time[1000];
int wait_time_point = 0;

int decide_vector(int left, int right);
void process_leftover(int boolean, int start, int end);
void calculation();

int main() {
	int testcase;
	scanf("%d", &testcase);

	while (testcase--) {
		int subcase, startP, time;
		scanf("%d %d", &subcase, &startP);
		startP -= 2;
		while (--subcase) {
			scanf("%d", &time);
			if (startP >= 0){
				store[0][startP--] = time;
				left_store++;
			}
			else
				store[1][right_store++] = time;
		}

		int left = 0;
		int right = 0;
		int vector;
		while (left < left_store && right < right_store) {
			vector = decide_vector(left, right);
			if (vector > 0) {
				for (int i = 0; i < vector; i++) {
					store[0][left] += store[1][right++];
				}
				//right += vector;
			}
			else {
				vector *= -1;
				for (int i = 0; i < vector; i++) {
					store[1][right] += store[0][left++];
				}
				//left += vector * -1;
			}
		}
		//cout << ":::::::::" << right << ":" << right_store << "  " << left << ":" <<  left_store << endl;
		if (left == left_store)
			process_leftover(1, right, right_store);
		else
			process_leftover(0, left, left_store);

		//wait_time 계산후 출력
		calculation();
		//cout << "STOP" << endl;
	}

	return 0;
}

void calculation() {
	int sum = 0;
	for (int i = 0; i < wait_time_point; i++) {
		sum += wait_time[i] * (wait_time_point - i);
		//cout << wait_time[i] << " ";
	}
	//cout << endl;
	wait_time_point = 0;
	left_store = 0;
	right_store = 0;
	cout << sum << endl;
	
}

void process_leftover(int boolean, int start, int end) {
	for (; start < end; start++) 
		wait_time[wait_time_point++] = store[boolean][start];
}

int decide_vector(int left, int right) {
	int size = 1;
	while (true) {
		if(left == left_store)
			return size * -1;
		if (right == right_store)
			return size;

		if (store[0][left] < store[1][right]){
			wait_time[wait_time_point++] = store[0][left];
			return size * -1;
		}
		else if (store[0][left] > store[1][right]){
			wait_time[wait_time_point++] = store[1][right];
			return size;
		}

		size++;
		wait_time[wait_time_point++] = store[0][left];
		left++;
		right++;
	}
}