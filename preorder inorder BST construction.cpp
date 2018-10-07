#include <iostream>
#include<cstring>
#include<string>
#define TRUE 1
#define FALSE 0
using namespace std;
struct btreenode
		{
			btreenode *leftchild ;
			int data ;
			btreenode *rightchild ;
		} *root ;
		

void insert ( btreenode **sr, int num ) {
	if ( *sr == NULL )
	{
		*sr = new btreenode ;

		( *sr ) -> leftchild = NULL ;
		( *sr ) -> data = num ;




		( *sr ) -> rightchild = NULL ;
	}
	else  
	{
	
		if ( num < ( *sr ) -> data )
			insert ( & ( ( *sr ) -> leftchild ), num ) ;
		else
			
			insert ( & ( ( *sr ) -> rightchild ), num ) ;
	}
}
void  buildtree ( int num )
{
	insert ( &root, num ) ;
}
int main(){
	char a[20],b[20];
	cout<<"ENTER A PREORDER "<<endl;
	cin.getline(a,20);
	cout<<a<<endl;
	return 0;
}

