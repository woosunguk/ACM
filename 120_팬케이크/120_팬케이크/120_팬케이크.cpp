#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>

using namespace std;

vector <int> cakeStack;												//모든 팬 케이크 저장

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
		gets(cake);													// ↑
		if (strlen(cake) == 0)										// |
			break;													// |
		cout << cake << endl;										// 입력	-> 각줄마다 " "로 잘라서 cakeStack에 팬케이크 넣음
		tempToken = strtok(cake, " ");								// |
		while (tempToken) {											// |
			cakeStack.push_back(atoi(tempToken));					// |
			tempToken = strtok(NULL, " ");							// |		
		}															// ↓

		size = cakeStack.size();
		level_bottom = size;

		while (level_bottom--) {
			level_top = cake_find_maxvalue(level_bottom);			//최대값의 위치를 찾기위한 함수 호출

			if (cakeStack.at(level_top) != cakeStack.at(level_bottom)) {	//level_bottom에 제값이 없다면
				if (level_top != 0)									//최대값이 맨 위에있다면 뒤집지 않음
					cout << size - level_top << " ";

				cake_reverse(level_top, level_bottom);				//케이크를 뒤집음
				cout << size - level_bottom << " ";
			}
		}

		cout << "0" << endl;										//마지막에 0을 출력하고 한 testcase 종료
		cakeStack.clear();											//초기화
	}

	return 0;
}

int cake_find_maxvalue(int level_bottom) {							//최대값을 찾아서 위치를 반환
	int max = 0;
	int i = 0;
	int level_top;
	for (i; i <= level_bottom; i++) {
		if (cakeStack.at(i) > max) {
			max = cakeStack.at(i);									//최대값을 갱신함
			level_top = i;											//최대값이 나온 장소를 저장
		}
	}

	return level_top;												//최대값이 나온 장소를 반환
}
void cake_reverse(int level_top, int level_bottom) {					//level_top 밑에있는 값을 빼서 위로 올림		
	int i, j;

	for (i = 1, j = level_top; j < level_bottom; i++, j++)
		cakeStack.insert(cakeStack.begin(), cakeStack.at(j + i));	//level_top 밑에있는 것들을 빼서 위로 올리면
																	//케이크를 2중뒤집는 효과를 보임
}

