#ifndef MATRIXLIB_H
#define MATRIXLIB_H

#ifdef MATRIXLIB_EXPORTS
#define MATRIXLIB_API __declspec(dllexport)
#else
#define MATRIXLIB_API __declspec(dllimport)
#endif

extern "C" {
    MATRIXLIB_API void transposeMatrix(int* matrix, int* transposedMatrix, int rows, int cols);
    MATRIXLIB_API void permuteRows(int* matrix, int rows, int cols, int* rowIndices);
    MATRIXLIB_API void permuteCols(int* matrix, int rows, int cols, int* colIndices);
}

#endif 