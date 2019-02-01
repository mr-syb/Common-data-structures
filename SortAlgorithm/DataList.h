#ifndef DATELIST_H
#define DATELIST_H
#include "iostream"
#include "time.h"


using namespace std;

const int DefaultSize = 100;
template <typename T>
class Element {                             //���ݱ�Ԫ�ض���
public:

	Element<T>& operator =(Element<T> &x)	//Ԫ��x��ֵ����this
	{
		key = x.key;
		otherdata = x.otherdata;
		return *this;
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
	/*friend istream &operator >>(istream &in, Element<T> &e)
	{
		in >> e.key>>e.otherdata;
		if (!in)
		{
			e.key = 0;
			e.otherdata = 0;
		}
		return in;
	}*/
	friend ostream &operator <<(ostream &out, Element<T> &e)
	{
		out <<  e.otherdata;
		return out;
	}

public:
	T key;                                  //������
	T otherdata;							//�������ݳ�Ա
};


template <class T>
class DataList {				 //���ݱ����Ͷ���
public:
	DataList(int maxSz = DefaultSize) :maxSize(maxSz), currentSize(0)//���캯��
	{
		Vector = new Element<T>[maxSize];
	}

	DataList(T L[], int n)
	{
	
		maxSize = n;
		Vector = new Element<T>[maxSize * sizeof(Element<T>)];
		for (int i = 0; i < maxSize; i++)
		{
			Element<T> e;
			e.key = L[i];
			e.otherdata = L[i];
			Vector[i] = e;
		}
		MyPrint();
	}


	void Swap(Element<T> &x, Element<T> &y)//��������
	{
		Element<T> temp;
		temp = y;
		y = x;
		x = temp;
	}

	DataList<T>& operator =(DataList<typename T> other)
	{
		maxSize = other.maxSize;
		for(int i = 0;i<maxSize;i++)
		{
			Vector[i] = other.Vector[i];
		}
		return *this;
	}

	int Length() { return maxSize; }//ȡ����

	Element<T> & operator [](int i)//����[]���ţ�ʹ�����ȡ��i��Ԫ��
	/*�˴��������õ�ԭ���ǿ����÷���ֵ����ֵ*/
	{
		return Vector[i];
	}

	void randInitByInt()
	{
		srand(nullptr);
		int i;
		for (i = 0; i < this->Length(); i++)
		{
			Element<T> e;
			int data = rand() % 100;
			e.key = data;
			e.otherdata = data;
			Vector[i] = e;
		}
		maxSize = this->Length();
		MyPrint();
	}

	void MyPrint(bool iEnd = false)
	{
		return;
		if (!iEnd)
		{
			cout << "��ʼ����Ϊ��";
		}
		else {
			cout << "���������Ϊ��";
		}
		
		for (int i = 0; i < Length(); i++)
		{
			cout << Vector[i] << ' ';
		}
		cout << endl;
	}

	int Partition(const int low, const int hight);//���ٻ�������

private:
	Element<T> * Vector;						//�洢����Ԫ�ص�����
	int maxSize;								//���������Ԫ�ظ���
	int currentSize;							//��ǰԪ�ظ���
};

template <class T>
class Sort
{
public:
	friend class DataList<typename T>;
#pragma region ð������
	void BubbleSort1(DataList<T> &V, int n);
	void BubbleSort2(DataList<T> &V, int n);
#pragma endregion
	
#pragma region ��������
	void InsertSort(DataList<T> &L, const int left, const int right);
	void BinaryInsertSort(DataList<T> &L, const int left, const int right);
#pragma endregion
};



#endif // !DATEDATELIST_H

