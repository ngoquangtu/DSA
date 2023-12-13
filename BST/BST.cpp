#include "BST.h"
#include <iostream>
#include <fstream>

// Node constructor
Node::Node(const string& k, const string& v) : key(k), value(v), left(nullptr), right(nullptr) {}

// BST constructor
BST::BST() : root(nullptr) {}

// BST destructor
BST::~BST() {
    clear(root);
}

// Insert a key-value pair into the BST
void BST::insert(const string& key, const string& value) {
    root = insert(root, key, value);
}

// Remove a node with the given key from the BST
void BST::remove(const string& key) {
    root = remove(root, key);
}

// Search for a key in the BST and return its value
string BST::search(const string& key) const {
    Node* node = search(root, key);
    return (node != nullptr) ? node->value : "File not found";
}

// Get the root of the BST
Node* BST::getRoot() const {
    return root;
}

// Find and display duplicate files in the BST
void BST::findDuplicates() const {
    unordered_map<string, string> seen;
    findDuplicates(root, seen);
}

// Save the BST to a file
void BST::saveToFile(const string& filename) {
    ofstream file(filename);
    saveToFile(root, file);
    file.close();
}

// Load the BST from a file
void BST::loadFromFile(const string& filename) {
    ifstream file(filename);
    root = loadFromFile(file);
    file.close();
}

// Private method to insert a node into the BST
Node* BST::insert(Node* node, const string& key, const string& value) {
    if (node == nullptr) return new Node(key, value);
    if (key < node->key) node->left = insert(node->left, key, value);
    else if (key > node->key) node->right = insert(node->right, key, value);
    return node;
}

// Private method to remove a node from the BST
Node* BST::remove(Node* node, const string& key) {
    // Implementation remains unchanged
    // ...
}

// Private method to search for a key in the BST
Node* BST::search(Node* node, const string& key) const {
    // Implementation remains unchanged
    // ...
}

// Private method to find and display duplicate files
Node* BST::findDuplicates(Node* node, unordered_map<string, string>& seen) const {
    if (node != nullptr) {
        findDuplicates(node->left, seen);
        if (seen.find(node->key) != seen.end()) {
            cout << "Duplicated files: " << node->key << " and " << seen[node->key] << endl;
        }
        else {
            seen[node->key] = node->value;
        }
        findDuplicates(node->right, seen);
    }
    return node;
}

// Private method to find the node with the minimum value in the BST
Node* BST::minValueNode(Node* node) {
    while (node->left != nullptr) node = node->left;
    return node;
}

// Private method to load the BST from a file
Node* BST::loadFromFile(ifstream& file) {
    Node* node = nullptr;
    string key, value;
    while (file >> key >> value) {
        node = insert(node, key, value);
    }
    return node;
}

// Private method to clear the BST
void BST::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}

// Private method to save the BST to a file
void BST::saveToFile(Node* node, ofstream& file) {
    if (node != nullptr) {
        saveToFile(node->left, file);
        file << node->key << " " << node->value << endl;
        saveToFile(node->right, file);
    }
}

int main() {
    // Example usage
    BST bst;
    bst.insert("file1.txt", "content1");
    bst.insert("file2.txt", "content2");
    bst.insert("file3.txt", "content3");
    bst.insert("file1.txt", "content4"); // Duplicate file

    // Find and display duplicates
    bst.findDuplicates();

    return 0;
}

