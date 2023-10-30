#pragma once
#include "player.h"
#include <string>
#include <sstream>
#include "Bullet.h"
#include "Enemy.h"
#include "guiPlayerPoints.h"
#include "GameOver.h"
#include "guiplayerHpBar.h"
#include "Bonus.h"
#include "LineEnemy.h"
#include<map>

class Game
{
private:
    sf::RenderWindow* window;
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets;

    sf::Texture worldBackgroundText;
    sf::Sprite worldBackground;
    unsigned points;
     unsigned maxPoints;  // Variable pour le nombre maximal de points possibles
     std::vector<LineEnemy*> lineEnemies;
    Player* player;
    std::vector<Bonus*> bonuses;
    sf::Texture bonusTexture;
    int bonusFrequency; // Adjust this value based on enemy speed
    int bonusTimer; // Keep track of time to determine when to spawn bonuses

    guiPlayerPoints* gui1;
    GameOver* gui2;
    guiplayerHpBar* gui3;





    float spawnTimer;
    float spawnTimerMax;
    std::vector<Enemy*> enemies;
    void initwindow();
    void initTextures();
    void initPlayer();
    void initGUID();
    void initWord();
    void initEnemies();
    void initSystems();

public:
    Game();
    virtual ~Game();
    void run();
    void updatePollEvents();
    void updateInput();
    void updateWorld();
    void updateColusion();
    void updateBullets();
    void updateGUI();
    void renderGUI();
    void renderWorld();
    void updateEnemies();
    void updateCombat();
    void update();
    void render();
    void initBonus();
    void updateBonus();
    void handleBonusCollision();
    void generateBonus();
};

