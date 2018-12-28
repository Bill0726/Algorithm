/******************************************************************************************
 * ѭ������
 * �����Դ�����ʲô���ʣ����Թ�ע΢�Ź��ںţ�AProgrammer
 * �����������΢�ţ�91395421
 * �һ����Ϊ����
 ******************************************************************************************/
#pragma once

#define MAX_SIZE 10 //�������
template <typename T> class CircularQueue {
private:
	int _size = 0; //���е�ǰ��ģ
	int _front = 0; //����ָ��
	int _rear = 0; //��βָ��
	T* _elem; //������
public:
	CircularQueue() {
		_elem = new T[MAX_SIZE];
	}

	int size() {
		return _size;
	}

	bool empty() {
		/*�ӿջ����ʱ������ָ��Ͷ�βָ�붼����������ʱӦ�ø��ݶ��еĹ�ģ size ���ж�
		  �� size=0����ӿգ��� size=max_size�������*/
		return _front == _rear && _size == 0; 
	}

	bool enqueue(T const& e) { //���
		if (_size == MAX_SIZE) return false; //�����������򷵻�false
		_elem[_rear] = e;
		_rear = (_rear + 1) % MAX_SIZE;
		_size++;
		return true;
	}

	T dequeue() { //����
		if (empty()) return 0;
		T e = _elem[_front];
		_front = (_front + 1) % MAX_SIZE;
		_size--;
		return e;
	}

	T& front() {
		return _elem[_front];
	}
};
