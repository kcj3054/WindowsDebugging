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
	NodeRef root = make_shared<Node>("R1���߽�");
	{
		NodeRef node = make_shared<Node>("��������");
		root->children.push_back(node);
		{
			NodeRef leaf1 = make_shared<Node>("����");
			NodeRef leaf2 = make_shared<Node>("����");
			NodeRef leaf3 = make_shared<Node>("���丮");
			
			node->children.push_back(leaf1);
			node->children.push_back(leaf2);
			node->children.push_back(leaf3);

		}
		// ..
		
		// ..
	}

	return root;
}

//��½� ���� ������ �� ������� depth �־��ָ����~ 
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

// ���� (depth) : ��Ʈ��忡�� � ��忡 �����ϱ� ���� ���ľ� �ϴ� ������ �� , �� ~ ������ �� ~ ���� ���� 
// ���� (height) : ���� ����� �ִ� ����� ���� (max (depth))
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