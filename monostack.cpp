#include <bits/stdc++.h>
using namespace std;

//BEGIN
namespace mono{

   template<class T>
   vector<int> prev(vector<T> &v, bool(*func)(T,T) ){
      int len = v.size();
      stack<T> mg;
      vector<int> ans(v.size(), -1);

      for(int i = 0; i < len; i++){
         while( mg.size() and func(mg.top(),v[i]) ) mg.pop();
         if( mg.size() ) ans[i] = mg.top();
         mg.push( i );
      }
      return ans;
   }

   template<class T>
   vector<int> next(vector<T> &v, bool(*func)(T,T) ){
      int len = v.size();
      stack<T> mg;
      vector<int> ans(v.size(), -1);

      for(int i = len-1; i >= 0; i--){
         while( mg.size() and func(mg.top(),v[i]) ) mg.pop();
         if( mg.size() ) ans[i] = mg.top();
         mg.push( i );
      }
      return ans;
   }

   template<class T>
   vector<int> prevGreater(vector<T> &v){
      return prev(v, [](T a, T b){ return a<=b;} );
   }

   template<class T>
   vector<int> prevGreaterOrEqual(vector<T> &v){
      return prev(v, [](T a, T b){ return a<b;} );
   }

   template<class T>
   vector<int> prevLess(vector<T> &v){
      return prev(v, [](T a, T b){ return a>=b;} );
   }

   template<class T>
   vector<int> prevLessOrEqual(vector<T> &v){
      return prev(v, [](T a, T b){ return a>b;} );
   }

   template<class T>
   vector<int> nextGreater(vector<T> &v){
      return next(v, [](T a, T b){ return a<=b;} );
   }

   template<class T>
   vector<int> nextGreaterOrEqual(vector<T> &v){
      return next(v, [](T a, T b){ return a<b;} );
   }

   template<class T>
   vector<int> nextLess(vector<T> &v){
      return next(v, [](T a, T b){ return a>=b;} );
   }

   template<class T>
   vector<int> nextLessOrEqual(vector<T> &v){
      return next(v, [](T a, T b){ return a>b;} );
   }
}
//END

//Main
int N, M, CASES;

main(){

}
