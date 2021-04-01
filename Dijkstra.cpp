#include <iostream>
#include <list>
#include <queue>
#include <functional>
#include <algorithm>

#define INF 2147483647

using namespace std;

typedef pair<int, int> iPair;
class Graph
{
public:
	int V;
	priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
	list<pair<int, int> >* adj;
	vector<int> dist;

	Graph(int v)
	{
		V = v;
		adj = new list<iPair>[v + 1];
		dist = vector<int>(V + 1, INF);
	}
	void addEdge(int x, int y, int w)
	{
		adj[x].push_back(make_pair(y, w));
	}
	void Dijkstra(int s);
};
void Graph::Dijkstra(int src)
{
	pq.push(make_pair(0, src));
	dist[src] = 0;

	while ( !pq.empty() )
	{
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();

		if ( dist[here] < cost )
			continue;

		list<pair<int, int> >::iterator it;
		for ( it = adj[here].begin(); it != adj[here].end(); ++it )
		{
			int there = (*it).first;
			int nextDist = cost + (*it).second;

			if ( dist[there] > nextDist )
			{
				dist[there] = nextDist;
				pq.push(make_pair(dist[there], there));
			}
		}
	}
}
int main(void)
{
	int v, e, x, y, w, i;

	cin >> v >> e;
	if ( v < 1 || v > 5000 || e < 1 || e > 260000 )return 0;

	Graph g(v);

	for ( i = 0; i < e; i++ )
	{
		cin >> x >> y >> w;
		g.addEdge(x, y, w);
	}

	g.Dijkstra(1);

	cout << *max_element(g.dist.begin() + 2, g.dist.end()) << endl;

	return 0;
}
