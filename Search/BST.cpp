#include "BST.h"

template<class T>
bool BST<T>::Remove(T x , BSTNode<T>* &ptr)
{/**˼·����ɾ���Ľڵ��Ҷ�ӽڵ㣬�����������еĺ����ڵ���棬
 �ݹ�ɾ���滻�ڵ㡣ֱ����ɾ���Ľڵ�ΪҶ�ӽڵ㣬����ɾ����*/
	BSTNode<T>* temp;
	if (ptr != NULL)
	{
		if (x < ptr->Data) Remove(x, ptr->left);//��������ɾ��
		else if (x > ptr->Data) Remove(x, ptr->right);//��������ɾ��
		else if (ptr->left != NULL&& ptr->right != NULL)//�ҵ���Ҫɾ���Ľ�㣬��ӵ�����Һ���
		{
			temp = ptr->right;
			while (temp->left != NULL)//�ҵ����������еĺ����ڵ��滻��ɾ���Ľڵ�
				temp = temp->left;
			ptr->Data = temp->Data;
			Remove(ptr->Data, ptr->right);//���������еݹ�ɾ���滻�ڵ�
		}
		else//�ҵ���Ҫɾ���Ľڵ㣬��ΪҶ�ӽڵ���ߵ�һ�ӽڵ�
		{
			temp = ptr;
			if (ptr->left == NULL)//����������
				ptr = ptr->right;
			else//����������
				ptr = ptr->left;
			delete temp;//����ɾ�����սڵ�
			return true;
		}
	}
	return false;
}

template<class T>
BSTNode<T>* BST<T>::Min(BSTNode<T>* subTree)
{
	if (subTree->left == NULL)
		return subTree;
	Min(subTree->left);
}

template<class T>
BSTNode<T>* BST<T>::BinarySearch(T key, BSTNode<T>* ptr)
{
	if (ptr == NULL)
		return NULL;
	if (key > ptr->Data)
	{
		BinarySearch(ptr->right);
	}
	else if(key < ptr->Data)
	{
		BinarySearch(ptr->left);
	}
	else
	{
		return ptr;
	}
}

template<class T>
bool BST<T>::Insert(T e, BSTNode<T>* &x)
{
	if (x == NULL)
	{
		x = new T(e);
		return true;
	}
	else if(e < x->Data)
	{
		Insert(e, x->left);
	}
	else if(e > x->Data)
	{
		Insert(e, x->right);
	}
	else
	{
		return false;
	}

}


template<class T>
void BST<T>::MakeEmpty(BSTNode<T>& node)
{
	if (node.left != NULL&& node.right != NULL)
	{
		if (node.left != NULL)
		{
			MakeEmpty(node.left);
		}
		else if (node.right != NULL)
		{
			MakeEmpty(node.right);
		}
	}
	else {
		delete node;
	}
}


