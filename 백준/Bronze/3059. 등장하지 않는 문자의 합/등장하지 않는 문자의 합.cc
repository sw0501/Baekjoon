#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++){
        int arr[26] = {0,};
        string str;
        cin >> str;
        
        for(int j=0;j<str.size();j++){
            arr[(int)(str[j]-'A')]++;
        }
        
        int sum = 0;
        for(int j=0;j<26;j++){
            if(!arr[j]){
                sum += j + 65;
            }
        }
        
        cout << sum << "\n";
    }

    
    return 0;
}
