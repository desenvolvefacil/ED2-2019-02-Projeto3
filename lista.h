/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   lista.h
 * Author: Carlao
 *
 * Created on 14 de Maio de 2019, 13:35
 */

#ifndef LISTA_H
#define LISTA_H

/* substitua "elemento" pelo tipo de dado utilizado */
typedef struct node {
    int item;
    struct node *proximo;
} NO;

typedef struct {
    NO *inicio;
} LISTA;

/********************************************************************
 * Metodos da Lista
 *******************************************************************/
LISTA *criar_lista(void);

int inserir_inicio(LISTA *lista, int item);

void imprimir_lista(LISTA *lista);

void apagar_lista(LISTA *lista);

/******************************************************************
 * Metodos do Quick Sort
 *******************************************************************/


// Returns the last node of the list 
NO * getTail(NO *cur);

// Partitions the list taking the last element as the pivot 
NO * partition(NO *head, NO *end, NO **newHead, NO **newEnd);


//here the sorting happens exclusive of the end node 
NO * quickSortRecur(NO *head, NO *end);

// The main function for quick sort. This is a wrapper over recursive 
// function quickSortRecur() 
void quickSort(NO **headRef);


#endif /* LISTA_H */

