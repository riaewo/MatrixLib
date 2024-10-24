#include <iostream>
#include <cstring>
#include "MatrixLib.h"
using namespace std;

// Функция, печатающая матрицу
void printMatrix(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i * cols + j] << " ";
        }
        cout << endl;
    }
}

// Функция, показывающая информацию о работе программы
void showHelp() {
    setlocale(0, "");
    cout << "Работа приложения: main.exe [опции]\n";
    cout << "Опции:\n";
    cout << "  --help    Показать информацию о работе программы\n";
    cout << "Эта программа демонстрирует операции над матрицами, такие как:\n";
    cout << "  - Транспонирование матрицы 4 на 4\n";
    cout << "  - Перестановка строк/столбцов местами\n";
}

int main(int argc, char* argv[]) {
    setlocale(0, "");
    // Проверка на --help
    if (argc > 1 && strcmp(argv[1], "--help") == 0) {
        showHelp();
        return 0;
    }

    int rows = 4, cols = 4; // Матрица 4 на 4
    int matrix[16];         // 
    int transposedMatrix[16] = { 0 };

    // Ввод элементов матрицы
    cout << "Введи элементы для матрицы 4 на 4:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i * cols + j];  // Ввод элементов
        }
    }

    cout << "Изначальная матрица:\n";
    printMatrix(matrix, rows, cols);

    // Транспонирование матрицы
    transposeMatrix(matrix, transposedMatrix, rows, cols);
    cout << "\nТранспонированная матрица:\n";
    printMatrix(transposedMatrix, cols, rows);

    // Поменять местами строки (в моем случае 0 и 3)
    int rowIndices[4] = { 3, 1, 2, 0 }; // 
    permuteRows(matrix, rows, cols, rowIndices);
    cout << "\nМатрица после того, как поменяли местами строки:\n";
    printMatrix(matrix, rows, cols);

    // Сброс матрицы
    int originalMatrix[16];
    copy(matrix, matrix + 16, originalMatrix);

    // Поменять местами столбцы (в моем случае 0 и 3)
    int colIndices[4] = { 3, 1, 2, 0 }; // 
    permuteCols(matrix, rows, cols, colIndices);
    cout << "\nМатрица после того, как поменяли местами столбцы:\n";
    printMatrix(matrix, rows, cols);

    return 0;
}
