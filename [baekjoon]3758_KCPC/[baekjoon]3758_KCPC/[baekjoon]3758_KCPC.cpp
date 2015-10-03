#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int team_problem[101][101] = { 0 };
int arr_submit[10000] = { 0 };

void init();
int sum_init(int n, int k, int t, int m);
int find_myLank(int t);

int main() {
	int testcase;
	int n, k, t, m;
	int i, j, s;
	int m_temp;

	init();
	scanf("%d", &testcase);
	while (testcase--) {
		scanf("%d %d %d %d", &n, &k, &t, &m);
		m_temp = m;
		while (m_temp--) {
			scanf("%d %d %d", &i, &j, &s);
			arr_submit[m_temp+1] = i;
			team_problem[i][0]++;
			if(team_problem[i][j] < s)
				team_problem[i][j] = s;
			
		}
		//cout << sum_init(n, k, t, m) << endl;
	}
	long long test = 10000999999;
	//cout << test << endl;
	return 0;
}
void init() {
	for (int i = 1; i < 101; i++) {
		for (int j = 1; j < 101; j++) {
			team_problem[i][j] = -1;
		}
	}
}
int sum_init(int n, int k, int t, int m) {
	int sum = 0;
	int up_to_myTeam = 1;
	long long myTeam_grade;
	int team_lank[101] = { 0, };
	for (int i = 1, j = 1; i <= m ; i++) {
		if (team_lank[arr_submit[i]] == 0)
			team_lank[arr_submit[i]] = j++;
		arr_submit[i] = 0;
	}

	for (int j = 1; j <= k; j++) {
		if (team_problem[t][j] > 0)
			sum += team_problem[t][j];
	}
	myTeam_grade = sum * 1000000 + (10000 - team_problem[t][0]) * 100 + (team_lank[t] - 1);

	sum = 0;
	cout << myTeam_grade << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (team_problem[i][j] > 0) 
				sum += team_problem[i][j];
				
			team_problem[i][j] = -1;
		}
		cout << sum * 1000000 + (10000 - team_problem[i][0]) * 100 + (team_lank[i] - 1) << endl;
		if (myTeam_grade < sum * 1000000 + (10000 - team_problem[i][0]) * 100 + (team_lank[i] - 1))
			up_to_myTeam++;
		
		sum = 0;
		team_problem[i][0] = 0;
	}
	return up_to_myTeam;
}