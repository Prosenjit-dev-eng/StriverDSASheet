#include<bits/stdc++.h>
using namespace std;
bool checkPerfectNumber(int num) {
    int sum = 0;
    for(int i = 1; i < sqrt(num); i++){
        if(num%i == 0){
            sum += i;
            if(num/i != num) sum += (num/i);
        }
    }
    return num == sum;
}
int main()
{
    return 0;
}