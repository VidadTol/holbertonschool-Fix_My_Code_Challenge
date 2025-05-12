#include "lists.h"
#include <stdlib.h>

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *tmp = *head;
    unsigned int p = 0;

    if (!head || !*head)
        return (-1);

    while (tmp && p < index)
    {
        tmp = tmp->next;
        p++;
    }

    if (!tmp)
        return (-1);

    tmp->n = 0;

    if (index == 0)
    {
        *head = tmp->next;
        if (*head)
            (*head)->prev = NULL;
    }
    else
    {
        if (tmp->prev)
            tmp->prev->next = tmp->next;
        if (tmp->next)
            tmp->next->prev = tmp->prev;
    }

    free(tmp);
    tmp = NULL;

    return (1);
}
