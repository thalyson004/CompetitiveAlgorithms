#include <bits/stdc++.h>
using namespace std;
//BEGIN
namespace math{
   int64_t fat(int);
   int64_t ifat(int);
   int64_t inv(int64_t);
   int64_t fastExp(int64_t, int64_t);
   int64_t combination(int64_t, int64_t);

   int64_t MOD = 1000000007LL;
   vector<int64_t> factorial(1,1);
   vector<int64_t> ifactorial(1,1);

   int64_t fat(int x){
      while(factorial.size() <= x){
         factorial.push_back( (factorial.back()*factorial.size())%MOD  );
      }
      return factorial[x];
   }

   int64_t ifat(int x){
      fat(x);
      while(ifactorial.size() <= x){
         ifactorial.push_back( inv( fat(ifactorial.size()) ) );
      }
      return ifactorial[x];
   }


   int64_t fastExp(int64_t x, int64_t y){
      int64_t ans = 1;

      while(y){
         if(y&1LL) ans = (ans*x)%MOD;
         y/=2LL;
         x = (x*x)%MOD;
      }
      return ans;
   }

   int64_t inv(int64_t x){
      return fastExp(x, MOD-2LL);
   }

   /*WARNING: Using inv fuction many time can be your algorithm to much slow*/
   int64_t combination(int64_t n, int64_t k){
      if(n<k) return 0LL;
      return (((fat(n)*ifat(k))%MOD)*ifat(n-k))%MOD;
   }

   template<class T>
   T gcd(T a, T b){
      return __gcd(a,b);
   }

   template<class T>
   T lcm(T a, T b){
      return a*(b/__gcd(a,b));
   }

   /*WARNING: actually, this struct is pretty slow*/
   struct modInt{
      int64_t value;
      modInt(){
         value = 0;
      }
      modInt(int64_t _value){
         value = _value%MOD;
      }

      void operator += (int64_t x){
         value = (value + x)%MOD;
      }
      void operator -= (int64_t x){
         value = (value - x + MOD)%MOD;
      }
      void operator *= (int64_t x){
         value = (value * x)%MOD;
      }
      void operator /= (int64_t x){
         value = (value * inv(x))%MOD;
      }

      friend std::ostream& operator << (std::ostream &os, const modInt &x) {
         return os << x.value;
      }

      friend std::istream& operator >> (std::istream &is, modInt &x) {
         return is >> x.value;
      }
   };
}
//END

int main(){

   cout << math::fastExp(2,10) << endl;
   cout << math::combination(3,3) << endl;
   cout << math::combination(5,3) << endl;

   math::modInt ans;

   ans += 1000000;
   cout << ans << endl;
   ans *= 1000000;
   cout << ans << endl;

   cout << math::gcd(20, 15) << endl;
   cout << math::lcm(20, 15) << endl;
}

/*
6
1 2
2 3
3 5
4 6
5 4
*/
