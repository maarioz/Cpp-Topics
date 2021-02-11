#include <iostream>
#include <bitset>

constexpr int option1 = 0x01; // 001
constexpr int option2 = 0x02; // 010
constexpr int option3 = 0x04; // 100

template <unsigned T>
std::bitset<T> rotateLeft(std::bitset<T>& bits, unsigned places) {
  return (bits << (places % bits.size())) | (bits >> (bits.size() - places % bits.size()));
}

template<unsigned T>
std::bitset<T> rotateRight(std::bitset<T>& bits, unsigned places) {
  return (bits >> (places % bits.size())) | (bits << (bits.size() - places % bits.size()));
}

void foo(bool opt1, bool opt2, bool opt3) {
  if (opt1) {
    // ...
  }
}

void foo(int options) {
  if (options & option1) {
    // ...
  }
}

int main(int argc, char* argv[]) {

  constexpr std::bitset<8> mask0{ 1 << 0 }; // 0000 0001
	constexpr std::bitset<8> mask1{ 1 << 1 }; // 0000 0010
	constexpr std::bitset<8> mask2{ 1 << 2 }; // 0000 0100
	constexpr std::bitset<8> mask3{ 1 << 3 }; // 0001 0000
	constexpr std::bitset<8> mask4{ 1 << 4 }; // 0001 0000
	constexpr std::bitset<8> mask5{ 1 << 5 }; // 0010 0000
	constexpr std::bitset<8> mask6{ 1 << 6 }; // 0100 0000
	constexpr std::bitset<8> mask7{ 1 << 7 }; // 1000 0000

  std::bitset<8> bits{0};

  /* Set 2nd, 4th and 6th bits */
  bits |= (mask2 | mask4 | mask6);

  /* Reset 4th and 6th bits */
  bits &= ~(mask4 | mask6);

  /* Flip 1st and 5th bits */
  bits ^= (mask1 | mask5);

  foo(true, false, true);
  foo(option1 | option3);

  return 0;
}
