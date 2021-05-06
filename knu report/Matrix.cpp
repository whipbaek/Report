#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>


using namespace std;

const unsigned int MAX = 101;

int d[MAX]; // matrix information ( d0 .. dn )
int p[MAX][MAX] ; // parent
int M[MAX][MAX] = { 0 }; //input 배열
int n, result;

int minimum(int i, int j, int* mink);
void Print_P(int i, int j);
int Matrix(int n);




int main(void) {

	ifstream fin("input.txt");
	
	fin >> n;
	for (int i = 0; i < n; i++)
		fin >> d[i];

	cout << "n :" << n << endl;
	for (int i = 0; i < n; i++)
		cout << "d[" << i << "] : " << d[i] << endl;

	fin.close();

	result = Matrix(n);
	cout << "\n";

	Print_P(1, n-1);
	cout << "\n";

	return 0;
}


int minimum(int i, int j, int* mink) {
	int k, m, min;
	min = 999999;
	for (k = i; k < j; k++) {
		m = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
		if (min > m) {
			min = m;
			*mink = k; // parent 정보
		}
	}
	return min;
}

int Matrix(int n) { 

	int i, j, k, diagonal;

	for (i = 1; i <= n; i++)
		M[i][i] = 0; //대각선 값 초기화

	for (diagonal = 1; diagonal < n; diagonal++) { // k = 대각선 개수 , 가장 큰 반복문
		for (i = 1; i <= n - diagonal; i++) { 
			j = i + diagonal;
	
			M[i][j] = minimum(i, j, &k);
			p[i][j] = k;
		}
	}
	return M[1][n];
}


void Print_P(int i, int j) {

	ofstream fout;
	fout.open("output.txt");

	int k;

	if (i == j)
		fout << i << " ";
	else {
		k = p[i][j];
		fout << '(';
		Print_P(i, k);
		Print_P(k + 1, j);
		fout << ')';
	}

	fout.close();
}