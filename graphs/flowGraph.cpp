#include <bits/stdc++.h>
using namespace std;
//BEGIN
struct FlowGraph{
   int vertices;
   int source, sink;
   vector<vector<int>> edges;
   vector<vector<int>> residual;

   vector<int> &operator [] (int i){
      return edges[i];
   }

   FlowGraph(){
      source = 0;
      sink = 0;
      vertices=0;
   }

   FlowGraph(int _vertices){
      source = 0;
      sink = _vertices-1;
      vertices = _vertices;
      edges = vector<vector<int>>(vertices);
      residual = vector<vector<int>>(vertices, vector<int>(vertices));
   }

   void add_edge(int v, int u, int flow){
      edges[v].push_back(u);
      edges[u].push_back(v);
      residual[v][u] += flow;
   }

   int max_flow(){
      vector<vector<int>> cur = residual;
      int flow = 0;
      bool flag = true;
      while(flag){
         flag = false;

         vector<int> parent(vertices, -1);
         parent[source]=0;
         queue<int> bfs;
         bfs.push( source );

         while(bfs.size()){
            int v = bfs.front();
            bfs.pop();

            for(int u: edges[v]){
               if( cur[v][u]>0 and parent[u]==-1 ){
                  parent[u] = v;
                  bfs.push(u);
               }
            }
         }
         if( parent[sink]>0 ){
            flag = true;
            int min_flow = INT_MAX;
            int v = sink;
            while(v!=source){
               min_flow = min(min_flow, cur[ parent[v] ][v]);
               v = parent[v];
            }
            flow += min_flow;
            v = sink;
            while(v!=source){
               cur[ parent[v] ][v] -= min_flow;
               cur[v][parent[v]] += min_flow;
               v = parent[v];
            }
         }

      }

      return flow;
   }
};
//END
int main(){
   int N, M;
   scanf("%d %d", &N, &M);
   FlowGraph graph(N);

   for(int i= 0; i < M; i++){
      int u,v, flow;
      scanf("%d %d %d", &u, &v, &flow);
      graph.add_edge(u-1,v-1, flow);
   }

   printf("%d\n", graph.max_flow() );

}

/*
7 13
1 2 7
1 3 17
1 4 16
2 6 4
2 4 3
3 4 7
3 6 13
4 6 18
4 5 6
4 7 11
5 7 20
6 5 9
6 7 15
*/
