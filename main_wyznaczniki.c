/*
 a00*x+a01*y+a02*z=b0
 a10*x+a11*y+a12*z=b1
 a20*x+a21*y+a22*z=b2



 | a00 a01 a02 |
 |             |
 | a10 a11 a12 |= w = a00*a11*a22+a10*a21*a02+a20*a01*a12 - a02*a11*a20-a12*a21*a00-a22*a01*a10
 |             |
 | a20 a21 a22 |

 | b0 a01 a02  |
 |             |
 | b1 a11 a12  |= wx
 |             |
 | b2 a21 a22  |

 | a00 b0 a02 |
 |            |
 | a10 b1 a12 |= wy
 |            |
 | a20 b2 a22 |

 | a00 a01 b0 |
 |            |
 | a10 a11 b1 |= wz
 |            |
 | a20 a21 b2 |

1.  jeżeli w != 0  => istnieje jedno rozwiązanie x0 = wx/w,  x1 = wy/w, x2 = wz/w

2.  jeżeli w=wy=wx=wz=0  => istnieje nieskończenie wiele rozwiązań

3.  układ jest sprzeczny

*/

double det3(double a[][3]) {
    return a[0][0]*a[1][1]*a[2][2]+a[1][0]*a[2][1]*a[0][2]+a[2][0]*a[0][1]*a[1][2] - a[0][2]*a[1][1]*a[2][0]-a[1][2]*a[2][1]*a[0][0]-a[2][2]*a[0][1]*a[1][0];
}

int sol3(double a[][3], double b[], double x[], double z[]) {
    double w = det3(a);

    double temp[3][3];

    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            temp[i][j] = a[i][j];

    for (i = 0; i < 3; i++)
        temp[i][0] = b[i];

    double wx = det3(temp);

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            temp[i][j] = a[i][j];

    for (i = 0; i < 3; i++)
        temp[i][1] = b[i];


    double wy = det3(temp);

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            temp[i][j] = a[i][j];

    for (i = 0; i < 3; i++)
        temp[i][2] = b[i];

    double wz = det3(temp);

    if (w != 0.0) {
        x[0] = wx / w;
        x[1] = wy / w;
        x[2] = wz / w;
        return 1;
    }

    return 0;
}

#include <stdio.h>

void sprawdzenie(double [][2], double [], double [], double []);

int main() {
    double a[2][2], b[2], x[2], z[2];

    printf("Podaj układ równań 3x3: \n");

    scanf("%lgx%lgy%lgz=%lg", &a[0][0], &a[0][1], &a[0][2], &b[0]);
    scanf("%lgx%lgy%lgz=%lg", &a[1][0], &a[1][1], &a[1][2], &b[1]);
    scanf("%lgx%lgy%lgz=%lg", &a[2][0], &a[2][1], &a[2][2], &b[2]);

    int n = sol3(a, b, x,z);

    if (n == 1) {
        printf("Jedno rozwiązanie x=%g i y=%g i z=%g\n", x[0], x[1], x[2]);

        printf("Sprawdzenie:\n");

        double r[3];

        sprawdzenie(a, b, x, r);

        printf("r[0]=%g, r[1]=%g, r[2]=%g\n", r[0], r[1], r[2]);
        return 0;
    }

    printf("Układ jest sprzeczny\n");
    return 0;

}

void sprawdzenie(double a[][2], double b[], double x[], double r[]) {
    r[0] = a[0][0] * x[0] + a[0][1] * x[1] +a[0][2] *x[2] - b[0];
    r[1] = a[1][0] * x[0] + a[1][1] * x[1] +a[1][2] *x[2] - b[1];
    r[2] = a[2][0] * x[0] + a[2][1] * x[1] +a[2][2] *x[2] - b[2];
}


