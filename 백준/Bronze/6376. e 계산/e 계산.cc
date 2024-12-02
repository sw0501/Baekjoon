#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
    // 코드를 작성해주세요

    double s = 0;
    double fact[10] = { 1, };

    cout << "n" << " " << "e" << "\n";
    cout << "- -----------\n";
    for (int i = 1; i <= 9; i++) {
        fact[i] = fact[i - 1] * i;
    }

    for (int i = 0; i <= 9; i++) {
        s += 1 / fact[i];
        if (i <= 2) {
            cout << i << " " << s << "\n";
        }
        else {
            printf("%d %.9lf\n", i, s);
        }
        
    }


    return 0;
}
