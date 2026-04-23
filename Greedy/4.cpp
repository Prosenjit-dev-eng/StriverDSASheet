#include<bits/stdc++.h>
using namespace std;
bool lemonadeChange(vector<int>bills){
    int n = bills.size();
    int five = 0, ten = 0;
    for (int i = 0; i < n; i++)
    {
      if (bills[i]==5)
      {
        five++;
      }
      else if (bills[i] == 10)
      {
        // If 5 is there from before
        if (five)
        {
            ten++;
            five--;
            
        }
        else return false;
      }
       else {
            // Check if there are both
            // $5 and $10 bills
            // available to give change
            if(five && ten){
                 // Use one $5 bill
                five--; 
                // Use one $10 bill
                ten--;   
            }
            // If there are not enough $10 bills,
            // check if there are at least
            // three $5 bills available
            else if (five >= 3){
                // Use three $5 bills
                // to give change
                five -= 3;  
            }
            // If unable to give
            // change, return false
            else return false;  
        }
      
    }
    return true;
}
int main()
{
    vector<int>bills = {5, 5, 10, 10, 20};
    cout<<lemonadeChange(bills)<<endl;
    return 0;
}