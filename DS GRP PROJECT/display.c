// displays the menu items
#include "allImports.h"
#include "AdminFile.c"
#include "user.c"
// #include "ticket.c"
void displayLogin()
{
    int choice;
    bool chr = true;
    while (chr)
    {
        system("CLS");
        printf("\n");
        int u_count;
        u_count = 0;
        printf("\n");
        while (u_count <= 60)
        {
            printf("-");
            usleep(5000);
            u_count++;
        }
        printf("\n");
        printf("                          1>> Admin\n                          2>> User                        ");
        printf("\n");
        u_count = 0;
        while (u_count <= 60)
        {
            printf("-");
            usleep(5000);
            u_count++;
        }
        printf("\n");
        // puts("");
        scanf("%d", &choice);
        if (choice == 2)
        {
            int ch1;
            char u[100];
            strcpy(u, user());
            printf("Welcome, %s!!!\n", u);
            // printf("MENU\n");
            int u_count;
            u_count = 0;
            printf("\n");
            while (u_count <= 60)
            {
                printf("=");
                usleep(5000);
                u_count++;
            }
            printf("\n");
            printf("1. Book Ticket\n2. Display Ticket\n3. Train Enquiry\n4. Cancel Ticket\n5.Exit");
            printf("\n");
            u_count = 0;
            while (u_count <= 60)
            {
                printf("=");
                usleep(5000);
                u_count++;
            }
            printf("\n");
            scanf("%d", &ch1);
            do
            {
                switch (ch1)
                {
                case 1:
                    book_ticket1();
                    break;
                case 2:
                    display1();
                    break;
                case 3:
                    train_enq1();
                    break;
                case 4:
                    cancel_ticket1();
                    break;
                case 5:
                    break;
                }
                u_count = 0;
            printf("\n");
            while (u_count <= 60)
            {
                printf("=");
                usleep(5000);
                u_count++;
            }
            printf("\n");
            printf("1. Book Ticket\n2. Display Ticket\n3. Train Enquiry\n4. Cancel Ticket\n5.Exit");
            printf("\n");
            u_count = 0;
            while (u_count <= 60)
            {
                printf("=");
                usleep(5000);
                u_count++;
            }
            printf("\n");
                scanf("%d", &ch1);
            } while (ch1 != 5);
            chr = false;
        }
        else if (choice == 1)
        {
            int ch1;
            char ad[100];
            strcpy(ad, admin());
            printf("Welcome, %s!!!\n", ad);
            // printf("MENU\n");
            int u_count;
            u_count = 0;
            printf("\n");
            while (u_count <= 60)
            {
                printf("=");
                usleep(5000);
                u_count++;
            }
            printf("\n");
            printf("1. Book Ticket\n2. Display Ticket\n3. Train Enquiry\n4. Cancel Ticket\n5. Railway Database\n6. Graphical Analysis\n7. Exit");
            printf("\n");
            u_count = 0;
            while (u_count <= 60)
            {
                printf("=");
                usleep(5000);
                u_count++;
            }
            printf("\n");
            scanf("%d", &ch1);
            do
            {
                switch (ch1)
                {
                case 1:
                    system("CLS");
                    book_ticket();
                    printf("Enter Any key to continue");
                    getch();
                    system("CLS");
                    break;
                case 2:
                    system("CLS");
                    display();
                    printf("Enter Any key to continue");
                    getch();
                    system("CLS");
                    break;
                case 3:
                    system("CLS");
                    train_enq();
                    printf("Enter Any key to continue");
                    getch();
                    system("CLS");
                    break;
                case 4:
                    system("CLS");
                    cancel_ticket();
                    printf("Enter Any key to continue");
                    getch();
                    system("CLS");
                    break;
                case 5:
                    do
                    {
                        system("CLS");
                        int i = 0;
                        printf("\n");
                        while (i <= 60)
                        {
                            printf("-");
                            usleep(5000);
                            i++;
                        }
                        printf("\n");
                        // printf("\n--------------------------------------------------------\n");
                        printf("                       RAILWAY DATABASE                     ");
                        // printf("\n--------------------------------------------------------\n\n");
                        i = 0;
                        printf("\n");
                        while (i <= 60)
                        {
                            printf("-");
                            usleep(5000);
                            i++;
                        }
                        printf("\n");
                        printf("\n1.Add trains");
                        usleep(50000);
                        printf("\n2.Delete trains");
                        usleep(50000);
                        printf("\n3.Search trains");
                        usleep(50000);
                        printf("\n4.Modify trains");
                        usleep(50000);
                        printf("\n5.Display trains");
                        usleep(50000);
                        printf("\n6.Back Up");
                        usleep(50000);
                        printf("\n7.Exit\n");
                        usleep(50000);
                        scanf("%d", &choice2);
                        switch (choice2)
                        {
                        case 1:
                            system("CLS");
                            add_train();
                            printf("press any key to continue!!!!\n");
                            getch();
                            break;
                        case 2:
                            system("CLS");
                            delete_train();
                            printf("press any key to continue!!!!\n");
                            getch();
                            break;
                        case 3:
                            system("CLS");
                            search_train();
                            printf("press any key to continue!!!!\n");
                            getch();
                            break;
                        case 4:
                            system("cls");
                            modify_train();
                            printf("press any key to continue!!!!\n");
                            getch();
                            break;
                        case 5:
                            system("CLS");
                            display_train();
                            printf("press any key to continue!!!!\n");
                            getch();
                            break;
                        case 6:
                            system("CLS");
                            backup();
                            printf("press any key to continue!!!!\n");
                            getch();
                            break;
                        case 7:
                            break;
                        default:
                            printf("Enter valid choice\n");
                            break;
                        }
                    } while (choice2 != 7);
                    break;
                case 6:
                    GraphicalAnalysis();
                    break;

                case 7:
                    break;
                default:
                    printf("Enter valid choice\n");
                }
                u_count = 0;
                printf("\n");
                while (u_count <= 60)
                {
                    printf("=");
                    usleep(5000);
                    u_count++;
                }
                printf("\n");
                printf("1. Book Ticket\n2. Display Ticket\n3. Train Enquiry\n4. Cancel Ticket\n5. Railway Database\n6. Graphical Analysis\n7. Exit");
                printf("\n");
                u_count = 0;
                while (u_count <= 60)
                {
                    printf("=");
                    usleep(5000);
                    u_count++;
                }
                printf("\n");
                scanf("%d", &ch1);
            } while (ch1 != 7);
            chr = false;
        }
        else
        {
            printf("Enter Valid Number\n");
        }
    }
}
