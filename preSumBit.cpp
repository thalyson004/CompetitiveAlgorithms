#include <bits/stdc++.h>
using namespace std;

//BEGIN
struct PrefixSumBit{
   int len;
   vector<int> bit;

   /*1 to len*/
   PrefixSumBit(int _len){
      len = _len;
      bit = vector<int>(len+1);
   }
   /*LeastSignificantBit*/
   static int LSB(int value){
      return value & -value;
   }

   void add(int value, int id){
      while( id <= len ){
         bit[id]+=value;
         id += LSB(id);
      }
   }

   int preSum(int id){
      int ans = 0;
      while(id){
         ans += bit[id];
         id -= LSB(id);
      }
      return ans;
   }
};
//END

main(){
   PrefixSumBit bit(10);

   for(int i = 1; i <= 10; i++){
      bit.add(i, i);
   }
   printf("Chegou aqui\n");
   for(int i = 1; i <= 10; i++){
      printf("%d - %d\n", bit.preSum(i), i );
   }

   return 0;
}

/*
abacaba
6
4 7
1 2
1 1
3 4
5 7
1 3


N�mero de diferentes subsequ�ncias cont�guas que aparecem pelo menos duas vezes na sequ�ncia
https://www.urionlinejudge.com.br/judge/pt/problems/view/1377
*/
