
#include<stdio.h>
#include<string.h>

void recordPatient();
void displayPatients();
void deletePatient();

struct Patient
{
	char name[20], sex[5];
	int age;
} p[5];

int tot = 0;

// record Patient function
void recordPatient()
{
	printf("\nEnter: \n");

	printf("\nName: ");
	scanf("%s", p[tot].name);

	printf("\nAge: ");
	scanf("%d", &p[tot].age);

	printf("\nSex: ");
	scanf("%s", p[tot].sex);

	tot++;
}

// Display all patients function
void displayPatients()
{

	int i;

	printf("\nPatients records:\n");

	for(i = 0; i < tot; i++) {
		printf("\nName: %s\n", p[i].name);
		printf("\nAge: %d\n", p[i].age);
		printf("\nSex: %s\n", p[i].sex);
	}
}

// Update patient function
void updatePatient()
{
	char pName[20], newSex[5];
	int i, newAge;

	printf("Enter patient Name: ");
	scanf("%s", pName);

	for(i = 0; i < tot; i++) {
		if(strcmp(p[i].name, pName) == 0) {
			printf("\nOld data: \n");

			printf("Name: %s\n", p[i].name);
			printf("Age: %d\n", p[i].age);
			printf("Sex: %s\n", p[i].sex);

			// inserting new data
			printf("\nEnter new: \n");

			printf("\nName: ");
			scanf("%s", pName);

			// replace entered name
			strcpy(p[i].name, pName);

			printf("\nAge: ");
			scanf("%d", &newAge);

			// replace entered age
			p[i].age = newAge;

			printf("\nSex: ");
			scanf("%s", newSex);

			// replace entered sex
			strcpy(p[i].sex, newSex);

		} else {
			printf("Name %s not found!", pName);
		}
	}
}

// Delete patient function
void deletePatient()
{
	char pName[20];
	int i;

	printf("Enter patient Name: ");
	scanf("%s", pName);

	for(i = 0; i < tot; i++) {
		if(strcmp(p[i].name, pName) == 0) {
			printf("\nPatient data: \n");

			printf("Name: %s\n", p[i].name);
			printf("Age: %d\n", p[i].age);
			printf("Sex: %s\n", p[i].sex);

		} else {
			printf("Name %s not found!", pName);
		}
	}

}

// Main function
int main()
{
	int c;
	c = 0;

	do
	{
		printf("\nEnter\n1. Record\n2. Display\n3. Update\n4. Delete\n0. Exit\n: > ");
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
				deletePatient();
				break;
			case 0:
				printf("\nThank you!");
				break;
			default:
				printf("\nChoice must be 0, 1, 2, 3, or 4.");
		}
	} while(c != 0);

	printf("\n");
}
















