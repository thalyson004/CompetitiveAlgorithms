#include <bits/stdc++.h>
using namespace std;

//BEGIN
struct SparseTable {
   int len;
   int log;
   int INF;
   int(*func)(int,int);
   vector< vector<int> > table;

   template<class RandomIterator>
   SparseTable( RandomIterator begin, RandomIterator end, int(*_func)(int,int)=[](int x, int y){return max(x,y);} ){
      len = distance(begin, end);
      func = _func;
      setINF();
      setLog();

      table = vector< vector<int> >(log+1, vector<int>(len, -INF) );
      for(int i = 0; i < len; i++){
         table[0][i] = begin[i];
      }

      for(int i = 1; i <= log; i++){
         for(int j = 0; j < len; j++){
            if( j+(1<<i)-1 < len ){
               table[i][j] = func(table[i-1][j], table[i-1][j+(1<<(i-1))]);
            }
         }
      }
   }

   void setINF(){
      INF = 1;
      while( INF < (INF<<2) ) INF = (INF<<2);
      INF = func(INF, -INF );
   }

   void setLog(){
      log = 1;
      while( (1<<log) < len  ) log++;
   }

   int query(int l, int r){
      if(l>r or l<0 or r>=len) return -INF;
      if(l==r)return table[0][l];
      int n = 0;
      while(l+(1<<(n+1)) <= r) n++;
      return func( table[n][l], table[n][r-(1<<n)+1] );
   }
};
//END

//Main
int N, M, CASES;

main(){
   int v[] = {1,5,6,3,2,9,7,3,2,6};
   //         0 1 2 3 4 5 6 7 8 9

   printf("SparseTable\n");
   SparseTable myTable(v, v+10);
   cout << myTable.query(0, 3) << endl;
   cout << myTable.query(3, 7) << endl;
   cout << myTable.query(1, 1) << endl;
   cout << myTable.query(6, 9) << endl;
}
