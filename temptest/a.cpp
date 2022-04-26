#include <bits/stdc++.h>
using namespace std;
int op(int a, int b, int t)
{
    if (t == 0)
        return a + b;
    if (t == 1)
        return a - b;
    if (t == 2)
        return a * b;
    if (t == 3 && a & b == 0)
        return a / b;
    return 11111111;
}
bool damage(vector<int> &power)
{
    int a, b, c, d;
    a = power[0];
    b = power[1];
    c = power[2];
    d = power[3];
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int x = 0; x < 4; x++)
            {
                if (op(op(op(a, b, i), c, j), d, x) == 24)
                    return true;
            }
    // a b c d
    // a b d c
    // a c b d
    // a c d b
    // a d b c
    // a d c b
    return false;
    // 1 2 3 4 5 6 7 8 9
    // 1 2 3 4 5 6 7 8 9
    // 1 2 3 4 5 6 7 8 9
    // 1 2 3 4 5 6 7 8 9
}

int main()
{
    vector<int> p = {1, 1, 2, 7};
    cout << damage(p);
    return 0;
}