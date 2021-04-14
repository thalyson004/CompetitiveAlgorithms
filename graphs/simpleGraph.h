#ifndef SIMPLE_GRAPH
#define SIMPLE_GRAPH

struct SimpleGraph{
   int vertices;
   std::vector<std::vector<int>> edges;

   std::vector<int> &operator [] (int i){
      return edges[i];
   }

   SimpleGraph(){
      vertices=0;
   }

   SimpleGraph(int _vertices){
      vertices = _vertices;
      edges = std::vector<std::vector<int>>(vertices);
   }

   void add_bi_edge(int v, int u){
      edges[v].push_back(u);
      edges[u].push_back(v);
   }

   void add_edge(int v, int u){
      edges[v].push_back(u);
   }

   std::vector<int> distanceFrom(int v){
      std::vector<int> dist(vertices, -1);
      dist[v] = 0;
      std::queue<int> bfs;
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

   std::vector<int> distanceFrom(std::vector<int> vs){
      std::vector<int> dist(vertices, -1);
      for(int v: vs) dist[v] = 0;

      std::queue<int> bfs;
      for(int v: vs) bfs.push( v );

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
      std::vector<int> distA = distanceFrom(v);
      int longest = 0;
      for(int i = 0; i < vertices; i++){
         if(  distA[longest] < distA[i] )
            longest = i;
      }
      return longest;
   }

   int longestDistanceFrom(int v){
      std::vector<int> distA = distanceFrom(v);
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

   void toposort(int v, std::vector<int> &order, std::vector<bool> &mark){
      mark[v]=1;
      for(int u: edges[v]){
         if(!mark[u])
            toposort(u, order, mark);
      }
      order.push_back(v);
   }

   std::vector<int> toposort(){
      std::vector<int> order;
      std::vector<bool> mark(vertices);
      for(int i = 0; i < vertices; i++ ){
         if(!mark[i])
            toposort(i, order, mark);
      }
      return order;
   }

   std::vector<int> scc(){
      std::vector<int> comp(vertices);
      std::vector<int> order = toposort();
      SimpleGraph T = transpose();

      int cur = 0;
      while(order.size()){
         int v = order.back();
         order.pop_back();
         if(comp[v])continue;
         std::queue<int> bfs;
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

#endif
