#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
/*
	4
	IDENTIFIER=(A|a|B|b|C|c|D|d|E|e|F|f|G|g|H|h|I|i|J|j|K|k|L|l|M|m|N|n|O|o|P|p|Q|q|R|r|S|s|T|t|U|u|V|v|W|w|X|x|Y|y|Z|z|_)(A|a|B|b|C|c|D|d|E|e|F|f|G|g|H|h|I|i|J|j|K|k|L|l|M|m|N|n|O|o|P|p|Q|q|R|r|S|s|T|t|U|u|V|v|W|w|X|x|Y|y|Z|z|_|1|2|3|4|5|6|7|8|9)* 
	INT=(-|epsilon)(1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)*
	FLOAT=(-|epsilon)(0|1|2|3|4|5|6|7|8|9)*(.)(0|1|2|3|4|5|6|7|8|9)*(e|E|epsilon)(+|-)(1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)*
	COMPLEX=(-|epsilon)(1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)*(+|-)(1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)*(i|I)
	int a1_ = 123.45 , 0AB = 123 / 12.0e+3 ; 
	a1_ = 0AB / 45+2i ; 
	return 0 ; 
//FLOAT=(-|epsilon)(0|1|2|3|4|5|6|7|8|9)(.|epsilon)(0|1|2|3|4|5|6|7|8|9)*(e|E|epsilon)(+|-)(1|2|3|4|5|6|7|8|9)(0|1|2|3|4|5|6|7|8|9)*

KEY
OP
DELIMITER

ABC123 +ABC_1 ACA_12_1 ANC ABC12 
123.3 1.2e+3 0.2 
123 0123 120 0 

<S>-><DEFINE>
<S>-><CALULATE>
<DEFINE>-><KEY><VAR>
<VAR>-><IDENTIFIER>

*/

///
char in[1000];
string epsilon="epsilon";
set<string>symb;
int n,row1=0,tottp=0;
///
struct edge{
	int to;
	string value;
};
struct TYPE{
	string name;
	map<string,int>word2idx;
	vector<edge>rule[100];
};
vector<TYPE>types;
vector<TYPE>dfa;
int vis_ending[100];
void readline_(){
	TYPE* newtype=new TYPE();
	int state=0;
	cin.getline(in,1000);
	string tmp="";
	vector<string>ext;
	
	rep(i,0,strlen(in)-1){
		if(in[i]=='='){
			newtype->name=tmp;
			tmp="";
		}
		else if(in[i]=='('){
			
			ext.clear();
		}
		else if(in[i]=='|'){
			ext.push_back(tmp);
			tmp="";
		}
		else if(in[i]==')'){
			ext.push_back(tmp);
			tmp="";
			if(in[i+1]=='*'){
				for(auto s1:ext){
					newtype->rule[state].push_back({state,s1});
					cout<<":"<<s1<<endl;
				}
			}
			else {
				for(auto s1:ext){
					newtype->rule[state].push_back({state+1,s1});
					cout<<"	;"<<s1<<endl;
				}
				state++;
			}
		}
		else if(in[i]=='*')continue;
		else tmp+=in[i];
	}
	vis_ending[++tottp]=state; 
	types.push_back(*newtype);
}


struct WORD{
	string type;
	string name;
	int row,col;
};
vector<WORD>Stc[1005];
map<set<int>,int>set2id[100];
map<int,set<int>>id2set[100];
void DFA(){
	for(auto type:types){
		TYPE nowtp; 
		queue<pair<set<int>,int> > q;
		map<set<int>,int> vis; 
		set<int> ID;
		ID.insert(0); 
		q.push({ID,0});
		int nowstep=0,tot=1;
		while(!q.empty()){
			auto now=q.front().first;
			int nowstep=q.front().second;
			set<int> ext;
			for(auto id:ID){
				for(auto e:type.rule[id]){
					if(e.value=="epsilon"){
						ext.insert(e.to);
					}
				}
			}
			for(auto c:symb){
				set<int> ext1;
				for(auto id1:ext){
					for(auto e:type.rule[id1]){
						if(e.value==c){
							ext1.insert(e.to);
						}
					}
					if(!vis.count(ext1)){
						q.push({ext1,++tot});vis[ext1]=1;
					}
				}
				nowtp.rule[nowstep].push_back({int(tot),c});
			}
		}
		
		dfa.push_back(nowtp); 
	}
}
bool checkline(int row,int col){
	cin.getline(in,1000);
	cout<<in<<endl;
	string sentence="";
	rep(i,0,int(strlen(in))-1)sentence+=in[i];
	if(sentence=="return 0 ; "){row1--;return 0;} 
	if(strlen(in)==0){row1--;return 1;} 
	string tmp="",name="";
	int state=0;
	rep(i,0,int(strlen(in)-1))
	if(in[i]==' '){
		if(name=="")continue; 
		
		if(name=="+" || name=="-" || name=="*" || name=="/" || name=="="){
			tmp="OP";
			cout<<tmp<<" "<<name<<" "<<row<<" "<<col<<endl;
			Stc[row].push_back({tmp,name,row,col});col++;
			name="";continue;
		}
		if(name=="," || name==";"){
			tmp="DELIMITER";
			cout<<tmp<<" "<<name<<" "<<row<<" "<<col<<endl;
			Stc[row].push_back({tmp,name,row,col});col++;
			name="";continue;
			
		}
		
		cout<<name<<endl;
		bool right=0;
		for(auto type:types){
			state=0;
			bool is_this_type=1;
			rep(j,0,name.length()-1){
				char c=name[j];
				tmp="";tmp+=c;
				int find=0,has_epsilon=0,to;
				for(auto edg:type.rule[state]){
					if(edg.value==tmp){
						state=edg.to;find=1;break;
					}
					if(edg.value==epsilon){
						to=edg.to;has_epsilon=1;
					}
				}
				if(!find && has_epsilon){
					state=to;j--;find=1;
				}
				if(!find)is_this_type=0;
			}
			
			if(is_this_type && name!=""){
				if (type.name == "IDENTIFIER"){
					if(name=="int" || name=="float" || name=="complex"){
						type.name="Key";
					}
				}
				cout<<type.name<<" "<<name<<" "<<row<<" "<<col<<endl;
				right=1; 
				Stc[row].push_back({type.name,name,row,col});col++; 
				symb.insert(name);
				break;
			}
		}
		if(!right)Stc[row].push_back({"wrong_type",name,row,col++});
		name="";
		state=0;
	}
	else {
		name+=in[i];
	}
	return 1;
}
int main(){
	freopen("1_in_grammar.txt","r",stdin);
	cin>>n;
	cin.getline(in,10);
	rep(i,1,n)readline_();
	
	for(auto type:types){
		cout<<type.name<<endl;
	}
	while(checkline(++row1,0));
	freopen("2_in_token_seq.txt","w",stdout); 
	int tottoken=0;
	rep(i,1,row1){
		for(auto word:Stc[i]){
			tottoken++;
		}
	}
	cout<<tottoken<<endl;
	rep(i,1,row1){
		for(auto word:Stc[i]){
			cout<<setw(5)<<word.row<<setw(15)<<word.type<<setw(10)<<word.name<<endl;
		}
		cout<<endl; 
	}
	
	return 0; 
} 
