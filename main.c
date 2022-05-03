

#include<stdio.h>
#include<string.h>

// =================== 

/* Functions declation
there are not necessary if the functions are at the top of the main function (which is the case)
so You can remove them if you want */

void recordPatient();
void displayPatients();
void updatePatient();
void searchPatient();
void deletePatient();

// ===================== 

/*
Structure Patient declare as array of 5 length
*/
struct Patient
{
	char name[30], date[20], email[30];
	int phone_no;
} p[5];

// tot variable to keep track of the amount of the patient
int tot = 0;

// Main function
int main()
{
	int c;
	c = 0;

	do
	{
		printf("\nEnter:\n[1]. Record\n[2]. Display\n[3]. Update\n[4]. Search\n[5]. Delete\n[0]. Exit\n: > ");
		scanf("%d", &c);
		switch(c)
		{
			case 1:
				recordPatient();
				break;
			case 2:
				displayPatients();
				break;
			case 3:
				updatePatient();
				break;
			case 4:
				searchPatient();
				break;
			case 5:
				deletePatient();
				break;
			case 0:
				printf("\nThank you!");
				break;
			default:
				printf("\nChoice must be 0, 1, 2, 3, 4, or 5.");
		}
	} while(c != 0);

	printf("\n");
}



// record Patient function
void recordPatient()
{
	printf("\nEnter \n");

	printf("\nName: ");
	scanf("%s", p[tot].name);

	printf("\nDate (format: [dd/mm/22]): ");
	scanf("%s", p[tot].date);

	printf("\nEmail: ");
	scanf("%s", p[tot].email);

	printf("\nPhone no (ex: 25078xxxxxx): ");
	scanf("%d", &p[tot].phone_no);

	tot++; // increase the amount of the patient when one patient is added
}

// Display all patients function
void displayPatients()
{

	int i;

	printf("\nPatients records:\n");
	printf("\nName\t\t\t\tDate\t\t\tEmail\t\t\t\tPhone\n=======\t\t\t\t======\t\t\t=======\t\t\t\t========\n");

	for(i = 0; i < tot; i++) {
		printf("%s\t\t\t\t%s\t\t\t%s\t\t\t\t%d\n", p[i].name, p[i].date, p[i].email, p[i].phone_no);
	}
}

// Update patient function
/*
In this function there is new functions (pName, newSex, and newAge) to store
entered new data of the patient and we will use them to replace the ones which are
already entered.

1st we check if the name is available
if not we pass 1 to found variable
if the patient is available
we we will display his datas then update them
*/
void updatePatient()
{
	char pName[30], newDate[20], newEmail[30];
	int i, newPhone_no, found=0;

	printf("Enter patient Name: ");
	scanf("%s", pName);

	for(i = 0; i < tot; i++) {
		if(strcmp(p[i].name, pName) == 0) {
			found = 1; // we pass one when the name is found

			printf("\nOld data: \n");

			printf("\nName\t\t\t\tDate\t\t\tEmail\t\t\t\tPhone\n=======\t\t\t\t======\t\t\t=======\t\t\t\t========\n");
			printf("%s\t\t\t\t%s\t\t\t%s\t\t\t\t%d\n", p[i].name, p[i].date, p[i].email, p[i].phone_no);

			// inserting new data
			printf("\nEnter new \n");

			printf("\nName: ");
			scanf("%s", pName);
			// replace entered name
			strcpy(p[i].name, pName);

			// ------====------------

			printf("\nDate (format: [dd/mm/22]): ");
			scanf("%s", newDate);
			// replace entered Date
			strcpy(p[i].date, newDate);

			// ------====------------

			printf("\nEmail: ");
			scanf("%s", newEmail);
			// replace entered email
			strcpy(p[i].email, newEmail);

			// ------====------------

			printf("\nPhone no (ex: 25078xxxxxx): ");
			scanf("%d", &newPhone_no);
			// replace entered new phone number
			p[i].phone_no = newPhone_no;

		}
	}
	// if found is still zero we tell the user that the name is not available
	if(found == 0) {
		printf("Patient with name %s not found! Try again", pName);
	}
}

// Search one patient function
void searchPatient()
{
	char pName[20];
	int i, found=0;

	printf("Enter patient Name: ");
	scanf("%s", pName);

	for(i = 0; i < tot; i++) {
		if(strcmp(p[i].name, pName) == 0) {
			found = 1; // we pass one when the name is found

			printf("\nName\t\t\t\tDate\t\t\tEmail\t\t\t\tPhone\n=======\t\t\t\t======\t\t\t=======\t\t\t\t========\n");
			printf("%s\t\t\t\t%s\t\t\t%s\t\t\t\t%d\n", p[i].name, p[i].date, p[i].email, p[i].phone_no);
		}
	}

	// if found is still zero we tell the user that the name is not available
	if(found == 0) {
		printf("Patient with name %s not found! Try again", pName);
	}

}

// Delete patient function
// Still don't know how to delete
void deletePatient()
{
	char pName[20];
	int i, found=0;

	printf("Enter patient Name: ");
	scanf("%s", pName);

	for(i = 0; i < tot; i++) {
		if(strcmp(p[i].name, pName) == 0) {
			found = 1;
			printf("\nOops!\n");
			printf("The patient is inside and the program can't remove him/her\n");

		}
	}

	if(found == 0) {
		printf("Patient with name %s not found! Try again", pName);
	}

}




