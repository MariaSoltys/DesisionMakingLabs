#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int SIZE = 5;

class Relation
{
public:
    int size = SIZE;

    Relation() {};

    int** FillIn(int** P, int** Q, int** R)
        {
        int a;
        cout << "Relation compilator" << endl;
        cout << "Do you want to generate relation?" << endl
            << "0 - No, stay with custom" << endl
            << "1 - Empty" << endl
            << "2 - Full" << endl
            << "3 - Diagonal" << endl
            << "4 - Antidiagonal" << endl << endl;
        cin >> a;
        if (a == 1) {
            for (int i = 0; i < SIZE; i++) { for (int j = 0; j < SIZE; j++) { P[i][j] = 0; }; };
        };
        if (a == 2) {
            for (int i = 0; i < SIZE; i++) { for (int j = 0; j < SIZE; j++) { P[i][j] = 1; }; };
        };
        if (a == 3) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (i == j) {
                        P[i][j] = 1;
                    }
                    else {
                        P[i][j] = 0;
                    };
                };
            };
        };
        if (a == 4) {
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    if (i == j) {
                        P[i][j] = 0;
                    }
                    else {
                        P[i][j] = 1;
                    };
                };
            };
        };

        return P;
    }

    virtual int** Union(int** P, int** Q)
    {
        return 0;
    };

    virtual int** Intersection(int** P, int** Q)
    {
        return 0;
    };

    virtual int** Difference(int** P, int** Q)
    {
        return 0;
    };

    virtual int** SymDiff(int** P, int** Q)
    {
        return 0;
    };

    virtual int** Complement(int** P)
    {
        return 0;
    };

    virtual int** Converce(int** P)
    {
        return 0;
    };

    virtual int** Composition(int** P, int** Q)
    {
        return 0;
    };

    virtual int** Dual(int** P)
    {
        return 0;
    };

    virtual void CallAll(int** P, int** Q)
    {

    };

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
    // ######################################## Lab 02 functions ################################################
    // Relation properties check

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

        cout << "Antieflexivity: ";
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
                if ((P[i][j] == P[j][i]) || (P[i][i] == 1)) {
                    check = false;
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

    //Additional function
    bool isAcyclic(int** R, std::vector<bool>& visited, int vertex, int parent) {
        visited[vertex] = true;

        for (int i = 0; i < SIZE; i++) {
            if (R[vertex][i] == 1) {
                if (!visited[i]) {
                    if (isAcyclic(R, visited, i, vertex)) {
                        return true;
                    }
                }
                else if (i != parent) {
                    return true;
                }
            }
        }

        return false;
    }

    bool prp_Acyclicity(int** P)
    {
        std::vector<bool> visited(SIZE, false);
        bool check = true;

        for (int i = 0; i < SIZE; i++) {
            if (!visited[i]) {
                if (isAcyclic(P, visited, i, -1)) {
                    check = false;
                }
            }
        }

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
                if ((P[i][j] == P[j][i]) && (P[i][j] == 0)) {
                    check = false;
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
        /*
        type_Tolerance(P);
        type_Equivalence(P);
        type_Quasiorder(P);
        type_Order(P);
        type_Total_Order(P);
        type_Linear(P);
        type_Total_Linear(P);*/

        if (!type_Tolerance(P) && !type_Equivalence(P) && !type_Quasiorder(P) && !type_Order(P) && !type_Total_Order(P) && !type_Linear(P) && !type_Total_Linear(P))
        {
            cout << endl << "Relation has no type." << endl << endl;
        };
    };
    //####################################### Task 4 ############################################
    int** SymmetricComponent(int** R)
    {
        int** result = new int* [SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            result[i] = new int[SIZE];
            for (int j = 0; j < SIZE; j++)
            {
                result[i][j] = (R[i][j] && R[j][i]) ? 1 : 0;
            }
        }
        return result;
    }

    int** AsymmetricComponent(int** R)
    {
        int** result = new int* [SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            result[i] = new int[SIZE];
            for (int j = 0; j < SIZE; j++)
            {
                result[i][j] = (R[i][j] && !R[j][i]) ? 1 : 0;
            }
        }
        return result;
    }

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

    bool IsReachable(int startVertex, int endVertex, int** R)
    {
        if (startVertex < 0 || startVertex >= SIZE || endVertex < 0 || endVertex >= SIZE)
        {
            return false;
        }
        return R[startVertex][endVertex];
    }

    bool IsMutuallyReachable(int vertex1, int vertex2, int** R)
    {
        return IsReachable(vertex1, vertex2, R) && IsReachable(vertex2, vertex1, R);
    }

    // ############################### Task 5 ########################################

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

    ~Relation() {}

};

/// /////////////////////////////////////////////////////////////////////////////

class Relation_Matrix :public Relation
{
public:

    Relation_Matrix()
    {

    };

    int** Union(int** P, int** Q) override
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

    int** Intersection(int** P, int** Q) override
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

    int** Difference(int** P, int** Q) override
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

    int** SymDiff(int** P, int** Q) override
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

    int** Complement(int** P) override
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

    int** Converce(int** P) override
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

    int** Composition(int** P, int** Q) override
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

    int** Dual(int** P) override
    {
        int** result = new int* [SIZE],
            ** result1 = Converce(P);

        for (int i = 0; i < SIZE; i++) {
            result[i] = new int[SIZE];
            for (int j = 0; j < SIZE; j++) {
                if (result1[i][j] == 0) {
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

        return result;
    };

    void CallAll(int** P, int** Q) override
    {
        cout << "Union: " << endl;
        Printing(Union(P, Q));

        cout << "Intersection: " << endl;
        Printing(Intersection(P, Q));

        cout << "Difference: " << endl;
        Printing(Difference(P, Q));

        cout << "Symmetrical Difference: " << endl;
        Printing(SymDiff(P, Q));

        cout << "Complement: " << endl;
        Printing(Complement(P));

        cout << "Converce: " << endl;
        Printing(Converce(P));

        cout << "Composition: " << endl;
        Printing(Composition(P, Q));

        cout << "Dual: " << endl;
        Printing(Dual(P));
    };

    void Check(int** P, int** Q)
    {
        bool check = true;
        int a;
        cout << "Cheking relations..." << endl << endl;

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (P[i][j] != Q[i][j]) {
                    check = false;
                };
            };
        };

        if (check) {
            cout << "Error! Relations are the same!" << endl;
            cin >> a;
        };
    };

    ~Relation_Matrix()
    {

    };

};

/// //////////////////////////////////////////////////////////////////////////////////////////

class Relation_Cut : public Relation
{
public:
    Relation_Cut()
    {

    };

    int** To_Cut(int** P)
    {
        Relation_Matrix a;
        int** result = new int* [SIZE];
        int** CP = a.Converce(P);

        for (int i = 0; i < SIZE; i++)
        {
            result[i] = new int[SIZE];
            for (int j = 0; j < SIZE; j++)
            {
                if (CP[i][j] == 1)
                {
                    result[i][j] = j + 1;
                }
                else
                {
                    result[i][j] = 0;
                }
            };
        };
        for (int i = 0; i < SIZE; i++) {
            delete[] CP[i];
        }
        delete[] CP;
        return result;
    };

    int** Print_Cut(int** P)
    {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ". {";
            for (int j = 0; j < SIZE; j++) {
                if (P[i][j] != 0)
                {
                    cout << P[i][j] << ' ';
                }
            };
            cout << "}" << endl;
        };
        cout << endl;
        return 0;
    };

    int** Union(int** P, int** Q) override
    {
        Relation_Matrix a;
        int** CP = a.Union(P, Q);
        int** result = To_Cut(CP);

        for (int i = 0; i < SIZE; i++) {
            delete[] CP[i];
        }
        delete[] CP;

        return result;

        return result;
    };

    int** Intersection(int** P, int** Q) override
    {
        Relation_Matrix a;
        int** CP = a.Intersection(P, Q);
        int** result = To_Cut(CP);

        for (int i = 0; i < SIZE; i++) {
            delete[] CP[i];
        }
        delete[] CP;

        return result;
    };

    int** Difference(int** P, int** Q) override
    {
        Relation_Matrix a;
        int** CP = a.Difference(P, Q);
        int** result = To_Cut(CP);

        for (int i = 0; i < SIZE; i++) {
            delete[] CP[i];
        }
        delete[] CP;

        return result;
    };

    int** SymDiff(int** P, int** Q) override
    {
        Relation_Matrix a;
        int** CP = a.SymDiff(P, Q);
        int** result = To_Cut(CP);

        for (int i = 0; i < SIZE; i++) {
            delete[] CP[i];
        }
        delete[] CP;

        return result;
    };

    int** Complement(int** P) override
    {
        Relation_Matrix a;
        int** CP = a.Complement(P);
        int** result = To_Cut(CP);

        for (int i = 0; i < SIZE; i++) {
            delete[] CP[i];
        }
        delete[] CP;

        return result;
    };

    int** Converce(int** P) override
    {
        Relation_Matrix a;
        int** CP = a.Converce(P);
        int** result = To_Cut(CP);

        for (int i = 0; i < SIZE; i++) {
            delete[] CP[i];
        }
        delete[] CP;

        return result;
    };

    int** Composition(int** P, int** Q) override
    {
        Relation_Matrix a;
        int** CP = a.Composition(P, Q);
        int** result = To_Cut(CP);

        for (int i = 0; i < SIZE; i++) {
            delete[] CP[i];
        }
        delete[] CP;

        return result;
    };

    int** Dual(int** P) override
    {
        Relation_Matrix a;
        int** CP = a.Dual(P);
        int** result = To_Cut(CP);

        for (int i = 0; i < SIZE; i++) {
            delete[] CP[i];
        }
        delete[] CP;

        return result;
    };

    void CallAll(int** P, int** Q) override
    {
        cout << "Union: " << endl;
        Print_Cut(Union(P, Q));

        cout << "Intersection: " << endl;
        Print_Cut(Intersection(P, Q));

        cout << "Difference: " << endl;
        Print_Cut(Difference(P, Q));

        cout << "Symmetrical Difference: " << endl;
        Print_Cut(SymDiff(P, Q));

        cout << "Complement: " << endl;
        Print_Cut(Complement(P));

        cout << "Converce: " << endl;
        Print_Cut(Converce(P));

        cout << "Composition: " << endl;
        Print_Cut(Composition(P, Q));

        cout << "Dual: " << endl;
        Print_Cut(Dual(P));
    };

    ~Relation_Cut()
    {

    };
};

int main()
{
    int P1[SIZE][SIZE] = { {1,0,0,0,0},{1,1,0,1,1},{0,0,0,0,0},{0,0,0,0,0},{0,1,1,0,1} },
        Q1[SIZE][SIZE] = { {0,0,0,0,0},{0,1,0,1,0},{0,0,0,0,0},{1,1,0,0,0},{0,0,0,0,0} },
        R1[SIZE][SIZE] = { {0,1,1,0,0},{0,0,1,0,1},{0,1,0,0,0},{1,1,1,1,1},{1,0,1,1,0} };

    int ** P = new int* [SIZE],
        ** Q = new int* [SIZE],
        ** R = new int* [SIZE];
    //int** res = new int* [SIZE];
    //Matrix
    Relation_Matrix arr;

    //Convert int[][] to int**
    P = arr.Convert(P1);
    Q = arr.Convert(Q1);
    R = arr.Convert(R1);

    /*
    arr.Check(P, Q);
    arr.CallAll(P, Q);
    
    res = arr.Difference(arr.Composition(P, Q), arr.Dual(R));

    cout << "Expession result (Matrix):" << endl;
    arr.Printing(res);

    //Cut
    Relation_Cut cut;

    cout << "Cut representation:" << endl;
    cut.CallAll(P, Q);
    cout << "Expession result (Cut):" << endl;
    cut.Print_Cut(cut.To_Cut(res));
    */

    //Deleting arrays

    cout << "Lab 02: relation Q" << endl << endl;
    Relation obj;
    cout << endl << "Properties:" << endl << endl;
    obj.Check_prp(Q);
    cout << endl << "Relation type:" << endl << endl;
    obj.Check_Type(Q);

    if (not obj.prp_Transitivity(Q))
    {
        cout << "Transitive Closure:" << endl;
        obj.Printing(obj.TransitiveClosure(Q));
        cout << endl << "New type:" << endl;
        obj.Check_Type(obj.TransitiveClosure(Q));
    };

    cout << endl << "Factorization:" << endl << endl;
    vector<set<int>> equivalenceClasses = obj.FactorizeByEquivalence(P);
    for (size_t i = 0; i < equivalenceClasses.size(); i++) {
        cout << "Equivalence Class " << (i + 1) << ": { ";
        for (int element : equivalenceClasses[i]) {
            cout << element << " ";
        }
        cout << "}" << endl;
    }

    for (int i = 0; i < SIZE; i++) {
        //delete[] res[i];
        delete[] P[i];
        delete[] Q[i];
        delete[] R[i];
    };
    //delete[] res; 
    delete[] P; delete[] Q; delete[] R;

    return 0;
}