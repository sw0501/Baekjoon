#include<iostream>

using namespace std;

int main(){
    
    int N;
    int K;
    cin >> N >> K;
    
    for(int i=0;i<K;i++){
        int num;
        cin >> num;
        num*=100;
        num/=N;
        
        if(num<=4){
            cout << 1 << " ";
        }
        else if(num<=11){
            cout << 2<< " ";
        }
        else if(num<=23){
            cout << 3<< " ";
        }
        else if(num<=40){
            cout << 4<< " ";
        }
        else if(num<=60){
            cout << 5<< " ";
        }
        else if(num<=77){
            cout << 6<< " ";
        }
        else if(num<=89){
            cout << 7<< " ";
        }
        else if(num<=96){
            cout << 8<< " ";
        }
        else if(num<=100){
            cout << 9<< " ";
        }
    }
    
    
    return 0;
}