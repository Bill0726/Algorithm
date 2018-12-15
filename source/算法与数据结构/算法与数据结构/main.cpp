#include <iostream>
#include "LinkedList.h"
#include "Application_of_Stack.h"

using namespace std;

template <typename T>
void print(LinkedList<T> list) {
	ListNode<T> * p = list.first();
	while (p != list.last()->succ) {
		cout << p->data;
		p = p->succ;
		if (p == list.last()->succ)
			cout << endl;
		else
			cout << " ";
	}
}

template <typename T>
void insertionSort(LinkedList<T> &list, ListNode<T>* p, int n) {
	for (int r = 0; r < n; r++) { //��һΪ���ڵ�
		ListNode<T>* pos = list.search(p->data, r, p); //���Һ��ʵ�λ�ã�p->dataָ���ǽڵ� p �д洢������
		list.insertAfter(pos, p->data); //����
		p = p->succ; //�� p ָ�����ĺ��
		list.remove(p->pred); //ɾ�� p ��ǰ��
	}
}

int main() {
	Stack<char> s;
	convert(s, 19960206, 2);
	while (s.empty() == false) {
		cout << s.pop();
	}
	//cout << s.size() << endl;
	//cout << s.empty() << endl;

	//s.push(1);
	//s.push(2);
	//s.push(3);

	//cout << s.size() << endl;
	//cout << s.top() << endl;

	//int ascii = '0';
	//for (int i = 0; i < 10; i++) {
	//	printf("\'%c\', ", ascii + i);
	//}
	//ascii = 'A';
	//for (int i = 0; i < 6; i++) {
	//	printf("\'%c\', ", ascii + i);
	//}
	//LinkedList<int> list; //����һ��LinkedList����

	//list.insertAsLast(6); //��Ϊĩ�ڵ����
	//list.insertAsLast(5);
	//list.insertAsLast(3);
	//list.insertAsLast(1);
	//list.insertAsLast(8);
	//list.insertAsLast(7);
	//list.insertAsLast(2);
	//list.insertAsLast(4);

	//ListNode<int>* p = list.first(); //��ȡ�׽ڵ������

	//int n = list.size();
	//insertionSort(list, p, n); //list.size()�ǻ�ȡ����Ĺ�ģ���������еĽڵ�����

	//p = list.first();
	//for (int i = 0; i < n; i++) {
	//	cout << p->data << " "; //p->data ָ���ǽڵ� p �д洢������
	//	p = p->succ; //�� p ָ�� p �ĺ��
	//}
	//cout << endl;
	//cout << endl;

	//cout << "�����ģ��" << list.size() << endl; //����size
	//cout << "�����Ƿ�Ϊ�գ�" << list.empty() << endl; //����size

	//ListNode<int> * first = list.first(); //����first
	//ListNode<int> * last = list.last(); //����last
	//cout << first->data << ", " << last->data << endl;
	//list.insertBefore(first, -1); //����insertBefore
	//list.insertAfter(first, 0); //����insertAfter

	//print(list);

	//ListNode<int>* p = first->succ->succ;
	//ListNode<int>* q = first->succ->succ->succ;
	//cout << q->data << endl;
	//list.merge(p, 1, list, q, 1);
	//list.sort(); //����sort
	//list.deduplicate(); //����deduplicate
	//print(list);
	//list.set(-1, 100);
	//cout << list.get(7) << endl;
	//list.uniquify();
	//print(list);
	//cout << "search: " << list.search(5, 5, last)->data << endl; //����search

	//cout << list.disordered() << endl; //����disordered

	//cout << list.remove(list.first()->succ) << endl; //����remove
	//print(list);

	//ListNode<int>* target = list.find(1, 5, list.last()); //����find
	//cout << target->data << endl;

	//cout << list[3] << endl; //�������ز����� ��[]��
	/*
	int a[11] = { 1,2,2,3,4,4, 5,5,5,7,7};
	int A[8] = { 19,14,96,10,20,15,4,26 };
	//int B[8] = { 1,2,4,6,2,3,3,5 };
	int B[8] = { 6,3,2,7,1,5,8,4 };
	//int B[2] = { 2, 1 };
	Vector<int> v(B, 0, 8);
	//v.deduplicate();
	//v.increase();
	//v.uniquify();
	//cout << v.binSearch(2, 0, 11) << endl;
	//v.merge(0, 4, 8);
	v.mergeSort(0, 8);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}*/
	system("pause");
	return 0;
}