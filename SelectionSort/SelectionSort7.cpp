#include "iostream"

using namespace std;

int main(int argc, char const *argv[])
{
	int m[]={6,3,6,8,4,3,6,8,6,4,5,7,9,4,23,2,56,7,7};
	int s=sizeof(m)/sizeof(int);

	for (int i = 0; i < s; ++i)
	{
		int max=i;
		for (int j = i; j < s; ++j)
		{
			if (m[j]>m[max])
			{
				max = j;
			}
		}

		if (max!=i)
		{
			int tmp= m[i];
			m[i]=m[max];
			m[max]=tmp;
		}
	}

	for (int i = 0; i < s; ++i)
	{
		cout<<m[i]<< ", ";
	}
	return 0;
}