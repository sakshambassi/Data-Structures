#include <bits/stdc++.h>

using namespace std;

struct node
{
	int end;
	int weight;
};

void addEdge(vector<struct node *> adjList[], int s, int e, int weight)
{
	struct node * root=NULL;
	root = new(struct node);
	root->end = e;
	root->weight = weight;
	adjList[s].push_back(root);
	root = new(struct node);
	root->end = s;
	root->weight = weight;
	adjList[e].push_back(root);
}

void DisplayGraph(vector<struct node *> adjList[], int v)
{
	vector<struct node *>::iterator it;
	for (int i = 0; i < v; ++i)
	{
		cout<<"Adjacency List of vertex "<<i<<": ";
		cout<<"Head"<<i;
		for (it=adjList[i].begin(); it != adjList[i].end(); it++)
		{
			cout<<" ->"<<(*it)->end;
		}
		cout<<"\n";
	}
}

void DFSUtil(int source, bool visited[],vector<struct node *> adjList[])
{
	visited[source] = true;
	cout<<source<<" ";
	vector<struct node *>::iterator it;
	for (it = adjList[source].begin(); it !=adjList[source].end(); ++it)
	{
		if(!visited[(*it)->end])
			DFSUtil((*it)->end,visited,adjList);
	}
}

void DFS(vector<struct node *> adjList[],int v, int source)
{
	bool visited[v];
	for (int i = 0; i < v; ++i)
	{
		visited[i] = false;
	}
	DFSUtil(source,visited,adjList);
}

void BFS(vector<struct node *> adjList[],int v, int source)
{
	bool visited[v];
	for (int i = 0; i < v; ++i)
	{
		visited[i] = false;
	}
	list<int> queue;
	visited[source]=true;

	queue.push_back(source);

	vector<struct node *>::iterator it;
	while(!queue.empty())
	{
		source = queue.front();
		cout<< source << " ";
		queue.pop_front();

		for (it = adjList[source].begin(); it !=adjList[source].end(); ++it)
		{
			if(!visited[(*it)->end])
			{
				visited[(*it)->end] = true;
				queue.push_back((*it)->end);
			}
		}
	}
}

int main()
{
	int v, s, e, count, weight;
	cout<<"\nEnter the number of vertices: ";
	cin>>v;
	cout<<"\nEnter the number of edges: ";
	cin>>count;
	vector<struct node *> adjList[v];
	for (int i = 0; i < count; ++i)
	{
		cout<<"Enter start vertex: ";
		cin>>s;
		cout<<"Enter end vertex: ";
		cin>>e;
		cout<<"Enter weight: ";
		cin>>weight;
		addEdge(adjList,s,e,weight);
	}
	DisplayGraph(adjList, v);
	DFS(adjList, v, 2);
	BFS(adjList, v, 2);
	return 0;
}