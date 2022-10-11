// #include "RailwayDatabase.c"
#include "ticket.c"

const char *sub(char *st)
{
    int count = 0;
    char *n;
    char st1[100], st2[100];
    strcpy(st1, st);
    // printf("%s\n", st1);
    int i;
    for (i = 0; i < strlen(st1); i++)
    {
        if (st1[i] == ' ')
        {
            count++;
        }
        if (count == 5)
        {
            break;
        }
    }
    int j, k;
    for (j = i + 1, k = 0; st1[j] != ' '; j++, k++)
    {
        // printf("%c ", st1[j]);
        st2[k] = st1[j];
    }
    st2[k] = '\0';
    n = strdup(st2);
    printf("!%s\n", n);
    return n;
}

void GraphicalAnalysis()
{
    char *s1, *s2, *s3, *s4, s[100];
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    printf("\n\nEnter the Source1:\t");
    fflush(stdin);
    gets(s);
    s1 = strdup(s);
    // puts(s1);
    int l = strlen(s1), j;
    for (j = 0; j < l; j++)
    {
        s1[j] = tolower(s1[j]);
    }
    printf("\n\nEnter the Source2:\t");
    fflush(stdin);
    gets(s);
    s2 = strdup(s);
    l = strlen(s2);
    for (j = 0; j < l; j++)
    {
        s2[j] = tolower(s2[j]);
    }
    printf("\n\nEnter the Source3:\t");
    fflush(stdin);
    gets(s);
    s3 = strdup(s);
    l = strlen(s3);
    for (j = 0; j < l; j++)
    {
        s3[j] = tolower(s3[j]);
    }
    printf("\n\nEnter the Source4:\t");
    fflush(stdin);
    gets(s);
    s4 = strdup(s);
    l = strlen(s4);
    for (j = 0; j < l; j++)
    {
        s4[j] = tolower(s4[j]);
    }
    read_database();
    p = ptr;
    while (p != NULL)
    {
        char *s;
        char *string = sub(p->train_det);
        if (strcmp(string, s1) == 0)
            count1++;
        if (strcmp(string, s2) == 0)
            count2++;
        if (strcmp(string, s3) == 0)
            count3++;
        if (strcmp(string, s4) == 0)
            count4++;
        p = p->next;
    }
    // printf("$1%d $2%d $3%d $4%d\n",count1,count2,count3,count4);
    int g[5], i;
    g[0] = count1;
    g[1] = count2;
    g[2] = count3;
    g[3] = count4;
    printf("\n\n\n\t\t\t\tBAR GRAPH\t\n");
    printf("\n\t\t|\n\t\t|\n\t\t");
    for (i = 0; i < count1; i++)
    {
        printf("|||||");
    }
    printf("|");
    printf("\t%s\t%d", s1, count1);
    printf("\n\t\t|\n\t\t|\n\t\t");
    for (i = 0; i < count2; i++)
    {
        printf("|||||");
    }
    printf("|");

    printf("\t%s\t%d", s2, count2);
    printf("\n\t\t|\n\t\t|\n\t\t");
    for (i = 0; i < count3; i++)
    {
        printf("|||||");
    }
    printf("|");

    printf("\t%s\t%d", s3, count3);
    printf("\n\t\t|\n\t\t|\n\t\t");
    for (i = 0; i < count4; i++)
    {
        printf("|||||");
    }
    printf("|");

    printf("\t%s\t%d", s4, count4);

    printf("\n\t\t|");
    printf("\n---------------------------------------------------------------------------------------------------------------------");
}

void train_enq()
{
    read_database();
    int flag = 0;
    char source[100], destination[100], srcdest[100];
    char *s, *d;
    printf("-------------------------------------------------------------------------\n");
    printf("			TRAIN ENQUIRY					\n");
    printf("-------------------------------------------------------------------------\n\n");
    printf("enter your source:");
    fflush(stdin);
    gets(source);
    strlwr(source);
    printf("enter your destination:");
    fflush(stdin);
    gets(destination);
    strlwr(destination);
    sprintf(srcdest, "%s %s", source, destination);
    p = ptr;
    if (p == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("\n-----------------------------------------------------------------------------------------------------------------------\n");
        printf("Train No|| Train Name || Date || Arr. time(Hrs) || Dept. time(Hrs) ||  Source  || Destination || Duration || Distance");
        printf("\n-----------------------------------------------------------------------------------------------------------------------\n   ");
        while (p != NULL)
        {
            if (strstr(p->train_det, srcdest) && strstr(p->train_det, "\n"))
            {
                printf("	%s", p->train_det);
                flag = 1;
            }
            p = p->next;
        }
        printf("\n\n");
        if (flag == 0)
        {
            printf("No trains found for given Source & Destination!\n");
        }
    }
}