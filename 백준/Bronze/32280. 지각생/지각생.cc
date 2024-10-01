#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int N;
    cin >> N;
    
    getchar();
    
    string teacher;
    vector<string>student;
    
    for(int i=0;i<N+1;i++){
        string str;
        
        getline(cin,str);
        
        string t = str.substr(0,5);
        string c = str.substr(6);
        
        if(c=="teacher"){
            teacher = t;
        }
        else{
            student.push_back(t);
        }
    }
    
    string late;
    getline(cin,late);
        
    int cnt = 0;
    
    for(int i=0;i<N;i++){
        if(student[i]<late){
            continue;
        }
        else if(student[i] >= teacher){
            cnt++;
        }
    }
    cout << cnt << "\n";
    
    
    return 0;
}
