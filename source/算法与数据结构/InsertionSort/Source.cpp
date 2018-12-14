#include <iostream>

using namespace std;

/*������A[low, high)��������*/
void insertionSort(int A[], int low, int high) {
	for (int i = low + 1; i < high; i++) { //�ӵ� 2 ��Ԫ�ؿ�ʼ����
		int temp = A[i]; //���� A[i]
		int pos = i - 1;
		while (pos >= low && A[pos] > temp)
			A[pos + 1] = A[pos--];
		A[++pos] = temp;
	}
}

int main() {
	int A[8] = { 6, 5, 3, 1, 8, 7, 2, 4 };
	insertionSort(A, 0, 8);

	for (int i = 0; i < 8; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	cout << endl;
	system("pause");
	return 0;
}