#include "points_segments.h"

int *naive(int **segs, int s, int *pts, int p){
    int *ans=calloc(p, sizeof(int));
    for (int i=0;i<p;i++){
        for (int j=0;j<s;j++){
            if (pts[i]>=segs[j][0] && pts[i]<=segs[j][1])
                ans[i]++;
        }
    }
    return ans;
}