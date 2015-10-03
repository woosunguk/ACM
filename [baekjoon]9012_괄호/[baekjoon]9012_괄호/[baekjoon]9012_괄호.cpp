#include <iostream>
#include <string.h>

using namespace std;

int main() {
	char str[50] = "";
	int testcase;
	int count;
	int i;
	int size;
	scanf("%d", &testcase);

	while (testcase--) {
		scanf("%s", str);
		i = 0;
		count = 0;

		while (str[i] != '\0') {
			if (count < 0) {
				break;
			}
			if (str[i] == '(')
				count++;
			else if (str[i] == ')')
				count--;
			i++;
		}
		if (count == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	

	return 0;
}