//
// Created by Lisa Cresti on 15/03/2018.
//

#ifndef CRESTIMATRIX_MATRIXTEMPLATE_H
#define CRESTIMATRIX_MATRIXTEMPLATE_H

template <typename T>

class MatrixTemplate {

public:

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
        MatrixTemplate<T>
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

    bool operator!=(const MatrixTemplate& right) const {
        return !(*this==right);
    }

    //TODO sel row

    //TODO sel col

    //TODO trasposta

    int getRows() const {
        return rows;
    }

    int getColumns() const {
        return columns;
    }

private:

    int rows;
    int columns;
    T* matrix;

};

#endif //CRESTIMATRIX_MATRIXTEMPLATE_H
