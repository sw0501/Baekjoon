#include <iostream>

using namespace std;

int main() 
{
    // 코드를 작성해주세요
    int T;
    cin >> T;
    
    for(int t=0;t<T;t++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int A,B,C,D;
        cin >> A >> B >> C >> D;
        
        int ans = 0;
        
        ans += (a+A<1?1:a+A);
        ans += (b+B<1?1:b+B) * 5;
        ans += (c+C<0?0:c+C) * 2;
        ans += (d+D) * 2;
        
        cout << ans << "\n";
    }
    return 0;
}
