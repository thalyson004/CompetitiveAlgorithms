#include <bits/stdc++.h>
using namespace std;

//BEGIN
/*Calc inversions to order an integer permutation interval*/
/*WARNING only for integer permutations (0 to N-1)*/
template<class Interator>
int64_t countInversions(Interator begin, Interator end){
   if(begin+1==end) return int64_t(0);

   int64_t ans = 0;
   int dist = distance(begin, end)/2;
   Interator mid = begin+dist;
   ans += countInversions(begin, mid);
   ans += countInversions(mid, end);

   Interator l = begin;
   Interator r = mid;

   vector<int> cur;
   while(l!=mid and r!=end){
      if(*l<*r){
         cur.push_back(*l);
         dist--;
         l++;
      }else{
         cur.push_back(*r);
         r++;
         ans+=dist;
      }
   }
   while(l!=mid){
      cur.push_back(*l);
      dist--;
      l++;
   }
   while(r!=end){
      cur.push_back(*r);
      r++;
      ans+=dist;
   }
   for(int i = 0; i < cur.size(); i++){
      *(begin+i) = cur[i];
   }
   return ans;
}
/*Calc inversions for transform a start vector to a target vector*/
template<class T>
int64_t countInversions(vector<T> &start, vector<T> &target){

   map<T,int> ids;
   vector<vector<int>> positions;
   for(int i = int(start.size())-1; i >= 0; i--){
      T value = start[i];
      if( ids.count( value )==0 ){
         int id = ids.size();
         ids[value] = id;
         positions.push_back( vector<int>() );
      }
      positions[ ids[value] ].push_back( i );
   }
   vector<int> order;
   for(int i = 0; i < target.size(); i++){
      int id = ids[ target[i] ];
      int pos = positions[id].back();
      positions[id].pop_back();
      order.push_back(pos);
   }
   return countInversions(order.begin(), order.end());
}
//END

//Main
int N;

main(){
   cin >> N;
   vector<char> v = vector<char>(N);
   for(auto &x:v)cin >> x;
   vector<char> rv = v;
   reverse(rv.begin(), rv.end());
   cout << countInversions(v, rv) << endl;


}
