#include <vector>
#include "LinkedList.cpp"
#include <string>

template <typename T>
class HashTable {
  vector< LinkedList<T> > table;


  int hashfunction (string s) { // hash function
  int g=31;
  int hash=0;
  for (int i = 0; i <s.length(); i++)
  hash=g*hash+s[i];
  hash= hash & 0x7fffffff;//to make sure gatting positive number
    return hash % table.size();
  }


 public:
  HashTable (int size) {
    table.resize (size); // resize vector to support size elements.
  }
  ~HashTable() {
    for (int i = 0; i < table.size(); i++)
      table[i].makeEmpty();
  }
  int size() {
    return table.size();
  }
  void insert (T newItem) {
    int location = hashfunction(newItem);
        table[location].insertFront(newItem);
  }
  bool retrieve (T & target) {
    int location = hashfunction(target);
    if(!table[location].find(target))
        return false;
    return true;
  }
  friend ostream& operator<< (ostream& os, HashTable<T>& ht) {
    for (int i = 0; i < ht.size(); i++)
      os << i << " = " << ht.table[i] << endl;
    return os;
  }
};
