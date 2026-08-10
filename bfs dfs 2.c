#include <stdio.h>
#include <stdlib.h>
int display(int rows, int cols, int *arr)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", arr[i * cols + j]);
        }
        printf("\n");
    }
    return 0;
}
void bfs(int v, int n, int *g)
{
    int *vis = malloc(n * sizeof(int)); //checks whether node was visited or not
    int *q = malloc(n * sizeof(int)); 
    int f = 0, r = 0; //front and rear variables for queue
    int i;
    for (i = 0; i < n; i++)
        vis[i] = 0; //all nodes first initialized as not visited
    vis[v] = 1; //first visited vertex taken as 1
    q[r++] = v;
    while (f < r)
    {
        int u = q[f++]; //this means that the queue element at the front is dequeued, and front is pointed to the next element.
        printf("%d ", u); //the popped element is printed
        for (i = 0; i < n; i++)
        {
            if (g[u * n + i] == 1 && vis[i] == 0) //if the edge exists and has not been visited before
            {
                vis[i] = 1; //the node has been marked visited
                q[r++] = i; //rear element points to the ith element.
            }
        }
    }
    free(vis); 
    free(q);
}
void dfs(int v, int n, int *g)
{
    int *vis = malloc(n * sizeof(int)); 
    int *s = malloc(n * sizeof(int));
    int top = -1; //top is initialized to -1
    int i;
    for (i = 0; i < n; i++)
        vis[i] = 0; //all nodes are first marked as unvisited
    s[++top] = v; //top=whatever integer we have given for starting the traversal
    while (top >= 0)
    {
        int u = s[top--]; //value popped from stack stored in u

        if (vis[u] == 0) //if not visited before
        {
            vis[u] = 1; //marked as visited
            printf("%d ", u); //and it is printed

            for (i = n - 1; i >= 0; i--)
            {
                if (g[u * n + i] == 1 && vis[i] == 0) //if edge exists and has not been visited before
                    s[++top] = i; //increment top and store i at top
            }
        }
    }
    free(vis);
    free(s);
}
int main()
{
    int vertices;
    int i, j;
    int ch, sv;

    printf("enter number of vertices: ");
    scanf("%d", &vertices);

    int arr[vertices * vertices];

    for (i = 0; i < vertices; i++)
    {
        for (j = 0; j < vertices; j++)
        {
            printf("enter 1 if edge exists, otherwise 0: ");
            scanf("%d", &arr[i * vertices + j]);
        }
    }

    while (1)
    {
        printf("\n1. display matrix");
        printf("\n2. bfs");
        printf("\n3. dfs");
        printf("\n4. exit");
        printf("\nenter choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                display(vertices, vertices, arr);
                break;

            case 2:
                printf("enter starting vertex from 0 to %d: ", vertices - 1);
                scanf("%d", &sv);

                if (sv >= 0 && sv < vertices)
                    bfs(sv, vertices, arr);
                else
                    printf("invalid vertex");

                printf("\n");
                break;

            case 3:
                printf("enter starting vertex from 0 to %d: ", vertices - 1);
                scanf("%d", &sv);

                if (sv >= 0 && sv < vertices)
                    dfs(sv, vertices, arr);
                else
                    printf("invalid vertex");

                printf("\n");
                break;

            case 4:
                return 0;

            default:
                printf("invalid choice\n");
        }
    }
}
