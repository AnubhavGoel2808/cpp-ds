#include <iostream>
#include <queue>
#include <stack>


/* 
    WHITE  -> not discovered
    GREY  -> discovered
    BLACK -> done
*/
#define WHITE 0
#define GREY 1
#define BLACK 2

using namespace std;

class Node
{
  private:
    int val;
    Node *next;

    friend class Graph;

  public:
    Node(int val)
    {
        this->val = val;
        this->next = 0;
    }
};

class Graph
{
  private:
    int no_v;
    Node **adj;

  public:
    // Parametrized Constructor
    Graph(int);

    // Setter Method
    void AddEdge(int, int);

    // Getter Method
    Node **GetGraph() const;

    // Application Methods
    int *BFS(int) const;
    void DFS(int) const;
    void ShowGraph() const;
};

Graph::Graph(int no_v)
{
    this->no_v = no_v;

    adj = new Node *[no_v];

    for (int i = 0; i < no_v; i++)
    {
        adj[i] = 0;
    }
}

void Graph::AddEdge(int u, int v)
{
    Node *new_node = new Node(v);

    if (!adj[u])
    {
        adj[u] = new_node;
    }
    else
    {
        new_node->next = adj[u];
        adj[u] = new_node;
    }
}

Node **Graph::GetGraph() const
{
    return adj;
}

int *Graph::BFS(int source) const
{
    queue<int> q;

    int arr_disc[no_v] = {WHITE};

    int *level = new int[no_v];

//    for (int i = 0; i < no_v; i++)
//    {
//        level[i] = {-1};
//    }

    q.push(source);
    arr_disc[source] = GREY;
    level[source] = 0;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        int parent_level = level[v];

        arr_disc[v] = BLACK;

        Node *ptr = adj[v];

        while (ptr)
        {
            if (arr_disc[ptr->val] == WHITE)
            {
                q.push(ptr->val);
                arr_disc[ptr->val] = GREY;
                level[ptr->val] = parent_level + 1;
            }
            ptr = ptr->next;
        }
    }

    return level;
}

void Graph::DFS(int source) const
{
    stack<int> s;

    int arr_disc[no_v] = {WHITE};

	int baap[no_v];

    s.push(source);
    arr_disc[source] = GREY;
    baap[source]=-1;
 
    
    while (!s.empty())
    {
        int v = s.top();
        s.pop();

		cout<<v<<" ("<<baap[v]<<") \n";
        arr_disc[v] = BLACK;
        Node *ptr = adj[v];

        while (ptr)
        {	
			if(arr_disc[ptr->val]==GREY)
				baap[ptr->val]=v;
            if (arr_disc[ptr->val] == WHITE)
            {
				baap[ptr->val]=v;
                s.push(ptr->val);
                arr_disc[ptr->val] = GREY;
            }
            
            ptr = ptr->next;
        }
    }
    
   

    return;
}



void Graph::ShowGraph() const
{
    for (int i = 0; i < no_v; i++)
    {
        cout << i << " ->  ";

        Node *ptr = adj[i];

        while (ptr)
        {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }

        cout << "\n";
    }

    return;
}

int main()
{
    cout << "\nenter no of vertices : ";
    int no_v;
    cin >> no_v;

    Graph graph(no_v);

    cout << "enter 0 for directed and 1 for undirected graph : ";
    int choice;
    cin >> choice;

    cout << "\nenter (u,v) pair in the graph (-1 to exit): ";
    int u, v;

    while (1)
    {
        cin >> u;

        if (u == -1)
            break;

        cin >> v;

        graph.AddEdge(u, v);

        if (choice == 1)
            graph.AddEdge(v, u);
    }

    graph.ShowGraph();

    cout << "\nenter source : ";
    int s;
    cin >> s;

    cout << "\nBFS : ";

    int *level = graph.BFS(s);

    for (int i = 0; i < no_v; i++)
    {
        cout << "\n"
             << level[i];
    }
    
    cout << "\n\nDFS : ";

    graph.DFS(s);


    return 0;
}
