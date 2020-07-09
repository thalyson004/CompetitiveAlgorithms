#include <bits/stdc++.h>
using namespace std;
//BEGIN
struct SuffixArray{
   int len;
   string s;
   vector<int> P;

   void mySort(vector< int > &p, vector<int> &level){

      vector<int> ctn(len);
      for( auto &it: level ){
         ctn[ it ]++;
      }
      vector<int> start(len);
      for(int i = 1; i < len; i++) start[i] = start[i-1]+ctn[i-1];
      vector< int > p_new(len);

      for( auto &it:p) {
         p_new[ start[ level[it] ]++ ] = it;
      }

      p = p_new;

   }

   SuffixArray(const string _s){
      s = _s+"$";
      len = s.size();

      P = vector<int>(len);
      vector<int> level = vector<int>(len);

      {
         vector< pair<char,int> > v(len);
         for(int i = 0; i < len; i++) v[i] = {s[i], i} ;
         sort( v.begin(), v.end() );

         for(int i = 0; i < len; i++) P[i] = v[i].second;
         level[ P[0] ] = 0;
         for(int i = 1; i < len; i++){
            P[i] = v[i].second;
            level[ P[i] ] = level[ P[i-1] ] + (v[i].first>v[i-1].first);
         }
      }

      for(int k = 0; (1<<(k)) < len; k++){

         for(int i = 0; i < len; i++)
            P[i] = (P[i] - (1<<k) + len)%len;

         mySort( P, level );
         vector<int> level_new(len);
         level_new[ P[0] ] = 0;
         for(int i = 1; i < len; i++){
            pair<int,int> prev = {level[P[i-1]], level[ (P[i-1] +(1<<k))%len ] };
            pair<int,int> now = {level[P[i]], level[ (P[i] +(1<<k))%len ] };
            level_new[ P[i] ] = level_new[ P[i-1] ] + (now>prev);
         }
         level = level_new;
      }
   }

   void print(){
      printf("--- My Array ---\n");
      for(int i = 0; i < len; i++){
         cout << P[i] << ' ' <<  (s.c_str() + P[i]) << '\n';
      }
   }
};
//END
int main(){
   string s;
   //s = "ababba";
   cin >> s;

   SuffixArray myArray(s.c_str());

   //myArray.print();
   vector<int> ans = myArray.P;
   for(int i: ans)printf("%d ", i);
   printf("\n");
}

/*
ababba
*/
