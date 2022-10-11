#include "allImports.h"
struct node
{
	int train_no;
	char *train_name;
	char *date;
	int st_hour;
	int st_min;
	int arr_hour;
	int arr_min;
	char *source;
	char *destination;
	int duration_hour;
	int duration_min;
	float distance;
	// int flag;
	struct node *next;
	char *train_det;
} *head = NULL, *last = NULL, *p, *train, *ptr, *gp = NULL;
int tno, choice, choice2, c = 1;
int s_hour, s_min, a_hour, a_min, dura_hour, dura_min;
float dist;
char tname[100], sou[100], dest[100], dat[100];

void read_database()
{
	ptr = NULL;
	struct node *last;
	last = ptr;
	char str[100];
	int i, filempty = 0;
	FILE *infile = fopen("railway_database.txt", "r");
	fseek(infile, 0, SEEK_END);
	int len = (int)ftell(infile);
	if (len <= 0)
	{
		filempty = 1;
		printf("FILE IS EMPTY!!\n");
		p = NULL;
		//	head=p;
	}
	if (filempty == 0)
	{
		rewind(infile); // sets the file position to the beginning of the file for the stream pointed to by stream
		while (fgets(str, sizeof(str), infile))
		{
			struct node *node;
			node = (struct node *)malloc(sizeof(struct node));
			node->train_det = strdup(str);
			node->next = NULL;
			if (feof(infile))
			{
				break;
			}
			if (last == NULL)
			{
				last = ptr = node;
			}
			else
			{
				last = last->next = node;
			}
		}
		fclose(infile);
	}
}

void time_difference()
{
	if (s_hour > 12 && a_hour < 12)
	{
		dura_hour = 24 - s_hour;
		dura_hour = dura_hour + a_hour;
	}
	else if (a_hour > 12 && s_hour < 12)
	{
		dura_hour = 24 - a_hour;
		dura_hour = dura_hour + s_hour;
	}
	else
	{
		dura_hour = a_hour - s_hour;
	}
	if (a_min > s_min)
	{
		dura_min = a_min - s_min;
	}
	else
	{
		dura_min = s_min - a_min;
	}
}
int add_train()
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
	printf("                          ADD TRAIN                        ");
	printf("\n");
	u_count = 0;
	while (u_count <= 60)
	{
		printf("-");
		usleep(5000);
		u_count++;
	}
	printf("\n");
	// FILE *fq;
	// fq=fopen("railway_database.txt","r");
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	/*if(fq==NULL)
	{
		printf("FILE IS NOT OPENED\n");
	}*/
	int x;
	/*char chr;
	chr=fgetc(fq);
	int i=1;
	while(chr!=EOF)
	{
		if(chr=='\n')
		{
			i=i+1;
		}
		chr=getc(fq);
	}
	fclose(fq);*/
	// int t_flag=1;
	// int i;
	srand((unsigned)time(&t));
	printf("Enter the train details\n");
	tno = rand() % 100000;
	printf("train no: %d\n",tno);
	// scanf("%d",&tno);
	fflush(stdin);
	printf("Train Name: ");
	gets(tname);

	printf("Today's date is: %02d/%02d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
	printf("Train Date: ");
	gets(dat);

	printf("Current time is: %02d:%02d\n", tm.tm_hour, tm.tm_min);
	printf("Train Start time: ");

	scanf("%d:%d", &s_hour, &s_min);
	printf("train Arrival time: ");

	scanf("%d:%d", &a_hour, &a_min);
	fflush(stdin);
	printf("Train Source: ");
	gets(sou);
	printf("Train Destination: ");
	gets(dest);

	printf("Train Distance: ");
	scanf("%f", &dist);
	train = (struct node *)malloc(sizeof(struct node));
	train->train_no = tno;
	train->train_name = strdup(tname);
	train->date = strdup(dat);
	train->st_hour = s_hour;
	train->st_min = s_min;
	train->arr_hour = a_hour;
	train->arr_min = a_min;
	train->source = strdup(sou);
	train->destination = strdup(dest);
	time_difference();
	train->duration_hour = dura_hour;
	train->duration_min = dura_min;
	train->distance = dist;
	// train->flag=t_flag;
	train->next = NULL;

	char str[100];
	int len, j;
	fflush(stdin);
	sprintf(str, "%d %s %s %d:%d %d:%d %s %s %d:%d %.2f\n", train->train_no, train->train_name, train->date, train->st_hour, train->st_min, train->arr_hour, train->arr_min, train->source, train->destination, train->duration_hour, train->duration_min, train->distance);
	// fflush(stdin);
	// puts(str);
	len = strlen(str);
	for (j = 0; j < len; j++)
	{
		str[j] = tolower(str[j]);
	}

	FILE *fp;
	fp = fopen("railway_database.txt", "a");
	// fprintf(fp,"T:%d %s %s %d:%d %d:%d %s %s %d:%d %.2f %d\n",train->train_no,train->train_name,train->date,train->st_hour,train->st_min,train->arr_hour,train->arr_min,train->source,train->destination,train->duration_hour,train->duration_min,train->distance,train->flag);
	fputs(str, fp);
	fclose(fp);
	printf("\nTRAIN IS ADDED SUCCESSFULLY!!!\n");
}
int delete_train()
{
	int j = 0;
	printf("\n");
	while (j <= 60)
	{
		printf("-");
		usleep(5000);
		j++;
	}
	printf("\n");
	printf("                         DELETE TRAIN                       ");
	j = 0;
	printf("\n");
	while (j <= 60)
	{
		printf("-");
		usleep(5000);
		j++;
	}
	printf("\n");
	read_database();
	int t_del, found = 1, len;
	printf("Enter the train no to be deleted: ");
	scanf("%d", &t_del);
	char tno_del[100], chr, str[100];
	sprintf(tno_del, "%d", t_del);
	strcpy(str, "t:");
	strcat(str, tno_del);
	strcat(str, " ");
	len = strlen(str);
	// len=len-1;
	FILE *fp;
	fp = fopen("railway_database.txt", "w");
	// fq=fopen("delete_copy.txt","w");
	p = ptr;
	if (p == NULL)
	{
		printf("LIST IS EMPTY!!\n");
	}
	else
	{
		while (p != NULL)
		{
			// fputs(p->train_det,fq);
			if (strncmp(str, p->train_det, len))
			{
				/*fseek(fq,-3,SEEK_CUR);
				chr=fgetc(fq);
				fputc('0',fq);
				fputc('\n',fq);*/
				found = 0;
				fputs(p->train_det, fp);
			}
			p = p->next;
		}
	}

	fclose(fp);
	// fclose(fq);

	// remove("railway_database.txt");
	// rename("delete_copy.txt","railway_database.txt");
	if (found == 0)
	{
		printf("\nTRAIN IS DELETED SUCCESSFULLY!!!\n");
	}
	else
	{
		printf("\nTRAIN NOT FOUND!!!\n");
	}
}

int search_train()
{
	int j = 0;
	printf("\n");
	while (j <= 60)
	{
		printf("-");
		usleep(5000);
		j++;
	}
	printf("\n");
	printf("                         SEARCH TRAIN                       ");
	j = 0;
	printf("\n");
	while (j <= 60)
	{
		printf("-");
		usleep(5000);
		j++;
	}
	printf("\n");
	read_database();
	int t_find, found = 0, len;
	printf("Enter the train no to be searched");
	scanf("%d", &t_find);
	char tno_find[100], str[100];
	sprintf(tno_find, "%d", t_find);
	strcpy(str, "t:");
	strcat(str, tno_find);
	// strcat(str," ");
	// read_database();
	len = strlen(str);
	p = ptr;
	if (p == NULL)
	{
		printf("LIST IS EMPTY!!\n");
	}
	else
	{
		while (p != NULL)
		{
			if (strncmp(str, p->train_det, len) == 0)
			{
				printf("%s\n", p->train_det);
				found = 1;
			}
			p = p->next;
		}
	}
	if (found == 0)
	{
		printf("SOORY!!TRAIN NOT FOUND\n");
	}
}
int display_train()
{
	int j = 0;
	printf("\n");
	while (j <= 60)
	{
		printf("-");
		usleep(5000);
		j++;
	}
	printf("\n");
	printf("                        DISPLAY TRAINS                      ");
	j = 0;
	printf("\n");
	while (j <= 60)
	{
		printf("-");
		usleep(5000);
		j++;
	}
	printf("\n");
	read_database();
	int i;
	p = ptr;
	if (p == NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else
	{
		printf("\n---------------------------------------------------------------------\n");
		printf("|No| Train name\t    |  DATE | ST| AT | SRC | DEST | D(hrs)| DISTANCE |");
		printf("\n---------------------------------------------------------------------\n");
		do
		{
			/*if(strstr(p->train_det,"1\n"))
			{
				printf("\n%s\n",p->train_det);
			}*/
			printf("\n%s\n", p->train_det);
			p = p->next;
		} while (p != NULL);
	}
	// head=NULL;
}

void ExportDatabase()
{
	read_database();
	FILE *f1 = fopen("railway_database.txt", "r");
	FILE *f = fopen("BackUp.txt", "w");
	p = ptr;
	if (p == NULL)
	{
		printf("List is Empty\n");
		getch();
	}
	else
	{
		char exp[4][100] = {"Exporting Data", "Exporting Data.", "Exporting Data..", "Exporting Data..."};
		for (int i = 0; i < 4; i++)
		{
			printf("%s ", exp[i]);
			sleep(1);
			system("cls");
		}
		while (p != NULL)
		{
			// fprintf(f, "t:%d %s %s %d:%d %d:%d %s %s %d:%d %.2f\n", p->train_no, p->train_name, p->date, p->st_hour, p->st_min, p->arr_hour, p->arr_min, p->source, p->destination, p->duration_hour, p->duration_min, p->distance);
			fputs(p->train_det, f);
			p = p->next;
		}
		// char ch;
		// while ((ch = fgetc(f1)) != EOF){
		// 	printf("%c ", ch);
		// 	fputc(ch, f);
		// }
		printf("Successfully Exported The Data!!!");
		sleep(2);
		fclose(f);
		fclose(f1);
	}
}

void ImportDatabase()
{
	char str[100];
	FILE *import = fopen("BackUp.txt", "r");
	p = NULL;
	last = p;
	int empty = 0;
	fseek(import, 0, SEEK_END);
	if (p == NULL)
	{
		printf("empty");
		sleep(1);
		p = (struct node *)malloc(sizeof(struct node));
		head = p;
	}
	int len = (int)ftell(import);
	printf("%d ", len);
	sleep(1);

	if (len <= 0)
	{
		empty = 1;
		printf("File Is Empty\n");
		p = NULL;
		// head = p;
	}
	if (empty == 0)
	{
		// printf("in if\n");
		rewind(import); // sets the file position to the beginning of the file for the stream pointed to by stream
		while (fgets(str, sizeof(str), import))
		{
			// printf("in while\n");

			struct node *node;
			node = (struct node *)malloc(sizeof(struct node));
			node->train_det = strdup(str);
			// printf("%s\n",node->train_det);

			node->next = NULL;
			if (feof(import))
			{
				break;
			}
			if (last == NULL)
			{
				last = ptr = node;
			}
			else
			{
				last = last->next = node;
			}
		}
		fclose(import);
	}

	FILE *f = fopen("railway_database.txt", "w");
	struct node *temp;
	temp = ptr;
	if (temp == NULL)
	{
		printf("list is empty");
	}
	else
	{
		while (temp != NULL)
		{
			fputs(temp->train_det, f);
			temp = temp->next;
		}
	}
	fclose(f);
	// fclose(import);
}

void backup()
{
	int ch;
	system("cls");
	printf("Enter\n1. Import Database\n2. Export Database\n3. Exit\nEnter Your Choice\n");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
		system("cls");
		ImportDatabase();
		char imp[4][100] = {"Importing Data", "Importing Data.", "Importing Data..", "Importing Data..."};
		for (int i = 0; i < 4; i++)
		{
			printf("%s ", imp[i]);
			sleep(1);
			system("cls");
		}
		printf("Successfully Imported The Data!!!");
		break;

	case 2:
		system("cls");
		ExportDatabase();
		break;

	default:
		printf("Enter Valid Choice\n");
	}
}

void modify_train()
{
	char no[10],mod_train[100];
	read_database();
	display_train();
	printf("Enter Train No. to modify:");
	fflush(stdin);
	gets(no);
	FILE *fp;
	fp=fopen("railway_database.txt","w");
	p=ptr;
	if(p==NULL){
		printf("List is empty");
	}
	else
	{
		while(p!=NULL){
			if(strncmp(no,p->train_det,strlen(no))==0){
				printf("Train_no:%s\n",no);
				printf("Enter the train details:\n");
				fflush(stdin);
				printf("Train name: ");
				gets(tname);
				strlwr(tname);
				printf("Train date: ");
				gets(dat);
				printf("Train start time: ");
				scanf("%d:%d", &s_hour,&s_min);
				printf("Train arrival time: ");
				scanf("%d:%d", &a_hour,&a_min);
				fflush(stdin);
				printf("Train source: ");
				gets(sou);
				strlwr(sou);
				printf("Train destination: ");
				gets(dest);
				strlwr(dest);
				printf("Train distance: ");
				scanf("%f",&dist);
				train=(struct node*)malloc(sizeof(struct node));
				train->train_name=strdup(tname);
				train->date=strdup(dat);
				train->st_hour=s_hour;
				train->st_min=s_min;
				train->arr_hour=a_hour;
				train->arr_min=a_min;
				train->source=strdup(sou);
				train->destination=strdup(dest);
				time_difference();
				train->duration_hour=dura_hour;
				train->duration_min=dura_min;
				train->distance=dist;
				//train->flag=t_flag;
				train->next=NULL;
				fflush(stdin);
				sprintf(mod_train,"%s %s %s %d:%d %d:%d %s %s %d:%d %.2f\n",no,train->train_name,train->date,train->st_hour,train->st_min,train->arr_hour,train->arr_min,train->source,train->destination,train->duration_hour,train->duration_min,train->distance);
				fflush(stdin);
				puts(mod_train);
				strcpy(p->train_det,mod_train);
				fputs(p->train_det,fp);
				printf("TRAIN HAS BEEN MODIFIED\n\n");
			}
			else{
				fputs(p->train_det,fp);
				//printf("train is not modified");
			}
			p=p->next;
		}
	}
	fclose(fp);
}
