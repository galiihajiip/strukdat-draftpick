/*
================================================================================
    EAS STRUKTUR DATA - DRAFT PICK MOBILE LEGENDS
    
    Implementasi:
    - Abstract Data Type (ADT)
    - Rekursif
    - Single Linked List
    - Double Linked List
    - Stack
    - Queue
    - Sorting (Quick Sort, Merge Sort)
    - Binary Search Tree (BST)
    - AVL Tree
    - Priority Queue
    
    Fitur: Insert, Delete, Search, View, Export to .txt
================================================================================
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <algorithm>
using namespace std;

// ==================== ABSTRACT DATA TYPE (ADT) ====================
struct Hero {
    string name;
    string role;
    int power;
    int pickRate;
    
    Hero() : name(""), role(""), power(0), pickRate(0) {}
    Hero(string n, string r, int p, int pr) : name(n), role(r), power(p), pickRate(pr) {}
};

// ==================== SINGLE LINKED LIST ====================
struct SLLNode {
    Hero data;
    SLLNode* next;
    SLLNode(Hero h) : data(h), next(nullptr) {}
};

class SingleLinkedList {
private:
    SLLNode* head;
    int size;
public:
    SingleLinkedList() : head(nullptr), size(0) {}
    
    void insert(Hero h) {
        SLLNode* newNode = new SLLNode(h);
        if (!head) {
            head = newNode;
        } else {
            SLLNode* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        size++;
    }
    
    bool remove(string name) {
        if (!head) return false;
        if (head->data.name == name) {
            SLLNode* temp = head;
            head = head->next;
            delete temp;
            size--;
            return true;
        }
        SLLNode* temp = head;
        while (temp->next && temp->next->data.name != name) {
            temp = temp->next;
        }
        if (temp->next) {
            SLLNode* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            size--;
            return true;
        }
        return false;
    }
    
    Hero* search(string name) {
        SLLNode* temp = head;
        while (temp) {
            if (temp->data.name == name) return &temp->data;
            temp = temp->next;
        }
        return nullptr;
    }
    
    void display() {
        SLLNode* temp = head;
        int i = 1;
        while (temp) {
            cout << setw(3) << i++ << ". " << setw(15) << left << temp->data.name 
                 << " | " << setw(10) << temp->data.role 
                 << " | Power: " << setw(3) << temp->data.power << endl;
            temp = temp->next;
        }
    }
    
    bool isEmpty() { return head == nullptr; }
    int getSize() { return size; }
    SLLNode* getHead() { return head; }
};

// ==================== DOUBLE LINKED LIST ====================
struct DLLNode {
    Hero data;
    DLLNode* prev;
    DLLNode* next;
    DLLNode(Hero h) : data(h), prev(nullptr), next(nullptr) {}
};

class DoubleLinkedList {
private:
    DLLNode* head;
    DLLNode* tail;
    int size;
public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    
    void insertBack(Hero h) {
        DLLNode* newNode = new DLLNode(h);
        if (!tail) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    
    bool remove(string name) {
        DLLNode* temp = head;
        while (temp) {
            if (temp->data.name == name) {
                if (temp->prev) temp->prev->next = temp->next;
                else head = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                else tail = temp->prev;
                delete temp;
                size--;
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    
    void displayForward() {
        DLLNode* temp = head;
        int i = 1;
        while (temp) {
            cout << setw(3) << i++ << ". " << setw(15) << left << temp->data.name 
                 << " | " << setw(10) << temp->data.role << endl;
            temp = temp->next;
        }
    }
    
    int getSize() { return size; }
    DLLNode* getHead() { return head; }
};

// ==================== STACK ====================
struct StackNode {
    string action;
    Hero hero;
    StackNode* next;
    StackNode(string a, Hero h) : action(a), hero(h), next(nullptr) {}
};

class Stack {
private:
    StackNode* top;
    int size;
public:
    Stack() : top(nullptr), size(0) {}
    
    void push(string action, Hero h) {
        StackNode* newNode = new StackNode(action, h);
        newNode->next = top;
        top = newNode;
        size++;
    }
    
    bool pop(string &action, Hero &h) {
        if (!top) return false;
        action = top->action;
        h = top->hero;
        StackNode* temp = top;
        top = top->next;
        delete temp;
        size--;
        return true;
    }
    
    bool isEmpty() { return top == nullptr; }
    
    void display() {
        StackNode* temp = top;
        cout << "\n=== HISTORY (Stack) ===" << endl;
        while (temp) {
            cout << "- " << temp->action << ": " << temp->hero.name << endl;
            temp = temp->next;
        }
    }
};

// ==================== QUEUE ====================
struct QueueNode {
    string team;
    string phase;
    QueueNode* next;
    QueueNode(string t, string p) : team(t), phase(p), next(nullptr) {}
};

class Queue {
private:
    QueueNode* front;
    QueueNode* rear;
    int size;
public:
    Queue() : front(nullptr), rear(nullptr), size(0) {}
    
    void enqueue(string team, string phase) {
        QueueNode* newNode = new QueueNode(team, phase);
        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    
    bool dequeue(string &team, string &phase) {
        if (!front) return false;
        team = front->team;
        phase = front->phase;
        QueueNode* temp = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        size--;
        return true;
    }
    
    bool isEmpty() { return front == nullptr; }
};


// ==================== BINARY SEARCH TREE (BST) ====================
struct BSTNode {
    Hero data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(Hero h) : data(h), left(nullptr), right(nullptr) {}
};

class BST {
private:
    BSTNode* root;
    
    BSTNode* insertRec(BSTNode* node, Hero h) {
        if (!node) return new BSTNode(h);
        if (h.name < node->data.name)
            node->left = insertRec(node->left, h);
        else if (h.name > node->data.name)
            node->right = insertRec(node->right, h);
        return node;
    }
    
    BSTNode* minValueNode(BSTNode* node) {
        BSTNode* current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }
    
    BSTNode* deleteRec(BSTNode* node, string name) {
        if (!node) return node;
        if (name < node->data.name)
            node->left = deleteRec(node->left, name);
        else if (name > node->data.name)
            node->right = deleteRec(node->right, name);
        else {
            if (!node->left) {
                BSTNode* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                BSTNode* temp = node->left;
                delete node;
                return temp;
            }
            BSTNode* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteRec(node->right, temp->data.name);
        }
        return node;
    }
    
    BSTNode* searchRec(BSTNode* node, string name) {
        if (!node || node->data.name == name) return node;
        if (name < node->data.name)
            return searchRec(node->left, name);
        return searchRec(node->right, name);
    }
    
    void inorderRec(BSTNode* node) {
        if (node) {
            inorderRec(node->left);
            cout << setw(15) << left << node->data.name 
                 << " | " << setw(10) << node->data.role 
                 << " | Power: " << node->data.power << endl;
            inorderRec(node->right);
        }
    }
    
    void preorderRec(BSTNode* node) {
        if (node) {
            cout << setw(15) << left << node->data.name 
                 << " | " << setw(10) << node->data.role << endl;
            preorderRec(node->left);
            preorderRec(node->right);
        }
    }
    
    void postorderRec(BSTNode* node) {
        if (node) {
            postorderRec(node->left);
            postorderRec(node->right);
            cout << setw(15) << left << node->data.name 
                 << " | " << setw(10) << node->data.role << endl;
        }
    }
    
    int countRec(BSTNode* node) {
        if (!node) return 0;
        return 1 + countRec(node->left) + countRec(node->right);
    }
    
    void exportRec(BSTNode* node, ofstream &file) {
        if (node) {
            exportRec(node->left, file);
            file << node->data.name << "," << node->data.role << "," 
                 << node->data.power << "," << node->data.pickRate << endl;
            exportRec(node->right, file);
        }
    }

public:
    BST() : root(nullptr) {}
    
    void insert(Hero h) { root = insertRec(root, h); }
    void remove(string name) { root = deleteRec(root, name); }
    
    Hero* search(string name) {
        BSTNode* result = searchRec(root, name);
        return result ? &result->data : nullptr;
    }
    
    void displayInorder() {
        cout << "\n=== BST Inorder (Sorted A-Z) ===" << endl;
        inorderRec(root);
    }
    
    void displayPreorder() {
        cout << "\n=== BST Preorder ===" << endl;
        preorderRec(root);
    }
    
    void displayPostorder() {
        cout << "\n=== BST Postorder ===" << endl;
        postorderRec(root);
    }
    
    int count() { return countRec(root); }
    
    void exportToFile(string filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << "=== BST Hero Data ===" << endl;
            file << "Name,Role,Power,PickRate" << endl;
            exportRec(root, file);
            file.close();
            cout << "Data exported to " << filename << endl;
        }
    }
    
    BSTNode* getRoot() { return root; }
};

// ==================== AVL TREE ====================
struct AVLNode {
    Hero data;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(Hero h) : data(h), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;
    
    int height(AVLNode* node) {
        return node ? node->height : 0;
    }
    
    int getBalance(AVLNode* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }
    
    AVLNode* rightRotate(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }
    
    AVLNode* leftRotate(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }
    
    AVLNode* insertRec(AVLNode* node, Hero h) {
        if (!node) return new AVLNode(h);
        
        if (h.power < node->data.power)
            node->left = insertRec(node->left, h);
        else if (h.power > node->data.power)
            node->right = insertRec(node->right, h);
        else {
            if (h.name < node->data.name)
                node->left = insertRec(node->left, h);
            else
                node->right = insertRec(node->right, h);
        }
        
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);
        
        // Left Left
        if (balance > 1 && h.power < node->left->data.power)
            return rightRotate(node);
        // Right Right
        if (balance < -1 && h.power > node->right->data.power)
            return leftRotate(node);
        // Left Right
        if (balance > 1 && h.power > node->left->data.power) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // Right Left
        if (balance < -1 && h.power < node->right->data.power) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node;
    }
    
    AVLNode* minValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left)
            current = current->left;
        return current;
    }
    
    AVLNode* deleteRec(AVLNode* node, string name) {
        if (!node) return node;
        
        if (name < node->data.name)
            node->left = deleteRec(node->left, name);
        else if (name > node->data.name)
            node->right = deleteRec(node->right, name);
        else {
            if (!node->left || !node->right) {
                AVLNode* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                AVLNode* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = deleteRec(node->right, temp->data.name);
            }
        }
        
        if (!node) return node;
        
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);
        
        if (balance > 1 && getBalance(node->left) >= 0)
            return rightRotate(node);
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && getBalance(node->right) <= 0)
            return leftRotate(node);
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        
        return node;
    }
    
    AVLNode* searchRec(AVLNode* node, string name) {
        if (!node) return nullptr;
        if (node->data.name == name) return node;
        AVLNode* left = searchRec(node->left, name);
        if (left) return left;
        return searchRec(node->right, name);
    }
    
    void inorderRec(AVLNode* node, int &idx) {
        if (node) {
            inorderRec(node->left, idx);
            cout << setw(3) << idx++ << ". " << setw(15) << left << node->data.name 
                 << " | " << setw(10) << node->data.role 
                 << " | Power: " << setw(3) << node->data.power << endl;
            inorderRec(node->right, idx);
        }
    }
    
    void exportRec(AVLNode* node, ofstream &file) {
        if (node) {
            exportRec(node->left, file);
            file << node->data.name << "," << node->data.role << "," 
                 << node->data.power << "," << node->data.pickRate << endl;
            exportRec(node->right, file);
        }
    }
    
    int countRec(AVLNode* node) {
        if (!node) return 0;
        return 1 + countRec(node->left) + countRec(node->right);
    }

public:
    AVLTree() : root(nullptr) {}
    
    void insert(Hero h) { root = insertRec(root, h); }
    void remove(string name) { root = deleteRec(root, name); }
    
    Hero* search(string name) {
        AVLNode* result = searchRec(root, name);
        return result ? &result->data : nullptr;
    }
    
    void displayInorder() {
        cout << "\n=== AVL Tree (Sorted by Power) ===" << endl;
        int idx = 1;
        inorderRec(root, idx);
    }
    
    int count() { return countRec(root); }
    
    void exportToFile(string filename) {
        ofstream file(filename);
        if (file.is_open()) {
            file << "=== AVL Tree Hero Data (Sorted by Power) ===" << endl;
            file << "Name,Role,Power,PickRate" << endl;
            exportRec(root, file);
            file.close();
            cout << "Data exported to " << filename << endl;
        }
    }
    
    AVLNode* getRoot() { return root; }
};


// ==================== PRIORITY QUEUE (untuk Hero Recommendation) ====================
struct PQNode {
    Hero data;
    int priority;
    PQNode* next;
    PQNode(Hero h, int p) : data(h), priority(p), next(nullptr) {}
};

class PriorityQueue {
private:
    PQNode* head;
    int size;
public:
    PriorityQueue() : head(nullptr), size(0) {}
    
    void enqueue(Hero h, int priority) {
        PQNode* newNode = new PQNode(h, priority);
        if (!head || priority > head->priority) {
            newNode->next = head;
            head = newNode;
        } else {
            PQNode* temp = head;
            while (temp->next && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }
    
    bool dequeue(Hero &h) {
        if (!head) return false;
        h = head->data;
        PQNode* temp = head;
        head = head->next;
        delete temp;
        size--;
        return true;
    }
    
    void display() {
        PQNode* temp = head;
        int i = 1;
        cout << "\n=== Priority Queue (Hero Recommendations) ===" << endl;
        while (temp) {
            cout << setw(3) << i++ << ". " << setw(15) << left << temp->data.name 
                 << " | Priority: " << temp->priority << endl;
            temp = temp->next;
        }
    }
    
    bool isEmpty() { return head == nullptr; }
    int getSize() { return size; }
};

// ==================== SORTING ALGORITHMS ====================
class Sorting {
public:
    // Quick Sort untuk array Hero
    static void quickSort(Hero arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    static int partition(Hero arr[], int low, int high) {
        int pivot = arr[high].power;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j].power >= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
    
    // Merge Sort untuk array Hero
    static void mergeSort(Hero arr[], int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }
    
    static void merge(Hero arr[], int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;
        Hero* L = new Hero[n1];
        Hero* R = new Hero[n2];
        
        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];
        
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i].name <= R[j].name) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];
        
        delete[] L;
        delete[] R;
    }
};

// ==================== REKURSIF FUNCTIONS ====================
int countHeroByRoleRec(Hero arr[], int n, string role) {
    if (n <= 0) return 0;
    int count = (arr[n-1].role == role) ? 1 : 0;
    return count + countHeroByRoleRec(arr, n-1, role);
}

int sumPowerRec(Hero arr[], int n) {
    if (n <= 0) return 0;
    return arr[n-1].power + sumPowerRec(arr, n-1);
}

void printHeroRec(Hero arr[], int n, int idx) {
    if (idx >= n) return;
    cout << setw(3) << idx+1 << ". " << setw(15) << left << arr[idx].name 
         << " | " << setw(10) << arr[idx].role 
         << " | Power: " << arr[idx].power << endl;
    printHeroRec(arr, n, idx+1);
}


// ==================== DATA HERO MOBILE LEGENDS (REAL) ====================
const int TOTAL_HEROES = 125;

Hero heroPool[TOTAL_HEROES] = {
    // Tank
    Hero("Tigreal", "Tank", 82, 75), Hero("Akai", "Tank", 80, 70),
    Hero("Franco", "Tank", 85, 80), Hero("Minotaur", "Tank", 78, 65),
    Hero("Lolita", "Tank", 83, 72), Hero("Gatotkaca", "Tank", 84, 78),
    Hero("Grock", "Tank", 81, 68), Hero("Hylos", "Tank", 79, 66),
    Hero("Uranus", "Tank", 77, 60), Hero("Belerick", "Tank", 76, 58),
    Hero("Khufra", "Tank", 88, 85), Hero("Esmeralda", "Tank", 86, 82),
    Hero("Baxia", "Tank", 82, 70), Hero("Atlas", "Tank", 87, 83),
    Hero("Barats", "Tank", 80, 65), Hero("Gloo", "Tank", 79, 62),
    Hero("Edith", "Tank", 85, 78), Hero("Fredrinn", "Tank", 84, 75),
    Hero("Johnson", "Tank", 83, 77), Hero("Hilda", "Tank", 78, 68),
    
    // Fighter
    Hero("Balmond", "Fighter", 75, 70), Hero("Alucard", "Fighter", 80, 78),
    Hero("Bane", "Fighter", 77, 65), Hero("Zilong", "Fighter", 79, 75),
    Hero("Freya", "Fighter", 81, 72), Hero("Alpha", "Fighter", 78, 68),
    Hero("Ruby", "Fighter", 82, 76), Hero("Roger", "Fighter", 80, 70),
    Hero("Chou", "Fighter", 90, 92), Hero("Sun", "Fighter", 76, 65),
    Hero("Lapu-Lapu", "Fighter", 83, 74), Hero("Argus", "Fighter", 79, 68),
    Hero("Martis", "Fighter", 81, 70), Hero("Aldous", "Fighter", 84, 78),
    Hero("Leomord", "Fighter", 82, 72), Hero("Thamuz", "Fighter", 80, 68),
    Hero("Minsitthar", "Fighter", 77, 60), Hero("Badang", "Fighter", 78, 65),
    Hero("Guinevere", "Fighter", 85, 80), Hero("X.Borg", "Fighter", 86, 82),
    Hero("Dyrroth", "Fighter", 83, 75), Hero("Masha", "Fighter", 79, 66),
    Hero("Silvanna", "Fighter", 81, 70), Hero("Yu Zhong", "Fighter", 88, 85),
    Hero("Khaleed", "Fighter", 82, 72), Hero("Barats", "Fighter", 80, 68),
    Hero("Paquito", "Fighter", 89, 88), Hero("Phoveus", "Fighter", 84, 76),
    Hero("Aulus", "Fighter", 81, 70), Hero("Arlott", "Fighter", 85, 78),
    Hero("Yin", "Fighter", 86, 80), Hero("Julian", "Fighter", 87, 84),
    Hero("Terizla", "Fighter", 78, 62), Hero("Jawhead", "Fighter", 84, 77),
    
    // Assassin
    Hero("Saber", "Assassin", 82, 75), Hero("Karina", "Assassin", 85, 82),
    Hero("Fanny", "Assassin", 92, 70), Hero("Hayabusa", "Assassin", 88, 80),
    Hero("Natalia", "Assassin", 84, 75), Hero("Lancelot", "Assassin", 90, 88),
    Hero("Helcurt", "Assassin", 81, 68), Hero("Gusion", "Assassin", 91, 90),
    Hero("Selena", "Assassin", 87, 78), Hero("Hanzo", "Assassin", 80, 65),
    Hero("Ling", "Assassin", 93, 85), Hero("Benedetta", "Assassin", 89, 84),
    Hero("Aamon", "Assassin", 86, 78), Hero("Joy", "Assassin", 88, 82),
    Hero("Nolan", "Assassin", 87, 80), Hero("Harley", "Assassin", 83, 74),
    
    // Mage
    Hero("Eudora", "Mage", 80, 78), Hero("Alice", "Mage", 82, 72),
    Hero("Nana", "Mage", 79, 75), Hero("Kagura", "Mage", 89, 82),
    Hero("Cyclops", "Mage", 81, 70), Hero("Aurora", "Mage", 80, 68),
    Hero("Vexana", "Mage", 78, 62), Hero("Odette", "Mage", 83, 76),
    Hero("Gord", "Mage", 79, 65), Hero("Pharsa", "Mage", 85, 80),
    Hero("Zhask", "Mage", 82, 70), Hero("Lunox", "Mage", 87, 82),
    Hero("Harith", "Mage", 88, 78), Hero("Kadita", "Mage", 81, 68),
    Hero("Cecilion", "Mage", 86, 80), Hero("Luo Yi", "Mage", 84, 75),
    Hero("Xavier", "Mage", 90, 88), Hero("Valentina", "Mage", 89, 85),
    Hero("Yve", "Mage", 85, 78), Hero("Lylia", "Mage", 83, 72),
    Hero("Vale", "Mage", 84, 76), Hero("Chang'e", "Mage", 82, 74),
    Hero("Novaria", "Mage", 86, 79), Hero("Zhuxin", "Mage", 87, 81),
    
    // Marksman
    Hero("Miya", "Marksman", 78, 80), Hero("Bruno", "Marksman", 84, 82),
    Hero("Clint", "Marksman", 83, 78), Hero("Layla", "Marksman", 77, 85),
    Hero("Yi Sun-shin", "Marksman", 82, 70), Hero("Moskov", "Marksman", 81, 72),
    Hero("Karrie", "Marksman", 85, 78), Hero("Irithel", "Marksman", 80, 68),
    Hero("Lesley", "Marksman", 86, 84), Hero("Hanabi", "Marksman", 79, 72),
    Hero("Claude", "Marksman", 88, 82), Hero("Kimmy", "Marksman", 81, 70),
    Hero("Granger", "Marksman", 87, 85), Hero("Wanwan", "Marksman", 89, 86),
    Hero("Popol and Kupa", "Marksman", 83, 74), Hero("Brody", "Marksman", 90, 88),
    Hero("Beatrix", "Marksman", 91, 90), Hero("Natan", "Marksman", 85, 78),
    Hero("Melissa", "Marksman", 86, 80), Hero("Ixia", "Marksman", 84, 76),
    
    // Support
    Hero("Rafaela", "Support", 76, 65), Hero("Estes", "Support", 84, 78),
    Hero("Angela", "Support", 86, 85), Hero("Faramis", "Support", 80, 68),
    Hero("Mathilda", "Support", 88, 84), Hero("Floryn", "Support", 82, 72),
    Hero("Diggie", "Support", 79, 66), Hero("Carmilla", "Support", 81, 70),
    Hero("Kaja", "Support", 83, 75), Hero("Johnson", "Support", 82, 74),
    Hero("Chip", "Support", 85, 78)
};


// ==================== DRAFT PICK SYSTEM ====================
class DraftPickSystem {
private:
    BST bstHeroes;
    AVLTree avlHeroes;
    SingleLinkedList availableHeroes;
    DoubleLinkedList bannedHeroes;
    DoubleLinkedList pickedBlue;
    DoubleLinkedList pickedRed;
    Stack history;
    Queue draftOrder;
    PriorityQueue recommendations;
    
    int bansPerTeam;
    int picksPerTeam;
    
    void initializeHeroes() {
        for (int i = 0; i < TOTAL_HEROES; i++) {
            bstHeroes.insert(heroPool[i]);
            avlHeroes.insert(heroPool[i]);
            availableHeroes.insert(heroPool[i]);
        }
    }
    
    void initializeDraftOrder() {
        // Ban order: B-R-B-R-B-R (3 bans each)
        for (int i = 0; i < bansPerTeam; i++) {
            draftOrder.enqueue("BLUE", "BAN");
            draftOrder.enqueue("RED", "BAN");
        }
        // Pick order: B-R-R-B-B-R-R-B-B-R (snake draft)
        draftOrder.enqueue("BLUE", "PICK");
        draftOrder.enqueue("RED", "PICK");
        draftOrder.enqueue("RED", "PICK");
        draftOrder.enqueue("BLUE", "PICK");
        draftOrder.enqueue("BLUE", "PICK");
        draftOrder.enqueue("RED", "PICK");
        draftOrder.enqueue("RED", "PICK");
        draftOrder.enqueue("BLUE", "PICK");
        draftOrder.enqueue("BLUE", "PICK");
        draftOrder.enqueue("RED", "PICK");
    }
    
    void generateRecommendations(string role = "") {
        while (!recommendations.isEmpty()) {
            Hero h;
            recommendations.dequeue(h);
        }
        
        SLLNode* temp = availableHeroes.getHead();
        while (temp) {
            if (role.empty() || temp->data.role == role) {
                recommendations.enqueue(temp->data, temp->data.power);
            }
            temp = temp->next;
        }
    }
    
    void displayAvailableHeroes() {
        cout << "\n========== AVAILABLE HEROES ==========" << endl;
        availableHeroes.display();
    }
    
    void displayByRole(string role) {
        cout << "\n=== Heroes with role: " << role << " ===" << endl;
        SLLNode* temp = availableHeroes.getHead();
        int i = 1;
        while (temp) {
            if (temp->data.role == role) {
                cout << setw(3) << i++ << ". " << setw(15) << left << temp->data.name 
                     << " | Power: " << temp->data.power << endl;
            }
            temp = temp->next;
        }
    }

public:
    DraftPickSystem() : bansPerTeam(3), picksPerTeam(5) {
        initializeHeroes();
        initializeDraftOrder();
    }
    
    void displayMainMenu() {
        cout << "\n";
        cout << "+--------------------------------------------------------------+" << endl;
        cout << "|       MOBILE LEGENDS - DRAFT PICK SYSTEM                     |" << endl;
        cout << "|       EAS Struktur Data                                      |" << endl;
        cout << "+--------------------------------------------------------------+" << endl;
        cout << "|  1. Start Draft Pick                                         |" << endl;
        cout << "|  2. Manage Hero Database                                     |" << endl;
        cout << "|  3. View All Heroes (BST - Sorted by Name)                   |" << endl;
        cout << "|  4. View All Heroes (AVL - Sorted by Power)                  |" << endl;
        cout << "|  5. Search Hero                                              |" << endl;
        cout << "|  6. Hero Statistics                                          |" << endl;
        cout << "|  7. Export Data to File                                      |" << endl;
        cout << "|  8. View History (Stack)                                     |" << endl;
        cout << "|  9. Hero Recommendations (Priority Queue)                    |" << endl;
        cout << "|  0. Exit                                                     |" << endl;
        cout << "+--------------------------------------------------------------+" << endl;
        cout << "Pilih menu: ";
    }
    
    void manageHeroMenu() {
        int choice;
        do {
            cout << "\n=== MANAGE HERO DATABASE ===" << endl;
            cout << "1. Insert Hero (BST & AVL)" << endl;
            cout << "2. Delete Hero (BST & AVL)" << endl;
            cout << "3. View BST (Inorder)" << endl;
            cout << "4. View AVL (Inorder)" << endl;
            cout << "5. Back" << endl;
            cout << "Pilih: ";
            cin >> choice;
            cin.ignore();
            
            if (choice == 1) {
                string name, role;
                int power, pickRate;
                cout << "Nama Hero: "; getline(cin, name);
                cout << "Role (Tank/Fighter/Assassin/Mage/Marksman/Support): "; getline(cin, role);
                cout << "Power (1-100): "; cin >> power;
                cout << "Pick Rate (1-100): "; cin >> pickRate;
                
                Hero newHero(name, role, power, pickRate);
                bstHeroes.insert(newHero);
                avlHeroes.insert(newHero);
                availableHeroes.insert(newHero);
                history.push("INSERT", newHero);
                cout << "Hero " << name << " berhasil ditambahkan!" << endl;
            }
            else if (choice == 2) {
                string name;
                cout << "Nama Hero yang akan dihapus: "; getline(cin, name);
                Hero* found = bstHeroes.search(name);
                if (found) {
                    history.push("DELETE", *found);
                    bstHeroes.remove(name);
                    avlHeroes.remove(name);
                    availableHeroes.remove(name);
                    cout << "Hero " << name << " berhasil dihapus!" << endl;
                } else {
                    cout << "Hero tidak ditemukan!" << endl;
                }
            }
            else if (choice == 3) {
                bstHeroes.displayInorder();
            }
            else if (choice == 4) {
                avlHeroes.displayInorder();
            }
        } while (choice != 5);
    }
    
    void searchHero() {
        string name;
        cout << "Masukkan nama hero: ";
        cin.ignore();
        getline(cin, name);
        
        Hero* result = bstHeroes.search(name);
        if (result) {
            cout << "\n=== HERO FOUND ===" << endl;
            cout << "Name     : " << result->name << endl;
            cout << "Role     : " << result->role << endl;
            cout << "Power    : " << result->power << endl;
            cout << "Pick Rate: " << result->pickRate << endl;
        } else {
            cout << "Hero tidak ditemukan!" << endl;
        }
    }
    
    void heroStatistics() {
        cout << "\n=== HERO STATISTICS ===" << endl;
        cout << "Total Heroes in BST: " << bstHeroes.count() << endl;
        cout << "Total Heroes in AVL: " << avlHeroes.count() << endl;
        cout << "Available Heroes   : " << availableHeroes.getSize() << endl;
        
        // Count by role using recursion
        cout << "\nHero count by role (Recursive):" << endl;
        cout << "Tank     : " << countHeroByRoleRec(heroPool, TOTAL_HEROES, "Tank") << endl;
        cout << "Fighter  : " << countHeroByRoleRec(heroPool, TOTAL_HEROES, "Fighter") << endl;
        cout << "Assassin : " << countHeroByRoleRec(heroPool, TOTAL_HEROES, "Assassin") << endl;
        cout << "Mage     : " << countHeroByRoleRec(heroPool, TOTAL_HEROES, "Mage") << endl;
        cout << "Marksman : " << countHeroByRoleRec(heroPool, TOTAL_HEROES, "Marksman") << endl;
        cout << "Support  : " << countHeroByRoleRec(heroPool, TOTAL_HEROES, "Support") << endl;
        
        cout << "\nTotal Power (Recursive): " << sumPowerRec(heroPool, TOTAL_HEROES) << endl;
    }
    
    void exportData() {
        int choice;
        cout << "\n=== EXPORT DATA ===" << endl;
        cout << "1. Export BST to bst_heroes.txt" << endl;
        cout << "2. Export AVL to avl_heroes.txt" << endl;
        cout << "3. Export Draft Result to draft_result.txt" << endl;
        cout << "4. Export All" << endl;
        cout << "Pilih: ";
        cin >> choice;
        
        if (choice == 1 || choice == 4) {
            bstHeroes.exportToFile("bst_heroes.txt");
        }
        if (choice == 2 || choice == 4) {
            avlHeroes.exportToFile("avl_heroes.txt");
        }
        if (choice == 3 || choice == 4) {
            exportDraftResult();
        }
    }
    
    void exportDraftResult() {
        ofstream file("draft_result.txt");
        if (file.is_open()) {
            file << "========================================" << endl;
            file << "    MOBILE LEGENDS DRAFT PICK RESULT    " << endl;
            file << "========================================" << endl;
            file << "\n=== BANNED HEROES ===" << endl;
            DLLNode* temp = bannedHeroes.getHead();
            while (temp) {
                file << "- " << temp->data.name << " (" << temp->data.role << ")" << endl;
                temp = temp->next;
            }
            
            file << "\n=== TEAM BLUE PICKS ===" << endl;
            temp = pickedBlue.getHead();
            while (temp) {
                file << "- " << temp->data.name << " (" << temp->data.role << ")" << endl;
                temp = temp->next;
            }
            
            file << "\n=== TEAM RED PICKS ===" << endl;
            temp = pickedRed.getHead();
            while (temp) {
                file << "- " << temp->data.name << " (" << temp->data.role << ")" << endl;
                temp = temp->next;
            }
            
            file.close();
            cout << "Draft result exported to draft_result.txt" << endl;
        }
    }
    
    void showRecommendations() {
        int choice;
        cout << "\n=== HERO RECOMMENDATIONS ===" << endl;
        cout << "Filter by role:" << endl;
        cout << "1. All" << endl;
        cout << "2. Tank" << endl;
        cout << "3. Fighter" << endl;
        cout << "4. Assassin" << endl;
        cout << "5. Mage" << endl;
        cout << "6. Marksman" << endl;
        cout << "7. Support" << endl;
        cout << "Pilih: ";
        cin >> choice;
        
        string role = "";
        switch(choice) {
            case 2: role = "Tank"; break;
            case 3: role = "Fighter"; break;
            case 4: role = "Assassin"; break;
            case 5: role = "Mage"; break;
            case 6: role = "Marksman"; break;
            case 7: role = "Support"; break;
        }
        
        generateRecommendations(role);
        recommendations.display();
    }
    
    void startDraftPick() {
        // Reset draft
        while (bannedHeroes.getSize() > 0) {
            DLLNode* temp = bannedHeroes.getHead();
            if (temp) bannedHeroes.remove(temp->data.name);
        }
        while (pickedBlue.getSize() > 0) {
            DLLNode* temp = pickedBlue.getHead();
            if (temp) pickedBlue.remove(temp->data.name);
        }
        while (pickedRed.getSize() > 0) {
            DLLNode* temp = pickedRed.getHead();
            if (temp) pickedRed.remove(temp->data.name);
        }
        
        // Reinitialize available heroes
        while (!availableHeroes.isEmpty()) {
            SLLNode* temp = availableHeroes.getHead();
            if (temp) availableHeroes.remove(temp->data.name);
        }
        for (int i = 0; i < TOTAL_HEROES; i++) {
            availableHeroes.insert(heroPool[i]);
        }
        
        cout << "\n+--------------------------------------------------------------+" << endl;
        cout << "|              DRAFT PICK STARTED!                             |" << endl;
        cout << "|              Ban: 3 per team | Pick: 5 per team              |" << endl;
        cout << "+--------------------------------------------------------------+" << endl;
        
        // ========== BAN PHASE ==========
        cout << "\n==================== BAN PHASE ====================" << endl;
        string banOrder[] = {"BLUE", "RED", "BLUE", "RED", "BLUE", "RED"};
        
        for (int i = 0; i < 6; i++) {
            string team = banOrder[i];
            cout << "\n[" << team << "] BAN " << (i/2 + 1) << " of 3" << endl;
            cout << "----------------------------------------" << endl;
            
            // Display available heroes with numbers
            SLLNode* temp = availableHeroes.getHead();
            int idx = 1;
            while (temp) {
                cout << setw(3) << idx << ". " << setw(15) << left << temp->data.name 
                     << " | " << setw(10) << temp->data.role << endl;
                temp = temp->next;
                idx++;
            }
            
            cout << "\nPilih nomor hero untuk di-BAN: ";
            int choice;
            cin >> choice;
            
            // Find hero by index
            temp = availableHeroes.getHead();
            idx = 1;
            Hero* selectedHero = nullptr;
            string selectedName = "";
            while (temp) {
                if (idx == choice) {
                    selectedHero = &temp->data;
                    selectedName = temp->data.name;
                    break;
                }
                temp = temp->next;
                idx++;
            }
            
            if (!selectedHero) {
                cout << "Nomor tidak valid! Ulangi." << endl;
                i--;
                continue;
            }
            
            bannedHeroes.insertBack(*selectedHero);
            history.push("BAN-" + team, *selectedHero);
            availableHeroes.remove(selectedName);
            cout << ">>> " << team << " mem-BAN " << selectedName << "!" << endl;
        }
        
        // ========== PICK PHASE ==========
        cout << "\n==================== PICK PHASE ====================" << endl;
        string pickOrder[] = {"BLUE", "RED", "RED", "BLUE", "BLUE", "RED", "RED", "BLUE", "BLUE", "RED"};
        
        for (int i = 0; i < 10; i++) {
            string team = pickOrder[i];
            int pickNum = (team == "BLUE") ? pickedBlue.getSize() + 1 : pickedRed.getSize() + 1;
            cout << "\n[" << team << "] PICK " << pickNum << " of 5" << endl;
            cout << "----------------------------------------" << endl;
            
            // Display available heroes with numbers
            SLLNode* temp = availableHeroes.getHead();
            int idx = 1;
            while (temp) {
                cout << setw(3) << idx << ". " << setw(15) << left << temp->data.name 
                     << " | " << setw(10) << temp->data.role 
                     << " | Power: " << temp->data.power << endl;
                temp = temp->next;
                idx++;
            }
            
            cout << "\nPilih nomor hero untuk di-PICK: ";
            int choice;
            cin >> choice;
            
            // Find hero by index
            temp = availableHeroes.getHead();
            idx = 1;
            Hero* selectedHero = nullptr;
            string selectedName = "";
            while (temp) {
                if (idx == choice) {
                    selectedHero = &temp->data;
                    selectedName = temp->data.name;
                    break;
                }
                temp = temp->next;
                idx++;
            }
            
            if (!selectedHero) {
                cout << "Nomor tidak valid! Ulangi." << endl;
                i--;
                continue;
            }
            
            if (team == "BLUE") {
                pickedBlue.insertBack(*selectedHero);
            } else {
                pickedRed.insertBack(*selectedHero);
            }
            history.push("PICK-" + team, *selectedHero);
            availableHeroes.remove(selectedName);
            cout << ">>> " << team << " mem-PICK " << selectedName << "!" << endl;
        }
        
        // Display final result
        displayDraftResult();
    }
    
    void displayDraftResult() {
        cout << "\n+--------------------------------------------------------------+" << endl;
        cout << "|                    DRAFT PICK RESULT                         |" << endl;
        cout << "+--------------------------------------------------------------+" << endl;
        
        cout << "\n=== BANNED HEROES (" << bannedHeroes.getSize() << ") ===" << endl;
        bannedHeroes.displayForward();
        
        cout << "\n=== TEAM BLUE PICKS (" << pickedBlue.getSize() << ") ===" << endl;
        pickedBlue.displayForward();
        
        cout << "\n=== TEAM RED PICKS (" << pickedRed.getSize() << ") ===" << endl;
        pickedRed.displayForward();
        
        // Auto export
        exportDraftResult();
    }
    
    void viewHistory() {
        history.display();
    }
    
    void run() {
        int choice;
        do {
            displayMainMenu();
            cin >> choice;
            
            switch(choice) {
                case 1: startDraftPick(); break;
                case 2: manageHeroMenu(); break;
                case 3: bstHeroes.displayInorder(); break;
                case 4: avlHeroes.displayInorder(); break;
                case 5: searchHero(); break;
                case 6: heroStatistics(); break;
                case 7: exportData(); break;
                case 8: viewHistory(); break;
                case 9: showRecommendations(); break;
                case 0: cout << "Terima kasih! Goodbye!" << endl; break;
                default: cout << "Menu tidak valid!" << endl;
            }
        } while (choice != 0);
    }
};

// ==================== MAIN FUNCTION ====================
int main() {
    cout << "+--------------------------------------------------------------+" << endl;
    cout << "|     EAS STRUKTUR DATA - MOBILE LEGENDS DRAFT PICK           |" << endl;
    cout << "|                                                              |" << endl;
    cout << "|  Implementasi:                                               |" << endl;
    cout << "|  - ADT, Rekursif, Single & Double Linked List               |" << endl;
    cout << "|  - Stack, Queue, Sorting, BST, AVL Tree, Priority Queue     |" << endl;
    cout << "+--------------------------------------------------------------+" << endl;
    
    DraftPickSystem system;
    system.run();
    
    return 0;
}
