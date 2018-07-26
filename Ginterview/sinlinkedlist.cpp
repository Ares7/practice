#include<iostream>

using namespace std;

struct nodeStruct { 
    int val;
    struct nodeStruct* right;
    struct nodeStruct* left;

};

void addNode(struct nodeStruct* hd, int value)
{
    struct nodeStruct* newNode  = (struct nodeStruct*)malloc(sizeof(struct nodeStruct));
    //char *word = (char*)malloc(sizeof(char));
    struct nodeStruct* currNode;
    struct nodeStruct* prevNode;
    currNode = hd;

    if(hd != nullptr)
    {
        while(currNode!= nullptr )
        {
            prevNode = currNode;
            if(currNode->val < value)
            {
                currNode = currNode->right;
            }
            else
            {
                currNode = currNode->left;
            }
        }
        newNode->val = value;
        newNode->left = NULL;
        newNode->right = NULL;

        currNode = newNode;
    }
    else
    {
        newNode->val = value;
        newNode->left = NULL;
        newNode->right = NULL;    

        hd = newNode;
    }

}

void tst(int  *z)
{
    cout<<(*z);
}
int main() 
{  
   //myabc.i=55;
   //cout<<myabc.i;

   int k =5;
    int *p;
    p = &k;

    tst(p);

    
    struct nodeStruct* root = nullptr;

    addNode(root, 25);
    addNode(root, 15);
    addNode(root, 27);
    addNode(root, 44);
    addNode(root, 19);




    return 0;
}