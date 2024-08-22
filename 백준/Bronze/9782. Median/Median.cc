#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    
    int cnt = 0;
    while(1){
        cnt++;
        int N;
        cin >> N;
        if(N==0)break;
        
        if(N%2){
            for(int i=1;i<=N;i++){
                int temp;
                cin >> temp;
                if(i==(N+1)/2){
                    cout << "Case " << cnt << ": ";
                    printf("%.1lf\n",(double)temp);
                }
            }
        }
        else{
            int a,b;
            for(int i=1;i<=N;i++){
                int temp;
                cin >> temp;
                if(i==(N)/2){
                    a = temp;
                }
                else if(i==N/2 + 1){
                    b = temp;
                    cout << "Case " << cnt << ": ";
                    printf("%.1lf\n",(double)(a+b)/2);
                }
            }
        }
      
        
    }
    
    return 0;
}