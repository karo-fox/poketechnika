#pragma once
#include <pugixml.hpp>
#include "GameObject.h"
#include "Drawable.h"
#include "PokemonTypes.h"
#include "Move.h"
class Pokemon :
    public GameObject
{
private:
    std::string name;
    int lvl;
    int xp;
    PokemonType type1;
    PokemonType type2;
    float hp;
    float maxhp;
    Move move1;
    Move move2;
    Move move3;
    Move move4;
public:
    Drawable front;
    Drawable back;

    Pokemon(
        std::string name_, int lvl_, int xp_, PokemonType type1_, PokemonType type2_, 
        float hp_, float maxhp_, Move move1_, Move move2_, Move move3_, Move move4_, 
        const std::string& front_texture = "assets/textures/pokemon/error.png", 
        const std::string& back_texture = "assets/textures/pokemon/error.png"
    );
    Pokemon();
    void update(float elapsedTime, InputHandler& ih);
    void save(pugi::xml_node& node);
    void load(pugi::xml_node& node);

    // Reduces Pokemon health points
    void reduceHP(float red);
    // Returns Pokemon health points
    float getHP();
    // Returns Pokemon experience points
    int getXP();
    // Returns Pokemon level
    int getLvl();
    // Cures Pokemon
    void setHPToMax();
    // Sets the new level and set's new maximal health points if the conditions are met
    bool checkForLvlUp();
    // Sets new level
    void setLvl(int lvl_);
    // Adds experience points
    void addXP(int xp_);
    // Returns Pokemon's name
    std::string getName();
    // Returns pokemon movement data
    std::vector<std::string> getMoveData(int move_idx);
    // Returns maximal health points
    int getMaxHp();
    // Returns move according to given number
    Move getMove(int id);
    // Returns first type
    PokemonType getType1();
    // Returns second type
    PokemonType getType2();
};