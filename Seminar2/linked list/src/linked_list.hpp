#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class Linked_list {
public:
  Linked_list();
  ~Linked_list();

  int last_value(int *value);

  int add_value(int value);

  void display_list();
  bool is_list_empty();

private:
  class Node {
  public:
    int value;
    Node *next_node;
    Node(const Node &other);
    Node();
    Node(int value);
  };

  void _display_list();

  Node *starting_node;
  Node *current_node;
  Node *last_node;

  Node *go_to_last_node();
  void destroy_last_node();
};

#endif
