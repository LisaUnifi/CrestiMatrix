//
// Created by Lisa Cresti on 15/03/2018.
//

#ifndef CRESTIMATRIX_MATRIXTEMPLATE_H
#define CRESTIMATRIX_MATRIXTEMPLATE_H

#include <iostream>
#include <cmath>
#include <cfloat>

template <typename T>

class MatrixTemplate {

public:

    MatrixTemplate() {
        //...
    }

    MatrixTemplate(int r, int c) : rows(r), columns(c) {
        //TODO exception when r<1 and/or c<1, or set it =1
        matrix = new T[rows * columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[(i * columns) + j] = 0;
            }
        }
    }

    MatrixTemplate (const MatrixTemplate& right){
        rows = right.rows;
        columns = right.columns;
        matrix = new T[rows*columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[(i * columns) + j] = right.matrix[(i * columns) + j];
            }
        }
    }

    ~MatrixTemplate(){
        delete[] matrix;
    }

    MatrixTemplate operator+(const MatrixTemplate& right) const {
        //TODO controllo sulla dimensione della matrice con eccezione
        MatrixTemplate<T> matrixSum(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrixSum.matrix[(i * columns) + j] = matrix[(i * columns) + j] + right.matrix[(i * columns) + j];
            }
        }
        return matrixSum;
    }

    MatrixTemplate operator+=(const MatrixTemplate& right) {
        //TODO controllo sulla dimensione della matrice con eccezione
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[(i * columns) + j] = matrix[(i * columns) + j] + right.matrix[(i * columns) + j];
            }
        }
        return *this;
    }

    MatrixTemplate operator-(const MatrixTemplate& right) const {
        //TODO controllo sulla dimensione della matrice con eccezione
        MatrixTemplate<T> matrixDif(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrixDif.matrix[(i * columns) + j] = matrix[(i * columns) + j] - right.matrix[(i * columns) + j];
            }
        }
        return matrixDif;
    }

    MatrixTemplate operator-=(const MatrixTemplate& right) {
        //TODO controllo sulla dimensione della matrice con eccezione
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[(i * columns) + j] = matrix[(i * columns) + j] - right.matrix[(i * columns) + j];
            }
        }
        return *this;
    }

    MatrixTemplate operator*(const T& number) const {
        MatrixTemplate<T>;
        //TODO
    }

    MatrixTemplate operator*(const MatrixTemplate& right) const {
        //TODO controllo sulla dimensione della matrice e se può fare il prodotto con la right, con eccezione
        MatrixTemplate<T> matrixMul(rows, right.columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < right.columns; j++) {
                matrixMul.matrix[(i * right.columns) + j] = 0;
                for (int k = 0; k < columns; k++){
                    matrixMul.matrix[(i * right.columns) + j] = matrix[(i * columns) + k] + right.matrix[(k * right.columns) + j];
                }
            }
        }
        return matrixMul;
    }

    bool operator==(const MatrixTemplate& right) const {
        if (rows != right.rows)
            return  false;
        if (columns != right.columns)
            return false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (!equal(matrix[(i * columns) + j], right.matrix[(i * columns) + j]))
                    return false;
            }
        }
        return true;
    }

    bool equal(const int& left, const int& right){
        return (left == right);
    }

    bool equal(const float& left, const float& right){
        if (fabs(left - right) < FLT_EPSILON){
            return false;
        }
        return true;
    }

    bool equal(const double& left, const double& right){
        if (fabs(left - right) < FLT_EPSILON){
            return false;
        }
        return true;
    }

    bool operator!=(const MatrixTemplate& right) const {
        return !(*this==right);
    }

    MatrixTemplate selectRow(int i) {
        //TODO exception i>rows or i<1
        MatrixTemplate<T> rowMatrix(1, columns);
        for (int k = 0; k < columns; k++){
            rowMatrix.matrix[i] = matrix[((i-1)* columns) + k];
        }
        return rowMatrix;
    }

    MatrixTemplate selectColumn(int i) {
        //TODO exception i>columns or i<1
        MatrixTemplate<T> columnMatrix(1, columns);
        for (int k = 0; k < rows; k++){
            columnMatrix.matrix[i] = matrix[(k * columns) + (i - 1)];
        }
        return columnMatrix;
    }

    MatrixTemplate transpose() const {
        MatrixTemplate<T> matrixTransposed(columns, rows);
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < columns; j++){
                matrixTransposed.matrix[(j * matrixTransposed.columns) + i] = this->matrix[(i * this->columns) + j];
            }
        }
        return matrixTransposed;
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                std::cout << matrix[(i * columns) + j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    int getRows() const {
        return rows;
    }

    int getColumns() const {
        return columns;
    }

    T getValue(int i, int j) const {
        //TODO excption: i>rows, j>columns, i<1, j<1
        return matrix[((i - 1) * columns) + (j - 1)];
    }

    void setValue(int i, int j, const T& value ){
        //TODO exception
        matrix[((i - 1) * columns) + (j - 1)] = value;
    }

private:

    int rows;
    int columns;
    T* matrix;

};

#endif //CRESTIMATRIX_MATRIXTEMPLATE_H
