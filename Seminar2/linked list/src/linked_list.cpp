#include "linked_list.hpp"

#include <exception>
#include <iostream>
#include <stdexcept>

Linked_list::Linked_list() : starting_node{nullptr} {
  std::cout << "Linked list is created !" << std::endl;
}

Linked_list::~Linked_list() {
  std::cout << "Linked list destruction is starting!" << std::endl;
  while (this->is_list_empty() == false) {
    this->destroy_last_node();
    this->display_list();
  }
  std::cout << "Linked list is destroyed!" << std::endl;
}

Linked_list::node *Linked_list::go_to_last_node() {
  node *curr_node = this->starting_node;
  while (curr_node != nullptr && curr_node->next_node != nullptr) {
    curr_node = curr_node->next_node;
  }
  return curr_node;
}

int Linked_list::last_value(int *value) {
  if (this->is_list_empty()) {
    std::cerr << "No node into the list" << std::endl;
    return 1;
  }
  node *curr_node = this->go_to_last_node();
  *value = curr_node->value;
  return 0;
}

int Linked_list::add_value(int value) {

  if (this->is_list_empty()) {
    this->starting_node = new node(value);
    return 0;
  } else if (value < this->starting_node->value) {
    node *node_mem(this->starting_node);
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
      node *node_mem(this->current_node->next_node);
      node *new_node = new node(value, node_mem);
      this->current_node->next_node = new_node;
      return 0;
    }
    this->current_node = this->current_node->next_node;
  }
  return 1;
}

void Linked_list::display_list() {
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

void Linked_list::_display_list() {
  if (this->current_node == nullptr) {
    std::cout << "-> nullptr" << std::endl;
  } else {
    std::cout << "-> " << this->current_node->value << " ";
    this->current_node = this->current_node->next_node;
    return this->_display_list();
  }
}

bool Linked_list::is_list_empty() { return this->starting_node == nullptr; }

void Linked_list::destroy_last_node() {
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

Linked_list::node::_node(const node &other)
    : value(other.value),
      next_node(other.next_node ? new node(*other.next_node) : nullptr) {}

Linked_list::node::_node() : value(0), next_node(nullptr) {}

Linked_list::node::_node(int _value) : value(_value), next_node(nullptr) {}
Linked_list::node::_node(int _value, node *_next_node)
    : value(_value), next_node(_next_node) {}
