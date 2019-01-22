#pragma once
#include "display.h"

int nSolu = 0; //�������
int nCheck = 0; //���Ե��ܴ���

/*�жϵ� k ���ʺ��Ƿ���֮ǰ�� k-1 ���ʺ��ͻ���ȿ��Ի��๥����
  �������һ�ʺ��ͻ���򷵻� true�����򷵻�false*/
bool conflict(int k, int* solu) {
	for (int i = 0; i < k; i++) {
		if (solu[k] == solu[i] || (k + solu[k]) == (i + solu[i]) || (k - solu[k]) == (i - solu[i])) {
			return true;
		}
	}
	return false;
}

/*���ô������� N �ʺ�����*/
void placeQueensWithPureArray(unsigned int N) {
	int* solu = new int[N];
	int size = 0;
	solu[0] = 0; //��ԭ��λ�ó���
	do { //������̽������
		if (N <= size || N <= solu[size]) { //���Գ���
			size--;	solu[size]++; //����һ�У���������̽��һ��
		}else { //������̽��һ��
			while (solu[size] < N && conflict(size, solu)) { //ͨ�������лʺ�ıȶ�
				solu[size]++; //�����ҵ��ɰڷ���һ�ʺ����
				nCheck++;
			}
			if (solu[size] < N) { //�����ڿɰڷŵ���
				size++; //��ǰ��Ĺ�ģ�� 1
				if (N <= size) { //����Ĺ�ģ�ѹ���ȫ�ֽ�
					nSolu++; //ȫ�ֽ�������� 1
					displaySolution(solu, N); //��ӡȫ�ֽ�
				}
				solu[size] = 0; //ת����һ�У��ӵ�0�п�ʼ����̽��һ�ʺ�
			}
		}
	} while (0 < size || solu[size] < N);
}
