#include <gtkmm.h>

int main(int argc, char **argv) {
  auto app = Gtk::Application::create(argc, argv, "net.sourceforge.projectM-gtk");
  Gtk::Window window;
  window.set_default_size(800, 400);
  //window.set_title("projectM");
  return app->run(window);
}
