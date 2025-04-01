#include <iostream>
#include <type_traits>

// Function that only accepts integral types
template <typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
T process_integral(T value) {
    std::cout << "Processing integral value: " << value << std::endl;
    return value;
}

// Function that only accepts floating-point types
template <typename T, typename = std::enable_if_t<std::is_floating_point_v<T>>>
T process_floating_point(T value) {
    std::cout << "Processing floating-point value: " << value << std::endl;
    return value;
}

int main() {
    process_integral(10); // Output: Processing integral value: 10
    process_floating_point(3.14f); // Output: Processing floating-point value: 3.14
    
    // The following lines would cause compilation errors because of `enable_if`:
    // process_integral(3.14);
    // process_floating_point(10);

    return 0;
}