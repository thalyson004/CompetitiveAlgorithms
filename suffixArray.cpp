#include <bits/stdc++.h>
using namespace std;
//BEGIN
struct SuffixArray{
   int len;
   string s;
   vector<int> P;

   void mySort(vector< pair< pair<int,int> ,int> > &v){
      int len = v.size();

      {
         vector<int> ctn(len);
         for( auto &it: v ){
            ctn[ it.first.second ]++;
         }
         vector<int> start(len);
         for(int i = 1; i < len; i++) start[i] = start[i-1]+ctn[i-1];
         vector< pair< pair<int,int> ,int> > v_new(len);
         for( auto &it:v) {
            v_new[ start[ it.first.second ]++ ] = it;
         }
         v = v_new;
      }

      {
         vector<int> ctn(len);
         for( auto &it: v ){
            ctn[ it.first.first ]++;
         }
         vector<int> start(len);
         for(int i = 1; i < len; i++) start[i] = start[i-1]+ctn[i-1];
         vector< pair< pair<int,int> ,int> > v_new(len);
         for( auto &it:v) {
            v_new[ start[ it.first.first ]++ ] = it;
         }
         v = v_new;
      }
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
         vector< pair< pair<int,int> ,int> > v(len);
         for(int i = 0; i < len; i++)
            v[i] = {{level[i], level[  (i+(1<<k))%len ]}, i};

         mySort( v );

         for(int i = 0; i < len; i++) P[i] = v[i].second;
         level[ P[0] ] = 0;
         for(int i = 1; i < len; i++){
            level[ P[i] ] = level[ P[i-1] ] + (v[i].first > v[i-1].first);
         }
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
   s = "ababba";

   SuffixArray myArray(s.c_str());

   myArray.print();
}

/*
ababba
*/
