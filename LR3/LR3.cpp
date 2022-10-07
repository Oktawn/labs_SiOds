#include "student.h"

int main()
{

    const int len = 25;
    const int lg = 8;
    string men;

    Stydent std[len];
    Marsh trafic[lg];

    addSt(std, 1);
    cout << endl;
    showST(std, 1);
    cout << "\nsearch:"; cin >> men;
    cout << endl;
    search_student(std, len, men);
    binary_file_cin(std, len);

    add_path(trafic, 2);
    showTR(trafic, 2);
    cout << "\nenter point: "; cin >> men;
    search_enging_path(trafic, lg, men);

    return 0;
}

