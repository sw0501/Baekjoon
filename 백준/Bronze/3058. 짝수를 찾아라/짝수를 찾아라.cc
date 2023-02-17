#include<iostream>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        int sum = 0;
        int m = 101;
        int num;
        for(int i=0;i<7;i++){
            cin >> num;
            if(num%2==0){
                sum += num;
                m = (num>m?m:num);
            }
        }
        cout << sum << " " << m << "\n";
    }
    
    return 0;
}