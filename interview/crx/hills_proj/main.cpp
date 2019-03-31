#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
    std::ios::sync_with_stdio(false);

    // might think about negative ints coming.

    //vector<int> v = {3, 2, 4, 1, 2}; //12-2 right
    //vector<int> v = {4, 1, 1, 0, 2, 3}; //13-8 right

    //vector<int> v = {4, 3, 2, 1, 2}; // 10-1 right
    //vector<int> v = {4, 1, 4, 4, 3, 1, 2}; // 14-4- right
    //vector<int> v = {2, 0, 2}; //2, right
    //vector<int> v = {3, 0, 0, 2, 0, 4}; // 4, right
    //vector<int> v = { 0, 0, 0}; // 0, right

    //vector<int> v = {3, 2, 1, 0, 1, 2, 2}; // 4, right
    //vector<int> v = {4, 3, 2, 1, 1}; // 7-0 right
    //vector<int> v = {4, 3, 2, 1, 2, 2, 0}; // 6-1 right
    //vector<int> v = {2, 1, 0, 1, 0, 0, 1, 0}; // 5-3, right
     vector<int> v = { 4, 3, 2, 1, 2, 0, 1}; // 15-3, wrong
    //vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1}; // wrong 1-6
    //vector<int> v = {1,2,3,2,1};



    int vSize = v.size();
    int startEl = 0, chkEl, minVal, endEl;
    int grandSum = 0, tSum = 0;
    int higher, lower = 0;
    int hix, bkpIx;

    while (startEl < vSize)
    {
        chkEl = startEl + 1;
        lower = v[startEl];
        higher = v[startEl];

        //going through valley
        while (v[startEl] > v[chkEl])
        {
            if (chkEl < vSize - 1)
            {
                if (v[chkEl] < lower)
                {
                    lower = v[chkEl];
                    bkpIx = hix;

                    //cant comment it, see ex 13
                    higher = 0;

                }
                //need equality to update the index.
                else if (v[chkEl] >= higher)
                {
                    higher = v[chkEl];
                    hix = chkEl;
                }
                chkEl++;
            }
                //reached the very right border
            else
            {
                //need equality to update the index.
                if (v[chkEl] >= higher)
                {
                    higher = v[chkEl];
                    hix = chkEl;
                }
                break;
            }

        }

        if (higher != 0)
        {
            endEl = hix;
        }
        else
        {
            endEl = chkEl;
        }

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