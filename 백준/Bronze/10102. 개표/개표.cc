/*********************************************************************
*Title : 개표
*Number : <img src="https://d2gd6pc034wcta.cloudfront.net/tier/3.svg" class="solvedac-tier">&nbsp;10102번
*Author : dkxkqkrtkddn
*Description : A와 B가 한 오디션 프로의 결승전에 진출했다. 결승전의 승자는 심사위원의 투표로 결정된다.심사위원의 투표 결과가 주어졌을 때, 어떤 사람이 우승하는지 구하는 프로그램을 작성하시오. 
*Input : 입력은 총 두 줄로 이루어져 있다. 첫째 줄에는 심사위원의 수 V (1 ≤  V ≤  15)가 주어지고, 둘째 줄에는 각 심사위원이 누구에게 투표했는지가 주어진다. A와 B는 각각 그 참가자를 나타낸다. 
*Output : A가 받은 표가 B보다 많은 경우에는 AB가 받은 표가 A보다 많은 경우에는 B같은 경우에는 Tie를 출력한다. 
*Start Time : 2023년 1월 8일 18시 59분 31초
*End Time : 2023년 1월 8일 시 분 초
*comments program : https://chrome.google.com/webstore/detail/boj-blog-post/ehhcjhfkaiohgflkjifmageahncijacd?hl=ko
*********************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void) {
ios_base::sync_with_stdio(0);
cin.tie(0);

    int tmp;
    cin >> tmp;
    
    string str;
    cin >> str;
    
    int A=0,B=0;
    for(int i=0;i<str.length();i++){
        if(str[i]=='A')A++;
        else B++;
    }
    
    if(A>B){
        cout << "A";
    }
    else if(A<B){
        cout << "B";
    }
    else{
        cout << "Tie" << "\n";
    }
    
	return 0;
}