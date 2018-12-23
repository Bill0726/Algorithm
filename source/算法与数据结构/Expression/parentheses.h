/******************************************************************************************
 * �����Դ�����ʲô���ʣ����Թ�ע΢�Ź��ںţ�AProgrammer
 * �����������΢�ţ�91395421
 * �һ����Ϊ����
 ******************************************************************************************/
#pragma once
#include "../DataStructure/Stack.h"

/*�����ʽexp[low, high]�е������Ƿ�ƥ��*/
bool checkParen(const char exp[], int low, int high) {
	Stack<char> S;
	while (low <= high) {
		switch (exp[low]) {
			case '(':
			case '[':
			case '{':
				S.push(exp[low]); break;
			case ')':
				if ((S.empty()) || ('(' != S.pop())) return false;
				break;
			case ']':
				if ((S.empty()) || ('[' != S.pop())) return false;
				break;
			case '}':
				if ((S.empty()) || ('{' != S.pop())) return false;
				break;
			default: break; //�������ַ�һ�ɺ���
		}
		low++;
	}
	return S.empty();
}
