#pragma once
template <class T>
class LinearList 
{
public:
	/*LinearList();
	~LinearList();*/
	/** ������*/
	virtual int Size()const { return 0; };
	/** ����*/
	virtual int Length() const { return 0; };
	/** �ڱ�����������ֵX*/
	virtual int Search(const T& x)const { return 0; };
	/** �ڱ��ж�λ��i��Ԫ�ص�λ��*/
	virtual int Locate(int i) const { return 0; };
	/** ȡ��i�������ֵ*/
	virtual bool GetData(int i, T& x) { return 0; };
	/** �޸ĵ�i�������ֵ*/
	virtual void SetData(int i, const T& x){};
	/** �ڵ�i����������x*/
	virtual bool Insert(int i, const T& x) { return 0; };
	/** ɾ����i������ͨ��x����*/
	virtual bool Remove(int i, T&x) { return 0; };
	virtual bool IsEmpty() { return 0; };
	virtual bool IsFull() { return 0; };
	virtual void Sort(){};
	/** ����*/
	virtual void Input(){};
	/** ���*/
	virtual void Output() { std::cout << "LinearList->Output()"; };
	/** ���ƣ����������������ͱ��뱨�����ܴ����������ʵ�����������Ͳ��������������͡������������ͻ���ʽת�������͡������������������ָ������á�*/
	virtual LinearList<T>& operator=(LinearList<T> &L) { return *this; };
};