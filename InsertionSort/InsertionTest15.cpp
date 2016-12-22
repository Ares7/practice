#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int m[]={45,5,23,56,3,8,6,3,56,3,4,2,4,6,78,4};
	int s= sizeof(m)/sizeof(int)- 1 ;

	for (int i = s-1; i >=0; --i)
	{
		int min = m[i];
		int k = i+1;

		while(k<=s && min<m[k])
		{
			m[k-1]=m[k];
			k++;
		}
			m[k-1]=min;

	}

	for (int i = 0; i < s; ++i)
	{
		cout<<m[i]<<", ";
	}
	
	return 0;
}