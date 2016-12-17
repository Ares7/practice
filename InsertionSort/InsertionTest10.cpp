#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int m[]={5,7,34,56,67,34,6,67,45,34,67,45,34,45,78,789,34,23,23,65,56,34};
	int s=sizeof(m)/sizeof(int)-1;

	for (int i = 1; i < s; ++i)
	{
		int max=m[i];
		int k=i-1;

		while(k>=0 && max>m[k])
		{
			m[k+1]=m[k];
			k--;
		}
			m[k+1]=max;

	}

	for (int i = 0; i < s; ++i)
	{
		cout<< m[i]<< ", ";
	}
	return 0;
}