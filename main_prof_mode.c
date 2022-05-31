
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
void updatePatient() {
	FILE *fptr;

	char updateKey[20]; // variable to store an id to delete
	struct Patient pat[100]; // structure to store temporal data

	int dataLength = 0, i, found = 0; // dataLength to count items in file an counter i for looping and flag

	fptr = fopen("patient_appointment_records.txt", "r"); // open file in read mode

	// loop in file and store founded data in local structure
	while(!feof(fptr)) {
		fscanf(fptr, "%s\t%s %s\t%s\t%s\n", pat[dataLength].Id, pat[dataLength].Fname, pat[dataLength].Lname, pat[dataLength].appointmentDate, pat[dataLength].phone_no);
		dataLength++; // increase the value in dataLength per data found
	}
	fclose(fptr); // close the file after scaning the data

	// check if file is not empty (if dataLength is equal to zero the file is empty)
	if(dataLength == 0) {
		printf("File is Empty");
	} else {
		// get search key
		printf("\nEnter Id of the Patient to update: ");
		scanf("%s", updateKey);

		// write data into file by skiping the one with the search key
		for(i = 0; i < dataLength; i++) {
			if(strcmp(pat[i].Id, updateKey) == 0) {
				found = 1;

				printf("\nPatient found!\n"); // inform that is found
				printf("%s\t%s %s\t%s\t%s\n", pat[i].Id, pat[i].Fname, pat[i].Lname, pat[i].appointmentDate, pat[i].phone_no);
				printf("\nEnter new:\n");

				printf("\nNational ID: ");
				scanf("%s", pat[i].Id);

				printf("\nFirst name: ");
				scanf("%s", pat[i].Fname);

				printf("\nLast name: ");
				scanf("%s", pat[i].Lname);

				printf("\nAppointment date (format: [dd/mm/yy]): ");
				scanf("%s", pat[i].appointmentDate);

				printf("\nPhone no (ex: 25078xxxxxx): ");
				scanf("%s", pat[i].phone_no);
			}
		}
	}
	// overwrite the update data in file if the updateKey matched with the one in array
	if(found == 1) {
		fptr = fopen("patient_appointment_records.txt", "w"); // open the file in write mode again

		for(i = 0; i < dataLength; i++) {
			fprintf(fptr, "%s\t%s %s\t%s\t%s\n", pat[i].Id, pat[i].Fname, pat[i].Lname, pat[i].appointmentDate, pat[i].phone_no);
		}

		printf("\nPatient updated succesfuly!\n");
		fclose(fptr); // close the file again
	} else {
		printf("\nPatient not found! ... Check well the ID\n");
	}
}

// Search one patient function
void searchPatient()
{
	FILE *fptr;

	char toSearchId[20]; // to store an id to update

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
			printf("%s\t%s %s\t%s\t%s\n", p.Id, p.Fname, p.Lname, p.appointmentDate, p.phone_no);
			fclose(fptr);
			return;
		}
	}

	// if the Id not available
	printf("\nId with %s not found check spelling\n", toSearchId);
}

// Delete patient function
void deletePatient() {
	FILE *fptr;

	char deleteKey[20]; // variable to store an id to delete
	struct Patient pat[100]; // structure to store temporal data

	int dataLength = 0, i, found = 0; // dataLength to count items in file an counter i for looping and flag

	fptr = fopen("patient_appointment_records.txt", "r"); // open file in read mode

	// loop in file and store founded data in local structure
	while(!feof(fptr)) {
		fscanf(fptr, "%s\t%s %s\t%s\t%s\n", pat[dataLength].Id, pat[dataLength].Fname, pat[dataLength].Lname, pat[dataLength].appointmentDate, pat[dataLength].phone_no);
		dataLength++; // increase the value in dataLength per data found
	}
	fclose(fptr); // close the file after scaning the data

	// check if file is not empty (if dataLength is equal to zero the file is empty)
	if(dataLength == 0) {
		printf("File is Empty");
	} else {
		fptr = fopen("patient_appointment_records.txt", "w"); // open the file in write mode again

		// get search key
		printf("\nEnter Id of the Patient to delete: ");
		scanf("%s", deleteKey);

		// write data into file by skiping the one with the search key
		for(i = 0; i < dataLength; i++) {
			if(strcmp(pat[i].Id, deleteKey) == 0) {
				found = 1;

				printf("\nPatient found!\n"); // inform that is found
				printf("%s\t%s %s\t%s\t%s\n", pat[i].Id, pat[i].Fname, pat[i].Lname, pat[i].appointmentDate, pat[i].phone_no);
				printf("\nDeleting patient...\n"); // simulate deletion
			}
			if(strcmp(pat[i].Id, deleteKey) != 0) {
				fprintf(fptr, "%s\t%s %s\t%s\t%s\n", pat[i].Id, pat[i].Fname, pat[i].Lname, pat[i].appointmentDate, pat[i].phone_no);
			}
		}

		if(found == 0) {
			printf("\nPatient not found! ... Check well the ID\n");
		} else {
			printf("\nPatient deleted succesfuly!\n"); // simulate deletion
		}

		fclose(fptr); // close the file again
	}
}

// Main function
int main()
{
	int choice; // to store choice type
	choice = 0;

	printf("\n========================================");
	printf("\n| PATIENT APPOINTMENT TO DOCTOR SYSTEM |\n");
	printf("========================================\n");

	do
	{
		printf("\nEnter:\n[1]. Record\n[2]. Display\n[3]. Update\n[4]. Search\n[5]. Delete\n[0]. Exit\n: > ");
		scanf("%d", &choice);

		/* Switch between choices and call the function based on the choice */
		switch(choice)
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
	} while(choice != 0);

	printf("\n");
}




