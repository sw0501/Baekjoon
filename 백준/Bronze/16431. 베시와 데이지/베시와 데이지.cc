#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int b[2];
    int d[2];
    int j[2];
    
    cin >> b[0] >> b[1];
    cin >> d[0] >> d[1];
    cin >> j[0] >> j[1];
    
    int bt = 0;
    int dt = 0;
    
    dt = abs(j[0]-d[0]) + abs(j[1] - d[1]);
    bt = max(abs(j[0]-b[0]),abs(j[1]-b[1]));
    
    //<< "dasiy : " << dt << "\n";
    //cout << "bessie : " << bt << "\n";
    if(bt==dt){
        cout << "tie" << "\n";
    }
    else if(bt>dt){
        cout << "daisy" << "\n";
    }
    else{
        cout << "bessie" << "\n";
    }
    return 0;
}
