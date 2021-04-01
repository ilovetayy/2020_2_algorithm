//2018008804_LeeGyuYeong_12838
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> VtoV;
typedef struct Tuple
{
	int x;
	int y;
	int w;
};

int cnt = 0;
vector<Tuple> res;

class Graph
{
	int V, E;
	vector<pair<int, VtoV> > edges;
public:
	Graph(int v, int e)
	{
		V = v;
		E = e;
	}
	void addEdge(int e1, int e2, int w)
	{
		edges.push_back({ w, { e1, e2 } });
	}
	void kruskal();
};
class DisjointSets
{
	int *parent, *rank;
	int n;
public:
	DisjointSets(int n)
	{
		this->n = n;
		parent = new int[n + 1];
		rank = new int[n + 1];

		for ( int i = 0; i <= n; i++ )
		{
			rank[i] = 0;
			parent[i] = i;
		}
	}
	int find(int v)
	{
		if ( v != parent[v] )
			parent[v] = find(parent[v]);
		return parent[v];
	}
	void unionByRank(int x, int y)
	{
		x = find(x);
		y = find(y);

		if ( rank[x] > rank[y] )
			parent[y] = x;
		else
		{
			parent[x] = y;
			if ( rank[x] == rank[y] )
				rank[y]++;
		}
	}
};
void Graph::kruskal()
{
	sort(edges.begin(), edges.end());

	DisjointSets ds(V);

	vector<pair<int, VtoV> >::iterator itr;
	for ( itr = edges.begin(); itr != edges.end(); itr++ )
	{
		int u = itr->second.first;
		int v = itr->second.second;
		int w = itr->first;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		if ( set_u != set_v )
		{
			cnt++;
			res.push_back({u,v,w});
			ds.unionByRank(set_u, set_v);
		}
	}
}
int main(void)
{
	int v, e, i, x, y, w;

	cin >> v >> e;
	if ( v < 1 || v>1000 || e < 1 || e>499500 )return 0;

	Graph g = Graph(v, e);

	for ( i = 0; i < e; i++ )
	{
		cin >> x >> y >> w;
		g.addEdge(x, y, w);
	}

	g.kruskal();
	cout << cnt << endl;
	for ( i = 0; i < res.size(); i++ )
	{
		cout << res[i].x << " " << res[i].y << " " << res[i].w << endl;
	}

	return 0;
}