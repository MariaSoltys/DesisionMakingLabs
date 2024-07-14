#include <iostream>
#include <iomanip>

const int N = 5;

void Bay_Lapl(int price[N][N], float p[N]) {
    float res[N];
    for (int i = 0; i < N; i++) {
        float sum = 0;
        for (int j = 0; j < N; j++) {
            float k = static_cast<float>(price[i][j]) * p[j];
            sum = sum + k;
        }
        res[i] = sum;
    }
    float max = res[0];
    int l = 0;
    for (int i = 0; i < N; i++) {
        if (res[i] > max) {
            max = res[i];
            l = i;
        }
    }
    std::cout << "\n---Bayes-Laplace Method---\nResult= " << max << "   Strategy " << l + 1 << "\n";
}

void Valda(int price[N][N]) {
    int min_row[N];
    for (int i = 0; i < N; i++) {
        int min = price[i][0];
        for (int j = 0; j < N; j++) {
            if (price[i][j] < min) {
                min = price[i][j];
            }
        }
        min_row[i] = min;
    }
    int max = min_row[0];
    int l = 0;
    for (int i = 0; i < N; i++) {
        if (min_row[i] > max) {
            max = min_row[i];
            l = i;
        }
    }
    std::cout << "\n---Valda Method---\nResult = " << max << "   Strategy " << l + 1 << "\n";
}

void Sedvigzh(int risk[N][N]) {
    int max_row[N];
    for (int i = 0; i < N; i++) {
        int max = risk[i][0];
        for (int j = 0; j < N; j++) {
            if (risk[i][j] > max) {
                max = risk[i][j];
            }
        }
        max_row[i] = max;
    }
    int min = max_row[0];
    int l = 0;
    for (int i = 0; i < N; i++) {
        if (max_row[i] < min) {
            min = max_row[i];
            l = i;
        }
    }
    std::cout << "\n---Savage Method---\nResult = " << min << "   Strategy " << l + 1 << "\n";
}

void Gurvits(int price[N][N], float a) {
    int min_row[N];
    int max_row[N];
    int res[N];
    for (int i = 0; i < N; i++) {
        int min = price[i][0];
        for (int j = 0; j < N; j++) {
            if (price[i][j] < min) {
                min = price[i][j];
            }
        }
        min_row[i] = min;
    }
    for (int i = 0; i < N; i++) {
        int max = price[i][0];
        for (int j = 0; j < N; j++) {
            if (price[i][j] > max) {
                max = price[i][j];
            }
        }
        max_row[i] = max;
    }
    for (int i = 0; i < N; i++) {
        res[i] = static_cast<int>(a * static_cast<float>(min_row[i]) + (1 - a) * static_cast<float>(max_row[i]));
    }
    int max = res[0];
    int l = 0;
    for (int i = 0; i < N; i++) {
        if (res[i] > max) {
            max = res[i];
            l = i;
        }
    }
    std::cout << "\n---Gurwitz Method---\nwhen x = " << a << "\nResult = " << max << "   Strategy " << l + 1 << "\n";
}

int main() {
    int price_m[N][N] = {
        {13915, 13915, 13915, 13915, 13915},
        {11385, 16445, 16445, 16445, 16445},
        {8855, 13915, 18975, 18975, 18975},
        {6325, 11385, 16445, 21505, 21505},
        {3795, 8855, 13915, 18975, 24035},
    };

    float p[N] = { 0.1, 0.1, 0.3, 0.3, 0.2 };

    int price_m2[N][N] = {
        {480, 320, 60, -100, -260},
        {800, 590, 230, 20, -190},
        {1200, 940, 480, 220, -40},
        {1600, 1290, 730, 420, 110},
        {1880, 1520, 860, 500, 140},
    };

    float p2[N] = { 0.4, 0.2, 0.2, 0.1, 0.1 };

    int max_row[N];
    for (int i = 0; i < N; i++) {
        int max = price_m[0][i];
        for (int j = 0; j < N; j++) {
            if (price_m[j][i] > max) {
                max = price_m[j][i];
            }
        }
        max_row[i] = max;
    }

    int risk_m[N][N];
    std::cout << "\n----Task 1----\n";
    std::cout << "Payment matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << std::setw(5) << price_m[i][j] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\nRisk matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            risk_m[j][i] = max_row[i] - price_m[j][i];
            std::cout << std::setw(5) << risk_m[j][i] << " ";
        }
        std::cout << "\n";
    }
    Bay_Lapl(price_m, p);
    std::cout << "\n";
    Valda(price_m);
    std::cout << "\n";
    Sedvigzh(risk_m);
    std::cout << "\n";
    float a[N] = { 0, 0.2, 0.4, 0.6, 0.8 };
    for (int i = 0; i < N; i++) {
        Gurvits(price_m, a[i]);
        std::cout << "\n";
    }
    std::cout << "\n";
    std::cout << "----Task 2----\n";
    std::cout << "Payment matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << std::setw(5) << price_m2[i][j] << " ";
        }
        std::cout << "\n";
    }
    int risk_m2[N][N];
    std::cout << "\nRisk matrix:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            risk_m2[j][i] = max_row[i] - price_m2[j][i];
            std::cout << std::setw(5) << risk_m2[j][i] << " ";
        }
        std::cout << "\n";
    }
    Bay_Lapl(price_m2, p2);
    std::cout << "\n";
    Valda(price_m2);
    std::cout << "\n";
    Sedvigzh(risk_m2);
    std::cout << "\n";
    float a2[N] = { 0, 0.2, 0.4, 0.5, 0.6 };
    for (int i = 0; i < N; i++) {
        Gurvits(price_m2, a2[i]);
        std::cout << "\n";
    }
    std::cout << "\n";
    return 0;
}
