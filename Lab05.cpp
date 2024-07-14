#include <iostream>
#include <cmath>
#include <vector>

class RelationMatr {
public:
    bool isAgreed(const std::vector<std::vector<int>>& metricMatrix) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (metricMatrix[i][j] != 0 && metricMatrix[i][j] != 1000) {
                    if (!(metricMatrix[i][j] == -metricMatrix[j][i])) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    double findDistance(const std::vector<std::vector<int>>& m, const std::vector<std::vector<int>>& m1) {
        double sum = 0.0;

        if (isAgreed(m) && isAgreed(m1)) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (m[i][j] != 1000) {
                        sum += std::abs(static_cast<double>(m[i][j] - m1[i][j]));
                    }
                    else if (m[i][j] == 1000 && m1[i][j] == 1000) {
                        sum += 0.0;
                    }
                    else if (m[i][j] > m1[i][j]) {
                        sum += static_cast<double>(m[i][j]);
                    }
                    else {
                        sum += static_cast<double>(m1[i][j]);
                    }
                }
            }
        }
        else {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (m[i][j] != 1000) {
                        sum += std::abs(static_cast<double>(m[i][j] - m1[i][j]));
                    }
                    else if (m[i][j] == 1000 && m1[i][j] == 1000) {
                        sum += 0.0;
                    }
                    else if (m[i][j] > m1[i][j]) {
                        sum += static_cast<double>(m[i][j]);
                    }
                    else {
                        sum += static_cast<double>(m1[i][j]);
                    }
                    if (m[j][i] != 1000) {
                        sum += static_cast<double>(m[j][i] - m1[j][i]);
                    }
                    else if (m[j][i] == 1000 && m1[j][i] == 1000) {
                        sum += 0.0;
                    }
                    else if (m[j][i] > m1[j][i]) {
                        sum += static_cast<double>(m[j][i]);
                    }
                    else {
                        sum += static_cast<double>(m1[j][i]);
                    }
                }
            }
        }

        return sum / 2.0;
    }
};

class Relation {
public:
    std::vector<std::vector<int>> getQ1() {
        std::vector<std::vector<int>> mas = {
            {1, 0, 0, 0, 0},
            {0, 1, 0, 0, 0},
            {1, 1, 1, 1, 1},
            {0, 0, 0, 1, 0},
            {1, 0, 0, 0, 1}
        };
        return mas;
    }

    std::vector<std::vector<int>> getR1() {
        std::vector<std::vector<int>> mas = {
            {1, 0, 0, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 1, 1, 0, 1}
        };
        return mas;
    }

    std::vector<std::vector<int>> getS1() {
        std::vector<std::vector<int>> mas = {
            {0, 1, -1, 2, -1},
            {-1, 0, -2, 1, -2},
            {1, 2, 0, 3, 0},
            {-2, -1, -3, 0, -3},
            {1, 2, 0, 3, 0}
        };
        return mas;
    }

    std::vector<std::vector<int>> getT1() {
        std::vector<std::vector<int>> mas = {
            {0, -2, -2, 0, -2},
            {2, 0, 0, 2, 0},
            {2, 0, 0, 2, 0},
            {0, -2, -2, 0, -2},
            {2, 0, 0, 2, 0}
        };
        return mas;
    }
};

void printMatrix(const std::vector<std::vector<int>>& array) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    RelationMatr relMatr;
    Relation relationInstance;

    std::cout << "Q = " << std::endl;
    printMatrix(relationInstance.getQ1());

    std::cout << "R = " << std::endl;
    printMatrix(relationInstance.getR1());

    std::cout << "Result: " << relMatr.findDistance(relationInstance.getQ1(), relationInstance.getR1()) << std::endl;
    std::cout << "Linear order" << std::endl;

    std::cout << "Q1 = " << std::endl;
    printMatrix(relationInstance.getQ1());

    std::cout << "R1 = " << std::endl;
    printMatrix(relationInstance.getR1());

    std::cout << "Result: " << relMatr.findDistance(relationInstance.getQ1(), relationInstance.getR1()) << std::endl;
    std::cout << "Equivalence" << std::endl;

    std::cout << "S1 = " << std::endl;
    printMatrix(relationInstance.getS1());

    std::cout << "T1 = " << std::endl;
    printMatrix(relationInstance.getT1());

    std::cout << "Result: " << relMatr.findDistance(relationInstance.getS1(), relationInstance.getT1()) << std::endl;

    return 0;
}
