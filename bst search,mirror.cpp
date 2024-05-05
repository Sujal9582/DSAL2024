#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
}*root=NULL;

//insert node in bst

void insert(int data){
    struct node *nn = new node;
    nn->data = data;
    nn->left=nn->right=NULL;
    if(root==NULL){
        root = nn;
    }
    else{
        struct node* temp=root;
        while(1){
            if(data==temp->data){
                cout<<"\nDuplicate data found";
                delete nn;
                return;
            }
            else if(data<temp->data){
                if(temp->left==NULL){
                    temp->left = nn;
                    return;
                }
                temp = temp->left;
            }
            else{
             if(temp->right==NULL){
                 temp->right = nn;
                 return;
             }
             temp = temp->right;
            }
        }
    }
}

//search the data in tree
void search(int data){
    if(root==NULL){
        cout<<"\nEmpty tree...";
        return;
    }
    struct node *temp=root;
    while(temp!=NULL){
        if(temp->data == data){
            cout<<"\nData Found...";
            return;
        }
        else if(data<temp->data){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    cout<<"\nData not found";
}

//mirror of the tree
void mirror(struct node* r){
    if(r==NULL)
        return;
    
    struct node* temp=r->left;
    r->left = r->right;
    r->right = temp;
    mirror(r->left);
    mirror(r->right);
    
}

//display tree
void display(struct node* r){
    if(r==NULL)
        return;
    
    display(r->left);
    cout<<"->"<<r->data;
    display(r->right);
}


//driver code
int main(){
int data;
int choice;

while(true){
    cout<<"\n1. Insert Node";
    cout<<"\n2. Display Tree";
    cout<<"\n3. Search";
    //cout<<"\n4. Height Of Tree";
    cout<<"\n4. Mirror of Tree";
    //cout<<"\n6. Minimum Node";
    cout<<"\n. Exit";
    cout<<"\n=>";
    cin>>choice;
    
    switch(choice){
        case 1:
            cout<<"\nEnter data : ";
            cin>>data;
            insert(data);
            break;
        case 2:
            display(root);
            cout<<endl;
            break;
        case 3:
            cout<<"Enter key to search : ";
            cin>>data;
            search(data);
            break;
        // case 4:
        //     cout<<"\nHeight of tree : "<<height(root)<<endl;
        //     break;
        case 4:
            mirror(root);
            cout<<"\nMirror Tree : ";
            display(root);
            break;
        // case 6:
        //     cout<<"Minimum data : "<<min(root)<<endl;
        //     break;
        case 5:
            return 0;
            break;
        default:
            cout<<"\nWrong choice\n";
    }
}

return 0;
}