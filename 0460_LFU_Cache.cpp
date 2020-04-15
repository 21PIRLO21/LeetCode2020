#include <ostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/* hard */
//方法二：O(1)
// 用一个hashmap 装 key 和 count
//再用一个hashmap装 count 和对应count的链表头
//每次key更新时，将node 装到对应count的链表头里边
//每次要删除时，从最小count的链表的最后边删除

//例如每次get, 利用key 从keyToListNode获取到 MyListNode，此时可得到count，再通过count从countToList
//可以获取到节点所属对应的链表，然后再从链接里边拿掉该节点，并将该节点添加到新的count对应的链表里边

class MyListNode {
public :
    MyListNode (int count, int key, int value) : _count(count), _key(key),  _value(value),
                             _next(nullptr), _pre(nullptr){

    }

    int _count;
    int _key;
    int _value;

    MyListNode* _next;
    MyListNode* _pre;
};

class MyList {
public :
    MyList(): _size(0), _head(nullptr), _tail(nullptr) {

    }

    //只是从链表里边拿掉节点，并不删除
    void remove(MyListNode* node) {
        if (node == nullptr)
            return;
        

        MyListNode*pre = node->_pre;
        MyListNode* next = node->_next;
        if (pre)
            pre->_next = next;
        if (next)
            next->_pre = pre;

        if (_head == node)
            _head = node->_next;
        if (_tail == node)
            _tail = node->_pre;
    
        node->_next = nullptr;
        node->_pre = nullptr;
        --_size;
        return;
    }

    void leftInsert(MyListNode* node) {
        if (node == nullptr)
            return;
        
        node->_next = _head;
        node->_pre = nullptr;
        if (_head)
            _head->_pre = node;
        
        _head = node;
        if (_tail == nullptr)
            _tail = _head;
        
        ++_size;
    }

    void rightInsert(MyListNode* node) {
        if (node == nullptr)
            return;

        if (_tail == nullptr) {
            if (_head == nullptr) {
                _tail = _head = node;
                node->_next = node->_pre = nullptr;
                ++_size;
            } else {
                cout << "Error:: _tail == nullptr && _head != nullptr " << endl;
            }
        
            return;
        }

        node->_pre = _tail;
        node->_next = nullptr; 
        _tail = node;
        ++_size;
        return;
    }

    void rightErase() {
        if (_head == nullptr)
            return;
        if (_tail == nullptr)
            return;

        if (_head == _tail) {
            delete _tail;
            _head = _tail = nullptr;
            _size = 0;
            return;
        }

        //至少有2个节点
        MyListNode* temp = _tail;
        temp->_pre->_next = nullptr;
        _tail = temp->_pre;
        delete temp;
        --_size;

        return;
    }

    MyListNode* getRight() {
        return _tail;
    }

    int size() {
        return _size;
    }
    void show() {
         MyListNode* temp = _head;
         while (temp != nullptr) {
             cout << "key : " << temp->_key << ", value : " << temp->_value << ", count : " << temp->_count << endl;
             temp = temp->_next;
         }
    }

private:
    int _size;
    MyListNode* _head;
    MyListNode* _tail;
};


class LFUCache {
public:
    LFUCache(int capacity) {
        _capacity = capacity;
        _minCount = 1;
    }
    
    int get(int key) {
        unordered_map<int, MyListNode*> ::iterator it0 = keyToListNode.find(key);
        //找不到
        if (it0 == keyToListNode.end())
            return -1;

        MyListNode* targetNode = it0->second;
        if (targetNode == nullptr) {
            cout << "Error:: TargetNode == nullptr" << endl;
            return -1;
        }

        unordered_map<int, MyList*>::iterator it1 = countToList.find(targetNode->_count);
        if (it1 == countToList.end())
            return -1;
        
        MyList* list = it1->second;
        if (list) {
            list->remove(targetNode);
            //只剩最后一个节点删掉，可以把TargetNode->_count对应的键值对一起删掉
            if (list->size() < 1) {
                delete list;
                countToList.erase(targetNode->_count);
            }
        }
            
        
        targetNode->_count++;
        unordered_map<int, MyList*>::iterator it2 =  countToList.find(targetNode->_count);
        if (it2 == countToList.end()) {
            //之前还没有数值为count的节点，创建第一个
            MyList* myList = new MyList;
            myList->leftInsert(targetNode);
            countToList[targetNode->_count] = myList;
        } else {
            it2->second->leftInsert(targetNode);
        }

        //更新_minCount
        if (countToList.find(_minCount) != countToList.end()) {
            _minCount = _minCount;//可以保持不变
        } else {
            _minCount = _minCount + 1;//既然countToList[_minCount] 变了，那肯定是由于 前边的 countToList.erase(targetNode->_count)引起的，
        }

        return targetNode->_value;
    }
    
    void put(int key, int value) {
        if (_capacity < 1)
            return;

        unordered_map<int, MyListNode*> ::iterator it0 = keyToListNode.find(key);
        //找到,本来已有
        if (it0 != keyToListNode.end()) {
            MyListNode* targetNode = it0->second;
            targetNode->_value = value;
            unordered_map<int, MyList*>::iterator it1 = countToList.find(targetNode->_count);
            if (it1 == countToList.end())
                return ;

            MyList* list = it1->second;
            if (list) {
                list->remove(targetNode);
                //只剩最后一个节点删掉，可以把TargetNode->_count对应的键值对一起删掉
                if (list->size() < 1) {
                    delete list;
                    countToList.erase(targetNode->_count);
                }
            }

            targetNode->_count++;
            unordered_map<int, MyList*>::iterator it2 =  countToList.find(targetNode->_count);
            if (it2 == countToList.end()) {
                //之前还没有数值为count的节点，创建第一个
                MyList* myList = new MyList;
                myList->leftInsert(targetNode);
                countToList[targetNode->_count] = myList;
            } else {
                it2->second->leftInsert(targetNode);
            }

        } else {
            MyListNode* myListNode = new MyListNode(1, key, value);

            //满了，得先删掉一个
            if (keyToListNode.size() == _capacity) {
                    unordered_map<int, MyList*>::iterator it3 = countToList.find(_minCount);//这个肯定可以找到
                    MyList* list2 = it3->second;
                    MyListNode* node = list2->getRight();
                    if (node) {
                         keyToListNode.erase(node->_key);
                    }
                    list2->rightErase();
                    if (list2->size() < 1 && _minCount > 1) {
                        delete list2;
                        countToList.erase(_minCount);
                    }
                   
            }

            //插入 
            MyList* list3 = nullptr;
            if (countToList.find(1) == countToList.end()) {
                list3 = new MyList;
                countToList[1] = list3;
            } else {
                list3 = countToList.find(1)->second;
            }
            list3->leftInsert(myListNode);//节点插入map里边的链表
             keyToListNode[key] = myListNode;//节点插入map里边
        }
        
       

        //更新_minCount 
        if (countToList.find(1) != countToList.end()) {
            _minCount = 1;
        } else  if (countToList.find(_minCount) != countToList.end()) {
            _minCount = _minCount;//可以保持不变
        } else {
            _minCount = _minCount + 1;//既然countToList[_minCount] 变了，那肯定是由于 前边的 countToList.erase(targetNode->_count)引起的，
        }
    }

    void showList() {
        for (auto it : countToList) {
            MyList* list= it.second;
            cout << "count : " << it.first << ", _minCount : " << _minCount << ",  list : " << endl;
            list->show();
        }

        return;
    }

private:
    int _capacity;
    int _minCount;
    unordered_map<int, MyListNode*>  keyToListNode;
    unordered_map<int, MyList* > countToList;

};
