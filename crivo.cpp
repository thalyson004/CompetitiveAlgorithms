#include <bits/stdc++.h>
using namespace std;

//BEGIN
struct Crivo{
   int len;
   vector<int> primes;
   vector<bool> isPrime;
   vector<int> smlDiv;

   Crivo(int _len){
      len = _len+1;
      isPrime = vector<bool>(len, true);
      smlDiv = vector<int>(len, 1);

      isPrime[0] = isPrime[1] = 0;

      for(int i = 2; i <len; i++){
         if( isPrime[i] ){
            primes.push_back(i);
            smlDiv[i] = i;
            for(int j = i+i; j < len; j+=i){
               isPrime[j]=0;
               smlDiv[j] = i;
            }
         }
      }
   }

   int size(){
      return primes.size();
   }
};
//END

main(){
   int maximo = 1000000;

   Crivo myCrivo(maximo);

   printf("Total de primos  ate %d = %d\n", maximo, myCrivo.size());

   return 0;
}
