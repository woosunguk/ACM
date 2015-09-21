#include <iostream>
#include <stdio.h>

using namespace std;

int drive(int position_n, int position_m, bool pre_course, int change_course, int temp_g);

int n, m, l, g;
int size_n;
int size_m;
int min_course = 100;
int map_size;
int arr[2][10000] = { 0 };

int main() {
	int testcase;
	int i = 0;
	scanf("%d", &testcase);
	while (testcase--) {
		scanf("%d %d %d %d", &m, &n, &l, &g);

		size_n = (n - 1) * m;
		size_m = n * (m - 1);

		for (i = 0; i < size_n; i++) {
			scanf("%d", &arr[0][i]);
		}

		for (i = 0; i < size_m; i++) {
			scanf("%d", &arr[1][i]);
		}

		drive(1, 1, true, 0, arr[0][0]);
		drive(n - 1, n, false, 0, arr[1][0]);

		if (min_course != 100)
			cout << min_course + (((m + n - 2) * l)) << endl;
		else
			cout << "-1" << endl;
		min_course = 100;


	}

	return 0;
}

int drive(int position_n, int position_m, bool pre_course, int change_course, int temp_g) {
	bool check = false;

	if (position_n >= size_n && position_m >= size_m) {
		if (min_course > change_course){
			min_course = change_course;
		}
	}

	else {
		if (position_n % (n - 1) != 0 || position_m % n == 0) {
			if (temp_g + arr[0][position_n] <= g && min_course > change_course){
				if (pre_course == false){
					change_course++;
					check = true;
				}
				drive(position_n + 1, position_m + 1, true, change_course, temp_g + arr[0][position_n]);		
			}
		}
		if (position_m < size_m) {
			if (temp_g + arr[1][position_m] <= g && min_course > change_course){
				if (pre_course == true)
					change_course++;
				if (check)
					change_course--;
				drive(position_n + (n - 1), position_m + n, false, change_course, temp_g + arr[1][position_m]);
			}
		}
	}

	return 0;
}