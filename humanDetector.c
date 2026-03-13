#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

/* * Project: Wolf Recognize
 * Description: Human Scanning, Pattern Recognition, and Global Trace System
 * Language: C
 */

// Structure to hold Human Target Data
typedef struct {
    int id;
    char name[50];
    float match_accuracy;
    char location[50];
    char ip_address[20];
} WolfTarget;

// Function Prototypes
void initialize_system();
void perform_identity_scan(const char *identity_name);
void perform_number_scan(const char *number);
void random_delay(int ms);
void generate_fake_ip(char *buffer);

int main() {
    char choice;
    char input_buffer[100];

    // Seed random number generator
    srand(time(NULL));

    initialize_system();

    printf("\n[SELECT OPERATION MODE]\n");
    printf(" 1. Global Identity Name Scan (Nmap Style)\n");
    printf(" 2. MSISDN Number Trace (Truecaller Mode)\n");
    printf(" Q. Quit System\n");

    printf("\nSelect Option > ");
    scanf(" %c", &choice);

    if (choice == '1') {
        printf("\nEnter Target Identity Name: ");
        scanf(" %[^\n]s", input_buffer);
        perform_identity_scan(input_buffer);
    }
    else if (choice == '2') {
        printf("\nEnter Mobile Number (with Country Code, e.g., +91...): ");
        scanf(" %[^\n]s", input_buffer);
        perform_number_scan(input_buffer);
    }
    else {
        printf("\nExiting Wolf Recognize. System Standby.\n");
    }

    return 0;
}

// Function to simulate system hardware initialization
void initialize_system() {
    printf("========================================\n");
    printf("   WOLF RECOGNIZE - HUMAN SCANNER v2.5  \n");
    printf("========================================\n");
    printf("[INFO] Initializing Global Neural Network...\n");
    printf("[INFO] Connecting to Satellite Uplink...\n");
    printf("[SUCCESS] System Online.\n");
}

void random_delay(int ms) {
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}

void generate_fake_ip(char *buffer) {
    sprintf(buffer, "%d.%d.%d.%d",
        rand() % 255, rand() % 255, rand() % 255, rand() % 255);
}

// Option 1: Identity Name Scan (Existing Nmap Style)
void perform_identity_scan(const char *identity_name) {
    printf("\nStarting Wolf Nmap 7.94 ( https://wolf-recognize.org ) at %s", __DATE__);
    printf("\nNmap scan report for identity: %s\n", identity_name);
    printf("Host is up (0.0023s latency).\n");

    printf("\n[Scanning Global Database] ");

    int total_matches = 0;
    WolfTarget matches[10];

    for (int i = 0; i <= 100; i += 5) {
        printf(".");
        random_delay(50);

        if (i > 10 && i < 90 && (rand() % 10) > 7) {
            if (total_matches < 10) {
                WolfTarget t;
                t.id = 1000 + rand() % 9000;
                strcpy(t.name, identity_name);
                generate_fake_ip(t.ip_address);

                const char* locations[] = {"New York, US", "Mumbai, IN", "London, UK", "Tokyo, JP", "Berlin, DE", "Local Area Network"};
                strcpy(t.location, locations[rand() % 6]);

                t.match_accuracy = 80.0 + (rand() % 200) / 10.0;
                matches[total_matches++] = t;

                printf("\n[+] Discovered signature match in sector %s (%s)\n", t.location, t.ip_address);
                printf("[Scanning Global Database] ");
            }
        }
    }
    printf(" Done.\n");

    printf("\n----------- SCAN RESULTS FOR '%s' -----------\n", identity_name);
    for(int i = 0; i < total_matches; i++) {
        printf("ID: %d | LOC: %-15s | IP: %-15s | CONF: %.2f%%\n",
            matches[i].id, matches[i].location, matches[i].ip_address, matches[i].match_accuracy);
    }

    if (total_matches == 0) printf("[INFO] No active entities found.\n");
    printf("-------------------------------------------------------------\n");
}

// Option 2: Phone Number Trace (New Truecaller Style)
void perform_number_scan(const char *number) {
    printf("\n[INIT] Connecting to Global Telecom Exchanges...\n");
    printf("[INFO] Tracing MSISDN: %s\n", number);

    const char *regions[] = {
        "North America (NANP - +1)",
        "India (Dept of Telecom - +91)",
        "Europe (ETSI - +44/+33/+49)",
        "Asia-Pacific (APT - +86/+81)",
        "South America (CITEL - +55)"
    };

    int found = 0;
    char found_region[50];

    // Simulate Region Scanning
    for (int i=0; i<5; i++) {
        printf("[SEARCHING] Pinging gateways in %s...", regions[i]);
        random_delay(800);

        // Simulation: 70% chance to find it, or logic based on number?
        // Let's make it random for simulation fun, but consistent if called again in same run (not really possible here without seed reset)
        // Check if number length is valid (> 6 digits)
        if (strlen(number) > 6 && !found && (rand() % 100 < 40)) {
            found = 1;
            strcpy(found_region, regions[i]);
            printf(" [MATCH FOUND]\n");
            // Don't break immediately, maybe simulate finishing scan?
            // user wants "dikhaye ki ye number world me hai ya nhi"
            // If found, we stop scanning other regions to save time like real systems
            break;
        } else {
             printf(" [NO RECORD]\n");
        }
    }

    if (found) {
        // Generate Fake Identity Details
        const char *first_names[] = {"Rahul", "John", "Priya", "Wei", "Fatima", "Carlos", "Satoshi", "Emily"};
        const char *last_names[] = {"Sharma", "Smith", "Patel", "Wang", "Al-Sayed", "Rodriguez", "Nakamoto", "Johnson"};
        const char *carriers[] = {"Jio 5G", "Airtel", "Verizon", "T-Mobile", "China Mobile", "Vodafone", "BSNL"};
        const char *professions[] = {"Software Engineer", "Doctor", "Student", "Business Owner", "Unknown", "Government Official"};

        char owner_name[50];
        sprintf(owner_name, "%s %s", first_names[rand() % 8], last_names[rand() % 8]);

        printf("\n=============================================\n");
        printf("       GLOBAL NUMBER TRACE REPORT            \n");
        printf("=============================================\n");
        printf("TARGET NUMBER   : %s\n", number);
        printf("STATUS          : ACTIVE / ALLOCATED\n");
        printf("REGION ORIGIN   : %s\n", found_region);
        printf("CARRIER NETWORK : %s\n", carriers[rand() % 7]);
        printf("---------------------------------------------\n");
        printf("REGISTERED OWNER DETAILS:\n");
        printf("NAME            : %s\n", owner_name);
        printf("PROFESSION      : %s\n", professions[rand() % 6]);
        printf("SIGNAL STRENGTH : -%ddBm (Strong)\n", 50 + rand()%40);
        printf("LAST ACTIVE     : Just now\n");
        printf("=============================================\n");
    } else {
        printf("\n[CRITICAL ERROR] NUMBER NOT FOUND IN WORLD DATABASE.\n");
        printf("----------------------------------------------------\n");
        printf("Analysis of %s yielded 0 results.\n", number);
        printf(" - The number is unallocated.\n");
        printf(" - It does not exist on any terrestrial network.\n");
        printf(" - Status: VOID / NULL\n");
        printf("----------------------------------------------------\n");
    }
}