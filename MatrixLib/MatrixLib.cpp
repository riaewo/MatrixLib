#include "MatrixLib.h"

// ������� ���������������� �������
void transposeMatrix(int* matrix, int* transposedMatrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposedMatrix[j * rows + i] = matrix[i * cols + j];
        }
    }
}

// ������� ��� ������������ ����� � �������
void permuteRows(int* matrix, int rows, int cols, int* rowIndices) {
    int* tempMatrix = new int[rows * cols];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            tempMatrix[i * cols + j] = matrix[rowIndices[i] * cols + j];
        }
    }

    // ����������� �������������� ����� ������� � �������
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i * cols + j] = tempMatrix[i * cols + j];
        }
    }

    delete[] tempMatrix;
}

// ������� �������������� ������� � �������
void permuteCols(int* matrix, int rows, int cols, int* colIndices) {
    int* tempMatrix = new int[rows * cols];

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            tempMatrix[i * cols + j] = matrix[i * cols + colIndices[j]];
        }
    }

    // ����������� �������������� �������� ������� � �������
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i * cols + j] = tempMatrix[i * cols + j];
        }
    }

    delete[] tempMatrix;
}
