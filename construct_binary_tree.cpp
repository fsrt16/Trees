#include<iostream>
using namespace std;
struct node
{
	int data;
	node *left,*right;
}*root=NULL,*t=NULL;
int index=0;
int search(int in[],int key,int first,int last)
{
	int i;
	for(i=first;i<=last;i++)
	{
		if(in[i]==key)
		return i;
	}
}
node *create(int in[],int pre[],int first,int last)
{
	if(first>last)
	return NULL;
	else
	node *t=new node;
	t->data=pre[index++];
	int j=search(in,t->data,first,last);
	t->left=create(in,pre,first,j-1);
	t->right=create(in,pre,j+1,last);
	return t;
}
int main()
{
	int n,i;
	int in[n],pre[n];
	int first=0,last=n-1;
	cout<<"enter the total no. of nodes ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"give the inorder walk ";
		cin>>in[n];
	}
	for(i=0;i<n;i++)
	{
		cout<<"give the preorder walk ";
		cin>>pre[n];
	}
	create(in,pre,first,last);
	return 0;
}
