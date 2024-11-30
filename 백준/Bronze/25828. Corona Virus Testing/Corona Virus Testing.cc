#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    // 코드를 작성해주세요
    
    int g, p, t;

    cin >> g >> p >> t;

    int total = g * p;

    if (total > g + p * t) {
        cout << 2;
    }
    else if (total < g + p * t) {
        cout << 1;
    }
    else {
        cout << 0;
    }



    return 0;
}