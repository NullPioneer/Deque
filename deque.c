#include <stdio.h>

int rear = -1, front = -1, item;
int cq[50];

void enqueuerear(int len, int item) {
    if ((front == (rear + 1) % len)) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        cq[rear] = item;
    } else {
        rear = (rear + 1) % len;
        cq[rear] = item;
    }
}

void enqueuefront(int len, int item) {
    if ((rear == (front-1+len) % len)) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        cq[front] = item;
    } else {
        front = (front - 1 + len) % len;
        cq[front] = item;
    }
}

int dequeuefront(int len) {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
        return -1;
         } 
else if(front==rear)
{
            front = -1;
            rear = -1;
        } else 
       {
            item = cq[front];
            front=(front+1)%len;
            return item;
      }
}
int dequeuerear(int len) {
    if (rear == -1) {
        printf("Queue is empty\n");
        return -1;
    } else if(front==rear)
    {
        front=-1;
        rear=-1;
}
else 
{
          item = cq[rear];
            rear = (rear - 1 + len) % len;
        return item;
    }
}

void display(int len) {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else 
       {
          if(front<=rear)
         {
        printf("Current queue is:\n");
       for (int i = front; i <= rear; i++) {
                printf("%d\n", cq[i]);
            }
        } else  if(rear<front)
{
          printf("Current queue is:\n");
          for (int i = front; i < len; i++) {
                printf("%d\n", cq[i]);
            }
            for (int i = 0; i <= rear; i++) {
                printf("%d\n", cq[i]);
            }
        }
    }
}

int main() {
    int ch, n, b;

    printf("Enter the size of the queue\n");
    scanf("%d", &n);
    
    do {
        printf("Enter your choice\n");
        printf("1-Enqueue from rear\n2-Enqueue from front\n3-Dequeue from front\n4-Dequeue from rear\n5-Display\n6-exit\n");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                if (front != (rear + 1) % n) {
                    printf("Insert the element\n");
                    scanf("%d", &item);
}
                    enqueuerear(n, item);
                    display(n);
                    break;

            case 2:
                if (front != (rear + 1) % n) {
                    printf("Insert the element\n");
                    scanf("%d", &item);
}
                    enqueuefront(n, item);
                    display(n)
                break;

            case 3:
                b = dequeuefront(n);
                    printf("Popped element\n");
printf("%d\n", b);
                display(n);
                break;

            case 4:printf("Popped element\n");
                b = dequeuerear(n);
                    printf("%d\n", b);
                display(n);
                break;

            case 5:
                display(n);
                break;

            case 6:
                break;

            default:
                printf("Wrong input\n");
        }
    } while (ch != 6);
}
