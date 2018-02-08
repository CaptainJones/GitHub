// original author Dr. Michel Leverington
// modified by 65582

// hello world

#include "linkedlist.h"
#include "Utility.h"
#include "linkedlist.c"

struct Config_data_info
{
       char *identifier;
       char *info;
};

NodeType *getConfigDataFromFile( struct NodeType *headNode, char *fileName )
   {
                     
    const int STD_STR_LEN = 60;
    const int MAX_STR_LEN = 120;
    const int NOT_AT_FILE_END = 0;
    const char READ_ONLY_FLAG[] = "r";
    const char NULL_CHAR = '\0';
    const char SEMICOLON = ';';
    const char SPACE = ' ';
    const char NEW_LINE = '\n';
    
    char errorMessage = NULL;
    
    FILE *fileAccessPtr;
    int strIndex, charAsInt;
    char dummyChar, strBuffer[ MAX_STR_LEN ];
    Boolean continueRun = True;
    //struct NodeType *tempNodePtr 
                      //= (struct NodeType *)malloc( sizeof( struct NodeType ) );

    fileAccessPtr = fopen( fileName, READ_ONLY_FLAG );

    if( fileAccessPtr != NULL )
    {
        
        char charAsInt = fgetc( fileAccessPtr );
            while(charAsInt != NEW_LINE)
            {
                 charAsInt = fgetc( fileAccessPtr );  
            }
        charAsInt = fgetc( fileAccessPtr );
        
        while( continueRun == True )
        {
            if(charAsInt == '\0')
            {
                break;
            }
            char inIdentifier = getStringUntil(fileAccessPtr, ':', MAX_STR_LEN);
            char descriptor = getStringUntil(fileAccessPtr, '\n', MAX_STR_LEN); 
            component = strip(component, SPACE);
            
            Config_data_info *info = ConfigInfoCreate(component, descriptor, cycle_time);
            
            if(checkForCompliance(info) == True)
            {
                  NodeType newNode = makeNode(info);
                  addNode(headNode, newNode);
            }
            else
            {
                headNode = clearList(headNode);
                headNode = makeNode(errorMessage);
                return headNode;
            }
        }
    }

    else
       {
        errorMessage = 'file input error';
        headNode = clearList(headNode);
        headNode = makeNode(errorMessage);
        return headNode;
       }

    errorMessage = 'Unknown error';
    headNode = clearList(headNode);
    headNode = makeNode(errorMessage);
    return headNode;
   }
   
Meta_data_info *ConfigInfoCreate(char newIdentifier, char newInfo)
{
      Meta_data_info *structToReturn;
      
      structToReturn -> identifier = newIdentifier;
      structToReturn -> info = newInfo;
      
      return structToReturn
}

Boolean checkForCompliance(Config_data_info *info)
{
        char[60] inIdentifier = toLowerCase(info -> identifier);
        char[60] inInfo = info -> info;
        int counter = 0;
        
        switch(inIdentifier)
        {
                            case 'version':
                                 counter++;
                                 break;
                            
                            case 'phase':
                                 counter++;
                                 break;
                                 
                            case 'file path':
                                 counter++;
                                 break;
                                 
                            case 'cpu scheduling code':
                                 counter += cpuSchedulingTest(info);
                                 break;
                            
                            case 'quantum time':
                                 infoAsInt = stringToInt(info);
                                 if(infoAsInt >= 0 && infoAsInt <= 100)
                                 {
                                              counter++;
                                 }
                                 else
                                 {
                                     errorMessage = 'Quantum time error'
                                 }
                                 break;
                                 
                            case 'memory available':
                                 infoAsInt = stringToInt(info);
                                 if(infoAsInt >= 0 && infoAsInt <= 1048576)
                                 {
                                              counter++;
                                 }
                                 else
                                 {
                                     errorMessage = 'Memory available error'
                                 }
                                 break;
                                 
                            case 'processor cycle time':
                                 infoAsInt = stringToInt(info);
                                 if(infoAsInt >= 1 && infoAsInt <= 1000)
                                 {
                                              counter++;
                                 }
                                 else
                                 {
                                     errorMessage = 'Processor cycle time error'
                                 }
                                 break;
                                 
                            case 'i/o cycle time':
                                 infoAsInt = stringToInt(info);
                                 if(infoAsInt >= 1 && infoAsInt <= 10000)
                                 {
                                              counter++;
                                 }
                                 else
                                 {
                                     errorMessage = 'Processor cycle time error'
                                 }
                                 break;
                                 
                            case 'log to':
                                 info = toLower(info);
                                 if(info == 'monitor' ||
                                    info == 'file' ||
                                    info == 'both')
                                 {
                                         counter++;
                                 }
                                 else
                                 {
                                     errorMessage = 'log to error';
                                 }
                                 break;
                                 
                            case 'log file path':
                                 if(info != NULL)
                                 {
                                         counter++;
                                 }
                                 else
                                 {
                                     errorMessage = 'log file path error';
                                 }
                                 break;
        }
        
        if(counter == 9)
        {
                   return True;
        }
        
        return false;
}
                                 
int cpuSchedulingTest(char *info)
{
    if(info == 'NONE' || info == 'FCFS-N' || info == 'SJF-N' || 
                      info == 'SRTF-P' || info == 'FCFS-P' || info == 'RR-P')
    {
                      return 1;
    }
    
    return 0;
}














