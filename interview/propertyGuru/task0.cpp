// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> &A)
{
    // write your code in C++14 (g++ 6.2.0)
    unordered_map<int, bool> umap;
    int N = A.size();

    for (int ix = 0; ix < N; ix++)
    {
        umap.insert(make_pair(A[ix], true));
        // cout << A[ix] << endl;
    }
    //cout << "\nAll Elements : \n";
    unordered_map<int, bool>::iterator itr;

    // for (itr = umap.begin(); itr != umap.end(); itr++)
    // {
    //     // itr works as a pointer to pair<string, double>
    //     // type itr->first stores the key part  and
    //     // itr->second stroes the value part
    //     cout << itr->first << "  " << itr->second << endl;
    // }

    for (int ix = 1; ix <= N; ix++)
    {
        if (umap.find(ix) == umap.end())
        {
            //cout << "here" << endl;
            return ix;
        }
    }

    return N + 1;
}

int main()
{
    vector<int> A{-1, -3};

    cout << solution(A);
}