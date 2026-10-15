// 作用：定义各种基础整型常量极限值
#include <climits>
// C++ 封装的 C,stdlib.h, rand(),srand(),设置随机种子;
#include <cstdlib>
// C++ 标准输入输出流库
#include <iostream>
// C++ 内存管理头文件,智能指针相关
#include <memory>
#include <vector>
// 提供 C 风格 IO 函数: `printf()`、`scanf()`、`fopen`、`fclose`等
#include <cstdio>

template <typename K, typename V>
struct SkipListNode {
    K key;
    V val;
    std::vector<SkipListNode*> next;
    // nullptr: 初始化每个元素默认值是空指针
    SkipListNode(K k, V v, int level) : key(k), val(v), next(level, nullptr) {}
};

template <typename K, typename V>
class SkipList {
   public:
    using Node = SkipListNode<K, V>;
    const int MAX_LEVEL = 10;
    int cur_level;
    Node* head;
    Node* tail;

    explicit SkipList(int max_level = 16) : MAX_LEVEL(max_level), cur_level(0) {
        head = new Node(K{}, V{}, MAX_LEVEL);
    }

    // 跳表里面所有 Node 节点永远是堆上 new 出来的，这部分由 SkipList
    // 析构函数统一释放;
    ~SkipList() {
        Node* p = head;
        while (p != nullptr) {
            Node* del = p;
            p = p->next[0];
            delete del;
        }
    }

    int random_level() const {
        int level = 1;
        while ((rand() & 1 == 0) && level < MAX_LEVEL - 1) {
            level++;
        }
        return level;
    }

    bool less(Node* p, K key, V val) {
        if (p->key < key) {
            return true;
        }
        if (p->key == key && p->val < val) {
            return true;
        }
        return false;
    }

    bool insert(K key, V val) {
        std::vector<Node*> update(MAX_LEVEL, nullptr);
        Node* p = head;

        for (int i = cur_level; i >= 0; i--) {
            while (p->next[i] != nullptr && less(p->next[i], key, val)) {
                p = p->next[i];
            }
            update[i] = p;
        }

        p = p->next[0];
        if (p != nullptr && p->key == key && p->val == val) {
            p->val = val;
            return true;
        }

        int new_level = random_level();
        if (new_level > cur_level) {
            for (int i = cur_level + 1; i <= new_level; i++) {
                update[i] = head;
            }
            cur_level = new_level;
        }

        Node* new_node = new Node(key, val, cur_level + 1);
        for (int i = 0; i <= cur_level; i++) {
            new_node->next[i] = update[i]->next[i];
            update[i]->next[i] = new_node;
        }
        return true;
    };

    Node* search(K key, V val) {
        Node* p = head;
        for (int i = cur_level; i >= 0; i--) {
            while (p->next[i] != nullptr && less(p->next[i], key, val)) {
                p = p->next[i];
            }
        }
        p = p->next[0];
        if (p != nullptr && p->key == key && p->val == val) {
            return p;
        }
        return nullptr;
    };

    bool remove(K key, V val) {
        Node* p = head;
        std::vector<Node*> DEL(MAX_LEVEL, nullptr);

        for (int i = cur_level; i >= 0; i--) {
            while (p->next[i] != nullptr && less(p->next[i], key, val)) {
                p = p->next[i];
            }
            DEL[i] = p;
        }

        p = p->next[0];
        if (p == nullptr || !(p->key != key && p->val != val)) {
            return false;
        }

        for (size_t i = 0; i <= cur_level; i++) {
            if (DEL[i]->next[i] != p) {
                break;
            }
            DEL[i]->next[i] = p->next[i];
        }

        delete p;

        while (cur_level > 0 && head->next[cur_level] == nullptr) {
            cur_level--;
        }

        return true;
    };

    void print_list() {
        Node* p = head->next[0];
        while (p != nullptr) {
            std::cout << "key: " << p->key << "  val:" << p->val << std::endl;
            p = p->next[0];
        }
        std::cout << "\n";
    };

    void scan_same_key(K key) {
        Node* p = head;

        for (int i = cur_level; i >= 0; i--) {
            while (p->next[i] != nullptr && p->next[i]->key < key) {
                p = p->next[i];
            }
        }
        p = p->next[0];
        while (p != nullptr && p->key == key) {
            std::cout << "key= " << key << "  val=" << p->val << std::endl;
            p = p->next[0];
        }
        std::cout << '\n';
    }
};

int main() {
    // 智能指针;
    std::unique_ptr<SkipList<int, std::string>> unique_skip =
        std::make_unique<SkipList<int, std::string>>(8);
    std::shared_ptr<SkipList<int, std::string>> shard_skip =
        std::make_shared<SkipList<int, std::string>>(8);

    // 堆上: 裸指针
    auto sk_ptr = new SkipList<int, std::string>(8);
    delete sk_ptr;

    // 栈内存: 自动析构，不用手动管理内存;
    SkipList<int, std::string> sk(8);
    sk.insert(1, "b");
    sk.insert(1, "a");  // key相同 val更小，排在前面
    sk.insert(2, "x");
    sk.insert(1, "c");
    sk.insert(3, "m");

    sk.print_list();
    // 输出顺序：(1,a) (1,b) (1,c) (2,x) (3,m)

    sk.scan_same_key(1);

    auto node = sk.search(1, "b");
    if (node) {
        printf("find key=%d   val=%s  \n", node->key, node->val.c_str());
    }

    sk.remove(1, "b");
    sk.print_list();
    return 0;

    // 编译执行
    // g++ 13.3 支持编译 C++ 20 标准
    // g++ skiplist.cpp -std=c++20 -o skiplist && ./skiplist
    // g++ skiplist.cpp -std=c++20 -fsanitize=address -o skiplist && ./skiplist
}
