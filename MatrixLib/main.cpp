#include <iostream>
#include <cstring>
#include "MatrixLib.h"
using namespace std;

// �������, ���������� �������
void printMatrix(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i * cols + j] << " ";
        }
        cout << endl;
    }
}

// �������, ������������ ���������� � ������ ���������
void showHelp() {
    setlocale(0, "");
    cout << "������ ����������: main.exe [�����]\n";
    cout << "�����:\n";
    cout << "  --help    �������� ���������� � ������ ���������\n";
    cout << "��� ��������� ������������� �������� ��� ���������, ����� ���:\n";
    cout << "  - ���������������� ������� 4 �� 4\n";
    cout << "  - ������������ �����/�������� �������\n";
}

int main(int argc, char* argv[]) {
    setlocale(0, "");
    // �������� �� --help
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        showHelp();
        return 0;
    }

    int rows = 4, cols = 4; // ������� 4 �� 4
    int matrix[16];         // 
    int transposedMatrix[16] = { 0 };

    // ���� ��������� �������
    cout << "����� �������� ��� ������� 4 �� 4:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "������� [" << i << "][" << j << "]: ";
            cin >> matrix[i * cols + j];  // ���� ���������
        }
    }

    cout << "����������� �������:\n";
    printMatrix(matrix, rows, cols);

    // ���������������� �������
    transposeMatrix(matrix, transposedMatrix, rows, cols);
    cout << "\n����������������� �������:\n";
    printMatrix(transposedMatrix, cols, rows);

    // �������� ������� ������ (� ���� ������ 0 � 3)
    int rowIndices[4] = { 3, 1, 2, 0 }; // 
    permuteRows(matrix, rows, cols, rowIndices);
    cout << "\n������� ����� ����, ��� �������� ������� ������:\n";
    printMatrix(matrix, rows, cols);

    // ����� �������
    int originalMatrix[16];
    copy(matrix, matrix + 16, originalMatrix);

    // �������� ������� ������� (� ���� ������ 0 � 3)
    int colIndices[4] = { 3, 1, 2, 0 }; // 
    permuteCols(matrix, rows, cols, colIndices);
    cout << "\n������� ����� ����, ��� �������� ������� �������:\n";
    printMatrix(matrix, rows, cols);

    return 0;
}
