#include <stdlib.h>
#include <stdio.h>

typedef int Boolean;
Boolean True = 1;
Boolean False = 0;

Boolean MetaInfoComp(struct Meta_data_info *info1, struct Meta_data_info *info2);
Boolean ConfigInfoComp(struct Config_data_info *info1, struct Config_data_info *info2);
char *getStringUntil(FILE *inFile, char endChar, int maxLength);
int charToInt(char charToConvert);
char intToChar(int intToConvert);
Boolean isIn(char testChar, char *testString);
int getLen(char *testString);
int power(int base, int exp);
int stringToInt(char *testString);
char strip(char *string, char striped);
char *toLowerCase(char *inString);
