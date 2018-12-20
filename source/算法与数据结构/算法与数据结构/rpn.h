/******************************************************************************************
 * �����Դ�����ʲô���ʣ����Թ�ע΢�Ź��ںţ�AProgrammer
 * �����������΢�ţ�91395421
 * �һ����Ϊ����
 ******************************************************************************************/
#pragma once
#include <math.h>
#include <cstring>

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

void append(char*& rpn, char*& infix) {
    int n = strlen ( rpn ); //RPN��ǰ���ȣ���'\0'��β������n + 1��
	char buf[64];
	int i = 0;
	while (isdigit(*infix) || '.' == *infix) {
		buf[i++] = *infix;
		infix++;
	}
	buf[i++] = ' ';
	buf[i] = '\0';
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

/*��׺���ʽת���ɺ�׺���ʽ*/
void in2rpn(char* infix, char*& RPN) {
	Stack<char> optr; //��Ų�������ջ
	optr.push('\0');
	while (!optr.empty()) { //�������ջ�ǿ�ʱ�����������ʽ�еĸ��ַ�
		if (isspace(*infix)) infix++; //�����ո�ֱ�Ӻ��ԣ���ȡ��һ���ַ�
		else if (isdigit(*infix)) { //����ǰ�ַ�Ϊ����������
			append(RPN, infix); //ֱ��׷����RPNĩβ
		}
		else { //����������������
			switch (orderBetween(optr.top(), *infix)) { //��ջ���������뵱ǰ���������Ա�
				case '<': //��ջ�����������ȼ�С�ڵ�ǰ�����������ȼ�
					optr.push(*infix); infix++; break; //�򽫵�ǰ��������ջ
				case '=': //��ջ�������������ȼ����ڵ�ǰ�����������ȼ�����ʱֻ���������������ţ�
					optr.pop(); infix++; break; //��ֱ�ӽ�ջ����������������������һ�ַ�
				case '>': //��ջ�������������ȼ����ڵ�ǰ�����������ȼ�
					append(RPN, optr.pop()); break; //��ջ��������׷����RPNĩβ���������õ�ǰ���������µ�ջ����������Ƚ�
				default: //�������Ƿ��ַ���ֱ���˳�����
					exit(-1);
			}
		}
	}
}
