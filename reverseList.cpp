/*************************************************************************
    > File Name: reverseList.cpp
    > Author: Morain
    > Mail: morainchen135@gmail.com
    > Created Time: 2014年08月03日 星期日 19时20分57秒
 ************************************************************************/

#include <iostream>
//#include <list>
using namespace std;

/*int main(int argc, char const *argv[])
{
	list <int> l;
	int i ;
	for(i = 1 ; i <= 100 ; i++)
	{
		l.push_back(i);
	}
	list <int>::iterator itor;
	for(itor = l.begin() ; itor != l.end()  ; itor++)
	{
		cout<<*itor<<" ";
	}
	cout<<endl;
	return 0;
}*/
typedef struct Node
{
	struct Node *next;
	int data;
}Node;
void listAdd(Node * head, int a)
{
	Node * p;
	for( p =head ; p->next !=NULL ; p = p->next);
	Node * newNode = new Node;
	newNode->data = a;
	newNode->next = NULL;
	p->next = newNode;

}
void reverseList(Node * head)
{
	Node * pPre , * pCur , * pNext;
	pPre = head->next;
	pCur = pPre->next;
	pNext = NULL;
	while(pCur != NULL)
	{
		pNext = pCur->next;
		pCur->next = pPre;
		pPre = pCur;
		pCur = pNext;
	}
	head->next->next = NULL;
	head->next = pPre;
}
int main(int argc, char const *argv[])
{
	
	Node * head = new Node;
	head->next = NULL;
	int i ;
	for( i = 1 ; i <= 10 ; i++ )
	{
		listAdd(head , i);
	}
	Node * p ;
	for(p = head->next ; p != NULL ; p = p->next)
	{
		cout<<p->data<<" ";
	}
	cout<<endl;
	reverseList(head);
	for(p = head->next ; p != NULL ; p = p->next)
	{
		cout<<p->data<<" ";
	}
	cout<<endl;
	return 0;
}
