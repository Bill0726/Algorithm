#include <iostream>

using namespace std;

/* A�������׵�ַ
 * target�����ҵ�Ŀ��Ԫ��
 * low�����ҷ�Χ���½�λ��
 * high�����ҷ�Χ���Ͻ�λ��
 *
 * ����ֵ�������ҳɹ����򷵻�Ŀ��Ԫ�ص�λ�ã�������ʧ�ܣ��򷵻�-1*/
int binSearch(int * A, int target, int low, int high){
    while(low <= high){ //ÿ���������ܶ�Ҫ�����αȽ��жϣ���������֧
        //int mid = int((low + high) * 0.618); //���е�Ϊ��� 
        int mid = (low + high) >> 1; //���е�Ϊ���
        cout << A[mid] << endl;
        if(target < A[mid])
            high = mid - 1 ; //����ǰ���[low, mid]�������� 
        else if(A[mid] < target)
            low = mid + 1; //�������[mid+1, high]��������
        else 
            return mid; //��mid������
    }
    return -1; //����ʧ�ܣ�����-1
}
/* A�������׵�ַ
 * target�����ҵ�Ŀ��Ԫ��
 * low�����ҷ�Χ���½�λ��
 * high�����ҷ�Χ���Ͻ�λ��
 *
 * ����ֵ�������ҳɹ����򷵻�Ŀ��Ԫ�ص�λ�ã�������ʧ�ܣ��򷵻�-1*/
int binSearch2(int * A, int target, int low, int high) {
	high++;
	int n = 0;
	while (1 < high - low) {
		int mid = (low + high) >> 1; //���е�Ϊ��㣬���ȽϺ�ȷ������
		(target < A[mid]) ? high = mid : low = mid; //��������Ϊ[lwo, mid-1]��[mid, high]
		n++;
	}//����ʱhigh = low
	cout << n;
	return (target == A[low]) ? low : -1; //��������Ԫ�����ڵ�λ�û�-1
}

/*����a������ǲ������е�ĳһ����
  ����ֵ������������ǲ������е�λ��*/
int fibLength(int a) {
	int f = 0, f1 = 0, f2 = 1, index = 1;
	if (f1 == a)
		return 1;
	if (f2 == a)
		return 2;
	while (f <= a) {
		f = f1 + f2;
		f1 = f2;
		f2 = f;
		index++;
	}
	return index;
}

/*����len������ǲ����еĳ���
  ����ֵ������һ������ָ�룬��ָ��ָ�򳤶�Ϊlen�����飬�������д����ǰlen������ǲ���*/
int * createFibSequence(int len) {
	int * fib = new int[len];
	if (len == 1) {
		fib[0] = 0;
		return fib;
	}else if (len == 2) {
		fib[0] = 0;
		fib[1] = 1;
		return fib;
	}
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i < len; i++) {
		fib[i] = fib[i - 2] + fib[i - 1];
	}
	return fib;
}

/* A�������׵�ַ
 * target�����ҵ�Ŀ��Ԫ��
 * low�����ҷ�Χ���½�λ��
 * high�����ҷ�Χ���Ͻ�λ��
 *
 * ����ֵ�������ҳɹ����򷵻�Ŀ��Ԫ�ص�λ�ã�������ʧ�ܣ��򷵻�-1*/
int fibSearch(int * A, int target, int low, int high) {
	high++;
	int fib_len = fibLength(high - low + 1);
	int * fib = createFibSequence(fib_len); //��������ǲ�����

	fib_len--;
	while (low < high)
	{
		while (high - low < fib[fib_len])
			fib_len--; //ͨ����ǰ˳����ң�ȷ������Fib[k] - 1�����
		int mid = low + fib[fib_len] - 1; //���ƽ�����з�
		if (target < A[mid]) //����ǰ���[low, mid)��������
			high = mid;
		else if (A[mid] < target) //�������[mid+1, low)
			low = mid + 1;
		else
			return mid; //��mid������
	}
	delete[] fib; //�ͷ�����ǲ�����ռ�õ��ڴ�
	return -1; //�����ڴ�
}

int main(){
    //int nums[10] = {5, 12, 23, 43, 66, 98, 100, 290, 300, 555};
    int nums[7] = {5, 12, 23, 43, 66, 98, 100};

	//for (int i = 0; i < 7; i++)
		//cout << binSearch2(nums, nums[i], 0, 6) << endl;
	int len = 40;
	int * fib = createFibSequence(len);
	delete[] fib;

	for (int i = 0; i < 7; i++)
		cout << fibSearch(nums, nums[i], 0, 6) << endl;

	system("pause");
    return 0;
}
