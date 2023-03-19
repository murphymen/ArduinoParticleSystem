
class ListNode {  
public:
    ListNode *next;
    ListNode *prev;
};


// class IntrusiveList with friend class iterator
class IntrusiveList {
public:
    friend class iterator;
    ListNode *head;
    ListNode *tail;
    int size;

    
    IntrusiveList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    
    void push_back(ListNode *node) {
        if (head == nullptr) {
            head = node;
            tail = node;
            node->next = nullptr;
            node->prev = nullptr;
        } else {
            tail->next = node;
            node->prev = tail;
            node->next = nullptr;
            tail = node;
        }
        size++;
    }
    
    void push_front(ListNode *node) {
        if (head == nullptr) {
            head = node;
            tail = node;
            node->next = nullptr;
            node->prev = nullptr;
        } else {
            head->prev = node;
            node->next = head;
            node->prev = nullptr;
            head = node;
        }
        size++;
    }
    
    void pop_back() {
        if (tail != nullptr) {
            ListNode *node = tail;
            tail = tail->prev;
            if (tail != nullptr) {
                tail->next = nullptr;
            } else {
                head = nullptr;
            }
            //delete node;
            size--;
        }
    }
    
    void pop_front() {
        if (head != nullptr) {
            ListNode *node = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            //delete node;
            size--;
        }
    }
    
    void clear() {
        while (head != nullptr) {
            pop_front();
        }
    }
    

    ListNode* remove(ListNode *node) {
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        } else {
            head = node->next;
        }
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }
        size--;
        return node;
    }
    

   // class iterator
class iterator {
public:
    ListNode *node;
    
    iterator(IntrusiveList *list) {
        node = list->head;
    }
    
    iterator(IntrusiveList *list, ListNode *node) {
        this->node = node;
    }
    
    iterator& operator++() {
        node = node->next;
        return *this;
    }
    
    iterator operator++(int) {
        iterator tmp(*this);
        operator++();
        return tmp;
    }
    
    iterator& operator--() {
        node = node->prev;
        return *this;
    }
    
    iterator operator--(int) {
        iterator tmp(*this);
        operator--();
        return tmp;
    }
    
    bool operator==(const iterator& rhs) {
        return node == rhs.node;
    }
    
    bool operator!=(const iterator& rhs) {
        return node != rhs.node;
    }
    
    ListNode* operator*() {
        return node;
    }
};

    // Method ListNode* remove(iterator it)
    // Remove the node pointed to by the iterator and return this node
    ListNode* remove(IntrusiveList::iterator it) {
        /*
        ListNode *node = it.node;
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        } else {
            head = node->next;
        }
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        } else {
            tail = node->prev;
        }
        size--;
        return node;
        */
        return remove(it.node);
    }

    // Method iterator begin()
    // Return an iterator pointing to the first node in the list
    IntrusiveList::iterator begin() {
        return IntrusiveList::iterator(this);
    }

    // Method iterator end()
    // Return an iterator pointing to the last node in the list
    IntrusiveList::iterator end() {
        return IntrusiveList::iterator(this, nullptr);
    }
};

