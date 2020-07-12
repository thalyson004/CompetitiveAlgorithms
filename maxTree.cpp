#include <bits/stdc++.h>
using namespace std;

//BEGIN
struct MaxTree {
   int len;
   int INF = (1<<30);
   vector<int> tree;
   vector<int> left;
   vector<int> right;

   int leftChild(int id){ return id*2+1; }
   int rightChild(int id){ return id*2+2; }

   MaxTree( int _len ){
      len = _len;
      tree = vector<int>(4*len);
      left = vector<int>(4*len);
      right = vector<int>(4*len);

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

   int query(int ql, int qr, int id = 0){
      if( left[id]>qr or right[id]<ql ) return -INF;
      else if( ql<=left[id] and right[id]<=qr ) return tree[id];
      else return max( query(ql,qr,leftChild(id)), query(ql,qr,rightChild(id)));
   }

   int update(int value, int loc, int id = 0){
      if( left[id]>loc or right[id]<loc ){
         return -INF;
      }else if( loc==left[id] and loc==right[id] ){
         return tree[id] = value;
      }else{
         return tree[id] = max(
                  update(value, loc, leftChild(id)),
                  update(value, loc, rightChild(id))
         );
      }
   }

};
//END

//Main
int N, M, CASES;

main(){

   MaxTree myTree(10);

   cout << myTree.query(0, 9) << endl;
   myTree.update(5, 4);

   cout << myTree.query(1, 3) << endl;
   cout << myTree.query(3, 5) << endl;
   cout << myTree.query(5, 9) << endl;
}
