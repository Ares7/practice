#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
	int m[]={9,4,2,7,2,9,2,5,6,7,1,4,0,3,5,7,2,4,8,4};

	int s = sizeof(m)/sizeof(int);

	for (int i = 1; i < s; ++i)
	{
		int k= i-1;
		int min=m[i];
		while(k>=0 && min<m[k])
		{
			m[k+1]=m[k];
			k--;
		}
		m[k+1]=min;
	}

	for (int i = 0; i < s; ++i)
	{
		cout<<m[i]<< ", ";
	}
	return 0;
}