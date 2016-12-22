#include "iostream"
using namespace std;

int main(int argc, char const *argv[])
{
	int m[]={4,3,6,4,22,34,89,56,4,56,34,3,67,4,67};
	int s= sizeof(m)/sizeof(int);

	int tmp;

	for (int i = 1; i < s; ++i)
	 {
	 	for (int j = 0; j < s; ++j)
	 	{
			if (m[i]>m[j])
			{
				tmp=m[i];
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
