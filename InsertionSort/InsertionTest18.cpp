#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
	int m[]={6,4,7,8,3,5,7,8,4,34,6,6,78,3,45,78,89,3};
	int s = sizeof(m)/sizeof(int);

	for (int i = 0; i < s; ++i)
	{
		int k = i-1;
		int max = m[i];

		while(k >= 0 && m[k]<max)
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