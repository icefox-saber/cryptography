#include <iostream>
#include <vector>

// 模26运算
int mod26(int x) {
    return (x % 26 + 26) % 26;
}

int main() {
    // 定义3x3矩阵
    std::vector<std::vector<int>> matrix = {
        {3, 4, 6},
        {21, 15, 14},
        {20, 23, 5}
    };

    // 定义3x1向量
    std::vector<int> vector = {8, 13, 6};

    // 定义期望结果
    std::vector<int> expected_result = {8, 5, 21};

    // 计算矩阵和向量的乘积，并对每个元素模26
    std::vector<int> result(3, 0);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result[i] += matrix[i][j] * vector[j];
        }
        result[i] = mod26(result[i]); // 对结果进行模26运算
    }

    // 输出计算的结果
    std::cout << "Calculated result: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    // 检查计算结果是否与期望结果一致
    bool is_correct = true;
    for (int i = 0; i < 3; ++i) {
        if (result[i] != expected_result[i]) {
            is_correct = false;
            break;
        }
    }

    if (is_correct) {
        std::cout << "The matrix multiplication is correct (mod 26)." << std::endl;
    } else {
        std::cout << "The matrix multiplication is incorrect." << std::endl;
    }

    return 0;
}
