#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int GCD(int a,int b){
    while(1){
        int c = b%a;
        if(c==0)return a;
        b = a;
        a = c;
    }
    return 0;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    
    sort(arrayA.begin(),arrayA.end());
    sort(arrayB.begin(),arrayB.end());
    
    //최대 공약수의 약수들 중 정답이 존재
    int num1 = arrayA[0];
    int flag = 0;
    int ans = 0;
    for(int i=1;i<arrayA.size();i++){
        int temp = GCD(num1,arrayA[i]);
        if(temp==0){
            flag = 1;
            break;
        }
        else {
            num1 = temp;
        }
    }
    
    if(flag){
        num1 = 0;
    }
    
    //최대 공약수의 약수들 중 정답이 존재
    int num2 = arrayB[0];
    flag = 0;
    for(int i=1;i<arrayB.size();i++){
        int temp = GCD(num2,arrayB[i]);
        if(temp==0){
            flag = 1;
            break;
        }
        else {
            num2 = temp;
        }
    }
    
    if(flag){
        num2 = 0;
    }
    
    cout << num1 << " " << num2 << "\n";
    
    //나눌 수 있는 수가 없는 경우
    if(num1==1 && num2==1){
        return 0;
    }
    //num1만 나눠지는 경우
    else if(num1!= 1&& num2==1){
        //해당 수의 약수들에 대해 모두 실행
        for(int n = num1;n>=2;n--){
            //약수인 경우 진행
            if(num1%n==0){
               	int flag = 1;
                //나눠지는 경우 조건 위배
                for(int i=0;i<arrayB.size();i++){
					if(arrayB[i]%n==0){
                        flag = 0;
                        break;
                    }
                }
                if(flag)return n;
            }
        }
        
    }
    else if(num1==1 && num2!=1){
		//해당 수의 약수들에 대해 모두 실행
        for(int n = num2;n>=2;n--){
            //약수인 경우 진행
            if(num2%n==0){
               	int flag = 1;
                //나눠지는 경우 조건 위배
                for(int i=0;i<arrayA.size();i++){
					if(arrayA[i]%n==0){
                        flag = 0;
                        break;
                    }
                }
                if(flag)return n;
            }
        }
    }
    
    else if(num1!=1 && num2 !=1){
        
        //해당 수의 약수들에 대해 모두 실행
        for(int n = num1;n>=2;n--){
            //약수인 경우 진행
            if(num1%n==0){
               	int flag = 1;
                //나눠지는 경우 조건 위배
                for(int i=0;i<arrayB.size();i++){
					if(arrayB[i]%n==0){
                        flag = 0;
                        break;
                    }
                }
                if(flag){
                    ans = n;
                    break;
                }
            }
        }
        //해당 수의 약수들에 대해 모두 실행
        for(int n = num2;n>=2;n--){
            //약수인 경우 진행
            if(num2%n==0){
               	int flag = 1;
                //나눠지는 경우 조건 위배
                for(int i=0;i<arrayA.size();i++){
					if(arrayA[i]%n==0){
                        flag = 0;
                        break;
                    }
                }
                //위에서 a의 조건에 만족하는 경우가 있을 때 값 비교
                if(flag){
                    if(ans>=n){
                        return ans;
                    }
                    else{
                        return n;
                    }
                }
            }
        }
    }
    
    //만족하는 값이 남아있는 경우 값 리턴
    if(ans!=0){
        return ans;
    }
    int answer = 0;
    return answer;
}