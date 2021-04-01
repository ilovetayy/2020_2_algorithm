//2018008804_LeeGyuYeong_12838
#include <iostream>
#include <list>
using namespace std;

typedef struct Graph
{
	int V;
	list<int>* adj;
};
void addEdge(Graph g, int e1, int e2)
{
	g.adj[e1].push_back(e2);
	g.adj[e2].push_back(e1);
}
void dfs(Graph g, int v, bool visit[])
{
	visit[v] = true;
	list<int>::iterator iter;
	for ( iter = g.adj[v].begin(); iter != g.adj[v].end(); ++iter )
	{
		if ( visit[*iter] == false )
			dfs(g, *iter, visit);
	}
}
int main(void)
{
	int V, E, i, e1, e2;
	int component = 0;

	cin >> V >> E;
	if ( V < 1 || V > 1000 || E < 1 || E > 5000 ) return 0;

	Graph G;
	G.V = V;
	G.adj = new list<int>[V + 1];

	for ( i = 0; i < E; i++ )
	{
		cin >> e1 >> e2;
		addEdge(G, e1, e2);
	}

	bool* visit = new bool[V + 1];

	for ( i = 1; i <= V; i++ ) visit[i] = false;

	for ( i = 1; i <= V; i++ )
	{
		if ( visit[i] == false )
		{
			dfs(G, i, visit);
			component += 1;
		}
	}
	cout << component << '\n';

	return 0;
}