#include "type.h"
u16 counter = 0; // number of students, initialy = 0
Student student[MAX_SIZE];

void printMainMenu ()
{
    printf("\nWelocme to students database! :)\n");
    printf("\nEnter 1 to enter as an admin, 2 to enter as a user, 0 to terminate: ");
}
void checkMenuInput(s8* password)
{
    u8 choice;
    while (1)
    {
        u8 ret = scanf("%d",&choice);
        if (ret != 1 || (choice != 1 && choice != 2 && choice != 0))
        {
            printf("Invalid choice!. try again: "); 
            clearInputBuffer();
            continue;
        }
        break;
    }
    if (choice == 1)
        handleAdmin();
    else if (choice == 2)
        handleUser();
    else exit(0);
}
void handleUser()
{
    s16 id;
    u16 idx;
    while (1)
    {
        printf("Enter Student's ID, or 0 to go back: ");
        if ( processID(&id,&idx,1) == 1) break;
    }
}
void handleAdmin ()
{
    u8 choice;
    s8 input_password [10];
    printf("\nEnter admin password or type exit to return to main menu: ");
    while(1)
    {
        s8 ret = scanf("%9s",input_password);
        if (ret != 1)
        {
            printf("Invalid Input!. try again: ");
            continue;
        }
        if (!strcmp(input_password,"exit"))
        {
            return;
        }
        if (strcmp(input_password,PASSWORD))
            printf("Passowrd is incorrect, try again or type exit to return to main menu: ");
        else break;
    }
    while (1)
    {
        printf("\nChoose an operation.\n");
        printf("\n1- Add a student\n");
        printf("2- Edit student's data\n");
        printf("0- return to main menu\n");
        while (1)
        {
            if (scanf("%d",&choice) != 1)
            {
                printf("Invalid Input, try again: ");
                continue;
            }
            //scanf("%*c");
            if (choice == 0 || choice == 1 || choice == 2)
                break;
            printf("Invalid Choide, try again: ");
        }
        if (choice == 1)
            addStudent();
        else if (choice == 2)
        {
            printf("\nPlease Enter Student's ID: ");
            u16 id;
            u16 idx;
            processID(&id,&idx,0);
        }
        else break;
    }

}
void addStudent()
{
    if (counter == MAX_SIZE)
    {
        printf("\nMaximum number of students reached!\n");
        return;
    }
    printf("Enter Student's name: ");
    scanf("%24s",student[counter].name);
    while (1)
    {
        printf("Enter Student's ID: ");
        u8 ret = scanf("%hu",&student[counter].ID);
		if (ret != 1)
		{
			clearInputBuffer();
			printf("Invalid Input!.\n");
			continue;
		}
        if (searchID(student[counter].ID,NULL) == -1)
            break;
        printf("There is a student has this ID already!\n");
    }
    printf("Enter Student's degree in maths: ");
	addDegree(&student[counter].math);
    printf("Enter Student's degree in language: ");
    addDegree(&student[counter].language);
    printf("Enter Student's degree in physics: ");
    addDegree(&student[counter].physics);;
    printf("Enter Student's degree in chemistry ");
    addDegree(&student[counter].chemistry);
    counter++;
    printf("\nStudent's data has been inserted successfully!\n");
}
void showStudentInfo(u16 idx)
{
    printf("\nStudent's name: %s\n",student[idx].name);
    printf("Student's ID: %d\n",student[idx].ID);
    printf("Student's degree in maths: %d\n",student[idx].math);
    printf("Student's degree in language: %d\n",student[idx].language);
    printf("Student's degree in physics: %d\n",student[idx].physics);
    printf("Student's degree in chemistry: %d\n",student[idx].chemistry);

}
void editStudent(u16 idx)
{
    u16 choice;
    u16 degree;
    while (1)
    {
        printf("\nWhat Would you like to do ?\n");
        printf("\n1- Edit Math Degree \n");
        printf("2- Edit Language Degree \n");
        printf("3- Edit Physics Degree \n");
        printf("4- Edit Chemistry Degree \n");
        printf("5- Go Back\n");
        while (1)
        {
            u8 ret = scanf("%hu",&choice);
			if (ret != 1)
			{
				printf("Invalid Input!. try again: "); 
				clearInputBuffer();
				continue;
			}
            if (choice == 1)
            {
                printf("Enter the new degree: ");
				editDegree(&student[idx].math);
                break;
            }
            else if (choice == 2)
            {
                printf("Enter the new degree: ");
                editDegree(&student[idx].math);
                break;
            }
            else if (choice == 3)
            {
                printf("Enter the new degree: ");
                editDegree(&student[idx].math);
                break;
            }
            else if (choice == 4)
            {
                printf("Enter the new degree: ");
                editDegree(&student[idx].math);
                break;
            }
            else if (choice == 5) break;
            else if (choice > 5 || choice < 1) printf("Invalid Choice, try again: ");
        }
        if (choice == 5) break;
    }
}
s8 setID(u16* id, u16* idx)
{
    s16 tmp;
    s8 ret = scanf("%hd",&tmp);
    if (ret != 1 || tmp < 0)
    {
        clearInputBuffer();
        return -2;
    }
    *id = tmp;
    if (*id == 0) return 0;
    return searchID(*id, idx);
}
s8 searchID (u16 id, u16* idx)
{
    for (u16 i = 0; i < counter; i++)
    {
        if (id == student[i].ID)
        {
            if (idx)
                *idx = i;
            return 1;
        }
    }
    return -1;
}
u8 processID(u16* id, u16* idx, u8 flag)
{
    while (1)
    {
        s8 ret = setID(id,idx);
        if (ret == -2)
            printf("Invalid input!. try again or type 0 to go back: ");
        else if (ret == -1)
            printf("The ID was not found!. try again or type 0 to go back: ");
        else if (ret == 0) return 1;
        else
        {
            showStudentInfo(*idx);
            if (!flag) editStudent(*idx);
            break;
        }
    }
    return 0;
}
void clearInputBuffer()
{while (getchar() != '\n');}
void editDegree(u16* degree)
{
	while (1)
	{
		u8 ret = scanf("%hu",degree);
		if (ret != 1){
		clearInputBuffer();
		printf("Invalid Input, try again: ");
		continue;}
		if (*degree < 0 || *degree > 100)
			printf("Degree must be within range 0 to 100!. try again: ");
		else break;
	}
    printf("Degree has successfully been modified!\n");
}
void addDegree(u16* degree)
{
	while (1)
	{
		u8 ret = scanf("%hu",degree);
		if (ret != 1){
		clearInputBuffer();
		printf("Invalid Input, try again: ");
		continue;}
		if (*degree < 0 || *degree > 100)
			printf("Degree must be within range 0 to 100!. try again: ");
		else break;
	}
}
