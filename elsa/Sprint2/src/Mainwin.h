#ifndef __MAINWIN_H
#define __MAINWIN_H

#include <gtkmm.h>
#include "Store.h"

class Mainwin : public Gtk::Window {
    public:
        Mainwin();
        virtual ~Mainwin();
    protected:
		void on_view_peripheral_click();
		void on_view_desktop_click();
		void on_view_order_click();
		void on_view_customer_click();
		
		void on_insert_peripheral_click();
		void on_insert_desktop_click();
		void on_insert_order_click();
		void on_insert_customer_click();
		
		std::string get_string(std::string prompt);
		double get_double(std::string prompt);
		int get_int(std::string prompt);
		
		void set_data(std::string s);
		void set_msg(std::string s);
		
        void on_about_click();             // Display About dialog
        void on_quit_click();              // Exit the program
    private:
        Store* store;

        Gtk::Label* data;
        Gtk::Label* label;
};

#endif 

