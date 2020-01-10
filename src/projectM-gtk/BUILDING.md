compilar projectM-qt:
./configure --enable-qt --enable-gles LIBS="-lQt5Gui -lQt5OpenGL"

instalar para poder compilar o projectM-gtk e executar tb:
./configure --enable-qt --enable-gles LIBS="-lQt5Gui -lQt5OpenGL" --prefix=$(pwd)/src/projectM-gtk/projectM
make install

export LD_LIBRARY_PATH=$(pwd)/projectM/lib

apt install libgtkmm-3.0-dev build-essential

para buildar é necessário indicar local com os arquivos .so libprojectM.so
para isso buildo o projectM passando o paramentro .configure --prefix=/tmp/projectm
e depois o Makefile do projectM-gtk faz o resto, ele referencia o /tmp/projectM

sem essa gambiarra acima dá erro na linkedição da seguinte forma:

g++ projectM-gtk.cpp -o projectM-gtk `pkg-config gtkmm-3.0 --cflags --libs` -I../libprojectM -I../libprojectM/Renderer
/usr/bin/ld: /tmp/ccnU1d2o.o: na função "initialize_projectm()":
projectM-gtk.cpp:(.text+0xc2): referência não definida para "projectM::projectM(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, int)"
collect2: error: ld returned 1 exit status

por algum motivo os arquivos .so somente são gerados após o make install

para executar é preciso uma segunda gambiarra e setar o LD_LIBRARY_PATH para o /tmp/projectm/libs
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/taylor


com toda essa gaambiarra consegui compilar e executar, mas a execução finaliza com erro:


./projectM-gtk 
[projectM] config file: config.inp
Failed to compile shader 'Fragment: v2f_c4f'. Error: 
Failed to compile shader 'Vertex: v2f_c4f_t2f'. Error: 
Failed to compile shader 'Fragment: v2f_c4f_t2f'. Error: 
Failed to link program: 
Failed to compile shader 'Vertex: blur1'. Error: 
Failed to compile shader 'Fragment: blur1'. Error: 
Failed to link program: 
Failed to compile shader 'Vertex: blur2'. Error: 
Failed to compile shader 'Fragment: blur2'. Error: 
Failed to link program: 
[PresetFactory] url is idle://Geiss & Sperl - Feedback (projectM idle HDR mix).milk
Exceção de ponto flutuante

algumas issues citam erros parecidos e dao a dica de habilitar --enable-gles

$as_echo "#define USE_GLES 1" >>confdefs.h
