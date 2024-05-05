#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

struct node
{
    char op;
    node *left,*right;
};
void postorder(node *top)
{
    stack <node *> s1,s2;
    node *t=top;
    s1.push(t);
    while(!s1.empty())
    {
        t=s1.top();
        s1.pop();
        s2.push(t);
        if(t->left!=NULL)
        {
            s1.push(t->left);
        }
        if(t->right!=NULL)
        {
            s1.push(t->right);
        }
    }
        while(!s2.empty())
        {
            t=s2.top();
            s2.pop();
            cout<<t->op;
        }
    
}    
    
int main() {
    char prefix[20];
    int l,i;
    node *t1,*t2;
    stack <node *> s;
    cout<<"\nenter the correct prefix expression:";
    cin>>prefix;
    l=strlen(prefix);
    node *nn,*root;
    
    for(i=l-1;i>=0;i--)
    {
        nn=new node;
        nn->left=NULL;
        nn->right=NULL;
        if(prefix[i]=='+'||prefix[i]=='-'||prefix[i]=='*'||prefix[i]=='/')
         {
            t1=s.top();
            s.pop();
            t2=s.top();
            s.pop();
            nn->op=prefix[i];
            nn->left=t1;
            nn->right=t2;
            s.push(nn);
            
        }
        else
        {
             nn->op=prefix[i];
             s.push(nn);
        }
    }
    root=s.top();
    postorder(root);
    return 0;
}


