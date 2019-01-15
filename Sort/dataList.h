#ifndef DATELIST_H
#define DATELIST_H
#include <iostream>

const int DefaultSize = 100;
template <class T>
class Element {                                 //���ݱ�Ԫ�ض���
public:
	T key;                                      //������
	T otherdata;                            //�������ݳ�Ա
	Element<T> & operator =(Element<T> &x)//Ԫ��x��ֵ����this
	{
		key = x.key;
		other = x.other;
		return this;
	}
	bool operator == (Element<T> &x)           //�ж�this��x�Ƿ����
	{
		return key == x.key;
	}
	bool operator <=(Element<T> &x)				//�ж�this�Ƿ�С�ڵ���x
	{
		return key <= x.key;
	}
	bool operator > (Element<T> &x)				//�ж�this�Ƿ����x
	{
		return key > x.key;
	}
	bool operator < (Element<T> &x)				//�ж�this�Ƿ�С��x
	{
		return key < x.key;
	}
};


template <class T>
class dataList {				 //���ݱ����Ͷ���
public:
	dataList(int maxSz = DefaultSize) :maxSize(maxSz), currentSize(0)//���캯��
	{
		Vector = new Element<T>[maxSize];
	}

	void Swap(Element<T> &x, Element<T> &y)//��������
	{
		Element<T> temp;
		temp = y;
		y = x;
		x = temp;
	}

	int Length() { return maxSize; }//ȡ����

	Element<T> & operator [](int i)//����[]���ţ�ʹ�����ȡ��i��Ԫ��
	/*�˴��������õ�ԭ���ǿ����÷���ֵ����ֵ*/
	{
		return Vector[i];
	}

	/*friend istream &operator >>(istream &in, dataList <T> &L)
	{
		in >> L.Vector++;
		if (!in)
			L = dataList();
		return in;
	}


	friend ostream &operator <<(ostream &out, const dataList<T> &L)
	{
		if(L.Vector++ != NULL)
		out<<L.Vector++;
		return out;
	}*/


	int Partition(const int low, const int hight);//���ٻ�������

private:
	Element<T> * Vector;						//�洢����Ԫ�ص�����
	int maxSize;								//���������Ԫ�ظ���
	int currentSize;							//��ǰԪ�ظ���
};
#endif // !DATEDATELIST_H
