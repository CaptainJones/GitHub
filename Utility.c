#include "Utility.h"

Boolean MetaInfoComp(struct Meta_data_info *info1, struct Meta_data_info *info2)
{
        if(info1 -> component == info2 -> compnent &&
           info1 -> descriptor == info2 -> descriptor &&
           info1 -> cycle_time == info2 -> cycle_time)
           {
                 return Boolean.True;
           }
        return Boolean.False;
}

Boolean ConfigInfoComp(struct Config_data_info *info1, struct Config_data_info *info2)
{
        if(info1 -> identifier == info2 -> identifier &&
           info1 -> info == info2 -> info)
           {
                 return Boolean.True;
           }
        return Boolean.False;
}

char[] getStringUntil(FILE *cur_file, char endChar, int max_len)
{
       char charAsInt = fgetc( cur_file );
       char[maz_len] stringToReturn = NULL;
       int count = 0;
       while(charAsInt != endChar || count == max_len)
       {
            stringToReturn[count] = intToChar(charAsInt);
            count++;
       }
}

int charToInt(char charToConvert)
{
         return (int)(char - '0');
}

char intToChar(int intToConvert)
{
     return (char)(intToConvert + '0');
}

Boolean isIn(char testChar, char[] testString)
{
        char cur_char = testString[0];
        int count = 0;
        while(cur_char != '\0')
        {
               if(testChar == cur_char)
               {
                           return True;
               }
               count++;
               cur_char = testString[count];
        }
        return False;
}

int getLen(char *testString)
{
    char cur_char = testString[0];
    int count = 0; 
    while(cur_char != '\0')
    {
          count++;
          cur_char = testSting[count];
    }
    return count;
}

int power(int base, int exp)
{
    if(exp >= 0)
    {
           return power(base, exp - 1) * base;
    }
}


int stringToInt(chat[] testString)
{
    int length = getLen(testString);
    int power = length;
    int numToReturn = NULL;
    int index;
    char charToConvert;
    int convertedChar;
    int shiftedInt;
    
    for(index = 0; index <= length; index++)
    {
         charToConvert = testString[index];
         convertedChar = charToInt(charToConvert);
         shiftedInt = convertedChar * power(10, power);
         numToReturn += shiftedInt;
         power--;
    }
}

char strip(char[] string, char striped)
{
     int length = getLen(string);
     int index;
     int numOfApperence = 0;
     char[length] stringHolder;
     char[length] stringToReturn;
     
     for(index = 0; index <= length; index++)
     {
               if(string[index] != striped)
               {
                  stringHolder[stringHolderIndex] = string[index];
               }
     }
     
     int newLength = getLen(stringHolder);
     char[newLength] stringToReturn;
     
     for(index = 0; index <= newLength; index++)
     {
               stringToReturn[index] = stringHolder[index];
     }
     
     retrun strignToReturn;
}

char *toLowerCase(char *inString)
{
     char *stringToReturn;
     int len = getLen(inString);
     int index = 0;
     
     for(index = 0; index <= len; index++)
     {
               if(isIn(inString[index]) == 'ABCDEFGHIJKLMNOPQRSTUVWXYZ')
               {
                   stringToReturn[index] = (inString[index] - 'A') + 'a'               
               }
     }
     
     return stringToReturn;
}

















