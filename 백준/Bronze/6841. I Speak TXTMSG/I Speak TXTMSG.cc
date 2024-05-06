#include<iostream>

using namespace std;

int main(){
    
    string str;
    
    while(1){
        cin >> str;
        if(str=="CU") cout << "see you" << "\n";
        else if(str==":-)") cout << "I’m happy" << "\n";
        else if(str==":-(") cout << "I’m unhappy" << "\n";
        else if(str==";-)") cout << "wink" << "\n";
        else if(str==":-P") cout << "stick out my tongue" << "\n";
        else if(str=="(~.~)") cout << "sleepy" << "\n";
        else if(str=="TA") cout << "totally awesome" << "\n";
        else if(str=="CCC") cout << "Canadian Computing Competition" << "\n";
        else if(str=="CUZ") cout << "because" << "\n";
        else if(str=="TY") cout << "thank-you" << "\n";
        else if(str=="YW") cout << "you\'re welcome" << "\n";
        else if(str=="TTYL") {
            cout << "talk to you later" << "\n";
            break;
        }
        else{
            cout << str << "\n";
        }
    }
    
    return 0;
}