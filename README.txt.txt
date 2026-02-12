student name : Yasamin Zahedi
Date: 13 February 2026
project description:
this project is a simple Matrix and Vector library written in c++
the program is divided into three files:
matrix_library.h  is for function declarations
matrix_library.cpp is for function implementations
demostration.cpp is for testing

vector operations:
Addiction
Subtraction
Scalar multiplication
Dot product
Cross product
Magnitude that is only for n=3
Normalization

Determinant Algorithm:
 1,if matrix size = 1 return A[0][0]
2,if matrix size = 2 det= ad-bc
3. for n>2:
expand along the first row the for each element:
build smaller matrix
call determinant recursively
multiply by sign (+-+-)
sum all results

Matrix inverse algorithm only for 2*2
|A| = ad-bc which is determinant
if det=0 matrix has no inverse
otherwise we can find the answer

Limitations:
maximum matrix size is 10*10
cross product s only for n=3
inverse implemented is only for 2*2




