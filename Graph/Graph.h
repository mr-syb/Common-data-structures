#pragma once
/*Kruskal��³˹�����㷨
T = �ռ���                                                           //T����С�������ı߼��ϣ�E�Ǵ�Ȩ����ͼ�ı߼���
while��T�����ı��� < n-1 && E�����ı��� > 0��
{
	��E��ѡ��һ��Ȩֵweight��С�ıߣ�w,v��;
	��E��ɾ���ߣ�w,v��;
	if(���ߣ�w,v������T�󲻻������·)
	{
		���ߣ�w,v������T;
	}
}
if(T�����ı��� < n-1)
	����ʧ�ܣ�
*/

/*Prim����ķ�㷨
Vmst = {u0},Emst = �ռ���                                            //VmstΪ��С�������Ķ��㼯��EmstΪ��С�������ı߼���u0Ϊ��С�������ĳ�������,
while(Vmust�����Ķ�����С��n && E��Ϊ��)                             //EΪ��Ȩ����ͼ�ı߼�
{
	��E��ѡ��һ��Ȩֵ��С�ıߣ�w,v��&& w����Vmust && v���� V - Vmust;//VΪ��Ȩ����ͼ�Ķ��㼯
	���ߣ�w,v����E��ɾ����
	��Vmst = Vmst U {w},Emst = Emst U {(w,v)};
}
if(Vmst�����Ķ�����С��n)
	����ʧ�ܣ�
*/

#include <cstdlib>
const int DefaultVetices = 30;

template<class T ,class E>
class Graph
{
public:
	const E MaxWeight = ......;
	Graph(int SE = DefaultVetices);
	~Graph();
	bool GraphEmpty()const {
		return NumEdgets == 0 ? true : false;
	}
	bool GraphFull() {
		if (NumVertices == MaxVertices || NumEdgets == MaxVertices * (MaxVertices - 1) / 2)
			return true;
		else return false;
	}
	int NumberOfVertices() { return NumVertices; }
	int MumberOfEdgets() { return NumEdgets; }
	virtual T GetValue(int i);
	virtual E GetWeight(int v1, int v2);
	virtual int GetFirstNeighbor(int v);
	virtual int GetNextNeighbor(int v, int w);
	virtual bool InsertVertice(const T& vertice);
	virtual bool InsertEdge(int v1, int v2, E weight);
	virtual bool RemoveVertice(int v);
	virtual bool RemoveEdge(int v1, int v2);
	void DFS(Graph<T, E>& G,const T& v, void(*Visit)(T));
	void BFS(Graph<T, E>& G, const T& v,void(*Visit)(T));
protected:
	int MaxVertices;
	int NumEdgets;
	int NumVertices;
	virtual int GetVerticePos(T vertice);
	void DFS(Graph<T, E>& G, int v, bool Visited[], void(*Visit)(T));
};

