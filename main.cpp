#include <iostream>
#include "MatrixTemplate.h"

int main() {
    try {
        MatrixTemplate<float> a(3, 4);
        MatrixTemplate<float> b(4, 2);
        SquareMatrixTemplate<float> c(2);
        a.setValue(2, 2, 4.5);
        a.setValue(3, 1, 6.7);
        b.setValue(2, 2, 2);
        b.setValue(3, 1, 2);
        c.setValue(2, 2, 1);
        c.setValue(1,1,1);
        MatrixTemplate<float> d(a.getRows(), b.getColumns());
        d = a*b;
        d.print();
        c.print();
    }
    catch(std::out_of_range &e){
        std::cerr << e.what() << std::endl;
        return -1;
    }
    catch(std::logic_error &e){
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}