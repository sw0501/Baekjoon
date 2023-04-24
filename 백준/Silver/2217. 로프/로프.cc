/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    long long arr[100000] = {0,};
    for(int i=0;i<N;i++){
        cin >> arr[i];
    }
    
    sort(arr,arr+N);
    reverse(arr,arr+N);
    
    long long Max_weight = -1;
    for(int i=0;i<N;i++){
        if(Max_weight <= arr[i]*(i+1)){
            Max_weight = arr[i]*(i+1);
        }
    }
    
    cout << Max_weight << "\n";

    return 0;
}
