#ifndef GRAPH_H
#define GRAPH_H
#include "../!include/RPN/token.h"
#include "../!include/RPN/queue.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "../!include/SFML/constants.h"

using namespace std;

class Graph
{
public:
    Graph();
    //getters
    sf::Vector2f getGraphRange();
    sf::Vector2f getScreenRange();
    sf::Vector2f getOrigin();
    int getNumOfPoints();
    vector<sf::CircleShape> getGraph();
    float getGraphUnit();
    //setters
    void setGraphRange(float x, float y);
    void setScreenRange(sf::Vector2f screenRange);
    void setOrigin(float x, float y);
    void setNumOfPoints(int numOfPoints);
    void setFunction(Queue<Token*>& inFix);
    //print
    void printScreenRange();
    void printOrigin();
    //
   vector<sf::Vector2f> plot();
   vector<sf::Vector2f> translate();
   void generateGraph();

private:
    Queue<Token*> _function;
    float _graphUnit;
    sf::Vector2f _graphRange;
    sf::Vector2f _screenRange;
    sf::Vector2f _origin;
    int _numOfPoints;
};

#endif // GRAPH_H
