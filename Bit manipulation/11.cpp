#include<bits/stdc++.h>
using namespace std;
    // Seive of Eratosthenes
    // T.C. = nlog(log(n)) 
int countPrimes(int n) {
        vector<int>prime(n+1,1);
        for(int i = 2; i*i <= n; i++){
            if(prime[i] == 1){
                for(int j = i*i; j <= n; j+=i){
                    prime[j] = 0;
                }
            }
        }
        int cnt = 0;
        for(int k = 2; k < n;k++){
            if(prime[k] == 1){
                cnt++;
            }
        }
        return cnt;
}
int main()
{
    int n;
    cin>>n;
    cout<<countPrimes(n)<<endl;
    return 0;
}