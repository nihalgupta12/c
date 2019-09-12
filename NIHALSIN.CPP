#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct list
{
 int age;
 int rollno;
 struct list *next;

};
  struct list *start=NULL,*last=NULL;
 struct list *nn(int,int);
 void add()
 {

    int age,rollno;
    struct list *ptr1;
    char ch;
   do{
    printf("\nenter age:");
    scanf("%d",&age);
    printf("\nenter rollno");
    scanf("%d",&rollno);
      ptr1=nn(age,rollno);
    if(start==NULL)
    {start=last=ptr1;}
    else
    {
    last->next=ptr1;
    last=ptr1;
    }
    printf("do you want to continue?(y/n):");
    fflush(stdin);
    ch=getchar();
    }while(ch=='y'||ch=='Y');
 }

     struct list* nn(int age,int rollno)
      {
       struct list* ptr;
       ptr=(struct list*)malloc(sizeof(struct list));
       ptr->age=age;
       ptr->rollno=rollno;
       ptr->next=NULL;
       return ptr;

      }
   void traverse()
   {
    struct list *ptr=start;
    while(ptr!=NULL)
    {
     printf("\n%d---->%d",ptr->age,ptr->rollno);
     ptr=ptr->next;

    }

   }
  void main()
  {
  add();
  traverse();
    getch();
  }