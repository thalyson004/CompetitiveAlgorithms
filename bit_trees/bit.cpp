#include <bits/stdc++.h>
using namespace std;

//BEGIN
struct PrefixSumBit{
   int len;
   vector<int> bit;

   /*1 to len*/
   PrefixSumBit(int _len): len(_len), bit(len+1){}

   /*LeastSignificantBit*/
   static int LSB(int value){
      return value & -value;
   }

   void update(int value, int id){
      while( id <= len ){
         bit[id]+=value;
         id += LSB(id);
      }
   }

   int query(int id){
      int ans = 0;
      while(id){
         ans += bit[id];
         id -= LSB(id);
      }
      return ans;
   }
};
struct PosfixSumBit : public PrefixSumBit{
   PosfixSumBit(int _len) : PrefixSumBit(_len){}

   int reverseIndex(int id){
      return len-id+1;
   }
   int query(int id){
      return PrefixSumBit::query(reverseIndex(id));
   }
   void update(int value, int id){
      PrefixSumBit::update(value, reverseIndex(id));
   }
};
//END

main(){
   printf("PrefixSum\n");
   PrefixSumBit pre(10);

   for(int i = 1; i <= 10; i++){
      pre.update(i, i);
   }
   for(int i = 1; i <= 10; i++){
      printf("%d - %d\n", pre.query(i), i );
   }

   printf("PosfixSum\n");
   PosfixSumBit pos(10);

   for(int i = 1; i <= 10; i++){
      pos.update(i, i);
   }
   for(int i = 1; i <= 10; i++){
      printf("%d - %d\n", pos.query(i), i );
   }

   return 0;
}
