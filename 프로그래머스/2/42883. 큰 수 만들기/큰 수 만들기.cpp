#include <string>
#include <vector>
#include <stack>

using namespace std;

//포함하지 않을 자릿수
int del[1000000]={0,};

string solution(string number, int k) {
    string answer = "";

    stack<char>st;
    
    st.push(number[0]);
    
    for(int i=1;i<number.length();i++){
        //number[i] > st.top() 인 경우 pop 실행
        while(!st.empty()&&number[i]>st.top() && k>0){
            st.pop();
            k--;
        }
        st.push(number[i]);
    }
    
    while(k>0){
        st.pop();
        k--;
    }
    
    stack<char>temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    
    while(!temp.empty()){
        answer += temp.top();
        temp.pop();
    }
    
    return answer;
}