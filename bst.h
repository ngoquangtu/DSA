#ifndef BST_H
#define BST_H

#include <string>
#include <unordered_map>

using namespace std;

struct Node {
    string key;
    string value;
    Node(const string& k, const string& v);
    Node* left;
    Node* right;
};

class BST {
public:
    BST();
    ~BST();
    void insert(const string& key, const string& value);
    void remove(const string& key);
    string search(const string& key) const;
    Node* getRoot() const;
    void findDuplicates(unordered_map<string, string>& seen) const;
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);

private:
    Node* root;
    Node* insert(Node* node, const string& key, const string& value);
    Node* remove(Node* node, const string& key);
    Node* search(Node* node, const string& key) const;
    Node* minValueNode(Node* node);
    void clear(Node* node);
    void saveToFile(Node* node, ofstream& file);
    Node* loadFromFile(ifstream& file);
    Node* findDuplicates(Node* node, unordered_map<string, string>& seen) const;
};

#endif // BST_H
