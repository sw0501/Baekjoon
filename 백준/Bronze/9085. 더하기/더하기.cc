/*********************************************************************
*Title : 더하기
*Number : <img src="https://d2gd6pc034wcta.cloudfront.net/tier/3.svg" class="solvedac-tier">&nbsp;9085번
*Author : dkxkqkrtkddn
*Description : 10보다 작거나 같은 자연수 N개를 주면 합을 구하는 프로그램을 작성하시오. 
*Input : 입력의 첫 줄에는 테스트 케이스의 개수 T(1 ≤ T ≤ 10)가 주어진다. 각 테스트 케이스는 첫 줄에 자연수의 개수 N(1 ≤ N ≤ 100)이 주어지고, 그 다음 줄에는 N개의 자연수가 주어진다. 각각의 자연수 사이에는 하나씩의 공백이 있다. 
*Output : 각 테스트 케이스에 대해서 주어진 자연수의 합을 한 줄에 하나씩 출력한다. 
*Start Time : 2023년 1월 1일 16시 43분 8초
*End Time : 2023년 1월 1일 시 분 초
*comments program : https://chrome.google.com/webstore/detail/boj-blog-post/ehhcjhfkaiohgflkjifmageahncijacd?hl=ko
*********************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(void) {
ios_base::sync_with_stdio(0);
cin.tie(0);

    int T;
    cin >> T;
    for(int t=0;t<T;t++){
        int N,sum=0;
        cin >> N;
        int tmp;
        for(int i=0;i<N;i++){
            cin >> tmp;
            sum += tmp;
        }
        cout << sum << "\n";
    }
    
	return 0;
}