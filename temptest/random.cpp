#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000;
bool cmp(int a, int b)
{
    return rand() % 10 > 5 ? 1 : 0;
}
int main()
{
    int a[MAXN];
    int n;
    bool flag = true;
    cout << "Please input the size of the data you want to sort>>";
    cin >> n;
    while (flag)
    {
        for (int i = 0; i < n; i++)
            a[i] = i + 1;
        srand(time(0));
        random_shuffle(a, a + n);
        //sort(a, a + n, cmp);
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "If you want to stop the program, please input 21666>>";
        cin >> n;
        if (n == 21666)
            break;
    }
}