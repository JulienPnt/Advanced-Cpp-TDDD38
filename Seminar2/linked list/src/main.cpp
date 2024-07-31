#include "linked_list.hpp"

#include <cassert>
#include <iostream>

int main() {

  // Test case
  Linked_list my_linked_list = Linked_list();
  my_linked_list.add_value(0);
  my_linked_list.display_list();
  my_linked_list.add_value(1);
  my_linked_list.display_list();
  my_linked_list.add_value(2);
  my_linked_list.display_list();
  my_linked_list.add_value(3);
  my_linked_list.display_list();
  my_linked_list.add_value(4);
  my_linked_list.display_list();
  my_linked_list.add_value(5);
  my_linked_list.display_list();
  my_linked_list.add_value(6);

  /*
  my_linked_list.display_list();
  my_linked_list.delete_by_index(0);
  my_linked_list.display_list();
  my_linked_list.delete_by_index(6);
  my_linked_list.display_list();
  my_linked_list.delete_by_index(5);
  my_linked_list.display_list();
  my_linked_list.delete_by_index(2);
  my_linked_list.display_list();
  */
  return 0;
}
