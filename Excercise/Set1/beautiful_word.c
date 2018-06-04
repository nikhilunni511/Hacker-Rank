#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int f,f1=0;
    char* w = (char *)malloc(100000 * sizeof(char));
    char v[]="aeiouy";
    scanf("%s",w);
    for(int i=0;i<strlen(w)-1;i++)
    {
        f=0;
        if(w[i]==w[i+1]){
            printf("No\n");
            f1=1;
            return 0;
        }
        for(int j=0;j<strlen(v);j++){
            if(w[i]==v[j])
                f=1;
            if(f==1)
            {
                for(int k=0;k<strlen(v);k++){
                    if(w[i+1]==v[k]){
                        f1=1;
                        printf("No\n");
                        return 0;
                    }
                }
            }
        }
        
    }
    if(f1==0)
        printf("Yes\n");
    return 0;
}
