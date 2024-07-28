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

Linked_list::Node *Linked_list::go_to_last_node() {
  Node *curr_node = this->starting_node;
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
  Node *curr_node = this->go_to_last_node();
  *value = curr_node->value;
  return 0;
}

int Linked_list::add_value(int value) {

  std::cout << "2" << std::endl;
  if (this->is_list_empty()) {
    this->starting_node = new Node;
    this->starting_node->value = value;
    this->starting_node->next_node = nullptr;
    return 0;
  } else if (value < this->starting_node->value) {
    Node *node_mem(this->starting_node);
    node_mem->value = this->starting_node->value;
    node_mem->next_node = this->starting_node->next_node;
    delete this->starting_node;
    Node new_node(value);
    this->starting_node = &new_node;
    this->starting_node->next_node = node_mem;
    return 0;
  }

  std::cout << "3" << std::endl;
  this->current_node = this->starting_node;
  while (this->current_node != nullptr) {
    std::cout << "4" << std::endl;
    if (this->current_node->next_node == nullptr) {
      std::cout << "5" << std::endl;
      Node new_node(value);
      std::cout << "6" << std::endl;
      new_node.next_node = nullptr;
      std::cout << "7" << std::endl;
      this->current_node->next_node = &new_node;
      return 0;
    } else if (this->current_node->next_node->value > value) {
      Node *node_mem(this->current_node);
      node_mem->value = this->current_node->next_node->value;
      node_mem->next_node = this->current_node->next_node->next_node;
      Node new_node(value);
      new_node.next_node = node_mem;
      this->current_node->next_node = &new_node;
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
  } else if (this->starting_node->next_node == nullptr) {
    delete this->starting_node;
    this->starting_node = nullptr;
  } else {
    this->current_node = this->starting_node;
    while (this->current_node->next_node->next_node != nullptr) {
      this->current_node = this->current_node->next_node;
    }
    delete this->current_node->next_node;
    this->current_node->next_node = nullptr;
  }
}

Linked_list::Node::Node(const Node &other)
    : value(other.value),
      next_node(other.next_node ? new Node(*other.next_node) : nullptr) {}

Linked_list::Node::Node() : value{0}, next_node(nullptr) {}

Linked_list::Node::Node(int _value) : value{_value}, next_node(nullptr) {}
