#include <iostream>
#include <chrono>

int main() {
    using namespace std::chrono;

    auto start = high_resolution_clock::now();

    std::system("./main");

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    std::cout << "Execution time: " << duration.count() << " ms\n";
    std::cout << (duration.count() < 100 ? "PASS\n" : "FAIL\n");
    start = high_resolution_clock::now();

    std::system("./main --help -o --cli -0");

    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

    std::cout << "Execution time: " << duration.count() << " ms\n";
    std::cout << (duration.count() < 100 ? "PASS\n" : "FAIL\n");

    std::system("./main --help -h --cli -c --output -o --version -v");

    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);

    std::cout << "Execution time: " << duration.count() << " ms\n";
    std::cout << (duration.count() < 100 ? "PASS\n" : "FAIL\n");

    return 0;
}
