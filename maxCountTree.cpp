#include <bits/stdc++.h>
using namespace std;

//BEGIN
struct MaxCountTree {
   int len;
   int INF;
   vector<int> max_value;
   vector<int> occ;
   vector<int> left;
   vector<int> right;
   int(*func)(int,int);

   int leftChild(int id){ return id*2+1; }
   int rightChild(int id){ return id*2+2; }


   void init(){
      max_value = vector<int>(4*len);
      left = vector<int>(4*len);
      right = vector<int>(4*len);
      occ = vector<int>(4*len);
      setINF();
   }
   MaxCountTree( int _len, int(*_func)(int,int)=[](int x, int y){return max(x,y);} ){
      len = _len;
      func = _func;
      init();
      build(0, 0, len-1);
   }

   template<class RandomIterator>
   MaxCountTree( RandomIterator begin, RandomIterator end, int(*_func)(int,int)=[](int x, int y){return max(x,y);} ){
      len = distance(begin, end);
      func = _func;
      init();
      build(0, 0, len-1, begin);
   }

   void setINF(){
      INF = 1;
      while( INF < (INF<<2) ) INF = (INF<<2);
      INF = func(INF, -INF );
   }

   template<class RandomIterator>
   int build(int id, int l, int r, RandomIterator begin){
      left[id]=l;
      right[id]=r;
      if(l!=r){
         int m = (l+r)/2;
         max_value[id] = func(
                        build( leftChild(id), l,  m, begin),
                        build( rightChild(id), m+1,  r, begin)
                     );
         occ[id] = (max_value[id]==max_value[leftChild(id)]?occ[leftChild(id)]:0) +
                  (max_value[id]==max_value[rightChild(id)]?occ[rightChild(id)]:0);
         return max_value[id];
      }else{
         occ[id] = 1;
         return max_value[id] = begin[l];
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
      max_value[id] = 0;
      occ[id] = l-r+1;
   }

   pair<int,int> query(int ql, int qr, int id = 0){
      if( left[id]>qr or right[id]<ql ) return {-INF, 0};
      else if( ql<=left[id] and right[id]<=qr ) return {max_value[id], occ[id]};
      else {
         pair<int,int> q1 = query(ql,qr,leftChild(id));
         pair<int,int> q2 = query(ql,qr,rightChild(id));
         int value=func(q1.first,q2.first);
         int cc = (value==q1.first?q1.second:0) +
                  (value==q2.first?q2.second:0);
         return {value, cc};
      }
   }

   int update(int value, int loc, int id = 0){
      if( left[id]>loc or right[id]<loc ){
         return max_value[id];
      }else if( loc==left[id] and loc==right[id] ){
         return max_value[id] = value;
      }else{
         max_value[id] = func(
                  update(value, loc, leftChild(id)),
                  update(value, loc, rightChild(id))
         );
         occ[id] = (max_value[id]==max_value[leftChild(id)]?occ[leftChild(id)]:0) +
                   (max_value[id]==max_value[rightChild(id)]?occ[rightChild(id)]:0);
         return max_value[id];
      }
   }

};
//END

//Main
int N, M, CASES;

main(){
   int v[] = {1,1,9,9,1,9,1,9,1,9};
   //         0 1 2 3 4 5 6 7 8 9
   printf("MaxTree\n");
   MaxCountTree myTree(v, v+10);
   cout << myTree.query(0, 3).first << " " << myTree.query(0, 3).second << endl;
   cout << myTree.query(3, 7).first << " " << myTree.query(3, 7).second << endl;
   cout << myTree.query(1, 1).first << " " << myTree.query(1, 1).second << endl;
   cout << myTree.query(6, 9).first << " " << myTree.query(6, 9).second << endl;

   vector<int> vv(v, v+10);
   printf("MinTree\n");
   myTree = MaxCountTree(vv.begin(), vv.end(), [](int x,int y){return min(x,y);});
   cout << myTree.query(0, 3).first << " " << myTree.query(0, 3).second << endl;
   cout << myTree.query(3, 7).first << " " << myTree.query(3, 7).second << endl;
   cout << myTree.query(1, 1).first << " " << myTree.query(1, 1).second << endl;
   cout << myTree.query(6, 9).first << " " << myTree.query(6, 9).second << endl;
}
