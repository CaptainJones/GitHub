// original author Dr. Michel Leverington
// modified by 655829

#ifndef LINKED_LIST_C
#define LINKED_LIST_C

// header files

#include "Meta_data_parser.h"
#include "Config_data_parser.h"
#include "Utility.h"
#include <stdlib.h> 

struct NodeType
   {
    char *errorMessage; // hard-coded STD_STR_LEN since it is not declared yet
    struct meta_data_info *Meta_data;
    struct config_data_info *Config_data;
    struct NodeType *next;
   };

//struct NodeType *addNode( struct NodeType *, struct NodeType *);
//struct NodeType *makeNodeMeta(struct Meta_data_info *);
//struct NodeType *makeNodeConfig(struct Config_data_info *);
//struct NodeType *makeNodeChar(char *);
//struct NodeType *findNodeMeta( struct NodeType *, struct Meta_data_info *);
//struct NodeType *findNodeConfig( struct NodeType *, struct Config_data_info * );
//struct NodeType *clearList( struct NodeType * );
//struct NodeType *removeNodeMeta( struct NodeType *, struct Meta_data_info * );
//struct NodeType *removeNodeConfig( struct NodeType *, struct Config_data_info * );


struct NodeType *addNodeHelper( struct NodeType *currNode, struct NodeType *newNode )
{
         if(currNode -> next = NULL)
         {
                     currNode -> next = newNode;
                     return newNode;
         }
         
         return addNodeHelper(currNode -> next, newNode);
}

struct NodeType *addNode( struct NodeType *headNode, struct NodeType *newNode )
   {

    // check for viable node
    if( headNode != NULL )
       {
                 
        return addNodeHelper(headNode, newNode);
        
       }

    // assume empty head node
    headNode = newNode;
    return headNode;
    // possible loss of node not info just the node with that last dec
   }

// function eliminates redundant code in addNode

struct NodeType *makeNodeMeta(struct Meta_data_info *newInfo)
   {
    struct NodeType *newNode
                   = ( struct NodeType * ) malloc( sizeof( struct NodeType ) );

    newNode -> errorMessage = NULL;
    newNode -> Meta_data = newInfo;
    newNode -> Config_data = NULL;
    
    return newNode;
   }
   
struct NodeType *makeNodeConfig(struct Config_data_info *newInfo)
   {
    struct NodeType *newNode
                   = ( struct NodeType * ) malloc( sizeof( struct NodeType ) );

    newNode -> Config_data = newInfo;
    
    return newNode;
   }
   
struct NodeType *makeNodeChar(char *errorMessage)
         {
             struct NodeType *newNode
                   = ( struct NodeType * ) malloc( sizeof( struct NodeType ) );
                   
             newNode -> errorMessage = errorMessage;
             
             return newNode;
         }

// returned node memory is not freed inside linked list
// it must be freed in calling function
struct NodeType *findNodeMeta( struct NodeType *workingNode, struct Meta_data_info *newInfo )
   {
    if( workingNode != NULL )
       {
        if( MetaInfoComp(workingNode -> Meta_data, newInfo) == 1 )
           {
            return makeNodeMeta(newInfo);
           }

        return findNodeMeta( workingNode->next , newInfo );
       }

    return NULL;
   }


struct NodeType *findNodeConfig( struct NodeType *workingNode, struct Config_data_info *newInfo )
   {
    if( workingNode != NULL )
       {
        if( ConfigInfoComp(workingNode -> Config_data, newInfo) == 1 )
           {
            return makeNodeConfig( newInfo );
           }

        return findNode( workingNode -> next, newInfo );
       }

    return NULL;
   }

struct NodeType *clearList( struct NodeType *headNode )
   {
    if( headNode == NULL )
       {
        return NULL;
       }

    if( headNode->next != NULL )
       {
        clearList( headNode->next );
       }

    free( headNode );

    headNode = NULL;

    return headNode;
   }

struct NodeType *removeNodeHelperMeta(struct NodeType *workingNode, struct Meta_data_info *infoToRemove )
{
         struct NodeType *nextNode = workingNode -> next;
         
         struct NodeType *removedNode;
         struct NodeType *nodeHolder;
         
         if( MetaInfoComp(nextNode -> Meta_data, infoToRemove) == 1 )
         {
             removedNode = nextNode;
             nodeHolder = nextNode -> next;
             free(nextNode);
             workingNode -> next = nodeHolder;
             return removedNode;
         }
         
         removeNodeHelper(workingNode -> next, infoToRemove);
}

struct NodeType *removeNodeMeta( struct NodeType *headNode, struct Meta_data_info *infoToRemove )
   {
         struct NodeType *nextNodeHolder;
         struct NodeType *nodeRemoved;
         if( MetaInfoComp(headNode -> Meta_data, infoToRemove) == 1 )
         {
             nextNodeHolder = headNode -> next;
             nodeRemoved = headNode;
             free(headNode);
             headNode  = nextNodeHolder;
             return nodeRemoved;
         }
         return removeNodeHelper(headNode, infoToRemove);
   }

struct NodeType *removeNodeHelperConfig(struct NodeType *workingNode, struct Config_data_info *infoToRemove )
{
         struct NodeType *nextNode = workingNode -> next;
         
         struct NodeType *removedNode;
         struct NodeType *nodeHolder;
         
         if( MetaInfoComp(nextNode -> Config_data, infoToRemove) == 1 )
         {
             removedNode = nextNode;
             nodeHolder = nextNode -> next;
             free(nextNode);
             workingNode -> next = nodeHolder;
             return removedNode;
         }
         
         return removeNodeHelper(workingNode -> next, infoToRemove);
}

struct NodeType *removeNodeConfig( struct NodeType *headNode, struct Config_data_info *infoToRemove )
   {
         struct NodeType *nextNodeHolder;
         struct NodeType *nodeRemoved;
         if( ConfigInfoComp(headNode -> Config_data, infoToRemove) == 1 )
         {
             nextNodeHolder = headNode -> next;
             nodeRemoved = headNode;
             free(headNode);
             struct NodeType *headNode;
             return nodeRemoved;
         }
         return removeNodeHelper(headNode, infoToRemove);
   }

#endif   // LINKED_LIST_C


