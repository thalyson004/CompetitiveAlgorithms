#include <bits/stdc++.h>
using namespace std;
/*
TODO:
   Add begin() and end() methods
*/

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

   Matrix(int _rows, int _columns, T value){
      rows = _rows;
      columns = _columns;
      grid = vector< vector<T> >(rows, vector<T>(columns, value));
   }

   bool inside(int row, int column){
      return row>=0 and row<rows and column>=0 and column<columns;
   }

   vector<T>& operator [] (int row){
      return grid[row];
   }

   void fill(T value){
      for(int i = 0; i < rows; i++)
         for(int j = 0; j < columns; j++)
            grid[i][j] = value;
   }

   void clock_rotate(){
      vector< vector<T> > result = vector< vector<T> >(columns, vector<T>(rows));

      for(int i = 0; i < columns; i++){
         for(int j = 0; j < rows; j++){
            result[i][j] = grid[rows-j-1][i];
         }
      }
      swap(columns, rows);
      grid = result;
   }

   Matrix pow(int x, int mod){
      if(rows!=columns) return Matrix();

      Matrix<T> ans(rows, columns);
      for(int i=0; i < rows; i++)
         ans[i][i] = 1;

      Matrix<T> cur = *this;
      while(x){
         if(x&1){
            ans = multiply(ans, cur, mod);
         }
         cur = multiply(cur, cur, mod);
         x /= 2;
      }

      return ans;
   }


   void print(){
      for(int i = 0; i < rows; i++){
         for(int j = 0; j < columns; j++){
            cout << grid[i][j] << ' ';
         }
         cout << "\n";
      }
   }

   void flipH(){
      for(int i = 0; i < rows; i++){
         reverse(grid[i].begin(), grid[i].end());
      }
   }

private:
   Matrix<T> multiply(Matrix<T> &a, Matrix<T> &b, int mod){
      if(a.columns != b.rows ) return Matrix();
      Matrix<T> ans(a.rows, b.columns);
      for(int i = 0; i < a.rows; i++){
         for(int j = 0; j < b.columns; j++){
            for(int k = 0; k < a.columns; k++){
               ans[i][j] = (ans[i][j] + a[i][k]*b[k][j])%mod;
            }
         }
      }
      return ans;
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
   printf("---\n");
   m.print();
   printf("---\n");
   m.fill(7);
   m.print();
   printf("---\n");
   m = Matrix<int>(3,3);
   int x = 0;
   for(int i = 0; i < 3; i++)
   for(int j = 0; j < 3; j++)
      m[i][j] = x++;
   m.print();
   printf("---\n");
   m.clock_rotate();
   m.print();
   printf("---\n");
   m.clock_rotate();
   m.print();
   //suahsuahsuah
}
