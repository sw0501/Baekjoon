#include <iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

int main(){

    double pi = 3.14159265359;
    double area;
    cin >> area;

    printf("%.10f",sqrt(area/pi) * 2 * pi);
    return 0;
}