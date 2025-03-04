#include <iostream>
#include <unordered_set>
using namespace std;

int main() 
{
    // 코드를 작성해주세요
    
    unordered_set<int> set;
    
    int prev = 0;
    int next = 0;
    
    int N;
    cin >> N;
    
    for(int i=1;i<=N;i++){
        set.insert(prev);
        prev = next;
        if(prev - i <0 || set.find(prev - i) != set.end()){
            next = prev + i;
        }
        else{
            next = prev - i;
        }
    }
    
    cout << next;
    
    return 0;
}
