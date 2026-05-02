#include<stdio.h>
#include<stdlib.h>
#define MAX 100
struct node{
int vertex;
struct node*next;
};
struct node*graph[20];
int visited[20];
int n;
struct node*create(int v){
struct node*newnode=malloc(sizeof(struct node));
newnode->vertex=v;
newnode->next=NULL;
return newnode;
}
void addedge(int u,int v){
struct node*nn=create(v);
nn->next=graph[u];
graph[u]=nn;

nn=create(u);
nn->next=graph[v];
graph[v]=nn;
}

void removeedge(int u,int v){
struct node*t=graph[u],*prev=NULL;
while(t!=NULL){
       if(t->vertex==v){
              if(prev!=NULL)
                     prev->next=t->next;
              else
                     graph[u]=t->next;
              free(t);
              break;
       }
       prev=t;
       t=t->next;
}}
t=graph[v];
prev=NULL;
while(t!=NULL){
       if(t->vertex==u){
              if(prev!=NULL)
                     prev->next=t->next;
              else
                     graph[v]=t->next;
              free(t);
              break;
       }
       prev=t;
       t=t->next;
}
}

void print() {
    for(int i=0;i<n;i++) {
        printf("%d: ", i);
        struct node* t = graph[i];
        while(t) {
            printf("%d ", t->vertex);
            t = t->next;
        }
        printf("\n");
        }
}
void bfs(int start){
int q[20],f=0,r=0;
for(int i=0;i<n;i++)
       visited[i]=0;

       visited[start]=1;
       q[r++]=start;
       printf("BFS: ");while(f<r) {
        int cur = q[f++];
        printf("%d ", cur);

        struct node* t = graph[cur];
        while(t!=NULL) {
            if(!visited[t->vertex]) {
                visited[t->vertex]=1;
                q[r++]=t->vertex;
            }
            t = t->next;
        }
    }
    printf("\n");
}
void leaf(){
printf("Leaf Vertices: ");
for(int i=0;i<n;i++) {
        int count=0;
        struct node* t = graph[i];
        while(t!=NULL){
              count++;
              t=t->next;
               }
        if(count==1) {
          printf("%d ", i);
        }
    }
    printf("\n");
}
int isconnect(){
int q[20], f=0, r=0;

    for(int i=0;i<n;i++)
       visited[i]=0;

    visited[0]=1;
    q[r++]=0;

 while(f<r) {
        int cur = q[f++];
        struct node* t = graph[cur];
        while(t) {
            if(!visited[t->vertex]) {
                visited[t->vertex]=1;
                q[r++]=t->vertex;
            }
            t = t->next;
        }
    }

    for(int i=0;i<n;i++)
        if(!visited[i])
              return 0;

    return 1;
}
void totaldegree(){
int total=0;
for(int i=0;i<n;i++){
       struct node*t=graph[i];
       while(t!=NULL){
              total++;
              t=t->next;
       }
}
printf("Total degree: %d\n",total);
}
void nooutgoing(){
printf("No outgoing edge vertices: ");
for(int i=0;i<n;i++)
       if(graph[i]==NULL)
       printf("%d",i);
printf("\n");
}
void compo(){
int q[20], f, r, count=0;

    for(int i=0;i<n;i++)
       visited[i]=0;
    for(int i=0;i<n;i++) {
        if(!visited[i]) {
            f=r=0;
            visited[i]=1;
            q[r++]=i;

            while(f<r) {
                int cur = q[f++];
                struct node* t = graph[cur];
                while(t!=NULL) {
                    if(!visited[t->vertex]) {
                        visited[t->vertex]=1;
                        q[r++]=t->vertex;
                    }
                    t = t->next;
                }
            }
            count++;
        }
    }

    printf("Connected components: %d\n", count);
}

int main(){
int ch,u,v;
 printf("Enter number of vertices: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
       graph[i]=NULL;

    while(1) {
        printf("\n--- MENU ---\n");
        printf("1. Add Edge\n 2. Remove Edge\n 3. Print Graph\n 4. BFS\n");
        printf("5. Leaf Vertices\n 6. Check Connected\n 7. Total Degree\n");
        printf("8. No Outgoing Edge\n 9. Connected Components\n 0. Exit\n");
        printf("Enter choice: ");
        scanf("%d",&ch);switch(ch) {
            case 1:
                printf("Enter u v: ");
                scanf("%d%d",&u,&v);
                addedge(u,v);
                break;

            case 2:
                printf("Enter u v: ");
                scanf("%d%d",&u,&v);
                removeedge(u,v);
                break;

            case 3:
                print();
                break;

            case 4:
                printf("Start vertex: ");
                scanf("%d",&u);
                bfs(u);
                break;

            case 5:
                leaf();
                break;

            case 6:
                if(isconnect())
                     printf("Graph is Connected\n");
                else
                printf("Graph is NOT Connected\n");
                break;

            case 7:
                totaldegree();
                break;

            case 8:
                nooutgoing();
                break;
case 9:
                compo();
                break;

            case 0:
                return 0;
        }
    }
}

