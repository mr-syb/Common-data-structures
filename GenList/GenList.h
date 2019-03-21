#pragma once
#include <iostream>
#include <cstdlib>
#include <assert.h>
template<class T>
struct GenListNode {
public:
	GenListNode()
	{
		Type = 0; 
		next = NULL; 
		Info->Ref = 0;
	}
	GenListNode(GenListNode<T>& other)
	{
		Type = other.Type;
		Info = other.Info;
		next = other.next;
	}

private:
	int Type;//0/1/2
	union 
	{
		int Ref;
		T Value;
		GenListNode<T>* child;
	}Info;
	GenListNode<T>* next;
};

template<class T>
struct Items {//����ֵ����ṹ����
	int Type;//0/1/2
	union
	{
		int Ref;
		T Value;
		GenListNode<T>* child;
	}Info;
	Items() //constructer
	{ 
		Type = 0;
		Info->Ref = 0; 
	}
	Items(Items<T>& other)//copy constructer
	{
		Type = other.Type;
		Info = other.Info;
	}
};

template<class T>
class GenList {
public:
	GenList();
	~GenList();
	bool Head(Items<T>& x);
	bool Tail(GenList<T>& x);
	GenListNode<T>* First();
	GenListNode<T>* Next(GenListNode<T>* Elem);
	void Copy(const GenList<T>& R);//�ݹ鿽���ⲿ����
	int Length();
	int Depth();
	friend std::istream& operator>>(std::istream& in, GenList<T>& L);

private:
	GenListNode<T>* first;
	GenListNode<T>* Copy(GenListNode<T>* L);//�ݹ鿽���ڲ�����,ǰ�ᣬ�ǹ�����ݹ��
	int Length(GenListNode<T>* L);
	int Depth(GenListNode<T>* L);
	bool Equal(GenListNode<T>* s, GenListNode<T>* t);
	void Remove(GenListNode<T>* ls);//�ͷ���LΪ��ͷ�Ĺ�����ٶ�ls��ΪNULL
	void CreateList(std::istream& in, GenListNode<T> * &ls);
};

