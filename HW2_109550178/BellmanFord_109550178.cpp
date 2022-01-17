#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define INF 0x3f3f3f3f 
using namespace std;

struct Edge{
    int start;
    int weight;
    int end;
};

class Graph{
public:
    int vernum;
    int edgenum;
    Edge* edge;
    Graph(){};
    Graph(int vernum,int edgenum){
        this->vernum = vernum;
        this->edgenum = edgenum;
    }
};

Graph* createGraph(int vernum, int edgenum){
    
    Graph* graph = new Graph;
    graph->vernum = vernum;
    graph->edgenum = edgenum;
    graph->edge = new Edge[edgenum];
    
    return graph;
}

void BellmanFord(Graph* graph,int source, int target){
    int V = graph->vernum;
    int E = graph->edgenum;
    int dist[V];

//Initialize
    for(int i=0; i<V; i++){
        dist[i] = INF;
    }
    dist[source] = 0;

//Iteration
    for(int i=0; i<V-1; i++){
        for(int j=0; j<E; j++){
            int u = graph->edge[j].start;
            int v = graph->edge[j].end;
            int weight = graph->edge[j].weight;

            if(dist[u] != INF && dist[u] + weight < dist[v]){
                dist[v] = dist[u] + weight;
            }
        }
    }

//Check negative cycle
    for(int i=0; i<E; i++){
        int u = graph->edge[i].start;
        int v = graph->edge[i].end;
        int weight = graph->edge[i].weight;

        if(dist[u] != INF && dist[u] + weight < dist[v]){
            cout << "Negative loop detected!" <<endl;
            return;
        }
    }

    cout << dist[target] << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int vernum,edgenum,source,target;
    cin >> vernum >> edgenum >> source >> target;
    Graph* graph = createGraph(vernum, edgenum);

    // Creating directed
    // weighted edges
    for(int i=0; i<edgenum ;i++){
        int start,end,weight;
        cin >> start >> end >> weight;

        graph->edge[i].start = start;
        graph->edge[i].end = end;
        graph->edge[i].weight = weight;
    }

    BellmanFord(graph, source, target);
    
    return 0;
}
