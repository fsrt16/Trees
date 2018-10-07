// Program with insert and remove operation
#include <iostream>
#define TRUE 1
#define FALSE 0
const int m=8;
int a1[m];
using namespace std;
class btree
{

	private :

		struct btreenode
		{
			btreenode *leftchild ;
			int data ;
			btreenode *rightchild ;
		} *root,*rootm ;

	public :

		btree( ) ;
        void buildtree ( int num ) ;
		static void insert ( btreenode **sr, int ) ;
		static void search ( btreenode **sr, int num, btreenode **par,
					  btreenode **x, int *found ) ;
        void remove ( int num ) ;
		static void rem ( btreenode **sr, int ) ;
        void display( ) ;
        
		static void inorder ( btreenode *sr ) ;
		static void postorder(btreenode *sr);
		static void preoder(btreenode *sr);
        ~btree( ) ;
        static void del ( btreenode *sr ) ;
         void max ();
          void min ();
          void mr();
        static  void mirror(btreenode *root);
       int ht();
         static int hieght(btreenode *sr);
         void leaf();
         static  void lf(btreenode *sr);
         
        
} ;


btree :: btree( )
{
	root = NULL ;
	rootm=NULL;
}


int btree::ht(){
	hieght(root);
}
int btree::hieght(btreenode *sr){
	
	
	if(sr ==NULL){
	
		return 0;
	}
if(sr->rightchild==NULL && sr->leftchild==NULL){
	return 0;
}
int a=hieght(sr->leftchild);
int b=hieght(sr->rightchild);
if(b>a){
	
	return(b+1);
}
else
return(a+1);
	
	
	
}
void btree::mr(){
	mirror(root);
}
void btree::mirror(btreenode *root){
	btreenode *t;
	if(root!=NULL){
		t=root->leftchild;
		root->leftchild=root->rightchild;
		root->rightchild=t;
		mirror(root->leftchild);
		mirror(root->rightchild);
		
	}
}
void btree::max(){
	
		btreenode *t;
	t=root;
	while((t)->rightchild !=NULL){
		(t)=(t)->rightchild;
	}
	if((t)->leftchild!=NULL){
		(t)=(t)->leftchild;
		cout<<endl<<"THE MAXM ELEMENT IS  "<<(t)->data;
	}
	cout<<endl<<"THE MAXM ELEMENT IS  "<<(t)->data;
	
}

void btree::min(){

		btreenode *t;
	t=root;
		while((t)->leftchild !=NULL){
		(t)=(t)->leftchild;
	}
	if((t)->rightchild!=NULL){
		(t)=(t)->rightchild;
		cout<<endl<<"THE MAXM ELEMENT IS  "<<(t)->data;
	}
	cout<<endl<<"THE MAXM ELEMENT IS  "<<(t)->data;
	
}



void btree :: buildtree ( int num )
{
	insert ( &root, num ) ;
}

void btree :: insert ( btreenode **sr, int num )
{
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

void btree :: remove ( int num )
{
	rem ( &root, num ) ;
}


void btree :: rem ( btreenode **sr, int num )
{
	int found ;
	btreenode *parent, *x, *xsucc ;

	
	if ( *sr == NULL )
	{
		cout << "\nTree is empty" ;
		return ;
	}

	parent = x = NULL ;

	
	search ( sr, num, &parent, &x, &found ) ;

	
	if ( found == FALSE )
	{
		cout << "\nData to be deleted, not found" ;
		return ;
	}

	
	if ( x -> leftchild != NULL && x -> rightchild != NULL )
	{
		parent = x ;
		xsucc = x -> rightchild ;

		while ( xsucc -> leftchild != NULL )
		{
			parent = xsucc ;
			xsucc = xsucc -> leftchild ;
		}

		x -> data = xsucc -> data ;
		x = xsucc ;
	}

	
	if ( x -> leftchild == NULL && x -> rightchild == NULL )
	{
		if ( parent -> rightchild == x )
			parent -> rightchild = NULL ;
		else
			parent -> leftchild = NULL ;

		delete x ;
		return ;
	}

	
	if ( x -> leftchild == NULL && x -> rightchild != NULL )
	{
		if ( parent -> leftchild == x )
			parent -> leftchild = x -> rightchild ;
		else
			parent -> rightchild = x -> rightchild ;

		delete x ;
		return ;
	}

	
	if ( x -> leftchild != NULL && x -> rightchild == NULL )
	{
		if ( parent -> leftchild == x )
			parent -> leftchild = x -> leftchild ;
		else
			parent -> rightchild = x -> leftchild ;

		delete x ;
		return ;
	}
}


void btree :: search ( btreenode **sr, int num, btreenode **par,
		btreenode **x, int *found )
{
	btreenode *q ;

	q = *sr ;
	*found = FALSE ;
	*par = NULL ;

	while ( q != NULL )
	{
		
		if ( q -> data == num )
		{
			*found = TRUE ;
			*x = q ;
			return ;
		}

		*par = q ;

		if ( q -> data > num )
			q = q -> leftchild ;
		else
			q = q -> rightchild ;
	}
}


void btree :: display( )
{
	cout<<root->data<<endl;
	cout<<" INORDER : "<<endl;
	inorder ( root ) ;
	cout<<endl<<endl<<"postorder :  "<<endl;
	postorder(root);
	cout<<endl<<endl<<"pretorder :  "<<endl;
	preoder(root);
	
	
}

	
	

void btree :: inorder ( btreenode *sr )
{
	static int i=0;
	if ( sr != NULL )
	{
		inorder ( sr -> leftchild ) ;


		cout << sr -> data << "\t" ;
a1[i++]=sr->data;

		inorder ( sr -> rightchild ) ;
	}
}
void btree :: postorder(btreenode *sr)
{
	if ( sr != NULL )
	{
		postorder ( sr -> leftchild ) ;
        postorder ( sr -> rightchild ) ;

		cout << sr -> data << "\t" ;

		
	}
}
void btree :: preoder(btreenode *sr){
	if ( sr != NULL )
	{
		cout << sr -> data << "\t" ;
		preoder ( sr -> leftchild ) ;
        preoder ( sr -> rightchild ) ;

		

		
	}
}


btree :: ~btree( )
{
	del ( root ) ;
}

void btree :: del ( btreenode *sr )
{
	if ( sr != NULL )
	{
		del ( sr -> leftchild ) ;
		del ( sr -> rightchild ) ;
	}
	delete sr ;
}

int main( )
{
	btree bt ;
	int req, i = 0, num, a[ ] = { 100,80,150,60,90,170,160,175,190} ;

	while ( i <= 8 )
	{
		bt.buildtree ( a[i] ) ;
		i++ ;
	}

	cout << "Binary tree before deletion:\n" ;
	bt.display( ) ;
	bt.max();
cout<<endl;
bt.min();
cout<<endl<<endl<<endl;
bt.mr();
bt.display();
int k=bt.ht();
cout<<endl<<endl<<"THE HIEGHT OF THE GIVEN TREE IS : "<<endl<<k+1;

cout<<endl<<endl<<endl<<endl;
for(int j=0;j<8;j++){
	cout<<a1[j]<<endl;
}
	return 0;
}


