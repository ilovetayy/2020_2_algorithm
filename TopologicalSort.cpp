//2018008804_LeeGyuYeong_12838
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
public:
	int V;
	vector<int>* adj;
	Graph(int V)
	{
		this->V = V;
		adj = new vector<int>[V + 1];
	}
	void addEdge(int e1, int e2)
	{
		adj[e1].push_back(e2);
	}
	void dfs(int v, bool* visit, stack<int>& s);
	void topologicalSort();
	bool isCycle();
	bool isCycleDfs(int v, bool* visit, bool* rec);
};
bool Graph::isCycleDfs(int v, bool* visit, bool* rec)
{
	if ( visit[v] == false )
	{
		visit[v] = true;
		rec[v] = true;

		vector<int>::iterator iter;
		for ( iter = adj[v].begin(); iter != adj[v].end(); ++iter )
		{
			if ( visit[*iter] == false && isCycleDfs(*iter, visit, rec) == true )
			{
				return true;
			}
			else if ( rec[*iter] == true )
			{
				return true;
			}
		}
	}
	rec[v] = false;
	return false;
}
bool Graph::isCycle()
{
	bool* visit = new bool[V + 1];
	bool* rec = new bool[V + 1];
	for ( int i = 0; i <= V; i++ )
	{
		visit[i] = false;
		rec[i] = false;
	}
	for ( int i = 1; i <= V; i++ )
	{
		if ( isCycleDfs(i, visit, rec) )
			return true;
	}
	return false;
}
void Graph::dfs(int v, bool* visit, stack<int>& s)
{
	visit[v] = true;

	vector<int>::iterator it;
	for ( it = adj[v].begin(); it != adj[v].end(); it++ )
	{
		if ( visit[*it] == false )
			dfs(*it, visit, s);
	}
	s.push(v);
}
void Graph::topologicalSort()
{
	stack<int> Stack;

	bool* visited = new bool[V + 1];
	for ( int i = 0; i <= V; i++ ) visited[i] = false;

	for ( int i = 1; i <= V; i++ )
	{
		if ( visited[i] == false )
			dfs(i, visited, Stack);
	}

	while ( Stack.empty() == false )
	{
		cout << Stack.top() << " ";
		Stack.pop();
	}
	cout << endl;
}
int main(void)
{
	int V, E, i, e1, e2;

	cin >> V >> E;
	if ( V < 1 || V > 1000 || E < 0 || E > 50000 ) return 0;

	Graph g = Graph(V);
	Graph g_cycle = Graph(V);
	
	for ( i = 0; i < E; i++ )
	{
		cin >> e1 >> e2;
		g.addEdge(e1, e2);
		g_cycle.addEdge(e1, e2);
	}

	if ( g_cycle.isCycle() )
	{
		cout << 0 << endl;
	}
	else
	{
		for ( i = 1; i <= g.V; i++ )
			if ( g.adj[i].empty() == false )
				sort(g.adj[i].begin(), g.adj[i].end());

		cout << 1 << endl;
		g.topologicalSort();
	}

	return 0;
}