#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    int num = 0;
    char op = '+';
    bool flag = true;
    int temp;
    
    while(1){
        if(flag){
            cin >> temp;
            
            switch(op){
                case '+':
                    num += temp;
                    break;
                case '-':
                    num-=temp;
                    break;
                case '*':
                    num *= temp;
                    break;
                case '/':
                    num /= temp;
                    break;
            }
        }
        else{
            cin >> op;
            if(op=='='){
                cout << num << "\n";
                break;
            }
        }
        flag = !flag;
    }
    
    
    return 0;
}
