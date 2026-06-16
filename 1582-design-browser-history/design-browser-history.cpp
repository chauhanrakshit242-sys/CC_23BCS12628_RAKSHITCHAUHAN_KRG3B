class doublyLinked
{
public:
    string data;
    doublyLinked* next;
    doublyLinked* prev;

    doublyLinked(string data)
    {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

class BrowserHistory {
public:
    doublyLinked* temp;

    BrowserHistory(string homepage) {
        temp = new doublyLinked(homepage);
    }

    void visit(string url) {
        doublyLinked* node = new doublyLinked(url);

        temp->next = node;
        node->prev = temp;

        temp = node;
    }

    string back(int steps) {

        while(steps > 0 && temp->prev != nullptr)
        {
            temp = temp->prev;
            steps--;
        }

        return temp->data;
    }

    string forward(int steps) {

        while(steps > 0 && temp->next != nullptr)
        {
            temp = temp->next;
            steps--;
        }

        return temp->data;
    }
};