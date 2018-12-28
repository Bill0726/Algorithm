#pragma once
#include "LinkedList.h"

template <typename T> class Queue {
private:
	LinkedList<T> list;
public:
	int size() {
		return list.size();
	}

	bool empty() {
		return list.empty();
	}

	void enqueue(T const& e) { //��ӣ���β������
		list.insertAsLast(e);
	}

	T dequeue() { //���ӣ����ײ�ɾ��
		return list.remove(list.first());
	}

	T& front() { //����
		return list.first()->data;
	}
};
