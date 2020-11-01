#include <bits/stdc++.h>
using namespace std;
class Date
{
    int year, month, day;

public:
    Date(int y, int m, int d) : year(y), month(m), day(d)
    {
        cout << "Constructorl of Date: ";
        print();
        cout << endl;
    }
    Date()
    {
        time_t ltime = time(NULL);
        tm *today = localtime(&ltime);
        year = today->tm_year + 1900;
        month = today->tm_mon + 1;
        day = today->tm_mday;
        cout << "Default Constructorl of Date: ";
        print();
        cout << endl;
    }
    ~Date()
    {
        cout << "Destructor of Date: ";
        print();
        cout << endl;
    }
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    void print()
    {
        cout << year << '.' << month << '.' << day;
    }
};
int main()
{
    Date date1(2002, 10, 1);
    cout << "date1:";
    date1.print();
    cout << endl;
    Date *date2 = new Date;
    cout << "date2:";
    date2->print();
    cout << endl;
    delete date2;
    date1 = Date(2001, 12, 21);
    cout << "date1:";
    date1.print();
    cout << endl;
    return 0;
}