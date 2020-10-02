/*
Following are the detailed steps.

Input: Graph and a source vertex src
Output: Shortest distance to all vertices from src. If there is a negative weight cycle, then shortest distances are not calculated, negative weight cycle is reported.

1) This step initializes distances from the source to all vertices as infinite and distance to the source itself as 0. Create an array dist[] of size |V| with all values as infinite except dist[src] where src is source vertex.

2) This step calculates shortest distances. Do following |V|-1 times where |V| is the number of vertices in given graph.
…..a) Do following for each edge u-v
………………If dist[v] > dist[u] + weight of edge uv, then update dist[v]
………………….dist[v] = dist[u] + weight of edge uv

3) This step reports if there is a negative weight cycle in graph. Do following for each edge u-v
……If dist[v] > dist[u] + weight of edge uv, then “Graph contains negative weight cycle”
The idea of step 3 is, step 2 guarantees the shortest distances if the graph doesn’t contain a negative weight cycle. If we iterate through all edges one more time and get a shorter path for any vertex, then there is a negative weight cycle
*/

#include <iostream>
#include <list>
#include <queue>
#include <map>
#define inf 1e9
using namespace std;

class Edge {
public:
     int src, dest, weight;
};

class Graph {
	int v, e;
	Edge *edge;

public:
	Graph(int v, int e) {
		this->v = v;
    this->e = e;
		edge = new Edge[e];
	}

	void addEdge(int u, int v, int w,int count, bool bidir = true) {
		edge[count].src = u;
    edge[count].dest = v;
    edge[count].weight = w;
	}

     void print() {
          for(int i=0;i<e;i++) {
               cout<<edge[i].src<<" "<<edge[i].dest<<" "<<edge[i].weight<<endl;;
          }
     }

     void BellmanFord(int src) {
          int distance[v];
          for(int i=0;i<v;i++) {
               if(i==src)
                    distance[i] = 0;
               else
                    distance[i] = inf;
          }
          for(int i=1;i<=this->v-1;i++) {
               for(int j=0;j<this->e;j++) {
                    int src = edge[j].src;
                    int dest = edge[j].dest;
                    int wt = edge[j].weight;
                    if(distance[src] != inf and distance[src]+wt < distance[dest]) {
                         distance[dest] = distance[src] + wt;
                    }
               }
          }

          // For negative weight cycle
          for (int i = 0; i < e; i++) { 
             int src = edge[i].src; 
             int dest = edge[i].dest; 
             int wt = edge[i].weight; 
             if (distance[src] != inf && distance[src] + wt < distance[dest]) {
                 printf("Graph contains negative weight cycle from %d to %d", src, dest); 
                 return;
            }
          } 

          // print distance
          for (int i = 0; i < v; ++i) 
               printf("%d - %d\n", i, distance[i]); 
          return;
 

};
    }
int main(int argc, char const *argv[])
{
     int n, e;
     cin>>n>>e;
	Graph g(n, e);
	for(int i=0;i<e;i++) {
          int u, v, w;
          cin>>u>>v>>w;
          g.addEdge(u, v, w, i);
     }
     // g.print();
     g.BellmanFord(0);
	return 0;
}
