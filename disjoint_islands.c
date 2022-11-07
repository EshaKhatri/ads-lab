#include<stdio.h>
#include <stdlib.h>

int parent[25];
int input[25];


int find(int x){
    if (parent[x]==-1){
        return x;
    }
    else return parent[x];
}

void union(int a, int b){
if(find(a)!=find(b))
        parent(find(a))=find(b);

}


void traverse(int i){
    if (input[i-6]==1)
        union(i-6,i);

    else if (input[i-5]==1)
        union(i-5,i);

    else if (input[i-4]==1)
        union(i-4,i);

    else if (input[i-1]==1)
        union(i-1,i);

    else if (input[i+1]==1)
        union(i+1,i);

    else if (input[i+4]==1)
        union(i+4,i);

    else if (input[i+5]==1)
        union(i+5,i);

    else if (input[i+6]==1)
        union(i+6,i);

}
int main(){
    int count = 0;
    for(int i=0;i<25;i++){
    parent[i]=-1;
}
for(int i=0 ; i<25 ; i++){
    scanf("%d \t",&input[i]);
}

for(int i=0; i<25; i++){
    if (input[i]==1){
        traverse(i);
    }
}
for(int i=0; i<25; i++){
    if (parent[i]=0){
        count++;
    }
}
}
