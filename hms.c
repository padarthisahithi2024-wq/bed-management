#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "beds.dat"
#define MAX_NAME_LEN 100
#define MAX_DISEASE_LEN 100
#define MAX_CONTACT_LEN 50

// ------------------ STRUCT DEFINITION ------------------
typedef struct {
    int bedNo;
    char patientName[MAX_NAME_LEN];
    int age;
    char gender[10];
    char disease[MAX_DISEASE_LEN];
    char contact[MAX_CONTACT_LEN];
    char status[20];  // Occupied / Vacant
} Bed;

// ------------------ FUNCTION DECLARATIONS ------------------
void addBed();
void viewBeds();
void searchBed();
void updateBed();
void deleteBed();
int bedExists(int bedNo);
void saveBed(Bed b);
void loadBeds(Bed beds[], int *count);
void writeAllBeds(Bed beds[], int count);

// ------------------ MAIN MENU ------------------
int main() {
    int choice;
    do {
        printf("\n==============================\n");
        printf("      BED MANAGEMENT SYSTEM\n");
        printf("==============================\n");
        printf("1. Add Bed / Assign Patient\n");
        printf("2. View All Beds\n");
        printf("3. Search Bed\n");
        printf("4. Update Bed Details\n");
        printf("5. Delete Bed Record\n");
        printf("6. Exit\n");
        printf("------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: addBed(); break;
            case 2: viewBeds(); break;
            case 3: searchBed(); break;
            case 4: updateBed(); break;
            case 5: deleteBed(); break;
            case 6: printf("Exiting program. Goodbye!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

// ------------------ ADD BED / ASSIGN PATIENT ------------------
void addBed() {
    Bed b;

    printf("\n--- Add Bed / Patient Allocation ---\n");
    printf("Enter Bed Number: ");
    scanf("%d", &b.bedNo);
    getchar();

    if (bedExists(b.bedNo)) {
        printf("Error: Bed number already assigned!\n");
        return;
    }

    printf("Enter Patient Name: ");
    fgets(b.patientName, sizeof(b.patientName), stdin);
    b.patientName[strcspn(b.patientName, "\n")] = '\0';

    printf("Enter Patient Age: ");
    scanf("%d", &b.age);
    getchar();

    printf("Enter Gender: ");
    fgets(b.gender, sizeof(b.gender), stdin);
    b.gender[strcspn(b.gender, "\n")] = '\0';

    printf("Enter Disease: ");
    fgets(b.disease, sizeof(b.disease), stdin);
    b.disease[strcspn(b.disease, "\n")] = '\0';

    printf("Enter Contact Info: ");
    fgets(b.contact, sizeof(b.contact), stdin);
    b.contact[strcspn(b.contact, "\n")] = '\0';

    strcpy(b.status, "Occupied");

    saveBed(b);
    printf("Bed assigned successfully!\n");
}

// ------------------ SAVE BED ------------------
void saveBed(Bed b) {
    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        perror("Error opening file");
        return;
    }
    fwrite(&b, sizeof(Bed), 1, fp);
    fclose(fp);
}

// ------------------ CHECK BED EXISTENCE ------------------
int bedExists(int bedNo) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;

    Bed b;
    while (fread(&b, sizeof(Bed), 1, fp)) {
        if (b.bedNo == bedNo) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// ------------------ VIEW ALL BEDS ------------------
void viewBeds() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No bed records found.\n");
        return;
    }

    Bed b;
    printf("\n%-8s %-20s %-5s %-10s %-20s %-15s %-10s\n",
           "BedNo", "Name", "Age", "Gender", "Disease", "Contact", "Status");
    printf("--------------------------------------------------------------------------------------\n");

    while (fread(&b, sizeof(Bed), 1, fp)) {
        printf("%-8d %-20s %-5d %-10s %-20s %-15s %-10s\n",
               b.bedNo, b.patientName, b.age, b.gender, b.disease, b.contact, b.status);
    }

    fclose(fp);
}

// ------------------ SEARCH BED ------------------
void searchBed() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("No bed records found.\n");
        return;
    }

    int bedNo, found = 0;
    Bed b;

    printf("\nEnter Bed Number to search: ");
    scanf("%d", &bedNo);

    while (fread(&b, sizeof(Bed), 1, fp)) {
        if (b.bedNo == bedNo) {
            printf("\nBed Found:\n");
            printf("Bed Number: %d\nName: %s\nAge: %d\nGender: %s\nDisease: %s\nContact: %s\nStatus: %s\n",
                   b.bedNo, b.patientName, b.age, b.gender, b.disease, b.contact, b.status);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No bed assigned with number %d.\n", bedNo);

    fclose(fp);
}

// ------------------ UPDATE BED ------------------
void updateBed() {
    Bed beds[200];
    int count = 0, bedNo, found = 0;

    loadBeds(beds, &count);

    printf("\nEnter Bed Number to update: ");
    scanf("%d", &bedNo);
    getchar();

    for (int i = 0; i < count; i++) {
        if (beds[i].bedNo == bedNo) {
            found = 1;

            printf("Enter new contact: ");
            fgets(beds[i].contact, sizeof(beds[i].contact), stdin);
            beds[i].contact[strcspn(beds[i].contact, "\n")] = '\0';

            printf("Enter new disease: ");
            fgets(beds[i].disease, sizeof(beds[i].disease), stdin);
            beds[i].disease[strcspn(beds[i].disease, "\n")] = '\0';

            printf("Enter status (Occupied/Vacant): ");
            fgets(beds[i].status, sizeof(beds[i].status), stdin);
            beds[i].status[strcspn(beds[i].status, "\n")] = '\0';

            break;
        }
    }

    if (found) {
        writeAllBeds(beds, count);
        printf("Bed details updated successfully.\n");
    } else {
        printf("Bed number not found.\n");
    }
}

// ------------------ DELETE BED ------------------
void deleteBed() {
    Bed beds[200];
    int count = 0, bedNo, found = 0;

    loadBeds(beds, &count);

    printf("\nEnter Bed Number to delete: ");
    scanf("%d", &bedNo);
    getchar();

    for (int i = 0; i < count; i++) {
        if (beds[i].bedNo == bedNo) {
            found = 1;
            printf("Are you sure you want to delete Bed %d? (y/n): ", bedNo);
            char confirm = getchar();
            getchar();

            if (confirm == 'y' || confirm == 'Y') {
                for (int j = i; j < count - 1; j++)
                    beds[j] = beds[j + 1];

                count--;
                writeAllBeds(beds, count);
                printf("Record deleted successfully.\n");
            } else {
                printf("Deletion cancelled.\n");
            }
            break;
        }
    }

    if (!found)
        printf("Bed number not found.\n");
}

// ------------------ LOAD & WRITE ALL ------------------
void loadBeds(Bed beds[], int *count) {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return;

    *count = 0;
    while (fread(&beds[*count], sizeof(Bed), 1, fp))
        (*count)++;

    fclose(fp);
}

void writeAllBeds(Bed beds[], int count) {
    FILE *fp = fopen(FILE_NAME, "wb");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    fwrite(beds, sizeof(Bed), count, fp);
    fclose(fp);
}
