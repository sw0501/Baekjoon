#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int solution(int n, int k) {
    int answer = 0;

    vector<int>str;

    int CKP = 1;
    while(n!=0){
        str.push_back(n%k);
        if(n%k==0)CKP=0;
        n/=k;
    }

    long long temp = 0;
    for(int i=str.size()-1;i>=0;i--){
        //0이라면 소수 판별
        if(str[i]==0){
            //2이상인 경우 소수 판별
            if(temp>=2){
                int flag = 1;
                for(int j=2;j<=sqrt(temp);j++){
                    if(temp%j==0){
                        flag=0;
                        break;
                    }
                }
                if(flag){
                    answer++;
                }
            }
            //0 초기화
            temp=0;
        }
        else{
            temp*=10;
            temp+=str[i];
        }
    }

    //2이상일 경우 소수 판별
    if(temp!=0 && temp>=2){
        int flag = 1;
            for(int j=2;j<=sqrt(temp);j++){
                if(temp%j==0){
                    flag=0;
                    break;
                }
            }
        if(flag)answer++;
    }

    return answer;
}