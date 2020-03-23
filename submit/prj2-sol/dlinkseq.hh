#ifndef DLINK_SEQ_HH_
#define DLINK_SEQ_HH_
#include "seq.hh"
#include <cassert>
#include <cstddef>
#include <memory>
#include <utility>
template <typename E> class DLinkSeqConstIter;
template <typename E>
class DLinkSeq : public Seq<E> {
    friend class DLinkSeqConstIter<E>;
    struct Node {
        Node* prev;
        Node* next;
        Node(Node* prev, Node* next): prev(prev), next(next) {
            next->prev = this;
            prev->next = this;
        }
        virtual ~Node() {
            next->prev = prev;
            prev->next = next;
        };
    };
    struct DataNode : public Node {
        E value;
        DataNode(const E& e, Node* prev, Node* next): Node(prev, next), value(e) {};
    };
    Node sentinel{&sentinel, &sentinel};
    int len = 0;
    void insertAfter(Node* node, const E& item) {
        new DataNode(item, node, node->next);
        len++;
    }
    E remove(DataNode* node) {
        E value = node->value;
        delete node;
        return value;
    }
public:
    DLinkSeq() = default;
    static SeqPtr<E> make() {
        return std::make_unique<DLinkSeq<E>>();
    }
    ~DLinkSeq() override {
        clear();
    }
    void clear() override {
        while (&sentinel != sentinel.prev) pop();
    }
    void unshift(const E& item) override {
        insertAfter(&sentinel, item);
    }
    void push(const E& item) override {
        insertAfter(sentinel.prev, item);
    }
    E shift() override {
        assert(len && "shift() on empty dlink seq");
        return remove(static_cast<DataNode*>(sentinel.next));
    }
    E pop() override {
        assert(len && "pop() on empty dlink seq");
        return remove(static_cast<DataNode*>(sentinel.prev));
    }
    int size() const override { return len; }
    ConstIterPtr<E> cbegin() const override {
        return std::make_unique<DLinkSeqConstIter<E>>(sentinel.next);
    }
    ConstIterPtr<E> cend() const override {
        return std::make_unique<DLinkSeqConstIter<E>>(&sentinel);
    }
};
template <typename E>
class DLinkSeqConstIter : public ConstIter<E> {
    using Node = typename DLinkSeq<E>::Node;
    using DataNode = typename DLinkSeq<E>::DataNode;
    const Node* current;
public:
    DLinkSeqConstIter(const Node* current): current(current) {}
    DLinkSeqConstIter& operator++() override {
        current = current->next;
        return *this;
    }
    DLinkSeqConstIter& operator--() override {
        current = current->prev;
        return *this;
    }
    operator bool() override {
        return dynamic_cast<const DataNode*>(current);
    }
    const E& operator*() override {
        return static_cast<const DataNode*>(current)->value;
    }
    const E* operator->() override {
        return &static_cast<const DataNode*>(current)->value;
    }
};

#endif
