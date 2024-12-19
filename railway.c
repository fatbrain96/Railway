#include<stdio.h>
#include<stdlib.h>
# define num 3

struct passenger{
    int id;
	char passengerName[50];
    int age;
    char gender[20];
    char date[25];
    char boarding[20];
    char destination[20];
}p;

FILE*fp;

void bookticket();
void cancelticket();
void passengerlist();

int count=0;
int n=0; 

int main(){

    int ch;

    while(1){
        system("cls");
        printf("**** RAILWAY RESERVATION SYSTEM ****\n\n");
        printf("1.Book a ticket\n");
        printf("2.Cancel a ticket\n");
        printf("3.Passenger's List\n");
        printf("0.Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch){
        case 0:
            exit(0);

        case 1:
		   bookticket();
            break;

        case 2:
            cancelticket();
            break;

        case 3:
            passengerlist();
            break;

        default:
            printf("NOT FOUND ...!!\n\n");

        }
        printf("\n\nPress Any Key To Continue...");
        getch();
    }

    return 0;
}

void bookticket()
{
    fp = fopen("passenger.txt", "ab");
    
	printf("Enter passenger ID:");
    scanf("%d",&p.id);
    
	printf("Passenger's Name: ");
    fflush(stdin);
    gets(p.passengerName);

    printf("Gender: ");
    fflush(stdin);
    gets(p.gender);

    printf("Age: ");
    fflush(stdin);
    scanf("%d",&p.age);

    printf("Date of Journey: ");
    fflush(stdin);
    gets(p.date);
    
    printf("Boarding station: ");
    fflush(stdin);
    gets(p.boarding);
    
    printf("Destination station: ");
    fflush(stdin);
    gets(p.destination);

    if(p.age>=80 || p.age<=10)
    {printf("\n Age not eligible.....!!!");
	}
    else if(n>num)
	{ count++;
	printf("\nSeat Not Available..\n You have been added to the waiting list.\nWaiting list number: %d",count);
	}	
    else
    { n++;
    printf("\nTicket booked successfully.....\n Passenger ID: %d\n Bearth Alloted: UPPER",p.id);
	}
	
	fwrite(&p, sizeof(p), 1, fp);
    fclose(fp);
}

void cancelticket()
{  	    int id, f=0;
    printf("Enter ID to be cancelled: ");
    scanf("%d", &id);

    FILE *ft;

    fp = fopen("passenger.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while(fread(&p, sizeof(p), 1, fp) == 1){

        if(id == p.id){
            f=1;
        }else{
            fwrite(&p, sizeof(p), 1, ft);
        }
    }

    if(f==1){
    	n--;
        printf("\n\nTicket cancelled Successfully.");
    }else{
        printf("\n\n Passenger Not Found !");
    }

    fclose(fp);
    fclose(ft);

    remove("passenger.txt");
    rename("temp.txt", "passenger.txt");

}

void passengerlist()
{ fp = fopen("passenger.txt", "rb");
   if(fp== NULL)
   { printf("\nLIST IS EMPTY....!!!");
   }
   else
   {  while(fread(&p, sizeof(p), 1, fp) == 1){ 
   printf("Name: %s\nAge: %d\nGender: %s\nDate: %s\nBoarding station: %s\nDestination station: %s\n\n",p.passengerName,p.age,p.gender,p.date,p.boarding,p.destination);
  }
  fclose(fp);
}
}
