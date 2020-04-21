#include "Mainwin.h"
#include "Entrydialog.h"
#include <sstream>
#include <fstream>
#include <iostream> // for std::cerr logging

Mainwin::Mainwin() : store{new Store{}} {

    // /////////////////
    // G U I   S E T U P
    // /////////////////
    
    filename = "untitled.elsa";

    set_default_size(400, 200);
    set_title("E.L.S.A.");

    // Put a vertical box container as the Window contents
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    // /////// ////////////////////////////////////////////////////////////////
    // M E N U
    // Add a menu bar as the top item in the vertical box
    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    // vbox->add(*menubar);

    //     F I L E
    // Create a File menu and add to the menu bar
    Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
    menubar->append(*menuitem_file);
    Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
    menuitem_file->set_submenu(*filemenu);

    //         Q U I T
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
    menuitem_quit->signal_activate().connect([this] {this->on_quit_click();});
    filemenu->append(*menuitem_quit);
    
    //         S A V E 
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_save = Gtk::manage(new Gtk::MenuItem("_Save", true));
    menuitem_save->signal_activate().connect([this] {this->on_save_click();});
    filemenu->append(*menuitem_save);
    
    //         S A V E A S
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_saveas = Gtk::manage(new Gtk::MenuItem("Save _As", true));
    menuitem_saveas->signal_activate().connect([this] {this->on_save_as_click();});
    filemenu->append(*menuitem_saveas);
    
    //         O P E N
    // Append Quit to the File menu
    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Open", true));
    menuitem_open->signal_activate().connect([this] {this->on_open_click();});
    filemenu->append(*menuitem_open);
    
    //     V I E W
    // Create a View menu and add to the menu bar
    Gtk::MenuItem *menuitem_view = Gtk::manage(new Gtk::MenuItem("_View", true));
    menubar->append(*menuitem_view);
    Gtk::Menu *viewmenu = Gtk::manage(new Gtk::Menu());
    menuitem_view->set_submenu(*viewmenu);
    
    //           P E R I P H E R A L
    // Append peripheral to the View menu
    Gtk::MenuItem *menuitem_vperipheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
    menuitem_vperipheral->signal_activate().connect([this] {this->on_view_peripheral_click();});
    viewmenu->append(*menuitem_vperipheral);
    
    //           D E S K T O P
    // Append desktop to the View menu
    Gtk::MenuItem *menuitem_vdesktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
    menuitem_vdesktop->signal_activate().connect([this] {this->on_view_desktop_click();});
    viewmenu->append(*menuitem_vdesktop);
    
    //           O R D E R
    // Append order to the View menu
    Gtk::MenuItem *menuitem_vorder = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_vorder->signal_activate().connect([this] {this->on_view_order_click();});
    viewmenu->append(*menuitem_vorder);
    
    //           C U S T O M E R
    // Append customer to the View menu
    Gtk::MenuItem *menuitem_vcustomer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_vcustomer->signal_activate().connect([this] {this->on_view_customer_click();});
    viewmenu->append(*menuitem_vcustomer);
    
    //     I N S E R T
    // Create a Insert menu and add to the menu bar
    Gtk::MenuItem *menuitem_insert = Gtk::manage(new Gtk::MenuItem("_Insert", true));
    menubar->append(*menuitem_insert);
    Gtk::Menu *insertmenu = Gtk::manage(new Gtk::Menu());
    menuitem_insert->set_submenu(*insertmenu);
    
    //           P E R I P H E R A L
    // Append peripheral to the Insert menu
    Gtk::MenuItem *menuitem_peripheral = Gtk::manage(new Gtk::MenuItem("_Peripheral", true));
    insertmenu->append(*menuitem_peripheral);
    Gtk::Menu *peripheralmenu = Gtk::manage(new Gtk::Menu());
    menuitem_peripheral->set_submenu(*peripheralmenu);
    
    //           G E N E R I C
    // Append peripheral to the Insert menu
    Gtk::MenuItem *menuitem_generic = Gtk::manage(new Gtk::MenuItem("_Generic", true));
    menuitem_generic->signal_activate().connect([this] {this->on_insert_generic_click();});
    peripheralmenu->append(*menuitem_generic);
    
    //           R A M
    // Append peripheral to the Insert menu
    Gtk::MenuItem *menuitem_ram = Gtk::manage(new Gtk::MenuItem("_Ram", true));
    menuitem_ram->signal_activate().connect([this] {this->on_insert_ram_click();});
    peripheralmenu->append(*menuitem_ram);
    
    
    //           D E S K T O P
    // Append desktop to the Insert menu
    Gtk::MenuItem *menuitem_idesktop = Gtk::manage(new Gtk::MenuItem("_Desktop", true));
    menuitem_idesktop->signal_activate().connect([this] {this->on_insert_desktop_click();});
    insertmenu->append(*menuitem_idesktop);
    
    //           O R D E R
    // Append order to the Insert menu
    Gtk::MenuItem *menuitem_iorder = Gtk::manage(new Gtk::MenuItem("_Order", true));
    menuitem_iorder->signal_activate().connect([this] {this->on_insert_order_click();});
    insertmenu->append(*menuitem_iorder);
    
    //           C U S T O M E R
    // Append customer to the Insert menu
    Gtk::MenuItem *menuitem_icustomer = Gtk::manage(new Gtk::MenuItem("_Customer", true));
    menuitem_icustomer->signal_activate().connect([this] {this->on_insert_customer_click();});
    insertmenu->append(*menuitem_icustomer);

    //     H E L P
    // Create a Help menu and add to the menu bar
    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
    menubar->append(*menuitem_help);
    Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
    menuitem_help->set_submenu(*helpmenu);

    //           A B O U T
    // Append About to the Help menu
    Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
    menuitem_about->signal_activate().connect([this] {this->on_about_click();});
    helpmenu->append(*menuitem_about);
     
    // /////////////////////////// ////////////////////////////////////////////
    // S T I C K S   D I S P L A Y
    // Provide a text entry box to show the remaining sticks
    data = Gtk::manage(new Gtk::Label());
    data->set_hexpand(true);
    data->set_vexpand(true);
    vbox->add(*data);
    
    // S T A T U S   B A R   D I S P L A Y ////////////////////////////////////
    // Provide a status bar for game messages
    msg = Gtk::manage(new Gtk::Label());
    msg->set_hexpand(true);
    vbox->pack_start(*msg, Gtk::PACK_SHRINK, 0);
    // vbox->add(*msg);
    // Make the box and everything in it visible
    
    std::ostringstream oss;
    oss << R"(		
			         	===============
			         	Welcome to ELSA
			         	===============

   Exceptional Laptops and Supercomputers Always!)";
   set_data(oss.str());

    vbox->show_all();
}

Mainwin::~Mainwin() { }

// /////////////////
// C A L L B A C K S
// /////////////////

void Mainwin::on_quit_click() {
    close();
}

void Mainwin::on_about_click() {
    Gtk::AboutDialog dialog;
    dialog.set_transient_for(*this); // Avoid the discouraging warning
    dialog.set_program_name("E.L.S.A.");
    auto logo = Gdk::Pixbuf::create_from_file("super_computer.jpg");
    dialog.set_logo(logo);
    dialog.set_version("Version 0.1");
    dialog.set_copyright("Copyright 2020");
    dialog.set_license_type(Gtk::License::LICENSE_GPL_3_0);
    std::vector< Glib::ustring > authors = {"Ahmed N. Malabi"};
    dialog.set_authors(authors);
    std::vector< Glib::ustring > artists = {
        "Logo by NASA, licensed under CC BY-SA 3.0 https://www.rawpixel.com/image/440048/supercomputer"};
    dialog.set_artists(artists);
    dialog.run();
}

/////////////
// V I E W //
/////////////

void Mainwin::on_view_peripheral_click()
{
	std::ostringstream oss;
	for(int i=0; i<store->num_options(); ++i) 
		oss << i << ") " << store->option(i) << "\n";
	set_data(oss.str());
}

void Mainwin::on_view_desktop_click()
{
	std::ostringstream oss;
	for(int i=0; i<store->num_desktops(); ++i) 
        oss << i << ") " << store->desktop(i) << "\n";
    set_data(oss.str());
}

void Mainwin::on_view_order_click()
{
	std::ostringstream oss;
	for(int i=0; i<store->num_orders(); ++i) 
        oss << i << ") " << store->order(i) << "\n";
    set_data(oss.str());
}

void Mainwin::on_view_customer_click()
{
	std::ostringstream oss;
	for(int i=0; i<store->num_customers(); ++i)
    	oss << i << ") " << store->customer(i) << "\n";
	set_data(oss.str());
}

/////////////////
// I N S E R T //
/////////////////

void Mainwin::on_insert_generic_click()
{
	Gtk::Dialog dialog{"Insert a Generic Product",*this};
	Gtk::Grid grid;
	
	Gtk::Label g_name{"Name"};
	Gtk::Entry n_entry;
	grid.attach(g_name,0,0,1,1);
	grid.attach(n_entry,1,0,2,1);
	
	Gtk::Label g_cost{"Cost"};
	Gtk::Entry c_entry;
	grid.attach(g_cost,0,1,1,1);
	grid.attach(c_entry,1,1,2,1);
	
	dialog.get_content_area()->add(grid);
	
	dialog.add_button("Insert", Gtk::RESPONSE_OK);
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
	
	dialog.show_all();
	
	int response;

	std::string name, cost;
	
	while((response = dialog.run()) == Gtk::RESPONSE_OK)
	{
		if((n_entry.get_text().size() == 0) || (c_entry.get_text().size() == 0))
		{
			if(n_entry.get_text().size() == 0)
				n_entry.set_text("NAME REQUIRED");
				
			if(c_entry.get_text().size() == 0)
				c_entry.set_text("COST REQUIRED");
				
			continue;
		}
		
		name = n_entry.get_text();
		cost = c_entry.get_text();
		Options* option = new Options{name, std::stod(cost)};
		store->add_option(*option);
		n_entry.set_text("");
		c_entry.set_text("");
	}
	on_view_peripheral_click();
}

void Mainwin::on_insert_ram_click()
{
	Gtk::Dialog dialog{"Insert a Generic Product",*this};
	Gtk::Grid grid;
	
	Gtk::Label r_name{"Name"};
	Gtk::Entry n_entry;
	grid.attach(r_name,0,0,1,1);
	grid.attach(n_entry,1,0,2,1);
	
	Gtk::Label r_gb{"Size"};
	Gtk::Entry g_entry;
	grid.attach(r_gb,0,1,1,1);
	grid.attach(g_entry,1,1,2,1);
	
	Gtk::Label r_cost{"Cost"};
	Gtk::Entry c_entry;
	grid.attach(r_cost,0,2,1,1);
	grid.attach(c_entry,1,2,2,1);
	
	dialog.get_content_area()->add(grid);
	
	dialog.add_button("Insert", Gtk::RESPONSE_OK);
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
	
	dialog.show_all();
	
	int response;

	std::string name, gb, cost;
	
	while((response = dialog.run()) == Gtk::RESPONSE_OK)
	{
		if((n_entry.get_text().size() == 0) || (c_entry.get_text().size() == 0) || (g_entry.get_text().size() == 0))
		{
			if(n_entry.get_text().size() == 0)
				n_entry.set_text("NAME REQUIRED");
				
			if(g_entry.get_text().size() == 0)
				g_entry.set_text("SIZE REQUIRED");
				
			if(c_entry.get_text().size() == 0)
				c_entry.set_text("COST REQUIRED");
				
			continue;
		}
		
		name = n_entry.get_text();
		gb = g_entry.get_text();
		cost = c_entry.get_text();
		Ram* ram = new Ram{name, std::stod(cost), std::stoi(gb)};
		store->add_option(*ram);
		n_entry.set_text("");
		g_entry.set_text("");
		c_entry.set_text("");
	}
	on_view_peripheral_click();
}

void Mainwin::on_insert_desktop_click()
{
	int desktop = store->new_desktop();
	std::ostringstream oss;
        while(true) {
        	oss.str("");
            oss << store->desktop(desktop) << "\n\n";
            for(int i=0; i<store->num_options(); ++i) 
            	oss << i << ") " << store->option(i) << '\n';
        	set_data(oss.str());
            int option = get_int("<b>Add which peripheral (cancel when done)</b>");
            if(option == -1 || option > store->num_options()) break;
            try {
                store->add_option(option, desktop);
            } catch(std::exception& e) {
                std::cerr << "#### INVALID OPTION ####\n\n";
            }
        }
        on_view_desktop_click();
}

void Mainwin::on_insert_order_click()
{
	std::ostringstream oss;
	for(int i=0; i<store->num_customers(); ++i) 
        oss << i << ") " << store->customer(i) << '\n';
        set_data(oss.str());
    int customer = get_int("<b>Which customer</b>");

    int order = store->new_order(customer);

    while(true) {
    oss.str("");
        for(int i=0; i<store->num_desktops(); ++i) 
        	oss << i << ") " << store->desktop(i) << '\n';
        set_data(oss.str());
        int desktop = get_int("<b>Which desktop</b>");
        if(desktop == -1 || desktop > store->num_desktops()) break;
        store->add_desktop(desktop, order);
    }
    oss << "\n++++ Order Placed ++++\n" << store->order(order);
    on_view_order_click();
}

void Mainwin::on_insert_customer_click()
{
	Gtk::Dialog dialog{"Insert a Customer",*this};
	Gtk::Grid grid;
	
	Gtk::Label c_name{"Name"};
	Gtk::Entry n_entry;
	grid.attach(c_name,0,0,1,1);
	grid.attach(n_entry,1,0,2,1);
	
	Gtk::Label c_phone{"Phone"};
	Gtk::Entry p_entry;
	grid.attach(c_phone,0,1,1,1);
	grid.attach(p_entry,1,1,2,1);

	Gtk::Label c_email{"Email"};
	Gtk::Entry e_entry;
	grid.attach(c_email,0,2,1,1);
	grid.attach(e_entry,1,2,2,1);
	
	dialog.get_content_area()->add(grid);
	
	dialog.add_button("Insert", Gtk::RESPONSE_OK);
	dialog.add_button("Cancel", Gtk::RESPONSE_CANCEL);
	
	dialog.show_all();
	
	int response;

	std::string name, phone, email;
	
	while((response = dialog.run()) == Gtk::RESPONSE_OK)
	{
		if((n_entry.get_text().size() == 0) || (p_entry.get_text().size() == 0) || (e_entry.get_text().size() == 0))
		{
			if(n_entry.get_text().size() == 0)
				n_entry.set_text("NAME REQUIRED");
				
			if(p_entry.get_text().size() == 0)
				p_entry.set_text("PHONE REQUIRED");
				
			if(e_entry.get_text().size() == 0)
				e_entry.set_text("EMAIL REQUIRED");
			continue;
		}
		
		name = n_entry.get_text();
		phone = p_entry.get_text();
		email = e_entry.get_text();
		Customer customer{name, phone, email};
		store->add_customer(customer);
		n_entry.set_text("");
		p_entry.set_text("");
		e_entry.set_text("");
	}
	on_view_customer_click();
}

void Mainwin::on_save_click()
{
    try {
        std::ofstream ofs{filename};
        store->save(ofs);
        if(!ofs) throw std::runtime_error{"Error writing file"};
    } catch(std::exception& e) {
        Gtk::MessageDialog{*this, "Unable to save file"}.run();
    }
}

void Mainwin::on_save_as_click()
{
	Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FileChooserAction::FILE_CHOOSER_ACTION_SAVE);
    dialog.set_transient_for(*this);

    auto filter_elsa = Gtk::FileFilter::create();
    filter_elsa->set_name("ELSA files");
    filter_elsa->add_pattern("*.elsa");
    dialog.add_filter(filter_elsa);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename("untitled.elsa");
    filename = dialog.get_filename();

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Save", 1);

    int result = dialog.run();

    if (result == 1)
		on_save_click();
}

void Mainwin::on_open_click()
{
	Gtk::FileChooserDialog dialog("Please choose a file", Gtk::FileChooserAction::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    auto filter_elsa = Gtk::FileFilter::create();
    filter_elsa->set_name("ELSA files");
    filter_elsa->add_pattern("*.elsa");
    dialog.add_filter(filter_elsa);
 
    auto filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    dialog.set_filename(filename);

    //Add response buttons the the dialog:
    dialog.add_button("_Cancel", 0);
    dialog.add_button("_Open", 1);

    int result = dialog.run();

    if (result == 1) {
        try {
            delete store;
            std::ifstream ifs{filename};
            store = new Store{ifs};
            if(!ifs) throw std::runtime_error{"File contents bad"};
            std::ostringstream oss;
    		oss << R"(		
						     	===============
						     	Welcome to ELSA
						     	===============

   			Exceptional Laptops and Supercomputers Always!)";
   set_data(oss.str());
        } catch (std::exception& e) {
            Gtk::MessageDialog{*this, "Unable to open file"}.run();
        }
    }
}

///////////////////////
// U T I L I T I E S //
///////////////////////

///////////
// S E T //
///////////

void Mainwin::set_data(std::string s)
{
	data->set_markup(s);
}

void Mainwin::set_msg(std::string s)
{
	msg->set_markup(s);
}

///////////
// G E T //
///////////

std::string Mainwin::get_string(std::string prompt)
{
	EntryDialog edialog{*this, prompt, true};
    edialog.set_text("Enter in alpha caracters (a-z) (A-Z)");
    edialog.run();
    
    return edialog.get_text();
}

double Mainwin::get_double(std::string prompt)
{
	EntryDialog edialog{*this, prompt, true};
    edialog.set_text("Enter in numeric caracters and a decimal (234.56)");
    edialog.run();
    
    double temp;
    
    try
    {
    	temp = std::stod(edialog.get_text());
    }
    catch (std::exception& e)
    {
    	temp = -1.0;
    }
    return temp;
}

int Mainwin::get_int(std::string prompt)
{
	EntryDialog edialog{*this, prompt, true};
    edialog.set_text("Enter in numeric characters (123)");
    edialog.run();
    
    int temp;
    
    try
    {
    	temp = std::stod(edialog.get_text());
    }
    catch (std::exception& e)
    {
    	temp = -1;
    }
    return temp;
}
