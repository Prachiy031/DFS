#include <stdio.h>
#include<stdlib.h>
#define n 4


  int A[n][n],stack[10],top=-1;
 int visited[n];
 
 void DFS(int v){
     visited[v]=1;
     for(int i=0;i<n;i++){
         if(A[v][i]==1 && !visited[i]){
             printf("The edge is [%d %d]\n",v,i);
             DFS(i);
         }
     }
 }
 int pop(){
    stack[top--];
    return stack[top];
}
void dfs1(int v)
{
      visited[v]=1;
      //printf("%d ",v);
      stack[++top]=v;
     for(int i=0;i<n;i++){
         if(A[v][i]==1 && !visited[i]){
             printf("The edge is [%d %d]\n",v,i);
             DFS(i);
             break;
         }
     }

   for(int i=0;i<n;i++){
       if(A[stack[top]][i]==1 && !visited[i]){
           pop();
           
       }
       else{
           dfs1(stack[top]);
       }
}
}


void main()
{
    int v;
    printf("Enter the matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
for(int i=0;i<n;i++){
    visited[i]=0; 
}

printf("Enter the starting vertex\n");
scanf("%d",&v);
//DFS(v);
dfs1(v);
}


