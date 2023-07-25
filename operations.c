/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 05:47:59 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/25 05:56:32 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct node    *sa(struct node *a,char *op)
{
    int		tmp;

    if (a->next)
    {
        tmp = a->data;
        a->data = a->next->data;
        a->next->data = tmp;
    }
    printf("%s\n",op);
    return (a);
}

struct node   *ra(struct node *a, int op)
{
    struct node *tmp;
    struct node *head;

    head = a;
    tmp = a;
    while (tmp->next)
        tmp = tmp->next;
    tmp->next = a;
    a = a->next;
    tmp->next->next = NULL;
    printf("%s\n",op);
    return (a);
}


