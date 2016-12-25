#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int m[]={5,67,7,4,67,67,23,7,9,90,4,2,7,5,56,34,45,67,4,4,32};
	int s = sizeof(m)/sizeof(int);

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
		cout<<m[i]<< ", ";
	}
	
	return 0;
}