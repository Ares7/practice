#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int m[]={78,34,65,5,3,34,8,5,45,67,2,3,6,4,3,8989,22,34,34,77};

	int s= sizeof(m)/sizeof(int) - 1;

	for (int i = s-1; i >= 0; --i)
	{
		int min=m[i];
		int k = i+1;

		while(k<= s && min<m[k])
		{
			m[k-1]=m[k];
			k++;
		}
			m[k-1]=min;

	}

	for (int i = 0; i < s; ++i)
	{
		cout<< m[i]<< ", " ;
	}
	return 0;
}