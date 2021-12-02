game: game.cpp game.hpp Ghost.cpp Ghost.hpp main.cpp SinGhost.cpp SinGhost.hpp
	g++ -o  play game.cpp game.hpp Ghost.cpp Ghost.hpp main.cpp SinGhost.cpp SinGhost.hpp `pkg-config --cflags --libs sdl2` -lSDL2_image
