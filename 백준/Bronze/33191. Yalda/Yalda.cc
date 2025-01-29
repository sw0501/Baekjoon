#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int a;
    int b,c,d;
    cin >> a>> b>> c >> d;
    
    string str = "";
    
    int s = 10000000;
    if(a >= b){
        cout << "Watermelon";
        return 0;
    }
    else if(a>=c){
        cout << "Pomegranates";
        return 0;
    }
    else if(a>=d){
        cout << "Nuts";
        return 0;
    }
    else{
        cout << "Nothing";
        return 0;
    }
    
    
    
    return 0;
}
