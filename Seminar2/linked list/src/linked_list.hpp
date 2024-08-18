#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

class Linked_list {
public:
  Linked_list();
  ~Linked_list();

  int last_value(int *value);

  int add_value(int value);
  int delete_by_index(const int index);
  int delete_by_value(const int value);

  void display_list();
  bool is_list_empty();

private:
  struct _node {
    int value;
    struct _node *next_node;
    _node(const _node &other);
    _node();
    _node(int value);
    _node(int _value, _node *_next_node);
  };
  typedef struct _node node;

  void _display_list();

  node *starting_node;
  node *current_node;
  node *last_node;

  node *go_to_last_node();
  void destroy_last_node();
  bool is_occurence_exist(const int value);
  int get_index_of_first_occurrence(const int value);
};

#endif
