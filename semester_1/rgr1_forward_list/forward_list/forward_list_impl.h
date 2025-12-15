#pragma once

#include <iterator>
#include <iostream>

class ForwardList {

private:
    struct Node {
        int value_;  
        Node* next_;

        explicit Node(int value) : value_(value), next_(nullptr) {
        }
    };

public:
    class ForwardListIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int; 
        using pointer = value_type*;
        using reference = value_type&;

        explicit ForwardListIterator(Node* position) : position_(position) {
        }

        ForwardListIterator& operator++() { 
            if (position_ != nullptr) {
                position_ = position_->next_;
            }
            return *this;
        }

        ForwardListIterator operator++(int) {  
            ForwardListIterator retval = *this;
            ++(*this);
            return retval;
        }

        bool operator==(const ForwardListIterator& other) const {
            return position_ == other.position_;
        }

        bool operator!=(const ForwardListIterator& other) const {
            return !(*this == other);
        }

        reference operator*() const {
            return position_->value_;
        }

        pointer operator->() {
            return &position_->value_;
        }

    private:
        Node* position_;
    };

    class ConstForwardListIterator {
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = int;  
        using pointer = const value_type*;
        using reference = const value_type&;

        explicit ConstForwardListIterator(const Node* position) : position_(position) {
        }

        ConstForwardListIterator& operator++() {
            if (position_ != nullptr) {
                position_ = position_->next_;
            }
            return *this;
        }

        ConstForwardListIterator operator++(int) {
            ConstForwardListIterator retval = *this;
            ++(*this);
            return retval;
        }

        bool operator==(const ConstForwardListIterator& other) const {
            return position_ == other.position_;
        }

        bool operator!=(const ConstForwardListIterator& other) const {
            return !(*this == other);
        }

        reference operator*() const {
            return position_->value_;
        }

        pointer operator->() const {
            return &position_->value_;
        }

    private:
        const Node* position_;
    };

    ForwardListIterator begin() {
        return ForwardListIterator(head_);
    }

    ForwardListIterator end() {
        return ForwardListIterator(nullptr);
    }

    ConstForwardListIterator begin() const {
        return ConstForwardListIterator(head_);
    }

    ConstForwardListIterator end() const {
        return ConstForwardListIterator(nullptr);
    }


    ForwardList();

    ForwardList(const ForwardList& rhs);
    ForwardList(size_t count, int value);  

   
    ForwardList(std::initializer_list<int> init);  

    ForwardList& operator=(const ForwardList& rhs);

   
    ~ForwardList();

    
    void PushFront(int value);  
    void PopFront();
   
    void Remove(int value);  

    void Clear();

  
    bool FindByValue(int value);
    void Print(std::ostream& out);

    
    int Front() const;  

  
    size_t Size() const;


    bool IsEmpty() const;

private:
    Node* head_;
    size_t size_;
};
