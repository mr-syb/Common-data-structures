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

/*Dijkstra�Ͻ�˹�����㷨<https://www.cnblogs.com/biyeymyhjob/archive/2012/07/31/2615833.html>
�ᷨ������һ�������ȨͼG��Դ��V0�������ϵ�Ȩֵ���Ǹ���Ҫ���ҳ���v��D���������������·��
1.��ʼ����	S = {V0};								//S�������� ���·�����յ�
			Dist[j] = Edge[0][j],j = 0,1,2...,n-1;	//Dist[j]��ʾ��ǰ�Ѿ��ҳ����Ĵ�Դ��V0��Vj�����·����Ȩֵ��nΪ��Ȩ����ͼ����ĸ���
2.������·���ĳ��ȣ�
			Dist[k] = min{Dist[i]},i����V-S			//V��ʾ��Ȩ����ͼ���ж��ļ���
			S = S U {K};
3.�޸ģ�	Dist[i] = min{Dist[k] + Edge[k][i]},����ÿһ��i����V - S;
4.�жϣ�    ��S = V �����㷨����������ת2��
*/

/*��������<https://blog.csdn.net/lisonglisonglisong/article/details/45543451>
���壺����������һ�������޻�ͼ���ж�����������С�
stack S;
������ж��㣻
	if(����i�����Ϊ0)
		�����i��ջS;
count = 0;
while(��ջS����ʱ)
{
	��ջS�˳�һ������v;
	���v;
	count++;
	��������v�������ڽӶ���w,������ȼ�һ��ȼ���0�Ķ���w��ջS;
}
if(����������count < ���綥�����n)
	���������д������򻷣�
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
	void Dijkstra(Graph<T, E>& G, T v, E dist[], int path[]);
protected:
	int MaxVertices;
	int NumEdgets;
	int NumVertices;
	virtual int GetVerticePos(T vertice);
	void DFS(Graph<T, E>& G, int v, bool Visited[], void(*Visit)(T));
};

