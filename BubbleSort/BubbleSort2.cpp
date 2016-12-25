#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int m[]={5,6,8,6,2,5,8,8,4,7,5,8,0,3,2,6,8,3,67,8,2,6,78,3,6,45,5};
	int s = sizeof(m)/sizeof(int);

	for (int i = 0; i < s; ++i)
	{
		for (int j = i; j < s; ++j) //not from j=0
		{
			if (m[j]>m[i])
			{
				int tmp=m[i];
				m[i]=m[j];
				m[j]=tmp;
			}
		}
	}

	for (int i = 0; i < s; ++i)
	{
		cout<<m[i]<<", ";
	}
	return 0;
}