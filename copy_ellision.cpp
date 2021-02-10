#include <iostream>

struct Noisy {
  Noisy() { std::cout << "no parameter ctor" << '\n'; }
  Noisy(const Noisy& other) { std::cout << "copy ctor" << '\n'; }
  Noisy(Noisy&& other) { std::cout << "move ctor" << '\n'; }
  void f() { std::cout << "Noisy::f()" << '\n'; }
  ~Noisy() { std::cout << "dtor" << '\n'; }
};

/* Return Value Optimalization. */
Noisy foo1() {
  return Noisy{};
}

Noisy foo2() {
  return Noisy{Noisy{Noisy{Noisy{Noisy{}}}}};
}

/* Named Return Value Optimalization */
Noisy foo3() {
  Noisy a;
  // ...
  return a;
}

Noisy foo4(Noisy x) {
  // ...
  x.f();
  // Move will be implicitly called when function argument is taken by value.
  return x;
}

/* Copy WILL happen! */
Noisy foo5(bool flag) {
  Noisy a;
  Noisy b;
  // ...
  return flag ? a : b;
}

int main() {
  Noisy n1 = foo1();
  Noisy n2 = foo2();
  Noisy n3 = foo3();

  Noisy test;
  Noisy n4 = foo4(test);

  Noisy n5 = foo4(Noisy{});
  Noisy n6 = foo5(true);

  return 0;
}
