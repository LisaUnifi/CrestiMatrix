//
// Created by Lisa Cresti on 15/03/2018.
//

#ifndef CRESTIMATRIX_MATRIXTEMPLATE_H
#define CRESTIMATRIX_MATRIXTEMPLATE_H

#include <iostream>
#include <cmath>
#include <cfloat>
#include <stdexcept>
#include "FactoryMatrixTemplate.h"
#include "FunctionMatrixTemplate.h"


template <typename T>
class MatrixTemplate {

public:

    MatrixTemplate(){
        this->rows = 0;
        this->columns = 0;
        this->matrix = NULL;
        this->factory = NULL;
    }

    MatrixTemplate(int r, int c) : rows(r), columns(c) {
        if ((rows<1) || (columns<1))
            throw std::out_of_range("Non è possibile creare la matrice: rows e columns devono essere maggiori di 1");
        matrix = new T[rows * columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[(i * columns) + j] = 0;
            }
        }
    }

    explicit MatrixTemplate(FactoryMatrixTemplate<T>* f) : factory(f){
        factory->createMatrix(rows, columns);
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

    virtual ~MatrixTemplate(){
        delete factory;
        delete[] matrix;
    }

    MatrixTemplate operator=(const MatrixTemplate &right) {
        if (&right == this)
            return *this;
        rows = right.rows;
        columns = right.columns;
        delete[] matrix;
        matrix = new T[rows * columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[(i * columns) + j] = right.matrix[(i * columns) + j];
            }
        }
        return *this;
    }

    MatrixTemplate operator+(const MatrixTemplate& right) const {
        if((rows != right.rows) || (columns != right.columns))
            throw std::logic_error("Non è possibile fare l'operazione richiesta: le matrici devono avere le stesse dimensioni.");
        MatrixTemplate<T> matrixSum(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrixSum.matrix[(i * columns) + j] = matrix[(i * columns) + j] + right.matrix[(i * columns) + j];
            }
        }
        return matrixSum;
    }

    MatrixTemplate operator+=(const MatrixTemplate& right) {
        if((rows != right.rows) || (columns != right.columns))
            throw std::logic_error("Non è possibile fare l'operazione richiesta: le matrici devono avere le stesse dimensioni.");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[(i * columns) + j] = matrix[(i * columns) + j] + right.matrix[(i * columns) + j];
            }
        }
        return *this;
    }

    MatrixTemplate operator-(const MatrixTemplate& right) const {
        if((rows != right.rows) || (columns != right.columns))
            throw std::logic_error("Non è possibile fare l'operazione richiesta: le matrici devono avere le stesse dimensioni.");
        MatrixTemplate<T> matrixDif(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrixDif.matrix[(i * columns) + j] = matrix[(i * columns) + j] - right.matrix[(i * columns) + j];
            }
        }
        return matrixDif;
    }

    MatrixTemplate operator-=(const MatrixTemplate& right) {
        if((rows != right.rows) || (columns != right.columns))
            throw std::logic_error("Non è possibile fare l'operazione richiesta: le matrici devono avere le stesse dimensioni.");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrix[(i * columns) + j] = matrix[(i * columns) + j] - right.matrix[(i * columns) + j];
            }
        }
        return *this;
    }

    MatrixTemplate operator*(const T& number) const {
        MatrixTemplate<T> matrixMul(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                matrixMul.matrix[(i * columns) + j] = number * matrix[(i * columns)] ;
            }
        }
        return matrixMul;
    }

    MatrixTemplate operator*(const MatrixTemplate& right) const {
        if(columns != right.rows)
            throw std::logic_error("Non è possibile fare l'operazione richiesta: la matrice di destra deve avere numero di righe pari alle colonne della matrice di sinistra.");
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
                if (!(sameOf(matrix[(i * columns) + j], right.matrix[(i * columns) + j])))
                    return false;
            }
        }
        return true;
    }

    bool operator!=(const MatrixTemplate& right) const {
        return !(*this==right);
    }

    MatrixTemplate selectRow(int i) {
        if ((i>rows) || (i<1))
            throw std::out_of_range("Riga non esistente.");
        MatrixTemplate<T> rowMatrix(1, columns);
        for (int k = 0; k < columns; k++){
            rowMatrix.matrix[i] = matrix[((i-1)* columns) + k];
        }
        return rowMatrix;
    }

    MatrixTemplate selectColumn(int i) {
        if ((i>columns) || (i<1))
            throw std::out_of_range("Colonna non esistente.");
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
        if ((i>rows) || (i<1) || (j>columns) || (j<1))
            throw std::out_of_range("Elemento non esistente.");
        return matrix[((i - 1) * columns) + (j - 1)];
    }

    void setValue(int i, int j, const T& value ){
        if ((i>rows) || (i<1) || (j>columns) || (j<1))
            throw std::out_of_range("Elemento non esistente.");
        matrix[((i - 1) * columns) + (j - 1)] = value;
    }

private:

    int rows;
    int columns;
    T* matrix;
    FactoryMatrixTemplate<T>* factory;

};

#endif //CRESTIMATRIX_MATRIXTEMPLATE_H
