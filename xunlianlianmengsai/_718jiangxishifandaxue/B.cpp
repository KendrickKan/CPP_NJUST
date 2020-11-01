#include <iostream>
#include <string>
using namespace std;
string str[105];
void print(string prestr, int n)
{
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        if (prestr.length() == str[i].length())
        {
            for (int j = 0; j < prestr.length(); j++)
            {
                if (prestr[j] != '-')
                    if (prestr[j] != str[i][j])
                        goto nextone;
            }
            cout << str[i] << endl;
            num++;
        }
    nextone:
        continue;
    }
    cout << "Total number of candidate words = " << num << endl
         << endl;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> str[i];
    int num, x;
    x = 1;
    cin >> num;
    string prestr;
    while (num--)
    {
        cin >> prestr;
        cout << "Word #" << x << ": " << prestr << endl;
        print(prestr, n);
        x++;
    }

    return 0;
}