#include<iostream>

using namespace std;

int main(){
    
    int checking = 0;
    char ordinary_num;
    for(int i=0;i<5;i++){
        int temp;
        cin >> ordinary_num;
        temp = (int)(ordinary_num-'0');
        checking+=temp*temp;
    }
    cout<<checking%10<<"\n";
    
    
    return 0;
}