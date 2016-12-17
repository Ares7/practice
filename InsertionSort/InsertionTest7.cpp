#include "iostream"

using namespace std;

int main(int argc, char const *argv[])
{
	int m[]={45,45,56,23,23,78,0,34,34,56,43,2,4,9,45,4,3};
	int s=sizeof(m)/sizeof(int)-1;

	for (int i = s-1; i >= 0; --i)
	{
		int min=m[i];
		int k=i+1;

		while(k<=s && min<m[k])
		{
			m[k-1]=m[k];
			k++;
		}
		m[k-1]=min;
	}

	for (int i = s; i >=0 ; --i)
	{
		cout<< m[i]<< ", ";
	}
	return 0;
}