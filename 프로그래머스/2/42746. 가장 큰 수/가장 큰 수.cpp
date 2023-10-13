#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a,string b){
    
    return a+b>b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string>temp;
    
    for(int i=0;i<numbers.size();i++){
        temp.push_back(to_string(numbers[i]));
    }
    
    sort(temp.begin(),temp.end(),compare);
    
    for(int i=0;i<temp.size();i++){
        if(i<temp.size()-1&&temp[i]=="0" && answer=="")continue;
        answer += temp[i];
    }
    
    return answer;
}