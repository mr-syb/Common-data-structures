#pragma once
template <class T>
class LinearList 
{
public:
	LinearList();
	~LinearList();
	/** ������*/
	virtual int Size()const = 0;
	/** ����*/
	virtual int Length() const = 0;
	/** �ڱ�����������ֵX*/
	virtual int Search(T& x)const = 0;
	/** �ڱ��ж�λ��i��Ԫ�ص�λ��*/
	virtual int Locate(int i) const = 0;
	/** ȡ��i�������ֵ*/
	virtual bool GetData(int i, T& x)const = 0;
	/** �޸ĵ�i�������ֵ*/
	virtual void SetData(int i,T& x) = 0;
	/** �ڵ�i����������x*/
	virtual bool Insert(int i, T&x) = 0;
	/** ɾ����i������ͨ��x����*/
	virtual bool Remove(int i, T&x) = 0;
	virtual bool IsEmpty()const = 0;
	virtual bool IsFull()const = 0;
	virtual void Sort() = 0;
	/** ����*/
	virtual void Input() = 0;
	/** ���*/
	virtual void Output() = 0;
	/** ���ƣ����������������ͱ��뱨�����ܴ����������ʵ�����������Ͳ��������������͡������������ͻ���ʽת�������͡������������������ָ������á�*/
	virtual LinearList<T>& operator=(LinearList<T> &L) = 0;
};