/******************************************************************************************
 * ΢�Ź��ںţ�AProgrammer
 ******************************************************************************************/
#pragma once
#include "ListNode.h" //�����б�ڵ���

template <typename T> class LinkedList { //�б�ģ����
private:
	int _size; //��ģ
	ListNode<T>* header; //ͷ�ڱ�
	ListNode<T>* trailer; //β�ڱ�

protected: /* �ڲ����� */
	void init() { //��ʼ���������б����ʱͳһ����
		header = new ListNode<T>; //����ͷ�ڱ��ڵ�
		trailer = new ListNode<T>; //����β�ڱ��ڵ�
		header->succ = trailer; header->pred = NULL; //����
		trailer->pred = header; trailer->succ = NULL; //����
		_size = 0; //��¼��ģ
	}

	void copyNodes(ListNode<T>* p, int n) { //O(n)
		init(); //����ͷ��β�ڱ��ڵ㲢����ʼ��
		while (n--) { //������p��n��������Ϊĩ�ڵ����
			insertAsLast(p->data);
			p = p->succ;
		}
	}

    int clear(){ //������нڵ�
        int oldSize = _size;
   	    while ( 0 < _size ) remove ( header->succ ); //����ɾ���׽ڵ㣬ֱ���б���
        return oldSize;
    }

	/*��·�鲢
	  �����޸�ָ��ָ������ݣ�����Ҫ��ָ�뱾������޸ģ����Բ�������������*/
	void merge(ListNode<T>* &p, int n, LinkedList<T> &L, ListNode<T>* q, int m) {
		ListNode<T>* pp = p->pred; //����ǰ����������header�����Ա㷵�ص�ǰ�ڵ�
		while (0 < m) { //��q��δ�Ƴ�����֮ǰ
			if ((0 < n) && p->data < q->data) { //��p���������ڣ���p->dataС�ڵ���q->data
				if (q == (p = p->succ))	break; n--; //��p����ϲ����������滻Ϊֱ�Ӻ��
			}else { //��p�ѳ����ҽ磬��q->dataС��p->data��
				insertBefore(p, L.remove((q = q->succ)->pred)); //��qת����p֮ǰ
				m--;
			}
		}
		p = pp->succ; //ȷ���鲢������ģ��£����
	}

	/*����Ĺ鲢�����㷨������ʼ��λ��p��n��Ԫ������*/
	void mergesort(ListNode<T>* &p, int n) {
		//assert(valid(p) && rank(p) + n <= _size);
		if (n < 2) return; //��������Χ���㹻С����ֱ�ӷ���
		ListNode<T>* pp = p->pred;

		//�ݹ�
		int m = n >> 1; //���е�Ϊ��
		ListNode<T>* q = p;
		for (int i = 0; i < m; i++) //��������
			q = q->succ;
		
		mergesort(p, m); //��ǰ�������������
		mergesort(q, n - m); //�Ժ��������������
		merge(p, m, *this, q, n - m);

		p = pp->succ;
	}

public:
// ���캯��
	/*Ĭ�Ϲ��캯��*/
	LinkedList () {
		init();
	}

	//���帴���б�L
    LinkedList ( LinkedList<T> & L ) {  
    	copyNodes ( L.first(), L._size ); 
    }
    
    //����L���Ե�r�����n�assert: r+n <= L._size��
    LinkedList ( LinkedList<T> const& L, int r, int n ) {
        copyNodes ( L[r], n );
    }
    
    //�����б�����λ��p���n�assert: pΪ�Ϸ�λ�ã���������n-1����̽ڵ㣩
    LinkedList ( ListNode<T> p, int n ) {
        copyNodes ( p, n );
    }

// ��������
    ~LinkedList(){ //�ͷţ�����ͷ��β�ڱ����ڵģ����нڵ�
        clear(); 
        delete header; 
        delete trailer;
    }

// ֻ�����ʽӿ�
	int size() const { //��ģ
		return _size;
	}

	bool empty() const { return _size <= 0; } //�п�

	//���ز����� ��[]����֧��ѭ�ȷ���
	T operator[](int r) const { //O(r)��Ч�ʵ��£���ż��Ϊ֮��ȴ���˳���
		ListNode<T>* p = first(); //���׽ڵ����
		while (0 < r--) p = p->succ; //˳����r���ڵ㼴��
		return p->data; //Ŀ��ڵ�
	} //��һ�ڵ���ȣ��༴ǰ��������

	//�˺������ܺ����ز����� ��[]�� һ�������Ƿ��ص� r ���ڵ����ֵ
	T get(int r) const { //O(r)
		ListNode<T>* p = first(); //���׽ڵ����
		while (0 < r--) p = p->succ; //˳����r���ڵ㼴��
		return p->data; //Ŀ��ڵ�
	} //��һ�ڵ���ȣ��༴ǰ��������

	/*�����׽ڵ�*/
	ListNode<T>* first() const {
		return _size == 0 ? NULL : header->succ;
	}

	/*����ĩ�ڵ�*/
	ListNode<T>* last() const {
		return _size == 0 ? NULL : trailer->pred;
	}
	//�ж�λ��p�Ƿ����Ϸ�
    bool valid ( ListNode<T> p ) { 
		return p && ( trailer != p ) && ( header != p ); 
	} //��ͷ��β�ڵ��ͬ��NULL

	/*�ж����нڵ��Ƿ�����������ǣ�����true�����򷵻�false
	  Ҫ��T Ϊ�������ͻ���ʵ���˶������ ��>�� ������*/
	int disordered() const { //ͳ����������Ԫ�ضԵ�����
		int n = 0; ListNode<T>* p = first();
		for ( int i = 0; i < _size - 1; p = p->succ, i++ )
			if ( p->data > p->succ->data ) n++;
		return n;
	}

	//�����б����
	ListNode<T>* find(T const & e) const {
		return find ( e, _size, trailer );
	}

	/*����
	  �ڽڵ�p��������trailer���� n �����棩ǰ���У��ҵ����� e �������
	  Ҫ��T Ϊ�������ͻ���ʵ���˶������ ��==�� ������*/
	ListNode<T>* find(T const & e, int n, ListNode<T>* p) const{ //˳����ң�O(n)
		while (0 < n-- && p->pred != NULL) //������������� p ��ǰ���� e �ȶ�
			if (e == (p = p->pred)->data)
				return p; //ֱ�����л�ΧԽ��
		return NULL; //��Խ����߽磬��ζ�Ų���ʧ��
	}//header �Ĵ���ʹ�ô����Ϊ���

	/*�������б��ڽڵ�p��������trailer����n�����棩ǰ���У��ҵ�������e�������
	  Ҫ��T Ϊ�������ͻ������ز����� ��<=��*/
	ListNode<T>* search(T const& e, int n, ListNode<T>* p) const {
		// assert: 0 <= n <= rank(p) < _size
		while (0 <= n--) //����p�������n��ǰ����������������Ƚ�
			/*DSA*/ {
			if (((p = p->pred)->data) <= e) break; //ֱ�����С���ֵԽ���ΧԽ��
			/*DSA*/
		}
		// assert: ����λ��p�ط����������Լ���������ܴ�ǰ���һ�ιؼ���ȽϿ���û�����壨��Ч����-inf�Ƚϣ�
		return p; //���ز�����ֹ��λ��
	} //ʧ��ʱ������������߽��ǰ����������header�����������߿�ͨ��valid()�жϳɹ����
	
	//�����б��������
	ListNode<T>* search(T const& e) const {
		return search(e, _size, trailer);
	}

// ��д���ʽӿ�
	ListNode<T>* insertAsFirst(T const& e) { //��e��Ϊ�׽ڵ��������
		return insertAfter(header, e); //�൱�� e ��Ϊͷ�ڱ�header�ĺ�̲���
	}

	ListNode<T>* insertAsLast(T const& e) { //��e��Ϊĩ�ڵ��������
		return insertBefore(trailer, e); //�൱�� e ��Ϊβ�ڱ�trailer��ǰ������
	}

	/*e ���� p ��ǰ������*/
	ListNode<T>* insertBefore(ListNode<T>* p, T const& e) {
		ListNode<T>* x = new ListNode<T>(e, p->pred, p); //��������ʱ100����
		p->pred->succ = x; //�������ӣ������½ڵ��λ��
		p->pred = x;
		_size++;
		return x;
	}

	/*e ���� p �ĺ�̲���*/
	ListNode<T>* insertAfter(ListNode<T>* p, T const& e) {
		ListNode<T>* x = new ListNode<T>(e, p, p->succ); //��������ʱ100����
		p->succ->pred = x;
		p->succ = x;
		_size++;
		return x;
	}
	/*ɾ���Ϸ�λ��p���ڵ㣬��������ֵ*/
	T remove(ListNode<T> * p) {
		T e = p->data; //���ݴ�ɾ���ڵ���ֵ����������T��ֱ�Ӹ�ֵ��
		p->pred->succ = p->succ;
		p->succ->pred = p->pred;
		delete p; //�ͷ��ڴ�
		_size--;
		return e; //���ر�����ֵ
	}

	/*������������*/
	void sort(ListNode<T>* p, int n) {
		mergesort ( p, n );  //�鲢����
	}

	//������������
	void sort() {
		sort(first(), _size);
	}

	int deduplicate() { //�޳����������е��ظ��ڵ�
		if (_size < 2) return 0; //ƽ��������Ȼ���ظ�
		int oldSize = _size; //��¼ԭ��ģ
		ListNode<T>* p = header; int r = 0; //p���׽ڵ㿪ʼ
		while (trailer != (p = p->succ)) { //����ֱ��ĩ�ڵ�
			ListNode<T>* q = find(p->data, r, p); //��p��r�����棩ǰ���в�����ͬ��
			q ? remove(q) : r++; //����ȷ���ڣ���ɾ��֮�������ȼ�һ
		} //assert: ѭ�������е�����ʱ�̣�p������ǰ��������ͬ
		return oldSize - _size; //�б��ģ�仯��������ɾ��Ԫ������
	}

	/*���������ȥ�ز����������޳��ظ�Ԫ�أ�Ч�ʸ���
	  Ҫ�������е�Ԫ��������ģ������� T �ǻ������ͻ������ز����� ��!=��*/
	int uniquify() { 
		if (_size < 2) return 0; //ƽ��������Ȼ���ظ�
		int oldSize = _size; //��¼ԭ��ģ
		ListNode<T>* p = first(); ListNode<T>* q; //pΪ��������㣬qΪ����
		while (trailer != (q = p->succ)) //����������ڵĽڵ��(p, q)
			if (p->data != q->data) p = q; //�����죬��ת����һ����
			else remove(q); //������ͬ����ɾ������
		return oldSize - _size; //�б��ģ�仯��������ɾ��Ԫ������
	}

	/*�� r ���ڵ��� 0������ r ���ڵ��ֵ��Ϊ e
	  �� r С�� 0���������� -r ���ڵ��ֵ��Ϊ e*/
	void set(int r, T e) {
		if (r > 0 && r >= _size) return;
		if (r < 0 && -r > _size) return;

		if (r >= 0) {
			ListNode<T>* p = first(); //���׽ڵ����
			while (0 < r--) p = p->succ; //˳����r���ڵ㼴��
			p->data = e;
		}
		else {
			ListNode<T>* p = last(); //���׽ڵ����
			while (0 > ++r) p = p->pred; //˳����r���ڵ㼴��
			p->data = e;
		}
	}
};
