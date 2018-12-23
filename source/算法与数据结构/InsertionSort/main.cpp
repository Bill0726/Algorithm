/******************************************************************************************
 * �����Դ�����ʲô���ʣ����Թ�ע΢�Ź��ںţ�AProgrammer
 * �����������΢�ţ�91395421
 * �һ����Ϊ����
 ******************************************************************************************/
#include <iostream>
#include "insertion_sort.h"

using namespace std;


int main() {
	int A[8] = { 6, 5, 3, 1, 8, 7, 2, 4 };
	insertionSort(A, 0, 8);

	for (int i = 0; i < 8; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	cout << endl;
	
	LinkedList<int> list; //����һ��LinkedList����

	list.insertAsLast(6); //��Ϊĩ�ڵ����
	list.insertAsLast(5);
	list.insertAsLast(3);
	list.insertAsLast(1);
	list.insertAsLast(8);
	list.insertAsLast(7);
	list.insertAsLast(2);
	list.insertAsLast(4);

	ListNode<int>* p = list.first(); //��ȡ�׽ڵ������

	int n = list.size();
	insertionSort(list, p, n); //list.size()�ǻ�ȡ����Ĺ�ģ���������еĽڵ�����

	p = list.first();
	for (int i = 0; i < n; i++) {
		cout << p->data << " "; //p->data ָ���ǽڵ� p �д洢������
		p = p->succ; //�� p ָ�� p �ĺ��
	}
	cout << endl;
	cout << endl;
	system("pause");
	return 0;
}