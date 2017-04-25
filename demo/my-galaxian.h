#ifndef MY_GALAXIAN_H
#define MY_GALAXIAN_H

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <sstream>

#include "Includes.h"
#include "Constants.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"

void test_galaxian_title_screen();
void test_galaxian_alien();
void test_galaxian_player_ship();
void test_galaxian_kill_aliens();
void test_galaxian_starfield();

bool isCollision(const Rect &, const Rect &);

class Alien
{
public:
    //Alien(int x = 0, int y = 0);

    virtual void run() = 0;
    virtual void draw(Surface &) const = 0;
    virtual bool & isAlive() = 0;
    virtual Rect & rect() = 0;

/*
//protected:
    Rect rect_;

    int state_;
    int dx_;
    int dy_;
    */
};

class AquaAlien : public Alien
{
public:
    AquaAlien(int x = 0, int y = 0);

    void run();
    void draw(Surface &) const;
    bool & isAlive();
    Rect & rect();

private:
    Rect rect_;
    static Image image_;

    int state_;
    bool isAlive_;
    int dx_;
    int dy_;
};

class RedAlien : public Alien
{
public:
    RedAlien(int x = 0, int y = 0);

    void run();
    void draw(Surface &) const;
    bool & isAlive();
    Rect & rect();

private:
    Rect rect_;
    static Image image_;

    int state_;
    bool isAlive_;
    int dx_;
    int dy_;
};

class PlayerShip
{
public:
    PlayerShip(int x = 0, int y = W - 100);
    void draw(Surface &) const;
    void moveRight();
    void moveLeft();
    bool & isAlive();
    Rect & rect();

private:
    Rect rect_;
    static Image image_;

    bool isAlive_;
    int dx_;
    int dy_;
};

class Laser
{
public:
    Laser(int x = 0, int y = 0);
    void run();
    void draw(Surface &) const;
    bool & isAlive();
    Rect & rect();
    
    static int timeOfLastLaser_;
private:
    bool isAlive_;
    Rect rect_;
    Color color_;

    int dx_;
    int dy_;
};

class Star
{
public:
    Star(int x = 0, int y = 0);
    void run();
    void draw(Surface &) const;
private:
    Rect rect_;
    Color color_;

    int dx_;
    int dy_;
    int dcolor_;
};

#endif

