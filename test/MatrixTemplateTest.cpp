#include "gtest/gtest.h"

#include "../MatrixTemplate.h"


TEST(MatrixTemplate, DefaultCostruttore) {
    MatrixTemplate<int> matA;
    ASSERT_EQ(0, matA.getRows());
    ASSERT_EQ(0, matA.getColumns());
}

TEST(MatrixTemplate, Costruttore){
    MatrixTemplate<int> matA(2, 3);
    ASSERT_EQ(2, matA.getRows());
    ASSERT_EQ(3, matA.getColumns());
    ASSERT_EQ(0, matA.getValue(1,1));
    ASSERT_ANY_THROW(MatrixTemplate<float> matB(0, 3));
}

TEST(MatrixTemplate,CopyConstructor){
    MatrixTemplate <float> matA(2,3);
    matA.setValue(1,1,0.5);
    matA.setValue(1,2,1.5);
    matA.setValue(1,3,2.5);
    matA.setValue(2,1,3.5);
    matA.setValue(2,2,4.5);
    matA.setValue(2,3,5.5);
    MatrixTemplate<float> matB(matA);
    ASSERT_TRUE(matA==matB);
}

TEST(MatrixTemplate, Somma){
    MatrixTemplate<int> matA(2,3);
    matA.setValue(1,1,1);
    matA.setValue(1,2,2);
    matA.setValue(1,3,3);
    matA.setValue(2,1,4);
    matA.setValue(2,2,5);
    matA.setValue(2,3,6);
    MatrixTemplate<int> matB(2,3);
    matB.setValue(1,1,7);
    matB.setValue(2,2,8);
    MatrixTemplate<int> matC(2,3);
    matC = matA + matB;
    ASSERT_EQ(8, matC.getValue(1,1));
    ASSERT_EQ(2, matC.getValue(1,2));
    ASSERT_EQ(3, matC.getValue(1,3));
    ASSERT_EQ(4, matC.getValue(2,1));
    ASSERT_EQ(13, matC.getValue(2,2));
    ASSERT_EQ(6, matC.getValue(2,3));
    MatrixTemplate<int> matD(2,2);
    ASSERT_ANY_THROW(matA + matD);
}

TEST(MatrixTemplate, UgualeSomma){
    MatrixTemplate<int> matA(2,3);
    matA.setValue(1,1,1);
    matA.setValue(1,2,2);
    matA.setValue(1,3,3);
    matA.setValue(2,1,4);
    matA.setValue(2,2,5);
    matA.setValue(2,3,6);
    MatrixTemplate<int> matB(2,3);
    matB.setValue(1,1,7);
    matB.setValue(2,2,8);
    matA = matA + matB;
    ASSERT_EQ(8, matA.getValue(1,1));
    ASSERT_EQ(2, matA.getValue(1,2));
    ASSERT_EQ(3, matA.getValue(1,3));
    ASSERT_EQ(4, matA.getValue(2,1));
    ASSERT_EQ(13, matA.getValue(2,2));
    ASSERT_EQ(6, matA.getValue(2,3));
    MatrixTemplate<int> matC(2,2);
    ASSERT_ANY_THROW(matA + matC);
}

TEST(MatrixTemplate, Differenza){
    MatrixTemplate<int> matA(2,3);
    matA.setValue(1,1,1);
    matA.setValue(1,2,2);
    matA.setValue(1,3,3);
    matA.setValue(2,1,4);
    matA.setValue(2,2,5);
    matA.setValue(2,3,6);
    MatrixTemplate<int> matB(2,3);
    matB.setValue(1,1,1);
    matB.setValue(2,2,5);
    MatrixTemplate<int> matC(2,3);
    matC = matA - matB;
    ASSERT_EQ(0, matC.getValue(1,1));
    ASSERT_EQ(2, matC.getValue(1,2));
    ASSERT_EQ(3, matC.getValue(1,3));
    ASSERT_EQ(4, matC.getValue(2,1));
    ASSERT_EQ(0, matC.getValue(2,2));
    ASSERT_EQ(6, matC.getValue(2,3));
    MatrixTemplate<int> matD(2,2);
    ASSERT_ANY_THROW(matA - matD);
}

TEST(MatrixTemplate, UgualeDifferenza){
    MatrixTemplate<int> matA(2,3);
    matA.setValue(1,1,1);
    matA.setValue(1,2,2);
    matA.setValue(1,3,3);
    matA.setValue(2,1,4);
    matA.setValue(2,2,5);
    matA.setValue(2,3,6);
    MatrixTemplate<int> matB(2,3);
    matB.setValue(1,1,7);
    matB.setValue(2,2,8);
    matA = matA - matB;
    ASSERT_EQ(0, matA.getValue(1,1));
    ASSERT_EQ(2, matA.getValue(1,2));
    ASSERT_EQ(3, matA.getValue(1,3));
    ASSERT_EQ(4, matA.getValue(2,1));
    ASSERT_EQ(0, matA.getValue(2,2));
    ASSERT_EQ(6, matA.getValue(2,3));
    MatrixTemplate<int> matC(2,2);
    ASSERT_ANY_THROW(matA - matC);
}

TEST(MatrixTemplate, ProdottoScalare){
    MatrixTemplate<int> matA(2,3);
    matA.setValue(1,1,1);
    matA.setValue(1,2,2);
    matA.setValue(1,3,3);
    matA.setValue(2,1,4);
    matA.setValue(2,2,5);
    matA.setValue(2,3,6);
    MatrixTemplate<int> matB(2,3);
    matB = matA * 2;
    ASSERT_EQ(2, matB.getValue(1,1));
    ASSERT_EQ(4, matB.getValue(1,2));
    ASSERT_EQ(6, matB.getValue(1,3));
    ASSERT_EQ(8, matB.getValue(2,1));
    ASSERT_EQ(10, matB.getValue(2,2));
    ASSERT_EQ(12, matB.getValue(2,3));
}

TEST(MatrixTemplate, Prodotto){
    MatrixTemplate<int> matA(2,3);
    matA.setValue(1,1,1);
    matA.setValue(1,2,2);
    matA.setValue(1,3,3);
    matA.setValue(2,1,4);
    matA.setValue(2,2,5);
    matA.setValue(2,3,6);
    MatrixTemplate<int> matB(3,3);
    matB.setValue(1,1,1);
    matB.setValue(2,2,5);
    MatrixTemplate<int> matC(2,3);
    matC = matA * matB;
    ASSERT_EQ(1, matC.getValue(1,1));
    ASSERT_EQ(2, matC.getValue(1,2));
    ASSERT_EQ(3, matC.getValue(1,3));
    ASSERT_EQ(4, matC.getValue(2,1));
    ASSERT_EQ(25, matC.getValue(2,2));
    ASSERT_EQ(6, matC.getValue(2,3));
    MatrixTemplate<int> matD(2,2);
    ASSERT_ANY_THROW(matA * matD);
}

TEST(MatrixTemplate, UgualeEDiverso){
    MatrixTemplate<int> matA(2,3);
    matA.setValue(1,1,1);
    matA.setValue(1,2,2);
    matA.setValue(1,3,3);
    matA.setValue(2,1,4);
    matA.setValue(2,2,5);
    matA.setValue(2,3,6);
    MatrixTemplate<int> matB(3,3);
    matB.setValue(1,1,1);
    matB.setValue(1,2,2);
    matB.setValue(1,3,3);
    matB.setValue(2,1,4);
    matB.setValue(2,2,5);
    matB.setValue(2,3,6);
    ASSERT_TRUE(matA == matB);
    ASSERT_FALSE(matA != matB);
    MatrixTemplate<int> matC(3,3);
    ASSERT_TRUE(matA != matC);
    ASSERT_FALSE(matA == matC);
    MatrixTemplate<int> matD(2,2);
    ASSERT_TRUE(matA != matD);
    ASSERT_FALSE(matA == matD);
    matA.setValue(1,1,3);
    ASSERT_TRUE(matA != matB);
    ASSERT_FALSE(matA == matB);
}


TEST(MatrixTemplate,SelectRow){
    MatrixTemplate<int> matA(2,3);
    matA.setValue(1,1,1);
    matA.setValue(1,2,2);
    matA.setValue(1,3,3);
    matA.setValue(2,1,4);
    matA.setValue(2,2,5);
    matA.setValue(2,3,6);
    MatrixTemplate<int> matB(matA.selectRow(2));
    ASSERT_EQ(4,matB.getValue(2,1));
    ASSERT_EQ(5,matB.getValue(2,2));
    ASSERT_EQ(6,matB.getValue(2,3));
    ASSERT_ANY_THROW(matA.selectRow(4));
}

TEST(MatrixTemplate,SelectColumn){
    MatrixTemplate<int> matA(2,3);
    matA.setValue(1,1,1);
    matA.setValue(1,2,2);
    matA.setValue(1,3,3);
    matA.setValue(2,1,4);
    matA.setValue(2,2,5);
    matA.setValue(2,3,6);
    MatrixTemplate<int> matB(matA.selectColumn(2));
    ASSERT_EQ(2,matB.getValue(1,2));
    ASSERT_EQ(5,matB.getValue(2,2));
    ASSERT_ANY_THROW(matA.selectColumn(4));
}

TEST(MatrixTemplate, Transpose){
    MatrixTemplate<int> matA(2,3);
    matA.setValue(1,1,1);
    matA.setValue(1,2,2);
    matA.setValue(1,3,3);
    matA.setValue(2,1,4);
    matA.setValue(2,2,5);
    matA.setValue(2,3,6);
    MatrixTemplate<int> matB(matA.transpose());
    ASSERT_EQ(3, matB.getRows());
    ASSERT_EQ(2, matB.getColumns());
    ASSERT_EQ(1, matB.getValue(1,1));
    ASSERT_EQ(4, matB.getValue(1,2));
    ASSERT_EQ(2, matB.getValue(2,1));
    ASSERT_EQ(5, matB.getValue(2,2));
    ASSERT_EQ(3, matB.getValue(3,1));
    ASSERT_EQ(6, matB.getValue(3,2));
}

TEST(MatrixTemplate, GetValue){
    MatrixTemplate<int> matA(2,3);
    matA.setValue(1,1,1);
    matA.setValue(1,2,2);
    matA.setValue(1,3,3);
    matA.setValue(2,1,4);
    matA.setValue(2,2,5);
    matA.setValue(2,3,6);
    ASSERT_EQ(3, matA.getValue(1,3));
    ASSERT_EQ(4, matA.getValue(2,1));
    ASSERT_ANY_THROW(matA.getValue(4,5));
}

TEST(MatrixTemplate, SetValue){
    MatrixTemplate<int> matA(2,3);
    matA.setValue(1,1,1);
    matA.setValue(1,2,2);
    matA.setValue(1,3,3);
    matA.setValue(2,1,4);
    matA.setValue(2,2,5);
    matA.setValue(2,3,6);
    ASSERT_ANY_THROW(matA.setValue(4,5,1));
}