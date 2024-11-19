#### Documentation Technique
Ce code est un jeu basé sur du texte écrit en C++. 


#### Class Tile ####

## Attributes : 
    - Bool shape[6][6] = store the tile in the 6x6 array

## Methods :
    - Tile() = default construtor

    - Tile(nlohmann::json d) = surcharged constructor who takes the tile from the json file 'Tilelist.json' as a parameter

    - ~Tile() = default destructor

    - get_cell() = return a cell from the 6x6 grid containing the tile

    - display() = display the tile

    - deep_copy(bool(&tmp_sh)[6][6]) = copy the tile into a temporary variable to rotate / flip it

    - deep_past(bool(tmp_sh)[6][6]) = past the tile once it's been rotated or flipped

    - flip_h() = flip the tile horizontally

    - flip_v() = flip the tile vertically

    - rotate() = rotate the tile counter clockwise


#### Class Player ####

## Attributes :
    - Char character = character to display on the board for the player

    - std::string name = name of the player

    - int exchange_number = counter of exchange coupons

## Methods :
    - Player(std::string n, char c) = surcharged constructor who takes the name of the player and his character and sets the exchange_number to 1

    - ~Player() = default destructor

    - get_name() = getter for the attribute name

    - get_exchange_number() = getter for the attribute exchange_number

    - increment_exchange_number() = increment the value of exchange_number

    - decrement_exchange_number() = decrement the value of exchange_number

    - get_char() = getter for the attribute character


  
#### Class Color ####

## Attributes :
    -int color = store the color of the player

    -std::map<int, std::string> indexes = store all the different 

## Methods :
    - Color() = default constructor

    - Color(int c) = surcharged constructor who takes the value of the index for the color

    - color_set() = setter for the color of the player

    - colorize_text(std::string text) = return the text with the appropriate color

    - init_indexes() = reference the different color id for each index


#### Class Board ####

## Attributes :
    - std::vector<std::vector<char>> board = vector who contains the board

    - Color color = store the instance of the class Color

    - int board_size = store the size of the board

    - int player_number = store the number of players

## Methods
    - Board() = default constructor

    - Board(int player_number) = surcharged constructor who takes the number of players as a parameter 

    - init_bonuses() = set the values for the total of each bonuses available on the board depending on the number of players

    - set_bonuses() = set the different bonuses on the board
    
    - display_board_x_board() = display the coords for x (lines)

    - display_board_char(int x, int y) =  display the different tiles with the color of the player

    - display_board() = display the board with the y axes (column)

    - check_victory() = check at the end of the game who won

    - place_base(char player, int x, int y) = place base grass tile at the start of the game

    - is_enemy_close(int x, int y, char player) = check if the enemy is close to the cell selected with input x and y

    - can_place_tile(Tile tile, int x, int y, char player) = return true if the tile can be placed in the selected cell

    - tile_apply(Tile tile, int x, int y, char player) = place the tile on the board

    - place_tile(Tile tile, int x, int y, char player) = if tile_apply is true then we call tile_apply in place_tile

    - rob_tile() = rob a 1x1 tile using the bonus rebbery

    - place_stone(int x, int y) = place a stone using the bonus stone in the cell selected with x and y  

    - check_neighborhood(int x, int y, char goal) = check the cell north south east west of the selected cell 

    - bonus_check() = check if a bonus cell is surrounded. if the bonus is surrounded then it increment the counter for the bonus (stone, robbery, tile exchange)

    - buy_grass_tile(int x, int y, char player) = place a 1x1 grass tile for a tile exchange coupons once all turns have been played 



#### Class Game ####

## attributes :
    - int tiles_number = contains the total of tiles for 1 player 

    - int players_number = contains the total of players

    - std::queue<Tile> tiles_queue = contains all 96 tiles in one queue

    - Board board = contains the instance of the class Board

    - std::vector<Player> players = vector who contains all the instances of Player

    - int player_turn = contains the total of turns based on the number of players
## methods

    - init_players() = create instances for all players depending on the number of players

    - init_queue() = create queue with all 96 tiles in a random order

    - tiles_queue_randomize(nlohmann::json data) = randomize the tiles in the queue

    - generate_rand_ind(int(&rand_tile_ind)[96]) = generate a random number for the randomazitaion of the tiles in the queue

    - queue_has_number(int number, int rand_tile_ind[96]) = vérification de l'état de la queue

    - display_current_next_tiles_queued(std::queue<Tile> queue) = display current tile in use and the next 5 tiles to come in the queue

    - display_turn_actions(int exchange_number) = display the actions menu for each turn and return the action

    - game_loop() = main loop of the game. this method handles the processing of each turn during the game until the game is finished

    - interpret_coords(char& x, char& y) = interpret the input given in the game exemple : x : A y : B

    - ask_coords(char& user_x, char& user_y, std::string text) = input for the placement of the tile during the game

    - place_stone() = handles the input for the placement of the tile and then call the method place_stone in the class Board

    - bases_placement() = handles the input for the placement of the tile and then call the method place_base in the class Board

    - place_tile() = handles the input for the placement of the tile and then call the method place_tile in the class Board

    - clear_terminal() = clear the prompt

    - make_action(int action) = take action as a parameter and call the right function depending on the action

    - game_start() = handles the start of the game. The players must place their bases

    - exchange_tile() = ask for wich tile in the queue the user would like to exchange and then push back the tiles unused

    - game_last_actions(std::vector<Player> &players) = during the ending of the game once all turns have been played the player can buy a 1x1 grass tile using exchange coupons

    - buy_grass_tile(char player) = handles the input and add a grass_tile on the board if the placement allow it

    - input_int(int min, int max, std::string text) = handles int input with min max as a parameter 

    - input_string(char &user_pos, std::string text) = handles string input with an address pointing to the var containing x and y

    - display_ending_turn() = display "ending turn..." and sleep for 1sc

    - clear_cin() = clear the remanence of the previous std::cin