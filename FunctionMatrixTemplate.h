//
// Created by lisa on 22/03/18.
//

#ifndef CRESTIMATRIX_FUNCTIONMATRIXTEMPLATE_H
#define CRESTIMATRIX_FUNCTIONMATRIXTEMPLATE_H

#include "MatrixTemplate.h"
#include <cfloat>
#include <cmath>

template <typename T>
class MatrixTemplate;

template <typename T>
class SquareMatrixTemplate;

template <typename T>
bool sameOf(const T& left, const T& right){
    return (left == right);
}

template <>
bool sameOf<float>(const float& left, const float& right) {
    if (fabs(left - right) < FLT_EPSILON){
        return false;
    }
    return true;
}

template <>
bool sameOf<double>(const double& left, const double& right) {
    if (fabs(left - right) < FLT_EPSILON){
        return false;
    }
    return true;
}


#endif //CRESTIMATRIX_FUNCTIONMATRIXTEMPLATE_H
