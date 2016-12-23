#include <iostream>

using namespace std;

/*
TODO: check for timing w and w/o additional ifs
*/

int main(int argc, char const *argv[])
{
	int m[]={5,6,7,34,67,3,56,89,67,23,45,6,6,3,56,34,67,3,2,2,3,5,8,9};
	int s = sizeof(m)/sizeof(int) ;

	for (int i = 0; i < s; ++i)
	{
		int min=i;
		for (int j = i; j < s; ++j)
		{
			if (m[j] < m[min])
			{
				min=j;
			}
		}
		
		if(min!=i)
		{
			int tmp=m[i];
			m[i]=m[min];
			m[min]=tmp;	
		}
		
	}

	for (int i = 0; i < s; ++i)
	{
		cout<< m[i]<< ", ";
	}
	return 0;
}