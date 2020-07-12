#include <bits/stdc++.h>
using namespace std;
//BEGIN
struct SimpleGraph{
   int vertices;
   vector<vector<int>> edges;

   vector<int> &operator [] (int i){
      return edges[i];
   }

   SimpleGraph(int _vertices){
      vertices = _vertices;
      edges = vector<vector<int>>(vertices);
   }

   void add_bi_edge(int v, int u){
      edges[v].push_back(u);
      edges[u].push_back(v);
   }

   void add_edge(int v, int u){
      edges[v].push_back(u);
   }

   vector<int> distanceFrom(int v){
      vector<int> dist(vertices, -1);
      dist[v] = 0;
      queue<int> bfs;
      bfs.push( v );
      while(bfs.size()){
         int v = bfs.front();
         bfs.pop();

         for(int u: edges[v]){
            if( dist[u]==-1 ){
               dist[u] = dist[v]+1;
               bfs.push( u );
            }
         }
      }
      return dist;
   }
};
//END
int main(){
   int N;
   scanf("%d", &N);
   SimpleGraph graph(N);

   for(int i= 1; i < N; i++){
      int u,v;
      scanf("%d %d", &u, &v);
      graph.add_bi_edge(u-1,v-1);
   }
   vector<int> dist = graph.distanceFrom(0);
   int cur = 0;
   for(int d: dist) cur += d%2;

   printf("%s\n", cur*2==N?"Y":"N");

   for(int i = 0; i < N; i++){
      printf("(%d) - %d:", int(graph[i].size()), i );
      for(int j=0; j < graph[i].size(); j++){
         printf(" %d", graph[i][j]);
      }
      printf("\n");
   }

}

/*
6
1 2
2 3
3 5
4 6
5 4
*/
