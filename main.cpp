#include <iostream>
#include "MatrixTemplate.h"
#include "SquareMatrixTemplate.h"
#include "FactoryMatrixTemplate.h"

int main() {
    MatrixTemplate<float> a(3,4);
    //MatrixTemplate<float> b(3,4);
    MatrixTemplate<float> c(4,2);
    //MatrixTemplate<int> d(3,4);
    SquareMatrixTemplate<float> e(2);
    a.setValue(2,2,4.5);
    a.setValue(3,1,6.7);
    //b.setValue(2,2,3.3);
    //b.setValue(3,1,1.3);
    c.setValue(2,2,2);
    c.setValue(3,1,2);
    //d.setValue(2,2,4);
    //d.setValue(3,1,6);
    e.setValue(2,2,1);
    //e.setValue(1,1,1);
    //a+=b;
    //d=d*7;
    //MatrixTemplate<float> f(a.getRows(), c.getColumns());
    //f = a*c;
    //f.print();
    //e.print();

    return 0;
}