
typedef struct _List List;
typedef struct _Iterator Iterator;
// Crea una lista vuota e restituisce la lista creata.
List *create_list();

// Accetta come input un puntatore a una lista e
// restituisce 1 se la lista è vuota (0 altrimenti).
// Il parametro di input non può essere NULL.
int list_is_empty(List *dinamic_array);

// Accetta come input un puntatore a una lista e
// restituisce il numero di elementi attualmente memorizzati nella lista.
// Il parametro di input non può essere NULL.
unsigned long list_size(List *lista);

// Accetta come input un puntatore a una lista.
// Rialloca memoria per duplicare la grandezza dell'array.
// Il parametro di input non può essere NULL.
void increse_memory(List *lista);

// Accetta come input un puntatore a una lista.
// Rialloca memoria per dimezzare la grandezza dell'array.
// Il parametro di input non può essere NULL.
void decrese_memory_unused(List *lista);

// Accetta come input un puntatore a una lista e un puntatore a un elemento.
// Aggiunge l'elemento in coda alla lista.
// I parametri di input non possono essere NULL.
void add_queue_element(List *lista,void* elem);


// Accetta come input un puntatore a una lista.
// Elimina l'elemento in coda all'array.
// Il parametro di input non può essere NULL.
void delete_queue_element(List *lista);

// Accetta come input un puntatore a una lista e un numero intero "index" e
// elimina l'i-esimo elemento della lista.
// Il primo parametro non può essere NULL; il secondo parametro deve essere una posizione valida
// all'interno della lista.
void delete_element(List *lista,unsigned long index);

// Accetta come input un puntatore a una lista e
// libera la memoria allocata per memorizzare la lista.
// Non libera la memoria allocata per memorizzare gli elementi della lista,
// poiché liberare quella memoria è responsabilità della funzione in cui
// la lista è stata creata.
// I parametri di input non possono essere NULL.
void list_free_memory(List *lista);

// Accetta come input un puntatore a una lista e un numero intero "index" e
// aggiunge all'i-esima posizione elem nella lista.
// Il primo parametro non può essere NULL; il secondo parametro deve essere una posizione valida
// all'interno della lista.
void add_element(List *lista,void* elem,long unsigned index);

// Accetta come input un puntatore a una lista e un numero intero "i" e
// restituisce il puntatore all'i-esimo elemento della lista
// Il primo parametro non può essere NULL; il secondo parametro deve essere una posizione valida
// all'interno della lista.
void* list_get(List *lista, unsigned long i);

// Accetta come input un puntatore a una lista
// crea un Iteratore per la lista passata come imput e restituisce il puntatore ad esso
// Il parametro di input non può essere NULL. 
Iterator *create_iterator(List *lista);

// Accetta come input un puntatore a una iteratore e
// libera la memoria allocata per memorizzarlo.
// I parametri di input non possono essere NULL.
void iterator_free_memory(Iterator *iteratore);

// Accetta come input un puntatore ad un iteratore
// restituisce l'elemento della lista alla posizione corrente dell' iteratore
// Il parametro input non può essere NULL.
void* iterator_get(Iterator *iteratore);

// Accetta come input un puntatore ad un iteratore
// imposta la posizione corrente dell' iteratore all'inizio della lista
// Il parametro input non può essere NULL.
void iterator_set_initial(Iterator *iteratore);

// Accetta come input un puntatore ad un iteratore
// imposta la posizione corrente dell' iteratore alla fine della lista
// Il parametro input non può essere NULL.
void iterator_set_end(Iterator *iteratore);

// Accetta come input un puntatore ad un iteratore
// incrementa la posizione corrente dell' iteratore
// Il parametro input non può essere NULL.
void iterator_increases(Iterator *iteratore);


// Accetta come input un puntatore ad un iteratore
// decrementa la posizione corrente dell' iteratore
// Il parametro input non può essere NULL.
void iterator_decreases(Iterator *iteratore);

// Accetta come input un puntatore ad un iteratore
// restituisce 1 se esiste un elemento sucessivo alla posizione corrente della lista (0 altrimenti)
// Il parametro input non può essere NULL.
int iterator_has_next(Iterator *iteratore);


// Accetta come input un puntatore ad un iteratore
// restituisce 1 se esiste un elemento precedente alla posizione corrente della lista (0 altrimenti)
// Il parametro input non può essere NULL.
int iterator_has_prev(Iterator *iteratore);

// Accetta come input un puntatore ad una lista
// Stampa la lista di input
// Il parametro input non può essere NULL. 
void print_List(List *lista);