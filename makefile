game: game.cpp Ghost.cpp main.cpp SinGhost.cpp Player.cpp String_check.cpp
	g++ -o  play game.cpp Ghost.cpp main.cpp SinGhost.cpp Player.cpp String_check.cpp `pkg-config --cflags --libs sdl2` -lSDL2_image

game2: game.cpp game.hpp Ghost.cpp Ghost.hpp main.cpp SinGhost.cpp Player.cpp Player.hpp SinGhost.hpp String_check.cpp
	g++ -o play2 game.cpp game.hpp Ghost.cpp Ghost.hpp main.cpp SinGhost.cpp Player.cpp Player.hpp SinGhost.hpp `pkg-config --cflags --libs sdl2` -lSDL2_image

