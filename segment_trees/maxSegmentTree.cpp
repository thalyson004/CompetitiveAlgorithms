#include <bits/stdc++.h>
using namespace std;

//BEGIN
struct MaxSegmentTree {
   int len;
   int INF;
   vector<int> max_segment;

   vector<int> preSum;
   vector<int> posSum;
   vector<int> sum;

   vector<int> left;
   vector<int> right;
   int(*func)(int,int);

   int leftChild(int id){ return id*2+1; }
   int rightChild(int id){ return id*2+2; }

   void init(){
      max_segment = vector<int>(4*len);
      left = vector<int>(4*len);
      right = vector<int>(4*len);

      preSum = vector<int>(4*len);
      posSum = vector<int>(4*len);
      sum = vector<int>(4*len);

      setINF();
   }

   MaxSegmentTree( int _len, int(*_func)(int,int)=[](int x, int y){return max(x,y);} ){
      len = _len;
      func = _func ;
      init();
      build(0, 0, len-1);
   }

   template<class RandomIterator>
   MaxSegmentTree( RandomIterator begin, RandomIterator end, int(*_func)(int,int)=[](int x, int y){return max(x,y);} ){
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

   void updateNode(int id){
      sum[id] = sum[leftChild(id)] + sum[rightChild(id)];
      preSum[id] = func(preSum[leftChild(id)],
                        sum[leftChild(id)] + preSum[rightChild(id)] );
      posSum[id] = func(posSum[rightChild(id)],
                        sum[rightChild(id)] + posSum[leftChild(id)] );

      max_segment[id] = func(max_segment[leftChild(id)],
                             max_segment[rightChild(id)]);
      max_segment[id] = func(max_segment[id],
                             preSum[rightChild(id)]+posSum[leftChild(id)]);
   }

   template<class RandomIterator>
   void build(int id, int l, int r, RandomIterator begin){
      left[id]=l;
      right[id]=r;
      if(l!=r){
         int m = (l+r)/2;
         build( leftChild(id), l,  m, begin);
         build( rightChild(id), m+1,  r, begin);
         updateNode(id);
      }else{
         max_segment[id] = sum[id] = posSum[id] = preSum[id] = begin[l];
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

   int query(int id = 0){
      return max_segment[id];
   }

   void update(int value, int loc, int id = 0){
      if( left[id]>loc or right[id]<loc ){
         return;
      }else if( loc==left[id] and loc==right[id] ){
         max_segment[id] = sum[id] = posSum[id] = preSum[id] = value;
      }else{
         update( value, loc, leftChild(id));
         update( value, loc, rightChild(id));
         updateNode(id);
      }
   }

};
//END

//Main
int N, M, CASES;

main(){
   int v[] = {5, -4, 4, 3, -5};
   printf("MinSegmentTree\n");
   MaxSegmentTree myTree(v, v+5);
   cout << myTree.query() << endl;
   myTree.update(3, 4);
   cout << myTree.query() << endl;
   myTree.update(-1, 3);
   cout << myTree.query() << endl;

   vector<int> vv(v, v+5);
   printf("MinSegmentTree\n");
   myTree = MaxSegmentTree(vv.begin(), vv.end(), [](int x,int y){return min(x,y);});
   cout << myTree.query() << endl;
   myTree.update(3, 4);
   cout << myTree.query() << endl;
   myTree.update(-1, 3);
   cout << myTree.query() << endl;

}
