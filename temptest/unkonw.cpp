#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    //char num1[10], num2[10];
    string num1, num2;
    string ch = "abc", tmp;
    string ans;
    int op1, op2;
    while (n--)
    {
        // memset(num1, 0, 10);
        // memset(num2, 0, 10);
        //cin.get();
        //tmp = cin.peek();
        cin >> num1;
        if (num1 != "a" && num1 != "b" && num1 != "c")
        {
            //num1 = ch;
            cin >> num2;
            //cin >> num1 >> num2;
        }
        else
        {
            ch = num1;
            cin >> num1 >> num2;
            //cin >> ch >> num1 >> num2;
        }
        op1 = stoi(num1), op2 = stoi(num2);
        if (ch == "a")
            ans = to_string(op1) + '+' + to_string(op2) + '=' + to_string(op1 + op2);
        else if (ch == "b")
            ans = to_string(op1) + '-' + to_string(op2) + '=' + to_string(op1 - op2);
        else if (ch == "c")
            ans = to_string(op1) + '*' + to_string(op2) + '=' + to_string(op1 * op2);
        cout << ans << endl;
        cout << ans.length() << endl;
    }
}
