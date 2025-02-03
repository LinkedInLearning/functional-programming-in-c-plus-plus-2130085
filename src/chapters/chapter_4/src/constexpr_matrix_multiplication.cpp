#include <iostream>
#include <array>

// Compile-time matrix multiplication
constexpr auto multiplyMatrices(const std::array<std::array<int, 2>, 2>& a,
                                const std::array<std::array<int, 2>, 2>& b) {
    std::array<std::array<int, 2>, 2> result = {};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
        }
    }
    return result;
}

int main() {
    constexpr std::array<std::array<int, 2>, 2> mat1 = {{{1, 2}, {3, 4}}};
    constexpr std::array<std::array<int, 2>, 2> mat2 = {{{5, 6}, {7, 8}}};

    constexpr auto result = multiplyMatrices(mat1, mat2);
    std::cout << "Matrix[0][0]: " << result[0][0] << "\n";
    std::cout << "Matrix[1][1]: " << result[1][1] << "\n";

    return 0;
}