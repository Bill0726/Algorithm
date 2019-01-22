#pragma once
#include "print.h"
#include "../DataStructure/Stack.h"

template <typename T> struct BinTreeNode {
	T data; //������
	BinTreeNode * LeftChild; //����ָ��
	BinTreeNode * RightChild; //�Һ���ָ��
};

template <typename T>
void travPre_R(BinTreeNode<T> * root) {
	if (!root)
		return;
	cout << root->data;
	travPre_R(root->LeftChild);
	travPre_R(root->RightChild);
}

template <typename T>
void travPre_I1(BinTreeNode<T> * root) {
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

template <typename T, typename VST>
void travPre_R(BinTreeNode<T> * root, VST& visit) {
	if (!root)
		return;
	visit(root->data);
	//travPre_R(root->LeftChild);
}