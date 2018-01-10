/*
 partially adopted form
 stanfordacm
 */

#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

typedef vector<double> VI;
typedef vector<VI> VVI;


struct MaxFlow {
	int L;
	int N;
	int M;
	int posA;
	int posB;



	VVI cap, flow;
	VI dad, Q;

	MaxFlow(int L, int N, int M) :
	N(N), cap(N, VI(N)), flow(N, VI(N)), dad(N), Q(N)
	{
		this->L = L;
		this->posA = 0;
		this->posB = N - 1;
		this->M = M;
	}

	void AddEdge(int from, int to, double cap)
	{
		this->cap[from][to] += cap;
	}

	int BlockingFlow(int s, int t)
	{
		fill(dad.begin(), dad.end(), -1);
		dad[s] = -2;

		int head = 0, tail = 0;
		Q[tail++] = s;
		while (head < tail)
		{
			int x = Q[head++];
			for (int i = 0; i < N; i++)
			{
				if (dad[i] == -1 && cap[x][i] - flow[x][i] > 0)
				{
					dad[i] = x;
					Q[tail++] = i;
				}
			}
		}

		if (dad[t] == -1) return 0;

		double totflow = 0;
		for (int i = 0; i < N; i++)
		{
			if (dad[i] == -1) continue;

			double amt = cap[i][t] - flow[i][t];
			for (int j = i; amt && j != s; j = dad[j])
				amt = min(amt, cap[dad[j] ][j] - flow[dad[j] ][j]);
			if (amt == 0) continue;
			flow[i][t] += amt;
			flow[t][i] -= amt;
			for (int j = i; j != s; j = dad[j])
			{
				flow[dad[j] ][j] += amt;
				flow[j][dad[j]] -= amt;
			}
			totflow += amt;
		}

		return totflow;
	}

	double GetMaxFlow(int source, int sink)
	{
		double totflow = 0;
		while (double flow = BlockingFlow(source, sink))
			totflow += flow;

		if(totflow>this->L)
		{
			return -1;
		}

		return totflow;
	}

	int FillGraph()
	{

		vector<string> currs;
		string cur;
		for (int i = 0; i < this->M; ++i)
		{
			cin>>cur;
			currs.push_back(cur);		
		}

		double val;
		for (int i = 0; i < this->M; ++i)
		{
			
			for (int i = 0; i < this->M; ++j)
			{
				cin >> val;
				if (val != 1)
				{
					this->AddEdge(currs[i], y-1, z);
					this->AddEdge(y-1, x-1, z);
				}

			}
		}

		return 0;
	}

};

int main() {

	vector<double> v;
	std::ios::sync_with_stdio(false);

	int t = 1;

	cin >> t;
	cin.ignore();

	//Read input data
	for (int k = 0; k < t; ++k)
	{
		int l, n, m;
		//cout << "enter:";
		cin >> l>> n >> m;

		MaxFlow mf(l, n, m);
		mf.FillGraph();

		v.push_back(mf.GetMaxFlow(mf.posA, mf.posB));

	}

	for (int j = 0; j < t; ++j)
	{

		cout << "Case #" << j + 1 << ": ";
		v[j];
		cout << endl;
	}
}

