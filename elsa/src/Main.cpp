#include "Mainwin.h"

int main (int argc, char *argv[]) {
    srand (time(NULL));
    auto app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.elsa.v0_1");
    Mainwin win;
    return app->run(win);
}

