#include "allImports.h"
bool strongPassword();
// Global Variables
bool accessRights = false;
int i;

FILE *pt;

const char *user()
{
    bool flag = false, pswd = true, lgn = true;
    int choice;
    char ch, *ID;
    fflush(stdin);
    printf("Sign Up\n");
    puts("1. Sign Up\n2. Login");
    scanf("%d", &choice);
    system("cls");
    if (choice == 1)
    {
        char str[200], id[100], pass[100];
        int d = 0, u = 0, l = 0, s = 0, k;
        pt = fopen("user.txt", "a");
        puts("Enter Your Username");
        scanf("%s", id);
        while (pswd)
        {
            system("cls");
            puts("Enter Your Username");
            printf("%s\n", id);
            puts("Enter your password");
            for (i = 0; i < 100; i++)
            {
                ch = getch();
                if (ch == 13)
                {
                    pass[i] = '\0';
                    pswd = strongPassword(id, pass);
                    break;
                }
                if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '@' || ch == '!' || ch == '#' || ch == '$' || ch == '&' || ch == '*' || ch == 8)
                {
                    if (ch == 8)
                    {
                        i = i - 2;
                        system("cls");
                        puts("Enter Your Username");
                        printf("%s\n", id);
                        puts("Enter your password");
                        for (k = 0; k < i + 1; k++)
                            printf("*");
                    }
                    else
                    {
                        pass[i] = ch;
                        printf("%c", pass[i]);
                        usleep(150000);
                        system("cls");
                        puts("Enter Your Username");
                        printf("%s\n", id);
                        puts("Enter your password");
                        ch = '*';
                        printf("*");
                        for (k = 0; k < i; k++)
                            printf("*");
                    }
                }
                else
                {
                    i--;
                }
            }
        }
        strcpy(str, id);
        strcat(str, " ");
        strcat(str, pass);
        strcat(str, "\n");
        fprintf(pt, "%s", str);
        choice = 2;
        fclose(pt);
        printf("Successfully Signed In\n");
        printf("Redirecting to Login Portal...\n");
        sleep(2);
        system("cls");
    }
    if (choice == 2)
    {
        printf("LOGIN\n");
        int k, f = 1;
        while (lgn)
        {
            char str[200], id[100], pass[100];
            pt = fopen("user.txt", "r");
            f = 1;
            puts("Enter Your Username");
            scanf("%s", id);
            while (f)
            {
                system("cls");
                puts("Enter Your Username");
                printf("%s\n", id);
                puts("Enter your password");
                for (i = 0; i < 100; i++)
                {
                    ch = getch();
                    if (ch == 13)
                    {
                        pass[i] = '\0';
                        f = 0;
                        break;
                    }
                    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '@' || ch == '!' || ch == '#' || ch == '$' || ch == '&' || ch == '*' || ch == 8)
                    {
                        if (ch == 8)
                        {
                            i = i - 2;
                            system("cls");
                            puts("Enter Your Username");
                            printf("%s\n", id);
                            puts("Enter your password");
                            for (k = 0; k < i + 1; k++)
                                printf("*");
                        }
                        else
                        {
                            pass[i] = ch;
                            printf("%c", pass[i]);
                            usleep(150000);
                            system("cls");
                            puts("Enter Your Username");
                            printf("%s\n", id);
                            puts("Enter your password");
                            ch = '*';
                            printf("*");
                            for (k = 0; k < i; k++)
                                printf("*");
                        }
                    }
                    else
                    {
                        i--;
                    }
                }
                strcpy(str, id);
                strcat(str, " ");
                strcat(str, pass);
                strcat(str, "\n");
                // printf("\n%s\n", str);
                char line[100];
                while (fgets(line, 200, pt))
                {
                    if (strcmp(line, str) == 0)
                    {
                        ID = id;
                        puts("\nLogin successful");
                        sleep(2);
                        system("cls");
                        flag = true;
                        lgn = false;
                        fclose(pt);
                        return ID;
                    }
                }
            }
            if (!flag)
            {
                puts("\nLogin failed");
                // f = 0;
                sleep(2);
                system("cls");
                fclose(pt);
            }
        }
    }
}

const char *admin()
{
    bool flag = false, adminlgn = true, pswd = true;
    int choice, k, f;
    char str[200], ch, *ADMIN;
    pt = fopen("admin.txt", "r");
    while (adminlgn)
    {
        f = 1;
        char id[100], pass[100];
        puts("Login Portal:");
        puts("Enter Your Username ");
        fflush(stdin);
        gets(id);
        puts("Enter Your Password");
        while (f)
        {
            system("cls");
            puts("Enter Your Username");
            printf("%s\n", id);
            puts("Enter your password");
            fflush(stdin);
            for (i = 0; i < 100; i++)
            {
                ch = getch();
                if (ch == 13)
                {
                    pass[i] = '\0';
                    f = 0;
                    break;
                }
                if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9') || ch == '@' || ch == '!' || ch == '#' || ch == '$' || ch == '&' || ch == '*' || ch == 8)
                {
                    if (ch == 8)
                    {
                        i = i - 2;
                        system("cls");
                        puts("Enter Your Username");
                        printf("%s\n", id);
                        puts("Enter your password");
                        for (k = 0; k < i + 1; k++)
                            printf("*");
                    }
                    else
                    {
                        pass[i] = ch;
                        printf("%c", pass[i]);
                        usleep(150000);
                        system("cls");
                        puts("Enter Your Username");
                        printf("%s\n", id);
                        puts("Enter your password");
                        ch = '*';
                        printf("*");
                        for (k = 0; k < i; k++)
                            printf("*");
                    }
                }
                else
                {
                    i--;
                }
            }
        }
        strcpy(str, id);
        strcat(str, " ");
        strcat(str, pass);
        strcat(str, "\n");
        char line[100];
        FILE *pt1 = fopen("admin.txt", "r");
        while (fgets(line, 200, pt1))
        {
            // sscanf(pt,line);
            // printf("%s\n", line);
            // printf("%s %s\n", pass, str);
            if (strcmp(line, str) == 0)
            {
                ADMIN = id;
                puts("\nLogin successful");
                sleep(2);
                system("cls");
                flag = true;
                accessRights = true;
                adminlgn = false;
                return ADMIN;
            }
        }
        if (!flag)
        {
            puts("\nLogin failed");
            sleep(2);
            system("cls");
            flag = true;
            f = 1;
        }
    }
}

bool strongPassword(char id[], char pass[])
{
    int d = 0, u = 0, l = 0, s = 0, i;
    char str[200];
    printf("\n");
    for (i = 0; i < strlen(pass); i++)
    {
        if (isdigit(pass[i]))
            d = 1;
        else if (isupper(pass[i]))
            u = 1;
        else if (islower(pass[i]))
            l = 1;
        else if (pass[i] == '@' || pass[i] == '!' || pass[i] == '#' || pass[i] == '$' || pass[i] == '&' || pass[i] == '*')
            s = 1;
    }

    if (d == 0)
    {
        printf("Please Enter a digit in your password\n");
        sleep(3);
        return true;
    }
    else if (u == 0)
    {
        printf("Please Enter a UpperCase in your password\n");
        sleep(3);
        return true;
    }
    else if (l == 0)
    {
        printf("Please Enter a LowerCase in your password\n");
        sleep(3);
        return true;
    }
    else if (s == 0)
    {
        printf("Please Enter a Special Character in your password\n");
        sleep(3);
        return true;
    }
    else if (strlen(pass) < 8 && strlen(pass) > 20)
    {
        printf("Your password must be in between of 8-20 characters\n");
        sleep(3);
        return true;
    }
    else
        return false;
}