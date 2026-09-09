// A singly linked list containing both even and odd numbers is given. Write an l0
// algorithm to create two separate linked lists from the given LL, one containing
// only the given odd numbers and the other containing only the given even numbers.

// Initialize EVEN = NULL and ODD = NULL.
// Set TEMP = HEAD.
// Repeat while TEMP != NULL:
// If TEMP->data % 2 == 0, insert TEMP->data into the EVEN list.
// Otherwise, insert TEMP->data into the ODD list.
// Move TEMP to the next node: TEMP = TEMP->next.
// Display the EVEN list.
// Display the ODD list.
// Stop.