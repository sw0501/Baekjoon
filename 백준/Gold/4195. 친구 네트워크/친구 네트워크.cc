/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>

using namespace std;

int set[200001] = {0,};
int number[200001] = {0,};

int getParent(int x){
    if(set[x]!=x){
        return set[x] = getParent(set[x]);
    }
    else return x;
}

int find(int a,int b){
    a = getParent(a);
    b = getParent(b);
    
    if(a==b){
        return 1;
    }
    else return 0;
}

void unionParent(int a,int b){
    a = getParent(a);
    b = getParent(b);
    
    if(a>b){
        set[a] = b;
        number[b] += number[a];
    }
    else {
        set[b] = a;
        number[a] += number[b];
    }
}

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;
    
    map<string,int>network;
    
    for(int t=0;t<T;t++){
        int N;
        cin >> N;
        for(int i=1;i<=2*N;i++){
            set[i] = i;
            number[i] = 1;
        }
        
        int num = 1;
        
        for(int i=0;i<N;i++){
            string str1, str2;
            cin >> str1 >> str2;
            
            if(network.find(str1)==network.end()){
                network.insert({str1,num++});
            }
            if(network.find(str2)==network.end()){
                network.insert({str2,num++});
            }
            
            if(!find(network.at(str1),network.at(str2))){
                unionParent(network.at(str1),network.at(str2));
            }
            cout << number[getParent(network.at(str1))] << "\n";
        }
        
        network.clear();
    }
    

    return 0;
}
