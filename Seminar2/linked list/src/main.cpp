#include "linked_list.hpp"

#include <cassert>
#include <iostream>

int main() {

  // Test case
  Linked_list<int> my_linked_list = Linked_list<int>();
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
  my_linked_list.add_value(5);
  my_linked_list.add_value(5);
  my_linked_list.add_value(5);
  my_linked_list.display_list();
  my_linked_list.add_value(6);
  my_linked_list.display_list();

  std::cout << "Value 5 is going to be deleted" << std::endl;
  my_linked_list.delete_by_value(5);
  my_linked_list.display_list();
  // Test case
  Linked_list<double> my_linked_list_2 = Linked_list<double>();
  my_linked_list_2.add_value(1);
  my_linked_list_2.add_value(1.1);
  my_linked_list_2.add_value(0.1);
  my_linked_list_2.add_value(-0.1);
  my_linked_list_2.add_value(10.1);
  my_linked_list_2.display_list();

  std::cout << "Value \'-0.1\' is going to be deleted" << std::endl;
  my_linked_list_2.delete_by_value(0.1);
  my_linked_list_2.display_list();

  Linked_list<char> my_linked_list_3 = Linked_list<char>();
  my_linked_list_3.add_value('a');
  my_linked_list_3.add_value('b');
  my_linked_list_3.add_value('c');
  my_linked_list_3.add_value('d');
  my_linked_list_3.add_value('a');
  my_linked_list_3.add_value('a');
  my_linked_list_3.add_value('b');
  my_linked_list_3.add_value('a');
  my_linked_list_3.add_value('z');
  my_linked_list_3.display_list();

  return 0;
}
