#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;

}*root = NULL;

void insert(int data)
{
    struct node* nn = new node;
    nn->data=data;
    nn->right=nn->left=NULL;

    if(root==NULL)
    {
        root=nn;
    }

    else
    {
        struct node* temp=root;
        while(1)
        if(data==temp->data)
        {
            cout<<"\n duplicate data found";
            delete nn;
            return;
        }
        else if(data<temp->data)

        {
            if(temp->left==NULL)
            {
                temp->left==nn;
                return;
            }
            temp = temp ->left;
           
        }
        else
        {
            if(data>temp->data)
            {
                if(temp->right==NULL)
                {
                    temp->right=nn;
                    return;
                }
                temp=temp->right;
            }
        }
    }
}

//height of tree

int height(struct node *r)
{
    if(r==NULL)
    {
        return 0;

    }
    int lh=height(r->left);
    int rh = height(r->right);
    if(lh>rh)
    {
         return lh=lh+1;
    }
    else
    {
        return rh=rh+1;
    }
}

//min node in tree

int min(struct node *r)
{
    if(r == NULL)
    {
        cout<<"tree is empty";
        return -1;
           
    }
    
    //traverse left to find min data
    while(r->left!=NULL)
    {
        r=r->left;
    }
    return r->data;

}

//display function

void display(struct node *r)
{
    if(r==NULL)
    {
        return;
    }
    display (r->left);
    cout<<"->"<<r->data;
    display(r->right);
    


}


int main()
{
    int data;
    int choice;

    while(true)
    {
        cout<<"\n1.insert node";
        cout<<"\n2.display tree";
        cout<<"\n3.height of tree";
        cout<<"\n4.minimum nodee";
        cout<<"\n5.exit";
        cout<<"\n=>";
        cin>>choice;

        switch (choice)
        {
            case 1:
            cout<<"enter data";
            cin>>data;
            insert(data);
            break;

            case 2:
            display(root);
            cout<<endl;
            break;
            
            case 3:
            cout<<"height of the tree is :"<<height(root)<<endl;
            break;

            case 4:
            cout<< "minimum data"<<min(root)<<endl;
            break;

            case 5:
            return 0;
            break;

            default:
            cout<<"\n wrong choice: \n";



            
        }


    }
    return 0;
}