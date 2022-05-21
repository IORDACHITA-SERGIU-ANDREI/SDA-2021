#include<stdio.h>
#include<stdlib.h>
  
typedef struct TNode
{
    int data;
    struct TNode* left;
    struct TNode* right;

}TNode;

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

TNode* newNode(int data)
{
    TNode* node = (TNode*)malloc(sizeof(TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
  
    return node;
}
  
TNode* ArrayToBST(int v[], int start, int end)
{

    if (start > end)
      return NULL;
  
    int mid = (start + end)/2;
    TNode *root = newNode(v[mid]);

    root->left =  ArrayToBST(v, start, mid-1);

    root->right = ArrayToBST(v, mid+1, end);
  
    return root;
}

TNode* search(TNode* node,int val)
{
    if(node == NULL || node->data == val)
            return node;
    if(node->data < val)
            return search(node->right,val);
    
    return search(node->left,val);
}

int verify(TNode *node)
{
    if (node == NULL)
        return -1;
    if (node->left != NULL && node->left->data  >= node->data)
        return 0;
    if (node->right!= NULL && node->right->data <= node->data)
        return 0;
    if (!verify(node->left) || !verify(node->right))
        return 0;

    return 1;
}

TNode* insert(TNode *node,int val)
{
    if(node == NULL)
        return newNode(val);

    if(val < node->data)
        node->left=insert(node->left,val);
    else if(val > node->data)
        node->right=insert(node->right,val);

        return node;
}

TNode* minValueNode(TNode *node)
{
    TNode *current=node;
    while(current->left!=NULL)
    {
        current=current->left;
    }
        return current;
}

TNode* deleteNode(TNode *node,int val)
{
    if(node == NULL)
        return node;
    if(val < node->data)
        node->left=deleteNode(node->left,val);
    else if(val > node->data)
        node->right=deleteNode(node->right,val);
    else
    {
        if(node->left == NULL)
        {
            TNode *temp=node;
            node=node->right;
            free(temp);
            return node;
        }
        else if (node->right == NULL)
        {
            TNode *temp=node;
            node=node->left;
            free(temp);
            return node;
        }

        TNode *temp=minValueNode(node->right);

        node->data=temp->data;

        node->right=deleteNode(node->right,temp->data);
    }

    return node;
}

void print(TNode* node)
{
    if (node == NULL)
       return;
    printf("%d ", node->data);
    print(node->left);
    print(node->right);
}
  
int main()
{
    FILE *f;
    int *v,n;
    printf("Introduceti numarul de elemente: ");
    scanf("%d",&n);
    v=(int*)malloc(sizeof(int));
    f=fopen("input.txt","r");
    for(int i=0;i<5;i++)
    {
        fscanf(f,"%d",&v[i]);
    }
    fclose(f);
    sort(v,n);
    int a=rand()%20;
  
    TNode *root = ArrayToBST(v, 0, n-1);
    printf("Afisare arbore: ");
    print(root);
    printf("\n");
    printf("Functia va afisa 1 daca arborele este binar de cautare, 0 in caz contrar si -1 daca arborele este NULL\n");
    printf("Arbore: %d\n",verify(root));


    if(search(root,a)!=NULL)
        printf("Valoarea introdusa aleatoriu (%d) se afla in arbore!\n",a);
    else
        printf("Valoarea aleatorie (%d) nu se afla in arbore!\n",a);

    root=insert(root,0);
    printf("Afisare arbore dupa ce a fost adaugat un element: ");
    print(root);
    printf("\n");
    root=deleteNode(root,7);
    printf("Afisare arbore dupa ce a fost sters un element: ");
    print(root);
    printf("\n");

    return 0;


}