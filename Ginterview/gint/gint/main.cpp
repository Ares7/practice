#include<iostream>

using namespace std;

struct nodeStruct {
	int val;
	struct nodeStruct* right;
	struct nodeStruct* left;

};

struct nodeStruct*  addNode(struct nodeStruct* hd, int value)
{
	struct nodeStruct* newNode  = (struct nodeStruct*)malloc(sizeof(struct nodeStruct));
	//char *word = (char*)malloc(sizeof(char));
	struct nodeStruct* currNode;
	struct nodeStruct* prevNode;
	int dir = 0;

	currNode = hd;
	prevNode = nullptr;
	//prevNode = hd;

	newNode->val = value;
	newNode->left = NULL;
	newNode->right = NULL;

	if(hd != nullptr)
	{

		while(currNode!= nullptr  )
		{

			//prevNode = currNode;
			if(currNode->val < value)
			{
				//prevNode->right =

				currNode = currNode->right;
				dir = 1;

				if(prevNode == nullptr)
				{
					prevNode = hd;
				}
				else
				{
					prevNode = prevNode->right;
				}
			}
			else
			{
				//prev = prev->left;
				currNode = currNode->left;
				dir = -1;

				if(prevNode == nullptr)
				{
					prevNode = hd;
				}
				else
				{
					prevNode = prevNode->left;
				}
			}
		}

		currNode = newNode;
		if(dir == 1)
		{
			prevNode->right = currNode;
		}
		else if (dir == -1)
		{
			prevNode->left = currNode;
		}
	}
	else
	{
		hd = newNode;
	}

	return hd;

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

	root = addNode(root, 25);
	root = addNode(root, 15);
	root = addNode(root, 27);
	root = addNode(root, 44);
	root = addNode(root, 19);




	return 0;
}
