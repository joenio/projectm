#include <gtkmm.h>
#include <projectM.hpp>

projectM *globalPM;

void initialize_projectm() {
  projectM::Settings settings;
  settings.windowHeight = 400;
  settings.windowWidth = 800;
  settings.presetURL = "/home/joenio/bin/projectm/share/projectM/presets";
  settings.smoothPresetDuration = 5;
  settings.presetDuration = 30;
  settings.shuffleEnabled = 1;
  settings.meshX = 48;
  settings.meshY = 32;
  settings.textureSize = 2048;
  settings.beatSensitivity = 0.8;
  settings.aspectCorrection = 1;
  settings.menuFontURL = "/home/joenio/bin/projectm/share/projectM/fonts/Vera.ttf";
  settings.titleFontURL = "/home/joenio/bin/projectm/share/projectM/fonts/Vera.ttf";
  globalPM = new projectM(settings);
  globalPM->projectM_resetGL(200, 200);
}

int main(int argc, char **argv) {
  auto app = Gtk::Application::create(argc, argv, "net.sourceforge.projectM-gtk");
  Gtk::Window window;
  window.set_default_size(800, 400);
  window.set_title("projectM");
  initialize_projectm();
  return app->run(window);
}
