#include<iostream>
#include<map>
#include<vector>
#include<queue>

using namespace std;

class Graph
{
public:
    map<int,std::vector<int>> adjList;
    void addEdge(int node1,int node2,bool isBidirect);
    void bfs(int root);
};

void Graph::addEdge(int node1,int node2,bool isBidirect = true){
    adjList[node1].push_back(node2);
    if(isBidirect){
        adjList[node2].push_back(node1);
    }
}
void Graph::bfs(int root)
{
    std::queue<int> q;
    map<int,bool> visited;
    
    q.push(root);
    visited[root] = true;
    
    while(q.empty() == false){
        int node = q.front();
        cout<<node<<"  ";
        q.pop();
        
        for(int neighbour: adjList[node]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
    }
}
int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2,4);
    g.bfs(0);

    return 0;
}