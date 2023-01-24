/*
Составить программу на языке Си с процедурами решения трансцендентных алгебраических уравнений различными численными методами 
(Итераций, Ньютона и половинного деления – дихтомии).
*/
#include <stdio.h>
#include <math.h>
double eps = 0.00001;
// 0.4+arctg(sqrt(x))-x=0
double f1(double x) {
    return 0.4+atan(sqrt(x))-x;
}
double f1d(double x) {
    return -1 + 1 / (2 * sqrt(x) * (x + 1));
}
double f1f(double x) {
    return 0.4 + atan(sqrt(x));
}

// tg(x/2) - ctg(x/2) + x = 0
double f2(double x) {
    return tan(x/2) - cos(x/2)/sin(x/2) + x;
}
double f2d(double x) {
    return 1/(2 * cos(x/2)*cos(x/2))+ 1/(2 * sin(x/2)*sin(x/2)) + 1;
}
double f2f(double x) {
    return 2 * atan(1 / (tan(x / 2) + x));
}

double dihotomia(double f(double x), double a, double b) {
    double c;
    while (fabs(a - b) > eps) {
        c = (a + b) / 2;
        if (f(a) * f(c) > 0) {
            a = c;
        } else {
            b = c;
    }
}
return c;

}
double iteration(double f(double x), double a, double b) {
    double x = (a+b)/2;
    double x1, n=0;
    do {
        x1 = x;
        x = f(x);
        n++;
    } while(fabs(x-x1) > eps && n<100);
    return x;
}
double newton(double f(double x), double fd(double y), double a,
double b) {
    double x = (a + b) / 2;
    double x1 = x - (f(x) / fd(x));
    while (fabs(x1 - x) > eps) {
        x = x1;
        x1 = x - (f(x) / fd(x));
    }
    return x;
}

int main() {
    double n1, n2, n3, m1, m2, m3;
    n1 = newton(f1, f1d, 1, 2);
    n2 = iteration(f1f, 1, 2);
    n3 = dihotomia(f1, 1, 2);
    m1 = newton(f2, f2d, 1, 2);
    m2 = iteration(f2f, 1, 2);
    m3 = dihotomia(f2, 1, 2);
    printf("Точность: %.5f\n", eps);
    printf(" ________________________________________________________________________________________\n");
    printf("| Уравнение                  | Отрезок |Прибл.корень| Ньютона   | Итераций   | Дихотомии |\n");
    printf("|____________________________|_________|____________|___________|____________|___________|\n");
    printf("|0.4 + arctg(sqrt(x)) - x = 0| [1:2]   | 1.2388     | %.4f      | %.4f       | %.4f |\n", n1, n2, n3);
    printf("|____________________________|_________|____________|___________|____________|___________|\n");
    printf("|tg(x/2) - ctg(x/2) + x = 0  | [1:2]   | 1.0769     | %.4f      | %.4f       | %.4f |\n", m1, m2, m3);
    printf("|____________________________|_________|____________|___________|____________|___________|\n");
    return 0;
}
