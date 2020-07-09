#include <bits/stdc++.h>
using namespace std;
//BEGIN
struct SuffixArray{
   int len;
   string s;
   vector<int> P;

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
         sort( v.begin(), v.end() );

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
