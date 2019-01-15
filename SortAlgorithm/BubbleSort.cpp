/*ð����������ַ���
  �㷨˼�룺�Ӻ���ǰ�����Ƚϣ���Ϊ����V[i-1]>V[i]�򽻻�����
            ÿ�˶������������С��Ԫ�����е�����λ��
�ռ临�Ӷȣ�O��1��
ʱ�临�Ӷȣ���ã��Ѿ��ź���ΪO��n��
			����ȫ����ΪO��n^2��
�㷨�ȶ�������ȶ�
*/

#include "DataList.h"

template <class T>
void Sort<T>::BubbleSort1(DataList<T> &V, int n) {
	//��������n��Ԫ�ؽ���ð������ִ��n-1�ˣ���i�˶Ե�V[n-1]��V[i]����
#pragma region timing
	clock_t startTime, endTime;
	startTime = clock();//��ʼ��ʱ
#pragma endregion

	for (int i = 1; i < n; i++) {
		for (int j = n - 1; j >= i; j--)
			if (V[j - 1] > V[j])
			{
				Element<T> temp = V[j - 1];
				V[j - 1] = V[j];
				V[j] = temp;
			}
	}
		
#pragma region print
	V.MyPrint(true);
	endTime = clock();//������ʱ
	cout << "BubbleSort1 run time is:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << 's' << endl;
#pragma endregion
}
template <class T>
void Sort<T>::BubbleSort2(DataList<T> &V, int n) {
#pragma region timing
	clock_t startTime, endTime;
	startTime = clock();//��ʼ��ʱ
#pragma endregion
	//���ý������exchange���������ð��û�з�����������˵��������ɣ�ֹͣ����
	bool exchange;
	int i, j;
	
	for (i = 1; i < n; i++) {
		exchange = false;
		for (j = n - 1; j >= i; j--)
		{
			if (V[j - 1] > V[j])
			{
				Element<T> temp = V[j - 1];
				V[j - 1] = V[j];
				V[j] = temp;
				exchange = true;
			}
		}
		if (exchange == false)
		{
#pragma region Timing
			V.MyPrint(true);
			endTime = clock();//������ʱ
			cout << "BubbleSort2 run time is:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << 's' << endl;
#pragma endregion
			return;
		}
	}
#pragma region print
	V.MyPrint(true);
	endTime = clock();//������ʱ
	cout << "BubbleSort2 run time is:" << (double)(endTime - startTime) / CLOCKS_PER_SEC << 's' << endl;
#pragma endregion

};

