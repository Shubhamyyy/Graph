1.
#include<bits/stdc++.h>
using namespace std;
class Trie;
class Node{
	char data;
	unordered_map<char,Node*> m;
	bool isTerminal;

public:
	Node(char d){
		data=d;
		isTerminal=false;
	}
	friend class Trie;
};

class Trie{
	Node *root;

public:
	Trie(){
		root=new Node('\0');
	}
	//insertion
	void insert(string word)
	{
		Node *temp=root;
		for(char ch:word)
		{
			if(temp->m.count(ch)==0)
			{
				Node *n=new Node(ch);
				temp->m[ch]=n;
			}
			temp=temp->m[ch];
		}
		temp->isTerminal=true;
	}
	//searching
	bool search(string word)
	{
		Node *temp=root;
		for(char ch:word)
		{
			if(temp->m.count(ch)==0)
				return false;
			temp=temp->m[ch];
		}
		return temp->isTerminal;
	}
};

int main()
{
	string words[]={"hello","he","apple","aple","news"};
	Trie t;
	for(auto word:words)
		t.insert(word);
	string key;;
	cin>>key;
	cout<<t.search(key)<<endl;
}

2.
#include<bits/stdc++.h>
using namespace std;
class Trie;
class Node{
	char data;
	unordered_map<char,Node*> m;
	bool isTerminal;

public:
	Node(char d){
		data=d;
		isTerminal=false;
	}
	friend class Trie;
};

class Trie{
	Node *root;

public:
	Trie(){
		root=new Node('\0');
	}
	//insertion
	void insert_helper(string word)
	{
		Node *temp=root;
		for(char ch:word)
		{
			if(temp->m.count(ch)==0)
			{
				Node *n=new Node(ch);
				temp->m[ch]=n;
			}
			temp=temp->m[ch];
		}
		temp->isTerminal=true;
	}
	//searching
	bool search(string word)
	{
		Node *temp=root;
		for(char ch:word)
		{
			if(temp->m.count(ch)==0)
				return false;
			temp=temp->m[ch];
		}
		return temp->isTerminal;
	}

	void insert(string word)
	{
		for(int i=0;word[i]!='\0';i++)
			insert_helper(word.substr(i));
	}
};

int main()
{
	string word="hello";
	Trie t;
	t.insert(word);
		
	string key;;
	cin>>key;
	cout<<t.search(key)<<endl;
}

3.
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	char data;
	unordered_map<char,Node*> children;
	bool isTerminal;

	Node(char d){
		data=d;
		isTerminal=false;
	}
};

class Trie{
public:
	Node *root;
	Trie(){
		root=new Node('\0');
	}
	//insertion
	void insert(string word)
	{
		Node *temp=root;
		for(char ch:word)
		{
			if(temp->children.count(ch)==0)
			{
				Node *n=new Node(ch);
				temp->children[ch]=n;
			}
			temp=temp->children[ch];
		}
		temp->isTerminal=true;
	}
};

void searchHelper(Trie t,string document,int i,unordered_map<string,bool> &m)
{
	Node *temp=t.root;
	for(int j=i;j<document.length();j++)
	{
		char ch=document[j];
		if(temp->children.count(ch)==0)
			return;
		temp=temp->children[ch];
		if(temp->isTerminal)
		{
			string out=document.substr(i,j-i+1);
			m[out]=true;
		}
	}
	return;
}

void documentSearch(string document,vector<string> words)
{
	// Create a trie of words
	Trie t;
	for(auto w:words)
		t.insert(w);

	// Searching
	unordered_map<string,bool> m;
	for(int i=0;i<document.length();i++)
		searchHelper(t,document,i,m);

	// Hashmmap
	for(auto w:words)
	{
		if(m[w])
			cout<<w<<" : True"<<endl;
		else
			cout<<w<<" : False"<<endl;
	}
}

int main()
{
	string document="litte cute cat loves to code in c++, java & python";
	vector<string> words={"cute cat","ttle","cat","quick","big"};

	documentSearch(document,words);
}
