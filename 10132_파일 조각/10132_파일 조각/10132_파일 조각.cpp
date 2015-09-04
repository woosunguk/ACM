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
		while (1) {												//�Է¹޾Ƽ� files�� ������
			cin >> file;
			files.push_back(file);
			cin.ignore();
			if (cin.peek() == '\n') break;						//���� �Է½� �Է� ����
		}

		sort(files.begin(), files.end(), compare);				//���ڿ����� ������ �������� ����

		if (files.size() == 2) {
			cout << files.at(0) << files.at(1) << endl << endl;			//2���Է��ϰ�� �ٷ� ���
		}
		else {
			int count = 0;
			for (i = 0; i < 2; i++) {				//����� ���� 2��ã��			-> ������ ���۹�ȣ,���۹�ȣ + 1 /������ 0��,1������ 
				if (files.at(i).length() == files.at(i + 1).length()) {
					check = i;
					break;
				}
			}

			for (i = 1; i < 3; i++) {							//���۹�ȣ�� ����1 ����
				file = files.at(check);
				file.append(files.at(files.size() - check - i));
				temp.push_back(file);

				file = files.at(files.size() - check - i);
				file.append(files.at(check));
				temp.push_back(file);
			}

			for (i = 1; i < 3; i++) {							//���۹�ȣ+1�� ����2���� ����1�� Intersect
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
					final_check = 0;							//�ѹ� ��µǸ� ����
					break;
				}
			}
		}

		temp.clear();											//�ʱ�ȭ
		files.clear();
		check = 0;
		cin.ignore();
		testcase_size--;
	}

	return 0;
}
