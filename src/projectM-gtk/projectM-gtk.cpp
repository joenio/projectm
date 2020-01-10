#define USE_GLES 1

#include <gtkmm.h>
#include <projectM.hpp>
#include <Renderer/Shader.hpp>
#include <iostream>

//#include "projectM-opengl.h"
//#include <GL/gl.h>


projectM *globalPM;

void initialize_projectm() {
  projectM::Settings settings;
  settings.windowHeight = 400;
  settings.windowWidth = 800;
  settings.presetURL = "/home/joenio/bin/projectm/share/projectM/presets";
  settings.smoothPresetDuration = 5;
  settings.presetDuration = 30;
  settings.shuffleEnabled = true;
  std::cout << "DEBUG inicio" << std::endl;
  globalPM = new projectM(settings);
  std::cout << "DEBUG fim" << std::endl;
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
