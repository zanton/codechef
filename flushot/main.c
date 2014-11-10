#include <stdio.h>

#define MAX_N 10000

double get_min(double x, double y) {
  if (x < y) return x; else return y;
}

double get_max(double x, double y) {
  if (x > y) return x; else return y;
}

int main() {
  int k, n, i;
  double t;
  double x[MAX_N];
  double newx, maxl, liml, max_d;
  double gap, mov, movj, movi, min;
  
  scanf("%d", &k);
  while (k>0) {
    scanf("%d %lf", &n, &t);
    for (i=0; i<n; i++)
      scanf("%lf", &x[i]);
    
    // Solving case k
    newx = x[0];
    maxl = x[0];
    liml = 0.0;
    max_d = 0.0;
    i = 1;
    while (i < n) {
      gap = x[i] - newx;
      if (t >= gap) {
        
        // measure movj, movi
        mov = t - gap;
        movj = movi = 0.0;
        min = get_min(mov, max_d);
        movi += min;
        mov -= min;
        if (mov > 0) {
          min = get_min(mov, liml);
          movj += min;
          mov -= min;
          if (mov > 0) {
            min = get_min(mov / 2.0, maxl - liml);
            movj += min;
            movi += mov - min;
            // max_d
            max_d = movi;
          }
        }
        // liml, maxl
        liml = get_max(0.0, liml - movj);
        maxl -= movj;
        // move right
        newx = x[i] + movi;
        
      } else { /* t < gap */
        
        // liml, maxl
        liml = get_min(max_d, x[i] - newx + liml - t);
        maxl = x[i] - newx + maxl - t;
        // move right
        newx = x[i];
        
      }
      i++;
    }    
    
    // Output result
    printf("%.4lf\n", max_d);
    
    // Next case
    k--;
  }
  
  return 0;
}


