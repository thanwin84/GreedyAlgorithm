#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>
#include<set>
#include<unordered_map>
#include<string>
using namespace std;
struct Node {
	string data;
	Node* next;
	Node* prev;
	Node(string data) {
		this->data = data;
		next = nullptr;
		prev = nullptr;
	}
};
class Solution {
public:
	int pageFaults(int N, int C, int pages[]) {
		// code here
		Node* head = new Node("head");
		Node* tail = new Node("tail");
		head->next = tail;
		tail->prev = head;
		unordered_map<string, Node*> storage;
		int page_faults = 0;
		for (int i = 0; i < N; i++) {
			if (!storage.count(to_string(pages[i]))) {
				page_faults++;
				if (storage.size() < C) {
					Node* new_node = new Node(to_string(pages[i]));
					storage[to_string(pages[i])] = new_node;
					Node* before_tail = tail->prev;
					before_tail->next = new_node;
					new_node->prev = before_tail;
					new_node->next = tail;
					tail->prev = new_node;
				}
				else {
					string data_to_delete = head->next->data;
					storage.erase(data_to_delete);
					//deleting second node 
					Node* after_head = head->next->next;
					head->next = after_head;
					after_head->prev = head;
					//adding new node before tail
					Node* new_node = new Node(to_string(pages[i]));
					storage[to_string(pages[i])] = new_node;
					Node* before_tail = tail->prev;
					before_tail->next = new_node;
					new_node->prev = before_tail;
					new_node->next = tail;
					tail->prev = new_node;
				}
			}
			else {
				Node* replace_node = storage[to_string(pages[i])];
				Node* before_node = replace_node->prev;
				Node* after_node = replace_node->next;
				before_node->next = after_node;
				after_node->prev = before_node;
				//adding new node before tail
				Node* before_tail = tail->prev;
				before_tail->next = replace_node;
				replace_node->prev = before_tail;
				replace_node->next = tail;
				tail->prev = replace_node;

			}
		}
		return page_faults;

	}
};
int main() {
	int pages[] = { 5, 0, 1, 3, 2, 4, 1, 0, 5 };
	Solution obj;
	cout <<obj.pageFaults(9, 4, pages);
	
	return 0;
}
