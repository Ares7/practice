#include <iostream>
#include <vector>

using namespace std;

/*
 * Function that computes number of gaps between bricks.
 *
 * Approach:
 * 1. make sure every gap has borders (bricks) on the left and right.
 * 2. the gap height is as high as the shortest border o nthe left or right.
 * 3. calculate the most certain values first. Most certain == shortest borders.
 */

int calcWaterVolume(vector<int> &v, int n)
{
    int lhigh = 0, rhigh = 0, startIx = 0, endIx = n - 1;
    int globSum = 0;

    while (startIx <= endIx)
    {
        if (v[startIx] < v[endIx])
        {
            if (v[startIx] > lhigh)
            {
                lhigh = v[startIx];
            }
            else
            {
                globSum += lhigh - v[startIx];
            }
            startIx++;
        }

        else
        {
            if (v[endIx] > rhigh)
            {
                rhigh = v[endIx];
            }
            else
            {
                globSum += rhigh - v[endIx];
            }
            endIx--;
        }
    }

    return globSum;
}

int main()
{
    std::ios::sync_with_stdio(false);

    vector<int> vBricks;

    int nBricks, brickVal, brIx = 0;

    cout << "Please enter the length of the floor (number of items in the array)." << endl;
    cin >> nBricks;

    cout << "Please enter integers separated by a space." << endl;
    while (brIx < nBricks)
    {
        cin >> brickVal;
        vBricks.push_back(brickVal);
        brIx++;
    }

    // determine number of gaps in the bricks:
    cout << "Result: " << calcWaterVolume(vBricks, nBricks) << endl;

    return 0;
}