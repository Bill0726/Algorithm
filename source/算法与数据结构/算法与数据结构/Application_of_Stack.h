#pragma once
#include "Stack.h"
#include <math.h>
#include <cstring>
#include <iostream>
using namespace std;

#define N_OPTR 9 //���������
typedef enum { ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE } Operator; //���������
//�ӡ������ˡ������˷����׳ˡ������š������š���ʼ������ֹ��

const char pri[N_OPTR][N_OPTR] = { //��������ȵȼ� [ջ��] [��ǰ]
   /*              |-------------------- �� ǰ �� �� �� --------------------| */
   /*              +      -      *      /      ^      !      (      )      \0 */
   /* --  + */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
   /* |   - */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
   /* ջ  * */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
   /* ��  / */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
   /* ��  ^ */    '>',   '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
   /* ��  ! */    '>',   '>',   '>',   '>',   '>',   '>',   ' ',   '>',   '>',
   /* ��  ( */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
   /* |   ) */    ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',
   /* -- \0 */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   ' ',   '='
};

Operator optr2rank ( char op ) { //�������ת������
   switch ( op ) {
      case '+' : return ADD; //��
      case '-' : return SUB; //��
      case '*' : return MUL; //��
      case '/' : return DIV; //��
      case '^' : return POW; //�˷�
      case '!' : return FAC; //�׳�
      case '(' : return L_P; //������
      case ')' : return R_P; //������
      case '\0': return EOE; //��ʼ������ֹ��
      default  : exit ( -1 ); //δ֪�����
   }
}

char orderBetween ( char op1, char op2 ) //�Ƚ����������֮������ȼ�
{ return pri[optr2rank ( op1 ) ][optr2rank ( op2 ) ]; }

void readNumber ( char*& p, Stack<float>& stk ) { //����ʼ��p���Ӵ�����Ϊ��ֵ�������������ջ
   stk.push ( ( float ) ( *p - '0' ) ); //��ǰ��λ��Ӧ����ֵ��ջ
   while ( isdigit ( * ( ++p ) ) ) //ֻҪ�������н��ڵ����֣�����λ���������������
      stk.push ( stk.pop() * 10 + ( *p - '0' ) ); //����ԭ��������׷������λ������ֵ������ջ
   if ( '.' != *p ) return; //�˺��С���㣬����ζ�ŵ�ǰ�������������
   float fraction = 1; //������ζ�Ż���С������
   while ( isdigit ( * ( ++p ) ) ) //��λ����
      stk.push ( stk.pop() + ( *p - '0' ) * ( fraction /= 10 ) ); //С������
}

void append ( char*& rpn, float opnd ) { //������������RPNĩβ
   int n = strlen ( rpn ); //RPN��ǰ���ȣ���'\0'��β������n + 1��
   char buf[64];
   if ( opnd != ( float ) ( int ) opnd ) sprintf ( buf, "%.2f \0", opnd ); //�����ʽ����
   else                          sprintf ( buf, "%d \0", ( int ) opnd ); //������ʽ
   rpn = ( char* ) realloc ( rpn, sizeof ( char ) * ( n + strlen ( buf ) + 1 ) ); //��չ�ռ�
   strcat ( rpn, buf ); //RPN�ӳ�
}

void append ( char*& rpn, char optr ) { //�����������RPNĩβ
   int n = strlen ( rpn ); //RPN��ǰ���ȣ���'\0'��β������n + 1��
   rpn = ( char* ) realloc ( rpn, sizeof ( char ) * ( n + 3 ) ); //��չ�ռ�
   sprintf ( rpn + n, "%c ", optr ); rpn[n + 2] = '\0'; //����ָ���������
}

int  facI(int n) { //���� n �Ľ׳�
	int res = 1;
	if (n == 0)
		return res;
	while (n > 0) {
		res *= n--;
	}
	return res;
}

float calcu ( float a, char op, float b ) { //ִ�ж�Ԫ����
   switch ( op ) {
      case '+' : return a + b;
      case '-' : return a - b;
      case '*' : return a * b;
      case '/' : if ( 0==b ) exit ( -1 ); return a/b; //ע�⣺����и�����Ϊ����ܲ���ȫ
      case '^' : return pow ( a, b );
      default  : exit ( -1 );
   }
}

float calcu ( char op, float b ) { //ִ��һԪ����
   switch ( op ) {
      case '!' : return ( float ) facI ( ( int ) b ); //Ŀǰ���н׳ˣ����մ˷�ʽ���
      default  : exit ( -1 );
   }
}

char* removeSpace ( char* s ) { //�޳�s[]�еİ׿ո�
   char* p = s, *q = s;
   while ( true ) {
      while ( isspace ( *q ) ) q++;
      if ( '\0' == *q ) { *p = '\0'; return s; }
      *p++ = *q++;
   }
}

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
