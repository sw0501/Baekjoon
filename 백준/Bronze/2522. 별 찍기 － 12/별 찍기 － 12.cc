#include<iostream>

using namespace std;

int main(){
    
    int N;
    cin >> N;
	//위 N-1줄
    for(int i=0;i<N-1;i++){
		//공백 출력
		for(int k=i;k<N-1;k++){
			cout << " ";
		}
		//별 출력
		for(int l=0;l<=i;l++){
			cout << "*";
		}
		cout << "\n";
    }
	for(int i=0;i<N;i++){
		cout << "*";
	}
	cout << "\n";
    for(int i=N-2;i>=0;i--){
		//공백 출력
		for(int k=i;k<N-1;k++){
			cout << " ";
		}
		//별 출력
		for(int l=0;l<=i;l++){
			cout << "*";
		}
		cout << "\n";
    }
    return 0;
}