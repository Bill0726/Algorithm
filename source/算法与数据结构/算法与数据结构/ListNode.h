/******************************************************************************************
 * ΢�Ź��ںţ�AProgrammer
 ******************************************************************************************/
#pragma once

template <typename T> class ListNode {
public:
	T data; //΢��
	ListNode<T> * pred; //ǰ��
	ListNode<T> * succ; //���
	ListNode(){} //���header��trailer�Ĺ���
	ListNode(T e, ListNode<T> * p = NULL, ListNode<T> * s = NULL) :data(e), pred(p), succ(s) {} //Ĭ�Ϲ�����
};
