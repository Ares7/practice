#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct cities_res
{
    int cs;
    vector<int> vi;
} info_res;

vector<cities_res> vres;

int main()
{
    std::ios::sync_with_stdio(false);

    int temp;
    vector<int> v;

    while (cin >> temp)
    {
        v.push_back(temp);
    }

    for (int ix = 0; ix < v.size(); ix++)
    {
        cout << v[ix] << " ";
    }

    return 0;
}