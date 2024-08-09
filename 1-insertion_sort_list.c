#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)

{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	/* Boucle pour déplacer l'élément `temp` vers sa position correcte. */
	while (current != NULL)
	{
		temp = current;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/* Réajuste les pointeurs pour enlever temp de sa position actuelle */
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;
			/* Insère `temp` avant son prédécesseur. */
			temp->next = temp->prev;
			temp->prev = temp->prev->prev;

			temp->next->prev = temp;

			if (temp->prev != NULL)
				temp->prev->next = temp;
			/* Si temp est le nouveau premier élément, ajuste la tête de la liste */
			else
				*list = temp;
			/* Affiche la liste après chaque échange. */
			print_list(*list);
		}
		/* Passe à l'élément suivant de la liste. */
		current = current->next;
	}
}
