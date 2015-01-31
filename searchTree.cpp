// searchTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <stack>
using namespace std;

typedef struct Node 
{
	int key;
	struct Node * left;
	struct Node * right;
	struct Node * parent;
} Node ,* pNode;

void treeInsert(pNode & root , int key)
{
	pNode newNode =(pNode)malloc(sizeof(Node));
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;

	pNode tmpY = NULL;
	pNode tmpX = root;
	while(tmpX != NULL)
	{
		tmpY = tmpX;
		if(tmpX->key < key)
			tmpX = tmpX->right;
		else
			tmpX = tmpX->left;
	}
	newNode->parent = tmpY;

	if (tmpY == NULL)
		root = newNode;
	else
	{
		if(tmpY->key > key)
			tmpY->left = newNode;
		else
			tmpY->right = newNode;
	}

}
//void inOrderTree(pNode root)
//{
//	if(root != NULL)
//	{
//		inOrderTree(root->left);
//		//cout<<root->key<<" ";
//		printf("%d " , root->key);
//		inOrderTree(root->right);
//	}
//}
pNode treeMinimum(pNode tmpX)
{
	while(tmpX->left != NULL)
		tmpX = tmpX->left;
	return tmpX;
}
pNode treeSuccessor(pNode tmpX)
{
	if(tmpX->right != NULL)
		return treeMinimum(tmpX->right);
	
	pNode tmpY = tmpX->parent;
	while(tmpY != NULL && tmpX == tmpY->right)
	{
		tmpX = tmpY;
		tmpY = tmpX->parent;
	}
	return tmpY;
}
void treeDelete(pNode & root , pNode & tmpZ)
{
	pNode tmpY , tmpX;
	if(!tmpZ->left || !tmpZ->right)
		tmpY = tmpZ;
	else
		tmpY = treeSuccessor(tmpZ);
	
	if(tmpY->left != NULL)
		tmpX = tmpY->left;
	else
		tmpX = tmpY->right;
	if(tmpX != NULL)
		tmpX->parent = tmpY->parent;
	if(tmpY->parent == NULL)
		root = tmpX;
	else
	{
		if(tmpY == tmpY->parent->left)
			tmpY->parent->left = tmpX;
		else
			tmpY->parent->right = tmpX;
	}
	if(tmpY != tmpZ)
		tmpZ->key = tmpY->key;
}

void inOrderTree(pNode & root)
{
	pNode tmp = root;
	stack <pNode> s;
	while(tmp != NULL || !s.empty() )
	{
		if(tmp != NULL)
		{
			s.push(tmp);
			tmp = tmp->left;
		}
		else
		{
			tmp = s.top(); 
			printf("%d " , tmp->key);
			s.pop();
			tmp = tmp->right;
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	pNode root = NULL;
	treeInsert(root , 15);
	treeInsert(root , 6);
	treeInsert(root , 18);
	treeInsert(root , 3);
	treeInsert(root , 7);
	treeInsert(root , 17);
	treeInsert(root , 20);
	treeInsert(root , 2);
	treeInsert(root , 4);
	treeInsert(root , 13);
	treeInsert(root , 9);
	
	inOrderTree(root);
	printf("\n");
	treeDelete(root , root);
	inOrderTree(root);
	printf("\n");
	system("pause");
	return 0;
}

