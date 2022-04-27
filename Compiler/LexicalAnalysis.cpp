#include <bits\stdc++.h>
using namespace std;
//尽可能的把关键字、运算符、限定符写全，不一定会用完
vector<string> Keywords = {"char", "double", "float", "int", "long", "short",
                           "unsigned", "signed", "struct", "union", "enum", "void",                           //数据类
                           "for", "do", "while", "break", "continue",                                         //循环类
                           "if", "else", "goto", "switch", "case", "default", "return",                       //条件类
                           "const", "sizeof", "typedef", "include", "main", "iostream"};                      //其他类
vector<string> MonocularOperators = {"+", "-", "*", "/", "!", "%", "~", "&", "|", "^", "="};                  //单目运算符
vector<string> BinocularOperators = {"++", "--", "&&", "||", "<=", "!=", "==", ">=", "+=", "-=", "*=", "/="}; //双目运算符
vector<string> Delimiters = {",", "(", ")", "{", "}", ";", "<", ">", "#"};                                    //限定符
int Keywords_Number = Keywords.size();                                                                        //关键字数量
int MonocularOperators_Number = MonocularOperators.size();                                                    //单目运算符数量
int BinocularOperators_Number = BinocularOperators.size();                                                    //双目运算符数量
int Delimiters_Number = Delimiters.size();
// NFA当输入一个的时候，所转向的是不确定的
//所以将NFA的每一个状态所转向的状态当作一个结构
struct NFA_Point
{
    char NFA_Point_State[200] = {'#'};
    int num;
};
// NFA存是将其转化为ASCALL码十进制值存在数组中                                                                    //限定符数量
struct NFA
{
    NFA_Point NFAMove[200][200];
    vector<string> NFAState; //状态 "Z"为终态
    vector<string> NFAInput;
    // vector<string> NFAOver;
};
NFA kNFA;
//一个子集
//用@代表空
struct Closure
{
    vector<string> cSet; //需要将其升序排序，以方便比对是否存在
};
vector<Closure> Closures; //子集集合
bool isInteger(char a);
bool isLetter(char a);
bool isKeyword(string a);
bool isMonocularOperator(string a);
bool isBinocularOperator(string a);
bool isDelimiter(string a);
bool is_in_NFAState(string str); //判断该状态是否存在于NFA中
bool is_in_NFAInput(string str); //判断该输入字母是否存在于NFA中
void initNFA();
bool CreateNFA();
void ShowNFA();
void get_closure();
void NFA_to_DFA();
int main()
{
    initNFA();
    if (!CreateNFA())
    {
        cout << "Error:构建NFA失败";
    }
    ShowNFA();
    //  cout << 'a' - 0;
    return 0;
}
bool isInteger(char a)
{
    if (a >= '0' && a <= '9')
        return true;
    return false;
}
bool isLetter(char a)
{
    if (a >= 'a' && a <= 'z')
        return true;
    if (a >= 'A' && a <= 'Z')
        return true;
    return false;
}
bool isKeyword(string a)
{
    for (int i = 0; i < Keywords_Number; i++)
    {
        if (a == Keywords[i])
            return true;
    }
    return false;
    //也可以用迭代器和find函数，但是没必要。
}
bool isMonocularOperator(string a)
{
    for (int i = 0; i < MonocularOperators_Number; i++)
    {
        if (a == MonocularOperators[i])
            return true;
    }
    return false;
}
bool isBinocularOperator(string a)
{
    for (int i = 0; i < BinocularOperators_Number; i++)
    {
        if (a == BinocularOperators[i])
            return true;
    }
    return false;
}
bool isDelimiter(string a)
{
    for (int i = 0; i < Delimiters_Number; i++)
    {
        if (a == Delimiters[i])
            return true;
    }
    return false;
}
bool is_in_NFAState(string str)
{
    for (int i = 0; i < kNFA.NFAState.size(); i++)
    {
        if (str == kNFA.NFAState[i])
            return true;
    }
    return false;
}
bool is_in_NFAInput(string str)
{ //判断该状态是否存在于NFA中
    for (int i = 0; i < kNFA.NFAInput.size(); i++)
    {
        if (str == kNFA.NFAInput[i])
            return true;
    }
    return false;
}
void initNFA()
{
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            for (int k = 0; k < 200; k++)
            {
                kNFA.NFAMove[i][j].NFA_Point_State[k] = '#';
            }
        }
    }
}
bool CreateNFA()
{
    ifstream fs("LexicalAnalysis.txt");
    if (fs.is_open())
    {
        // cout << "YES";
        string line;
        while (getline(fs, line))
        {
            // cout << line << "YES" << endl;
            string strL;
            strL = line[0];
            char ch1 = line[0];
            string strR = line.substr(3);
            // cout << strL << "" << strR << endl;
            if (!is_in_NFAState(strL)) //如果状态不存在，那就把它放进去
            {
                kNFA.NFAState.push_back(strL);
            }
            string strR0;
            strR0 = strR[0]; // String类型的
            if (!is_in_NFAInput(strR0))
            {
                kNFA.NFAInput.push_back(strR0);
            }
            if (strR.size() >= 2) //说明右边还有递归
            {
                kNFA.NFAMove[ch1 - 0][strR[0] - 0].NFA_Point_State[strR[1] - 0] = strR[1]; // ch1-'0'代表他的十进制数
                kNFA.NFAMove[ch1 - 0][strR[0] - 0].num++;
            }
            else
            {
                kNFA.NFAMove[ch1 - 0][strR[0] - 0].NFA_Point_State[strR[1] - 0] = 'Z'; //终态既包含了直接到字母或者数字的那种，又包含了空
                kNFA.NFAMove[ch1 - 0][strR[0] - 0].num++;
            }
        }
        fs.close();
        return true;
    }
    return false;
}
void ShowNFA()
{
    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            for (int k = 0; k < 200; k++)
            {
                char temp = kNFA.NFAMove[i][j].NFA_Point_State[k];
                if (temp != '#')
                    cout << char(i) << "->" << char(j) << temp << endl;
            }
        }
        cout << endl;
    }
}
void get_closure(Closure c)
{
    // for (int i = 0; i < c.cSet.size(); i++)
    // {
    //     for()
    // }
}
void NFA_to_DFA()
{
}