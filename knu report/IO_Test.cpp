#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void test(void);
int main(void) {
	
	test();

	ifstream fin;
	fin.open("b.txt");
	int arr[10];
	for (int i = 0; i < 10; i++) {
		fin >> arr[i];
		cout << arr[i]<<" ";
	}
	cout << "\n";

	fin.close();

	return 0;
}

void test(void) {

	ofstream fout; //Ãâ·Â °´Ã¼

	fout.open("b.txt");

	for (int i = 0; i <= 10; i++)
		fout << i << "\n";
	fout.close();
}