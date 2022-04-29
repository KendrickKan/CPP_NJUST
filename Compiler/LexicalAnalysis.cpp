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
char beginch;
struct NFA_Point
{
    vector<char> NFA_Point_State;
    // int num;
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
    vector<char> cSet;   //需要将其升序排序，以方便比对是否存在
    bool haveOver;       //用于判断是否含有终态
    int dfa[200] = {-1}; //下标就是输入的ASCAII的值，存的就是clousers的下标
};
vector<Closure> clousers; //子集集合
bool isInteger(char a);
bool isLetter(char a);
bool isKeyword(string a);
bool isMonocularOperator(string a);
bool isBinocularOperator(string a);
bool isDelimiter(string a);
bool is_in_NFAState(string str); //判断该状态是否存在于NFA中
bool is_in_NFAInput(string str); //判断该输入字母是否存在于NFA中
bool CreateNFA();
void ShowNFA();
bool is_in_closure(char a, Closure c); //判断该元素是否在子集
Closure get_closure(Closure c);
int is_in_closures(Closure c);
Closure colouse_move(Closure c, char ch);
void NFA_to_DFA();
void ShowDFA();
bool DFA(string str);
void slove();
int main()
{
    if (!CreateNFA())
    {
        cout << "Error:构建NFA失败";
    }
    ShowNFA();
    NFA_to_DFA();
    for (int i = 0; i < clousers.size(); i++)
    {
        cout << "T_Index:" << i << " ";
        for (int j = 0; j < clousers[i].cSet.size(); j++)
        {
            cout << clousers[i].cSet[j] << " ";
        }
        cout << clousers[i].haveOver;
        cout << endl;
    }
    ShowDFA();
    slove();
    // cout << 'a' - 0;
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
bool CreateNFA()
{
    ifstream fs("LexicalAnalysisOLD.txt");
    if (fs.is_open())
    {
        bool fbegin = false;
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
                if (!fbegin)
                {
                    beginch = ch1;
                    fbegin = true;
                }
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
                kNFA.NFAMove[ch1 - 0][strR[0] - 0].NFA_Point_State.push_back(strR[1]);
                // kNFA.NFAMove[ch1 - 0][strR[0] - 0].NFA_Point_State[strR[1] - 0] = strR[1]; // ch1-'0'代表他的十进制数
                // kNFA.NFAMove[ch1 - 0][strR[0] - 0].num++;
            }
            else
            {
                kNFA.NFAMove[ch1 - 0][strR[0] - 0].NFA_Point_State.push_back('Z');
                // kNFA.NFAMove[ch1 - 0][strR[0] - 0].NFA_Point_State[strR[1] - 0] = 'Z'; //终态既包含了直接到字母或者数字的那种，又包含了空
                // kNFA.NFAMove[ch1 - 0][strR[0] - 0].num++;
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
            for (int k = 0; k < kNFA.NFAMove[i][j].NFA_Point_State.size(); k++)
            {
                cout << char(i) << "->" << char(j) << kNFA.NFAMove[i][j].NFA_Point_State[k] << endl;
            }
        }
    }
}
bool is_in_closure(char a, Closure c)
{
    for (int i = 0; i < c.cSet.size(); i++)
    {
        if (a == c.cSet[i])
            return true;
    }
    return false;
}
Closure get_closure(Closure c)
{
    //这里的c.size()是动态变化的
    for (int i = 0; i < c.cSet.size(); i++)
    {
        for (int j = 0; j < kNFA.NFAMove[c.cSet[i] - 0]['@' - 0].NFA_Point_State.size(); j++)
        {
            char temp = kNFA.NFAMove[c.cSet[i] - 0]['@' - 0].NFA_Point_State[j]; //从该状态经过空弧走到temp
            if (!is_in_closure(temp, c))
            {
                c.cSet.push_back(temp);
            }
        }
    }
    return c; //加入子集 集合
}
int is_in_closures(Closure c)
{
    for (int i = 0; i < clousers.size(); i++)
    {
        if (clousers[i].cSet.size() == c.cSet.size())
        {
            //已经提前对其进行排序了，只需要一个一个比对就行了
            bool flag = false;
            for (int j = 0; j < clousers[i].cSet.size(); j++)
            {
                if (clousers[i].cSet[j] != c.cSet[j])
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
                return i;
        }
    }
    return -1;
}
Closure colouse_move(Closure c, char ch)
{
    Closure tempClosure;
    for (int i = 0; i < c.cSet.size(); i++)
    {
        for (int j = 0; j < kNFA.NFAMove[c.cSet[i] - 0][ch - 0].NFA_Point_State.size(); j++)
        {
            char temp = kNFA.NFAMove[c.cSet[i] - 0][ch - 0].NFA_Point_State[j];
            if (!is_in_closure(temp, tempClosure))
            {
                tempClosure.cSet.push_back(temp);
            }
        }
    }
    return tempClosure;
}
Closure chaveOver(Closure c)
{
    c.haveOver = false;
    for (int i = 0; i < c.cSet.size(); i++)
    {
        if (c.cSet[i] == 'Z')
            c.haveOver = true;
    }
    return c;
}
void NFA_to_DFA()
{
    Closure cbegin;
    cbegin.cSet.push_back(beginch); //初态 这里是定死了的 //但是后期可以改
    cbegin = get_closure(cbegin);   //得到第一个子集
    cbegin.haveOver = false;
    sort(cbegin.cSet.begin(), cbegin.cSet.end()); //排序，方便比对
    cbegin = chaveOver(cbegin);                   //判断是否含有终结
    clousers.push_back(cbegin);
    for (int i = 0; i < clousers.size(); i++)
    {
        for (int j = 0; j < kNFA.NFAInput.size(); j++)
        {
            char tempch = kNFA.NFAInput[j][0];
            if (kNFA.NFAInput[j][0] == '@') //这里的kNFA.NFAInput[j]其实是含有一个字符的字符串，所以只需要提起第一个就行啦
                continue;
            Closure temp = colouse_move(clousers[i], kNFA.NFAInput[j][0]);
            Closure temp2 = get_closure(temp);
            sort(temp2.cSet.begin(), temp2.cSet.end()); //排序，方便比对
            temp2 = chaveOver(temp2);                   //判断是否含有终结
            int tempIndex = is_in_closures(temp2);
            if (tempIndex == -1)
            {
                clousers.push_back(temp2);
                clousers[i].dfa[kNFA.NFAInput[j][0] - 0] = clousers.size() - 1; //加入新的就把最新的下标存
            }
            else
            {
                clousers[i].dfa[kNFA.NFAInput[j][0] - 0] = tempIndex;
            }
        }
    }
}
void ShowDFA()
{
    for (int i = 0; i < clousers.size(); i++)
    {
        cout << "T_Index:" << i << " "
             << "MoveTo: ";
        for (int j = 0; j < kNFA.NFAInput.size(); j++)
        {
            if (kNFA.NFAInput[j][0] == '@') //这里的kNFA.NFAInput[j]其实是含有一个字符的字符串，所以只需要提起第一个就行啦
                continue;
            char temp = kNFA.NFAInput[j][0];
            cout << "corss " << temp << " to " << clousers[i].dfa[temp - 0] << "; ";
        }
        cout << endl;
    }
}
bool DFA(string str)
{
    int tempIndex = 0;
    for (int i = 0; i < str.length(); i++)
    {
        tempIndex = clousers[tempIndex].dfa[str[i] - 0];
    }
    if (clousers[tempIndex].haveOver)
        return true;
    return false;
}
void slove()
{
    cout << "\n       内容      类别    行号\n";

    ifstream fs("LexicalAnalysisSourceProgram.txt");
    if (fs.is_open())
    {
        string line;
        int lineNum = 0; //代码所在行数
        while (getline(fs, line))
        {
            lineNum++;
            for (int i = 0; i < line.length();)
            {
                string checkStr = "";
                if (isInteger(line[i]))
                {
                    checkStr += line[i];
                    i++;
                    while (isInteger(line[i]) || isLetter(line[i]) || line[i] == '.' || line[i] == '+' || line[i] == '-')
                    {
                        checkStr += line[i];
                        i++;
                    }
                    if (DFA(checkStr))
                    {
                        cout << left << setw(15) << checkStr << " 常量      " << lineNum << endl;
                    }
                    else
                    {
                        cout << left << setw(15) << checkStr << " 非法常量   " << lineNum << endl;
                    }
                }
                else if (isLetter(line[i]))
                {
                    checkStr += line[i];
                    i++;
                    while (isLetter(line[i]) || isInteger(line[i]))
                    {
                        checkStr += line[i];
                        i++;
                    }
                    if (isKeyword(checkStr))
                    {
                        cout << left << setw(15) << checkStr << " 关键字    " << lineNum << endl;
                    }
                    else
                    {
                        if (DFA(checkStr))
                        {
                            if (DFA(checkStr))
                            {
                                cout << left << setw(15) << checkStr << " 标识符    " << lineNum << endl;
                            }
                            else
                            {
                                cout << left << setw(15) << checkStr << " 非法标识符  " << lineNum << endl;
                            }
                        }
                    }
                }
                checkStr = line[i]; //这样能将char转化为string
                if (isDelimiter(checkStr))
                {
                    i++;
                    cout << left << setw(15) << checkStr << " 限定符    " << lineNum << endl;
                }
                else if (isMonocularOperator(checkStr))
                {
                    i++;
                    cout << left << setw(15) << checkStr << " 运算符    " << lineNum << endl;
                }
                if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t')
                    i++;
            }
        }
        fs.close();
    }
}