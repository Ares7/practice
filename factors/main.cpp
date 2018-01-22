#include <vector>
#include "iostream"

using namespace std;

int main(int argc, char const *argv[])
{
	int n = 27;

	vector<int> f;

	for(int i=n-1;i>=1;i--)
	{
		if(n%i==0)
		{
			f.push_back(i);
		}
	}

	for(int i=0;i<f.size();i++)
	{
		cout<<f[i]<<" "; 
	}
	return 0;
}