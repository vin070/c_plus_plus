#include <iostream>

class linked_list {
private:
  int data;
  linked_list *next = NULL;

public:
  linked_list(int data) { this->data = data; }

  int get_data() const { return this->data; }

  void set_next(linked_list *next) { this->next = next; }

  linked_list *get_next() const { return this->next; }

  static linked_list *take_input() {
    int data = 0;
    std::cin >> data;
    linked_list *head = NULL, *tail = NULL;
    while (data != -1) {
      linked_list *node = new linked_list(data);
      if (head == NULL) {
        head = node;
        tail = node;
      } else {
        tail->set_next(node);
        tail = node;
      }
      std::cin >> data;
    }
    return head;
  }
  void static delete_all(linked_list *head) {
    while (head != NULL) {
      linked_list *new_head = head->get_next();
      delete head;
      head = new_head;
    }
    return;
  }

  static void print(linked_list *head) {
    while (head != NULL) {
      std::cout << head->get_data() << " ";
      head = head->get_next();
    }
    std::cout << std::endl;
  }
};

// struct circular_linked_list {
//   linked_list *odd_head;
//   linked_list *odd_tail;
//   linked_list *even_head;

//   circular_linked_list(linked_list *odd_head, linked_list *odd_tail,
//                        linked_list *even_head) {
//     this->odd_head = odd_head;
//     this->odd_tail = odd_tail;
//     this->even_head = even_head;
//   }
// };

// Recursive
// circular_linked_list *even_after_odd_helper(linked_list *head) {
//   if (!head) {
//     circular_linked_list *new_node = new circular_linked_list(head, head,
//     head); return new_node;
//   }

//   circular_linked_list *ans = even_after_odd_helper(head->get_next());

//   if (head->get_data() % 2 == 0) {
//     head->set_next(ans->even_head);
//     ans->even_head = head;
//   } else {
//     head->set_next(ans->odd_head);
//     ans->odd_head = head;
//     if (!ans->odd_tail)
//       ans->odd_tail = head;
//   }
//   return ans;
// }

// linked_list *even_after_odd(linked_list *head) {
//   circular_linked_list *ans = even_after_odd_helper(head);
//   if (ans->odd_head) {
//     ans->odd_tail->set_next(ans->even_head);
//     return ans->odd_head;
//   } else
//     return ans->even_head;
// }

linked_list *even_after_odd(linked_list *head) {

  linked_list *even_head = NULL;
  linked_list *odd_head = NULL;
  linked_list *odd_tail = NULL;
  linked_list *even_tail = NULL;
  while (head) {
    bool is_even = head->get_data() % 2 == 0;
    // First occurence of even number
    if (is_even && !even_tail) {
      even_head = head;
      even_tail = head;
    }
    // After first  occurence of even number
    else if (is_even && even_tail) {
      even_tail->set_next(head);
      even_tail = head;
    }
    // First occurence of odd number
    else if (!is_even && !odd_tail) {
      odd_head = head;
      odd_tail = head;
    }
    // After first occurence of odd number
    else if (!is_even && odd_tail) {
      odd_tail->set_next(head);
      odd_tail = head;
    }
    head = head->get_next();
  }
  // This case occurs when both even and odd numbers is in linked list
  // If only one type is present then tail->next will be already NULL
  if (odd_tail && even_tail) {
    odd_tail->set_next(even_head);
    even_tail->set_next(NULL);
  }

  if (odd_head)
    return odd_head;
  else
    return even_head;
}

int main() {
  int test_cases = 0;
  std::cin >> test_cases;
  while (test_cases--) {
    linked_list *head = linked_list::take_input();
    head = even_after_odd(head);
    linked_list::print(head);
    linked_list::delete_all(head);
  }
  return 0;
}