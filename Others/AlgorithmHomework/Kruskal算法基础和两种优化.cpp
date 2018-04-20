#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef int vertex;

struct Node{
	int top, end ,id;
	Node* next;
};
struct TreeNode{
	int id,group;
	vector<TreeNode> child;
};
class Graph{
private: 
	//顶点的标识和其对应的组
	vector<vertex> vec;
	vector<vertex> group;
	//顶点的边
	vector<vector<int>> edge;
	//当前的连接情况
	vector<pair<int, int>> link;
	//图的节点结构 *为kruskal算法的优化算法设计
	vector<Node> node;
	//图的树形存储结构 *为kruskal算法的树型优化设计
	vector<TreeNode> treeNode;
	//结算代价
	int cost;
public:
	Graph();
	void ShowLink();
	void ShowNode();
	void ShowTreeNode();
	void Kruskal();
	void KruskalNode();
	void KruskalTreeNode();
};
Graph::Graph(){
	vec = { 0, 1, 2, 3, 4, 5 };
	group = { 0, 1, 2, 3, 4, 5 };
	edge = { { 0, 1, 6 }, { 0, 2, 1 }, { 0, 3, 5 }, { 1, 2, 5 }, { 1, 4, 3 }, { 2, 3, 5 }, { 2, 4, 6 }, { 2, 5, 4 }, { 3, 5, 2 }, { 4, 5, 6 } };
	cost = 0;
	for (int i = 0; i < vec.size(); i++){
		Node t;
		t.top = vec[i];
		t.end = vec[i];
		t.id = i;
		t.next = NULL;
		node.push_back(t);
	}
	for (int i = 0; i < vec.size(); i++){
		TreeNode t;
		t.id = i;
		t.group = i;
		t.child.push_back(t);
		treeNode.push_back(t);
	}
}
void Graph::ShowLink(){
	for (auto line : link){
		cout << "<" << line.first << "," << line.second <<">"<< " ";
	}
	for (int num : group){
		cout << num;
	}
	cout << "cost:" << cost << endl;

};
void Graph::ShowNode(){
	for (auto line : node){
		cout << "< top:" << line.top << " end:" << line.end <<"> ";
	}
	cout << "cost:" << cost << endl;

};
void Graph::ShowTreeNode(){
	for (auto line : treeNode){
		cout << "< node:" ;
		for (auto t : line.child) cout << t.id;
		cout << ">" <<line.group;
	}
	cout << "cost:" << cost << endl;
};
void Graph::Kruskal(){
	int a, b;
	sort(edge.begin(), edge.end(), [](vector<int> a, vector<int> b){return a[2] < b[2]; });
	for (auto tim : edge){
		if (group[tim[0]] != group[tim[1]]){
			a = min(group[tim[0]], group[tim[1]]);
			b = max(group[tim[0]], group[tim[1]]);
			for (int i = 0; i < group.size();i++){
				if (group[i] == b) {
					group[i] = a;
				}
			}
			link.push_back(make_pair(tim[0], tim[1]));
			cost += tim[2];
			ShowLink();
		}
	}
};
void Graph::KruskalNode(){
	Node *p, *str, *last;
	Node front, back;
	sort(edge.begin(), edge.end(), [](vector<int> a, vector<int> b){return a[2] < b[2]; });
	for (auto tim : edge){
		if (node[tim[0]].top != node[tim[1]].top){
			if (node[tim[0]].top < node[tim[1]].top){
				front = node[tim[0]];
				back = node[tim[1]];
			}
			else{
				front = node[tim[1]];
				back = node[tim[0]];
			}
			str = &node[front.end];
			last = &node[back.top];
			for (p = &node[front.top]; p!=NULL; p = p->next){
				p->end = back.end;
			}
			for (p = &node[back.top]; p != NULL; p = p->next){
				p->top = front.top;
			}
			str->next = last;
			cost += tim[2];
			ShowNode();
		}
	}
}; 
void Graph::KruskalTreeNode(){
	sort(edge.begin(), edge.end(), [](vector<int> a, vector<int> b){return a[2] < b[2]; });
	for (auto tim : edge){
		if (treeNode[tim[0]].group != treeNode[tim[1]].group){
			for (int i = 0; i < treeNode[tim[1]].child.size(); i++){
				 treeNode[tim[0]].child.push_back(treeNode[tim[1]].child[i]);
				treeNode[treeNode[tim[1]].child[i].group].group = treeNode[tim[0]].group;
			}
			for (int i = 0; i < treeNode[tim[0]].child.size() - treeNode[tim[1]].child.size(); i++){
				treeNode[tim[1]].child.push_back(treeNode[tim[0]].child[i]);
			}
			cost += tim[2];
			ShowTreeNode();
		};
	};
};
int main(){
	Graph gra1,gra2,gra3;
	cout << "=====================" << endl;
	cout << "基础版Kruskal算法演示" << endl;
	gra1.Kruskal();
	cout << "=====================" << endl;
	cout << "基于链表节点的Kruskal改进算法演示" << endl;
	gra2.KruskalNode();
	cout << "=====================" << endl;
	cout << "基于树节点的Kruskal改进算法演示" << endl;
	gra3.KruskalTreeNode();
	return 0;
}
