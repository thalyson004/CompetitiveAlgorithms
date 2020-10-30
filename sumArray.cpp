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
      //Is better zero than swap.
      //Probally less errors.
      if(l>r) int(0);
      return query(r) - query(l-1);
   }

   int query(int r){
      //If is less than 0, has no interval
      if(r<0) return int(0);
      //If is greater than N-1, has whole interval
      else if(r>=len) return sum_array[len-1];
      //Else, only between 0 and r
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
