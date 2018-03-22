#include "gtest/gtest.h"

#include "../SquareMatrixTemplate.h"

TEST(SquareMatrixTemplate, Costruttore){
    SquareMatrixTemplate<int> matA(2);
    ASSERT_EQ(2, matA.getRows());
    ASSERT_EQ(2, matA.getColumns());
    ASSERT_EQ(0, matA.getValue(1,1));
    ASSERT_ANY_THROW(SquareMatrixTemplate<float> matB(0));
}

TEST(SquareMatrixTemplate, Determinante){
    SquareMatrixTemplate<int> matA(2);
    matA.setValue(1,1,2);
    matA.setValue(1,2,1);
    matA.setValue(2,1,1);
    matA.setValue(2,2,2);
    ASSERT_EQ(3, matA.determinant());
    SquareMatrixTemplate<int> matB(3);
    matB.setValue(1,1,2);
    matB.setValue(1,2,1);
    matB.setValue(1,3,1);
    matB.setValue(2,1,2);
    matB.setValue(2,2,1);
    matB.setValue(2,3,1);
    matB.setValue(3,1,2);
    matB.setValue(3,2,1);
    matB.setValue(3,3,1);
    ASSERT_EQ(0, matB.determinant());
    ASSERT_ANY_THROW(SquareMatrixTemplate<float> matC(7));
}