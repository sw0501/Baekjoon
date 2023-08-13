#include <string>
#include <vector>

using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    
    for(int i=0;i<queries.size();i++){
        int s = queries[i][0];
        int e = queries[i][1];
        while(s<e){
            char temp = my_string[s];
            my_string[s] = my_string[e];
            my_string[e] = temp;
            s++;
            e--;
        }
    }
    
    return my_string;
}