#include <bits/stdc++.h>
using namespace std;
//BEGIN
struct SuffixArray{
   int len;
   string s;
   vector<int> P;
   vector<int> pos;
   vector<int> lcp;

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

      pos = vector<int> (len);
      for(int i = 0; i < len; i++){
         pos[ P[i] ] = i;
      }

      lcp = vector<int> (len-1);
      int k = 0;
      for(int i = 0; i+1 < len; i++){
         int prev = P[ pos[ i ] - 1];
         while( s[i+k] == s[prev+k] ) k++;
         lcp[ pos[i]-1 ] = k--;
         k = max(k, int(0) );
      }
   }

   /*
   menor = 1
   maior = 0
   igual = -1
   */
   int compStr(int in, string &_s){
      for(int i = 0; i < _s.size(); i++){
         if( s[ (P[in]+i)%len ] != _s[i] ){
            return s[ (P[in]+i)%len ] < _s[i];
         }
      }

      return -1;
   }

   int first_match(string &_s){
      if( _s.size() > len ) return -1;
      int l = 0, r = len-1;

      while(l < r){
         int m = (l+r)/2;
         if( compStr(m, _s)==1 ){
            l = m+1;
         }else{
            r = m;
         }
      }
      return compStr(l, _s)==-1?l:-1;
   }

   int last_match(string &_s){
      if( _s.size() > len ) return -1;
      int l = 0, r = len-1;

      while(l < r){
         int m = (l+r+1)/2;
         if( compStr(m, _s) ){
            l = m;
         }else{
            r = m-1;
         }
      }
      return compStr(l, _s)==-1?l:-1;
   }

   int count_substr(string &_s){
      int l = first_match(_s);
      int r = last_match(_s);

      return l>=0?r-l+1:0;
   }

   int is_substr(string &_s){
      return first_match(_s) != -1;
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
   cin >> s;
   //s = "ababba";
   SuffixArray myArray(s.c_str());

   vector<int> ans = myArray.P;
   for(int i: ans)printf("%d ", i); printf("\n");

   ans = myArray.lcp;
   for(int i: ans)printf("%d ", i); printf("\n");


   return 0;
}

/*
ababba

6 5 0 2 4 1 3
0 1 2 0 2 1

Número de diferentes subsequências contíguas que aparecem pelo menos duas vezes na sequência
https://www.urionlinejudge.com.br/judge/pt/problems/view/1377
*/
