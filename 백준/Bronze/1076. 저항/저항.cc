#include<iostream>

using namespace std;

int main(){
    
    string str;
    
    cin >> str;
    
    long long value = 0;
    if(str == "black"){
        value += 0;
    }
    else if(str == "brown"){
        value += 1;
    }
    else if(str == "red"){
        value += 2;
    }
    else if(str == "orange"){
        value += 3;
    }
    else if(str == "yellow"){
        value += 4;
    }
    else if(str == "green"){
        value += 5;
    }
    else if(str == "blue"){
        value += 6;
    }
    else if(str == "violet"){
        value += 7;
    }
    else if(str == "grey"){
        value += 8;
    }
    else if(str == "white"){
        value += 9;
    }
    
    cin >> str;
    value *= 10;
    if(str == "black"){
        value += 0;
    }
    else if(str == "brown"){
        value += 1;
    }
    else if(str == "red"){
        value += 2;
    }
    else if(str == "orange"){
        value += 3;
    }
    else if(str == "yellow"){
        value += 4;
    }
    else if(str == "green"){
        value += 5;
    }
    else if(str == "blue"){
        value += 6;
    }
    else if(str == "violet"){
        value += 7;
    }
    else if(str == "grey"){
        value += 8;
    }
    else if(str == "white"){
        value += 9;
    }
    
    cin >> str;
    if(str == "black"){
        value *= 1;
    }
    else if(str == "brown"){
        value *= 10;
    }
    else if(str == "red"){
        value *= 100;
    }
    else if(str == "orange"){
        value *= 1000;
    }
    else if(str == "yellow"){
        value *= 10000;
    }
    else if(str == "green"){
        value *= 100000;
    }
    else if(str == "blue"){
        value *= 1000000;
    }
    else if(str == "violet"){
        value *= 10000000;
    }
    else if(str == "grey"){
        value *= 100000000;
    }
    else if(str == "white"){
        value *= 1000000000;
    }
    
    cout << value << "\n";
    
    return 0;
}