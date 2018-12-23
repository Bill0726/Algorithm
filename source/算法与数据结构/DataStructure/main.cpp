/******************************************************************************************
 * �����Դ�����ʲô���ʣ����Թ�ע΢�Ź��ںţ�AProgrammer
 * �����������΢�ţ�91395421
 * �һ����Ϊ����
 ******************************************************************************************/
#include <iostream>
#include "LinkedList.h"

using namespace std;

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

	p = list.first();
	for (int i = 0; i < n; i++) {
		cout << p->data << " "; //p->data ָ���ǽڵ� p �д洢������
		p = p->succ; //�� p ָ�� p �ĺ��
	}
	cout << endl;
	cout << endl;

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
	system("pause");
	return 0;
}