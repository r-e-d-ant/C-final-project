
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


/* record Patient function */

void recordPatient()
{
	FILE *fptr;

	// Ask for patient information
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

	// --------------------------------------

	/* Open and append new record into the file */

	// Open the file
	fptr = fopen("patient_appointment_records.txt", "a");

	// Appeding into the file
	fprintf(fptr, "%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);

	fclose(fptr); // close the file

	printf("\nPatient recorded succesfuly!\n"); // Inform that the record is added.
}

// Display all patients function
void displayPatients()
{
	FILE *fptr;

	fptr = fopen("patient_appointment_records.txt", "r"); // open the file in read mode

	printf("\nPatients records:\n\n");

	// Read the file then print the result
	while(!feof(fptr)) {
		// reading the file
		fscanf(fptr, "%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);

		// printing the result
		printf("%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);
	}

	fclose(fptr);
}

// Update patient function
void updatePatient()
{
	FILE *fptr;
	FILE *fptrUpdate;

	char toSearchId[20]; // to store an id to update
	int found = 0; // this var will get 1 if the id is found otherwise it will stay as zero

	// Ask for patient id
	printf("\nEnter patient\n");
	printf("National ID: ");
	scanf("%s", toSearchId);
	// ---------------

	printf("\nSearching patient with national ID: %s ...", toSearchId); // show the entered Id

	fptr = fopen("patient_appointment_records.txt", "r"); // open main file
	fptrUpdate = fopen("temp.txt", "a"); // open temporary file to store an updated infos.

	while(!feof(fptr)) {
		// scan the main file
		fscanf(fptr, "%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);

		/*
		check if the entered id to update match with any in the file
		if yes inform that the Id is available
		and ask for new infos for that patient
		*/
		if(strcmp(p.Id, toSearchId) == 0) {
			found = 1;// if available pass one to found variable

			printf("\n\nPatient found!\n\n");
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
		// adding the updated infos in the temporary file
		fprintf(fptrUpdate, "%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);
	}

	// close main and temporary file
	fclose(fptr);
	fclose(fptrUpdate);

	/* if the Id have been found */
	if(found == 1) {
		/*
			open again temporary file and main file
			to copy from temporary file to the main patients file
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

	// after completing all the process delete the temporary file
	remove("temp.txt");

	// close again main and temporary file
	fclose(fptr);
	fclose(fptrUpdate);
}

// Search one patient function
void searchPatient()
{
	FILE *fptr;

	char toSearchId[20]; // to store an id to update
	int found = 0; // this var will get 1 if the id is found otherwise it will stay as zero

	// Ask for patient id
	printf("\nEnter patient\n");
	printf("National ID: ");
	scanf("%s", toSearchId);
	// -----------------

	printf("\nSearching patient with national ID: %s ...\n\n", toSearchId); // show the entered Id

	fptr = fopen("patient_appointment_records.txt", "r"); // open main file

	while(!feof(fptr)) {
		// reading the file
		fscanf(fptr, "%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);

		// check if entered ID is available then print it
		if(strcmp(p.Id, toSearchId) == 0) {
			found = 1; // if available pass one to found variable
			printf("%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);
		}
	}

	// if the Id not available
	if(found == 0) {
		printf("\nId with %s not found check spelling\n", toSearchId);
	}

	fclose(fptr);
}

// Delete patient function
void deletePatient()
{
	FILE *fptr;
	FILE *fptrNewRecord;

	char toSearchId[20]; // to store an id to update
	int found = 0; // this var will get 1 if the id is found otherwise it will stay as zero

	// Ask for patient id
	printf("\nEnter patient\n");
	printf("National ID: ");
	scanf("%s", toSearchId);
	// -----------------

	printf("\nSearching patient with national ID: %s ...", toSearchId); // show the entered Id

	fptr = fopen("patient_appointment_records.txt", "r"); // open main file

	while(!feof(fptr)) {
		// scan the file
		fscanf(fptr, "%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);

		// check if the entered id is available
		if(strcmp(p.Id, toSearchId) == 0) {
			found = 1; // if available pass one to found variable

			/* inform that it is found and print all infos about it */

			printf("\nPatient found!\n"); // inform that is found

			// print all the infos about it
			printf("%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);

			printf("\nDeleting patient...\n"); // simulate deletion
		}
	}

	fclose(fptr); // close the main file

	/*
		If found is 1 which mean the id have been found
		open the main file in readmode and temporary file in append mode
		to store updated records without the one with that Id
	*/

	if(found == 1) {
		fptr = fopen("patient_appointment_records.txt", "r"); // open main file
		fptrNewRecord = fopen("tempNewRecord.txt", "a"); // open the temporary file

		while(!feof(fptr)) {
			// scan the records
			fscanf(fptr, "%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);

			// Append each record into the temporary file if the Id is not matching with the one found.
			if(strcmp(p.Id, toSearchId) != 0) {
				fprintf(fptrNewRecord, "%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);
			}
		}

		// remove the main file
		remove("patient_appointment_records.txt");

		// rename the temporal file to the name of the main file
		rename("tempNewRecord.txt", "patient_appointment_records.txt");

		printf("\nPatient deleted succesfuly!\n"); // inform the deletion of the patient
	} else {
		printf("\nId with %s not found check spelling\n", toSearchId);
	}

	// close again the opened files
	fclose(fptr);
	fclose(fptrNewRecord);
}

// Main function
int main()
{
	int c; // to store choice type
	c = 0;

	printf("\n========================================");
	printf("\n| PATIENT APPOINTMENT TO DOCTOR SYSTEM |\n");
	printf("========================================\n");

	do
	{
		printf("\nEnter:\n[1]. Record\n[2]. Display\n[3]. Update\n[4]. Search\n[5]. Delete\n[0]. Exit\n: > ");
		scanf("%d", &c);

		/* Switch between choices and call the function based on the choice */
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




