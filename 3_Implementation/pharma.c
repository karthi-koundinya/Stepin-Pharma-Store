/**
 * @file pharma.c
 * @author Karthik S (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
 #include<string.h>
 #include<ctype.h>
 struct Medicine{
   int id,price,quantity;
   char medicneName[100],Company[100],Mfg_Date[11],Exp_Date[11];
  }m[100];

 void DisplayMedicine(int number);
 void SearchMedicine(int number);
 void AddMedicine(int number,struct Medicine m[]);
 void DeleteMedicine(int number);
 void UpdateMedicine(int number);
 int main()
 {
   int i,j,choice,number=0,c;
   for(i=0;i<100;i++)
   {
    m[i].id=0;
   m[i].price=0;
   m[i].quantity=0;
   strcpy(m[i].Mfg_Date,"");
  strcpy(m[i].Exp_Date,"");
   strcpy(m[i].medicneName,"");
   strcpy(m[i].Company,"");
   }
   m[0].id=1;
   m[0].price=120;
   m[0].quantity=30;
   strcpy(m[0].Mfg_Date,"23-04-2021");
  strcpy(m[0].Exp_Date,"24-04-2022");
   strcpy(m[0].medicneName,"Paracetmol");
   strcpy(m[0].Company,"JK Pharma");
   do{
   printf("Enter\n1 - Add Medicine\n2 - Update Medicine\n3 - Delete Medicine\n4 - Search Medicine\n5 - Display Medicine\n");
   scanf("%d",&choice);
   switch(choice)
   {

      case 1:
      {
       ++number;
       AddMedicine(number,m);
       break;
      }
      case 2:
      {
        UpdateMedicine(number+1);

       break;
      }
      case 3:
      {
      DeleteMedicine(number+1);
       break;
      }
	case 4:
      {

       SearchMedicine(number+1);

       break;

      }
	case 5:

      {

       DisplayMedicine(number+1);

       break;

      }
   }
     printf("To Continue with other Options Enter 1 Else any other number\n");
     scanf("%d",&c);
   }while(c==1);

 }

 void SearchMedicine(int number){
   int i,flag=0;
  char name[100];
  printf("Enter the Medicine Name\n");
  fflush(stdin);
  scanf("%s",name);
  for(i=0;i<number;i++)
  {
   if(strcmp(m[i].medicneName,name)==0)
   {
    flag=1;
    printf("These are the details of Medicine\n");
   printf("\n==========================================================================================\n");
    printf("Id\t Name\t\t Price\t Qnty\t Company\t Mfg Date\t Exp Date\n");
printf("\n==========================================================================================\n");
printf("%d\t %s\t %d\t %d\t %s\t %s\t %s\t",m[i].id,m[i].medicneName,m[i].price,m[i].quantity,m[i].Company,m[i].Mfg_Date,m[i].Exp_Date);
printf("\n==========================================================================================\n");
  
   }
  }
  if(flag==0)
  {
   printf("Entered Name Not Found\n");
  }
 }
 void DisplayMedicine(int number){
  int i;
  if(number!=0)
  {
      printf("All Available Items are\n");
   for(i=0;i<number;i++)
   {
    if(m[i].id!=0){
printf("\n==========================================================================================\n");
    printf("Id\t Name\t\t Price\t Qnty\t Company\t Mfg Date\t Exp Date\n");
printf("\n==========================================================================================\n");
printf("%d\t %s\t %d\t %d\t %s\t %s\t %s\t",m[i].id,m[i].medicneName,m[i].price,m[i].quantity,m[i].Company,m[i].Mfg_Date,m[i].Exp_Date);
printf("\n==========================================================================================\n");
      }
   }
  }
  else{
   printf("\nNo Items or Medicines Available\n");
  }
 }
 void AddMedicine(int number,struct Medicine m[])
 {
  char name[100];
  printf("Enter Medicine Id\n");
  scanf("%d",&(m[number].id));
  fflush(stdin);
  printf("Enter Medicine Name\n");
  scanf("%s",(m[number].medicneName));
	fflush(stdin);
  printf("Enter Company Name\n");
  fflush(stdin);
 scanf("%s",(m[number].Company));
  printf("Enter Manufactured Date\n");
  fflush(stdin);
 scanf("%s",(m[number].Mfg_Date));
  printf("Enter Expiry Date\n");
  fflush(stdin);
  scanf("%s",(m[number].Exp_Date));
  printf("Enter Quantity\n");
  fflush(stdin);
  scanf("%d",&(m[number].quantity));
  printf("Enter Price\n");
  fflush(stdin);
  scanf("%d",&(m[number].price));
  printf("Medicine with id %d Added Successfully\n",m[number].id);
 }

 void DeleteMedicine(int number)
 {
  int id,i,flag=0,num;
  printf("Enter Id to be deleted\n");
  fflush(stdin);
  scanf("%d",&id);
  for(i=0;i<number;i++)
  {
   if(m[i].id==id)
   {
    flag=1;
    m[i].id=0;
    m[i].price=0;
    m[i].quantity=0;
    strcpy(m[i].medicneName,"");
    strcpy(m[i].Company,"");
    strcpy(m[i].Mfg_Date,"");
    strcpy(m[i].Exp_Date,"");
    num=i;
    break;
   }
  }
  if(flag==1)
  {
   printf("Medicine with %d is Deleted Successfully\n",id);
  }
 }

 void UpdateMedicine(int number)
 {
  int id,quantity,choice,c,i;
  printf("Enter id to change Details\n");
  scanf("%d",&id);
  for(i=0;i<number;i++)
  {
   if(m[i].id==id && m[i].id!=0)
   {
    do
    {
        printf("Enter\n1 - Change Quantity\n2 - Change Price\n3 - Change Name\n4 - Change Company\n5 - Change Manufaturing Date\n6 - Change Expiry Date\nAny other number to exit\n");
        scanf("%d",&choice);
        if(choice==1)
        {
         int quantity;
         printf("Enter Quantity to be update\n");
         fflush(stdin);
         scanf("%d",&quantity);
         m[i].quantity=quantity;
         printf("Quantity updated Successfully\n");
        }
        if(choice==2)
        {
         int price;
         printf("Enter Price to be update\n");
         fflush(stdin);
         scanf("%d",&price);
         m[i].price=price;
         printf("Price updated Successfully\n");
        }
        if(choice==3)
        {
         char name[100];
         printf("Enter Name to be update\n");
         fflush(stdin);
         scanf("%s",name);
         strcpy(m[i].medicneName,name);
         printf("Medicine Name updated Successfully\n");
        }
        if(choice==4)
        {
         char company[100];
         printf("Enter company to be update\n");
         fflush(stdin);
         scanf("%s",company);
         strcpy(m[i].Company,company);
         printf("Company updated Successfully\n");
        }
        if(choice==5)
        {
         char mfg[11];
         printf("Enter Manufacturing date to be updatd\n");
         fflush(stdin);
         scanf("%s",mfg);
         strcpy(m[i].Mfg_Date,mfg);
         printf("Manufacturing Date updated Successfully\n");
        }
        if(choice==6)
        {
         char exp[11];
         printf("Enter Expiry date to be update\n");
         fflush(stdin);
         scanf("%s",exp);
         strcpy(m[i].Exp_Date,exp);
         printf("Expiry Date updated Successfully\n");
        }
        if(choice<=0 && choice>6)
        {
         printf("Enter valid Choice\n");
        }
        printf("Enter 1 to Change other Details Else any other number\n");
        fflush(stdin);
        scanf("%d",&c);
    }while(c==1);

    break;
   }
  }
 }