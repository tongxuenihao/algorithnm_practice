#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

                         
typedef struct list_node {
    int  element;      
    struct list_node* Next; 
}Node;

Node* CreateList(void) {
    int len ;  
    int val ;  
    Node* p_head;
    Node* p_tail;
    Node* p_new;
    p_head = (Node*)malloc(sizeof(Node));    
    if (p_head == NULL)   
    {
        printf("malloc error\n");
    }

    p_tail = p_head;    
    p_tail->Next = NULL;  
    printf("input node count:");
    scanf("%d", &len);     
    for (int i = 0; i < len; i++) 
    {
        p_new = (Node*)malloc(sizeof(Node));  
        if (p_new == NULL) 
        {
            printf("malloc new node error\n");
        }
        printf("input the %d node data:", i + 1);
        scanf("%d", &val);   

        p_new->element = val; 
        p_tail->Next = p_new;    //    tail node point the new node
        p_new->Next = NULL;      //    the new node point null
        p_tail = p_new;     
    }
    printf("list create success\n");
    return p_head;
}


void traverse_list(Node* List) 
{
    Node* P = List->Next;  
    printf("list traverse list:");
    if (P == NULL)
    {
        printf("list is null");
    }
    while (P != NULL)
    {
        printf("%d ", P->element);
        P = P->Next;
    }
    printf("\n");
}

Node* find_list(Node* List) 
{
    Node* P = List->Next;  
    int num = 0;    
    int val = 0; 
    printf("input the number:");
    scanf("%d", &val);  
    while (P != NULL) 
    {
        if(P->element != val)
        {
            P = P->Next;
            ++num;
        }
        else
        {
            break;
        }
    }
    if(P != NULL)
    {
        printf("the node is:%d", num + 1);
    }
    else
    {
        printf("node donot exit");
    }
    printf("\n");
    return P;
}

void insert_list(Node* List, int pos, int val)
{
    Node* P1 = List->Next;
    Node* P2;
    Node * p_new;
    int num = 0;
    while (P1 != NULL) 
    {
        if(num < pos - 2)
        {
            P1 = P1->Next;
            ++num;
        }
        else
        {
            P2 = P1->Next;
            break;
        }
    }

    p_new = (Node*)malloc(sizeof(Node));  
    if (p_new == NULL) 
    {
        printf("malloc new node error\n");
    }
 
    p_new->element = val; 
    p_new->Next = P2;
    P1->Next = p_new;
}

void delete_list(Node* List, int pos) 
{
    Node* P1 = List->Next;
    Node* P2;
    int num = 0;
    while (P1 != NULL) 
    {
        if(num < pos - 2)
        {
            P1 = P1->Next;
            ++num;
        }
        else
        {
            P2 = P1->Next;
            break;
        }
    }

    P1->Next = P2->Next;
    free(P2);
    P2 = NULL;
}


void delete_the_list(Node* List) 
{
    Node* P;
    Node* Tmp;
    P = List->Next;    
    List->Next = NULL;
    while (P != NULL) 
    {
        Tmp = P->Next;        
        free(P);    
        P = Tmp;  
    }
    printf("delete list success\n");
}

int main() 
{
    Node* List = CreateList();     
    traverse_list(List);      
    find_list(List);
    insert_list(List, 3, 100);
    traverse_list(List);  
    delete_list(List, 3);
    traverse_list(List);  
    delete_the_list(List); 
    traverse_list(List);  
    return 0;
}

