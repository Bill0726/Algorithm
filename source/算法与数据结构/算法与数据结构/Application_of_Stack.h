/******************************************************************************************
 * �����Դ�����ʲô���ʣ����Թ�ע΢�Ź��ںţ�AProgrammer
 * �����������΢�ţ�91395421
 * �һ����Ϊ����
 ******************************************************************************************/
#pragma once
#include "Stack.h"
#include "rpn.h"
#include <iostream>
using namespace std;

float evaluate ( char* S, char*& RPN ) { //�ԣ����޳��׿ո�ģ����ʽS��ֵ����ת��Ϊ�沨��ʽRPN
   Stack<float> opnd; Stack<char> optr; //������ջ�������ջ /*DSA*/�κ�ʱ�̣�����ÿ������Ԫ��֮�����Сһ��
   S = removeSpace(S); //�޳� S �ж���Ŀո�
   optr.push ( '\0' ); //β�ڱ�'\0'Ҳ��Ϊͷ�ڱ�������ջ
   while ( !optr.empty() ) { //�������ջ�ǿ�֮ǰ�����������ʽ�и��ַ�
      if ( isdigit ( *S ) ) { //����ǰ�ַ�Ϊ����������
         readNumber ( S, opnd ); append ( RPN, opnd.top() ); //��������������������RPNĩβ
      } else //����ǰ�ַ�Ϊ���������
         switch ( orderBetween ( optr.top(), *S ) ) { //������ջ�������֮�����ȼ��ߵͷֱ���
            case '<': //ջ����������ȼ�����ʱ
               optr.push ( *S ); S++; //�����Ƴ٣���ǰ�������ջ
               break;
            case '=': //���ȼ���ȣ���ǰ�����Ϊ�����Ż���β���ڱ�'\0'��ʱ
               optr.pop(); S++; //�����Ų�������һ���ַ�
               break;
            case '>': { //ջ����������ȼ�����ʱ����ʵʩ��Ӧ�ļ��㣬�������������ջ
               char op = optr.pop(); append ( RPN, op ); //ջ���������ջ��������RPNĩβ
               if ( '!' == op ) { //������һԪ�����
                  float pOpnd = opnd.pop(); //ֻ��ȡ��һ������������
                  opnd.push ( calcu ( op, pOpnd ) ); //ʵʩһԪ���㣬�����ջ
               } else { //������������Ԫ�������
                  float pOpnd2 = opnd.pop(), pOpnd1 = opnd.pop(); //ȡ����ǰ������ /*DSA*/���ʣ��ɷ�ʡȥ������ʱ������
                  opnd.push ( calcu ( pOpnd1, op, pOpnd2 ) ); //ʵʩ��Ԫ���㣬�����ջ
               }
               break;
            }
            default : exit ( -1 ); //���﷨���󣬲�������ֱ���˳�
         }//switch
   }//while
   return opnd.pop(); //�������������ļ�����
}

float evaluate(char*& RPN) {
	Stack<float> opnd;
	readNumber(RPN, opnd); //��׺���ʽ��ͷ�϶���һ����
	while (true) {
		if (isspace(*RPN)) RPN++; //����ǿո񣬾ͼ�����ȡ��һ���ַ�
		else if (isdigit(*RPN)) readNumber(RPN, opnd); //��������֣��Ͷ�ȡ����
		else if (0 <= optr2rank(*RPN) && optr2rank(*RPN) <=  optr2rank ('!')) { 
			if (*RPN == '!') {
				float pOpnd = opnd.pop();
				opnd.push(calcu(*RPN, pOpnd)); //�����һԪ������������ջ����ջ
				RPN++;
			}
			else { //���򣬾���ջ���ʹ�ջ����ջ
				float pOpnd2 = opnd.pop(); 
				float pOpnd1 = opnd.pop();
				opnd.push(calcu(pOpnd1, *RPN, pOpnd2));
				RPN++;
			}
		}
		else if (*RPN == '\0') { //�������ַ���˵�������β���˳�ѭ��
			break;
		}
	}
	return opnd.pop(); //��󷵻�ջ��Ԫ��
}

/*s��һ��ջ����
  n����Ҫ��ת����ʮ������
  base�����ƣ����Ƕ����ƣ������� 2�����ǰ˽��ƣ������� 8���Դ�����*/
void convert(Stack<char> &s, __int64 n, int base) { //������
	//0 < n, 1 < base <= 16���½����µ���λ���ţ����� base ȡֵ��Χ�ʵ�����
	static char digit[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	while (n > 0) { //�ɵ͵��ߣ���һ������½����µĸ���λ
		s.push(digit[n % base]);//��������ǰλ����ջ
		n /= base; //�� n ����Ϊ��� base �ĳ���
	}
}//�½������ɸߵ��͵ĸ���λ���Զ����±�����ջ s ��

//void convert(Stack<char> &s, __int64 n, int base) { //��ʮ����ת�����������ƣ��ݹ��
//	static char digit[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	//0 < n, 1 < base <= 16���½����µ���λ���ţ����� base ȡֵ��Χ�ʵ�����
//	if (n > 0) { //����������֮ǰ��������
//		s.push(digit[n % base]); //�����¼��ǰ���λ����
//		convert(s, n / base, base); //ͨ���ݹ�õ����и���λ
//	}
//}//�½������ɸߵ��͵ĸ���λ���Զ����±�����ջ s ��

/*�����ʽexp[low, high]�е������Ƿ�ƥ��*/
bool paren(const char exp[], int low, int high) {
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
