#include <stdio.h>
#include <stdlib.h>


/* structured type definition */
typedef struct kid_type_tag
{
char name[20];
char surname[20];
int age;
float height;
char school[20];
char sibling[20];
int price;
}  kid_type;


/* declarations */

/* function that reads data from a file, stores it in an array and returns the number of records read*/
int read_records (char*file_name, kid_type kids[]);
/*given the array with stud info and stores the results in the same array in order to calcualte  the tax */
void apply_discount (kid_type kids[], int norecs);
/*scan for the name of the kid and display the result. Also ask if it will go to swimming and movie if it is the case */
void scan(kid_type kids[],char name[],char answer_1[],char answer_2[], int norecs);
/*check for all students which have the same first letter in name as the letter introduced form keyboard*/
void char_letter(kid_type kids[],char letter[],int norecs, char answer_1[],char answer_2[]);
/*Convert the answers to "y" and " "*/
void convert(kid_type kids[], int norecs, char letter[],char answer_1[],char answer_2[]);
/*write the file, using the name given by user*/
void write_kids (char* file_name,kid_type kids[], int norecs);



/* main function */
int main()
{

/* 1-dimensional array that stores dog-related data for all dogs in the store*/
kid_type kids[1000];


/* no current registered dogs (no records) */
int norecs = 0,norecs_b,norecs_g,change, answer;
int i, records=0,p,r;
char answer_1[20],answer_2[20];
/* file name */
char file[20], name[20];
char letter[20];

/* welcome message */
	printf("Welcome to the X-MAX 5000!\n");

	do
   {
	printf("MENU\n");
	printf("Read Files and display there inputs     {1}\n");
	printf("Calculate the tax                       {2}\n");
	printf("Search for a name                       {3}\n");
	printf("Search for the fist letter of name      {4}\n");
	printf("Save the file                           {5}\n");
	printf("Exit the program                        {6}\n");
    printf("Enter your choice:\n");
    scanf("%d", &answer);

	switch(answer)
{
/* read the files*/
case 1:
    if(records <1)/*it will not allow to read the files more than one time */
        {
printf("Enter the input file name:\n");
norecs_g = read_records("girls.txt", kids);/*record the first file*/
norecs= read_records("boys.txt", kids);/*record the second file*/


/*print the inputs*/
for(i=0;i<norecs;i++){
if(i<norecs_g) /*if i is smaller than the norecs_g will display the gender*/
    {
    printf("|girl|");
}
else/*when the i is biger than norece_g, change the hander to boys*/
{
    printf("|boy|");
}
/*print the inputs*/
    printf("%s %s %d %f %s %s\n", kids[i].name, kids[i].surname,
kids[i].age, kids[i].height, kids[i].school, kids[i].sibling);

}
records++;/*record the number of reads*/
	break;
    }
    else/*stop the user to read the files more than one time */
        {
        printf("The files are already read!\n\n");/*Error message*/
    };

break;

case 2:
/* applies tax calculation */
apply_discount(kids, norecs);

    break;
case 3:
/*search for the mane */
printf("Enter the name\n");
scanf("%s", name);/*introduce the name form the keyboard */
/* print results */
scan(kids, name,answer_1,answer_2, norecs);

	break;
case 4:
/*Print all results with star with the same letter*/
    printf("Enter the letter\n");
    scanf("%s", letter);/*introduce the letter form the keyboard */
    char_letter(kids,letter,norecs,answer_1,answer_2);
    break;
case 5:
    /*write the files  */
    printf("Enter the input file name:\n");
scanf("%s", file);/*introduce the name of file form the keyboard */
/* read records */
write_kids(file, kids,norecs);
	break;
case 6:
    /*Exit program */
	printf("Goodbye!\n");
		break;
}
   }while (answer != 6); /*if it is introduce a number smaller than 6, repeat*/


return (EXIT_SUCCESS);
}

/* function definitions */

int read_records (char*file_name, kid_type kids[])
{
	FILE* fp;
	int norecs,p=0,r=0;
    char ch;
	/* open file */
	fp = fopen(file_name, "r");

	while(!feof(fp))/*read till you reach the end of the file  */
{
	/* read on record from file */
 	fscanf(fp, "%s%c%s%c%d%c%f%c%s%c%s",
kids[norecs].name, &ch,
kids[norecs].surname, &ch,
&kids[norecs].age, &ch,
&kids[norecs].height, &ch,
kids[norecs].school, &ch,
kids[norecs].sibling, &ch);
/* increase the number of records read */
norecs++;
}
/* close file */
fclose(fp);
return norecs;

}


/*calculate the tax */
void apply_discount (kid_type kids[], int norecs)
{
	int i;

/* apply the calculation for the tax  */
	for (i = 0; i < norecs; i++)
{   kids[i].price=80;

    if (strcmp(kids[i].sibling, "yes" )==0){
        kids[i].price=kids[i].price-15;}

    if  (kids[i].age<=12)
    {
        kids[i].price=kids[i].price+5;
    }
    if (kids[i].height>100){
        kids[i].price=kids[i].price+10;}
    }
 	}

/*search for kid name */
void scan(kid_type kids[],char name[],char answer_1[],char answer_2[], int norecs)
{
    int i;
    /*Head of the table */
    for (i = 0; i < norecs; i++)
    {
	if (strcmpi(kids[i].name, name)==0 )/*check each name for a match */
        {
{
/*if the kid is taller than 1m, ask if he will swim */
if(kids[i].height>100.0){
printf("Will go swimming?");
scanf("%s", answer_1); /*record the answer */
}
/*if the kid is younger than 12 years old ask if he wants to go to movie*/
if(kids[i].age<=12){
printf("Will go see a movie ?");
scanf("%s", answer_2);/*record the answer*/
}
        /*Calculate the prices respecting the answers*/
        if (strcmpi(answer_1,"no")==0)
    {
        kids[i].price=kids[i].price-10;
    }
    if (strcmpi(answer_2,"no")==0)
    {
        kids[i].price=kids[i].price-5;
    }
        }
    printf("| name | surname | age | height | school | sibling | cost | \n");
    /*print the results*/
      printf("| %s |  %s  |  %d  |%.2f  | %s   |%s   |%d  |\n", kids[i].name, kids[i].surname,
kids[i].age, kids[i].height, kids[i].school, kids[i].sibling, kids[i].price);
break;
    }
    }
    /*Error message if a name is not in the base date */
    if (strcmpi(kids[i].name, name)!=0 )/*check each name for a match */
        printf("The name is not found\n\n ");

    }

/*Check of the first letter match  */
void char_letter(kid_type kids[],char letter[],int norecs, char answer_1[], char answer_2[]){
int i;

    printf("| name | surname | age | height | gomovie | goswim | sibling |\n");
    for (i = 0; i < norecs; i++){
   if (kids[i].name[0]==letter[0])/*Print all the results which start with the same letter*/

    {
        /*Convert the answers to display "y"  and " " */
    convert(kids, norecs, letter, answer_1,answer_2);
   /*Print the table */
     printf("| %s | %s | %d  | %.2f |    %s     |    %s    |    %s    |\n", kids[i].name, kids[i].surname,
kids[i].age, kids[i].height,answer_1,answer_2,kids[i].sibling);

   }
    else{
        printf("No match found\n\n");
    }
   }
   }




/*Convert the answers */
void convert (kid_type kids[], int norecs, char letter[],char answer_1[], char answer_2[])
{   int i;
	for (i = 0; i < norecs; i++){
    if (strcmp(kids[i].sibling, "yes")==0)/*If the answers will be yes , change it to "y"*/{
        strncpy(kids[i].sibling,"y", sizeof (kids[i].sibling));

    }
    if (strcmp(kids[i].sibling, "no")==0)/*If the answers will be yes , change it to " "*/
        {
        strncpy(kids[i].sibling," ", sizeof (kids[i].sibling));
        }

    if (strcmp(answer_1, "yes")==0){
        strncpy(answer_1,"y", sizeof (answer_2));
    }
    if (strcmp(answer_1, "no")==0){
        strncpy(answer_1," ", sizeof (answer_2));
    }

    if (strcmp(answer_2, "yes")==0){
        strncpy(answer_2,"y", sizeof (answer_2));
    }if (strcmp(answer_2, "no")==0){
        strncpy(answer_2," ", sizeof (answer_2));
    }
}
}

/*Write the files, with the name inputed by user*/
void write_kids (char* file_name,
kid_type kids[], int norecs)
{
	FILE* fp;
int i;

	/* open file */
	fp = fopen(file_name, "w");

fprintf(fp,"| name | surname | age | height | school | cost \n");

	for (i = 0; i < norecs; i++){
	/* read on record from file */

fprintf(fp,"%s %s %d %f %s %d\n", kids[i].name, kids[i].surname,
kids[i].age, kids[i].height, kids[i].school, kids[i].price);

	}
/* flush content into file */
fflush(fp);

/* close file */
fclose(fp);
}

