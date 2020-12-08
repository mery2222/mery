/*
 a00*x+a01*y=b0
 a10*x+a11*y=b1


 | a00 a01 |
 |         | = w = a00*a11 - a10*a01
 | a10 a11 |

 | b0  a01 |
 |         | = wx
 | b1  a11 |

 | a00  b0 |
 |         | = wy
 | a10  b1 |

1.  jeżeli w != 0  => istnieje jedno rozwiązanie x0 = wx/w  i  x1 = wy/w

2.  jeżeli w=wy=wx=0  => istnieje nieskończenie wiele rozwiązań

3.  układ jest sprzeczny

*/

double det2(double a[][2]) {
    return a[0][0] * a[1][1] - a[1][0] * a[0][1];
}

int sol2(double a[][2], double b[], double x[]) {
    double w = det2(a);

    double temp[2][2];

    int i, j;

    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            temp[i][j] = a[i][j];

    for (i = 0; i < 2; i++)
        temp[i][0] = b[i];

    double wx = det2(temp);


    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            temp[i][j] = a[i][j];

    for (i = 0; i < 2; i++)
        temp[i][1] = b[i];

    double wy = det2(temp);

    if (w != 0.0) {
        x[0] = wx / w;
        x[1] = wy / w;
        return 1;
    }

    if (wx == 0.0 && wy == 0.0)
        return 999;

    return 0;
}

#include <stdio.h>

void sprawdzenie(double [][2], double [], double [], double []);

int main() {
    double a[2][2], b[2], x[2];

    printf("Podaj układ równań 2x2: \n");

    scanf("%lgx%lgy=%lg", &a[0][0], &a[0][1], &b[0]);
    scanf("%lgx%lgy=%lg", &a[1][0], &a[1][1], &b[1]);

    int n = sol2(a, b, x);

    if (n == 1) {
        printf("Jedno rozwiązanie x=%g i y=%g\n", x[0], x[1]);

        printf("Sprawdzenie:\n");

        double r[2];

        sprawdzenie(a, b, x, r);

        printf("r[0]=%g, r[1]=%g\n", r[0], r[1]);
        return 0;
    }

    if (n > 1) {
        printf("Nieskończenie wiele rozwiązań\n");
        return 0;
    }

    printf("Układ jest sprzeczny\n");
    return 0;

}

void sprawdzenie(double a[][2], double b[], double x[], double r[]) {
    r[0] = a[0][0] * x[0] + a[0][1] * x[1] - b[0];
    r[1] = a[1][0] * x[0] + a[1][1] * x[1] - b[1];
}

