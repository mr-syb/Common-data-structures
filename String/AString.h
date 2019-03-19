#pragma once
#include <cstring>
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
	int operator == (Astring & other)const { return strcmp(ch, other.c_str())==0; }
	char* c_str() const{ return ch; }
	int operator !=(Astring& other)const { return strcmp(ch, other.c_str())!= 0; }
	Astring & operator=(Astring& other);
	int Find(Astring& other)const;//����other��*this��ĳ���Ӵ�ƥ�䣬�򷵻ص�һ�γ��ָ��Ӵ���λ�ã����򷵻�-1
	char& operator[](int i)const;

private:
	char* ch;
	int CurLength;
	int MaxSize;
};

