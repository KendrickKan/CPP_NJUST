/*
 * @Author: KendrickKan 
 * @Date: 2020-11-01 11:27:10 
 * @Last Modified by: KendrickKan
 * @Last Modified time: 2020-11-06 19:06:24
 */
#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repp(i, a, b) for (int i = a; i <= b; i++)
#define rep1(i, a, b) for (int i = a; i >= b; i--)
#define mem0(a) memset(a, 0, sizeof(a))
#define memfu1(a) memset(a, -1, sizeof(a))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define EPS 1e-10
#define MOD 1e9 + 7
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
enum Suit
{
    BigJoker = 1,
    LittleJoker,
    Heart,
    Diamond,
    Club,
    Spade
};
class Card
{
public:
    int dianshu;
    Suit suit;
    void print();
};

bool cmp(Card a, Card b)
{
    return rand() % 2 == 1 ? -1 : 1;
}
void Card::print()
{
    if (this->suit != 1 && this->suit != 2)
        cout << this->suit << " " << this->dianshu << endl;
    else
        cout << this->suit << endl;
}
class Deck
{
public:
    Card card[54];
    Deck();
    void print();
    void shuffle();
};
Deck::Deck()
{
    card[0].suit = BigJoker;
    card[0].dianshu = 0;
    card[1].suit = LittleJoker;
    card[1].dianshu = 0;
    for (int i = 2; i < 54; i++)
    {
        card[i].dianshu = (i - 2) / 4 + 2;
        if (((i - 2) % 4 + 1) == 1)
            card[i].suit = Heart;
        else if (((i - 2) % 4 + 1) == 2)
            card[i].suit = Diamond;
        if (((i - 2) % 4 + 1) == 3)
            card[i].suit = Club;
        if (((i - 2) % 4 + 1) == 4)
            card[i].suit = Spade;
    }
}
void Deck::print()
{
    for (int i = 0; i < 54; i++)
        this->card[i].print();
}

void Deck::shuffle()
{
    sort(card, card + 54, cmp);
}

int main()
{
    FastIO;
    return 0;
}