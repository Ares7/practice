#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	//
	int m[]={23,6444, 25, 67,34, 8, 999,6,6,43,6,6,6,45,56,3,2,45,56,5,56,67,3,4,12};
	int s=sizeof(m)/sizeof(int);

	for (int i = 0; i < s; ++i)
	{
		int max=i;
		for (int j = i; j < s; ++j) //start with j=i !!
		{
			if(m[j]>m[max])
				max=j;
		}

		if (max!=i)
		{
			int tmp=m[max];
			m[max]=m[i];
			m[i]=tmp;
		}
	}

	for (int i = 0; i < s; ++i)
	{
		cout<< m[i]<<", ";
	}
	return 0;
}