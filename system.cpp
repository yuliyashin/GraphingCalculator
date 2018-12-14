#include "system.h"
#include <iostream>
#include "../!include/Input/input.h"


System::System(){}
//------------------------------------------------------------------
//------------------------------------------------------------------

void System::Step(int command){

    sf::Vector2f graphRange = graph.getGraphRange();
    sf::Vector2f origin = graph.getOrigin();
    float graphUnit = WORK_PANEL/((graphRange.y) - (graphRange.x));

    switch (command){
    case ZOOMIN:
        graphRange.x *= .95;
        graphRange.y *= .95;
        graph.setGraphRange(graphRange.x, graphRange.y);
        break;
    case ZOOMOUT:
        graphRange.x *= 1.05;
        graphRange.y *= 1.05;
        graph.setGraphRange(graphRange.x, graphRange.y);
        break;
    case PANLEFT:
        origin.x += graphUnit;
        graph.setOrigin(origin.x, origin.y);
        graphRange.x -= SPEED;
        graphRange.y -= SPEED;
        graph.setGraphRange(graphRange.x, graphRange.y);
        break;

    case PANRIGHT:
        origin.x -= graphUnit;
        graph.setOrigin(origin.x, origin.y);
        graphRange.x += SPEED;
        graphRange.y += SPEED;
        graph.setGraphRange(graphRange.x, graphRange.y);
        break;
    case PANUP:
        origin.y += graphUnit;
        graph.setOrigin(origin.x, origin.y);
        break;
    case PANDOWN:
        origin.y -= graphUnit;
        graph.setOrigin(origin.x, origin.y);
        break;
    case INPUT:
        Queue<Token*> newFunction = tokenizeString();
        graph.setFunction(newFunction);
        break;
    }
}

void System::Draw(sf::RenderWindow& window){

    sf::Vector2f origin = graph.getOrigin();

    sf::VertexArray x_axis(sf::LinesStrip, 3);
    x_axis[0].position = sf::Vector2f(0, origin.y);
    x_axis[0].color = sf::Color::Black;
    x_axis[1].position = sf::Vector2f(origin.x, origin.y);   // x axis component
    x_axis[1].color = sf::Color::White;
    x_axis[2].position = sf::Vector2f(WORK_PANEL, origin.y);
    x_axis[2].color = sf::Color::Black;

    sf::VertexArray y_axis(sf::LinesStrip, 3);

    y_axis[0].position = sf::Vector2f(origin.x, 0);
    y_axis[0].color = sf::Color::Black;
    y_axis[1].position = sf::Vector2f(origin.x, origin.y);      // y axis component
    y_axis[1].color = sf::Color::White;
    y_axis[2].position = sf::Vector2f(origin.x, SCREEN_HEIGHT);
    y_axis[2].color = sf::Color::Black;

    vector<sf::Vector2f> translated = graph.translate();
    sf::VertexArray translatedCoordinates(sf::LinesStrip,3);
    for (int i = 0; i < NUMOFPOINTS; i++)
    {
        float x = translated[i].x;
        float y = translated[i].y;
        translatedCoordinates[i].color = sf::Color::Cyan;                  //grabs translated coordinates and plots the vertexes to conenct
        translatedCoordinates.append(sf::Vertex(sf::Vector2f(x,y)));
    }

    window.clear();
    window.draw(x_axis);
    window.draw(y_axis);                    //draws components onto window
    window.draw(translatedCoordinates);
}
