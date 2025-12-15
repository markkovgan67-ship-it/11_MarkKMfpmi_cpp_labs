#include "forward_list_impl.h"


ForwardList::ForwardList() : head_(nullptr), size_(0) {
}

ForwardList::ForwardList(const ForwardList& rhs) : head_(nullptr), size_(0) {
    if (rhs.head_ == nullptr) {
        return;
    }

    
    Node* current_rhs = rhs.head_;
    head_ = new Node(current_rhs->value_);
    Node* current = head_;
    size_ = 1;

    current_rhs = current_rhs->next_;

    
    while (current_rhs != nullptr) {
        current->next_ = new Node(current_rhs->value_);
        current = current->next_;
        current_rhs = current_rhs->next_;
        ++size_;
    }
}


ForwardList::ForwardList(size_t count, int value) : head_(nullptr), size_(0) {
    for (size_t i = 0; i < count; ++i) {
        PushFront(value);
    }
}


ForwardList::ForwardList(std::initializer_list<int> init) : head_(nullptr), size_(0) {
   
    for (auto it = init.end(); it != init.begin();) {
        --it;
        PushFront(*it);
    }
}


ForwardList& ForwardList::operator=(const ForwardList& rhs) {
    if (this == &rhs) {
        return *this;
    }

    
    Clear();

    
    if (rhs.head_ != nullptr) {
        Node* current_rhs = rhs.head_;
        head_ = new Node(current_rhs->value_);
        Node* current = head_;
        size_ = 1;

        current_rhs = current_rhs->next_;

        while (current_rhs != nullptr) {
            current->next_ = new Node(current_rhs->value_);
            current = current->next_;
            current_rhs = current_rhs->next_;
            ++size_;
        }
    }

    return *this;
}


ForwardList::~ForwardList() {
    Clear();
}


void ForwardList::PushFront(int value) {
    Node* new_node = new Node(value);
    new_node->next_ = head_;
    head_ = new_node;
    ++size_;
}


void ForwardList::PopFront() {
    if (head_ == nullptr) {
        return;
    }

    Node* temp = head_;
    head_ = head_->next_;
    delete temp;
    --size_;
}


void ForwardList::Remove(int value) {
    if (head_ == nullptr) {
        return;
    }

   
    while (head_ != nullptr && head_->value_ == value) {
        PopFront();
    }

    if (head_ == nullptr) {
        return;
    }

   
    Node* current = head_;
    while (current->next_ != nullptr) {
        if (current->next_->value_ == value) {
            Node* temp = current->next_;
            current->next_ = temp->next_;
            delete temp;
            --size_;
        }
        else {
            current = current->next_;
        }
    }
}


void ForwardList::Clear() {
    while (head_ != nullptr) {
        Node* temp = head_;
        head_ = head_->next_;
        delete temp;
    }
    size_ = 0;
}


bool ForwardList::FindByValue(int value) {
    Node* current = head_;
    while (current != nullptr) {
        if (current->value_ == value) {
            return true;
        }
        current = current->next_;
    }
    return false;
}

/
void ForwardList::Print(std::ostream& out) {
    Node* current = head_;
    while (current != nullptr) {
        out << current->value_;
        if (current->next_ != nullptr) {
            out << " ";
        }
        current = current->next_;
    }
}

int ForwardList::Front() const {
    if (head_ == nullptr) {
        return 0;
    }
    return head_->value_;
}


size_t ForwardList::Size() const {
    return size_;
}

bool ForwardList::IsEmpty() const {
    return head_ == nullptr;
}
