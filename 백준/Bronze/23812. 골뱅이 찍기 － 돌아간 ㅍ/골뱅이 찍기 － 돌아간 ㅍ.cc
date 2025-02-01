#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin >> N;
    
    //위
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << "@";
        }
        for(int j=0;j<N*3;j++){
            cout << " ";
        }
        for(int j=0;j<N;j++){
            cout << "@";
        }
        cout << "\n";
    }
    //중간 1
    for(int i=0;i<N;i++){
        for(int j=0;j<N*5;j++){
            cout << "@";
        }
        cout << "\n";
    }
    //중간 2
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << "@";
        }
        for(int j=0;j<N*3;j++){
            cout << " ";
        }
        for(int j=0;j<N;j++){
            cout << "@";
        }
        cout << "\n";
    }
    //중간 3
    for(int i=0;i<N;i++){
        for(int j=0;j<N*5;j++){
            cout << "@";
        }
        cout << "\n";
    }
    //아래
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << "@";
        }
        for(int j=0;j<N*3;j++){
            cout << " ";
        }
        for(int j=0;j<N;j++){
            cout << "@";
        }
        cout << "\n";
    }
    
    return 0;
}
