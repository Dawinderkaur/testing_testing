/*
 * list_db.c
 *
 *  Created on: Apr. 15, 2020
 *      Author: takis
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list_db.h"

/*****************************************************
 * FUNCTION DEFINITIONS
 *****************************************************/

/*
 * (private) function creates a new node; if it returns NULL, malloc() was unable to do it!
 */
stuLL_t* createNodeLinkedList(stuRec_t stdata)
{
	// PROBLEM #1: complete the code for this function
	//	       NOTE: PLEASE COMMIT CHANGES ONCE YOUR DONE THIS FUNCTION
stuLL_t *pNode = (stuLL_t*) malloc(sizeof(stuLL_t));
if (pNode != NULL)
{
		//provide data to new node pNode
		pNode->data.fname = stdata.fname;  //node created for family name
		pNode->data.gname = stdata.gname;  //node created for given name
		pNode->data.grade = stdata.grade;  // node created for grade

		pNode->pNext=NULL;   // initializing  pNode pointer
}
	return pNode;
}

/*
 * function adds a node to an existing list
 */
stuLL_t* addNodeLinkedList(stuLL_t *pHEAD, stuRec_t stdata)
{
	// check for an empty list
	if (pHEAD == NULL)
	{
		// list is empty, therefore, create the head node
		printf("Creating head node %s...\n", stdata.fName);
		pHEAD = createNodeLinkedList();
		if (pHEAD != NULL) // if there is no HEAP memory available, malloc() returns NULL
		{
			// add the data to the head node
			strcpy(pHEAD->data.fName, stdata.fName);
			strcpy(pHEAD->data.gName, stdata.gName);
			pHEAD->data.grade = stdata.grade;
			pHEAD->pNext = NULL; // the head node is also the last node atm
		}
		else
		{
			printf("error... cannot allocate memory!");
			exit(EXIT_FAILURE);
		}
	}
	else // pHEAD != NULL
	{
		// list is not empty, search for the end
		stuLL_t *pW = pHEAD;
		while (pW->pNext != NULL)
		{
			pW = pW->pNext;
		}

		// end is found, create the new node to add
		stuLL_t *pNode = createNodeLinkedList();
		if (pNode != NULL)
		{
			// pNode was allocated (i.e., there was sufficient memory for it)
			// so we can assign its data
			strcpy(pNode->data.fName, stdata.fName);
			strcpy(pNode->data.gName, stdata.gName);
			pNode->data.grade = stdata.grade;
			pNode->pNext = NULL; // the new last node get a NULL pNext ptr

			// attach new node to list
			pW->pNext = pNode;
		}
		else
		{
			printf("error... cannot allocate memory!");
			exit(EXIT_FAILURE);
		}
	}
	return pHEAD;
}

/*
 * function finds node in the Linked List with a fName matching targetFamilyName
 */
stuLL_t* findLinkedList(stuLL_t *pHEAD, char *targetFamilyName)
{
	stuLL_t *pW = pHEAD;
	unsigned int i = 0;
	if (pW != NULL) // if pW == NULL, simply exit
	{
		// list is not empty, begin search
		while ((pW != NULL) && (strcmp(pW->data.fName, targetFamilyName)))
		{
			// PROBLEM #2: complete the code for this function
			//	       NOTE: PLEASE COMMIT CHANGES ONCE YOUR DONE THIS FUNCTION
		return pw->pNext;  // if pw is not equal to null and the family name we are searching is not equal to target family name then
							// pointer will return to the next node or next family name for comparison.
		}
		printf("\n");
	}
	return pW; // if it family name comparison is same then it will return that particular node
}

/*
 * function displays node data associated with node pointed to by given pointer
 */
void displayNodeLinkedList(stuLL_t *pNode)
{
	printf("%-12s %-12s %-5s\n", "FAMILY NAME", "GIVEN NAME", "GRADE");
	if (pNode != NULL)
		printf("%-12s %-12s %2.3f\n", pNode->data.fName, pNode->data.gName,
				pNode->data.grade);
	else
		printf("RECORD NOT FOUND!\n");
}
