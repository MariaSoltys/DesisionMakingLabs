#include <conio.h>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <string>
#include <cstring>
#include <windows.h>
#include <cmath>
using namespace std;
class Relation {
	size_t size_of_relation;
	bool** relation;
public:
	
	Relation() {}
	Relation(size_t) {}
	Relation(const Relation&) {}
	
	virtual void SetRelation() const = 0;
	virtual void Show() const = 0;

	~Relation() {}
	virtual void Matrix() const = 0;
};
class GroupRelation : public Relation {
	size_t size_of_relation;
	int** relation;
	int** P1; int** P2; int** P3; int** P4; int** P5;
public:
	GroupRelation() {
		size_of_relation = 5;
		relation = new int* [size_of_relation];
		P1 = new int* [size_of_relation];
		P2 = new int* [size_of_relation];
		P3 = new int* [size_of_relation];
		P4 = new int* [size_of_relation];
		P5 = new int* [size_of_relation];
		for (size_t i(0); i < size_of_relation; ++i) {
			relation[i] = new int[size_of_relation];
			P1[i] = new int[size_of_relation];
			P2[i] = new int[size_of_relation];
			P3[i] = new int[size_of_relation];
			P4[i] = new int[size_of_relation];
			P5[i] = new int[size_of_relation];
		}
	};
	GroupRelation(size_t size) {
		this->size_of_relation = size;
		relation = new int* [size_of_relation];
		P1 = new int* [size_of_relation];
		P2 = new int* [size_of_relation];
		P3 = new int* [size_of_relation];
		P4 = new int* [size_of_relation];
		P5 = new int* [size_of_relation];
		for (size_t i(0); i < size_of_relation; ++i) {
			relation[i] = new int[size_of_relation];
			P1[i] = new int[size_of_relation];
			P2[i] = new int[size_of_relation];
			P3[i] = new int[size_of_relation];
			P4[i] = new int[size_of_relation];
			P5[i] = new int[size_of_relation];
		}
	}
	GroupRelation(const GroupRelation& r) {
		this->size_of_relation = r.size_of_relation;
		relation = new int* [size_of_relation];
		P1 = new int* [size_of_relation];
		P2 = new int* [size_of_relation];
		P3 = new int* [size_of_relation];
		P4 = new int* [size_of_relation];
		P5 = new int* [size_of_relation];
		for (size_t i(0); i < size_of_relation; ++i) {
			relation[i] = new int[size_of_relation];
			P1[i] = new int[size_of_relation];
			P2[i] = new int[size_of_relation];
			P3[i] = new int[size_of_relation];
			P4[i] = new int[size_of_relation];
			P5[i] = new int[size_of_relation];
		}
		for (size_t i(0); i < size_of_relation; ++i)
			for (size_t j(0); j < size_of_relation; ++j) {
				relation[i][j] = r.relation[i][j];
				P1[i][j] = r.P1[i][j];
				P2[i][j] = r.P2[i][j];
				P3[i][j] = r.P3[i][j];
				P4[i][j] = r.P4[i][j];
				P5[i][j] = r.P5[i][j];
			}
	}
	virtual void SetRelation() const {
		for (int k = 0; k < 5; k++) {
			cout << "\n\tP" << k + 1 << ":\n";
			for (size_t i(0); i < size_of_relation; ++i) {
				for (size_t j(0); j < size_of_relation; ++j) {
					char sym = _getche(); cout << " ";
					if (k == 0) P1[i][j] = (int)sym - 48;
					if (k == 1) P2[i][j] = (int)sym - 48;
					if (k == 2) P3[i][j] = (int)sym - 48;
					if (k == 3) P4[i][j] = (int)sym - 48;
					if (k == 4) P5[i][j] = (int)sym - 48;
				}
				cout << endl;
			}
		}
		for (size_t i(0); i < size_of_relation; ++i)
			for (size_t j(0); j < size_of_relation; ++j)
				relation[i][j] = 0;
	}
	virtual void Show() const {
		cout << "    E1  E2  E3  E4  E5\n";
		for (size_t i(0); i < size_of_relation; ++i) {
			cout << i + 1 << "| ";
			for (size_t j(0); j < size_of_relation; ++j)
				cout << setw(3) << relation[i][j] << " ";
			cout << endl;
		}
	}
	~GroupRelation() {
		for (size_t i(0); i < size_of_relation; ++i) {
			delete[] relation[i];
			delete[] P1[i];
			delete[] P2[i];
			delete[] P3[i];
			delete[] P4[i];
			delete[] P5[i];
		}
		delete[] relation;
		delete[] P1;
		delete[] P2;
		delete[] P3;
		delete[] P4;
		delete[] P5;
	}
	virtual void  Matrix() const {
		for (size_t i(0); i < size_of_relation; i++)
			for (size_t j(0); j < size_of_relation; j++) {
				relation[i][0] += P1[i][j];
				relation[i][1] += P2[i][j];
				relation[i][2] += P3[i][j];
				relation[i][3] += P4[i][j];
				relation[i][4] += P5[i][j];
			}
	}
	friend void Voting(GroupRelation& T) {
		cout << "\tVoting\n";
		int V[5] = { 0,0,0,0,0 }; int place = 1;
		for (size_t i(0); i < T.size_of_relation; i++)
			for (size_t j(0); j < T.size_of_relation; j++)
				if (T.relation[i][j] == 4) V[i] += 1;
		int max = V[0];
		while (max != 0) {
			max = V[0];
			for (size_t i(0); i < T.size_of_relation; i++)
				if (max < V[i]) max = V[i];
			cout << "Place " << place << ": ";
			for (size_t i(0); i < T.size_of_relation; i++)
				if (max == V[i]) { cout << i + 1 << " "; V[i] = -1; }
			cout << "(votes " << max << ").\n"; place++;
			if ((V[0] + V[1] + V[2] + V[3] + V[4]) == -5) break;
		}
	}
	friend void Kondors(GroupRelation& T) {
		int V[5] = { 0,0,0,0,0 }; int max = T.size_of_relation;
		cout << "\n\t Kondors\nParreto matrix S:\n";
		int S[5][5];
		for (size_t i(0); i < T.size_of_relation; i++) {
			for (size_t j(0); j < T.size_of_relation; j++) {
				S[i][j] = 0;
				for (size_t k(0); k < T.size_of_relation; k++)
					if (T.relation[i][k] > T.relation[j][k]) S[i][j]++;
				cout << S[i][j] << " ";
				if (i != j)
					if (T.size_of_relation - S[i][j] > (T.size_of_relation / 2)) S[i][j] = 0;
					else S[i][j] = 1;
			}
			cout << endl;
		}
		cout << "Matrix of the resulting relation B:\n";
		for (size_t i(0); i < T.size_of_relation; i++) {
			for (size_t j(0); j < T.size_of_relation; j++) {
				cout << S[i][j] << " "; V[i] += S[i][j];
			}
			cout << endl;
		}
		for (size_t i(0); i < T.size_of_relation; i++) {
			max -= 1;
			cout << "Place " << i + 1 << ": ";
			for (size_t j(0); j < T.size_of_relation; j++)
				if (V[j] == max) cout << j + 1 << " ";
			cout << endl;
		}
	}
	friend void Bord(GroupRelation& T) {
		cout << "\tBord\n";
		int V[5] = { 0,0,0,0,0 }; int place = 1; int stop = 0;
		for (size_t i(0); i < T.size_of_relation; i++)
			for (size_t j(0); j < T.size_of_relation; j++)
				V[i] += T.relation[i][j];
		while (stop != T.size_of_relation) {
			int max = V[0];
			for (size_t i(0); i < T.size_of_relation; i++)
				if (max < V[i]) max = V[i];
			cout << "Place " << place << ": ";
			for (size_t i(0); i < T.size_of_relation; i++)
				if (max == V[i]) { cout << i + 1 << " "; V[i] = -1; stop++; }
			cout << "(votes " << max << ").\n"; place++;
		}
	}
	friend void Median_Kemeni(GroupRelation& T) {
		cout << "\tCounting Kemeni median\n";
		int V[5] = { 0,0,0,0,0 }; int CV[5] = { 0,0,0,0,0 }; int min;
		bool BV[5] = { false,false,false,false,false }; int d = 0;
		for (size_t i(0); i < T.size_of_relation; i++)
			for (size_t j(i); j < T.size_of_relation; j++) {
				if (T.P1[i][j] == T.P1[j][i]) T.P1[i][j] = T.P1[j][i] = 0;
				else
					if (T.P1[i][j] > T.P1[j][i]) { T.P1[i][j] = 1; T.P1[j][i] = -1; }
					else { T.P1[i][j] = -1; T.P1[j][i] = 1; }

				if (T.P2[i][j] == T.P2[j][i]) T.P2[i][j] = T.P2[j][i] = 0;
				else
					if (T.P2[i][j] > T.P2[j][i]) { T.P2[i][j] = 1; T.P2[j][i] = -1; }
					else { T.P2[i][j] = -1; T.P2[j][i] = 1; }

				if (T.P3[i][j] == T.P3[j][i]) T.P3[i][j] = T.P3[j][i] = 0;
				else
					if (T.P3[i][j] > T.P3[j][i]) { T.P3[i][j] = 1; T.P3[j][i] = -1; }
					else { T.P3[i][j] = -1; T.P3[j][i] = 1; }

				if (T.P4[i][j] == T.P4[j][i]) T.P4[i][j] = T.P4[j][i] = 0;
				else
					if (T.P4[i][j] > T.P4[j][i]) { T.P4[i][j] = 1; T.P4[j][i] = -1; }
					else { T.P4[i][j] = -1; T.P4[j][i] = 1; }

				if (T.P5[i][j] == T.P5[j][i]) T.P5[i][j] = T.P5[j][i] = 0;
				else
					if (T.P5[i][j] > T.P5[j][i]) { T.P5[i][j] = 1; T.P5[j][i] = -1; }
					else { T.P5[i][j] = -1; T.P5[j][i] = 1; }
			}
		cout << "Matrix of relation in metric representation\n";
		for (size_t v(0); v < T.size_of_relation; v++) {
			cout << "\tM(P" << v + 1 << ")\n";
			for (size_t i(0); i < T.size_of_relation; i++) {
				for (size_t j(0); j < T.size_of_relation; j++) {
					if (v == 0) cout << setw(3) << T.P1[i][j] << " ";
					if (v == 1) cout << setw(3) << T.P2[i][j] << " ";
					if (v == 2) cout << setw(3) << T.P3[i][j] << " ";
					if (v == 3) cout << setw(3) << T.P4[i][j] << " ";
					if (v == 4) cout << setw(3) << T.P5[i][j] << " ";
				}
				cout << endl;
			}
		}
		cout << "\nCost matrix R:\n";
		for (size_t i(0); i < T.size_of_relation; i++) {
			for (size_t j(0); j < T.size_of_relation; j++) {
				T.relation[i][j] = 0;
				if (i != j) T.relation[i][j] = (1 - T.P1[i][j]) + (1 - T.P2[i][j]) + (1 - T.P3[i][j]) + (1 - T.P4[i][j]) + (1 - T.P5[i][j]);
				cout << setw(3) << T.relation[i][j] << " ";
			}
			cout << endl;
		}
		cout << "Received ranking:";
		for (size_t k(0); k < T.size_of_relation; k++) {
			for (size_t i(0); i < T.size_of_relation; i++) {
				V[i] = 0;
				for (size_t j(0); j < T.size_of_relation; j++) {
					if (BV[i] == false && BV[j] == false) V[i] += T.relation[i][j];
					if (BV[i] == true) V[i] = 100;
				}
			}
			min = V[0];
			for (size_t i(0); i < T.size_of_relation; i++)
				if (min > V[i]) min = V[i];
			for (size_t i(0); i < T.size_of_relation; i++)
				if (min == V[i]) { d += min; BV[i] = true; CV[k] = i; break; }
		}
		cout << CV[0] + 1 << " " << CV[1] + 1 << " " << CV[2] + 1 << " " << CV[3] + 1 << " " << CV[4] + 1;
		cout << "\nCondition of optimality of ranking:";
		for (size_t i(0); i < T.size_of_relation - 1; i++)
			if (T.relation[CV[i]][CV[i + 1]] >= T.relation[CV[i + 1]][CV[i]]) {
				min = CV[i];
				CV[i] = CV[i + 1];
				CV[i] = min;
			}
		cout << CV[0] + 1 << " " << CV[1] + 1 << " " << CV[2] + 1 << " " << CV[3] + 1 << " " << CV[4] + 1;
		cout << "\nD: " << d;
	}
};
void main() {
	GroupRelation P;	P.SetRelation();
	P.Matrix(); P.Show();
	Voting(P);
	Kondors(P);
	Bord(P);
	Median_Kemeni(P);
	_getch();
}