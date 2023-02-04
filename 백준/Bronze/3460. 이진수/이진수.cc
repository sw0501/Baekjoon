/*********************************************************************
*Title : 이진수
*Number : <img src="https://d2gd6pc034wcta.cloudfront.net/tier/3.svg" class="solvedac-tier">&nbsp;3460번
*Author : dkxkqkrtkddn
*Description : 양의 정수 n이 주어졌을 때, 이를 이진수로 나타냈을 때 1의 위치를 모두 찾는 프로그램을 작성하시오. 최하위 비트(least significant bit, lsb)의 위치는 0이다. 
*Input : 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, n이 주어진다. (1 ≤ T ≤ 10, 1 ≤ n ≤ 10^6) 
*Output : 각 테스트 케이스에 대해서, 1의 위치를 공백으로 구분해서 줄 하나에 출력한다. 위치가 낮은 것부터 출력한다. 
*Start Time : 2023년 1월 4일 16시 1분 33초
*End Time : 2023년 1월 4일 시 분 초
*comments program : https://chrome.google.com/webstore/detail/boj-blog-post/ehhcjhfkaiohgflkjifmageahncijacd?hl=ko
*********************************************************************/

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int main(void) {
ios_base::sync_with_stdio(0);
cin.tie(0);

    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        vector<int>v;
        int N;
        cin >> N;
        while(N!=0){
            v.push_back(N%2);
            N/=2;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]==1)cout << i << " ";
        }
        cout << "\n";
    }
    
	return 0;
}