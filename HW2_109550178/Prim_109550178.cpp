#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>       //use pair
#include <queue>         //use priority queue


using namespace std;

# define INF 0x3f3f3f3f
 
// iPair ==>  Integer Pair
typedef pair<int, int> iPair;
 
// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;     
    vector< pair<int, int> > *adj;
public:
    Graph(int V);  
    void addEdge(int u, int v, int w);
    void primMST();
};
 
// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new vector<iPair> [V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 
// Prints shortest paths from src to all other vertices
void Graph::primMST()
{
   
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
 
    int src = 0; // Taking vertex 0 as source
 
    vector<int> key(V, INF);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);
 
    pq.push(make_pair(0, src));
    key[src] = 0;
 
    /* Looping till priority queue becomes empty */
    while (!pq.empty())
    {
        int u = pq.top().second;    
          //Different key values for same vertex may exist in the priority queue.
        pq.pop(); 
          //The one with the least key value is always processed first.
          //Therefore, ignore the rest.
        if(inMST[u] == true){
            continue;
        }
       
        inMST[u] = true;  // Include vertex in MST
        // 'i' is used to get all adjacent vertices of a vertex
        vector< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;

            //  If v is not in MST and weight of (u,v) is smaller
            // than current key of v
            if (inMST[v] == false && key[v] > weight)
            {
                // Updating key of v
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }

    }
    int cost=0;
    // Print edges of MST using parent array
    for (int i = 1; i < V; ++i)
        cost += key[i];
    cout <<cost <<endl;
}
 

 int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int vernum,edgenum;
    cin >> vernum >> edgenum;
    Graph g(vernum);
    int start,end,weight;
    for(int i=0; i<edgenum; i++){
        cin >> start >> end >> weight;
        g.addEdge(start,end,weight);
    } 
    g.primMST();

    return 0;
}
