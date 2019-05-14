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
    int nroInscricao;
    double nota;
    char data[11];
    int tamanhoCidade;
    char cidade[100];
    int tamanhoEscola;
    char nomeEscola[100];

    struct node *proximo;
} NO;

typedef struct {
    NO *inicio;
} LISTA;

/********************************************************************
 * Metodos da Lista
 *******************************************************************/
LISTA *listaCriar(void);

int listarInserirInicio(LISTA *lista, int item);

void listarImprimir(LISTA *lista);

void listarApagar(LISTA *lista);

/******************************************************************
 * Metodos do Quick Sort
 *******************************************************************/


/**
 * Retorna o ultimo no da lista
 * @param cur
 * @return 
 */
NO * qsUltimoNo(NO *cur);

/**
 * Particiona a lista tomando o último elemento como o pivo
 * @param inicio
 * @param fim
 * @param novoInicio
 * @param novoFim
 * @return retorna o novo pivot
 */
NO * qsParticionar(NO *inicio, NO *fim, NO **novoInicio, NO **novoFim);

/**
 * Faz a classificação exclusiva do no final
 * @param inicio
 * @param fim
 * @return novo inicio da lista
 */
NO * qsRecursao(NO *inicio, NO *fim);

/**
 * Função para ordenar uma lista
 * @param cabeca da lista
 */
void qsOrdernarLista(NO **cabeca);


#endif /* LISTA_H */

