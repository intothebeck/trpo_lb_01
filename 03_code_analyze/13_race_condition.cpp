#include <iostream>
#include <thread>
#include <vector>

int main() {
    int counter = 0;
    const int num_threads = 100;
    const int num_loops = 100;
    
    std::vector<std::thread> threads;
    
    for (int i = 0; i < num_threads; ++i) {
        threads.emplace_back([&counter, num_loops](){
            for (int j = 0; j < num_loops; ++j) {
                counter++;
            }
        });
    }
    
    for (std::thread& t : threads) {
        t.join();
    }
    
    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}
