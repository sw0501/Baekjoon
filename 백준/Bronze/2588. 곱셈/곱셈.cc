/*********************************************************************
*Title : 곱셈
*Number : <img src="https://d2gd6pc034wcta.cloudfront.net/tier/3.svg" class="solvedac-tier">&nbsp;2588번
*Author : dkxkqkrtkddn
*Description : (세 자리 수) × (세 자리 수)는 다음과 같은 과정을 통하여 이루어진다.(1)과 (2)위치에 들어갈 세 자리 자연수가 주어질 때 (3), (4), (5), (6)위치에 들어갈 값을 구하는 프로그램을 작성하시오. 
*Input : 첫째 줄에 (1)의 위치에 들어갈 세 자리 자연수가, 둘째 줄에 (2)의 위치에 들어갈 세자리 자연수가 주어진다. 
*Output : 첫째 줄부터 넷째 줄까지 차례대로 (3), (4), (5), (6)에 들어갈 값을 출력한다. 
*Start Time : 2023년 1월 7일 15시 57분 52초
*End Time : 2023년 1월 7일 시 분 초
*comments program : https://chrome.google.com/webstore/detail/boj-blog-post/ehhcjhfkaiohgflkjifmageahncijacd?hl=ko
*********************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void) {
ios_base::sync_with_stdio(0);
cin.tie(0);

    int A,B;
    cin >> A >> B;
    
    int ans = 0;
    int cnt = 1;
    while(B!=0){
        cout << A * (B%10) << "\n";
        ans += (A*(B%10) )*cnt;
        cnt*=10;
        B/=10;
    }
    cout << ans << "\n";
    
	return 0;
}