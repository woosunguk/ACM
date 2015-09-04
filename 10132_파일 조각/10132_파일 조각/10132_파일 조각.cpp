#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
bool compare(const string &i, const string &j) {
	return i.length() < j.length();
}

int main() {
	vector<string> temp;
	vector<string> files;
	string file;
	int testcase_size;
	int i = 0;
	int j = 0;
	int check = 0;
	int final_check = 0;

	cin >> testcase_size;

	while (testcase_size) {
		while (1) {												//입력받아서 files에 저장함
			cin >> file;
			files.push_back(file);
			cin.ignore();
			if (cin.peek() == '\n') break;						//빈줄 입력시 입력 종료
		}

		sort(files.begin(), files.end(), compare);				//문자열길이 순으로 오름차순 정렬

		if (files.size() == 2) {
			cout << files.at(0) << files.at(1) << endl << endl;			//2개입력일경우 바로 출력
		}
		else {
			int count = 0;
			for (i = 0; i < 2; i++) {				//사이즈가 같은 2개찾음			-> 있으면 시작번호,시작번호 + 1 /없으면 0번,1번으로 
				if (files.at(i).length() == files.at(i + 1).length()) {
					check = i;
					break;
				}
			}

			for (i = 1; i < 3; i++) {							//시작번호로 조합1 만듬
				file = files.at(check);
				file.append(files.at(files.size() - check - i));
				temp.push_back(file);

				file = files.at(files.size() - check - i);
				file.append(files.at(check));
				temp.push_back(file);
			}

			for (i = 1; i < 3; i++) {							//시작번호+1로 조합2만들어서 조합1과 Intersect
				for (j = 0; j < 4; j++) {
					file = files.at(check + 1);
					file.append(files.at(files.size() - check - i));
					if (file == temp.at(j)) {
						cout << file << endl << endl;
						final_check = 1;
						break;
					}
					file = files.at(files.size() - check - i);
					file.append(files.at(check + 1));
					if (file == temp.at(j)) {
						cout << file << endl << endl;
						final_check = 1;
						break;
					}
				}
				if (final_check) {
					final_check = 0;							//한번 출력되면 종료
					break;
				}
			}
		}

		temp.clear();											//초기화
		files.clear();
		check = 0;
		cin.ignore();
		testcase_size--;
	}

	return 0;
}
