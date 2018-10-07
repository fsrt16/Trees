#include<iostream>
#include<cstring>
#include<string>
#define TRUE 1
#define FALSE 0
const int m=10;
using namespace std;
bool isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return true;
    return false;
}
 struct et
           {
            char value;
            et *left;
        	et *right;
          }*root;

		et* a[m];
int t=-1;

void push(et* n){
	if(t==m-1){
		cout<<"stack fll"<<endl;
		return;
	}
	t++;
	a[t]=n;
	
}
et* pop(){
	if(t==-1){
		cout<<"EMPTY   "<<endl;
		return 0;
	}
	et* d=a[t];
	t--;
	return d;
}

et*  insert (  char num[] )
{ 

	 et* temp;
	et* t2;
	et* t;
	et* t1;
    for(int i=0;i<strlen(num);i++){
    	
	
	if (!isOperator(num[i]))
        {
            temp = new et;
    temp->left = temp->right = NULL;
    temp->value = num[i];
            push(temp);
        }
        else 
        {
             temp = new et;
    temp->left = temp->right = NULL;
    temp->value =num[i];
    root=temp;
            t1= pop(); 
                 
            t2 = pop();
            temp->right = t1;
            temp->left = t2;
            push(temp);
        }}
        
        	temp=pop();
        	return temp;
		
        
}


void  preorder ( et *sr )
{
	if ( sr != NULL )
	{
		cout << sr -> value << "\t" ;
		preorder ( sr -> left) ;

		preorder ( sr -> right ) ;
	}
}

int main()
{
	
    char postfix[] = "ab+ef/g/+";

   et* r=insert(postfix);
	preorder(r);
	return 0;
	
}

