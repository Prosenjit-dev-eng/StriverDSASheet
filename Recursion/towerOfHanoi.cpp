#include<bits/stdc++.h>
using namespace std;
void hanoi(int n, char from_rod, char to_rod, char aux_rod){
   if (n == 0)
   {
        return;
   }
   hanoi(n-1,from_rod,aux_rod,to_rod);// A->B
   cout<<"Move Disk "<<n<<" From: "<<from_rod<<" To "<<to_rod<<endl;
   hanoi(n-1,aux_rod,to_rod,from_rod);// B->C
   
}
int main()
{
    hanoi(3,'A','C','B');
    return 0;
}