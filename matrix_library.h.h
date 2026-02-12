#ifndef MATRIX_LIBRARY_H
#define MATRIX_LBRARY_H

void addMatrix(int rows, int cols, int A[][10], int B[][10], int result[][10]);

void subtractMatrix(int rows, int cols, int A[][10], int B[][10], int result[][10]);

void scalarMatrix(int rows, int cols, int A[][10], int scalar, int result[][10]);

void multipyMatrix(int rowsA, int colsA, int A[][10], int rowsB, int colsB, int B[][10], int result[][10] );

void transposeMatrix(int rows, int cols, int A[][10], int [][10]);

void addvector(int n, int A[], int B[] , int result[]);

void subtractvector(int n, int A[], int B[], int result[]);

void scalarvector(int n, int A[], int scalar, int result[]);

int dotvector(int n, int A[],int B[]);

void crossvector(int A[], int B[], int result[]);

double magnitudevector(int n, int A[]);

void normalizevector(int n, int A[], double result[]);

int detRecursive(int n, int A[][10]);
void makesmallerMatrix(int A[][10], int smaller[][10], int rowtodelet, int coltodelet, int n);
int determinantrecursive(int rows, int cols, int A[][10]);

void inverseMatrix(int rows, int cols, int A[][10], double result[][10]);





#endif // MATRIX_LIBRARY_H

