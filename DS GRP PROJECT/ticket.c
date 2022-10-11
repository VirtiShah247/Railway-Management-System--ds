
#include "RailwayDatabase.c"
struct ticket
{
    char source[30], destination[30], date_of_travel[30], name[30], gender[30], mobile_no[30], email_id[30], aadhar_no[30], class_of_travel[30];
    int total_passenger, total_adult, age, total_child, train_no, ticket_id;
    float fare_adult, fare_child, fare_total;
    char dp[200];
    struct ticket *next;
} m, *hd = NULL;
int read_ticket_database()
{
    struct ticket *pt;
    pt = hd;
    FILE *f;
    f = fopen("ticket.txt", "r");
    fseek(f, 0, SEEK_END);
    int len = (int)ftell(f);
    if (len == 0)
    {
        fclose(f);
        printf("there is no tickets in train");
        return 0;
    }
    rewind(f);
    char s[200];
    while (fgets(s, sizeof(s), f))
    {
        struct ticket *tp;
        tp = (struct ticket *)malloc(sizeof(struct ticket));
        strcpy(tp->dp, s);
        tp->next = NULL;
        if (feof(f))
        {
            break;
        }
        if (hd == NULL)
        {
            pt = hd = tp;
        }
        else
        {
            pt = pt->next = tp;
        }
    }
    fclose(f);
    return 1;
}
void display()
{
    int i = read_ticket_database();
    if (i == 0)
    {
        return;
    }
    printf("\n\n--------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("||Ticket ID||Train Number||  Source  ||Destination||Date of travel||Total Passenger||Name of Payer||Mobile Number||Class||total Fare||\n\n");
    printf("\n\n--------------------------------------------------------------------------------------------------------------------------------------------\n\n");
    struct ticket *tp;
    tp = hd;
    while (tp != NULL)
    {
        printf("\n%s\n", tp->dp);
        tp = tp->next;
    }
    hd = NULL;
}
void cancel_ticket()
{
    int i = read_ticket_database(), found = 0;
    char id[10];
    if (i == 0)
    {
        return;
    }
    FILE *f;
    f = fopen("ticket.txt", "w");
    printf("\n\nEnter Ticket id for Cancel Ticket");
    scanf("%s", id);
    int d = strlen(id);
    struct ticket *tp;
    tp = hd;
    while (tp != NULL)
    {
        if (strncmp(id, tp->dp, d))
        {
            fputs(tp->dp, f);
        }
        else
        {
            found = 1;
        }
        tp = tp->next;
    }
    fclose(f);
    hd = NULL;
    if (found == 1)
    {
        printf("Successfully deleted ticket of ticket id = %s", id);
    }
    else
    {
        printf("There is no ticket with ticket id %s\n\n", id);
    }
    display();
}
int book_ticket()
{
    char v1[30], v2[30], v3[30], v4[30], v5[30], v6[30], v7[30], v8[30], v9[30];
    int a1, a2, a3, a4, a5, a6;
    float f1, f2, f3;
    time_t t;
    srand((unsigned long)time(&t));
    int choice, cc;
    float km;
    FILE *f;
    f = fopen("ticket.txt", "a");
    if (f == NULL)
    {
        printf("File is not opened");
        return;
    }
start:
    printf("-------------------WELCOME TO TICKET BOOKING PORTAL-------------------\n");
    usleep(2000);
    a6 = rand() % 100000;
    printf("Enter Journey Details \n\n");
    fflush(stdin);
    printf("Enter Source :");
    scanf("%s", v1);
    fflush(stdin);
    printf("Enter Destination :");
    scanf("%s", v2);
    fflush(stdin);
    printf("Enter date of travel :");
    scanf("%s", v3);
pass:
    printf("------------------------------------------------------------\n\n");
    fflush(stdin);
    printf("Enter total number of passenger :");
    scanf("%d", &a1);
    fflush(stdin);
    printf("Total Number of adults :");
    scanf("%d", &a2);
    fflush(stdin);
    printf("Total Number of Childs :");
    scanf("%d", &a3);
    if (a1 != a2 + a3)
    {
        printf("you entered wrong details of total passengers\n");
        goto pass;
    }
    fflush(stdin);
    printf("------------------------------------------------------------");
    usleep(2000);
    system("CLS");
    if (a1 != 0)
    {
        printf("\n\nEnter Personal Details of only one passenger\n\n");
        printf("------------------------------------------------------------\n\n");
        fflush(stdin);
        printf("Name: ");
        scanf("%s", v4);
        fflush(stdin);
        printf("Age: ");
        scanf("%d", &a4);
        fflush(stdin);
    gen:
        printf("Gender: ");
        scanf("%s", v5);
        strlwr(v5);
        if (strcmp(v5, "male") != 0 && strcmp(v5, "female") != 0)
        {
            printf("worng gender choice\n");
            goto gen;
        }
    mo:
        fflush(stdin);
        printf("Mobile Number:");
        scanf("%s", v6);
        if (strlen(v6) != 10)
        {
            printf("invalid mobile number\n");
            goto mo;
        }
        fflush(stdin);
        printf("Email Id: ");
        scanf("%s", v7);
    aa:
        fflush(stdin);
        printf("Aadhar Number: ");
        scanf("%s", v8);
        if (strlen(v8) != 12)
        {
            printf("invalid aadhar number\n");
            goto aa;
        }
    clss:
        fflush(stdin);
        printf("Class of Travel(Sleeper(SL),2 Tier AC(2AC),3 Tier AC(3AC)): ");
        scanf("%s", v9);
        strlwr(v9);
        if (strcmp(v9, "2ac") != 0 && strcmp(v9, "3ac") != 0 && strcmp(v9, "sl") != 0)
        {
            printf("wrong class choice\N");
            goto clss;
        }
        printf("------------------------------------------------------------");
        system("CLS");
    }
c:
    printf("------------------------------------------------------------\n");
    printf("Enter Your Choice\n1.Confirm Ticket\n2.Edit Ticket\n3.Cancel Booking");
    scanf("%d", &choice);
    printf("\n");
    if (choice == 1)
    {
        printf("------------------------------------------------------------\n\n");
        read_database();
        int flag = 0;
        strlwr(v1);
        strlwr(v2);
        char v[30];
        sprintf(v, "%s %s", v1, v2);
        p = ptr;
        if (p == NULL)
        {
            printf("There is no ");
            return;
        }
        printf("\n---------------------------------------------------------------------\n");
        printf("|No| Train name\t    |  DATE | ST| AT | SRC | DEST | D(hrs)| DISTANCE |");
        printf("\n---------------------------------------------------------------------\n");
        while (p != NULL)
        {
            if (strstr(p->train_det, v) && strstr(p->train_det, "\n"))
            {
                printf("   %s", p->train_det);
                flag = 1;
            }
            p = p->next;
        }
        printf("\n\n");
        if (flag == 0)
        {
            printf("No train found for the given source and destination");
            return;
        }
        printf("\n\n\n");
        printf("Select Train Number: ");
        scanf("%d", &a5);
        printf("Total Number Of KM: ");
        scanf("%f", &km);
    }
    else if (choice == 2)
    {
        goto start;
    }
    else if (choice == 3)
    {
        printf("Successfully Cancelled Booking");
        return 0;
    }
    else
    {
        printf("Entered Wrong Choice");
        goto c;
    }
    f1 = 2.0 * km * a2;
    f2 = 1.0 * km * a3;
    f3 = f1 + f2;
    printf("------------------------------------------------------------\n\n");
    printf("Total Fare = %f\n\n\nEnter Your Choice\n1. PAY NOW \n2. Cancel booking \n", f3);
    scanf("%d", &cc);
    if (cc == 1)
    {
        char s[200];
        int len, j;
        fflush(stdin);
        sprintf(s, "%d %d %s %s %s %d %d %d %s %d %s %s %s %s %s %f %f %f\n", a6, a5, v1, v2, v3, a1, a2, a3, v4, a4, v5, v6, v7, v8, v9, f1, f2, f3);
        len = strlen(s);
        strcpy(s, strlwr(s));
        fputs(s, f);
        printf("------------------------------------------------------------");
        printf("\n\nSuccesfully booked ticket, Your Ticket id is %d, please remember this ticket id for further journey\n\n", a6);
        printf("------------------------------------------------------------\n\n");
    }
    if (cc == 2)
    {
        printf("------------------------------------------------------------\n\n");
        printf("Succesfully cancel booking");
        printf("------------------------------------------------------------\n\n");
    }
    fclose(f);
}

// int main()
// {
//     int choice;
//     do
//     {
//         printf("-------------------WELCOME TO TICKET PORTAL-------------------\n\n\n");
//         printf("Enter Your Choice\n1.Ticket Book\n2.Display Ticket\n3.Cancel Ticket\n4.Sort Train\n5.EXIT");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//             system("CLS");
//             book_ticket();
//             printf("Enter Any key to continue");
//             getch();
//             system("CLS");
//             break;
//         case 2:
//             system("CLS");
//             display();
//             printf("Enter Any key to continue");
//             getch();
//             system("CLS");
//             break;
//         case 3:
//             system("CLS");
//             cancel_ticket();
//             printf("Enter Any key to continue");
//             getch();
//             system("CLS");
//             break;
//         case 4:
//             system("CLS");
//             //	sort_train();
//             printf("Enter Any key to continue");
//             getch();
//             system("CLS");
//             break;
//         case 5:
//             exit(0);
//             break;
//         default:
//             printf("You Entered Wrong Choice");
//         }
//     } while (choice != 4);
// }
