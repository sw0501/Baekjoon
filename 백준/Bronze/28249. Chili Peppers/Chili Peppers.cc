#include<iostream>
#include<unordered_map>


using namespace std;

int main(){
    unordered_map<string,int> peppers;
    
    peppers.insert({"Poblano", 1500});
    peppers.insert({"Mirasol", 6000});
    peppers.insert({"Serrano", 15500});
    peppers.insert({"Cayenne", 40000});
    peppers.insert({"Thai", 75000});
    peppers.insert({"Habanero", 125000});
    
    int N;
    cin >> N;
    
    long long int sum = 0;
    for(int i=0;i<N;i++){
        string name;
        cin >> name;
        sum += peppers[name];
    }
    
    cout << sum << "\n";
}