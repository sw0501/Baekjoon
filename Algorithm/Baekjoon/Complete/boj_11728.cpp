#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    int arr1[1000001];
    int arr2[1000001];
    int A;
    int B;
    
    cin >> A >> B;
    for(int i=0;i<A;i++){
        cin >> arr1[i];
    }
    for(int i=0;i<B;i++){
        cin >> arr2[i];
    }
    
	int i=0,j=0;
	
	while(!(i==A&&j==B)){
		if(i==A){
			cout << arr2[j++] << " ";
		}
		else if(j==B){
			cout << arr1[i++] << " ";
		}
		else if(arr1[i]<arr2[j]){
			cout << arr1[i++] << " ";
		}
		else {
			cout << arr2[j++] << " ";
		}
	}
    
    return 0;
}
