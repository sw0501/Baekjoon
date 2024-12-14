#include <iostream>

using namespace std;

void _0(){
    cout << "0000" << "\n";
    cout << "0  0" << "\n";
    cout << "0  0" << "\n";
    cout << "0  0" << "\n";
    cout << "0000" << "\n";
}

void _1(){
    cout << "   1" << "\n";
    cout << "   1" << "\n";
    cout << "   1" << "\n";
    cout << "   1" << "\n";
    cout << "   1" << "\n";
}

void _2(){
    cout << "2222" << "\n";
    cout << "   2" << "\n";
    cout << "2222" << "\n";
    cout << "2" << "\n";
    cout << "2222" << "\n";
}

void _3(){
    cout << "3333" << "\n";
    cout << "   3" << "\n";
    cout << "3333" << "\n";
    cout << "   3" << "\n";
    cout << "3333" << "\n";
}

void _4(){
    cout << "4  4" << "\n";
    cout << "4  4" << "\n";
    cout << "4444" << "\n";
    cout << "   4" << "\n";
    cout << "   4" << "\n";
}

void _5(){
    cout << "5555" << "\n";
    cout << "5" << "\n";
    cout << "5555" << "\n";
    cout << "   5" << "\n";
    cout << "5555" << "\n";
}

void _6(){
    cout << "6666" << "\n";
    cout << "6" << "\n";
    cout << "6666" << "\n";
    cout << "6  6" << "\n";
    cout << "6666" << "\n";
}

void _7(){
    cout << "7777" << "\n";
    cout << "   7" << "\n";
    cout << "   7" << "\n";
    cout << "   7" << "\n";
    cout << "   7" << "\n";
}

void _8(){
    cout << "8888" << "\n";
    cout << "8  8" << "\n";
    cout << "8888" << "\n";
    cout << "8  8" << "\n";
    cout << "8888" << "\n";
}

void _9(){
    cout << "9999" << "\n";
    cout << "9  9" << "\n";
    cout << "9999" << "\n";
    cout << "   9" << "\n";
    cout << "   9" << "\n";
}


int main() 
{
    // 코드를 작성해주세요
    string str;
    cin >> str;
    
    for(int i=0;i<str.size();i++){
        switch((int)(str[i]-'0')){
            case 0:
                _0();
                break;
            case 1:
                _1();
                break;
            case 2:
                _2();
                break;
            case 3:
                _3();
                break;
            case 4:
                _4();
                break;
            case 5:
                _5();
                break;
            case 6:
                _6();
                break;
            case 7:
                _7();
                break;
            case 8:
                _8();
                break;
            case 9:
                _9();
                break;
        }
        if(i<str.size()-1)cout << "\n";
    }
    return 0;
}
