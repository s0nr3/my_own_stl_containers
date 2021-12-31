make:
	g++ -std=c++11 -std=gnu++11 -pedantic -Wall -fno-elide-constructors iterable.cpp gtuvector.cpp gtuset.cpp gtuarray.cpp main.cpp -o driver