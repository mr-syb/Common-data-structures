/*ð����������ַ���
  �㷨˼�룺�Ӻ���ǰ�����Ƚϣ���Ϊ����V[i-1]>V[i]�򽻻�����
            ÿ�˶������������С��Ԫ�����е�����λ��
�ռ临�Ӷȣ�O��1��
ʱ�临�Ӷȣ���ã��Ѿ��ź���ΪO��n��
			����ȫ����ΪO��n^2��
�㷨�ȶ�������ȶ�
*/

#include "dataList.h"

template <class T>
void BubbleSort1(dataList<T> &V, int n) {
	//��������n��Ԫ�ؽ���ð������ִ��n-1�ˣ���i�˶Ե�V[n-1]��V[i]����
	for(int i = 1; i < n; i++)
		for(int j = n - 1; j >= i;j--)
			if (V[j - 1] > V[j])
			{
				T temp = V[j - 1];
				V[j - 1] = V[j];
				V[j] = temp;
			}
};

template <class T>
void BubbleSort2(dataList<T> &V, int n) {
	//���ý������exchange���������ð��û�з�����������˵��������ɣ�ֹͣ����
	bool exchange;
	int i, j;
	for (i = 1; i < n; i++) {
		exchange = false;
		for (j = n - 1; j >= i; j--)
			if (V[j - 1] > V[j])
			{
				T temp = V[j - 1];
				V[j - 1] = V[j];
				V[j] = temp;
				exchange = true;
			}
		if (exchange == false)
			return;
	}
};

