#include <iostream>

// 定义链表节点
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;
    ListNode* second;
    ListNode* third;

public:
    // 构造函数，用于初始化链表
    LinkedList() {
        // 创建链表节点
        head = new ListNode(1);
        second = new ListNode(2);
        third = new ListNode(3);

        // 连接节点
        head->next = second;
        second->next = third;

        // 遍历链表并输出节点值
        ListNode* current = head;
        while (current != nullptr) {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // 析构函数，用于释放链表占用的内存
    ~LinkedList() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    // 创建 LinkedList 类的对象
    LinkedList list;
    return 0;
}