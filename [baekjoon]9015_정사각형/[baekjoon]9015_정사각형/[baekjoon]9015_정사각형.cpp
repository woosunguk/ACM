#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int recovery_coordinate(int coordinate);
int main() {
	int testcase;
	int subcase;

	scanf("%d", &testcase);

	while (testcase--) {
		scanf("%d", &subcase);
		//int matrix[20000][20000] = { 0, };
		vector <int> points;
		int arr[3000] = { 0, };
		int x, y;
		int x2, y2;
		int differentX, differentY;
		int i = 0;
		while (i < subcase) {
			scanf("%d %d", &x, &y);
			x += 10001;
			x *= 100000;
			y += 10001;
			points.push_back(x + y);
			//cout << x + y << endl;
			i++;
		}
		cout << "END" << endl;

		sort(points.begin(), points.end());

		/*
		for (int p = 0; i < points.size(); i++) {
			cout << points[p] << endl;
		}
		*/
		
		for (i = 0; i < subcase; i++) {
			x = points[i] / 100000;
			y = points[i] % 100000;
			for (int j = i + 1; j < subcase; j++) {
				x2 = points[j] / 100000;
				y2 = points[j] % 100000;
				differentX = x - x2;
				differentY = y - y2;

				if (find(points.begin(), points.end(), item) != points.end());
			}
		}
	}
	return 0;
}
int recovery_coordinate(int coordinate) {
	x = 
}