
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct list
{
 int age;
 int rollno;
 struct list *next;
 struct list *pre;

};
  struct list *start=NULL,*last=NULL;
 struct list *nn(int,int);
 void add()
 {

    int age,rollno;
    struct list *ptr1,*ptr;
    char ch;
 do{
    printf("\nenter age:");
    scanf("%d",&age);
    printf("\nenter rollno");
    scanf("%d",&rollno);
      ptr1=nn(age,rollno);
    if(start==NULL)
    {start=ptr1;}
    else
    {
    ptr=start;

    while(ptr->next!=NULL)
    { ptr=ptr->next;}
    ptr->next=ptr1;

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
       ptr->pre=NULL;
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
   int countnodes()
   {
     struct list *ptr=start;
     int count=0;
     while(ptr!=NULL)
     {
     count++;
     ptr=ptr->next;
     }
     return count;
   }

   void insert()
   {
    int pos,count,age,rollno;
    struct list *ptr,*ptr1=start;
    printf("\nenter position");
    scanf("%d",&pos);
    count=countnodes();
    if(pos<1 ||pos>count+1)
    {
     printf("\n invalid position");
     return ;
    }
    else
    {
     printf("\n enter age");
      scanf("%d",&age);
     printf("\n enter rollno");
     scanf("%d",&rollno);
     ptr=nn(age,rollno);
     if(pos==1)
     {
      start->pre=ptr;
      ptr->next=start;
      start=ptr;
     }
     else
     {
      for(int i=1;pos-1>i;i++)
      {
       ptr1=ptr1->next;
      }
     ptr->next=ptr1->next;
     ptr->pre=ptr1;
     ptr1->next->pre=ptr;
     ptr1->next=ptr;


     }
    }

   }
    void deleteNode()
    {
     int pos,count;
     struct list *ptr,*ptr1;
     printf("\n enter position of node to be deleted: ");
     scanf("%d",&pos);
     count=countnodes();
     if(pos<1||pos>count)
     {
	printf("\n invalid position");
     }
     else
     {
      if(pos==1)
      {
      ptr=start;
      start=start->next;
      free(ptr);
      ptr=NULL;
      }
      else
      {
       ptr=start;
       for(int i=1;i<pos-1;)
       {
	 ptr=ptr->next;
	 i++;
       }
       ptr1=ptr->next;
       ptr->next=ptr->next->next;
       free(ptr1);
       ptr1=NULL;
      }
     }
   }
    void delroll()
    {
     int rollno;
     struct list *ptr=start,*ptr1;
     printf("\n enter rollno");
     scanf("%d",&rollno);
     while(ptr!=NULL&&ptr->rollno!=rollno)
     {
      ptr1=ptr;
      ptr=ptr->next;

     }
      if(ptr!=NULL)
      {
       if(ptr==start)
       {
	start=start->next;
	free(ptr);
	ptr=NULL;
       }
       else
       {
	ptr1->next=ptr->next;
	free(ptr);
	ptr=NULL;

       }
      }
       else
       {printf("\n element not found");

       }

    }
    void update()
    {
     int pos,count;
     struct list*ptr;
     printf("\n enter position of node:");
     scanf("%d",&pos);
     count=countnodes();
     if(pos<1||pos>count)
     {
      printf("\ninvalid position");

     }
     else
     {
      ptr=start;
      for(int i=1;i<count;)
      {
       ptr=ptr->next;
       i++;
      }
     }
     printf("\n enter new age");
     scanf("%d",&(ptr->age));
     printf("\n enter new rollno");
     scanf("%d",&(ptr->rollno));


    }
    void reverse()
    {
     struct list*ptr=start,*ptr1,*ptr2;
     ptr1=ptr;
     ptr=ptr->next;
     ptr2=ptr;
     ptr1->next=NULL;
     while(ptr!=NULL)
     {
      ptr=ptr->next;
      ptr2->next=ptr1;
      ptr1=ptr2;
      ptr2=ptr;
     }
     ptr=ptr1;
     start=ptr;
   }
   void main()
   {  clrscr();
     add();
     traverse();
     insert();
     traverse();
     getch();
   }