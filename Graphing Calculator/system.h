#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "graph.h"

using namespace std;
class System
{
public:
    System();
    void Step(int command);
    void Draw(sf::RenderWindow& window);
private:

    Graph graph;
    sf::VertexArray x_axis;
    sf::VertexArray y_axis;
};

#endif // SYSTEM_H
