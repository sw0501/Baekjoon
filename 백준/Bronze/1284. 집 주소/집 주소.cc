#include<iostream>

using namespace std;

int main(){
    
    int num;
    
    while(1){
        cin >> num;    
        if(num == 0){
            break;
        }
        else{
            int temp = 2;
            while(num != 0){
                temp++;
                if(num%10==0){
                    temp += 4;
                }
                else if(num%10==1){
                    temp+=2;
                }
                else{
                    temp+=3;
                }
                num/=10;
            }
            temp--;
            cout << temp << "\n";
        }
        
    }
    
    
    
    
    return 0;
}