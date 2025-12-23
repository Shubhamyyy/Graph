#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	string name;
	vector<string> nbrs;
    Node(){}
	Node(string name){
		this->name=name;
	}
};
class Graph{
	unordered_map<string,Node> map;
public:
	Graph(vector<string> cities){
		for(auto x:cities)
			map[x]=Node(x);
	}
	void addEdge(string x,string y,bool undir=false){
		map[x].nbrs.push_back(y);

		if(undir)
			map[y].nbrs.push_back(x);
	}
	void printAdjList()
    {
    	for(auto x:map)
    	{
    		cout<<x.first<<" --> ";
    		for(auto y:x.second.nbrs)
    			cout<<y<<", ";
    		cout<<endl;
    	}
    }
};

int main()
{
	vector<string> cities={"Delhi","London","Paris","New York"};
	Graph g(cities);

	g.addEdge("Delhi","London");
	g.addEdge("New York","London");
	g.addEdge("Delhi","Paris");
	g.addEdge("Paris","New York");

	g.printAdjList();
}