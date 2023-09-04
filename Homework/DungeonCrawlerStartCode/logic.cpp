
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char **loadLevel(const string &fileName, int &maxRow, int &maxCol, Player &player)
{
   std::ifstream file(fileName);
    string line;

    //---------------CHECK IF FILE NAME IS VAILD---------------------------------------
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (!(file.is_open()))
    {
        file.close();
        return nullptr;
    }
    if (file.eof())
    {
        return nullptr;
    }
    //---------------SET MAX ROW IN FILE EQUAL TO MAX ROW GIVEN AS A PARAMETER-----------------
    try
    {
        file >> maxRow;
    }
    catch (const std::exception &e)
    {
        return nullptr;
    }
    //---------------SET MAX COL IN FILE EQUAL TO MAX COL GIVEN AS A PARAMETER-----------------
    if (file.eof())
    {
        return nullptr;
    }
    try
    {
        file >> maxCol;
    }
    catch (const std::exception &e)
    {
        return nullptr;
    }

    //---------------CHECK IF STARTING ROW POSITION IN FILE IS LESS THAN MAX ROW-----------------
    if (file.eof())
    {
        return nullptr;
    }
    try
    {
        file >> player.row;
        if (player.row < 0 || player.row > maxRow)
        {
            return nullptr;
        }
    }
    catch (const std::exception &e)
    {
        return nullptr;
    }
    //---------------CHECK IF STARTING COL POSITION IN FILE IS LESS THAN MAX COL-----------------
    try
    {
        file >> player.col;
        if (player.col < 0 || player.col > maxRow)
        {
            return nullptr;
        }
    }
    catch (const std::exception &e)
    {
        return nullptr;
    }
    //-------CREATING AND POPULATING MAP----------------------------------
    bool door = false;

    char **map = createMap(maxRow, maxCol);
    if (map == nullptr)
    {
        return nullptr;
    }
    try
    {
        for (int row = 0; row < maxRow; row++)
        {
            for (int col = 0; col < maxCol; col++)
            {
                if (file.eof())
                {
                    deleteMap(map, maxRow);
                    return nullptr;
                }
                file >> map[row][col];
                if ((map[row][col] != TILE_AMULET) && (map[row][col] != TILE_DOOR) && (map[row][col] != TILE_EXIT) && (map[row][col] != TILE_MONSTER) && (map[row][col] != TILE_OPEN) && (map[row][col] != TILE_PILLAR) && (map[row][col] != TILE_PLAYER) && (map[row][col] != TILE_TREASURE))
                {
                    deleteMap(map, maxRow);
                    return nullptr;
                }
                // else if (map[row][col] == TILE_DOOR)
                // {
                //     door = true;
                // }
                else if ((row == player.row) && (col == player.col) && (map[row][col] != TILE_OPEN))
                {
                    deleteMap(map, maxRow);
                    return nullptr;
                }
                else if((map[row][col] == TILE_PLAYER) && (!(row == player.row)) && (!(col == player.col)))
                {
                    deleteMap(map, maxRow);
                    return nullptr;
                }
            }
        }
    }
    catch (const std::exception &e)
    {
        deleteMap(map, maxRow);
        return nullptr;
    }
    // if (door == false)
    // {
    //     deleteMap(map,maxRow);
    //     return nullptr;
    // }

    map[player.row][player.col] = TILE_PLAYER;
    file.close();
    return map;
}

//     //---------------CHECK IF FILE NAME IS VAILD---------------------------------------
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     if (!(file.is_open()))
//     {
//         file.close();
//         return nullptr;
//     }
//     if (file.eof())
//     {
//         return nullptr;
//     }
//     //---------------SET MAX ROW IN FILE EQUAL TO MAX ROW GIVEN AS A PARAMETER-----------------
//     try
//     {
//         file >> maxRow;
//     }
//     catch (const std::exception &e)
//     {
//         return nullptr;
//     }
//     //---------------SET MAX COL IN FILE EQUAL TO MAX COL GIVEN AS A PARAMETER-----------------
//     if (file.eof())
//     {
//         return nullptr;
//     }
//     try
//     {
//         file >> maxCol;
//     }
//     catch (const std::exception &e)
//     {
//         return nullptr;
//     }

//     //---------------CHECK IF STARTING ROW POSITION IN FILE IS LESS THAN MAX ROW-----------------
//     if (file.eof())
//     {
//         return nullptr;
//     }
//     try
//     {
//         file >> player.row;
//         if (player.row < 0 || player.row > maxRow)
//         {
//             return nullptr;
//         }
//     }
//     catch (const std::exception &e)
//     {
//         return nullptr;
//     }
//     //---------------CHECK IF STARTING COL POSITION IN FILE IS LESS THAN MAX COL-----------------
//     try
//     {
//         file >> player.col;
//         if (player.col < 0 || player.col > maxRow)
//         {
//             return nullptr;
//         }
//     }
//     catch (const std::exception &e)
//     {
//         return nullptr;
//     }
//     //-------CREATING AND POPULATING MAP----------------------------------
//     bool door = false;

//     char **map = createMap(maxRow, maxCol);
//     if (map == nullptr)
//     {
//         return nullptr;
//     }
//     try
//     {
//         for (int row = 0; row < maxRow; row++)
//         {
//             for (int col = 0; col < maxCol; col++)
//             {
//                 if (file.eof())
//                 {
//                     deleteMap(map, maxRow);
//                     return nullptr;
//                 }
//                 file >> map[row][col];
//                 if ((map[row][col] != TILE_AMULET) && (map[row][col] != TILE_DOOR) && (map[row][col] != TILE_EXIT) && (map[row][col] != TILE_MONSTER) && (map[row][col] != TILE_OPEN) && (map[row][col] != TILE_PILLAR) && (map[row][col] != TILE_PLAYER) && (map[row][col] != TILE_TREASURE))
//                 {
//                     deleteMap(map, maxRow);
//                     return nullptr;
//                 }
//                 else if (map[row][col] == TILE_DOOR)
//                 {
//                     door = true;
//                 }
//                 else if ((row == player.row) && (col == player.col) && (map[row][col] != TILE_OPEN))
//                 {
//                     deleteMap(map, maxRow);
//                     return nullptr;
//                 }
//                 else if((map[row][col] == TILE_PLAYER) && (!(row == player.row)) && (!(col == player.col)))
//                 {
//                     deleteMap(map, maxRow);
//                     return nullptr;
//                 }
//             }
//         }
//     }
//     catch (const std::exception &e)
//     {
//         deleteMap(map, maxRow);
//         return nullptr;
//     }
//     if (door == false)
//     {
//         deleteMap(map,maxRow);
//         return nullptr;
//     }

//     map[player.row][player.col] = TILE_PLAYER;
//     file.close();
//     return map;
// }

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int &nextRow, int &nextCol)
{
    if (input == MOVE_UP)
    {
        nextRow--;
    }
    else if (input == MOVE_DOWN)
    {
        nextRow++;
    }
    else if (input == MOVE_LEFT)
    {
        nextCol--;
    }
    else if (input == MOVE_RIGHT)
    {
        nextCol++;
    }
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char **createMap(int maxRow, int maxCol)
{
    if ((maxRow < 1) || (maxCol < 1))
    {
        return nullptr;
    }
    else if ((maxRow * maxCol) < 0)
    {
        return nullptr;
    }
    else if (maxRow > (INT32_MAX / maxCol))
    {
        return nullptr;
    }
    char **map = new char *[maxCol];

    bool fail = false;

    for (int i = 0; i < maxCol; ++i)
    { // loop through each column
        // assign that column to a one dimensional array on the heap of Pixels
        //  that has height elements (i.e. the number of rows)
        map[i] = new char[maxRow];

        if (map[i] == nullptr)
        { // failed to allocate
            fail = true;
        }
    }

    if (fail)
    { // if any allocation fails, clean up and avoid memory leak
        // deallocate any maxCol created in for loop
        for (int i = 0; i < maxRow; ++i)
        {
            delete[] map[i]; // deleting nullptr is not a problem
        }
        delete[] map; // delete array of pointers
        return nullptr;
    }

    // initialize cells
    // cout << "Initializing cells..." << endl;
    for (int row = 0; row < maxRow; ++row)
    {
        for (int col = 0; col < maxCol; ++col)
        {
            // cout << "(" << col << ", " << row << ")" << endl;
            map[row][col] = TILE_OPEN;
        }
    }
    return map;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char **&map, int &maxRow)
{
    if ((map == nullptr) || (maxRow < 1))
    {
        map = nullptr;
        maxRow = 0;
    }
    else
    {
        for (int i = 0; i < maxRow; ++i)
        {
            delete[] map[i]; // delete each individual array placed on the heap
        }
        delete[] map;
        map = nullptr;
        maxRow = 0;
    }
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char **resizeMap(char **map, int &maxRow, int &maxCol)
{
    if (map == nullptr)
    {
        return nullptr;
    }
    if (((maxRow * 2) < 0) || ((maxCol * 2) < 0))
    {
        return nullptr;
    }
    char **new_map = createMap((maxRow * 2), (maxCol * 2));
    if (new_map == nullptr)
    {
        return nullptr;
    }
    for (int row = 0; row < maxRow; row++)
    {
        for (int col = 0; col < maxCol; col++)
        {
            new_map[row][col] = map[row][col];
            if ((new_map[row][col] != TILE_AMULET) && (new_map[row][col] != TILE_DOOR) && (new_map[row][col] != TILE_EXIT) && (new_map[row][col] != TILE_MONSTER) && (new_map[row][col] != TILE_OPEN) && (new_map[row][col] != TILE_PILLAR) && (new_map[row][col] != TILE_PLAYER) && (new_map[row][col] != TILE_TREASURE))
            {
                deleteMap(new_map, maxRow);
                return nullptr;
            }
        }
    }
    for (int row = maxRow; row < (maxRow * 2); row++)
    {
        for (int col = 0; col < maxCol; col++)
        {
            if (!(map[(row - maxRow)][col] == TILE_PLAYER))
            {
                new_map[row][col] = map[(row - maxRow)][col];
            }
            else
            {
                new_map[row][col] = TILE_OPEN;
            }
        }
    }

    for (int row = 0; row < maxRow; row++)
    {
        for (int col = maxCol; col < (maxCol * 2); col++)
        {
            if (!(map[row][(col - maxCol)] == TILE_PLAYER))
            {
                new_map[row][col] = map[row][(col - maxCol)];
            }
            else
            {
                new_map[row][col] = TILE_OPEN;
            }
        }
    }

    for (int row = maxRow; row < (maxRow * 2); row++)
    {
        for (int col = maxCol; col < (maxCol * 2); col++)
        {
            if (!(map[(row - maxRow)][(col - maxCol)] == TILE_PLAYER))
            {
                new_map[row][col] = map[(row - maxRow)][(col - maxCol)];
            }
            else
            {
                new_map[row][col] = TILE_OPEN;
            }
        }
    }
    int temp = maxRow;
    deleteMap(map, maxRow);

    maxRow = temp;
    maxRow *= 2;
    maxCol *= 2;
    return new_map;
}
// {
//     if(map == nullptr){return nullptr;}
//     if(((maxRow*2)<0)||((maxCol*2)<0)){return nullptr;}
//     char **new_map = createMap((maxRow * 2), (maxCol * 2));
//     for (int row = 0; row < maxRow; row++)
//     {
//         for (int col = 0; col < maxCol; col++)
//         {
//             new_map[row][col] = map[row][col];
//         }
//     }

//     for (int row = maxRow; row < (maxRow * 2); row++)
//     {
//         for (int col = 0; col < maxCol; col++)
//         {
//             if (!(map[row][col] == TILE_PLAYER))
//             {
//                 new_map[row][col] = map[row][col];
//             }
//             else
//             {
//                 new_map[row][col] = TILE_OPEN;
//             }
//         }
//     }

//     for (int row = 0; row < maxRow; row++)
//     {
//         for (int col = maxCol; col < (maxCol * 2); col++)
//         {
//             if (!(map[row][col] == TILE_PLAYER))
//             {
//                 new_map[row][col] = map[row][col];
//             }
//             else
//             {
//                 new_map[row][col] = TILE_OPEN;
//             }
//         }
//     }

//     for (int row = maxRow; row < (maxRow * 2); row++)
//     {
//         for (int col = maxCol; col < (maxCol * 2); col++)
//         {
//             if (!(map[row][col] == TILE_PLAYER))
//             {
//                 new_map[row][col] = map[row][col];
//             }
//             else
//             {
//                 new_map[row][col] = TILE_OPEN;
//             }
//         }
//     }
//     int temp_maxRow = maxRow;
//     deleteMap(map, maxRow);
//     maxRow = temp_maxRow;
//     maxRow *= 2;
//     maxCol *= 2;
//     return reinterpret_cast<char **>(new_map);
// }

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure.
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char **map, int maxRow, int maxCol, Player &player, int nextRow, int nextCol)
{
    if ((nextRow >= maxRow) || (nextCol >= maxCol) || (nextRow < 0) || (nextCol < 0)||(player.row >= maxRow) || (player.col >= maxCol) || (player.row < 0) || (player.col < 0))
    {
        return STATUS_STAY;
    }
      if ((map[nextRow][nextCol] == TILE_MONSTER) || (map[nextRow][nextCol] == TILE_PILLAR))
    {
        return STATUS_STAY;
    }
    if (map[nextRow][nextCol] == TILE_TREASURE)
    {
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        player.treasure++;
        return STATUS_TREASURE;
    }
    else if ((map[nextRow][nextCol] == TILE_EXIT) && (player.treasure > 0))
    {
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        return STATUS_ESCAPE;
    }

    if (map[nextRow][nextCol] == TILE_AMULET)
    {
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        return STATUS_AMULET;
    }
    if (map[nextRow][nextCol] == TILE_DOOR)
    {
        map[player.row][player.col] = TILE_OPEN;
        player.row = nextRow;
        player.col = nextCol;
        map[player.row][player.col] = TILE_PLAYER;
        return STATUS_LEAVE;
    }
    if ((map[nextRow][nextCol] == TILE_EXIT) && (player.treasure == 0))
    {
        return STATUS_STAY;
    }
    map[player.row][player.col] = TILE_OPEN;
    player.row = nextRow;
    player.col = nextCol;
    map[player.row][player.col] = TILE_PLAYER;
    return STATUS_MOVE;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char **map, int maxRow, int maxCol, const Player &player)
{
    if (!(player.row == 0))
    {
        for (int row = (player.row - 1); row > -1; row--)
        {
            if (map[row][player.col] == TILE_PILLAR)
            {
                break;
            }
            if (map[row][player.col] == TILE_MONSTER)
            {
                map[row][player.col] = TILE_OPEN;
                map[(row + 1)][player.col] = TILE_MONSTER;
            }
        }
    }
    if (!(player.row == (maxRow - 1)))
    {
        for (int row = (player.row + 1); row < maxRow; row++)
        {
            if (map[row][player.col] == TILE_PILLAR)
            {
                break;
            }
            if (map[row][player.col] == TILE_MONSTER)
            {
                map[row][player.col] = TILE_OPEN;
                map[(row - 1)][player.col] = TILE_MONSTER;
            }
        }
    }
    if (!(player.col == 0))
    {
        for (int col = (player.col - 1); col > -1; col--)
        {
            if (map[player.row][col] == TILE_PILLAR)
            {
                break;
            }
            if (map[player.row][player.col] == TILE_MONSTER)
            {
                map[player.row][col] = TILE_OPEN;
                map[player.row][(col + 1)] = TILE_MONSTER;
            }
        }
    }
    if (!(player.col == (maxCol - 1)))
    {
        for (int col = (player.col + 1); col < maxCol; col++)
        {
            if (map[player.row][col] == TILE_MONSTER)
            {
                map[player.row][col] = TILE_OPEN;
                map[player.row][(col - 1)] = TILE_MONSTER;
            }
            if (map[player.row][col] == TILE_PILLAR)
            {
                break;
            }
        }
    }
    if (map[player.row][player.col] == TILE_MONSTER)
    {
        return true;
    }

    return false;
}
