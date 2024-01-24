#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
    
    string str;
    int a,b,c;
    
    for(int i=0;i<N;i++){
        cin >> str >> a >> b >> c;
        if(a+b+c>=55 && a>=35*0.3 && b>=25*0.3 && c>=40*0.3){
            cout << str << " " << a+b+c << " " << "PASS" << "\n";
        }
        else{
            cout << str << " " << a+b+c << " " << "FAIL" << "\n";
        }
    }
    
    return 0;
}