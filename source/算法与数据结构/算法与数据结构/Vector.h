/******************************************************************************************
 * ΢�Ź��ںţ�AProgrammer
 ******************************************************************************************/
#pragma once
typedef int Rank; //��
#define DEFAULT_CAPACITY 3 //Ĭ�ϳ�ʼ������ʵ��Ӧ���п�����Ϊ����;
template <typename T> class Vector{ //����ģ����
    private: 
		Rank _size; //��ģ 
		int _capacity; //����
		T* _elem; //������

    public:
        /* Ĭ�ϵĹ��캯�� */
        Vector(int c = DEFAULT_CAPACITY);
        /* �������临�� */
        Vector(T const * A, Rank lo, Rank hi);
        /* �������临�� */
        Vector(Vector<T> const& V, Rank lo, Rank hi);
        /* �������帴�� */
        Vector(Vector<T> const& V);
        /* �����������ͷ��ڲ��ռ� */
        ~Vector();
        
        /* TΪ�������ͣ��������ظ�ֵ��������=������������ΪA[lo]��A[hi-1]*/
        void copyFrom(T const *A, Rank lo, Rank hi);
        /* �����ռ䲻��ʱ���� */
        void expand();
        /* �����������[]�� 0 <= r < _size */
        T & operator[](Rank r) const ;
        /* ��Ԫ��e���뵽��Ϊr��λ�ã�0 <= r <= size */
        Rank insert(Rank r, T const & e);//O(n-r)
        /* ɾ������[lo, hi), 0 <= lo <= hi <= size */
        int remove(Rank lo, Rank hi); //O(n - hi)
        /* ��Ԫ��ɾ��
         * ������������ɾ��������������[r] = [r, r + 1) */
        T remove(Rank r);
        /* ���Ҳ���
         * ���������������ԣ�TΪ���еȵĻ������ͣ��������ز����� ��==�� �� ��!=��
         * ���������������ԣ�TΪ�ɱȽϵĻ������ͣ��������ز����� ��<�� �� ��>�� */
        Rank find(T const & e, Rank lo, Rank hi) const;
		//Ψһ����ɾ�������е��ظ�Ԫ�أ����ر�ɾ��Ԫ����Ŀ
		int deduplicate();

		//��������������Ψһ��
        //���ر�ɾ����Ԫ�صĸ���
        //������������ģ��򷵻� -1
        int uniquify();
		
		/* 
		   ��������������e��λ�ã�������ʧ�ܣ����ز�����e��Ԫ�ص������
		   ����e�����ҵ�Ŀ��Ԫ��
		   ����low�����ҷ�Χ���Ͻ�
		   ����high�����ҷ�Χ���½����һ��λ��
		*/
		Rank binSearch(T const& e, Rank low, Rank high);

        //�ж������Ƿ�����
        //����/���������У�����/����һ������Ԫ��˳��/����
        //��ˣ���������Ե���Ŀ�������Զ�������������̶�
        int disordered() const;

		/*ð������
		  ����low������Χ���½�
		  ����high������Χ���Ͻ����һ��λ��*/
		void bubbleSort(Rank low, Rank high);
		Rank bubble(Rank low, Rank high);
		//��������Ԫ�ص�ֵ
		void swap(T &a, T &b);

		/*�鲢����
		  ����low������Χ���½�
		  ����high������Χ���Ͻ����һ��λ��*/
		void mergeSort(Rank low, Rank high);
		void merge(Rank low, Rank mid, Rank high);

		//�����������еĽϴ���
		int max(int a, int b);
		//���������Ĺ�ģ _size
		int size();

        //���� ��[]�� ���������������ã������ſ��ԶԷ���ֵ��ֵ
        int& operator[] (int i);

		//�ж������Ƿ�Ϊ��
		bool empty() {
			return _size > 0 ? false : true;
		}
};

/* Ĭ�ϵĹ��캯�� */
template<typename T>
Vector<T>::Vector(int c){
    _elem = new T[_capacity = c];
    _size = 0;
}
/* �������临�� */
template<typename T>
Vector<T>::Vector(T const *A, Rank lo, Rank hi){
    copyFrom(A, lo, hi);
}
/* �������临�� */
template<typename T>
Vector<T>::Vector(Vector<T> const& V, Rank lo, Rank hi){
    copyFrom(V._elem, lo, hi);
}
/* �������帴�� */
template<typename T>
Vector<T>::Vector(Vector<T> const& V){
    copyFrom(V._elem, 0, V._size);
}
/* �����������ͷ��ڲ��ռ� */
template<typename T>
Vector<T>::~Vector(){
    delete [] _elem;
}

/* TΪ�������ͣ��������ظ�ֵ��������=������������ΪA[lo]��A[hi-1]*/
template<typename T>
void Vector<T>::copyFrom(T const *A, Rank lo, Rank hi){
    _elem = new T[_capacity = 2 * (hi - lo)]; //����ռ�
    _size = 0; //��ģ����
    while(lo < hi){ //A[lo, hi)�ڵ�Ԫ����һ
        _elem[_size++] = A[lo++]; //������_elem[0, hi-lo]
    }
}
/* �����ռ䲻��ʱ���� */
template<typename T>
void Vector<T>::expand(){
    if(_size < _capacity) //��δ��Աʱ����������
      return;
    _capacity = max(_capacity, DEFAULT_CAPACITY); //��������С����
    T* oldElem = _elem;
    _elem = new T[_capacity <<= 1]; //�����ӱ�
    for (int i = 0; i < _size; i++)//����ԭ��������
      _elem[i] = oldElem[i]; //TΪ�������ͣ����������������=��
    delete [] oldElem; //�ͷ�ԭ�ռ�
}
/* �����������[]�� 0 <= r < _size */
template<typename T>
T & Vector<T>::operator[](Rank r) const {
    return _elem[r];
}
/* ��Ԫ��e���뵽��Ϊr��λ�ã�0 <= r <= size */
template<typename T>
Rank Vector<T>::insert(Rank r, T const & e){//O(n-r)
    expand(); //���б�Ҫ������
    for(int i = _size; i > r; i--){ //�Ժ���ǰ
        _elem[i] = _elem[i-1]; //���Ԫ��˳�κ���һ����Ԫ
    }
    _elem[r] = e;
    _size++; //������Ԫ�أ���������
    return r; //������
}
/* ɾ������[lo, hi), 0 <= lo <= hi <= size */
template<typename T>
int Vector<T>::remove(Rank lo, Rank hi){ //O(n - hi)
    if(lo == hi) //����Ч�ʿ��ǣ����������˻����
      return 0;
    while (hi < _size) //[hi, _size)˳��ǰ��hi-loλ
      _elem[lo++] = _elem[hi++];
    _size = lo; //���¹�ģ�����б�Ҫ������
    return hi - lo; //���ر�ɾ��Ԫ�ص���Ŀ
}
/* ��Ԫ��ɾ��
 * ������������ɾ��������������[r] = [r, r + 1) */
template<typename T>
T Vector<T>::remove(Rank r){
    T e = _elem[r]; //���ݱ�ɾ����Ԫ��
    remove(r, r + 1); //��������ɾ���㷨
    return e; //���ر�ɾ����Ԫ��
}
/* ���Ҳ���
 * ���������������ԣ�TΪ���еȵĻ������ͣ��������ز����� ��==�� �� ��!=��
 * ���������������ԣ�TΪ�ɱȽϵĻ������ͣ��������ز����� ��<�� �� ��>�� */
template<typename T>
Rank Vector<T>::find(T const & e, Rank lo, Rank hi) const{
    //O(hi - lo) = O(n)�������ж��Ԫ��ʱ���ɷ����������
    while((lo < hi--) && e != _elem[hi]); //�������
    return hi; //hi < lo��ζ��ʧ�ܣ�����hi������Ԫ�ص���
}

//Ψһ����ɾ�������е��ظ�Ԫ�أ����ر�ɾ��Ԫ����Ŀ
template<typename T>
inline int Vector<T>::deduplicate()
{
	int oldSize = _size; //��¼ԭʼ��ģ
	Rank i = 1; //�� _elem[i] ��ʼ
	while (i < _size) { //��ǰ�����һ�����Ԫ�� _elem[i]
		find(_elem[i], 0, i) < 0 ? //��ǰ׺��Ѱ����ͬ��
			i++ //������ͬ�������������
: remove(i); //����ɾ����ͬ�ߣ����� 1 ��������
	}
	return oldSize - _size; //������ģ�仯������ɾ��Ԫ������
}

template <typename T>
int Vector<T>::uniquify() {
	if (disordered())
		return -1;
	Rank i = 0, j = 0; //���Ի��조���ڡ�Ԫ�ص���
	while (++j < _size) { //��һɨ�裬ֱ��ĩԪ��
		if (_elem[i] != _elem[j]) { //������ͬ�ߣ����ֲ�ͬԪ��ʱ����ǰ����������ǰ���Ҳ�
			_elem[++i] = _elem[j];
		}
	}
	_size = ++i;
	return j - i; //������ģ�仯��������ɾ��Ԫ������
}

template<typename T>
inline Rank Vector<T>::binSearch(T const & e, Rank lo, Rank hi)
{
	while (lo < hi) { //�����ԣ�A[0, lo) <= e < A[hi, n)
		Rank mid = (lo + hi) >> 1; //���е�Ϊ��㣬���ȽϺ�ȷ������
		(e < _elem[mid]) ? hi = mid : lo = mid + 1; //[lo, mid)��(mid, hi)
	}//����ʱ��A[lo = hi]Ϊ����e����СԪ��
	return --lo; //��lo-1��������e��Ԫ�ص������
}

template<typename T>
int Vector<T>::disordered() const {
	int n = 0; //������
	for (int i = 1; i < _size; i++) //��һ����������Ԫ��
		n += (_elem[i - 1] > _elem[i]); //���������
	return n; //����ֵn������������Եĸ��������ҽ��� n = 0 ʱ��������
}//��ֻ���ж��Ƿ��������״����������֮�󣬼���������ֹ

//ð������
template<typename T>
void Vector<T>::bubbleSort(Rank low, Rank high) {
	while (low < (high = bubble(low, high))); //����ɨ�轻����ֱ��ȫ��
}
template<typename T>
Rank Vector<T>::bubble(Rank low, Rank high) {
	Rank last = low; //���Ҳ������Գ�ʼ��Ϊ[low - 1, low]
	while (++low < high) { //�������ң���һ����������Ԫ��
		if (_elem[low - 1] > _elem[low]) { //��������������Ҳ������λ�ü�¼��������
			last = low;
			swap(_elem[low - 1], _elem[low]);
		}
	}
	return last; //�������Ҳ�������λ��
}
//����a��b����Ԫ�ص�ֵ
template<typename T>
void Vector<T>::swap(T &a, T &b) {
	if (typeid(T) == typeid(int)) {
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	else {
		T temp = a;
		a = b;
		b = a;
	}
}
template<typename T>
inline void Vector<T>::mergeSort(Rank low, Rank high)
{
	Rank step = 1;
	while (step < high) {
		for (Rank i = low; i < high; i += step << 1) {
			Rank lo = i, hi = (i + (step << 1)) <= high ? (i + (step << 1)) : high; //�����·�鲢���Ͻ����½� 
			Rank mid = i + step <= high ? (i + step) : high;
			merge(lo, mid, hi);
		}

		//��i��i+step�������������н��кϲ�
		//���г���Ϊstep
		//��i�Ժ�ĳ���С�ڻ��ߵ���stepʱ���˳�
		step <<= 1;//�ڰ�ĳһ�����鲢����֮�󣬲����ӱ�
	}
}
template<typename T>
inline void Vector<T>::merge(Rank low, Rank mid, Rank high){
	T* A = _elem + low; //�ϲ��������A[0, high - low) = _elem[low, high)
	int lb = mid - low;
	T* B = new T[lb]; //ǰ������B[0, lb) = _elem[low, mid)
	for (Rank i = 0; i < lb; B[i] = A[i++]); //����ǰ������B
	int lc = high - mid;
	T* C = _elem + mid; //��������C[0, lc) = _elem[mid, high)

	//��һ�ִ���ʽ
	for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);) { //B[j]��C[k]��С��ת��A��ĩβ
		if (j < lb && k < lc) //���j��k��û��Խ�磬��ô��ѡ��B[j]��C[k]�еĽ�С�߷���A[i]
			A[i++] = B[j] < C[k] ? B[j++] : C[k++];
		if (j < lb && lc <= k) //���jû��Խ���kԽ���ˣ���ô�ͽ�B[j]����A[i]
			A[i++] = B[j++];
		if (lb <= j && k < lc) //���kû��Խ���jԽ���ˣ���ô�ͽ�C[k]����A[i]
			A[i++] = C[k++];
	}

	//�ڶ��ִ���ʽ
	//for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);) { //B[j]��C[k]��С��ת��A��ĩβ
	//	if ((j < lb) && (lc <= k || B[j] <= C[k])) //C[k]���޻�С
	//		A[i++] = B[j++];
	//	if ((k < lc) && (lb <= j || C[k] < B[j])) //B[j]���޻����
	//		A[i++] = C[k++];
	//}//��ѭ��ʵ�ֽ��գ�����Ч�ʶ��ԣ������ִ���
	delete[] B; //�ͷ���ʱ�ռ�B
}

template<typename T>
int Vector<T>::max(int a, int b) {
	return a > b ? a : b;
}

template<typename T>
inline int Vector<T>::size()
{
	return _size;
}

template<typename T>
int& Vector<T>::operator[] (int i){
    return _elem[i];
}
