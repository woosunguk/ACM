#include <iostream>
#include <string>


#define MAX 101
#define SWAP(x, y, t) ( (t) = (x), (x) = (y), (y) = (t) )
int final_crypt[26][26] = { 0, };
int table[26] = { 0, };
int size[26] = { 0, };
using namespace std;


int cha_array_length(char *input);
int main() {
	int s = 0;
	int length = 0;
	string crypt;
	char words[16][1000] = {};
	char crypts[16][1000] = {};
	char alpha[26][1000] = {};

	int alpha_size[26] = { 0, };

	//int words_count[30] = { 0, };
	//char word[16];
	cin >> s;
	cin.ignore();

	int word_count = 0;
	while (s--) {
		cin.getline(words[word_count++], 16);
		//length = strlen(word);
		//strcpy(words[i], word);
		//cout << words[word_count++] << endl;
	}

	int crypt_count = 0;
	while (1) {
		if (cin.peek() == '\n') break;
		cin >> crypts[crypt_count++];
		//cout << crypts[i++] << endl;
		cin.ignore();
	}

	//cout << (int)'a' << endl;     97


	//1�� �Է�
	int i = 0;
	int j = 0;

	int alpha_count;
	int count;
	int check = 1;
	for (j = 0; j < 16; j++) {
		for (i = 0; i < word_count; i++) {
			alpha_count = (int)words[i][j] - 97;
			if (alpha_count >= 0) {
				for (int q = 0; q < crypt_count; q++) {
					if (crypts[q][j] != '\0') {

						count = alpha_size[alpha_count];
						while (alpha[alpha_count][count] != ',' && count > 0) {
							if (alpha[alpha_count][count--] == crypts[q][j]) {
								check = 0;
							}
						}
						if (check)
							alpha[alpha_count][alpha_size[alpha_count]++] = crypts[q][j];
						check = 1;
					}
				}
			}
			for (int k = 0; k < 26; k++) {
				table[k] = -k;
				if (alpha_size[k]>0) {
					if (alpha[k][alpha_size[k] - 1] != ',')
						alpha[k][alpha_size[k]++] = ',';
				}

			}
		}
	}


	//������ ã��
	int temp[26][26] = { 0, };

	int final_check = 0;
	int max = 1;
	int k = 0;
	count = 0;
	for (i = 0; i < 26; i++) {
		j = 0;
		final_check = 0;
		max = 1;
		final_crypt[i][0] = 1;
		while (alpha[i][j] != '\0') {
			if (alpha[i][j] != ',') {
				temp[i][alpha[i][j] - 97]++;
				if (temp[i][alpha[i][j] - 97] > max) {
					max = temp[i][alpha[i][j] - 97];
				}
			}
			else
				final_check++;
			j++;
		}


		k = 0;
		if (max == final_check) {
			for (j = 0; j < 26; j++) {
				if (temp[i][j] == max)
					final_crypt[i][k++] = j;
			}
			if (k == 1) {
				table[i] = final_crypt[i][k - 1];
			}
		}
		else {
			for (j = 0; j < 26; j++) {
				if (temp[i][j] > 0)
					final_crypt[i][k++] = j;
				j++;
			}
		}

		final_crypt[i][k] = -1;

	}




	//Ȯ���Ȱ͵��� ���������� �ٸ� Ȯ���� ã��
	int copy_table[26];
	for (i = 0; i < 26; i++) {
		copy_table[i] = table[i];
	}
	i = 0;
	j = 0;
	k = 0;
	int q = 0;
	check = 0;
	int save_alpha = 0;
	for (i = 0; i < word_count; i++) {
		while (crypts[i][j] != '\0') {
			for (k = 0; k < 26; k++) {
				if (crypts[i][j] - 97 == table[k]) {
					for (q = 0; q < word_count; q++) {
						if (words[q][j] - 97 == k) {
							save_alpha = q;
							check++;
						}
					}
					if (check == 1) {
						if (cha_array_length(crypts[j]) == cha_array_length(words[save_alpha])) {
							cout << "��Ҵ�" << endl;		//1�ڸ��δ� ��Ҵ�. 
														//1�ڸ� �̻� �����ؾߵǴµ�
						}
					}
				}
			}

			j++;
		}
	}


	cout << "stop" << endl;


	//Ȯ���Ȱ� ����
	int minus_size = 0;
	for (i = 0; i < 26; i++) {
		minus_size = 0;
		for (j = 0; j < 26; j++) {
			*(&final_crypt[i][j] - minus_size) = final_crypt[i][j];
			for (k = 0; k < 26; k++) {
				if (table[k] == final_crypt[i][j] && table[k]>0) {
					minus_size++;
				}
			}
		}
	}


	//Ȯ�� �ȵȰ͵� ��Ī�ϴ� �˰��� �����
	//final_crypt 0>= i <count ���� �����
	//table ����
	int table_temp[26] = { 0, };
	int kk = 0;
	check = 0;
	for (i = 0; i < 26; i++) {
		table_temp[i] = table[i];
	}
	size[0] = 1;
	size[2] = 1;
	for (i = 0; i < 26; i++) {
		if (final_crypt[i][0] != -1) {
			if (i == 14) {
				cout << "eee" << endl;
			};
			while (true) {
				k = 0;
				while (k < i) {
					if (table[k] == final_crypt[i][size[i]]) {
						check = 1;
						break;
					}
					k++;
				}
				if (!check) {    //table�� ��ϰ��� ���ٸ� table���
					table[i] = final_crypt[i][size[i]];
					size[i]++;
					break;								//while�� ����
				}
				else {   //table�� ���� �ִٸ�
					check = 0;
					size[i]++;							//���� ������ �ѱ��
					if (final_crypt[i][size[i]] == '\0') {	//�ִ��� �Ѱܺ����� ���� ������ �� ������ �������� ����
						kk = k;
						while (kk <= i) {
							table[kk++] = -1;			//���� i���� table�� 0���� �ٲ�
						}
						i = k;							// i���� �ߺ����� ������ �ٲ�
						break;
					}

				}
			}
		}
	}

	cout << "stop" << endl;
	cout << "stop" << endl;
	//rout(count-1);
	return 0;
}

int cha_array_length(char *input)
{
	int count = 0;
	while (input[count] != '\0') count++;
	return count;
}

/*
6
and
dick
jane
puff
spot
yertle
bjvg xsb hxsn xsb qymm xsb rqat xsb pnetfn

*/