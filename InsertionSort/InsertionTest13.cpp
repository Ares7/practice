#include "iostream"

using namespace std;

int main(int argc, char const *argv[])
{
	int m[] = {5,3,56,45,4,6,43,3,3,5,6,7};
	int s = sizeof(m)/sizeof(int) - 1;

	for (int i = 1; i < s; ++i)
	{
		int max = m[i];
		int k = i-1;

		while(k>=0 && max> m[k])
		{
			m[k+1]=m[k];
			k--;
		} 
		
		m[k+1]=max;


	}
 
 	for (int i = 0; i < s; ++i)
 	{
 		cout<<m[i]<<", ";
 	}
 	
	return 0;
}