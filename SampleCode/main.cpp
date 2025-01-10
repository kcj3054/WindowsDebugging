#include <iostream>
#include <queue>
#include <stack>
#include <memory>

using namespace std;

// using NodeRef = shared_ptr<struct Node>();
using NodeRef = shared_ptr<struct Node>;

struct Node
{
	Node() = default;
	Node(const string& data) : _data(data) { }

	string _data;
	vector<NodeRef> children;
};

NodeRef CreateTree()
{
	NodeRef root = make_shared<Node>("R1개발실");
	{
		NodeRef node = make_shared<Node>("디자인팀");
		root->children.push_back(node);
		{
			NodeRef leaf1 = make_shared<Node>("전투");
			NodeRef leaf2 = make_shared<Node>("경제");
			NodeRef leaf3 = make_shared<Node>("스토리");
			
			node->children.push_back(leaf1);
			node->children.push_back(leaf2);
			node->children.push_back(leaf3);

		}
		// ..
		
		// ..
	}

	return root;
}

//출력시 계층 구조를 잘 만들려면 depth 넣어주면되지~ 
void PrintTree(NodeRef root, int depth)
{
	for (int i = 0; i < depth; ++i)
		cout << "-";

	cout << root->_data << endl;

	for (auto& child : root->children)
	{
		PrintTree(child, depth + 1);
	}
}

// 깊이 (depth) : 루트노드에서 어떤 노드에 도달하기 위해 거쳐야 하는 간선의 수 , 오 ~ 간선의 수 ~ 예시 좋다 
// 높이 (height) : 가장 깊숙히 있는 노드의 깊이 (max (depth))
int GetHeight(NodeRef node)
{
	int height = 1;



	return height;
}

int main()
{
	NodeRef node = CreateTree();

	PrintTree(node, 0);

	return 0;
}