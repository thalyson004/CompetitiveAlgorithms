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

   template<class T>
   MaxTree( T *begin, T *end ){
      len = distance(begin, end);
      tree = vector<int>(4*len);
      left = vector<int>(4*len);
      right = vector<int>(4*len);
      build(0, 0, len-1, begin);
   }

   template<class T>
   int build(int id, int l, int r, T *begin){
      left[id]=l;
      right[id]=r;
      if(l!=r){
         int m = (l+r)/2;
         return tree[id] = max(
                        build( leftChild(id), l,  m, begin),
                        build( rightChild(id), m+1,  r, begin)
                     );
      }else{
         return tree[id] = begin[l];
      }
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
   int v[] = {1,5,6,3,2,9,7,3,2,6};
   //         0 1 2 3 4 5 6 7 8 9
   MaxTree myTree(v, v+10);

   cout << myTree.query(0, 3) << endl;
   cout << myTree.query(3, 7) << endl;
   cout << myTree.query(1, 1) << endl;
   cout << myTree.query(0, 9) << endl;
}
