#include <cassert>
#include <format>
#include <iostream>
#include <string>
#include <unordered_map>

template <typename K, typename V>
struct LRUNode {
    K key;
    V val;
    LRUNode<K, V>* prev{nullptr};
    LRUNode<K, V>* next{nullptr};
    LRUNode(K key, V val) : key(key), val(val) {}
};

template <typename K, typename V>
class LRUCache {
   private:
    size_t cap;
    std::unordered_map<K, LRUNode<K, V>*> hash_map;
    LRUNode<K, V>* head;
    LRUNode<K, V>* tail;

    void moveTohead(LRUNode<K, V>* node) {
        removeNode(node);
        addNode(node);
    }

    void removeNode(LRUNode<K, V>* node) {
        LRUNode<K, V>* prev = node->prev;
        LRUNode<K, V>* next = node->next;
        prev->next = next;
        next->prev = prev;
    }

    void addNode(LRUNode<K, V>* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    // head <-> tail
    // head <-> node <-> tail
    // head <-> node <-> node <-> tail
    K removeTail() {
        LRUNode<K, V>* del_node = tail->prev;
        assert(del_node != head &&
               "removeTail: cache is empty, no node to evict");
        removeNode(del_node);
        K del_key = del_node->key;
        delete del_node;
        return del_key;
    }

   public:
    explicit LRUCache(size_t cap) : cap(cap) {
        head = new LRUNode<K, V>(K{}, V{});
        tail = new LRUNode<K, V>(K{}, V{});
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        LRUNode<K, V>* p = head->next;
        while (p != tail) {
            LRUNode<K, V>* tmp = p;
            p = p->next;
            delete tmp;
        }

        delete head;
        delete tail;
    }

    bool get(K key, V &val) {
        auto it = hash_map.find(key);
        if (it == hash_map.end()) {
            return false;
        }
        LRUNode<K, V>* node = it->second;
        val = node->val;
        moveTohead(node);
        return true;
    }

    bool put(K key, V val) {
        auto it = hash_map.find(key);
        if (it != hash_map.end()) {
            LRUNode<K, V>* node = it->second;
            node->val = val;
            moveTohead(node);
            return true;
        }
        LRUNode<K, V>* node = new LRUNode<K, V>(key, val);
        hash_map[key] = node;
        addNode(node);

        if (hash_map.size() > cap) {
            K del_key = removeTail();
            hash_map.erase(key);
        }
        return true;
    }

    void print_lru() {
        LRUNode<K, V>* node = head->next;
        while (node != tail) {
            std::cout << std::format("[{},{}]", node->key, node->val);
            node = node->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LRUCache<int, std::string> lru(3);
    lru.put(1, "A");
    lru.put(2, "B");
    lru.put(3, "C");
    lru.put(4, "D");
    lru.print_lru();

    std::string v;
    lru.get(2, v);
    std::cout << std::format("[{}] \n", v);

    lru.print_lru();

    lru.put(5, "E");  // 容量满，淘汰1
    lru.print_lru();

    lru.put(2, "B2");  // 更新2的值，挪到头部
    lru.print_lru();
    return 0;

    // g++ lru.cpp -std=c++20 -o lru && ./lru
}