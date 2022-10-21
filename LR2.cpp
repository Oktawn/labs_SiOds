#include "KK.h"
//#include "KK.cpp"

int main()
{
    srand(unsigned int (time(0)));
    int s, c;
    cout << "string ar: "; cin >> s;
    cout << "colomn ar: "; cin >> c;
    int **ar= new int *[s];
    add_x(ar, s, c);
    create(ar, s, c);
    show(ar, s, c);
    printf("\n rows with no zero el = %d", sum_nozero_rows(ar, s, c));
    //cout << max_ind_main_diag(ar, s, c);
    printf("\n max number that occurs more than once =  %d", max_number_arr(ar, s, c));
    delete[] ar;
    return 0;
}


