#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    
    int i = my_string.length()-1;
    int j = is_suffix.length()-1;
    
    int flag = 1;
   
    while(i>=0&&j>=0){
        if(my_string[i]!=is_suffix[j]){
            cout << my_string[i] << " " << is_suffix[j] << "\n";
            flag = 0;
        }
        i--;
        j--;
    }
    
    if(j>=0){
        flag = 0;
    }
    
    return flag;
}