#include <iostream>
#include <vector>

using namespace std;

int main() {
	int testcase;
	int subcase;
	int num;
	scanf("%d", &testcase);

	while (testcase--) {
		vector <int> v;
		vector<int>::iterator it;
		vector<int>::iterator min_it;
		int min = 20000;
		int sum = 0;
		scanf("%d", &subcase);
		while (subcase--) {
			scanf("%d", &num);
			v.push_back(num);
		}
		
		while (v.size() != 1) {
			it = v.begin();
			for (int i = 0; i < v.size() - 1; it++, i++) {
				//if ((*it + (*it + 1)) < min){
				//	min = *it + (*it + 1);
				//	min_it = it;
				//}
				if (v.at(i) + v.at(i + 1) < min) {
					min = v.at(i) + v.at(i + 1);
					min_it = it;
				}
			}
			min_it = v.erase(min_it);
			min_it = v.erase(min_it);
			v.insert(min_it, 1, min);
			sum += min;
			min = 20000;
		}
		cout << v.at(0) << endl;
		cout << sum << endl;
	}
	return 0;
}

/*

//it = myvector.begin();
myvector.push_back(300);
it = myvector.begin();
myvector.insert(it, 2, 300);
*/