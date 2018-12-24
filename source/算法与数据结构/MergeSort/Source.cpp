/******************************************************************************************
 * �����Դ�����ʲô���ʣ����Թ�ע΢�Ź��ںţ�AProgrammer
 * �����������΢�ţ�91395421
 * �һ����Ϊ����
 ******************************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

/*�ϲ�Array[low, mid)��Array[mid, high)
  �ϲ�ǰӦ��֤Array[low, mid)��Array[mid, high)�е�Ԫ�ض��������*/
void merge(int* Array, int low, int mid, int high){
	int* A = Array + low; //�ϲ��������A[0, high - low) = _elem[low, high)
	int lb = mid - low;
	int* B = new int[lb]; //ǰ������B[0, lb) = _elem[low, mid)
	for (int i = 0; i < lb; B[i] = A[i++]); //����ǰ������B
	int lc = high - mid;
	int* C = Array + mid; //��������C[0, lc) = _elem[mid, high)

	/*i, j, k�ֱ�ָ��A, B, C�е�Ԫ��*/
	for (int i = 0, j = 0, k = 0; (j < lb) || (k < lc);) { //B[j]��C[k]��С��ת��A��ĩβ
		if (j < lb && k < lc) //���j��k��û��Խ�磬��ô��ѡ��B[j]��C[k]�еĽ�С�߷���A[i]
			A[i++] = B[j] < C[k] ? B[j++] : C[k++];
		if (j < lb && lc <= k) //���jû��Խ���kԽ���ˣ���ô�ͽ�B[j]����A[i]
			A[i++] = B[j++];
		if (lb <= j && k < lc) //���kû��Խ���jԽ���ˣ���ô�ͽ�C[k]����A[i]
			A[i++] = C[k++];
	}

	delete[] B; //�ͷ���ʱ�ռ�B
}

/*�ǵݹ�� ��ӡ��Ϣ*/
void mergeSort_print(int* Array, int low, int high)
{
	int step = 1;
	while (step < high) {
		for (int i = low; i < high; i += step << 1) {
			int lo = i, hi = (i + (step << 1)) <= high ? (i + (step << 1)) : high; //�����·�鲢���Ͻ����½� 
			int mid = i + step <= high ? (i + step) : high;
			cout << "lo=" << lo << ", high=" << hi << endl;
			merge(Array, lo, mid, hi);
			for (int i = low; i < high; i++) {
				cout << Array[i] << " ";
			}
			cout << endl;
		}

		//��i��i+step�������������н��кϲ�
		//���г���Ϊstep
		//��i�Ժ�ĳ���С�ڻ��ߵ���stepʱ���˳�
		step <<= 1;//�ڰ�ĳһ�����鲢����֮�󣬲����ӱ�
	}
}

/*�ݹ�� ��ӡ��Ϣ*/
void mergeSort_Recursive_print(int* Array, int low, int high) {
	if (low + 1 < high) {
		int mid = low + (high - low + 1) / 2;
		cout << "����ǰ��";
		for (int i = low; i < mid; i++) {
			cout << Array[i] << " ";
		}
		cout << endl;
		mergeSort_Recursive_print(Array, low, mid);
		cout << "�����";
		for (int i = low; i < mid; i++) {
			cout << Array[i] << " ";
		}
		cout << endl;

		cout << "����ǰ��";
		for (int i = mid; i < high; i++) {
			cout << Array[i] << " ";
		}
		cout << endl;
		mergeSort_Recursive_print(Array, mid, high);
		cout << "�����";
		for (int i = mid; i < high; i++) {
			cout << Array[i] << " ";
		}
		cout << endl;
		merge(Array, low, mid, high);
	}
}

/*�ǵݹ��*/
void mergeSort(int* Array, int low, int high)
{
	int step = 1;
	while (step < high - low) {
		for (int i = low; i < high; i += step << 1) {
			int lo = i, hi = (i + (step << 1)) <= high ? (i + (step << 1)) : high; //�����·�鲢���Ͻ����½� 
			int mid = i + step <= high ? (i + step) : high;
			merge(Array, lo, mid, hi);
		}

		//��i��i+step�������������н��кϲ�
		//���г���Ϊstep
		//��i�Ժ�ĳ���С�ڻ��ߵ���stepʱ���˳�
		step <<= 1;//�ڰ�ĳһ�����鲢����֮�󣬲����ӱ�
	}
}

/*�ݹ��
  Array��������������׵�ַ
  low��������ķ�Χ���½�
  high��������ķ�Χ���Ͻ�ĺ�һ��λ��
  ������Ҫ������Array[0]~Array[5]����������ôlow=0��high=6*/
void mergeSort_Recursive(int* Array, int low, int high) {
	if (low + 1 < high) { //��������ĳ��ȴ���1ʱ�����϶�������зֽ�
		int mid = low + (high - low + 1) / 2; //������ֽ��Array[low, mid)��A[mid, high)��Բ���ű�ʾ�����䣬�������в�������Ԫ��
		mergeSort_Recursive(Array, low, mid);
		mergeSort_Recursive(Array, mid, high);
		merge(Array, low, mid, high); //�ϲ�Array[low, mid)��A[mid, high)
	}
}

int main() {
	int B[8] = { 1,2,4,6,2,3,3,5 };
	int A[11] = { 2,1,6,4,2,3,3,9,2,8,5 };
	int C[2] = { 2,1 };
	int D[9] = { 2,1,6,4,2,3,3,9,2 };

	srand(time(0));
	mergeSort(A, 0, 4);
	/*
	for (int n = 0; n < 5; n++) {
		int length = rand() % 20;
		int* Array = new int[length];
		for (int i = 0; i < length; i++) {
			Array[i] = rand() % 100;
			cout << Array[i] << " ";
		}
		cout << endl;
		mergeSort(Array, 0, length);
		for (int i = 0; i < length; i++) {
			cout << Array[i] << " ";
		}
		cout << endl;
		cout << endl;
		delete[] Array;
	}*/
	//mergeSort(A, 0, 11);
	//mergeSort_Recursive(D, 0, 9);
	//merge(A, 0, 7);
	for (int i = 0; i < 11; i++) {
		cout << A[i] << " ";
	}
	system("pause");
	return 0;
}