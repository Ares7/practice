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

    // might think about negative ints coming.

    vector<int> v = {3, 2, 4, 1, 2};
    //vector<int> v = {4, 1, 1, 0, 2, 3};

    int vSize = v.size();
    int startEl = 0, chkEl, minVal, endEl;
    int grandSum = 0, tSum = 0;

    while (startEl < vSize)
    {
        chkEl = startEl + 1;
        while (v[startEl] > v[chkEl] && chkEl < vSize - 1)
        {
            chkEl++;
        }

        endEl = chkEl;
        minVal = min(v[startEl], v[endEl]);

        for (int ix = startEl; ix < endEl; ++ix)
        {
            if (minVal > v[ix])
            {
                tSum += (minVal - v[ix]);
            }
        }


        grandSum += tSum;
        tSum = 0;
        startEl = chkEl;

    }
    cout << grandSum;


    return 0;
}