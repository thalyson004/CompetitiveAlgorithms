#include <bits/stdc++.h>
using namespace std;
//BEGIN
namespace math{
   int64_t MOD = 1000000007LL;
   vector<int64_t> fatorial(1,1);

   int64_t fat(int x){
      while(fatorial.size() <= x){
         fatorial.push_back(  (fatorial.back()*fatorial.size())%MOD  );
      }
      return fatorial[x];
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

   int64_t combination(int64_t n, int64_t k){
      if(n<k) return 0LL;
      return (((fat(n)*inv(fat(k)))%MOD)*inv( fat(n-k) ))%MOD;
   }

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
}

/*
6
1 2
2 3
3 5
4 6
5 4
*/
