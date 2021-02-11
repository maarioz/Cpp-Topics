#include <iostream>
#include <chrono>

class Timer {
private:
    using clock = std::chrono::high_resolution_clock;
    using second = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock> start;
public:
    Timer() : start(clock::now()) {}

    void reset() {
        start = clock::now();
    }

    double elapsed() const {
        return std::chrono::duration_cast<second>(clock::now() - start).count();
    }
};


int main() {
    Timer timer; /* Timer starts here. */

    for (int i = 0; i < 10000; ++i) {
        for (int j = 0; j < 50000; ++j) {
          /* ... */
        }
    }

    /* Calling elapsed() will tell us how long the program took to run up to that point.*/
    std::cout << timer.elapsed() << " seconds\n";

    return 0;
}
