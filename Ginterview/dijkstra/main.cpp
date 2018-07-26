#include <iostream>
#include <list>
#include <array>
#include <queue>

using namespace std;
#define N = 10;

void printGraph(int NN, list<pair<int, int> > *neigb)
{
    list<pair<int, int> >::iterator i;
    for (int u = 0; u < NN; ++u)
    {
        cout << u << " has neighbors with distances: " << "\t";
        for (i = neigb[u].begin(); i != neigb[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            cout << v << " " << weight << "; ";
        }
        cout << endl;
    }
}

void fillGraph(list<pair<int, int> > *neigb)
{
    neigb[0].push_back(make_pair(1, 5));
    neigb[0].push_back(make_pair(2, 15));
    neigb[0].push_back(make_pair(3, 8));

    neigb[1].push_back(make_pair(2, 1));
    neigb[1].push_back(make_pair(4, 10));

    neigb[2].push_back(make_pair(3, 4));
    neigb[2].push_back(make_pair(4, 7));

    neigb[3].push_back(make_pair(4, 3));
}



int main()
{
    int NN = 4;

    list<pair<int, int> >* neigb;
    neigb = new list<pair<int, int> >[NN];

    priority_queue<pair<int, int>> pq;

    fillGraph(neigb);
    printGraph(NN, neigb);

    cout << "Hello, World!" << endl;

    array<int, 4> visied;
    array<int, 4> dist;
    array<int, 4> pred;

    visied.fill(-1);
    dist.fill(999999);
    pred.fill(-1);

    visied[0] = 1;
    dist[0] = 0;
    pred[0] = 0;


    for (auto& i: neigb[0])
    {
        int v = (*i).first;
        int weight = (*i).second;

        pq.push(make_pair(v, weight + dist[0]));


//            if (dist[v] > weight + dist[u])
//            {
//                dist[v] = weight + dist[u];
//                pred[v] = u;
//            }



        //visied[u] = 1;

    }

    //cout << dist[4] << endl;
    delete[] neigb;

    return 0;
}