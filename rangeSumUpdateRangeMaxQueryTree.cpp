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
#define int long long

#define sz(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define pb push_back
#define FOR(v, i, l) for(int v = i; v < (int)l; ++v)
#define REP(v, l) FOR(v, 0, l)

#define EPS 1e-6
#define oo (1LL<<60)
#define MAX 1000000000000000000LL
#define MOD 1000000007LL
#define debug(x) cout << #x << " is " << x << "\n";

const int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[8] = {2, -2, 2, -2, 1, -1, 1, -2};

//Classes
template<class T>struct Matrix{   int rows;   int columns;   vector< vector<T> > grid;   Matrix(int _rows, int _columns){      rows = _rows;      columns = _columns;      grid = vector< vector<T> >(rows, vector<T>(columns));   }   bool inside(int row, int column){      return row>=0 and row<rows and column>=0 and column<columns;   }   vector<T>& operator [] (int row){      return grid[row];   }   void print(){      for(int i = 0; i < rows; i++){         for(int j = 0; j < columns; j++){            cout << grid[i][j] << ' ';         }         printf("\n");      }   }};

//BEGIN
struct rangeSumUpdateRangeMaxQueryTree {
   int len;
   vector<int> great;
   vector<int> left;
   vector<int> right;
   vector<int> lazy;

   int leftChild(int id){ return id*2+1; }
   int rightChild(int id){ return id*2+2; }
   int elements(int id){ return right[id]-left[id]+1; }

   rangeSumUpdateRangeMaxQueryTree(int _len){
      len = _len;
      great = vector<int>(4*len);
      left = vector<int>(4*len);
      right = vector<int>(4*len);
      lazy = vector<int>(4*len);
      build(0, 0, len-1);
   }

   void build(int id, int l, int r){
      left[id]=l;
      right[id]=r;
      if(l!=r){
         int m = (l+r)/2;
         build( leftChild(id), l,  m);
         build( rightChild(id), m+1,  r);
      }
   }

   void push(int id){
      if( lazy[id]==0 ) return;
      great[id] += lazy[id];
      if(left[id]!=right[id]){
         lazy[ leftChild(id) ] += lazy[id];
         lazy[ rightChild(id) ] += lazy[id];
      }
      lazy[id] = 0;
   }

   int query(int ql, int qr, int id = 0){
      push(id);
      if( left[id]>qr or right[id]<ql ) return -(oo);
      else if( ql<=left[id] and right[id]<=qr ) return great[id];
      else return max( query(ql,qr,leftChild(id)), query(ql,qr,rightChild(id)));
   }

   int update(int value, int ql, int qr, int id = 0){
      push(id);
      if( left[id]>qr or right[id]<ql ){
      }else if( ql<=left[id] and right[id]<=qr ){
         lazy[id] += value;
         push(id);
      }else{
         great[id] = max(
                  update(value, ql,qr, leftChild(id)),
                  update(value, ql,qr, rightChild(id))
         );
      }
      return great[id];

   }

};
//END

//Main
int N, M, K, L, R, J, P, CASES;
int A,B,C;

main(){
   scanf("%lld", &CASES);
   while(CASES--){
      scanf("%lld %lld", &N, &M);
      rangeSumUpdateRangeMaxQueryTree myTree(N);

      while(M--){
         int op, l, r;
         scanf("%lld", &op);
         scanf("%lld %lld", &l, &r);
         if(op==1){
            l--; r--;
            printf("%lld\n", myTree.query(l, r));
         }else{
            int v;
            scanf("%lld", &v);
            l--; r--;
            myTree.update(v, l, r);
         }
      }
   }
}

/*
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8
0 5 7 14
1 4 8
*/
