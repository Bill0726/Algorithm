/******************************************************************************************
 * �����Դ�����ʲô���ʣ����Թ�ע΢�Ź��ںţ�AProgrammer
 * �����������΢�ţ�91395421
 * �һ����Ϊ����
 ******************************************************************************************/
#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;
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


int nSolu = 0; //�������
int nCheck = 0; //���Ե��ܴ���
int N; //���̴�С

Vector<Vector<Queen>> allSolution; //������еĽ�

void displayRow ( Queen& q ) { //��ӡ��ǰ�ʺ󣨷�����col�У�������
   printf ( "%2d: ", q.x );
   int i = 0;
   while ( i++ < q.y ) printf ( "[]" );
   printf ( "��" );
   while ( i++ < N ) printf ( "[]" );
   printf ( "%2d\n", q.y );
}

void displaySolution(Vector<Queen> solu_vector) {
	for (int i = 0; i < solu_vector.size(); i++)
		displayRow(solu_vector[i]);
	for (int i = 0; i < solu_vector.size(); i++) {
		printf("(%d, %d) ", solu_vector[i].x, solu_vector[i].y);
		if (i % 4 == 3)
			cout << endl;
	}
	cout << endl;
}

void placeQueens ( int N ) { //N�ʺ��㷨�������棩��������̽/���ݵĲ��ԣ�����ջ��¼���ҵĽ��
   Stack<Queen> solu; //��ţ����֣����ջ
   Queen q ( 0, 0 ); //��ԭ��λ�ó���
   Vector<Queen> solu_vector;

   do { //������̽������
      if ( N <= solu.size() || N <= q.y ) { //���ѳ��磬��
         q = solu.pop(); q.y++; //����һ�У���������̽��һ��
      } else { //������̽��һ��
         while ( ( q.y < N ) && ( 0 <= solu.find ( q ) ) ) //ͨ�������лʺ�ıȶ�
            /*DSA*///while ((q.y < N) && (solu.find(q))) //��������Listʵ��Stack����find()����ֵ������������ͬ��
            { q.y++; nCheck++; } //�����ҵ��ɰڷ���һ�ʺ����
         if ( N > q.y ) { //�����ڿɰڷŵ��У���
            solu.push ( q ); //���ϵ�ǰ�ʺ󣬲�
			if (N <= solu.size()) {
				nSolu++; //�����ֽ��ѳ�Ϊȫ�ֽ⣬��ͨ��ȫ�ֱ���nSolu����
				displaySolution(solu.toVector());
			}
            q.x++; q.y = 0; //ת����һ�У��ӵ�0�п�ʼ����̽��һ�ʺ�
         }
      }/*DSA*/
   } while ( ( 0 < q.x ) || ( q.y < N ) ); //���з�֧���ѻ���ٻ��֦֮���㷨����
}

