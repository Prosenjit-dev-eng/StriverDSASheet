#include<iostream>
#include<math.h>
using namespace std;
bool isAmstrong(int n){
    if(n<0) return false;
    int original = n;
    int ld = 0, sum = 0, count = 0, temp = n;
    while (temp != 0)
    {
        count++;
        temp/=10;
    }
    
    while (n!=0)
    {
        ld = n%10;
        sum += ld*ld*ld;
        n/=10;
    }
   if(sum == original) return true;
   return false; 
}
int main()
{
    int n;
    cin>>n;

    cout<<isAmstrong(n)<<endl;
    return 0;
}
// Time = O(d) => d = no. of digits
