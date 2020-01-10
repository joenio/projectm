projectM-gtk: projectM-gtk.cpp
	$(CXX) $? -o $@ `pkg-config gtkmm-3.0 gl --cflags --libs` -I../libprojectM -LprojectM/lib -lprojectM


clean:
	rm -f projectM-gtk
