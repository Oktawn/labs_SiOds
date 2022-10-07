#include "student.h"

int main()
{
    const int len = 25;
    string men;
    Stydent std[len];
    addSt(std, 1);
    cout << endl;
    showST(std, 1);
    cout << "\nsearch:"; cin >> men;
    cout << endl;
    search_student(std, len, men);
    binary_file_cin(std, len);

    return 0;
}

