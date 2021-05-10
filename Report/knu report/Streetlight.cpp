#include <iostream>

using namespace std;

const unsigned int MAX = 300;

int EE[MAX][MAX][2]; // ���¼Һ�
int PP[MAX][MAX][2]; // parent

int D[MAX] = { 0,3,11,12,13,15,17 }; // ���ε��� ��ġ(input ��)
int W[MAX] = { 0,2,10,18,19,15,19 };//  ���ε�� 1���� ���� �Һ�
int WS[MAX]; // ������ ��

int n, m; // n= ���ε� ���� , m = ���� ��ġ

int turnoff(int L, int R, int F);

int main(void) {

	n = 6, m = 5;
	
	//EE �ʱ�ȭ
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k < 2; k++)
				EE[i][j][k] = -1;
		}
	}

	

	//���� �� �ʱ�ȭ
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++)
			WS[i] += W[j];
	}

	
	cout << turnoff(m, m, 0);

	return 0;
}

int turnoff(int L, int R, int F) {
	if (L == 1 && R == n)
		return 0;

	int res = EE[L][R][F];
	int temp;
	int LS;

	if (res != -1)
		return res; //���� �����Ѵٸ�

	int now;
	if (!F) {
		now = L; // 0�Ͻ� L�� ����
		cout << "now(L) :" << now << "\n";
	}
	else {
		now = R; // 1�Ͻ� R�� ����
		cout << "now(R) :" << now << "\n";
	}
	LS = WS[n] - WS[R] + WS[L - 1]; // �̵��߿� �Ҹ�Ǵ� ����

	if (L - 1 >= 1) {
		temp = turnoff(L - 1, R, 0) + (D[now] - D[L - 1]) * LS; // L�� �̵�
		if (res == -1 || res > temp) {
			res = temp;
		}

		if (R + 1 <= n) {
			temp = turnoff(L, R + 1, 1) + (D[R + 1] - D[now]) * LS; //R�� �̵�
			if (res == -1 || res > temp)
				res = temp;
		}

		return res;

	}
}

