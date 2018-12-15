/******************************************************************************************
 * ΢�Ź��ںţ�AProgrammer
 ******************************************************************************************/
#pragma once

/*����������ջ��ʵ��*/
#include "Vector.h"

template <typename T> class Stack { //���������׶���Ϊջ�ף�ĩ����Ϊջ��
private:
	Vector<T> v;
public:

	//����ջ�Ĺ�ģ��ջ��Ԫ�صĸ�����
	int size() {
		return v.size();
	}

	//�ж�ջ�Ƿ�Ϊ��
	bool empty() {
		return v.empty();
	}

	//��ջ����Ч�ڽ���Ԫ����Ϊ������ĩԪ�ز���
	void push(T const& e) { //��ջ
		v.insert(size(), e);
	}

	//��ջ����Ч��ɾ��������ĩԪ��
	T pop() {
		return v.remove(size() - 1);
	}

	//ȡ����ֱ�ӷ���������ĩԪ��
	T& top() {
		return v[v.size() - 1];
	}
};
/*����������ջ��ʵ�ֽ���*/

/*���������ջ��ʵ��
#include "LinkedList.h"

template <typename T> class Stack {
private:
	LinkedList<T> list;
public:

	//����ջ�Ĺ�ģ��ջ��Ԫ�صĸ�����
	int size() {
		return list.size();
	}

	//�ж�ջ�Ƿ�Ϊ��
	bool empty() {
		return list.empty();
	}

	//��ջ����Ч�ڽ���Ԫ����Ϊ������ĩԪ�ز���
	void push(T const& e) { //��ջ
		list.insertAsLast(e);
	}

	//��ջ����Ч��ɾ��������ĩԪ��
	T pop() {
		return list.remove(list.last());
	}

	//ȡ����ֱ�ӷ���������ĩԪ��
	T& top() {
		return list.last()->data;
	}
};
���������ջ��ʵ�ֽ���*/
