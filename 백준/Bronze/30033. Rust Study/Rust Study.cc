#include<iostream>


using namespace std;

int A[1001] = {0,};
int B[1001] ={0,};

int main(){
    
    int N;
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
        
    for(int i=0;i<N;i++){
        cin >> B[i];
    }
    
    int D = 0;
        
    for(int i=0;i<N;i++){
        if(A[i]<=B[i]){
            D++;
        }
    }
    
    cout << D;
    return 0;
}