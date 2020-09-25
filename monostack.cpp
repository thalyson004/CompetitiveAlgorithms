#include <bits/stdc++.h>
using namespace std;

//BEGIN
namespace mono{

   template<class T>
   vector<int> monoPrev(vector<T> &v, bool(*func)(T,T) ){
      int len = v.size();
      stack<T> mg;
      vector<int> ans(v.size(), -1);

      for(int i = 0; i < len; i++){
         while( mg.size() and func(v[mg.top()],v[i]) ) mg.pop();
         if( mg.size() ) ans[i] = mg.top();
         mg.push( i );
      }
      return ans;
   }

   template<class T>
   vector<int> monoNext(vector<T> &v, bool(*func)(T,T) ){
      int len = v.size();
      stack<T> mg;
      vector<int> ans(v.size(), -1);

      for(int i = len-1; i >= 0; i--){
         while( mg.size() and func(v[mg.top()],v[i]) ) mg.pop();
         if( mg.size() ) ans[i] = mg.top();
         mg.push( i );
      }
      return ans;
   }

   template<class T>
   vector<int> prevGreater(vector<T> &v){
      bool (*actual)(T,T) = [](T a, T b){ return a<=b; };
      return monoPrev(v, actual );
   }

   template<class T>
   vector<int> prevGreaterOrEqual(vector<T> &v){
      bool (*actual)(T,T) = [](T a, T b){ return a<b; };
      return monoPrev(v, actual );
   }

   template<class T>
   vector<int> prevLess(vector<T> &v){
      bool (*actual)(T,T) = [](T a, T b){ return a>=b; };
      return monoPrev(v, actual );
   }

   template<class T>
   vector<int> prevLessOrEqual(vector<T> &v){
      bool (*actual)(T,T) = [](T a, T b){ return a>b; };
      return monoPrev(v, actual );
   }

   template<class T>
   vector<int> nextGreater(vector<T> &v){
      bool (*actual)(T,T) = [](T a, T b){ return a<=b; };
      return monoNext(v, actual);
   }

   template<class T>
   vector<int> nextGreaterOrEqual(vector<T> &v){
      bool (*actual)(T,T) = [](T a, T b){ return a<b; };
      return monoNext(v, actual );
   }

   template<class T>
   vector<int> nextLess(vector<T> &v){
      bool (*actual)(T,T) = [](T a, T b){ return a>=b; };
      return monoNext(v, actual );
   }

   template<class T>
   vector<int> nextLessOrEqual(vector<T> &v){
      bool (*actual)(T,T) = [](T a, T b){ return a>b;} ;
      return monoNext(v, actual );
   }
}
//END

//Main
int N, M, CASES;

main(){
   vector<int> v({2,45,6,4,3,1,3,6,8,9,3});

   vector<int> ng = mono::nextGreater(v);
}
