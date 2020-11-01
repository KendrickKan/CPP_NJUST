#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    m %= n;
    int *array = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    if (m != 0)
    {
        for (int i = m; i < n; i++)
            cout << array[i] << " ";
        for (int i = 0; i < m - 1; i++)
            cout << array[i] << " ";
        cout << array[m - 1];
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
            cout << array[i] << " ";
        cout << array[n - 1];
    }
    delete[] array;
    return 0;
}