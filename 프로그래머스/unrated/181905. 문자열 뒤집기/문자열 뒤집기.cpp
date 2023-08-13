#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {
    while(s<e){
        char temp = my_string[s];
        my_string[s] = my_string[e];
        my_string[e] = temp;
        s++;
        e--;
    }
    return my_string;
}