#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
using namespace std;
struct Node {
	char ch;
	int freq;
	Node* left;
	Node* right;
};
//function to allocate new treenode
Node* getNode(char ch, int freq, Node* left, Node* right) {
	Node* node = new Node();
	node->ch = ch;
	node->freq = freq;
	node->left = left;
	node->right = right;
	return node;
}
auto comp = [](Node *l, Node*r) {
	return l->freq > r->freq;
};
void encoding(Node* root, string str, unordered_map<char, string> &haffmanTree) {
	if (root == nullptr) {
		return;
	}
	if (!root->left and !root->right) {
		haffmanTree[root->ch] = str;
	}
	encoding(root->left, str + "0", haffmanTree);
	encoding(root->right, str + "1", haffmanTree);
}


void buildTree(string text) {
	//count freq of each char
	unordered_map<char, int> freq;
	for (int i = 0; i < text.size(); i++) {
		freq[text[i]] += 1;
	}
	priority_queue<Node*, vector<Node*>, decltype(comp)> minHeap(comp);
	//create a leafnode for each char
	for (auto pair : freq) {
		minHeap.push(getNode(pair.first, pair.second, nullptr, nullptr));
	}
  //building haffman tree
	while (minHeap.size() != 1) {
		Node* left = minHeap.top();
		minHeap.pop();
		Node* right = minHeap.top();
		minHeap.pop();
		int sum = left->freq + right->freq;
		minHeap.push(getNode('\0', sum, left, right));
	}
	//root of the haffman tree
	Node* root = minHeap.top();
	unordered_map<char, string> haffmanTree;
	encoding(root, "", haffmanTree);
	string encodedMessage;
	for (int i = 0; i < text.size(); i++) {
		encodedMessage += haffmanTree[text[i]];
	}
	for (auto item : encodedMessage) {
		cout << item;
	}
	
	
}
int main() {
	string text = "ABBCDBCCDAABBEEEBEAB";
	buildTree(text);
	return 0;
}
