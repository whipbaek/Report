#include <iostream>

using namespace std;

const unsigned int MAX = 300;

int EE[MAX][MAX][2]; // 전력소비량
int PP[MAX][MAX][2]; // parent

int D[MAX] = { 0,3,11,12,13,15,17 }; // 가로등의 위치(input 값)
int W[MAX] = { 0,2,10,18,19,15,19 };//  가로등마다 1초의 전력 소비량
int WS[MAX]; // 전력의 합

int n, m; // n= 가로등 개수 , m = 현재 위치

int turnoff(int L, int R, int F);

int main(void) {

	n = 6, m = 5;
	
	//EE 초기화
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k < 2; k++)
				EE[i][j][k] = -1;
		}
	}

	

	//전력 합 초기화
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
		return res; //값이 존재한다면

	int now;
	if (!F) {
		now = L; // 0일시 L에 존재
		cout << "now(L) :" << now << "\n";
	}
	else {
		now = R; // 1일시 R에 존재
		cout << "now(R) :" << now << "\n";
	}
	LS = WS[n] - WS[R] + WS[L - 1]; // 이동중에 소모되는 전력

	if (L - 1 >= 1) {
		temp = turnoff(L - 1, R, 0) + (D[now] - D[L - 1]) * LS; // L로 이동
		if (res == -1 || res > temp) {
			res = temp;
		}

		if (R + 1 <= n) {
			temp = turnoff(L, R + 1, 1) + (D[R + 1] - D[now]) * LS; //R로 이동
			if (res == -1 || res > temp)
				res = temp;
		}

		return res;

	}
}

