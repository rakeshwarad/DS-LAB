#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};
struct node *reveresesll(struct node *start){
    struct node *curr,*last=NULL,*next;
    if(start==NULL){
        printf("no elements in sll");
        return NULL;
    }
    else if(start->next==NULL){
        return start;
    }
    else{
        curr=start;
        while(curr!=NULL){
            next=curr->next;
            curr->next=last;
            last=curr;
            curr=next;
        }
        return last;
    }
}

int countNodes(struct node *start){
    int count=0;
    struct node *temp=start;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

struct node *sortsll(struct node *start){
    struct node *temp,*follow;
    int x;
    if(start==NULL){
        printf("no elements in sll");
        return NULL;
    }
    else if(start->next==NULL){
        return start;
    }
    else{
        int n=countNodes(start);
        for(int i=0;i<n;i++){
            temp=start->next;
            follow=start;
            while(temp!=NULL){
                if(follow->info>temp->info){
                    x=follow->info;
                    follow->info=temp->info;
                    temp->info=x;
                }
                temp=temp->next;
                follow=follow->next;
            }
        }
        return start;
    }
}

struct node *concatnate(struct node *start,struct node *head){
    struct node *temp;
    if(start==NULL){
        return head;
    }
    else if(head==NULL){
        return start;
    }
    else{
        temp=start;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        return start;
    }
}
struct node *queuepush(struct node *start){
    struct node *p,*temp,*follow;
    int x;
    p=(struct node*)malloc(sizeof(struct node));
    printf("enter the element to push");
    scanf("%d",&x);
    p->info=x;
    if(start==NULL){
        p->next=NULL;
        start=p;
    }
    else{
        temp=start;
        while(temp->next!=NULL){
            follow=temp;
            temp=temp->next;
        }
        p->next=NULL;
        temp->next=p;
    }
    return start;
}
struct node *queuepop(struct node *start){
    struct node *temp;
    if(start==NULL){
        printf("no elemts in slll");
    }
    else if(start->next==NULL){
        free(start);
        start=NULL;
    }
    else{
        temp=start->next;
        free(start);
        start=temp;
    }
    return start;
}

struct node *stackpush(struct node *start){
    struct node *p;
    int x;
    p=(struct node*)malloc(sizeof(struct node));
    printf("enter the element to push");
    scanf("%d",&x);
    p->info=x;
    if(start==NULL){
        p->next=NULL;
        start=p;
    }
    else{
        p->next=start;
        start=p;
    }
    return start;
}

struct node *stackpop(struct node *start){
    struct node *temp;
    if(start==NULL){
        printf("no elemts in slll");
    }
    else if(start->next==NULL){
        free(start);
        start=NULL;
    }
    else{
        temp=start->next;
        free(start);
        start=temp;
    }
    return start;
}

void display(struct node *start){
    struct node *temp;
    if(start==NULL){
        printf("no elements in sll");
    }
    else{
        temp=start;
        while(temp!=NULL){
            printf("%d ",temp->info);
            temp=temp->next;
        }
    }
}

int main() {
    struct node *start = NULL;
    struct node *start2=NULL;
    int choice;

    printf("Menu:\n");
    printf("1. Reverse SLL\n");
    printf("2. Sort SLL\n");
    printf("3. Concatenate two SLL\n");
    printf("4. Push (Stack)\n");
    printf("5. Pop (Stack)\n");
    printf("6. Display\n");
    printf("7. Push (queue)\n");
    printf("8. Pop (queue)\n");
    printf("999. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    while (choice != 999) {
        switch (choice) {
            case 1:
                start = reveresesll(start);
                break;
            case 2:
                printf("Sorted the SLL\n");
                start = sortsll(start);
                break;
            case 3:
                printf("Merged two SLL\n");
                start = concatnate(start, start2);
                break;
            case 4:
                start = stackpush(start);
                break;
            case 5:
                start = stackpop(start);
                break;
            case 6:
                display(start);
                break;
            case 7:
                start=queuepush(start);
                break;
            case 8:
                start=queuepop(start);
            default:
                printf("Wrong choice\n");
                break;
        }
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
    }

    return 0;
}
