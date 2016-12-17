#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int m[]={4,6,7,3,5,78,67,23,345,67,7,45,3,9};

	int s=sizeof(m)/sizeof(int)-1;

	for (int i = s-1; i >=0; --i)
	{
		int k=i+1;
		int max=m[i];

		while(k<=s && max>m[k])
		{
			m[k-1]=m[k];
			k++;
		}
		m[k-1]=max;
	}

	for (int i = s; i >= 0; --i)
	{
		cout<<m[i]<<", ";
	}

	return 0;
}
