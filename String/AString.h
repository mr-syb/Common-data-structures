#pragma warning(disable:4996)
#pragma once
#include <cstring>
#include <cstdlib>
#define DefaultSize 128
class Astring
{
public:
	Astring(int Sz = DefaultSize);
	Astring(const char* other);
	Astring(const Astring& other);
	~Astring() { delete[] ch; };
	int Length()const { return CurLength; }
	Astring& operator()(int pos, int len);//���ش�pos��ʼ����len�����ȵ��Ӵ�
	int operator == (Astring & other)const { return strcmp(ch, other.ch)==0; }
	int operator !=(Astring& other)const { return strcmp(ch, other.ch)!= 0; }
	Astring & operator=(Astring& other);
	int Find(Astring& other,int k)const;//����other��*this��ĳ���Ӵ�ƥ�䣬�򷵻ص�һ�γ��ָ��Ӵ���λ�ã����򷵻�-1//���ص�ģʽƥ��,(�����ⷨ)
	int KMPFind(Astring& other);
	void GetNext(Astring& other, int* Next)const;
	char& operator[](int i)const;

private:
	char* ch;
	int CurLength;
	int MaxSize;
};

