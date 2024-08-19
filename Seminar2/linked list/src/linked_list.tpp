#include "linked_list.hpp"

#include <exception>
#include <iostream>
#include <stdexcept>

template <typename T> Linked_list<T>::Linked_list() : starting_node{nullptr} {
  std::cout << "Linked list is created !" << std::endl;
}

template <typename T> Linked_list<T>::~Linked_list() {
  std::cout << "Linked list destruction is starting!" << std::endl;
  while (this->is_list_empty() == false) {
    this->destroy_last_node();
    this->display_list();
  }
  std::cout << "Linked list is destroyed!" << std::endl;
}
template <typename T>
typename Linked_list<T>::node *Linked_list<T>::go_to_last_node() {
  node *curr_node = this->starting_node;
  while (curr_node != nullptr && curr_node->next_node != nullptr) {
    curr_node = curr_node->next_node;
  }
  return curr_node;
}
template <typename T> int Linked_list<T>::add_value(const T value) {
  if (this->is_list_empty()) {
    this->starting_node = new node(value);
    return 0;
  } else if (value < this->starting_node->value) {
    node *node_mem = new node(*this->starting_node);
    delete this->starting_node;
    node *new_node = new node(value, node_mem);
    this->starting_node = new_node;
    return 0;
  }
  this->current_node = this->starting_node;
  while (this->current_node != nullptr) {
    if (this->current_node->next_node == nullptr) {
      node *new_node = new node(value);
      this->current_node->next_node = new_node;
      return 0;
    } else if (this->current_node->next_node->value > value) {
      node *node_mem = new node(*this->current_node->next_node);
      node *new_node = new node(value, node_mem);
      this->current_node->next_node = new_node;
      return 0;
    }
    this->current_node = this->current_node->next_node;
  }
  return 1;
}

template <typename T> void Linked_list<T>::display_list() {
  std::cout << "Start ";
  if (this->starting_node == nullptr) {
    std::cout << "-> nullptr" << std::endl;
  } else {
    this->current_node = this->starting_node;
    std::cout << "-> " << this->current_node->value << " ";
    this->current_node = this->current_node->next_node;
    return this->_display_list();
  }
}
template <typename T> void Linked_list<T>::_display_list() {
  if (this->current_node == nullptr) {
    std::cout << "-> nullptr" << std::endl;
  } else {
    std::cout << "-> " << this->current_node->value << " ";
    this->current_node = this->current_node->next_node;
    return this->_display_list();
  }
}
template <typename T> bool Linked_list<T>::is_list_empty() {
  return this->starting_node == nullptr;
}
template <typename T> void Linked_list<T>::destroy_last_node() {
  if (this->is_list_empty()) {
    return;
  } else if (this->starting_node->next_node == nullptr) {
    delete this->starting_node;
    this->starting_node = nullptr;
    return;
  } else {
    this->current_node = this->starting_node;
    while (this->current_node->next_node->next_node != nullptr) {
      this->current_node = this->current_node->next_node;
    }
    delete this->current_node->next_node;
    this->current_node->next_node = nullptr;
  }
}

template <typename T>
Linked_list<T>::node::_node(const node &other)
    : value(other.value), next_node(nullptr) {
    if (other.next_node != nullptr) {
        this->next_node = new node(*other.next_node);
    }
}
template <typename T>
Linked_list<T>::node::_node() : value(0), next_node(nullptr) {}
template <typename T>
Linked_list<T>::node::_node(T _value) : value(_value), next_node(nullptr) {}
template <typename T>
Linked_list<T>::node::_node(T _value, node *_next_node)
    : value(_value), next_node(_next_node) {}

template <typename T> int Linked_list<T>::delete_by_index(const int index) {
  if (this->is_list_empty()) {
    std::cerr << "The list is empty !" << std::endl;
    return 1;
  } else if (index == 0 && this->starting_node->next_node == nullptr) {
    delete this->starting_node;
    this->starting_node = nullptr;
    return 0;
  } else if (index == 0 && this->starting_node->next_node != nullptr) {
    node *mem_node(this->starting_node->next_node);
    delete this->starting_node;
    this->starting_node = mem_node;
    return 0;
  }
  int counter = 0;
  node *mem_node = nullptr;
  this->current_node = this->starting_node;
  while (counter < index && this->current_node->next_node != nullptr) {
    mem_node = this->current_node;
    this->current_node = this->current_node->next_node;
    counter++;
  }
  if (counter != index && this->current_node->next_node == nullptr) {
    return 1;
  } else if (counter == index && this->current_node->next_node == nullptr) {
    delete this->current_node;
  } else if (counter == index && this->current_node->next_node != nullptr) {
    mem_node->next_node = this->current_node->next_node;
    delete this->current_node;
  } else {
    return 1;
  }

  return 0;
}
template <typename T> bool Linked_list<T>::is_occurence_exist(const T value) {
  if (this->is_list_empty()) {
    std::cerr << "The list is empty !" << std::endl;
    return false;
  }
  node *curr_node = this->starting_node;
  while (curr_node != nullptr) {
    if (curr_node->value == value)
      return true;
    curr_node = curr_node->next_node;
  }
  return false;
}

template <typename T>
int Linked_list<T>::get_index_of_first_occurrence(const T value) {
  if (this->is_occurence_exist(value) == false)
    return -1;
  node *curr_node = this->starting_node;
  int index = 0;
  while (curr_node != nullptr) {
    if (curr_node->value == value)
      return index;
    index++;
    curr_node = curr_node->next_node;
  }
  return -1;
}

template <typename T> int Linked_list<T>::delete_by_value(const T value) {
  int index = 0;
  while ((index = this->get_index_of_first_occurrence(value)) != -1) {
    this->delete_by_index(value);
  }
  return 0;
}
