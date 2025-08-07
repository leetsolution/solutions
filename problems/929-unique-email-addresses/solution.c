#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int numUniqueEmails(char** emails, int emailsSize) {
    int uniqueCount = 0;
    char** uniqueEmails = (char**)malloc(emailsSize * sizeof(char*));
    for (int i = 0; i < emailsSize; i++) {
        uniqueEmails[i] = NULL;
    }

    for (int i = 0; i < emailsSize; i++) {
        char* email = emails[i];
        char* localName = (char*)malloc(101 * sizeof(char));
        char* domainName = (char*)malloc(101 * sizeof(char));
        int j = 0;
        while (email[j] != '@') {
            j++;
        }
        strncpy(localName, email, j);
        localName[j] = '\0';
        strcpy(domainName, email + j + 1);

        char* cleanedLocalName = (char*)malloc(101 * sizeof(char));
        int k = 0;
        int l = 0;
        bool plusFound = false;
        while (localName[k] != '\0') {
            if (localName[k] == '+') {
                plusFound = true;
                break;
            }
            if (localName[k] != '.') {
                cleanedLocalName[l] = localName[k];
                l++;
            }
            k++;
        }
        cleanedLocalName[l] = '\0';

        char* normalizedEmail = (char*)malloc(202 * sizeof(char));
        strcpy(normalizedEmail, cleanedLocalName);
        strcat(normalizedEmail, "@");
        strcat(normalizedEmail, domainName);

        bool isUnique = true;
        for (int m = 0; m < uniqueCount; m++) {
            if (strcmp(normalizedEmail, uniqueEmails[m]) == 0) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            uniqueEmails[uniqueCount] = (char*)malloc((strlen(normalizedEmail) + 1) * sizeof(char));
            strcpy(uniqueEmails[uniqueCount], normalizedEmail);
            uniqueCount++;
        }

        free(localName);
        free(domainName);
        free(cleanedLocalName);
        free(normalizedEmail);
    }

    for (int i = 0; i < uniqueCount; i++) {
        free(uniqueEmails[i]);
    }
    free(uniqueEmails);

    return uniqueCount;
}