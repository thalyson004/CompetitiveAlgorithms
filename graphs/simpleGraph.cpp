#include <bits/stdc++.h>
#include "simpleGraph.h"

using namespace std;

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
