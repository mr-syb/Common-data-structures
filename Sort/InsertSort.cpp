/*ֱ�Ӳ�������
�㷨˼�룺ÿ�ν�һ������������а��չؼ��ִ�С���뵽ǰ���Ѿ��ź���������С�
�ռ临�Ӷȣ�O��1��
ʱ�临�Ӷȣ���ã��Ѿ��ź���ΪO��n��
			����ȫ����ΪO��n^2��
			ƽ��O��n^2��
�㷨�ȶ�������ȶ�
�����ԣ�������˳��洢����ʽ�洢
============================================================================
�������򶼽��������β���1>�����ң�˳�����O��n�����������������в��ҵ�Ӧ�ò����λ��
						2>�����룬˳��洢�����Ա�Ĳ��룩��������Ԫ���ڳ��ռ䣬�����ڴ�����Ԫ�ص�Ԫ�����Ų
============================================================================
�۰�������򣨽�ֱ�Ӳ����㷨�Ĳ��ҹ��̸Ľ���ʹ���۰����O��logn����
�㷨˼�룺ÿ�ν�һ������������а��չؼ��ִ�С���뵽ǰ���Ѿ��ź���������С�
�ռ临�Ӷȣ�O��1��
ʱ�临�Ӷȣ����Ҳ�����O��n��-->O(logn),���벿��û�иı���ΪO��n^2��,,����ƽ����ΪO��n^2��
�㷨�ȶ�������ȶ�
*/
#include "dataList.h"

template <class T>
void InsertSort(dataList<T> &L,const int left, const int right) {
	//���ν�Ԫ��L.Vector[left]�������������β��뵽�����L.Vector[left],...,L.Vector[i-1]
	//�У�ʹ��L.Vector[left]...Vector[i]����
	Element<T> temp; int i, j;
	for (i = left + 1; i < = right; i++){
		if (L[i] < L[i - 1]){
			temp = L[i];
			j = i - 1;
			do {
				L[j + 1] = L[j];
				j--;
			} while (j > left && temp < L[j])
			L[j + 1] = temp;
		}
	}
};

template <class T>
viod BinaryInsertSort(dataList<T> &L, const int left, const int right){
	Element<T> temp;
	int i, j, low, mid, hight;
	for (i = left + 1; i <= right; i++){
		temp = L[i];
		low = left;
		hight = i - 1;
		while (low <= hight) {
			mid = (hight + low) / 2;
			if (temp < L[mid])
				hight = mid - 1;
			else
				low = mid + 1;
		}
		for (j = i - 1; j >= low; j--)
			L[j + 1] = L[j];
		L[low] = temp;
	}
};