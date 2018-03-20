//
// Created by Lisa Cresti on 19/03/2018.
//

#ifndef CRESTIMATRIX_SQUAREMATRIXTEMPLATE_H
#define CRESTIMATRIX_SQUAREMATRIXTEMPLATE_H

#include "MatrixTemplate.h"

template <typename T>;
//TODO la cosa del template non funziona

class SquareMatrixTemplate : public MatrixTemplate {

public:

    SquareMatrixTemplate(int d) : dim(d) {
        //TODO exception when d<1
        //TODO finish..
    }

    //TODO determinante

    //TODO inversa

private:

    int dim;
    T* matSquare;
};

#endif //CRESTIMATRIX_SQUAREMATRIXTEMPLATE_H
