#include <bits/stdc++.h>
using namespace std;
//BEGIN
template<class T>
struct Matrix{
   int rows;
   int columns;
   vector< vector<T> > grid;

   Matrix(){
         rows = columns = 0;
         grid = vector< vector<T> >();
   }

   Matrix(int _rows, int _columns){
      rows = _rows;
      columns = _columns;
      grid = vector< vector<T> >(rows, vector<T>(columns));
   }

   bool inside(int row, int column){
      return row>=0 and row<rows and column>=0 and column<columns;
   }

   vector<T>& operator [] (int row){
      return grid[row];
   }

   void print(){
      for(int i = 0; i < rows; i++){
         for(int j = 0; j < columns; j++){
            cout << grid[i][j] << ' ';
         }
         printf("\n");
      }
   }
};
//END
int main(){
   Matrix<int> zero;

   Matrix<int> m(3,4);
   printf("2, 3 are inside? %d\n", m.inside(2,3) );
   printf("-1, 3 are inside? %d\n", m.inside(-1,3) );

   m.print();
   m[2][3] = 5;
   m.print();
   //suahsuahsuah
}
