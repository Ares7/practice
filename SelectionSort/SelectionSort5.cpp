#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int m[]={6,7,9,3,7,4,4,9,4,6,3,9,2,8,8,0,2};
	int s = sizeof(m)/sizeof(int);

	for (int i = s-1; i >= 1; --i)
	{
		int min=i;
		
		for (int j = i; j >=0; --j)
		{
			if (m[min]>m[j])
			{
				min=j;
			}
		}

		if (min!=i)
		{
			int tmp=m[i];
			m[i]=m[min];
			m[min]=tmp;
		}
	}

	for (int i = 0; i < s; ++i)
	{
		cout<<m[i]<< ", ";
	}
	return 0;
}