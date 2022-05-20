
#include <stdio.h>
#include <string.h>

// ================

/*
Structure Patient
*/
struct Patient
{
	char Id[20], Fname[30], Lname[30], appointmentDate[20], phone_no[20];
} p;


// record Patient function
void recordPatient()
{
	FILE *fptr;

	printf("\nEnter \n");

	printf("\nNational ID: ");
	scanf("%s", p.Id);

	printf("\nFirst name: ");
	scanf("%s", p.Fname);

	printf("\nLast name: ");
	scanf("%s", p.Lname);

	printf("\nAppointment date (format: [dd/mm/yy]): ");
	scanf("%s", p.appointmentDate);

	printf("\nPhone no (ex: 25078xxxxxx): ");
	scanf("%s", p.phone_no);

	fptr = fopen("patient_appointment_records.txt", "a");
	fprintf(fptr, "%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);

	fclose(fptr);
}

// Display all patients function
void displayPatients()
{
	FILE *fptr;

	fptr = fopen("patient_appointment_records.txt", "r");

	printf("\nPatients records:\n");

	while(!feof(fptr)) {
		fscanf(fptr, "%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);
		printf("%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);
	}

	fclose(fptr);
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
	FILE *fptr;
	FILE *fptrUpdate;

	char toSearchId[20];
	int found = 0;

	printf("\nEnter patient\n");
	printf("National ID: ");
	scanf("%s", toSearchId);

	printf("\nSearching patient with national ID: %s ...", toSearchId);

	fptr = fopen("patient_appointment_records.txt", "r");
	fptrUpdate = fopen("temp.txt", "a");

	while(!feof(fptr)) {
		fscanf(fptr, "%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);

		if(strcmp(p.Id, toSearchId) == 0) {
			found = 1;
			printf("\n\nPatient found! \n");
			printf("%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);
			printf("\nEnter new:\n");

			printf("\nNational ID: ");
			scanf("%s", p.Id);

			printf("\nFirst name: ");
			scanf("%s", p.Fname);

			printf("\nLast name: ");
			scanf("%s", p.Lname);

			printf("\nAppointment date (format: [dd/mm/yy]): ");
			scanf("%s", p.appointmentDate);

			printf("\nPhone no (ex: 25078xxxxxx): ");
			scanf("%s", p.phone_no);
		}
		// adding new data in the temporary file
		fprintf(fptrUpdate, "%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);
	}

	fclose(fptr);
	fclose(fptrUpdate);

	if(found == 1) {
		/*
			open again temporary file and main file
			to copy from temporary file to the main patients family
		*/
		fptrUpdate = fopen("temp.txt", "r");
		fptr = fopen("patient_appointment_records.txt", "w");

		printf("\nUpdating...\n");

		while(!feof(fptrUpdate)) {
			// read from temporary file
			fscanf(fptrUpdate, "%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);
			// overwrite it to the main file
			fprintf(fptr, "%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);
		}

		printf("\nPatient updated succesfuly!\n");
		
	} else {
		printf("\nId with %s not found check spelling\n", toSearchId);
	}
	remove("temp.txt");

	fclose(fptr);
	fclose(fptrUpdate);
}

// Search one patient function
void searchPatient()
{
	FILE *fptr;

	char toSearchId[20];
	int found = 0;

	printf("Enter patient\n");
	printf("National ID: ");
	scanf("%s", toSearchId);

	printf("\nSearching patient with national ID: %s ...", toSearchId);

	fptr = fopen("patient_appointment_records.txt", "r");

	while(!feof(fptr)) {
		fscanf(fptr, "%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);

		if(strcmp(p.Id, toSearchId) == 0) {
			found = 1;
			printf("%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);
		}
	}

	if(found == 0) {
		printf("\nId with %s not found check spelling\n", toSearchId);
	}

	fclose(fptr);
}

// Delete patient function
// Still don't know how to delete
void deletePatient()
{
	printf("Will delete later!");
}

// Main function
int main()
{
	int c;
	c = 0;

	printf("\n========================================");
	printf("\n| PATIENT APPOINTMENT TO DOCTOR SYSTEM |\n");
	printf("========================================\n");

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




