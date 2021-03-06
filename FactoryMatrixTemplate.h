//
// Created by Lisa Cresti on 20/03/2018.
//

#ifndef CRESTIMATRIX_FACTORYMATRIXTEMPLATE_H
#define CRESTIMATRIX_FACTORYMATRIXTEMPLATE_H

#include "MatrixTemplate.h"
#include "SquareMatrixTemplate.h"
#include <string>

template <typename T>
class MatrixTemplate;

template <typename T>
class SquareMatrixTemplate;

template <typename T>
class FactoryMatrixTemplate {

public:

    MatrixTemplate<T>* createMatrix(int r, int c) const {
        MatrixTemplate<T>* newMatrix;
        if (r==c)
            newMatrix = new SquareMatrixTemplate<T>(r);
        else
            newMatrix = new MatrixTemplate<T>(r, c);
        return newMatrix;
    }

};

#endif //CRESTIMATRIX_FACTORYMATRIXTEMPLATE_H
