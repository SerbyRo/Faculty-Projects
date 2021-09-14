#ifndef UI_H
#define UI_H
#include "service.h"


void runAppUI();
void add_ui_expense(Expenses* expense);
void print_expense(Lista* l);
void print_expenses(Expenses* expense);
void filter_ui_by_tip(Expenses* expense);
void sort_ui_by_sum(Expenses* expense);
void sort_ui_expense(Expenses* expense);
void sort_ui_expense1(Expenses* expense);
void set_ui_expense(Expenses* expense);
void delete_ui_expense(Expenses* expense);

#endif /*UI_H*/
