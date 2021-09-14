#ifndef UI_H
#define UI_H
#include "service.h"


void runAppUI();
void add_ui_expense(Expenses* expense, Lista* undo_list);
void print_expense(Lista* l);
void print_expenses(Expenses* expense);
void filter_ui_by_tip(Expenses* expense);
void filter_ui_by_sum(Expenses* expense);
void filter_ui_by_day(Expenses* expense);
void sort_ui_by_sum(Expenses* expense);
void sort_ui_expense(Expenses* expense);
void sort_ui_expense1(Expenses* expense);
void sort_ui_expense2(Expenses* expense);
void sort_ui_expense3(Expenses* expense);
void set_ui_expense(Expenses* expense, Lista* undo_list);
void delete_ui_expense(Expenses* expense, Lista* undo_list);


/*
* CODE ADDED BY HATNEAN CRISTINA
*/
/*
* Functie ui care citeste o zi si afiseaza toate cheltuielile efectuate inainte de ziua respectiva
* input: expense - Expenses, lista de cheltuieli din service
*/

void filter_ui_by_zi(Expenses* expense);
void undo(Expenses* expense, Lista* undo_list);
void sort_perioada(Expenses* expense);

#endif /*UI_H*/
