#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int m[]={45,56,56,23,6,67,23,45,56,78,2,4,34,7,5,3,34,3};
	int s = sizeof(m)/sizeof(int) -1 ;

	for (int i = s-1; i >=0 ; --i)
	{
		int k = i+1;
		int max=m[i];

		while(k<=s && max>m[k])
		{

			m[k-1]=m[k];
			k++;
		}

			m[k-1]=max;

	}

	for (int i = 0; i <= s; ++i)
	{
		cout << m[i]<< endl;
	}


	return 0;
}