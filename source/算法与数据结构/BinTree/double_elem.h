#pragma once

template <typename T> struct Double //�������󣺱���һ��T�����
   {  void operator() ( T& e ) { e *= 2; }  }; //����T��ֱ�ӱ���
