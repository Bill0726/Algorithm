#pragma once
#include "../DataStructure/Stack.h" //ջ

class Queen {
public:
	int x, y; //�ʺ��������ϵ�λ������
	Queen(int xx = 0, int yy = 0) : x(xx), y(yy) {};
	bool operator==(Queen const& q) const { //�����еȲ��������Լ�ⲻͬ�ʺ�֮����ܵĳ�ͻ
		return (x == q.x) //�г�ͻ����Ϊ����ÿ��ֻ�ܷ�һ���ʺ�������һ��������ᷢ������ʡ��
			|| (y == q.y) //�г�ͻ
			|| (x + y == q.x + q.y) //�����Խ��߳�ͻ
			|| (x - y == q.x - q.y); //�ط��Խ��߳�ͻ
	}
	bool operator!= (Queen const& q) const { //���ز��Ȳ�����
		return !(*this == q);
	}
};
