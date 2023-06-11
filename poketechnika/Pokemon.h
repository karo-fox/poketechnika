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

    void reduceHP(float red);
    float getHP();
    int getLvl();
    void setHPToMax();
    std::string getName();
    std::vector<std::string> getMoveData(int move_idx);
    int getHp();
    int getMaxHp();
    Move getMove(int id);
    PokemonType getType1();
    PokemonType getType2();
};