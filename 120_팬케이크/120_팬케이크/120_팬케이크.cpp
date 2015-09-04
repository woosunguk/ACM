#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>

using namespace std;

vector <int> cakeStack;												//��� �� ����ũ ����

void cake_reverse(int level_top, int level_bottom);
int cake_find_maxvalue(int level_bottom);

int main() {
	char cake[500] = "";
	char* tempToken;

	int size = 0;
	int i, j;
	size_t level_top;
	size_t level_bottom;

	while (1) {
		gets(cake);													// ��
		if (strlen(cake) == 0)										// |
			break;													// |
		cout << cake << endl;										// �Է�	-> ���ٸ��� " "�� �߶� cakeStack�� ������ũ ����
		tempToken = strtok(cake, " ");								// |
		while (tempToken) {											// |
			cakeStack.push_back(atoi(tempToken));					// |
			tempToken = strtok(NULL, " ");							// |		
		}															// ��

		size = cakeStack.size();
		level_bottom = size;

		while (level_bottom--) {
			level_top = cake_find_maxvalue(level_bottom);			//�ִ밪�� ��ġ�� ã������ �Լ� ȣ��

			if (cakeStack.at(level_top) != cakeStack.at(level_bottom)) {	//level_bottom�� ������ ���ٸ�
				if (level_top != 0)									//�ִ밪�� �� �����ִٸ� ������ ����
					cout << size - level_top << " ";

				cake_reverse(level_top, level_bottom);				//����ũ�� ������
				cout << size - level_bottom << " ";
			}
		}

		cout << "0" << endl;										//�������� 0�� ����ϰ� �� testcase ����
		cakeStack.clear();											//�ʱ�ȭ
	}

	return 0;
}

int cake_find_maxvalue(int level_bottom) {							//�ִ밪�� ã�Ƽ� ��ġ�� ��ȯ
	int max = 0;
	int i = 0;
	int level_top;
	for (i; i <= level_bottom; i++) {
		if (cakeStack.at(i) > max) {
			max = cakeStack.at(i);									//�ִ밪�� ������
			level_top = i;											//�ִ밪�� ���� ��Ҹ� ����
		}
	}

	return level_top;												//�ִ밪�� ���� ��Ҹ� ��ȯ
}
void cake_reverse(int level_top, int level_bottom) {					//level_top �ؿ��ִ� ���� ���� ���� �ø�		
	int i, j;

	for (i = 1, j = level_top; j < level_bottom; i++, j++)
		cakeStack.insert(cakeStack.begin(), cakeStack.at(j + i));	//level_top �ؿ��ִ� �͵��� ���� ���� �ø���
																	//����ũ�� 2�ߵ����� ȿ���� ����
}

