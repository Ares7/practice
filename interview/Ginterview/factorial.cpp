#include "iostream"

using namespace std;

long double fct(int num)
{
    if (num<=1)
    {
        return num;
    }
    else
    {
        return num*fct(num-1);
    }
}

int main(int argc, char* argv[])
{
    long double  NN;
    std::cin >> NN;
    std::cout << fct(NN) << "\n";

    return 0;
}
