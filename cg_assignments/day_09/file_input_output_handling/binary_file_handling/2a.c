#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CFG 5      
#define MAX_LEN 50     

// Define the configuration structure
typedef struct config {
    char *ipaddress;  
    char name[MAX_LEN];  
    unsigned short port; 
} CONFIG;
CONFIG cfgarr_in[MAX_CFG];
CONFIG cfgarr_out[MAX_CFG];
int read_store_cfg(CONFIG cfgarr[]) {
    int count = 0;
    char ip[MAX_LEN]; 
    
    for (count = 0; count < MAX_CFG; count++) {
        cfgarr[count].ipaddress = (char *)malloc(MAX_LEN * sizeof(char));

        if (cfgarr[count].ipaddress == NULL) {
            printf("Memory allocation failed for IP address\n");
            return count; // Return the number of successful inputs so far
        }
        printf("Enter IP address for config %d: ", count + 1);
        fgets(ip, MAX_LEN, stdin);
        ip[strcspn(ip, "\n")] = '\0';  // Remove newline character from input
        strcpy(cfgarr[count].ipaddress, ip);  
        printf("Enter name for config %d: ", count + 1);
        fgets(cfgarr[count].name, MAX_LEN, stdin);
        cfgarr[count].name[strcspn(cfgarr[count].name, "\n")] = '\0';  
        printf("Enter port for config %d: ", count + 1);
        scanf("%hu", &cfgarr[count].port);
        getchar(); 
        printf("\n");
        char continue_input;
        printf("Do you want to enter another configuration? (y/n): ");
        scanf(" %c", &continue_input);
        getchar();  // Consume the newline character
        if (continue_input != 'y' && continue_input != 'Y') {
            break;
        }
    }
    return count;
}
void display(CONFIG cfgarr[], int count) {
    for (int i = 0; i < count; i++) {
        printf("Config %d\n", i + 1);
        printf("IP Address: %s\n", cfgarr[i].ipaddress);
        printf("Name: %s\n", cfgarr[i].name);
        printf("Port: %hu\n", cfgarr[i].port);
        printf("\n");
    }
}
void save_to_file(CONFIG cfgarr[], int count) {
    FILE *file = fopen("out.bin", "wb");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        fwrite(&cfgarr[i], sizeof(CONFIG), 1, file);
    }

    fclose(file);
}
void load_from_file(CONFIG cfgarr[], int *count) {
    FILE *file = fopen("out.bin", "rb");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return;
    }

    *count = 0;
    while (fread(&cfgarr[*count], sizeof(CONFIG), 1, file) == 1) {
        (*count)++;
        if (*count >= MAX_CFG) break;
    }

    fclose(file);
}
int main() {
    int count_in = read_store_cfg(cfgarr_in);  
    printf("\nStored Configurations:\n");
    display(cfgarr_in, count_in);  
    save_to_file(cfgarr_in, count_in);
    int count_out = 0;
    load_from_file(cfgarr_out, &count_out);
    printf("\nConfigurations read from file:\n");
    display(cfgarr_out, count_out);
    for (int i = 0; i < count_in; i++) {
        free(cfgarr_in[i].ipaddress);
    }

    return 0;
}
