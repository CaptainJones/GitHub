// original author Dr. Michel Leverington
// modified by 655829

// Header file for linkedlist.c

// Precompiler directive, to eliminate multiple compiles of h file
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// header files
#include <stdlib.h>  // malloc
#include "Meta_data_parser.h"
#include "Config_data_parser.h"
#include "linkedlist.c"

struct NodeType;

// function prototypes

struct NodeType *addNode( struct NodeType *headNode, struct NodeType *newNode );
struct NodeType *makeNodeMeta(struct Meta_data_info *newInfo);
struct NodeType *makeNodeConfig(struct Config_data_info *newInfo);
struct NodeType *makeNodeChar(char *errorMessage);
struct NodeType *findNodeMeta( struct NodeType *workingNode, struct Meta_data_info *newInfo );
struct NodeType *findNodeConfig( struct NodeType *workingNode, struct Config_data_info *newInfo );
struct NodeType *clearList( struct NodeType *headNode );
struct NodeType *removeNodeMeta( struct NodeType *headNode, struct Meta_data_info *infoToRemove );
struct NodeType *removeNodeConfig( struct NodeType *headNode, struct Config_data_info *infoToRemove );

#endif // LINKED_LIST_H


