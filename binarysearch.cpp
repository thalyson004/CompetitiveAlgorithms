#include <bits/stdc++.h>
using namespace std;

//BEGIN
namespace binary{
   template<class T>
   bool contain(T value, vector<T> &v){
      int l = 0, r = v.size();
      while(l<r){
         int m = (l+r)/2;
         if( v[m]<value ){
            l = m+1;
         }else{
            r = m;
         }
      }
      return l!=v.size() and v[l]==value;
   }

   template<class T>
   int firstGreater(T value, vector<T> &v){
      int l = 0, r = v.size();
      while(l<r){
         int m = (l+r)/2;
         if( v[m]>value ){
            r = m;
         }else{
            l = m+1;
         }
      }

      return l;
   }

   template<class T>
   int firstGreaterOrIgual(T value, vector<T> &v){
      int l = 0, r = v.size();
      while(l<r){
         int m = (l+r)/2;
         if( v[m]>=value ){
            r = m;
         }else{
            l = m+1;
         }
      }
      return l;
   }
}
//END

//Main
int N, M, CASES;

main(){
   vector<int> v({1,3,4,5,7,8,11,15});

   cout << binary::contain(2, v) << " " << binary::contain(8, v) << endl;
   cout << binary::firstGreater(2, v) << " " << binary::firstGreater(8, v) << endl;
   cout << binary::firstGreaterOrIgual(2, v) << " " << binary::firstGreaterOrIgual(8, v) << endl;
}
