#include <iostream>
using namespace std;
int main()
{
    int a = -7, b = 5, c = 7, d = -5;
    // *****Modulo Operator*****
    // x%y = x - (x/y)*y
    cout<<"******MODULO OPERATOR******"<<endl;
    cout << "-7 % 5 = " << a % b << endl;
    cout << "7 % -5 = " << c % d << endl;
    cout << "-7 % -5 = " << a % d << endl;
    cout << "-7 % 7 = " << a % c << endl;
    cout << "7 % -7 = " << c % a << endl;
    cout << "-5 % 7 = " << d % c << endl;
    cout << "-5 % -7 = " << d % a << endl;
    cout << "5 % -7 = " << b % a << endl;
    // Division operator
    cout<<"*****DIVISION OPERATOR******"<<endl;
    cout << "-7 / 5 = " << a / b << endl;
    cout << "7 / -5 = " << c / d << endl;
    cout << "-7 / -5 = " << a / d << endl;
    cout << "-7 / 7 = " << a / c << endl;
    cout << "7 / -7 = " << c / a << endl;
    cout << "-5 / 7 = " << d / c << endl;
    cout << "-5 / -7 = " << d / a << endl;
    cout << "5 / -7 = " << b / a << endl;
    cout<<-10%4<<endl;
    cout<<-10/4<<endl;

    return 0;
}