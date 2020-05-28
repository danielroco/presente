#ifndef STATE_H
#define STATE_H

#include "entity.h"

#define PLAYER_HP  10
#define PLAYER_RAD 10
#define PLAYER_SPEED 4
#define PLAYER_COOLDOWN 8

#define MINION_HP   4
#define MINION_RAD 12
#define BRUTE_HP   12
#define BRUTE_RAD  16
//Definimos las estadisticas del enemigo tipo BLOAT
#define BLOAT_HP 8
#define BLOAT_RAD 8
//Distintos tipos de daño del tipo BLOAT, el cual va a depender de la distancia a la cual este la entidad a comparar
//BLOAT_RANGE en float para poder compararlo con distance(), el cual tambien es float()
#define BLOAT_DMG 4
#define BLOAT_DMG_MID 6
#define BLOAT_DMG_MAX 11
#define BLOAT_RANGE 200.0

#define BULLET_DMG 3
#define BULLET_SPEED 16
#define BULLET_RAD   5


// ==== PLAYER DEFINITION
typedef struct {
    entity ent;
    // Cooldown of the player's weapon. The player can shoot when it is <=0.
    int cooldown;
} player;

// ==== ENEMY DEFINITION
typedef enum {MINION=0, BRUTE=1, BLOAT=2} enemykind;

typedef struct {
    entity ent;
    enemykind kind;
} enemy;

// ==== BULLET DEFINTION

typedef struct {
    entity ent;
    // TODO: We may want to add more fields...
} bullet;

// ==== STATE DEFINITION

#define MAX_ENEMIES 128
#define MAX_BULLETS 128

#define N_BUTTONS 5

// A state represents everything that's happening with the game objects at a given time.
typedef struct {
    // The player
    player pla;

    // An array of enemies:
    int n_enemies;
    enemy enemies[MAX_ENEMIES];

    // An array of bullets:
    int n_bullets;
    bullet bullets[MAX_BULLETS];

    // State of the controls, should be updated on each step.
    int button_state[N_BUTTONS];
    float aim_angle;

} state;

// Creates an empty state, allocating memory for it.
state *state_new();

// Updates the state of the game to the next frame.
void state_update(level *lvl, state *sta);

// Put enemies at random in the state until it has n_enemies enemies.
void state_populate_random(level *lvl, state *sta, int n_enemies);

// Deletes a state and the memory it requires.
void state_free(state *sta);



#endif
