#include <curses.h>
#include <menu.h>
#include <time.h>

#include "main.h"
#include "problems.h"

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4

char *choices[] = {
  "Problem 23",
  "Problem 33",
  "Problem 35",
  "Problem 36",
  "Problem 37",
  "Problem 38",
  "Problem 39",
  "Problem 41",
  "Problem 321",
  "Exit",
  (char *) NULL
};

WINDOW *problem_menu_win, *console_win, *output_win;

int main()
{	
  ITEM **problem_items;
	MENU *problem_menu;
  int n_choices, i, c, problem_index;
  
	/* Initialize curses */
	initscr();
	start_color();
  cbreak();
  noecho();
	keypad(stdscr, TRUE);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
  init_pair(3, COLOR_WHITE, COLOR_BLACK);
  
	/* Create items */
  n_choices = ARRAY_SIZE(choices);
  problem_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
  for(i = 0; i < n_choices; ++i)
    problem_items[i] = new_item(choices[i], "");
  
	/* Crate menu */
	problem_menu = new_menu((ITEM **)problem_items);
  
	/* Create the window to be associated with the menu */
  problem_menu_win = newwin(LINES - 1, 40, 0, 0);
  keypad(problem_menu_win, TRUE);
  
	/* Set main window and sub window */
  set_menu_win(problem_menu, problem_menu_win);
  set_menu_sub(problem_menu, derwin(problem_menu_win, ARRAY_SIZE(choices), 38, 3, 1));
	set_menu_format(problem_menu, n_choices, 1);
  
	/* Set menu mark to the string " * " */
  set_menu_mark(problem_menu, " * ");
  
	/* Print a border around the main window and print a title */
  box(problem_menu_win, 0, 0);
	print_in_middle(problem_menu_win, 1, 0, 40, "Problems", COLOR_PAIR(1));
	mvwaddch(problem_menu_win, 2, 0, ACS_LTEE);
	mvwhline(problem_menu_win, 2, 1, ACS_HLINE, 38);
	mvwaddch(problem_menu_win, 2, 39, ACS_RTEE);
  
	/* Post the menu */
	post_menu(problem_menu);
	wrefresh(problem_menu_win);
	
	attron(COLOR_PAIR(2));
	mvprintw(LINES - 1, 0, "Use the Arrow Keys to navigate.");
	attroff(COLOR_PAIR(2));
	refresh();
  
  console_win = newwin(LINES - 1, COLS - 40, 0, 40);
  box(console_win, 0, 0);
  
  print_in_middle(console_win, 1, 0, COLS - 40, "Project Euler", COLOR_PAIR(1));
  mvwaddch(console_win, 2, 0, ACS_LTEE);
	mvwhline(console_win, 2, 1, ACS_HLINE, COLS - 42);
	mvwaddch(console_win, 2, COLS - 41, ACS_RTEE);
  wrefresh(console_win);
  
  output_win = derwin(console_win, LINES - 5, COLS - 44, 3, 2);
//  box(output_win, 0, 0);
  
  set_description(output_win, problem_menu);
  
  wrefresh(output_win);
    
	while(c = getch())
	{    
    if(c == 10 && item_name(current_item(problem_menu)) == "Exit") break;    
    
    switch(c)
    {
        case KEY_DOWN:
          menu_driver(problem_menu, REQ_DOWN_ITEM);
          set_description(output_win, problem_menu);
          break;
        case KEY_UP:
          menu_driver(problem_menu, REQ_UP_ITEM);
          set_description(output_win, problem_menu);
          break;
        case KEY_NPAGE:
          menu_driver(problem_menu, REQ_SCR_DPAGE);
          break;
        case KEY_PPAGE:
          menu_driver(problem_menu, REQ_SCR_UPAGE);
          break;
        case 10:
        sscanf(item_name(current_item(problem_menu)), "%*s %i", &problem_index);
        run_problem(problem_index);
        break;
		}
    
    wrefresh(problem_menu_win);
    wrefresh(console_win);
    wrefresh(output_win);
	}	
  
	/* Unpost and free all the memory taken up */
  unpost_menu(problem_menu);
  free_menu(problem_menu);
  for(i = 0; i < n_choices; ++i)
    free_item(problem_items[i]);
	endwin();
}

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string, chtype color)
{
  int length, x, y;
	float temp;
  
	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;
  
	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	wattron(win, color);
	mvwprintw(win, y, x, "%s", string);
	wattroff(win, color);
	refresh();
}

void set_description(WINDOW *win, const MENU *menu)
{
  wclear(win);
  if (item_name(current_item(menu)) == "Problem 23") {
    mvwprintw(win, 0, 0, "Description:\n\n\n%s\n\n\nSolver output:\n\n\n", desc23());
  }
  else if (item_name(current_item(menu)) == "Problem 33") {
    mvwprintw(win, 0, 0, "Description:\n\n\n%s\n\n\nSolver output:\n\n\n", desc33());
  }
  else if (item_name(current_item(menu)) == "Problem 35") {
    mvwprintw(win, 0, 0, "Description:\n\n\n%s\n\n\nSolver output:\n\n\n", desc35());
  }
  else if (item_name(current_item(menu)) == "Problem 36") {
    mvwprintw(win, 0, 0, "Description:\n\n\n%s\n\n\nSolver output:\n\n\n", desc36());
  }
  else if (item_name(current_item(menu)) == "Problem 37") {
    mvwprintw(win, 0, 0, "Description:\n\n\n%s\n\n\nSolver output:\n\n\n", desc37());
  }
  else if (item_name(current_item(menu)) == "Problem 38") {
    mvwprintw(win, 0, 0, "Description:\n\n\n%s\n\n\nSolver output:\n\n\n", desc38());
  }
  else if (item_name(current_item(menu)) == "Problem 39") {
    mvwprintw(win, 0, 0, "Description:\n\n\n%s\n\n\nSolver output:\n\n\n", desc39());
  }
  else if (item_name(current_item(menu)) == "Problem 41") {
    mvwprintw(win, 0, 0, "Description:\n\n\n%s\n\n\nSolver output:\n\n\n", desc41());
  }
  else if (item_name(current_item(menu)) == "Problem 321") {
    mvwprintw(win, 0, 0, "Description:\n\n\n%s\n\n\nSolver output:\n\n\n", desc321());
  }
}

void run_problem(int number)
{
  char buf[1000000] = "";
  clock_t start, stop;
  double t = 0.0;
  int result;
  
//  mvwprintw(console_win, 1, 2, "Running problem %i...", number);
  
  start = clock();
  
  if(number == 23) {
    result = run23(buf);
  }
  else if(number == 33) {
    result = run33(buf);
  }
  else if (number == 35) {
    result = run35(buf);
  }
  else if (number == 36) {
    result = run36(buf);
  }
  else if (number == 37) {
    result = run37(buf);
  }
  else if (number == 38) {
    result = run38(buf);
  }
  else if (number == 39) {
    result = run39(buf);
  }
  else if (number == 41) {
    result = run41(buf);
  }
  else if (number == 321) {
    result = run321(buf);
  }
  
  stop = clock();
  
  
  wprintw(output_win, buf);
  mvwprintw(output_win, LINES - 8, 0, "Result: %i", result);
  wclrtoeol(output_win);
  
  t = (double) (stop - start) / CLOCKS_PER_SEC;
  mvwprintw(output_win, LINES - 6, 0, "Run time: %f seconds", t);
}