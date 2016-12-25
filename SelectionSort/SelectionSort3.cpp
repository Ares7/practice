#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
	int m[]={6,5,8,3,7,4,2,1,7,0,4,7,3,4,6,8,2,6,0};
	int s=sizeof(m)/sizeof(int)-1;

	for (int i = s; i >= 0; --i)
	{
		int min=i;
		for (int j = i; j >= 0; --j)
		{
			if (m[min]>m[j])
				min=j;
		}
        if (min!=i) 
        {
            int tmp=m[i];
            m[i]=m[min];
            m[min]=tmp;
        }
	}

    for (size_t i = 0; i < s; i++) {
        std::cout << m[i] <<", ";
    }
}
