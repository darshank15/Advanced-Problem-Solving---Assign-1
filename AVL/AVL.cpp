#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

//**********************************************************************
// Node Structure
//**********************************************************************
struct node{

    int data;
    struct node *left;
    struct node *right;
    int bf;
    int height;
    int tcount;
};

//**********************************************************************
// Height =Max Distance from leaf node OR Max height of its subtree
// Bf = balance factor 
// tcount =  Maintain total count of node including itself
//**********************************************************************

//**********************************************************************
// create empty node with given Data
//**********************************************************************
struct node* getnode(int x)
{
    struct node *temp= (struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->left=NULL;
    temp->right=NULL;
    temp->height=-1;
    temp->bf=0;
    temp->tcount=1;
    return temp;
}

//**********************************************************************
// return height of Perticular node
//**********************************************************************
int getheight(node *root) {
       if(root == NULL)
           return -1;
       else 
           return root->height;
}

//**********************************************************************
// Set Height of perticular node from its child
//**********************************************************************
int setHeight(node *root) {
       if(root == NULL) {
           return -1;
       } 
       else {
           return ( 1 + max(getheight(root->left), getheight(root->right)));
       }
}

//**********************************************************************
// return tcount of Perticular node
//**********************************************************************
int getCount(node *root) {
       if(root == NULL)
           return 0;
       else 
           return root->tcount;
}

//**********************************************************************
// Set tcount of perticular node from its child's tcount
//**********************************************************************
int setCount(node *root) {

       if(root == NULL) {
           return 0;
       } 
       else {
           return ( 1 + getCount(root->left) + getCount(root->right));
       }
}


//**********************************************************************
// Calculate balance factor of perticular Node
//**********************************************************************
int setbalancefactor(node *root)
{
    return (getheight(root->left) - getheight(root->right));
} 


//**********************************************************************
// Search perticular element from tree == Log(n) 
//**********************************************************************
int searchElement(node *root,int x)
{
    if(root==NULL)
        return 0;
    else
    {
        if(root->data == x)
        {
            return 1;
        }
        else if(root->data > x){
            return searchElement(root->left,x);
        }
        else if(root->data < x)
        {
            return searchElement(root->right,x);
        }
    }
    return 0;
}

//**********************************************************************
// Update/Recalculate height , Bf and tcount of tree after rotation 
//**********************************************************************
void updateHeightAndBf(node *root)
{
    root->height = setHeight(root);
    root->bf = setbalancefactor(root);
    root->tcount = setCount(root);
}

//**********************************************************************
// Rotate sub-tree to left side OR move wighter right part to left
//**********************************************************************
node* leftRotation(node *root)
{
    node *rightchild = root->right;
    root->right = rightchild->left;
    rightchild->left = root;
    updateHeightAndBf(root);
    updateHeightAndBf(rightchild); 
    return rightchild;
}

//**********************************************************************
// Rotate sub-tree to right side OR move wighter left part to right
//**********************************************************************
node* rightRotation(node *root)
{
    node *leftchild = root->left;
    root->left = leftchild->right;
    leftchild->right = root;
    updateHeightAndBf(root);
    updateHeightAndBf(leftchild); 
    return leftchild;
}

//**********************************************************************
// Find Which Rotation required for balancing 
//**********************************************************************
node* balancetree(node *root)
{
    //cout<<"balancetree called for  : "<<root->data;
    int rootbf=root->bf;
    if(rootbf == 2)
    {
        int rootleftbf=(root->left)->bf;
        if(rootleftbf>=0)
        {
            //cout<<"LL rotation"<<endl;
            return rightRotation(root);
        }
        else{

            //cout<<"LR rotaion";
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    else if(rootbf == -2)
    {
        int rootrightbf=(root->right)->bf;
        if(rootrightbf<=0)
        {
            //cout<<"RR rotation"<<endl;
            return leftRotation(root);
        }
        else {

            //cout<<"RL rotation"<<endl;
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }

    return root;
}

//**********************************************************************
// Return inorder successor of node
//**********************************************************************
struct node* getInordersuccessor(struct node *root)
{
    struct node *temp1=root;
    while(temp1->left != NULL)
        temp1 = temp1->left;

    return temp1;
}

//**********************************************************************
// Delete specific Node from tree
//**********************************************************************
struct node* deleteSpecificNode(struct node* root, int data)
{
    node *cur;
    if(root==NULL)
    {
        return root;
    }
    if(data < root->data)
    {
        cur = deleteSpecificNode(root->left, data);
        root->left = cur;
    }
    else if(data > root->data )
    {
        cur = deleteSpecificNode(root->right, data);
        root->right = cur;
    }
    // Element found in tree
    else{
        //leaf node to be deleted
        if(root->left==NULL && root->right==NULL)
        {
            root=NULL;
            //return root;
        }
        // if it has only one side tree
        else if(root->left==NULL || root->right==NULL)
        {
            if(root->left != NULL)
                root=root->left;
            else
                root=root->right;
        }
        //node have both side tree
        else{
            struct node *node1 = getInordersuccessor(root->right);
            root->data = node1->data;
            root->right = deleteSpecificNode(root->right,node1->data);
        }
          
    }
    if (root == NULL)
      return root;
    root->height = setHeight(root);
    root->bf = setbalancefactor(root);
    root->tcount = setCount(root);
    return balancetree(root);
}

//**********************************************************************
// Insert node into tree
//**********************************************************************
struct node* insert(struct node *root, int data) {
        //cout<<"Node to be inserted : "<<data<<endl;
        if(root == NULL) {
            node *temp = getnode(data);
            temp->height = setHeight(temp);
            temp->tcount = setCount(temp);
            temp->bf=setbalancefactor(temp);
              //printf("\nfirst insertion data : %d, height : %d , bf : %d ",temp->data,temp->height,temp->bf);
            return temp; 
        } 
        else {

            node *cur;
            if(data < root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            } 
            else if(data > root->data) {
                cur = insert(root->right, data);
                root->right = cur;
           }
           else{
                   return root;
           }
           root->height = setHeight(root);
           root->bf = setbalancefactor(root);
           root->tcount = setCount(root);
           //printf("\n*****Node : %d  height : %d  Bf : %d ",root->data,root->height,root->bf);
           return balancetree(root);

           //return root;
       }
}


//**********************************************************************
// Print inorder of tree along with its data, height, bf and tcount
//**********************************************************************
void inoder(node *root)
{
    if(root!=NULL) 
    {
        inoder(root->left);
        printf("\nNode : %d  height : %d  Bf : %d count: %d",root->data,root->height,root->bf,root->tcount);
        inoder(root->right);
    }
}

//**********************************************************************
// Find Nth smallest Element from tree === O(Height of tree)
//**********************************************************************
int getNSmallestElement(node *root,int k)
{

    int totalleftchild = getCount(root->left);
   
      if(totalleftchild+1 == k){ // +1 for rootNode itself
           return root->data;
   
      }
      else if(totalleftchild+1 >= k){
           return getNSmallestElement(root->left, k);
      }
      else{
           return getNSmallestElement(root->right, k - ( totalleftchild + 1 ));
      }

    // NOT EFFICIENT METHOD, TAKES TIME O(n) 
    // if(root!=NULL) 
    // {
    //     getNSmallestElement(root->left);
    
    //     nsmallest--;
    //     //printf("\nNode : %d  height : %d  Bf : %d ",root->data,root->height,root->bf);
    //     if(nsmallest==0)
    //     {
    //         //cout<<"\nRoot->data"<<root->data;
    //         smallestAns = (root->data);
    //     }
        
    //     getNSmallestElement(root->right);
    // }
}

//**********************************************************************
// Main Method , Program starts from Here...!!!
//**********************************************************************
int main()
{
    int total,query,choice,num;
    struct node *root = NULL;
    cin>>total;
    cin>>query;
    for(int i=0;i<total;i++)
    {
        cin>>num;
        root=insert(root,num);
    }
    while(query--)
    {
        cin>>choice;
        switch(choice)
        {
            case 1:
                cin>>num;
                root = insert(root, num);
                break;
            case 2:
                cin>>num;
                cout<<searchElement(root,num)<<endl;
                break;
            case 3:
                cin>>num;
                int smallestAns=getNSmallestElement(root,num);
                cout<<smallestAns<<endl;
                root = deleteSpecificNode(root,smallestAns);
                break;
        }
    }
    // cout<<"\n*********inorder traversal ***************";
    // inoder(root);
    // cout<<"\n*********inorder traversal ENDDDDDDDDD***************";
    return 0;
}