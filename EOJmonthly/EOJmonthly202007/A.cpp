#include <iostream>
#include <string>
using namespace std;
bool judgeb(int bnum, int totalbnum)
{

    if (bnum < totalbnum)
        return true;

    return false;
}

int main()
{
    int n;
    cin >> n;
    int anum, bnum, totalanum, totalbnum;
    string str;
    for (; n > 0; n--)
    {
        totalanum = totalbnum = anum = bnum = 0;
        cin >> str;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'a')
                totalanum++;
            else
                totalbnum++;
        }
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == 'a')
                anum++;
            else
                bnum++;
            if (str[i] == 'b')
            {
                bool temp = judgeb(bnum, totalbnum);
                if (anum == bnum)
                {
                    bnum = anum -= 1;
                    totalanum--;
                    totalbnum--;
                    //         goto stop;
                }
                if (anum < bnum)
                {
                    cout << "Dead Fang" << endl;
                    goto stop;
                }
                else if (anum > bnum && totalanum > totalbnum && !temp)
                {
                    cout << "Sad Fang" << endl;
                    goto stop;
                }
            }
        }
        cout << "Happy Fang" << endl;
    stop:
        continue;
    }

    return 0;
}