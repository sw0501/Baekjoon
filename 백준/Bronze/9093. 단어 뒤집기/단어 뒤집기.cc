#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

vector<string> split(string str, char delimiter);

int main(){
    
    int T;
    cin >> T;
    getchar();
    for(int i=0;i<T;i++){
        string str;
        getline(cin,str);
        vector<string>v = split(str,' ');
        for(int i=0;i<v.size();i++){
            
            for(int j=v[i].size()-1;j>=0;j--){
                cout << v[i][j];
            }
        
            cout << " ";
        }
        cout << "\n";
    }
    
    
    return 0;
}

 

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}