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
            int v = i->first;
            int weight = i->second;

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

    list<pair<int, int> > *neigb;
    neigb = new list<pair<int, int> >[NN];

    priority_queue<pair<int, int>> pq;

    fillGraph(neigb);
    printGraph(NN, neigb);

    cout << "Hello, World!" << endl;

    array<int, 5> visied;
    array<int, 5> dist;
    array<int, 5> pred;

    visied.fill(-1);
    dist.fill(999999);
    pred.fill(-1);

    visied[0] = 1;
    dist[0] = 0;
    pred[0] = 0;

    for (auto &i: neigb[0])
    {
        int v = i.first;
        int weight = i.second;
        dist[v] = weight;
        pred[v] = 0;

        pq.push(make_pair(v, weight));
    }


    while (!pq.empty())
    {
        auto i = pq.top();
        int v = i.first;
        int weight = i.second;

        if (visied[v] != 1)
        {
            for (auto &ngb: neigb[v])
            {
                int ngb_v = ngb.first;
                int ngb_weight = ngb.second;

                if (dist[ngb_v] > dist[v] + ngb_weight)
                {
                    dist[ngb_v] = dist[v] + ngb_weight;
                    pred[ngb_v] = v;

                    pq.push(make_pair(ngb_v, ngb_weight));
                }


            }
            visied[v] = 1;

        }
        pq.pop();

        //pq.push(make_pair(v, weight + dist[0]));

    }


    cout << dist[4] << endl;
//    cout << pred[4] << endl;
//    cout << dist[pred[4]] << endl;
//    cout << pred[pred[4]] << endl;
//    cout << dist[pred[pred[4]]] << endl;
    delete[] neigb;

    return 0;
}