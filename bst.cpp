#include "bst.h"
#include <fstream>
#include <iostream>

Node::Node(const string& k, const string& v) : key(k), value(v), left(nullptr), right(nullptr) {}

BST::BST() : root(nullptr) {}

BST::~BST() {
    clear(root);
}

void BST::insert(const string& key, const string& value) {
    root = insert(root, key, value);
}

void BST::remove(const string& key) {
    root = remove(root, key);
}

string BST::search(const string& key) const {
    Node* node = search(root, key);
    return (node != nullptr) ? node->value : "File not found";
}

Node* BST::getRoot() const {
    return root;
}

vector<string> BST::findDuplicates(const string& key) const {
    vector<string> duplicates;
    findDuplicates(root, key, duplicates);
    return duplicates;
}

void BST::saveToFile(const string& filename) {
    ofstream file(filename);
    saveToFile(root, file);
    file.close();
}

void BST::loadFromFile(const string& filename) {
    ifstream file(filename);
    root = loadFromFile(file);
    file.close();
}

Node* BST::insert(Node* node, const string& key, const string& value) {
    if (node == nullptr) return new Node(key, value);
    if (key < node->key) node->left = insert(node->left, key, value);
    else if (key > node->key) node->right = insert(node->right, key, value);
    return node;
}

Node* BST::remove(Node* node, const string& key) {
    if (node == nullptr) return node;
    if (key < node->key) node->left = remove(node->left, key);
    else if (key > node->key) node->right = remove(node->right, key);
    else
    {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = minValueNode(node->right);
        node->key = temp->key;
        node->value = temp->value;
        node->right = remove(node->right, temp->key);
    }
    return node;
}

Node* BST::search(Node* node, const string& key) const {
    if (node == nullptr || node->key == key) return node;
    if (key < node->key) return search(node->left, key);
    return search(node->right, key);
}

Node* BST::minValueNode(Node* node) {
    while (node->left != nullptr) node = node->left;
    return node;
}
Node* BST::loadFromFile(ifstream& file) {
    Node* node = nullptr;
    string key, value;
    while (file >> key >> value) {
        node = insert(node, key, value);
    }
    return node;
}

void BST::clear(Node* node) {
    if (node != nullptr) {
        clear(node->left);
        clear(node->right);
        delete node;
    }
}
void BST::saveToFile(Node* node, ofstream& file) {
    if (node != nullptr) {
        saveToFile(node->left, file);
        file << node->key << " " << node->value << endl;
        saveToFile(node->right, file);
    }
}


void BST::findDuplicates(Node* node, const string& key, vector<string>& duplicates) const {
    if (node != nullptr) {
        findDuplicates(node->left, key, duplicates);
        if (node->value == key) {
            duplicates.push_back(node->key);
        }
        findDuplicates(node->right, key, duplicates);
    }
}
