/* Demonstration of Argument Dependent Lookup (ADL). */

#include <iostream>

namespace Space {
  class X {};

  void swap(X& object1, X& object2) {
    std::cout << "Custom Swap" << '\n';
  }
}

void foo1() {
  std::cout << "foo1" << '\n';
  /* Uses std::swap, always. */
  Space::X obj1, obj2;
  std::swap(obj1, obj2);
}

void foo2() {
  std::cout << "foo2" << '\n';
  /* Uses Space::X swap if it exists. Otherwise, it does not compile. */
  Space::X obj1, obj2;
  swap(obj1, obj2);
}

void foo3() {
  std::cout << "foo3" << '\n';
  /* Uses Space::X swap if it exists. Otherwise, it uses std::swap. */
  using std::swap;
  Space::X obj1, obj2;
  swap(obj1, obj2);
}

int main() {
  foo1();
  foo2();
  foo3();
  return 0;
}
