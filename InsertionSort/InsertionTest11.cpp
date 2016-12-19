#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int m[]={5,34,6,67,34,46,67,3,56,5,23,56};
	int s = sizeof(m)/sizeof(int) - 1;

	for (int i = s; i >0 ; --i)
	{
		int max = m[i];
		int k = i + 1;

		while(k<=s && max>m[k])
		{

			m[k-1]=m[k];
			k++;
		}
		m[k-1]=max;
	}

	for (int i = 0; i <= s; ++i)
	{
		cout<< m[i]<< ", ";
	}
	return 0;
}