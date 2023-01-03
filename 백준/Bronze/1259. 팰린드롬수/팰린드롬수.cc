#include<iostream>

using namespace std;

int main(){
    while(1){
        string num;
        cin >> num;
        if(num[0]=='0')break;
        int temp = 1;
        for(int i=0;i<num.length()/2;i++){
            if(num[i]!=num[num.length()-i-1]){
				temp=0;
				break;
			}
        }
        if(temp)cout << "yes" << "\n";
        else cout << "no" << "\n";
    }
}