// This Node is for creating the trees  -->        left child<-data->right child
struct Node
{
    struct Node *lchild;
    struct Node *rchild;
    int data;
};

//This Queue is formed for storing the addresses of the tree
struct Queue
{
    int size;
    int front;
    int rear;
    /*  Node* (It is to define that return
            type is node as it is storing the address of the above node formed)
        *Q (It is to define the dynamically created array)
 */
    struct Node**Q;
};

void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node **)malloc(sizeof(struct Node*)*q->size);  // A queue will be formed
}

void enqueue(struct Queue *q,struct Node *x) //the element "x" will store Node type pointer address
{
    if((q->rear+1)%q->size==q->front)
        printf("Queue is Full");
    else
    {
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
struct Node* dequeue(struct Queue *q)
{
    struct Node* x=NULL;   //the return type in "x" is Node type
    if(q->front==q->rear)
        printf("Queue is Empty");
    else
    {
       q->front=(q->front+1)%q->size;
       x=q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue *q)
{
    return q->front==q->rear;
}


/*End of "Queue Creation" for trees */
