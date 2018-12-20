/******************************************************************************************
 * �����Դ�����ʲô���ʣ����Թ�ע΢�Ź��ںţ�AProgrammer
 * �����������΢�ţ�91395421
 * �һ����Ϊ����
 ******************************************************************************************/
#pragma once

#include "LinkedList.h"

/*����ʼ��λ�� p �� n ��Ԫ�ؽ�������*/
template <typename T>
void insertionSort(LinkedList<T> &list, ListNode<T>* p, int n) {
	for (int r = 0; r < n; r++) { //��һΪ���ڵ�
		ListNode<T>* pos = list.search(p->data, r, p); //���Һ��ʵ�λ�ã�p->dataָ���ǽڵ� p �д洢������
		list.insertAfter(pos, p->data); //����
		p = p->succ; //�� p ָ�����ĺ��
		list.remove(p->pred); //ɾ�� p ��ǰ��
	}
}

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
