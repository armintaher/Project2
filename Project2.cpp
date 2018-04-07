/* Project2.cpp
 * Ima Student
 * EE312, Spring 2017
 * Project 2, Matrix Multiplication
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "MatrixMultiply.h"


void multiplyMatrices(
        double a[],
        const uint32_t a_rows,
        const uint32_t a_cols,
        double b[],
        const uint32_t b_cols,
        double c[]) {
        double MAT=0;
    for(u_int16_t i=0; i< a_rows; i++) {
        for (u_int16_t j=0; j < b_cols; j++) {
            for(u_int16_t k=0; k < a_cols; k++){
                MAT = MAT + a[i*a_rows+k]*b[k*b_cols+j];

            }
            c[i*a_rows+j] = MAT;
            MAT=0;
        }
    }
}

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {

    double** mat = (double**)malloc(a_rows*sizeof(double*));
    for (u_int16_t r   = 0;   r  <  a_rows; r++) {
        mat[r] =  (double*)malloc(b_cols*sizeof(double));
    }
    for(u_int16_t i=0; i< a_rows; i++) {
        for (u_int16_t j=0; j < b_cols; j++) {
            mat[i][j]=0;
            for(u_int16_t k=0; k < a_cols; k++){
                mat[i][j] += a[i][k]*b[k][j];

            }
        }
    }
    return mat;
}

double** transposeMatrix(
         double** a,
         const uint32_t a_rows,
         const uint32_t a_cols) {
    double** mat = (double**)malloc(a_cols*sizeof(double*));
    for (u_int16_t r   = 0;   r  <  a_cols; r++) {
        mat[r] =  (double*)malloc(a_rows*sizeof(double));
    }

    for(u_int16_t i=0; i<a_rows; ++i)
        for(u_int16_t j=0; j<a_cols; ++j)
        {
            mat[j][i] = a[i][j];
        }

    return mat;
}
