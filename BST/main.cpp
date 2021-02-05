#include<iostream>
using namespace std;

struct node
{
    int key;
    node *left, *right;
};


node *newNode(int item)
{
    struct node *temp = new node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}


void preorder(node *root)
{
    if(!root)
        return;

    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
}


void postorder(node *root)
{
    if(!root)
        return;

    preorder(root->left);
    preorder(root->right);

    cout<<root->key<<" ";
}


node* insert(node* node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);


    return node;
}


node * minValueNode(node* node)
{

    while (node->left != NULL)
        node = node->left;

    return node;
}


node* deleteNode(node* root, int key)
{
    if (root == NULL) return root;


    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            delete(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            delete(root);
            return temp;
        }

        node* temp = minValueNode(root->right);

        root->key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
bool find(node *root,int data)
{
    if(!root)
        return(false);

    if(root->key==data)
        return(true);

    return(find(root->left,data)||find(root->right,data));
}

int main()
{
    int i,j,n,k,l,m;
    cout<<"How many integers you want: ";
    cin>>n;
    node *root = NULL;

    cout<<"Enter the integers: \n";
    for(i=0;i<n;i++)
    {
        cin>>k;
        root = insert(root, k);
    }
    while(1)
    {
        cout<<"\nChoose\n1 for inorder traverse\n2 for preorder traverse\n3 for postorder traverse\n4 for inserting new item\n5 for deleteing an item\n6 for exit the program";
        cin>>n;
        if(n==1)
        {
            inorder(root);
            cout<<endl;
        }
        else if(n==2)
        {
            preorder(root);
            cout<<endl;
        }
        else if(n==3)
        {
            postorder(root);
            cout<<endl;
        }
        else if(n==4)
        {
            cout<<"Enter the item for insert: ";
            cin>>k;
            if(find(root,k))
                cout<<"This item already exists.";
            else
            {
                root = insert(root, k);
                cout<<"The item is inserted.";
            }
        }
        else if(n==5)
        {
            cout<<"Enter the item for delete: ";
            cin>>k;
            if(!find(root,k))
                cout<<"This item not found.";
            else
            {

                root = deleteNode(root, k);
                cout<<"This item is deleted.";
            }
        }
        else
            break;
    }
}