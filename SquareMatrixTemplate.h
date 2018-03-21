//
// Created by Lisa Cresti on 19/03/2018.
//

#ifndef CRESTIMATRIX_SQUAREMATRIXTEMPLATE_H
#define CRESTIMATRIX_SQUAREMATRIXTEMPLATE_H

#include "MatrixTemplate.h"

template <typename T>
class MatrixTemplate;

template <typename T>
class SquareMatrixTemplate : public MatrixTemplate<T> {

public:

    explicit SquareMatrixTemplate(int d) : dim(d) {
        if (dim<1)
            throw std::out_of_range("Non è possibile creare la matrice: rows e columns devono essere maggiori di 1");
        matSquare = new T[dim ^ 2];
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                matSquare[(i * dim) + j] = 0;
            }
        }
    }

    virtual ~SquareMatrixTemplate(){
        delete[] matSquare;
    }

    float determinant() const {
        if (dim == 2)
            return (matSquare[0]*matSquare[3]) - (matSquare[1]*matSquare[2]);
        else if (dim == 3){
            float a = (matSquare[0]*matSquare[4]*matSquare[8]) + (matSquare[1]*matSquare[5]*matSquare[6]) + (matSquare[2]*matSquare[3]*matSquare[7]);
            float b = (matSquare[6]*matSquare[4]*matSquare[2]) + (matSquare[7]*matSquare[5]*matSquare[0]) + (matSquare[3]*matSquare[1]*matSquare[8]);
            return (a - b);
        }
        else {
            throw std::out_of_range("Non è possibile calcolare il determinante della matrice perchè troppo grande");
        }
    }

private:

    int dim;
    T* matSquare;
};

#endif //CRESTIMATRIX_SQUAREMATRIXTEMPLATE_H
