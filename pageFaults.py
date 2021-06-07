# time:  O(n) and space: O(2C)
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class Solution:
    def pageFaults(self, N, C, pages):
        head = Node('head')
        tail = Node('tail')
        head.next = tail
        tail.prev = head
        cur = head
        storage = {}
        pagefault = 0
        current = head
        count = 0
        for i in range(N):
            if pages[i] not in storage:
                pagefault += 1
                if len(storage) < C:
                    count += 1
                    new_node = Node(pages[i])
                    storage[pages[i]] = new_node
                    before_tail = tail.prev
                    before_tail.next = new_node
                    new_node.prev = before_tail
                    new_node.next = tail
                    tail.prev = new_node
                else:
                    data_to_delete = head.next.data
                    del storage[data_to_delete]
                    after_head = head.next.next
                    head.next = after_head
                    after_head.prev = head
                    # inserting new node at the tail
                    new_node = Node(pages[i])
                    storage[pages[i]] = new_node
                    before_tail = tail.prev
                    before_tail.next = new_node
                    new_node.prev = before_tail
                    new_node.next = tail
                    tail.prev = new_node
            else:
                to_be_replaced = storage[pages[i]]
                before_node = to_be_replaced.prev
                after_node = to_be_replaced.next
                before_node.next = after_node
                after_node.prev = before_node
                before_tail = tail.prev
                before_tail.next = to_be_replaced
                to_be_replaced.prev = before_tail
                to_be_replaced.next = tail
                tail.prev = to_be_replaced
        return pagefault
