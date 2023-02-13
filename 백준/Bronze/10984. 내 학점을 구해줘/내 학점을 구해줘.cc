#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    
    int T;
    cin >> T;
    
    for(int i=0;i<T;i++){
        int N;
        cin >> N;
        int s = 0;
        double avg = 0;
        for(int i=0;i<N;i++){
            int a;
            double b;
            cin >> a >> b;
            s += a;
            avg +=b*a;
        }
        printf("%d %.1lf\n", s, avg/(double)s);
    }
    
    return 0;
}