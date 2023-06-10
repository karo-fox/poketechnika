#pragma once
#include "GameObject.h"
#include "Drawable.h"
#include "PokemonTypes.h"
#include "Move.h"
class Pokemon :
    public GameObject, public Drawable
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
    Pokemon(std::string name_, int lvl_, int xp_, PokemonType type1_, PokemonType type2_, float hp_, float maxhp_, Move move1_, Move move2_, Move move3_, Move move4_);
    Pokemon();
    void update(float elapsedTime, InputHandler& ih);
    void setOwner(bool isPlayer);
};