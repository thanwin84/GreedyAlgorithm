struct Node {
	char ch;
	int freq;
	Node* left;
	Node* right;
	Node(char symbol, int freq) {
		this->left = nullptr;
		this->right = nullptr;
		this->ch = symbol;
		this->freq = freq;
	}

};
auto comp = [](Node* l, Node* r) {
	return l->freq > r->freq;
};

void preorder(Node* root, string str, vector<string>& result) {
	if (root == nullptr) {
		return;
	}
	if (root->ch != '#') {
		result.push_back(str);

	}
	preorder(root->left, str + "0", result);
	preorder(root->right, str + "1", result);
}

class Solution
{
public:
	vector<string> huffmanCodes(string S, vector<int> f, int N)
	{
		// Code here
		unordered_map<char, int> freq;
		priority_queue<Node*, vector<Node*>, decltype(comp)> minHeap(comp);
		for (int i = 0; i < N; i++) {
			minHeap.push(new Node(S[i],f[i] ));
		}
		while (minHeap.size() > 1) {
			Node* left = minHeap.top();
			minHeap.pop();
			Node* right = minHeap.top();
			minHeap.pop();
			int sum = left->freq + right->freq;
			Node* curr = new Node('#', sum);
			curr->left = left;
			curr->right = right;
			minHeap.push(curr);
		}
		//root of the haffman tree
		Node* root = minHeap.top();
		vector<string> result;
		preorder(root, "", result);
		return result;
	}
};
