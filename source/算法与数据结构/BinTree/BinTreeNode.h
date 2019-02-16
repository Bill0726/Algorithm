#pragma once
#include "print.h"
#include "../DataStructure/Stack.h"
#include "../DataStructure/Queue.h"

template <typename T> struct BinTreeNode {
	T data; //������
	BinTreeNode * LeftChild; //����ָ��
	BinTreeNode * RightChild; //�Һ���ָ��
	BinTreeNode * parent; //���ڵ�ָ��
};

/*�������*/
template <typename T, typename VST>
void travPre_R(BinTreeNode<T> * root, VST& visit) {
	if (!root)
		return;
	visit(root->data);
	travPre_R(root->LeftChild);
}

template <typename T>
void travPre_R(BinTreeNode<T> * root) {//��������������㷨���ݹ�棩
	if (!root)
		return;
	cout << root->data;
	travPre_R(root->LeftChild);
	travPre_R(root->RightChild);
}

template <typename T>
void travPre_I1(BinTreeNode<T> * root) {//��������������㷨��������#1��
	Stack<BinTreeNode<T>*> s; //����ջ
	if (root) //������ڵ㲻Ϊ��
		s.push(root); //������ڵ���ջ
	while (!s.empty()) { //��ջ���֮ǰ����ѭ��
		root = s.pop(); cout << root->data; //���������ʵ�ǰ�ڵ�
		if (root->RightChild)
			s.push(root->RightChild); //�Һ���������
		if (root->LeftChild)
			s.push(root->LeftChild); //���Ӻ����ȳ�
	}
}

//�ӵ�ǰ�ڵ�����������֧�������룬ֱ��û�����֧�Ľڵ㣻��;�ڵ���������������
template <typename T> //Ԫ�����͡�������
static void visitAlongLeftBranch ( BinTreeNode<T>* x, Stack<BinTreeNode<T>*>& S ) {
   while ( x ) {
      cout << x->data; //���ʵ�ǰ�ڵ�
	  if(x->RightChild)
		 S.push ( x->RightChild ); //�Һ�����ջ�ݴ棨���Ż���ͨ���жϣ�����յ��Һ�����ջ��
      x = x->LeftChild;  //�����֧����һ��
   }
}

template <typename T> //Ԫ�����͡�������
void travPre_I2 ( BinTreeNode<T>* root) { //��������������㷨��������#2��
   Stack<BinTreeNode<T>*> S; //����ջ
   while ( true ) {
      visitAlongLeftBranch ( root, S ); //�ӵ�ǰ�ڵ��������������
      if ( S.empty() ) break; //ֱ��ջ��
      root = S.pop(); //������һ�������
   }
}
/*�����������*/

/*�������*/
template <typename T>
void travIn_R(BinTreeNode<T> * root) {//��������������㷨���ݹ�棩
	if (!root)
		return;
	travIn_R(root->LeftChild);
	cout << root->data;
	travIn_R(root->RightChild);
}

template <typename T> //�ӵ�ǰ�ڵ�����������֧�������룬ֱ��û�����֧�Ľڵ�
static void goAlongLeftBranch ( BinTreeNode<T> * x, Stack<BinTreeNode<T> * >& S ) {
	while (x) { S.push(x); x = x->LeftChild; } //��ǰ�ڵ���ջ���漴������֧���룬����ֱ��������
}

template <typename T> //Ԫ�����͡�������
void travIn_I(BinTreeNode<T> * root) {//��������������㷨�������棩
   Stack<BinTreeNode<T> *> S; //����ջ
   while ( true ) {
      goAlongLeftBranch ( root, S ); //�ӵ�ǰ�ڵ������������ջ
      if ( S.empty() ) break; //ֱ�����нڵ㴦�����
      root = S.pop(); 
	  cout << root->data; //����ջ���ڵ㲢����֮
      root = root->RightChild; //ת��������
   }
}

template <typename T> //Ԫ�����͡�������
void travIn_I2 ( BinTreeNode<T>* root ) { //��������������㷨��������#2��
   Stack<BinTreeNode<T>*> S; //����ջ
   while ( true )
      if ( root ) {
         S.push ( root ); //���ڵ��ջ
         root = root->LeftChild; //�������������
      } else if ( !S.empty() ) {
         root = S.pop(); //��δ���ʵ�������Ƚڵ���ջ
         cout << root->data; //���ʸ����Ƚڵ�
         root = root->RightChild; //�������ȵ�������
      } else
         break; //�������
}
/*�����������*/

/*�������*/
template <typename T>
void travPost_R(BinTreeNode<T> * root) {//��������������㷨���ݹ�棩
	if (!root)
		return;
	travPost_R(root->LeftChild);
	travPost_R(root->RightChild);
	cout << root->data;
}

template <typename T> //����Sջ���ڵ�Ϊ���������У��ҵ�������ɼ�Ҷ�ڵ�
static void gotoHLVFL ( Stack<BinTreeNode<T>*>& S ) { //��;�����ڵ�������ջ
   while ( BinTreeNode<T>* x = S.top() ) //�Զ����£�������鵱ǰ�ڵ㣨��ջ����
      if ( x->LeftChild ) { //����������
         if ( x->RightChild ) S.push ( x->RightChild ); //�����Һ��ӣ�������ջ
         S.push ( x->LeftChild ); //Ȼ���ת������
      } else //ʵ������
         S.push ( x->RightChild ); //������
   S.pop(); //����֮ǰ������ջ���Ŀսڵ�
}

template <typename T>
void travPost_I ( BinTreeNode<T>* root ) { //�������ĺ�������������棩
   Stack<BinTreeNode<T>*> S; //����ջ
   if ( root ) S.push ( root ); //���ڵ���ջ
   while ( !S.empty() ) {
      if ( S.top() != root->parent ) //��ջ���ǵ�ǰ�ڵ�֮�������Ϊ�����֣�����ʱ��
         gotoHLVFL ( S ); //����������Ϊ��֮�����У��ҵ�HLVFL���൱�ڵݹ��������У�
      root = S.pop(); cout << root->data; //����ջ������ǰһ�ڵ�֮��̣���������֮
   }
}
/*�����������*/

/*��α���*/
template <typename T> //Ԫ������
void travLevel ( BinTreeNode<T>* root ) { //��������α����㷨
   Queue<BinTreeNode<T>*> Q; //��������
   Q.enqueue ( root ); //���ڵ����
   while ( !Q.empty() ) { //�ڶ����ٴα��֮ǰ����������
      BinTreeNode<T>* x = Q.dequeue(); cout << x->data; //ȡ�����׽ڵ㲢����֮
      if ( x->LeftChild ) Q.enqueue ( x->LeftChild ); //�������
      if ( x->RightChild ) Q.enqueue ( x->RightChild ); //�Һ������
   }
}
/*��α�������*/