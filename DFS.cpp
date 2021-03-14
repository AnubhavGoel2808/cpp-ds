#include "Graph.h"
#include<iostream>
using namespace std;


void dfs(Graph g,int s,bool visited[]){
	cout<<s<<" ";
	list<int> :: iterator i;
	visited[s]=true;
	for(i=g.adjList[s].begin();i!=g.adjList[s].end();i++){
		if(!visited[*i])
		dfs(g,*i,visited);
	}
}

int main(){
	cout<<"Enter number of vertices : ";
	int v;
	cin>>v;
	Graph g(v);
	cout<<"Enter number of edges : ";
	int e; cin>>e;
	cout<<"Enter edge source and destination (0-index based) :\n";
	bool visited[v];
	for(int i=0;i<e;i++)
	{
		int s,d;
		cin>>s>>d;
		g.addEdge(s,d);
	}
	for(int i=0;i<v;i++)
	visited[i]=false;
	dfs(g,0,visited);
	return 0;
}
