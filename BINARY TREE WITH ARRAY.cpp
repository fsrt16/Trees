#include<iostream>
using namespace std;
struct node{
 node *left,*right;
 char data;
};
class btree{
	private :
		struct node *root;
		char *arr;
		int *lc , *rc;
		
	public :
		btree(char *a, int *l , int *r , int size);
		void insert(int n);
		static node*buildtree(char *a,int *l, int *r,int n);
		void disp();
		static void inorder(node *sr);
		~btree();
		static void del(node*sr);
		
};
btree::btree(char*a,int *l, int *r, int size){
	root=NULL;
	arr=new char[size];
	lc=new int[size];
	rc=new int[size];
	for(int i=0;i<size;i++){
		*(arr+i)=*(a+i);
		*(lc+i)=*(l+i);
		*(rc+i)=*(r+i);
		
	}
}
// add nodes buildtree
void btree::insert(int n){
	root=buildtree(arr,lc,rc,n);
}
node *btree::buildtree(char *a,int *l, int *r,int n){
node *temp=NULL;
if(n!=-1){
	temp=new node;
	temp->left=buildtree(a,l,r,*(l+n));
	temp->data=*(a+n);
	temp->right=buildtree(a,l,r,*(r+n));
	
}	
return temp;
}
// calls inorder to traverse
void btree::disp(){
	inorder(root);
}
//displays data stored in the binary tree
void btree::inorder(node *sr){
	if(sr!=NULL){
		inorder(sr->left);
		cout<<sr->data<<endl;
		inorder(sr->right);
	}
}
btree::~btree(){
	delete arr;
	delete lc;
	delete rc;
	del(root);
}
//deletes nodes of the binary tree
void btree::del(node*sr){
	if(sr!=NULL){
		del(sr->left);
		del(sr->right);
	}
	delete sr;
}
int main(){
	cout<<endl;
	char a[]={ 'A','B','C','D','E','F','G','\0','\0','H',};
	int l[]={1,3,5,-1,9,-1,-1,-1,-1,-1};
	int r[]={2,4,6,-1,-1,-1,-1,-1,-1,-1};
	int sz=sizeof(a);
	btree bt(a,l,r,sz);
	bt.insert(0);
	
	cout<<"INORDER TRAVERSAL IS AS FOLLOWS :   ";
	bt.disp();
	return 0;
}







