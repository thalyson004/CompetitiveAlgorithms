#include <bits/stdc++.h>
using namespace std;

//BEGIN
struct SumArray{
   int len;
   vector<int> sum_array;

   SumArray(vector<int> &v){
      len = v.size();
      for(int i = 0; i < len; i++){
         sum_array.push_back( v[i] + query(i-1) );
      }
   }
   int query(int l, int r){
      if(l>r) swap(l,r);
      return query(r) - query(l-1);
   }

   int query(int r){
      if(r<0) return int(0);
      else if(r>=len) return sum_array[len-1];
      else return sum_array[r];
   }
};
//END

main(){
   printf("SumArray\n");
   vector<int> v;
   for(int i = 1; i <= 3; i++ ) v.push_back( i );
   SumArray sum(v);

   for(int i = 0; i < 3; i ++)
   for(int j = 0; j < 3; j ++)
      printf("%d - %d = %d\n",i,j,sum.query(i,j));

   return 0;
}
