#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>

using namespace std;

// Maximum level for this skip list
#define MAX_LEVEL 6

// Probability factor for random level
float P = 0.5;

// Node structure
class Node {
public:
  int key;
  Node **forward;

  Node(int key, int level) {
    this->key = key;
    forward = new Node *[level + 1];
    for (int i = 0; i <= level; i++)
      forward[i] = nullptr;
  }

  ~Node() {
    delete[] forward;
  }
};

// SkipList class
class SkipList {
  int level;
  Node *header;

public:
  SkipList() {
    level = 0;
    header = new Node(INT_MIN, MAX_LEVEL);
  }

  ~SkipList() {
    Node *current = header;
    while (current) {
      Node *next = current->forward[0];
      delete current;
      current = next;
    }
  }

  int randomLevel() {
    int lvl = 0;
    while ((float)rand() / RAND_MAX < P && lvl < MAX_LEVEL)
      lvl++;
    return lvl;
  }

  void insert(int key) {
    Node *current = header;
    Node *update[MAX_LEVEL + 1];
    for (int i = level; i >= 0; i--) {
      while (current->forward[i] && current->forward[i]->key < key)
        current = current->forward[i];
      update[i] = current;
    }

    current = current->forward[0];

    if (current == nullptr || current->key != key) {
      int rlevel = randomLevel();

      if (rlevel > level) {
        for (int i = level + 1; i <= rlevel; i++)
          update[i] = header;
        level = rlevel;
      }

      Node *n = new Node(key, rlevel);
      for (int i = 0; i <= rlevel; i++) {
        n->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = n;
      }

      cout << "Inserted key: " << key << endl;
    } else {
      cout << "Key already exists!\n";
    }
  }

  void deleteKey(int key) {
    Node *current = header;
    Node *update[MAX_LEVEL + 1];
    for (int i = level; i >= 0; i--) {
      while (current->forward[i] && current->forward[i]->key < key)
        current = current->forward[i];
      update[i] = current;
    }

    current = current->forward[0];

    if (current != nullptr && current->key == key) {
      for (int i = 0; i <= level; i++) {
        if (update[i]->forward[i] != current)
          break;
        update[i]->forward[i] = current->forward[i];
      }
      delete current;

      while (level > 0 && header->forward[level] == nullptr)
        level--;

      cout << "Deleted key: " << key << endl;
    } else {
      cout << "Key not found!\n";
    }
  }

  bool search(int key) {
    Node *current = header;
    for (int i = level; i >= 0; i--) {
      while (current->forward[i] && current->forward[i]->key < key)
        current = current->forward[i];
    }

    current = current->forward[0];
    if (current && current->key == key)
      return true;
    return false;
  }

  void display() {
    cout << "\n***** Skip List *****\n";
    for (int i = 0; i <= level; i++) {
      Node *node = header->forward[i];
      cout << "Level " << i << ": ";
      while (node != nullptr) {
        cout << node->key << " ";
        node = node->forward[i];
      }
      cout << endl;
    }
  }
};

// Main function with menu
int main() {
  srand(time(0));
  SkipList list;
  int choice, value;

  while (true) {
    cout << "\nSkip List Menu\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. Search\n";
    cout << "4. Display\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Enter value to insert: ";
      cin >> value;
      list.insert(value);
      break;
    case 2:
      cout << "Enter value to delete: ";
      cin >> value;
      list.deleteKey(value);
      break;
    case 3:
      cout << "Enter value to search: ";
      cin >> value;
      if (list.search(value))
        cout << "Found!\n";
      else
        cout << "Not found!\n";
      break;
    case 4:
      list.display();
      break;
    case 5:
      cout << "Exiting...\n";
      return 0;
    default:
      cout << "Invalid choice!\n";
    }
  }
}
