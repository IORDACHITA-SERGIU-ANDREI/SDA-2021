#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int height;
    int val;
    struct Node *left;
    struct Node *right;

} Node;

void sort(int v[],int n)
{
    int i,counter,aux;
    do
    {
        counter=0;
        for(i=0;i<n-1;i++)
        {
            if(v[i]>v[i+1])
            {
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                counter=1;
            }
        }
    }while(counter);

}

Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = data;
    node->height=0;
    node->left = NULL;
    node->right = NULL;
  
    return node;
}
  
Node* ArrayToAVL(int v[], int start, int end,int h)
{

    if (start > end)
      return NULL;
  
    int mid = (start + end)/2;
    Node *root = newNode(v[mid]);
    root->height=h;

    root->left =  ArrayToAVL(v, start, mid-1,h+1);
        
    root->right = ArrayToAVL(v, mid+1, end,h+1);
  
    return root;
}

int max(int x,int y)
{
    if(x>y)
        return x;
    if(x<=y)
        return y;
}

int nodeHeight(Node *root)
{
    if(root==NULL)
        return -1;
    else 
        return root->height;
}

Node *RightRotation(Node *a)
{
    Node *b=a->left;
    Node *c=b->right;

    b->right=a;
    a->left=c;

    a->height=max(nodeHeight(a->left),nodeHeight(a->right))+1;
    b->height=max(nodeHeight(b->left),nodeHeight(b->right))+1;

    return b;
}

Node *LeftRotation(Node *a)
{
    Node *b=a->right;
    Node *c=b->left;

    b->left=a;
    a->right=c;

    a->height=max(nodeHeight(a->left),nodeHeight(a->right))+1;
    b->height=max(nodeHeight(b->left),nodeHeight(b->right))+1;

    return b;
}

Node *LRRotation(Node *z)
{
    z->left=LeftRotation(z->left);

    return RightRotation(z);
}

Node *RLRotation(Node *z)
{
    z->right=RightRotation(z->right);

    return LeftRotation(z);
}

int verifyBST(Node *node)
{
    if (node == NULL)
        return -1;
    if (node->left != NULL && node->left->val  > node->val)
        return 0;
    if (node->right!= NULL && node->right->val < node->val)
        return 0;    
    if (!verifyBST(node->left) || !verifyBST(node->right))
        return 0;

    return 1;
}

int verify_e(Node *node)
{
    if(node->left==NULL && node->right==NULL)
        return 1;
    else if(node->left==NULL)
        return verify_e(node->right);
    else if(node->right==NULL)
        return verify_e(node->left);
    else
        return (verify_e(node->left) && verify_e(node->right)); 

    if(abs(node->left->height-node->right->height)>=2)
        return 0;
 
}

int verifyAVL(Node *node)
{
    return (verifyBST(node) && verify_e(node)); 
}

Node* search(Node* node,int key)
{
    if(node == NULL || node->val == key)
            return node;
    if(node->val < key)
            return search(node->right,key);
    
    return search(node->left,key);
}

Node* insert(Node *node,int key)
{
    if(node == NULL)
        return newNode(key);

    if(key < node->val)
        node->left=insert(node->left,key);
    else if(key > node->val)
        node->right=insert(node->right,key);
    else
        return node;

    // mai aveam de facut verificarile inaltimilor nodurilor si rotatiile unde este cazul
}

void print(Node* node)
{
    if (node == NULL)
       return;
    printf("%d ", node->val);
    print(node->left);
    print(node->right);
}

int main()
{
    FILE *f;
    int v[8];
    f=fopen("input.txt","r");
    for(int i=0;i<9;i++)
    {
        fscanf(f,"%d",&v[i]);
    }
    printf("\n");
    fclose(f);
    int n =9;
    sort(v,n);
    int a=rand()%20;

    Node *root=ArrayToAVL(v, 0, n-1,1);
    print(root);
    printf("\n");
    printf("Arborele este AVL : %d\n",verifyAVL(root));

    if(search(root,a)!=NULL)
        printf("Valoarea introdusa aleatoriu (%d) se afla in arbore!\n",a);
    else
        printf("Valoarea aleatorie (%d) nu se afla in arbore!\n",a);



        return 0;

}