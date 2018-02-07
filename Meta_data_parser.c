// original author Dr. Michel Leverington
// modified by 655829

#include "linkedlist.h"
#include "linkedlist.c
#include "Utility.h"

NodeType *getMetaDataFromFile( struct NodeType *headNode, char *fileName )
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
    
    NodeType headNode = NULL;
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
            char component = getStringUntil(fileAccessPtr, '(', MAX_STR_LEN);
            component = strip(component, SPACE);
            char descriptor = getStringUntil(fileAccessPtr, ')', MAX_STR_LEN); 
            char cycle_time = getStringUntil(fileAccessPtr, ';', MAX_STR_LEN);
            
            struct Meta_data_info *info = MetaInfoCreate(component, descriptor, cycle_time);
            
            if(checkForCompliance(info) == 1)
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
   
Meta_data_info *metaInfoCreate(char newComponent, char newDescriptor, char newCycleTime)
{
      Meta_data_info *structToReturn;
      
      structToReturn -> component = newComponent;
      structToReturn -> descriptor = newDescriptor;
      structToReturn -> cycle_time = newCycleTime;
      
      return structToReturn
}

Boolean checkForCompliance(Meta_data_info *info)
{
        char component = info -> component;
        char[] descriptor = info -> descriptor;
        char[] cycle_time = info -> cycle_time;
        
        char[6] componentTest = 'SAPMIO';
         
        
        if(isIn(component, componentTest) == 1)
        {
                           
             if(descriptorTest(descriptor) == 1)
             {
                                           
                  if(isIn(component, componentTest) == 1)
                  {
                        return true;
                  }
                  
                  else
                  {
                        errorMessage = 'meta data cycletime error:';
                  }
                  
             }
             
             else
             {
            errorMessage = 'meta data Descriptor error';
             }
             
        }
        
        else
        {
            errorMessage = 'meta data component error';
        }
        
        return false
}

Boolean descriptorTest(char[] descriptior)
{
        if(descriptior == 'access')
        {
           return True;
        }
        
        if(descriptior == 'allocate')
        {
           return True;
        }
        
        if(descriptior == 'end')
        {
           return True;
        }
        
        if(descriptior == 'hard drive')
        {
           return True;
        }
        
        if(descriptior == 'keyboard')
        {
           return True;
        }
        
        if(descriptior == 'printer')
        {
           return True;
        }
        
        if(descriptior == 'monitor')
        {
           return True;
        }
        
        if(descriptior == 'run')
        {
           return True;
        }
        
        if(descriptior == 'start')
        {
           return True;
        }
        return false;
}

Boolean cycleTimeTest(char[] cycle_time)
{
     if(getLen(cycle_time) < 7)
     {
          return True;
     }
     return False;
}
