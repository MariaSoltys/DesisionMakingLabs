#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class ChoiceMechanism {
public:
    std::vector<std::vector<int>> Q;
    int numAlternatives;
    int numCriteria;
    double alpha;
    std::vector<int> QE;
    std::vector<double> lambdaVector;
    std::string order;
    int mainCriteria;
    std::vector<int> QM;

    ChoiceMechanism(std::vector<std::vector<int>> Q, std::vector<int> QE, std::string order, int mainCriteria, std::vector<int> QM)
        : Q(Q), QE(QE), order(order), mainCriteria(mainCriteria), QM(QM) {
        numAlternatives = Q.size();
        numCriteria = Q[0].size();
        alpha = 0.5; 
        lambdaVector = {}; 
    }

    std::vector<int> searchMax(std::vector<std::vector<int>> T) {
        std::vector<int> maximums;
        for (int i = 0; i < numAlternatives; i++) {
            bool isMaximum = true;
            for (int j = 0; j < numAlternatives; j++) {
                if (i != j && T[i][j] != 1) {
                    isMaximum = false;
                    break;
                }
            }
            if (isMaximum) {
                maximums.push_back(i);
            }
        }
        return maximums;
    }

    std::vector<int> searchMin(std::vector<std::vector<int>> T) {
        std::vector<int> minimums;
        for (int i = 0; i < numAlternatives; i++) {
            bool isMinimum = true;
            for (int j = 0; j < numAlternatives; j++) {
                if (i != j && T[i][j] != 1) {
                    isMinimum = false;
                    break;
                }
            }
            if (isMinimum) {
                minimums.push_back(i);
            }
        }
        return minimums;
    }

    std::vector<int> searchMajr(std::vector<std::vector<int>> T) {
        std::vector<int> majorants;
        for (int j = 0; j < numAlternatives; j++) {
            bool isMajorant = true;
            for (int i = 0; i < numAlternatives; i++) {
                if (i != j && T[i][j] != 0) {
                    isMajorant = false;
                    break;
                }
            }
            if (isMajorant) {
                majorants.push_back(j);
            }
        }
        return majorants;
    }

    std::vector<int> searchMinr(std::vector<std::vector<int>> T) {
        std::vector<int> minorants;
        for (int i = 0; i < numAlternatives; i++) {
            bool isMinorant = true;
            for (int j = 0; j < numAlternatives; j++) {
                if (i != j && T[i][j] != 0) {
                    isMinorant = false;
                    break;
                }
            }
            if (isMinorant) {
                minorants.push_back(i);
            }
        }
        return minorants;
    }

    std::string formatAlternatives(std::vector<int> lst) {
        if (lst.empty()) {
            return "nothing found";
        }
        std::string result = "";
        for (int i = 0; i < lst.size(); i++) {
            if (i > 0) {
                result += ", ";
            }
            result += "a" + std::to_string(lst[i] + 1);
        }
        return result;
    }

    void setMechanism(std::string mechanism) {
        std::vector<std::vector<int>> T;
        if (mechanism == "pareto") {
            T = paretoDecision();
            std::cout << "\n" << mechanism << " decision T matrix\n" << printMatrix(T) << std::endl;
            std::vector<int> majorants = searchMajr(T);
            std::cout << "Majorants: " << formatAlternatives(majorants) << std::endl;
        }
        else if (mechanism == "slater") {
            T = slaterDecision();
            std::cout << "\n" << mechanism << " decision T matrix\n" << printMatrix(T) << std::endl;
            std::vector<int> maximums = searchMax(T);
            std::cout << "Maximums: " << formatAlternatives(maximums) << std::endl;
        }
        else {
            std::cout << "Unknown mechanism: " << mechanism << std::endl;
        }
    }
    std::vector<std::vector<int>> paretoDecision() {
        std::vector<std::vector<int>> T(numAlternatives, std::vector<int>(numAlternatives));
        for (int i = 0; i < numAlternatives; i++) {
            for (int j = 0; j < numAlternatives; j++) {
                if (i != j) {
                    std::vector<int> difference = vectorSubtract(Q[i], Q[j]);
                    bool allPositive = true;
                    bool anyPositive = false;
                    for (int diff : difference) {
                        if (diff < 0) {
                            allPositive = false;
                            break;
                        }
                        else if (diff > 0) {
                            anyPositive = true;
                        }
                    }
                    if (allPositive && anyPositive) {
                        T[i][j] = 1;
                    }
                }
            }
        }
        return T;
    }

    std::vector<int> vectorSubtract(std::vector<int> a, std::vector<int> b) {
        std::vector<int> result(numCriteria);
        for (int i = 0; i < numCriteria; i++) {
            result[i] = a[i] - b[i];
        }
        return result;
    }

    std::vector<std::vector<int>> slaterDecision() {
        std::vector<std::vector<int>> T(numAlternatives, std::vector<int>(numAlternatives));
        for (int i = 0; i < numAlternatives; i++) {
            for (int j = 0; j < numAlternatives; j++) {
                if (i != j) {
                    std::vector<int> difference = vectorSubtract(Q[i], Q[j]);
                    bool allPositive = true;
                    for (int diff : difference) {
                        if (diff <= 0) {
                            allPositive = false;
                            break;
                        }
                    }
                    if (allPositive) {
                        T[i][j] = 1;
                    }
                }
                else {
                    T[i][j] = 1;
                }
            }
        }
        return T;
    }

    std::vector<int> bestResult(std::vector<std::vector<int>> T) {
        std::vector<int> result;
        for (int i = 0; i < numAlternatives; i++) {
            bool isBest = true;
            for (int j = 0; j < numAlternatives; j++) {
                if (i != j && T[i][j] != 1) {
                    isBest = false;
                    break;
                }
            }
            if (isBest) {
                result.push_back(i);
            }
        }
        return result;
    }

    std::vector<int> guaranteedResult(std::vector<std::vector<int>> T) {
        std::vector<int> result;
        for (int i = 0; i < numAlternatives; i++) {
            bool isGuaranteed = true;
            for (int j = 0; j < numAlternatives; j++) {
                if (i != j && T[i][j] != 0) {
                    isGuaranteed = false;
                    break;
                }
            }
            if (isGuaranteed) {
                result.push_back(i);
            }
        }
        return result;
    }

    std::vector<int> byReferenceResult() {
        return searchMinr(Q);
    }

    std::vector<int> lexicographicResult() {
        std::vector<int> result;

        std::vector<int> indices(numAlternatives);
        for (int i = 0; i < numAlternatives; i++) {
            indices[i] = i;
        }
        std::sort(indices.begin(), indices.end(), [&](int a, int b) {
            return Q[a] < Q[b];
            });

        result.push_back(indices[0]);

        return result;
    }

    std::vector<int> mainCriterionResult() {
        std::vector<int> result;

        int maxIndex = 0;
        for (int i = 1; i < numAlternatives; i++) {
            if (Q[i][mainCriteria] > Q[maxIndex][mainCriteria]) {
                maxIndex = i;
            }
        }

        result.push_back(maxIndex);
        return result;
    }

    std::string printMatrix(std::vector<std::vector<int>> matrix) {
        std::string result = "";
        for (int i = 0; i < numAlternatives; i++) {
            result += "[";
            for (int j = 0; j < numAlternatives; j++) {
                result += std::to_string(matrix[i][j]);
                if (j < numAlternatives - 1) {
                    result += " ";
                }
            }
            result += "]";
            if (i < numAlternatives - 1) {
                result += "\n";
            }
        }
        return result;
    }
};

int main() {
    std::vector<std::vector<int>> Q = {
        {7, 3, 5},
        {8, 5, 7},
        {6, 4, 3},
        {3, 5, 8}
    };
    std::vector<int> QE = { 4, 4, 5 };
    std::string order = "Q3->Q2->Q1";
    int mainCriteria = 1;
    std::vector<int> QM = { 3, 4 };

    ChoiceMechanism cm(Q, QE, order, mainCriteria, QM);

    cm.setMechanism("pareto");
    cm.setMechanism("slater");

    std::vector<int> bestRes = cm.bestResult(cm.paretoDecision());
    std::cout << "Best Result: " << cm.formatAlternatives(bestRes) << std::endl;

    std::vector<int> guaranteedRes = cm.guaranteedResult(cm.paretoDecision());
    std::cout << "Guaranteed Result: " << cm.formatAlternatives(guaranteedRes) << std::endl;

    std::vector<int> byRefRes = cm.byReferenceResult();
    std::cout << "By Reference Result: " << cm.formatAlternatives(byRefRes) << std::endl;

    std::vector<int> lexicoRes = cm.lexicographicResult();
    std::cout << "Lexicographic Result: " << cm.formatAlternatives(lexicoRes) << std::endl;

    std::vector<int> mainCritRes = cm.mainCriterionResult();
    std::cout << "Main Criterion Result: " << cm.formatAlternatives(mainCritRes) << std::endl;

    return 0;
}
