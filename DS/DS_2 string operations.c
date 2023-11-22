#include <stdio.h>
#include <string.h>

void readString(char *str, const char *message) {
    printf("%s", message);
    scanf(" %[^\n]", str);
}

void findAndReplace(char *mainStr, const char *pattern, const char *replace) {
    int mainLen = strlen(mainStr);
    int patLen = strlen(pattern);
    char newStr[1000]; 

    int i, j, k;
    for (i = 0; i < mainLen; ) {

        for (j = 0; j < patLen; j++) {
            if (mainStr[i + j] != pattern[j]) {
                break;
            }
        }

        if (j == patLen) {
            for (k = 0; replace[k] != '\0'; k++) {
                newStr[i + k] = replace[k];
            }
            i += k;
        } else {
            newStr[i] = mainStr[i];
            i++;
        }
    }
    newStr[i] = '\0';

    strcpy(mainStr, newStr);
}

int main() {
    char mainStr[1000];
    char pattern[100];
    char replace[100];

    readString(mainStr, "Enter the main string: ");
    readString(pattern, "Enter the pattern to search for: ");
    readString(replace, "Enter the replacement string: ");

    findAndReplace(mainStr, pattern, replace);

    printf("Modified String: %s\n", mainStr);

    return 0;
}
