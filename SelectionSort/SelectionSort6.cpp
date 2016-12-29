#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int m[]={6,4,6,9,3,1,3,5,6,8,9,4,5,6,2,3,7,5};
	int s = sizeof(m)/sizeof(int)-1;

	for (int i = s; i >0; --i)
	{
		int max=i;
		int k=i;
		while(k>=0)
		{
			if (m[max]<m[k])
			{
				max=k;
			}
			k--;
		}
		if (max!=i)
		{
			int tmp=m[i];
			m[i]=m[max];
			m[max]=tmp;
		}

	}

	for (int i = 0; i < s; ++i)
	{
		cout<<m[i]<<", ";
	}
	return 0;
}