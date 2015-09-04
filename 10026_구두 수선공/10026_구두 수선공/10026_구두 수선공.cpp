#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <fstream>

using namespace std;

void Job_schedule();
void Print_schedule();

struct ORDER {
	int no;
	int due;
	int penalty;
};

int penalty_table[1000] = { 0, };
vector <ORDER> orders;

int main() {
	int testcase;
	int each_day;
	char line[100];
	char* tempToken;

	char test;
	cin >> testcase;
	getchar();

	while (testcase--) {
		cin >> each_day;
		getchar();
		if (each_day != 0) {

			ORDER order;
			int i = 1;

			while (each_day--) {
				gets(line);

				tempToken = strtok(line, " ");
				order.no = i;
				order.due = atoi(tempToken);
				order.penalty = atoi(strtok(NULL, " "));
				orders.push_back(order);
				i++;
			}

			Job_schedule();
			Print_schedule();
			orders.clear();
			cout << endl << endl;
		}


	}
}

void Job_schedule() {

	int penalty_1, penalty_2;

	int i, j;
	for (i = 0; i < orders.size() - 1; i++) {
		for (j = 0; j < orders.size() - 1 - i; j++) {
			penalty_1 = orders.at(j).due * orders.at(j + 1).penalty;		// A를 먼저할때 패널티
			penalty_2 = orders.at(j + 1).due * orders.at(j).penalty;		// B를 먼저할때 패널티

			if (penalty_1 > penalty_2) {
				ORDER temp = orders.at(j);
				orders.at(j) = orders.at(j + 1);
				orders.at(j + 1) = temp;
			}
		}
	}
}
void Print_schedule() {
	int i = 0;

	for (i = 0; i < orders.size(); i++) {
		cout << orders.at(i).no << " ";
	}

}