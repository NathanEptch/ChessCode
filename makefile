SRC = src/#utilisable avec $(SRC)
SRC_PIECE = src/PieceDirectory/#pour les pièces spécifiquement
OBJ = obj/#utilisable avec $(OBJ)
BIN = bin/#utilisable avec $(BIN)


FLAGS = -Wall -ggdb

HERITAGE_PIECE = $(OBJ)Piece.o $(OBJ)Pawn.o $(OBJ)Rook.o $(OBJ)Knight.o $(OBJ)Bishop.o $(OBJ)King.o $(OBJ)Queen.o
LIST_OBJECTS = $(HERITAGE_PIECE) $(OBJ)Player.o $(OBJ)Configuration.o $(OBJ)DisplayText.o $(OBJ)DisplayGraphic.o $(OBJ)Game.o $(OBJ)SaveConfig.o $(OBJ)Vector2D.o $(OBJ)Timer.o $(OBJ)Menu.o $(OBJ)MenuTime.o

TEST = $(LIST_OBJECTS) $(OBJ)mainTest.o
MAIN = $(LIST_OBJECTS) $(OBJ)main.o

INCLUDE_SFML = -lsfml-system -lsfml-window -lsfml-graphics


chessCodeTest : dir $(TEST)
	g++ $(TEST) -o $(BIN)chessCodeTest $(INCLUDE_SFML)

chessCode : dir $(MAIN)
	g++ $(MAIN) -o $(BIN)chessCode $(INCLUDE_SFML)


dir:
	mkdir -p bin obj

$(OBJ)Player.o : $(SRC)Player.cpp $(SRC)Player.h
	g++ $(FLAGS) -c $(SRC)Player.cpp -o $(OBJ)Player.o

$(OBJ)Piece.o : $(SRC)Piece.cpp $(SRC)Piece.h
	g++ $(FLAGS) -c $(SRC)Piece.cpp -o $(OBJ)Piece.o


#Héritages de pieces
#---------------------------------------------------------------------------#

$(OBJ)Pawn.o : $(SRC_PIECE)Pawn.cpp $(SRC_PIECE)Pawn.h
	g++ $(FLAGS) -c $(SRC_PIECE)Pawn.cpp -o $(OBJ)Pawn.o

$(OBJ)Rook.o : $(SRC_PIECE)Rook.cpp $(SRC_PIECE)Rook.h
	g++ $(FLAGS) -c $(SRC_PIECE)Rook.cpp -o $(OBJ)Rook.o

$(OBJ)Knight.o : $(SRC_PIECE)Knight.cpp $(SRC_PIECE)Knight.h
	g++ $(FLAGS) -c $(SRC_PIECE)Knight.cpp -o $(OBJ)Knight.o

$(OBJ)Bishop.o : $(SRC_PIECE)Bishop.cpp $(SRC_PIECE)Bishop.h
	g++ $(FLAGS) -c $(SRC_PIECE)Bishop.cpp -o $(OBJ)Bishop.o

$(OBJ)King.o : $(SRC_PIECE)King.cpp $(SRC_PIECE)King.h
	g++ $(FLAGS) -c $(SRC_PIECE)King.cpp -o $(OBJ)King.o

$(OBJ)Queen.o : $(SRC_PIECE)Queen.cpp $(SRC_PIECE)Queen.h
	g++ $(FLAGS) -c $(SRC_PIECE)Queen.cpp -o $(OBJ)Queen.o

#---------------------------------------------------------------------------#

$(OBJ)Configuration.o : $(SRC)Configuration.cpp $(SRC)Configuration.h
	g++ $(FLAGS) -c $(SRC)Configuration.cpp -o $(OBJ)Configuration.o

$(OBJ)DisplayText.o : $(SRC)DisplayText.cpp $(SRC)DisplayText.h
	g++ $(FLAGS) -c $(SRC)DisplayText.cpp -o $(OBJ)DisplayText.o

$(OBJ)DisplayGraphic.o : $(SRC)DisplayGraphic.cpp $(SRC)DisplayGraphic.h
	g++ $(FLAGS) -c $(SRC)DisplayGraphic.cpp -o $(OBJ)DisplayGraphic.o

$(OBJ)Vector2D.o : $(SRC)Vector2D.cpp $(SRC)Vector2D.h
	g++ $(FLAGS) -c $(SRC)Vector2D.cpp -o $(OBJ)Vector2D.o

$(OBJ)Timer.o : $(SRC)Timer.cpp $(SRC)Timer.h
	g++ $(FLAGS) -c $(SRC)Timer.cpp -o $(OBJ)Timer.o

$(OBJ)Game.o : $(SRC)Game.cpp $(SRC)Game.h
	g++ $(FLAGS) -c $(SRC)Game.cpp -o $(OBJ)Game.o

$(OBJ)SaveConfig.o : $(SRC)SaveConfig.cpp $(SRC)SaveConfig.h
	g++ $(FLAGS) -c $(SRC)SaveConfig.cpp -o $(OBJ)SaveConfig.o

$(OBJ)Menu.o : $(SRC)Menu.cpp $(SRC)Menu.h
	g++ $(FLAGS) -c $(SRC)Menu.cpp -o $(OBJ)Menu.o

$(OBJ)MenuTime.o : $(SRC)MenuTime.cpp $(SRC)MenuTime.h
	g++ $(FLAGS) -c $(SRC)MenuTime.cpp -o $(OBJ)MenuTime.o

$(OBJ)main.o : $(SRC)main.cpp
	g++ $(FLAGS) -c $(SRC)main.cpp -o $(OBJ)main.o

$(OBJ)mainTest.o : $(SRC)mainTest.cpp
	g++ $(FLAGS) -c $(SRC)mainTest.cpp -o $(OBJ)mainTest.o

#Nettoyage du dossier
clean :
	rm $(OBJ)*.o

veryclean :
	rm $(OBJ)*.o $(BIN)*
