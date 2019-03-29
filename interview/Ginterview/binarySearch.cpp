#include "iostream"
#include <algorithm>
using namespace std;

int binarySearch(int num, int m[], int SIZE)
{
    // for (int i = 0; i < SIZE; ++i)
    // {
    //     std::cout <<i <<" "<< m[i] << "\n";
    // }
    int low, high, mid;
    
    low = 0;
    high = SIZE - 1;

    while (low<=high)
    {
        mid = (high + low)/2;
        if (m[mid] == num)
        {
            return mid;
        }
        else if(m[mid]<num)
        {
            low = mid +1;
        }
        else
        {
            high = mid - 1;
        }
        
    }

    return -1;
}

int main(int argc, char* argv[])
{
    int NN, size;
    int m[]={4,8,2,12, 4,5,6,623, 67,33,34,67, 8,88,45};

    size = sizeof(m)/sizeof(int);

    std::sort(m, m+size);

    //NN = 45;
    cin>>NN;

    int pos = binarySearch(NN, m, size);

    if( pos == -1)
    {
        std::cout << "element not found!" << "\n";
    }
    else
    {
        std::cout << "element has position: " <<pos<< "\n";
    }

    return 0;
}
