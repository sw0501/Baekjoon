#include <iostream>

using namespace std;


int main() 
{
    // 코드를 작성해주세요
    const string str[9] = {
      " @@@   @@@ "
    , "@   @ @   @"
    , "@    @    @"
    , "@         @"
    , " @       @ "
    , "  @     @  "
    , "   @   @   " 
    , "    @ @    "
    , "     @     "
    };
    

    int num;
    cin >> num;
    for(int i=0;i<9;i++){
        for(int j=0;j<num;j++){
            cout << str[i];
            if(j!=num-1){
                cout << " ";
            }
        }
        cout << "\n";
    }
    
    return 0;
}
