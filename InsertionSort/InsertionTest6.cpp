#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int m[]={7,5,3,6,5,7,6,3,7,78,3,3,67,34,23,5,7,45,3,90};

	int s=sizeof(m)/sizeof(int);

	for (int i = 1; i < s; ++i)
	{
		
		int max=m[i];
		int k=i-1;

		while(k>=0 && max> m[k])
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