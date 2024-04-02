#ifndef LIST_HPP
#define LIST_HPP
/* List.hpp
 *
 * doubly-linked, double-ended list with Iterator interface
 * EECS 280 Project 4
 */

#include <iostream>
#include <iterator> //std::bidirectional_iterator_tag
#include <cassert>  //assert

using namespace std;

template <typename T>
class List {
  //OVERVIEW: a doubly-linked, double-ended list with Iterator interface
public:

  List() :first(nullptr),last(nullptr),zise(0){
  }

  List(List& ls){
    first = ls.first;
    copy_all(ls);
  }

  List& operator=(const List &rhs){
      clear();
      first = rhs.first;
      copy_all(rhs);
      return *this;
    }

  ~List(){
    first = nullptr;
    clear();
  }

  //EFFECTS:  returns true if the list is empty
  bool empty() const{
    return (first == nullptr);
  }

  //EFFECTS: returns the number of elements in this List
  //HINT:    Traversing a list is really slow. Instead, keep track of the size
  //         with a private member variable. That's how std::list does it.
  int size() const{
    return zise;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the first element in the list by reference
  T & front(){
    assert(!empty());
    return first->datum;
  }

  //REQUIRES: list is not empty
  //EFFECTS: Returns the last element in the list by reference
  T & back(){
    assert(!empty());
    return last->datum;
  }

  //EFFECTS:  inserts datum into the front of the list
  void push_front(const T &datum){
    zise++;
    Node *n = new Node;
    if (first != nullptr) {
      first->prev = n; 
    };
    n->datum = datum;
    n->next = first;
    n->prev = nullptr;
    first = n;
    if (last == nullptr) {
      last = first;
    }
  }

  //EFFECTS:  inserts datum into the back of the list
  void push_back(const T &datum){
    zise++;
    Node *n = new Node;
    if (last != nullptr) {
      last->next = n;
    };
    n->datum = datum;
    n->next = nullptr;
    n->prev = last;
    last = n;
    if (first == nullptr) {
      first = last;
    }
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the front of the list
  void pop_front(){
    assert(!empty());
    zise--;
    Node *victim = first;
    first = first->next;
    delete victim;
    first->prev = nullptr;
  }

  //REQUIRES: list is not empty
  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes the item at the back of the list
  void pop_back() {
    assert(!empty());
    zise--;
    Node *victim = last;
    last = last->prev;
    delete victim;
    last->next = nullptr;
  }

  //MODIFIES: may invalidate list iterators
  //EFFECTS:  removes all items from the list
  void clear(){
    while(!empty()){
      pop_front();
    }
  }

  // You should add in a default constructor, destructor, copy constructor,
  // and overloaded assignment operator, if appropriate. If these operations
  // will work correctly without defining these, you should omit them. A user
  // of the class must be able to create, copy, assign, and destroy Lists.

private:
  //a private type
  struct Node {
    Node *next;
    Node *prev;
    T datum;
  };

  //REQUIRES: list is empty
  //EFFECTS:  copies all nodes from other to this
  void copy_all(const List<T> &other){
    
    Node *ptr = other.first;
    Node *prev_ptr = nullptr;
    
    Node *f = new Node;
    first = f;
    f->datum = ptr->datum;
    f->next = nullptr;
    f->prev = nullptr;
    ptr = ptr->next;
    prev_ptr = f;

    while (ptr != nullptr) {
      Node *n = new Node;
      n->datum = ptr->datum;
      n->next = nullptr;
      n->prev = prev_ptr; // set prev to previous pointer
      prev_ptr->next = n; // set next of previous pointer to current address
      prev_ptr = n; // set previous pointer to current address
      
      ptr = ptr->next; //update the pointer indicating node in other list
    }

    last = prev_ptr;
    
  }

  Node *first;   // points to first Node in list, or nullptr if list is empty
  Node *last;    // points to last Node in list, or nullptr if list is empty

  int zise;

public:
  ////////////////////////////////////////
  class Iterator {
  public:
    //OVERVIEW: Iterator interface to List

    // Add a default constructor here. The default constructor must set both
    // pointer members to null pointers.

    Iterator():list_ptr(nullptr),node_ptr(nullptr){
    }

    // Add custom implementations of the destructor, copy constructor, and
    // overloaded assignment operator, if appropriate. If these operations
    // will work correctly without defining these, you should omit them. A user
    // of the class must be able to copy, assign, and destroy Iterators.


    // Your iterator should implement the following public operators:
    // *, ++ (both prefix and postfix), == and !=.
    // Equality comparisons must satisfy the following rules:
    // - two default-constructed iterators must compare equal
    // - a default-constructed iterator must compare unequal to an
    //   iterator obtained from a list, even if it is the end iterator
    // - two iterators to the same location in the same list must
    //   compare equal
    // - two iterators to different locations in the same list must
    //   compare unequal
    // - comparing iterators obtained from different lists results in
    //   undefined behavior
    //   - Your implementation can handle this however you like, but
    //     don't assume any particular behavior in your test cases --
    //     comparing iterators from different lists essentially
    //     violates the REQURES clause.
    // Note: comparing both the list and node pointers should be
    // sufficient to meet these requirements.


    // Type aliases required to work with STL algorithms. Do not modify these.
    using iterator_category = std::bidirectional_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = T*;
    using reference = T&;

    T& operator*() {
      assert(node_ptr);
      return node_ptr->datum;
    }

    //prefix
    Iterator operator++(){
      assert(node_ptr);
      node_ptr = node_ptr->next;
      return *this;
    }

    //postfix
    Iterator operator++(int){
      assert(node_ptr);
      Iterator copy = *this;
      node_ptr = node_ptr->next;
      return copy;
    }

    Iterator operator=(Iterator other){
      list_ptr = other.list_ptr;
      node_ptr = other.node_ptr;
      return *this;
    }

    
    bool operator==(const Iterator rhs) const {
      return (list_ptr == rhs.list_ptr)&&(node_ptr == rhs.node_ptr);
    }

    bool operator!=(const Iterator rhs) const{
      return node_ptr != rhs.node_ptr;
    }

    // This operator will be used to test your code. Do not modify it.
    // REQUIRES: Iterator is decrementable. All iterators associated with a
    //           list are decrementable, including end iterators, except for
    //           begin iterators (those equal to begin() on the list)
    // EFFECTS:  moves this Iterator to point to the previous element
    //           and returns a reference to this Iterator
    Iterator operator--() { // prefix -- (e.g. --it)
      assert(list_ptr);
      assert(*this != list_ptr->begin());
      node_ptr = node_ptr->prev;
      // if (node_ptr) {
        
      // } else { // decrementing an end Iterator moves it to the last element
      //   node_ptr = list_ptr->last;
      // }
      return *this;
    }

    // This operator will be used to test your code. Do not modify it.
    // REQUIRES: Iterator is decrementable. All iterators associated with a
    //           list are decrementable, including end iterators, except for
    //           begin iterators (those equal to begin() on the list)
    // EFFECTS:  moves this Iterator to point to the previous element
    //           and returns a copy of the original Iterator
    Iterator operator--(int /*dummy*/) { // postfix -- (e.g. it--)
      assert(list_ptr);
      assert(*this != list_ptr->begin());
      Iterator copy = *this;
      node_ptr = node_ptr->prev;
      return copy;
    }


    // REQUIRES: Iterator is dereferenceable
    // EFFECTS: returns the underlying element by pointer
    // NOTE: T must be a class type to use the syntax it->. If T has a
    //       member variable f, then it->f accesses f on the
    //       underlying T element.
    T* operator->() const {
      return &(node_ptr->datum);
    }

  private:
    const List *list_ptr; //pointer to the List associated with this Iterator
    Node *node_ptr; //current Iterator position is a List node
    // add any additional necessary member variables here

    // add any friend declarations here
    friend class List;
    friend class TextBuffer;

    // construct an Iterator at a specific position in the given List
    Iterator(const List *lp, Node *np):list_ptr(lp),node_ptr(np){

    }

  };//List::Iterator
  ////////////////////////////////////////

  // return an Iterator pointing to the first element
  Iterator begin() const{
    return Iterator(this,first);
  }

  // return an Iterator pointing to "past the end"
  Iterator end() const{
    return Iterator(this,last->next);

  }

  //REQUIRES: i is a valid, dereferenceable iterator associated with this list
  //MODIFIES: may invalidate other list iterators
  //EFFECTS: Removes a single element from the list container.
  //         Returns An iterator pointing to the element that followed the
  //         element erased by the function call
  Iterator erase(Iterator i){
    assert(i.node_ptr);
    zise--;
    Node *victim = i.node_ptr;
    victim->prev->next = victim->next;
    victim->next->prev = victim->prev;
    i.node_ptr = victim->next;
    delete victim;
    
    return i;
  }

  //REQUIRES: i is a valid iterator associated with this list
  //EFFECTS: Inserts datum before the element at the specified position.
  //         Returns an iterator to the the newly inserted element.
  Iterator insert(Iterator i, const T &datum){
    assert(i.node_ptr);
    zise++;
    Node *newbie = new Node;
    newbie->datum = datum;
    newbie->next = i.node_ptr;
    newbie->prev = i.node_ptr->prev;

    newbie->prev->next = newbie;
    newbie->next->prev = newbie;

    i.node_ptr = newbie;

    return i;
  }

};//List


////////////////////////////////////////////////////////////////////////////////
// Add your member function implementations below or in the class above
// (your choice). Do not change the public interface of List, although you
// may add the Big Three if needed.  Do add the public member functions for
// Iterator.



#endif // Do not remove this. Write all your code above this line.