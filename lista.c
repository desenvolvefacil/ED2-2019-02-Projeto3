/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

LISTA_DINAMICA *criar_lista(void) {
    LISTA_DINAMICA *lista = (LISTA_DINAMICA *) malloc(sizeof (LISTA_DINAMICA));

    lista->inicio = NULL;
    lista->fim = NULL;

    lista->tamanho = 0;

    return lista;
}

int inserir_inicio(LISTA_DINAMICA *lista, int item) {

    NO *no_novo = (NO *) malloc(sizeof (NO));
    no_novo->item = item;
    no_novo->proximo = lista->inicio;

    lista->inicio = no_novo;

    return 1;
}

void imprimir_lista(LISTA_DINAMICA *lista) {
    NO *no = lista->inicio;
    while (no != NULL) {
        printf("[%d]-> ", no->item);

        no = no->proximo;
    }

    printf("\n");
}

/*******
 * 
 * 
 * 
 * 
 * 
 * */


// Returns the last node of the list 

NO *getTail(NO *cur) {
    while (cur != NULL && cur->proximo != NULL)
        cur = cur->proximo;
    return cur;
}


// Partitions the list taking the last element as the pivot 

NO *partition(NO *head, NO *end, NO **newHead, NO **newEnd) {
    NO *pivot = end;
    NO *prev = NULL, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list might change 
    // which is updated in the newHead and newEnd variables 
    while (cur != pivot) {
        if (cur->item < pivot->item) {
            // First node that has a value less than the pivot - becomes 
            // the new head 
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->proximo;
        }
        else // If cur node is greater than pivot 
        {
            // Move cur node to next of tail, and change tail 
            if (prev){
                prev->proximo = cur->proximo;
            }
            NO *tmp = cur->proximo;
            cur->proximo = NULL;
            tail->proximo = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list, 
    // pivot becomes the head 
    if ((*newHead) == NULL)
        (*newHead) = pivot;

    // Update newEnd to the current last node 
    (*newEnd) = tail;

    // Return the pivot node 
    return pivot;
}


//here the sorting happens exclusive of the end node 

NO *quickSortRecur(NO *head, NO *end) {
    // base condition 
    if (!head || head == end)
        return head;

    NO *newHead = NULL, *newEnd = NULL;

    // Partition the list, newHead and newEnd will be updated 
    // by the partition function 
    NO *pivot = partition(head, end, &newHead, &newEnd);

    // If pivot is the smallest element - no need to recur for 
    // the left part. 
    if (newHead != pivot) {
        // Set the node before the pivot node as NULL 
        NO *tmp = newHead;
        while (tmp->proximo != pivot)
            tmp = tmp->proximo;
        tmp->proximo = NULL;

        // Recur for the list before pivot 
        newHead = quickSortRecur(newHead, tmp);

        // Change next of last node of the left half to pivot 
        tmp = getTail(newHead);
        tmp->proximo = pivot;
    }

    // Recur for the list after the pivot element 
    pivot->proximo = quickSortRecur(pivot->proximo, newEnd);

    return newHead;
}

// The main function for quick sort. This is a wrapper over recursive 
// function quickSortRecur() 

void quickSort(NO **headRef) {
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
