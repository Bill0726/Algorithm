//#include <iostream>
//using namespace std;

#include "../DataStructure/LinkedList.h"

int main() {

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
	//insertionSort(list, p, n); //list.size()�ǻ�ȡ����Ĺ�ģ���������еĽڵ�����

	p = list.first();
	for (int i = 0; i < n; i++) {
		//cout << p->data << " "; //p->data ָ���ǽڵ� p �д洢������
		p = p->succ; //�� p ָ�� p �ĺ��
	}
	//cout << endl;
	//cout << endl;
	return 0;
}
