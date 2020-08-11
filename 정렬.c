#include <stdio.h>
#include <stdlib.h>

//#define SWAP(x, y, t)	t = x; 

struct xy{
    int x;
    int y;
};

int main(){
    int n,p,q,x,y;
    p=1;
    q=1;
    scanf("%d", &n);
    struct xy *a;
    struct xy ex;
    a = (struct xy*)malloc(n*8);
    for(p=0;p!=n;p++){
        scanf("%d%d", &x, &y);
        ((a+p)->x) = x;
        ((a+p)->y)= y;
    }
    
    for(p=1;p!=n;p++){
        for(q=p;q!=n;q++){
            if((a+p-1)->x>(a+q)->x){
                ex = *(a+p-1);
                *(a+p-1)=*(a+q);
                *(a+q)=ex;
            }
        }
    }
    for(p=1;p!=n;p++){
        for(q=p;q!=n;q++){
            if((a+p-1)->y>(a+q)->y){
                ex = *(a+p-1);
                *(a+p-1)=*(a+q);
                *(a+q)=ex;
            }
        }
    }
    for(p=0;p!=n;p++){
        printf("%d %d\n", (a+p)->x, (a+p)->y);
    }
    return 0;
}
