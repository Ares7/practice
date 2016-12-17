#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int m[]={5,3,6,4,34,6,7,3,3,6,3,3,78,3,34,65,34};
	int s= sizeof(m)/sizeof(int)-1;

	for (int i = 1; i < s; ++i)
	{
		 int min=m[i];
		 int k=i-1;

		while(k>=0 && min<m[k])
		{
			m[k+1]=m[k];
			k--;
		}
			m[k+1]=min;

	}

	for (int i = 0; i < s; ++i)
	{
		cout<< m[i]<< ", ";
	}
	return 0;
}