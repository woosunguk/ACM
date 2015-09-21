#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> grade;
int team_problem[100][102] = { 0, };
int my_team_index;

int sum_init(int n, int k, int t);
int main() {
	int testcase;
	int n, k, t, m;
	int i, j, s;

	scanf("%d", &testcase);
	while (testcase--) {
		scanf("%d %d %d %d", &n, &k, &t, &m);
		while (m--) {
			scanf("%d %d %d", &i, &j, &s);

			if(team_problem[i][j] < s)
				team_problem[i][j] = s * 10;
		}

		sum_init(n, k, t);
		sort(grade.begin(), grade.end());
	}

	return 0;
}
int sum_init(int n, int k, int t) {
	int sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			sum += team_problem[i][j];
			if (team_problem[i][j] != 0)
				count++;
			team_problem[i][j] = 0;
		}
		grade.push_back(sum + count);

		if (i == t)
			my_team_index = i;

		sum = 0;
		count = 0;
	}
}