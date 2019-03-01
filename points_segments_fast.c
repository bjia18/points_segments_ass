#include "points_segments.h"

struct Seg{
    int num;
    char side;//left, right, or point
} seg;

int sort_points(const void *a, const void *b){
    return ( *(int*)a - *(int*)b );
}
int *fast(int **segs, int s, int*pts, int p){
    int size=p+s*2;
    int *ans2=calloc(p,sizeof(int));
    struct Seg *ans=calloc(size, sizeof(seg));
    struct Seg new;
    for (int i=0;i<p;i++){
        new.num=pts[i];
        new.side='p';
        ans[i]=new;
    }
    int iterate=0;
    for (int i=p;i<size;i+=2){
        new.num=segs[iterate][0];
        new.side='l';
        ans[i]=new;
        new.num=segs[iterate][1];
        new.side='r';
        ans[i+1]=new;
        iterate++;
    }
    qsort(ans, size, sizeof(seg), comparison);
    /*for (int i=0;i<size;i++){
        printf(" %d+%c",ans[i].num,ans[i].side);
    }
    printf("\n");*/
    int j=0, count=0;
    for (int i=0; i<size;i++){
        if (ans[i].side=='l')
            count++;
        else if (ans[i].side=='p'){
            ans2[j]=count;
            j++;
        } else
            count--;
    }
    return ans2;
}

int comparison(const void *a, const void *b){
    const struct Seg *a1, *b1;
    a1=(const struct Seg*)a;
    b1=(const struct Seg*)b;
    if (a1->num-b1->num==0){
        if (a1->side=='l' || b1->side=='l'){
            if (a1->side=='p')
                return 1;
            return -1;
        } else{
            if (a1->side=='p')
                return -1;
            return 1;
        }
    }
    return (a1->num-b1->num);
}