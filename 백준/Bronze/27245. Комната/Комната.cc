#include <iostream>
#include <cmath>


using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int row,col,height;
    cin >> row >> col >> height;
    
    if(min(row,col) / height  >= 2 && max(row,col) / min(row,col) <= 2){
        cout << "good" << "\n";
    }
    else{
        cout << "bad";
    }
    return 0;
}
