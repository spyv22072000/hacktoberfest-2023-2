//Node Structure:
Each node in the linked list will contain data, priority, and a pointer to the next node.//

class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int d, int p) : data(d), priority(p), next(nullptr) {}
};
//Priority Queue Class:
This class will have methods for enqueue, dequeue, and isEmpty.//
class PriorityQueue {
private:
    Node* head;

public:
    PriorityQueue() : head(nullptr) {}

    bool isEmpty() {
        return head == nullptr;
    }

    // Add element based on priority
    void enqueue(int data, int priority) {
        Node* newNode = new Node(data, priority);
        if (!head || priority < head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->priority <= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    // Remove the element with the highest priority
    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Priority Queue is empty!" << std::endl;
            return -1; // Error value, ideally should throw exception or handle error
        }
        Node* temp = head;
        head = head->next;
        int data = temp->data;
        delete temp;
        return data;
    }

    ~PriorityQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
int main() {
    PriorityQueue pq;
    
    pq.enqueue(10, 2);
    pq.enqueue(20, 1);
    pq.enqueue(30, 3);

    std::cout << pq.dequeue() << std::endl; // Should print 20 (highest priority 1)
    std::cout << pq.dequeue() << std::endl; // Should print 10 (next highest priority 2)
    std::cout << pq.dequeue() << std::endl; // Should print 30 (next highest priority 3)

    return 0;
}
//output 
20
10
30//
