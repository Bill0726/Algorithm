#pragma once
#include "print.h"
template <typename T> struct Print //�������󣺱���һ��T�����
   {  void operator() ( T& e ) { cout << e; }  }; //����T��ֱ�ӱ���
