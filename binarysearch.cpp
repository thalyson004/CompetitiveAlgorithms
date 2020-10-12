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
   int position(T value, vector<T> &v){
      int l = 0, r = v.size();
      while(l<r){
         int m = (l+r)/2;
         if( v[m]<value ){
            l = m+1;
         }else{
            r = m;
         }
      }
      return l;
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

   /* 00000[1]111 */
   int firstPossible(int l, int r, bool(*possible)(int) ) {
      while(l<r){
         int m = (l+r)/2;
         if( possible(m) ){
            r = m;
         }else{
            l = m+1;
         }
      }
      return l;
   }
   /* 1111[1]0000 */
   int lastPossible(int l, int r, bool(*possible)(int) ) {
      while(l<r){
         int m = (l+r+1)/2;
         if( possible(m) ){
            l = m;
         }else{
            r = m-1;
         }
      }
      return l;
   }
}
//END

//Main
int N, M, CASES;
vector<int> v({1,3,4,5,7,8,11,15});

bool func1(int i){
   return v[i]>9;
}

bool func2(int i){
   return v[i]<=4;
}

main(){
   cout << binary::contain(2, v) << " " << binary::contain(8, v) << endl;
   cout << binary::firstGreater(2, v) << " " << binary::firstGreater(8, v) << endl;
   cout << binary::firstGreaterOrIgual(2, v) << " " << binary::firstGreaterOrIgual(8, v) << endl;
   cout << binary::firstPossible(0, v.size()-1, func1) << endl;
   cout << binary::lastPossible(0, v.size()-1, func2) << endl;
}
