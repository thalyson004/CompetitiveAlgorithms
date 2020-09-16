#include <bits/stdc++.h>
using namespace std;

//BEGIN
struct BitTrieNode{
   BitTrieNode *child[2];
   int len;

   BitTrieNode(){
      child[0] = child[1] = NULL;
      len = 0;
   }
};
struct BitTrie {
   BitTrieNode *root;

   BitTrie(){
      root = new BitTrieNode();
   }

   void addNumber(int number){
      BitTrieNode *cur = root;
      cur->len++;
      for(int b = 30; b >= 0; b--){
         if( cur->child[ !!(number&(1<<b)) ] == NULL ){
            cur->child[ !!(number&(1<<b)) ] = new BitTrieNode();
         }
         cur=cur->child[ !!(number&(1<<b)) ];
      }
   }

   int maxXor(int number){
      BitTrieNode *cur = root;
      int ans = 0;
      for(int b = 30; b >= 0; b--){
         if(cur==NULL){
            break;
         }
         if( cur->child[ !(number&(1<<b)) ] != NULL ){
            ans += (1<<b);
            cur = cur->child[ !(number&(1<<b)) ];
         }else{
            cur = cur->child[ !!(number&(1<<b)) ];
         }
      }
      return ans;
   }
};
//END

//Main
int N, M, CASES;

main(){
   int v[] = {3, 10, 5, 25, 2, 8};

   BitTrie myTrie;
   for(int i = 0; i < 6; i++){
      myTrie.addNumber( v[i] );
   }

   int ans = 0;
   for(int i = 0; i < 6; i++){
      ans = max(ans, myTrie.maxXor(v[i]) );
   }
   printf("%d\n", ans);
}
