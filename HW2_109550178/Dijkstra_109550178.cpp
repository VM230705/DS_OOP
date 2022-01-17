#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>       //use pair
#include <unordered_set>     // 由於unordered_set容器不允許存儲重複的元素，因此該功能通常用於檢查容器中是否存在元素。如果元素存在於容器中，則該函數返回1，否則返回0。


#define infi 1000000000
using namespace std;
 
// Class of the node
class Node {
public:
    int vertexNumber;
 
    // Adjacency list that shows the
    // vertexNumber of child vertex
    // and the weight of the edge
    vector< pair<int, int> > children;
    Node(int vertexNumber)
    {
        this->vertexNumber = vertexNumber;
    }
 
    // Function to add the child for
    // the given node
    void add_child(int vNumber, int length)
    {
        pair<int, int> p;
        p.first = vNumber;
        p.second = length;
        children.push_back(p);
    }
};
 

vector<int> dijkstraDist(vector<Node*> g, int s, vector<int>& path)
{

    vector<int> dist(g.size());
 
    // Boolean array that shows
    // whether the vertex 'i'
    // is visited or not
    bool visited[g.size()];
    for (int i = 0; i < g.size(); i++) {
        visited[i] = false;
        path[i] = -1;
        dist[i] = infi;
    }
    dist[s] = 0;
    path[s] = -1;
    int current = s;
 
    unordered_set<int> sett;
    while (true) {
 
        // Mark current as visited
        visited[current] = true;
        for (int i = 0; i < g[current]->children.size();i++) {
            int v = g[current]->children[i].first;
            if (visited[v])
                continue;
 
            sett.insert(v);
            int alt = dist[current] + g[current]->children[i].second;
 
            if (alt < dist[v]) {
                dist[v] = alt;
                path[v] = current;
            }
        }
        sett.erase(current);
        if (sett.empty())
            break;
 
        // The new current
        int minDist = infi;
        int index = 0;
 
        // Loop to update the distance
        // of the vertices of the graph
        for (int a: sett) {
            if (dist[a] < minDist) {
                minDist = dist[a];
                index = a;
            }
        }
        current = index;
    }
    return dist;
}
 
// Function to print the path
// from the source vertex to
// the destination vertex
void printPath(vector<int> path, int i, int s)
{
    if (i != s) {
 
        // Condition to check if
        // there is no path between
        // the vertices
        if (path[i] == -1) {
            cout << "Path not found!!";
            return;
        }
        printPath(path, path[i], s);
        cout << path[i] << " ";
    }
}
 
// Driver Code
int main()
{
    vector<Node*> v;
    int vernum,edgenum,source,target;
    cin >> vernum >> edgenum >> source >> target;

    // Loop to create the nodes
    for (int i = 0; i < vernum; i++) {
        Node* a = new Node(i);
        v.push_back(a);
    }
 
    // Creating directed
    // weighted edges
    for(int i=0; i<edgenum ;i++){
        int start,end,weight;
        cin >> start >> end >> weight;
        v[start]->add_child(end,weight);
    }
 
    vector<int> path(v.size());
    vector<int> dist = dijkstraDist(v, source, path);
    
    //cout << "target distance: " << dist[target] << endl;
    cout <<dist[target] <<endl;
    //printPath(path,target,source);
    // Loop to print the distance of
    // every node from source vertex

    /*
    for (int i = 0; i < dist.size(); i++) {
        if (dist[i] == infi) {
            cout << i << " and " << source
                 << " are not connected"
                 << endl;
            continue;
        }
        cout << "Distance of " << i
             << "th vertex from source vertex "
             << source << " is: "
             << dist[i] << endl;
    }
    */
    return 0;
}