/*
   Problem name: -
   Difficulty level: -
   Techniques: -
   Hints: -
   Written by Thalyson
*/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define FF first.first
#define FS first.second
#define S second
#define SF second.first
#define SS second.second
#define ii pair<int,int>
#define iii pair<ii, int>
#define iiii pair<ii, ii>
#define viiii vector< iiii >
#define viii vector< iii >
#define vii vector< ii >
#define vi vector< int >
#define vvi vector<vector< int > >
#define int int64_t


#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define sortv(V) sort(all(V))
#define reversev(V) reverse(all(V))
#define uniquev(V) sortv(V),(V).erase(unique(all(V)),(V).end())
#define pb push_back


#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define debug(x) cout << #x << " is " << x << "\n";

// Trace dinâmico (parameter pack (c++11))
template<typename T>
void println(T a) { cout << a << "\n"; }
template<typename T, typename... Args>
void println(T a, Args... args) { cout << a << " "; println(args...); }

template<typename T>
void print(T a) { cout << a; }
template<typename T, typename... Args>
void print(T a, Args... args) { cout << a << " "; print(args...); }

template<typename T>
void printv(T a, string last="\n") {
    for(auto el: a)
      print(el, "");
    print(last);
}

template<typename T>
void scanv(T &a) {
    for(auto &el: a)
      cin >> el;
}


//Constants
#define EPS 1e-6
#define oo int(1LL<<60)
#define endl '\n'

//Directions ^>v<
const int dx4[4] = {-1, 0, 1, 0};
const int dy4[4] = {0, 1, 0, -1};

const int dx8[8] = {-1, -1, 0, 1, 1,  1,  0, -1};
const int dy8[8] = { 0,  1, 1, 1, 0, -1, -1, -1};

struct disjoint_set{
   int length;
   vector<int> leader;
   vector<int> group_size;
   vector<int> height;

   disjoint_set(){
      length = 0;
   }
   disjoint_set(int _len){
      length = _len;
      leader.resize(length);
      group_size.resize(length);
      height.resize(length);
      for(int i = 0; i < length; i++){
         leader[i]=i;
         group_size[i]=1;
      }
   }

   void update(int x, int y){
      x = query(x);
      y = query(y);
      if( x==y ) return;

      if( height[x]<height[y] ){
         swap(x,y);
      }else if(height[x]==height[y]){
         height[x]++;
      }

      group_size[ x ] += group_size[ y ];
      leader[ y ] = x;
   }

   bool query(int x, int y){
      return query(x)==query(y);
   }

   int query(int x){
      return x==leader[x]?(x):(leader[x] = query(leader[x]));
   }

   int size(int x){
      return group_size[ query(x) ];
   }
};


//Main
int N, M;

main(){
   std::ios::sync_with_stdio(false);
   cin.tie(0);
   cout << setprecision(9) << fixed;

   cin >> N >> M;
   disjoint_set dis(N);
   vector<int> mx(N), mn(N);
   for(int i = 0; i < N; i++){
      mx[i] = mn[i] = i+1;
   }

   while(M--){
      string op;
      int x,y;
      cin >> op >> x;
      x--;
      if(op == "union"){
         cin >> y;
         y--;

         x = dis.query(x);
         y = dis.query(y);
         if(x!=y){
            mx[x] = mx[y] = max(mx[y],mx[x]);
            mn[x] = mn[y] = min(mn[y],mn[x]);
            dis.update(x,y);
         }
      }else{
         x = dis.query(x);
         println(mn[x], mx[x], dis.group_size[x]);
      }
   }
}






















