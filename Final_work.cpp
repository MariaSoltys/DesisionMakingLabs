#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <chrono>
using namespace std;

const int SIZE = 5;

class Relation 
{
public:

    int** Convert(int P[SIZE][SIZE])
    {
        int** res = new int* [SIZE];
        for (int i = 0; i < SIZE; i++) {
            res[i] = new int[SIZE];
            for (int j = 0; j < SIZE; j++) {
                res[i][j] = P[i][j];
            };
        };
        return res;
    };

    int** Printing(int** P)
    {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                cout << P[i][j] << ' ';
            };
            cout << endl;
        };
        cout << endl;
        return 0;
    }

    int** Union(int** P, int** Q)
    {

        int** result = new int* [SIZE];

        for (int i = 0; i < SIZE; i++) {
            result[i] = new int[SIZE];
            for (int j = 0; j < SIZE; j++) {
                if (P[i][j] == Q[i][j]) {
                    result[i][j] = P[i][j];
                }
                else { result[i][j] = 0; };
            };
        };

        return result;
    };

    int** Intersection(int** P, int** Q)
    {

        int** result = new int* [SIZE];

        for (int i = 0; i < SIZE; i++) {
            result[i] = new int[SIZE];
            for (int j = 0; j < SIZE; j++) {
                if ((P[i][j] == 1) || (Q[i][j] == 1)) {
                    result[i][j] = 1;
                }
                else {
                    result[i][j] = 0;
                };
            };
        };

        return result;
    };

    int** Difference(int** P, int** Q)
    {

        int** result = new int* [SIZE];
        for (int i = 0; i < SIZE; i++) {
            result[i] = new int[SIZE];
            for (int j = 0; j < SIZE; j++) {
                if ((P[i][j] == 1) && (Q[i][j] == 0)) {
                    result[i][j] = 1;
                }
                else {
                    result[i][j] = 0;
                };
            };
        };

        return result;
    };

    int** SymDiff(int** P, int** Q)
    {
        int** result = new int* [SIZE],
            ** result1 = Union(P, Q),
            ** result2 = Intersection(P, Q);


        for (int i = 0; i < SIZE; i++) {
            result[i] = new int[SIZE];
            for (int j = 0; j < SIZE; j++) {
                if (result1[i][j] != result2[i][j]) {
                    result[i][j] = 1;
                }
                else {
                    result[i][j] = 0;
                };
            };
        };

        for (int i = 0; i < SIZE; i++) {
            delete[] result1[i];
        }
        delete[] result1;

        for (int i = 0; i < SIZE; i++) {
            delete[] result2[i];
        }
        delete[] result2;

        return result;
    };

    int** Complement(int** P) //доповнення
    {
        int** result = new int* [SIZE];

        for (int i = 0; i < SIZE; i++) {
            result[i] = new int[SIZE];
            for (int j = 0; j < SIZE; j++) {
                if (P[i][j] == 0) {
                    result[i][j] = 1;
                }
                else {
                    result[i][j] = 0;
                };
            };
        };

        return result;
    };

    int** Converce(int** P) //обернена
    {
        int** result = new int* [SIZE];

        for (int i = 0; i < SIZE; i++) {
            result[i] = new int[SIZE];
            for (int j = 0; j < SIZE; j++) {
                result[i][j] = P[j][i];
            };
        };

        return result;
    };

    int** Addition(int** P) //доповнення
    {
        int** result = new int* [SIZE];

        for (int i = 0; i < SIZE; i++) {
            result[i] = new int[SIZE];
            for (int j = 0; j < SIZE; j++) {
                if (P[i][j] == 0) {
                    result[i][j] = 1;
                }
                else {
                    result[i][j] = 0;
                }
                
            };
        };

        return result;
    };

    int** Composition(int** P, int** Q) //композиція
    {
        int** result = new int* [SIZE];

        for (int i = 0; i < SIZE; i++) {
            result[i] = new int[SIZE];
            for (int j = 0; j < SIZE; j++) {
                result[i][j] = 0;
                for (int k = 0; k < SIZE; k++) {
                    result[i][j] += P[i][k] * Q[k][j];

                };
            };
        };

        return result;
    };

    bool prp_Reflexivity(int** P)
    {
        bool check = true;
        for (int i = 0; i < SIZE; i++)
        {
            if (P[i][i] != 1) {
                check = false;
            };
        };

        cout << "Reflexivity: ";
        if (check) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        };
        return check;
    };

    bool prp_Antireflexivity(int** P)
    {
        bool check = true;
        for (int i = 0; i < SIZE; i++)
        {
            if (P[i][i] != 0) {
                check = false;
            };
        };

        cout << "Antireflexivity: ";
        if (check) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        };
        return check;
    };

    bool prp_Symmetry(int** P)
    {
        bool check = true;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (P[i][j] != P[j][i]) {
                    check = false;
                };
            };
        };

        cout << "Symmetry: ";
        if (check) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        };
        return check;
    };

    bool prp_Asymmetry(int** P)
    {
        bool check = true;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (i != j){
                    if (P[i][j] == P[j][i]) {
                        check = false;
                    };
                }
                else 
                {
                    if (P[i][i] == 1) 
                    {
                        check = false;
                    };
                };
            };
        };

        cout << "Asymmetry: ";
        if (check) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        };
        return check;
    };

    bool prp_Antisymmetry(int** P)
    {
        bool check = true;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (P[i][j] == P[j][i]) {
                    check = false;
                };
            };
        };

        cout << "Antisymmetry: ";
        if (check) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        };
        return check;
    };

    bool prp_Transitivity(int** P)
    {
        bool check = true;
        for (int a = 0; a < SIZE; a++) {
            for (int b = 0; b < SIZE; b++) {
                for (int c = 0; c < SIZE; c++) {
                    if (P[a][b] == 1 && P[b][c] == 1 && P[a][c] != 1) {
                        check = false;
                        return false;
                    }
                }
            }
        }
        cout << "Transitivity: ";
        if (check) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        };
        return check;
    };

    bool prp_Acyclicity(int** P)
    {
        bool check = true;
        int** temp = new int* [SIZE];
        temp = Union(P, Converce(P));
        int k = 0;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (temp[i][j] != 0) {
                    k++;
                };
            };
        };
        if (k > 0)
        {
            check = false;
        };
        for (int i = 0; i < SIZE; i++) {
            delete[] temp[i];
        };
        delete[] temp;
        cout << "Acyclicity: ";
        if (check) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        };
        return check;
    };

    bool prp_Connection(int** P)
    {
        bool check = true;
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                if (i != j) {
                    if (P[i][j] == P[j][i]) {
                        check = false;
                    };
                }
                else
                {
                    if (P[i][i] == 1)
                    {
                        check = false;
                    };
                };                
            };
        };

        cout << "Connection: ";
        if (check) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        };

        return check;
    };

    void Check_prp(int** P)
    {
        prp_Reflexivity(P);
        prp_Antireflexivity(P);
        prp_Symmetry(P);
        prp_Asymmetry(P);
        prp_Antisymmetry(P);
        prp_Transitivity(P);
        prp_Acyclicity(P);
        prp_Connection(P);
    };

    //Type of binary relations
    bool type_Tolerance(int** P)
    {
        bool check = false;
        if (prp_Symmetry(P) && prp_Reflexivity(P) && !prp_Transitivity(P))
        {
            check = true;
            cout << "Relation type: Tolerance" << endl;
        };

        return check;
    };

    bool type_Equivalence(int** P)
    {
        bool check = false;
        if (prp_Symmetry(P) && prp_Reflexivity(P) && prp_Transitivity(P))
        {
            check = true;
            cout << "Relation type: Equivalence" << endl;
        };

        return check;
    };

    bool type_Quasiorder(int** P)
    {
        bool check = false;
        if (prp_Transitivity(P) && prp_Reflexivity(P) && !prp_Symmetry(P) && !prp_Antisymmetry(P))
        {
            check = true;
            cout << "Relation type: Quasiorder" << endl;
        };

        return check;
    };

    bool type_Order(int** P)
    {
        bool check = false;
        if (prp_Antisymmetry(P) && prp_Reflexivity(P) && prp_Transitivity(P))
        {
            check = true;
            cout << "Relation type: Order" << endl;
        };

        return check;
    };

    bool type_Total_Order(int** P)
    {
        bool check = false;
        if (prp_Asymmetry(P) && prp_Transitivity(P) && !prp_Reflexivity(P))
        {
            check = true;
            cout << "Relation type: Total order" << endl;
        };

        return check;
    };

    bool type_Linear(int** P)
    {
        bool check = false;
        if (prp_Antisymmetry(P) && prp_Reflexivity(P) && prp_Transitivity(P) && prp_Connection(P))
        {
            check = true;
            cout << "Relation type: Linear" << endl;
        };

        return check;
    };

    bool type_Total_Linear(int** P)
    {
        bool check = false;
        if (prp_Transitivity(P) && prp_Antireflexivity(P))
        {
            check = true;
            cout << "Relation type: Total Linear" << endl;
        };

        return check;
    };

    void Check_Type(int** P)
    {
    
        type_Tolerance(P);
        type_Equivalence(P);
        type_Quasiorder(P);
        type_Order(P);
        type_Total_Order(P);
        type_Linear(P);
        type_Total_Linear(P);

        if (!type_Tolerance(P) && !type_Equivalence(P) && !type_Quasiorder(P) && !type_Order(P) && !type_Total_Order(P) && !type_Linear(P) && !type_Total_Linear(P))
        {
            cout << endl << "Relation has no type." << endl << endl;
        };
    };

    int** TransitiveClosure(int** R)
    {
        int** result = new int* [SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            result[i] = new int[SIZE];
            for (int j = 0; j < SIZE; j++)
            {
                result[i][j] = R[i][j];
            }
        }

        for (int k = 0; k < SIZE; k++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    if (result[i][k] && result[k][j])
                    {
                        result[i][j] = 1;
                    }
                }
            }
        }

        return result;
    }

    vector<set<int>> FactorizeByEquivalence(int** P) {
        vector<set<int>> equivalenceClasses;

        vector<bool> visited(SIZE, false);
        for (int i = 0; i < SIZE; i++) {
            if (!visited[i]) {
                set<int> equivalenceClass;
                equivalenceClass.insert(i);
                for (int j = i + 1; j < SIZE; j++) {
                    if (P[i][j] == 1) {
                        equivalenceClass.insert(j);
                        visited[j] = true;
                    }
                }
                equivalenceClasses.push_back(equivalenceClass);
            }
        }

        return equivalenceClasses;
    }

    std::vector<int> searchMax(int** T) {
        std::vector<int> maximums;
        for (int i = 0; i < SIZE; i++) {
            bool isMaximum = true;
            for (int j = 0; j < SIZE; j++) {
                if (T[i][j] != 1) {
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

    std::vector<int> searchMin(int** T) {
        std::vector<int> minimums;
        for (int i = 0; i < SIZE; i++) {
            bool isMinimum = true;
            for (int j = 0; j < SIZE; j++) {
                if (T[j][i] != 1) {
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

    std::vector<int> searchMajr(int** T) {
        std::vector<int> majorants;
        for (int j = 0; j < SIZE; j++) {
            bool isMajorant = true;
            for (int i = 0; i < SIZE; i++) {
                if (T[i][j] != 0) {
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

    std::vector<int> searchMinr(int** T) {
        std::vector<int> minorants;
        for (int i = 0; i < SIZE; i++) {
            bool isMinorant = true;
            for (int j = 0; j < SIZE; j++) {
                if (T[i][j] != 0) {
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

    string Distance_Unmetr(int** S, int** T)
    {
        string distance = "";
        int** SM = new int* [SIZE],
            ** TM = new int* [SIZE];
        for (int i = 0; i < SIZE; i++) {
            SM[i] = new int[SIZE];
            TM[i] = new int[SIZE];
            for (int j = 0; j < SIZE; j++) {
                if (i != j) {
                    if ((i != 0) && (j != 0)) {
                        SM[i][j] = S[i][j] - S[j][i];
                        TM[i][j] = T[i][j] - T[j][i];
                    }
                    else {
                        SM[i][j] = 111;
                        TM[i][j] = 111;
                    }
                }
                else {
                    SM[i][j] = 111;
                    TM[i][j] = 111;
                }
            };
        };
        int k = 1, sum = 0;
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = i + 1; j < SIZE; ++j)
            {
                if ((SM[i][j] != 111) && (TM[i][j] != 111)) {
                    sum += fabs(SM[i][j] - TM[i][j]);
                }
                else {
                    k++;
                }
            }
        }
        distance.append(to_string(k));
        distance.append("w + ");
        distance.append(to_string(sum));
        return distance;
    };

    double Distance_Metr(int** P, int** Q)
    {
        double distance = 0;

        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = i + 1; j < SIZE; ++j)
            {
                distance += fabs(P[i][j] - Q[i][j]);
            }
        }

        return distance;
    };

};

int main() 
{
    auto start_time = std::chrono::high_resolution_clock::now();

    int P1[SIZE][SIZE] = { {1,1,0,1,1},{0,1,0,1,0},{0,0,1,1,0},{1,0,0,1,1},{1,0,0,1,1} },
        /*Q1[SIZE][SIZE] = { {0,0,0,0,0},{1,0,1,0,0},{1,0,0,0,0},{1,1,1,0,0},{1,1,1,1,0} },*/
        Q1[SIZE][SIZE] = { {1,1,1,1,1},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{0,0,0,0,0} },
        R1[SIZE][SIZE] = { {1,0,0,0,1},{0,1,0,1,1},{1,0,0,1,1},{0,0,0,0,0},{0,0,0,0,0} },
        S1[SIZE][SIZE] = { {0,-1,1,-2,0},{1,0,2,-1,1},{-1,-2,0,-3,-1},{2,1,3,0,2},{0,-1,1,-2,0} },
        E1[SIZE][SIZE] = { {1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1} },
        T1[SIZE][SIZE] = { {0,-2,-2,1,-2},{2,0,0,3,0},{2,0,0,3,0},{-1,-3,-3,0,-3},{2,0,0,3,0} };

    int** P = new int* [SIZE],
        ** Q = new int* [SIZE],
        ** R = new int* [SIZE],
        ** S = new int* [SIZE],
        ** E = new int* [SIZE],
        ** T = new int* [SIZE];


    Relation obj;
    P = obj.Convert(P1);
    Q = obj.Convert(Q1);
    R = obj.Convert(R1);
    S = obj.Convert(S1);
    T = obj.Convert(T1);
    E = obj.Convert(E1);
    
    cout << "--------------------TASK 1-------------------------" << endl << endl;
    cout << "Composition of Q and R:" << endl;
    obj.Printing(obj.Composition(Q, R));
    cout << endl << "Symmetrical difference of Q and R:" << endl;
    obj.Printing(obj.SymDiff(Q, R));
    cout << endl;

    cout << "--------------------TASK 2-------------------------" << endl << endl;
    cout << endl << "Properties:" << endl << endl;
    obj.Check_prp(Q);
    cout << endl << "Relation type:" << endl << endl;
    obj.Check_Type(Q);
    cout << endl;

    cout << "--------------------TASK 3-------------------------" << endl << endl;
    cout << "Transitivity check for R:" << endl;
    if (not obj.prp_Transitivity(R))
    {
        cout << "It's not transitive, performing transitive closure." << endl;
        cout << "Transitive Closure:" << endl;
        obj.Printing(obj.TransitiveClosure(R));
        cout << "Mutual reach:" << endl;
        obj.Printing(obj.Union(obj.Intersection(E, obj.TransitiveClosure(R)), obj.Converce(obj.Intersection(E, obj.TransitiveClosure(R)))));
    };
    cout << "Transitive Closure:" << endl;
    obj.Printing(R);
    cout << "Mutual reach:" << endl;
    obj.Printing(obj.Union(obj.Intersection(E, R), obj.Converce(obj.Intersection(E, R))));

    cout << "--------------------TASK 4-------------------------" << endl << endl;
    cout << "Relation of equivalence:" << endl;
    obj.Printing(obj.Union(P, obj.Converce(P)));
    cout << "Relation of dominance:" << endl;
    obj.Printing(obj.Difference(P, obj.Union(P, obj.Converce(P))));
    cout << "Relation of incomparability:" << endl;
    obj.Printing(obj.Addition(obj.Intersection(P, obj.Converce(P))));

    cout << "--------------------TASK 5-------------------------" << endl << endl;
    cout << endl << "Factorization:" << endl << endl;
    vector<set<int>> equivalenceClasses = obj.FactorizeByEquivalence(P);
    for (size_t i = 0; i < equivalenceClasses.size(); i++) {
        cout << "Equivalence Class " << (i + 1) << ": { ";
        for (int element : equivalenceClasses[i]) {
            cout << element << " ";
        }
        cout << "}" << endl;
    }

    cout << "--------------------TASK 6-------------------------" << endl << endl;
    cout << "Maximum:";
    for (int element : obj.searchMax(R)) {
        cout << element << " ";
    }
    cout << endl;
    cout << "Minimum:";
    for (int element : obj.searchMin(R)) {
        cout << element << " ";
    }

    cout << endl;
    cout << "Majorant:";
    for (int element : obj.searchMajr(R)) {
        cout << element << " ";
    }
    cout << endl;
    cout << "Minorant:";
    for (int element : obj.searchMinr(R)) {
        cout << element << " ";
    }
    cout << endl;

    cout << "--------------------TASK 7-------------------------" << endl << endl;
    cout << "Distance between Q and R:" << endl;
    cout << obj.Distance_Unmetr(Q, R) << endl;

    cout << "--------------------TASK 8-------------------------" << endl << endl;
    cout << "Distance between S and T:" << endl;
    cout << obj.Distance_Metr(S, T) << endl;

    for (int i = 0; i < SIZE; i++) {
        //delete[] res[i];
        delete[] P[i];
        delete[] Q[i];
        delete[] R[i];
        delete[] S[i];
        delete[] T[i];
        delete[] E[i];
    };
    //delete[] res; 
    delete[] P; delete[] Q; delete[] R; delete[] S; delete[] T; delete[] E;

    cout << endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    cout << "Execution Time: " << duration.count() << " milliseconds" << std::endl;

    return 0;
};
