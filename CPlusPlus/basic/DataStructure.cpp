#include<iostream>
#include<vector>
#include<stack>
#include<queue>

// 数组
class ArrayStru {
private:
    int arr[3] = {0x0001,2,3};
public:
    ArrayStru() {    
        std::cout << "Array Struct: " <<std::endl;
        std::cout << "origin array: ";
        for (int i = 0; i < 3; ++i) {
            std::cout << " " << arr[i]  ;
        };

        std::cout << "\n arr[1]: " << arr[1] << std::endl; 
        std::cout<< std::endl;
    }
};

// 向量
class VectorStru {
private:
    // initializtion
    std::vector<int> vec;

public:
    VectorStru(){
        vec.push_back(1);
        for(int i=2; i <= 5; ++i) {
            vec.push_back(i);
        }
        std::cout << "Vector Struct: " <<std::endl;
        std::cout << "Vector Element add: " <<std::endl;
        for(int i=0; i < 5; ++i) {
            std::cout<< vec[i] << " ";
        }

        std::cout << "\n Delete last Element: " <<std::endl;

        vec.pop_back();
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout<< std::endl;
    }
};



class LinkedList {
protected:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

private:
    ListNode* head;
    ListNode* second;
    ListNode* third;
    ListNode* fourth;

public:
    LinkedList(){
        head = new ListNode(1);
        second = new ListNode(2);
        third = new ListNode(3);
        fourth = new ListNode(4);

        head->next = second;
        second->next = third;
        third->next = fourth;

        ListNode* current = head;
        while(current != nullptr) {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* temp = current;
            current = current -> next;
            delete temp;
        }
    }
};

// LIFO st.top() 访问栈顶元素, st.pop() 移出栈顶元素
class StackStru {

private:
    std::stack<int> st;

public:
    StackStru() {
        
    std::cout << "ACT: st.push(1)" << std::endl;
    st.push(1);

    std::cout << "ACT: st.push(2)" << std::endl; 
    st.push(2);


    std::cout << "ACT: st.push(3)" << std::endl; 
    st.push(3);

    std::stack<int> tempStack;
    while(!st.empty()) {
        // 3, 2, 1
        tempStack.push(st.top());
        st.pop();
    }
    std::cout << "stack elements: ";
    while(!tempStack.empty()) {
        // 1, 2, 3
        int element = tempStack.top();
        std::cout<< element << " ";
        // 从栈中取回元素
        st.push(element);
        tempStack.pop();
    }
    std::cout << std::endl;
    // 访问栈顶元素
    std::cout<< "Access the top ele of the stack:" << st.top() <<std::endl;

    st.pop();
    std::cout << "ACT: st.pop() " << std::endl;

    std::cout << "after popping of the top ele: " << st.top() << std::endl;
    }

};


// FIIO Queue 
class QueueStru {
private:
    std::queue<int> que;

public:
    QueueStru() {
         que.push(1);
         std::cout << "ACT: que.push(1) / que.front() : " << que.front();
         std::cout << " / que.back() : " << que.back() << std::endl;

        que.push(2);
        std::cout << "ACT: que.push(2) / que.front() : " << que.front();
        std::cout << " / que.back() : " << que.back() << std::endl;

        que.push(3);
        std::cout << "ACT: que.push(3) / que.front() : " << que.front();
        std::cout << " / que.back() : " << que.back() << std::endl;

        std::cout << "FUll queue Struct Value: ";
        int queSize = que.size();
        for ( int i=0; i < queSize; ++i) {
            int element = que.front();
            std::cout << element << " ";
            que.pop();
            que.push(element);
        }
        std::cout << std::endl;

        std::cout << "Queue First Element: " << que.front() << std::endl;
        std::cout << "Queue End Element: " << que.back() << std::endl;

        que.pop();
        std::cout << "ACT: que.pop()" << " / que.front() : " << que.front();

        std::cout << "After pop first elements: " << que.front() << std::endl;
        std::cout << "After pop last elements: " << que.back() << std::endl;

        std::cout << "FUll queue Struct Value: ";
        int queSize_2 = que.size();
        for ( int i=0; i < queSize_2; ++i) {
            int element = que.front();
            std::cout << element << " ";
            que.pop();
            que.push(element);
        }
        std::cout << std::endl;
    }
};

// 二叉树
class TreeStru {
protected:
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 前序遍历二叉树
void preOrderTravel(TreeNode* root) {
    if(root == nullptr) return;
    std::cout << root -> val << " ";
    preOrderTravel(root->left);
    preOrderTravel(root->right);
}

void destroyTree(TreeNode* root) {
    if(root == nullptr) return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

    TreeNode* root;

public:
    TreeStru() {
        // 创建二叉树
        root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);

        // 前序遍历二叉树
        preOrderTravel(root);
        std::cout << std::endl;

    }

    ~TreeStru() {
        destroyTree(root);
    }
};


int main() {

    // ArrayStru arr;

    // VectorStru VecStru;

    // LinkedList LikedList; 

    // StackStru stack_stru;

    // QueueStru queStru;

    TreeStru tree_stru;
    return 0;
}