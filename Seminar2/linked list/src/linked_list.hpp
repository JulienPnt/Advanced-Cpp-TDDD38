#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

template <typename T> class Linked_list {
public:
  Linked_list();
  ~Linked_list();

  int add_value(const T value);
  int delete_by_index(const int index);
  int delete_by_value(const T value);

  void display_list();
  bool is_list_empty();

private:
  struct _node {
    T value;
    struct _node *next_node;
    _node(const _node &other);
    _node();
    _node(T value);
    _node(T _value, _node *_next_node);
  };
  typedef struct _node node;

  void _display_list();

  node *starting_node;
  node *current_node;

  node *go_to_last_node();
  void destroy_last_node();
  bool is_occurence_exist(const T value);
  int get_index_of_first_occurrence(const T value);
};

#include "linked_list.tpp"

#endif
