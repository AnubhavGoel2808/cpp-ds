#include "Graph.h"
#include<iostream>
using namespace std;


void bfs(Graph g,int v){
	bool visited[v];int level=0;
	list<int> queue;
	for(int i=0;i<v;i++)
	visited[i]=false;
	queue.push_back(0);
	visited[0]=true;
	while(!queue.empty()){
		int s=queue.front();
		queue.pop_front();
		list<int> :: iterator i;
		for(i=g.adjList[s].begin();i!=g.adjList[s].end();i++){
			if(!visited[*i]){
				queue.push_back(*i);
				visited[*i]=true;
			}
		}
		cout<<s<<" "<<level;
	}
}

int main(){
	cout<<"Enter number of vertices : ";
	int v;
	cin>>v;
	Graph g(v);
	cout<<"Enter number of edges : ";
	int e;
	cin>>e;
	cout<<"Enter edge source and destination (0-index based) :\n";
	for(int i=0;i<e;i++)
	{
		int s,d;
		cin>>s>>d;
		g.addEdge(s,d);
	}
	bfs(g,v);
	return 0;
}
