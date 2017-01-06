#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int m[]={6,4,5,67,9,6,4,2,2,4,5,7,89,0,4,2,12,4,6,7,4,4,12};
	int s = sizeof(m)/sizeof(int);

	for (int i = 1; i < s; ++i)
	{
		int max = m[i];
		int k = i-1;

		while(k>=0 && m[k]<max)
		{
			m[k+1]=m[k];
			k--;
		}
		m[k+1]=max;

	}

	for (int i = 0; i < s; ++i)
	{
		cout<<m[i]<<", ";
	}

	return 0;
}