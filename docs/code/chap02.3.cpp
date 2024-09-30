#include <iostream>
#include <vector>

// 模26运算
int mod26(int x)
{
    return (x % 26 + 26) % 26;
}

// 检查当前的k值是否满足方程
bool checkSolution(const std::vector<int> &k_values, const std::vector<std::vector<int>> &matrix, const std::vector<int> &results)
{
    for (int i = 0; i < 3; ++i)
    {
        int sum = 0;
        for (int j = 0; j < 3; ++j)
        {
            sum += matrix[i][j] * k_values[j];
        }
        if (mod26(sum) != results[i])
        {
            return false; // 当前的k值不满足方程
        }
    }
    return true;
}

int main()
{
    // 系数矩阵
    std::vector<std::vector<int>> matrix = {
        {1, 17, 4},
        {0, 19, 7},
        {19, 0, 10}};

    // 方程右侧的结果向量
    std::vector<std::vector<int>> results = {
        {17, 14, 13},
        {20, 19, 19},
        {15, 4, 14}};

    // 穷举所有可能的k值
    for (int ki = 1; ki <= 3; ki++)
    {
        for (int k11 = 0; k11 < 26; ++k11)
        {
            for (int k12 = 0; k12 < 26; ++k12)
            {
                for (int k13 = 0; k13 < 26; ++k13)
                {
                    std::vector<int> k_values = {k11, k12, k13};
                    if (checkSolution(k_values, matrix, results[ki-1]))
                    {
                        std::cout << " k" <<ki<<"1=" << k11 << " k"<< ki<<"2=" << k12 << " k"<<ki<<"3=" << k13 << std::endl;
                    }
                }
            }
        }
    }
    return 0;
}
