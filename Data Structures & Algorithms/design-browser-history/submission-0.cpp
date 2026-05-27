class Node {
public:
    Node(std::string str) : page(str) {}
    ~Node();

    std::string page;
    Node* next = nullptr;
    Node* prev = nullptr;
};

class BrowserHistory {
public:
    Node* current_page = nullptr;
    BrowserHistory(string homepage) {
        /*
            Linked list doubly
            visit adds more pages to doubly linked list
            needs to remove all forward pointers
            just adds to the end

            back traverses steps to the back and returns the string
            need a pointer that stays at that position
        */

        current_page = new Node(homepage);
    }
    
    void visit(string url) {
        Node* new_page = new Node(url);
        current_page->next = new_page;
        new_page->prev = current_page;
        current_page = new_page;
    }
    
    string back(int steps) {
        while (current_page->prev && steps > 0) {
            current_page = current_page->prev;
            steps--;
        }

        return current_page->page;
    }
    
    string forward(int steps) {
        while (current_page->next && steps > 0) {
            current_page = current_page->next;
            steps--;
        }

        return current_page->page;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */