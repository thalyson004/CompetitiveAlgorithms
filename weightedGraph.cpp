#include <bits/stdc++.h>
using namespace std;
//BEGIN
struct WeightedGraph{
   int vertices;
   vector<vector<pair<int,int>>> edges;

   vector<pair<int,int>> &operator [] (int i){
      return edges[i];
   }

   WeightedGraph(){
      vertices=0;
   }

   WeightedGraph(int _vertices){
      vertices = _vertices;
      edges = vector<vector<pair<int,int>>>(vertices);
   }

   void add_bi_edge(int v, int u, int cost){
      edges[v].push_back({u, cost});
      edges[u].push_back({v, cost});
   }

   void add_edge(int v, int u, int cost){
      edges[v].push_back({u, cost});
   }

   vector<int> distanceFrom(int v){
      vector<int> dist(vertices, -1);
      dist[v] = 0;
      priority_queue< pair<int,int> > dj;
      dj.push( {0, v} );
      while(dj.size()){
         int v = dj.top().second;
         int total = -dj.top().first;
         dj.pop();
         if(total!=dist[v])continue;

         for(pair<int,int> edge: edges[v]){
            int u = edge.first;
            int weight = edge.second;

            if( dist[u]==-1 or dist[u]>total+weight ){
               dist[u] = total+weight;
               dj.push( {-dist[u], u} );
            }
         }
      }
      return dist;
   }

/*
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
   */
};
//END
int main(){
   int N;
   scanf("%d", &N);
   WeightedGraph graph(N);

   for(int i= 1; i < N; i++){
      int u,v, c;
      scanf("%d %d %d", &u, &v, &c);
      graph.add_bi_edge(u-1,v-1, c);
   }
   vector<int> dist = graph.distanceFrom(0);
   for(int i = 0; i< N; i++){
      printf("%d ", dist[i]);
   }
   printf("\n");

}

/*
6
1 2 4
2 3 2
3 5 5
4 6 2
5 4 3
*/
