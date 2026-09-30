#include <stdio.h>

int main(){
    double hh = 0.0;
    int d1, d2; // d1 * d2 <= 2k;
    double k;

    scanf("%lf %d %d", &k, &d1, &d2);

    double s = ((d2 - d1) / 2.0);
    hh = (k*k) - (s*s);
		
    printf("%.0lf\n", hh * 4);

    return 0;
}