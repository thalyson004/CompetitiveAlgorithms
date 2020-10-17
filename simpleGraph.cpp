#include <bits/stdc++.h>
using namespace std;
//BEGIN
struct SimpleGraph{
   int vertices;
   vector<vector<int>> edges;

   vector<int> &operator [] (int i){
      return edges[i];
   }

   SimpleGraph(){
      vertices=0;
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

   int longestVerticeFrom(int v){
      vector<int> distA = distanceFrom(v);
      int longest = 0;
      for(int i = 0; i < vertices; i++){
         if(  distA[longest] < distA[i] )
            longest = i;
      }
      return longest;
   }

   int longestDistanceFrom(int v){
      vector<int> distA = distanceFrom(v);
      int longest = 0;
      for(int i = 0; i < vertices; i++){
         if(  distA[longest] < distA[i] )
            longest = i;
      }
      return distA[longest];
   }

   int diameter(){
      int longest = longestVerticeFrom(0);
      return longestDistanceFrom(longest);
   }

   SimpleGraph transpose(){
      SimpleGraph ans(vertices);
      for(int v = 0; v < vertices; v++){
         for(int u:edges[v])
            ans.add_edge(u,v);
      }
      return ans;
   }

   void toposort(int v, vector<int> &order, vector<bool> &mark){
      mark[v]=1;
      for(int u: edges[v]){
         if(!mark[u])
            toposort(u, order, mark);
      }
      order.push_back(v);
   }

   vector<int> toposort(){
      vector<int> order;
      vector<bool> mark(vertices);
      for(int i = 0; i < vertices; i++ ){
         if(!mark[i])
            toposort(i, order, mark);
      }
      return order;
   }

   vector<int> scc(){
      vector<int> comp(vertices);
      vector<int> order = toposort();
      SimpleGraph T = transpose();

      int cur = 0;
      while(order.size()){
         int v = order.back();
         order.pop_back();
         if(comp[v])continue;
         queue<int> bfs;
         bfs.push(v);
         comp[v] = ++cur;
         while(bfs.size()){
            v = bfs.front();
            bfs.pop();
            for(int u:T[v]){
               if(!comp[u]){
                  comp[u]=cur;
                  bfs.push(u);
               }
            }
         }
      }
      return comp;
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
