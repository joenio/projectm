# projectM-gtk

minimalist GUI for projectM in GTK

## Compilling requirements:

```console
apt install libgtkmm-3.0-dev build-essential
```

## Compile projectM-gtk:

```console
./configure --enable-gtk --enable-gles LIBS="-lQt5Gui -lQt5OpenGL"
```

## ISSUES

### Issue 1: undefined reference to symbol

```console
/usr/bin/ld: ../projectM-qt/libprojectM_qt.a(qprojectm_mainwindow.o): undefined reference to symbol '_ZN5QIconC1Ev@@Qt_5'
/usr/bin/ld: /usr/lib/x86_64-linux-gnu/libQt5Gui.so: error adding symbols: DSO missing from command line
collect2: error: ld returned 1 exit status
make[3]: *** [Makefile:494: projectM-jack] Error 1
make[3]: Leaving directory '/home/joenio/src/projectm/src/projectM-jack'
```

Solution to issue 1:

add the following flags to the `./configure` command: "LIBS="-lQt5Gui -lQt5OpenGL"

### Issue 2: Floating point exception

```console
./src/projectM-gtk/projectM-gtk
Failed to compile shader 'Vertex: v2f_c4f'. Error: 
Failed to compile shader 'Fragment: v2f_c4f'. Error: 
Failed to link program: 
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
Floating point exception
```
