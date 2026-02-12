#include <iostream>
#include "matrix_library.h"
#include <cmath>

using namespace std;

void addMatrix(int rows, int cols, int A[][10], int B[][10], int result[][10]) {
    if(rows<=0 || cols<=0){
        cout << "Error:  invalid matrix dimensions (rows/cols must be positive)\n";
        return;
    }
    if(rows>10 || cols>10){
        cout << "Error: matrix size exceed limit (max 10*10)\n";
        return;
    }
for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
             result[i][j] = A[i][j] + B[i][j];
        }
   }
}

void subtractMatrix(int rows, int cols, int A[][10], int B[][10], int result[][10]){
    if(rows<=0 || cols<=0){
        cout << "Error:  invalid matrix dimensions (rows/cols must be positive)\n";
        return;
    }
    if(rows>10 || cols>10){
        cout << "Error: matrix size exceed limit (max 10*10)\n";
        return;
    }

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result[i][j] = A[i][j] - B[i][j];
        }
    }
}

void scalarMatrix(int rows, int cols, int A[][10], int scalar, int result[][10]) {
  for( int i=0; i<rows; i++){
    for (int j=0; j<cols; j++){
        result[i][j] = A[i][j] * scalar;
    }
  }

}

void multipyMatrix(int rowsA, int colsA, int A[][10],int rowsB, int colsB, int B[][10], int result[][10]){
    if(rowsA <=0 || colsA <=0 || rowsB <=0 || colsB <=0){
        cout << " Error: invalid matrix dimensions (rows/cols must be positive)\n";
    }
    else if (rowsA>10|| colsA>10 ||rowsB>10 || colsB>10){
        cout << " Error: matrix size exceeds limit(max 10*10)\n";
        return;
    }
else if(colsA != rowsB){
    cout << "Error" << endl;
}
else{
    for(int i=0; i<rowsA; i++){
        for (int j=0; j<colsB; j++){
            result[i][j] = 0;
            for(int k=0; k<colsA; k++){
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
  }
}
void transposeMatrix(int rows, int cols,int A[][10],int result[][10]){
    if(rows<=0 || cols<=0){
            cout << " Error: invalid matrix dimesions (rows/cols must be positive)\n";
    return;
    }
    if (rows>10 || cols>10){
        cout << "Error: matrix size exceeds limit (max 10*10)\n";
        return;
    }
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result[j][i]= A[i][j];
        }
    }
}
 //addvector
void addvector(int n, int A[],int B[], int result[]){
    if (n<=0){
        cout << "Error: invalid vector size\n";
        return;
    }
    if(n > 10){
        cout << "Error: vector size exceeds limit (max 10)\n";
        return;
    }
    for (int i=0; i<n; i++){
        result[i]=A[i]+B[i];
    }
}

void subtractvector(int n, int A[],int B[], int result[]){
    if (n<=0){
        cout << "Error: invalid vector size\n";
        return;
    }
    if(n > 10){
        cout << "Error: vector size exceeds limit (max 10)\n";
        return;
    }
    for (int i=0; i<n; i++){
        result[i]=A[i]-B[i];
    }
}
//scalar
void scalarvector(int n, int A[], int scalar, int result[]){
    if(n<=0){
        cout << "Error: invalid vector size\n";
        return;
    }
    if(n>10){
        cout << "Error: vector size exceeds limit(max 10)\n";
        return;
    }
    for(int i=0; i<n; i++)
        result[i] = A[i]* scalar;
    }
    int dotvector(int n, int A[],int B[]){
        if(n<=0){
        cout << "Error: invalid vector size\n";
        return 0;
    }
    if(n>10){
        cout << "Error: vector size exceeds limit(max 10)\n";
        return 0;
    }
      int sum =0;
      for(int i=0; i<n; i++){
        sum += A[i] * B[i];
      }
      return sum;
    }
void crossvector(int A[], int B[], int result[]){
    result[0] = A[1]*B[2] - A[2]*B[1];
    result[1] = A[2]*B[0] - A[0]*B[2];
    result[2] = A[0]*B[1] - A[1]*B[0];
}
//mag
double magnitudevector(int n, int A[]){
    if(n <= 0){
        cout << "Error: invalid vector size\n";
        return 0;
    }
    double sum = 0;
    for(int i=0; i<n; i++){
        sum += A[i]*A[i];
    }
    return sqrt(sum);
}
//normalize
void normalizevector(int n, int A[], double result[]){
    if(n <=0){
        cout << "Error: invalid vector size\n";
    return;
}
double mag = magnitudevector(n, A);
if(mag == 0){
    cout << "Error: cannot normalize zero vector\n";
    return;
}
for(int i= 0; i < n; i++){
    result[i] = A[i] / mag;
}
}
//det

void makesmallerMatrix(int A[][10], int smaller[][10], int rowtodelet, int coltodelet, int n){
            int r=0;
            for( int i = 0; i<n; i++){
                if(i == rowtodelet)
                    continue;

                int c=0;
                for(int j=0; j<n; j++){
                    if (j==coltodelet)
                        continue;

                    smaller[r][c] = A[i][j];
                    c++;
                }
                r++;
            }
        }
        int detRecursive(int n, int A[][10]){
            if (n == 1) return A[0][0];
            if (n == 2) return A[0][0]* A[1][1] - A[0][1] * A[1][0];

            int det = 0;
            int minor[10][10];
            int sign = 1;

            for (int col=0; col<n; col++){
                makesmallerMatrix(A, minor, 0, col, n);
                det +=sign * A[0][col] * detRecursive(n-1, minor);
                sign = -sign;
            }
            return det;
        }
  int determinantrecursive(int rows, int cols, int A[][10]){
      if(rows != cols){
        cout << " determinant only for square matrix\n";
        return 0;
      }
      return detRecursive(rows, A);
  }


        //inverse
    void inverseMatrix(int rows, int cols, int A[][10], double result[][10]){
        if(rows != 2 || cols != 2){
            cout << "only for 2*2 matrix\n";
            return;
        }
        int det = A[0][0]*A[1][1] - A[0][1]*A[1][0];
        if(det == 0){
            cout << "matrix has no inverse\n";
            return;
        }
        result[0][0] = (double)A[1][1]/ det;
        result[0][1]= -(double)A[0][1] / det;
        result[1][0] = -(double)A[1][0]/ det;
        result[1][1] = (double)A[0][0]/ det;
    }




