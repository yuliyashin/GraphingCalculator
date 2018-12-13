#include "graph.h"
#include <cmath>
#include "../!include/RPN/shuntingyard.h"
#include "../!include/Input/input.h"


using namespace std;

Graph::Graph(){
    _screenRange.x = SCREEN_WIDTH;
    _screenRange.y = SCREEN_HEIGHT;

    _graphRange.x = -10;
    _graphRange.y = 10;

    _origin.x = WORK_PANEL/2;
    _origin.y = _screenRange.y/2;

    _graphUnit = WORK_PANEL/((_graphRange.y) - (_graphRange.x));

    _function = tokenizeString();   //asks for user input
}

sf::Vector2f Graph::getGraphRange(){
    return _graphRange;
}

sf::Vector2f Graph::getScreenRange(){
    return _screenRange;
}

sf::Vector2f Graph::getOrigin(){
    return _origin;
}

int Graph::getNumOfPoints(){
    return _numOfPoints;
}

float Graph::getGraphUnit(){
    return _graphUnit;
}

void Graph::setGraphRange(float x, float y){
    _graphRange.x = x;
    _graphRange.y = y;
}
void Graph::setScreenRange(sf::Vector2f screenRange){
    _screenRange = screenRange;
}
void Graph::setOrigin(float x, float y){
    _origin.x = x;
    _origin.y = y;
}
void Graph::setNumOfPoints(int numOfPoints){
    _numOfPoints = numOfPoints;
}
void Graph::setFunction(Queue<Token*>& inFix){
    _function = inFix;
}

void Graph::printScreenRange(){
    cout << "SCREENX: " << _screenRange.x;
    cout << "SCREENY: " << _screenRange.y;
}

void Graph::printOrigin(){
    cout << "ORIGINX: " << _origin.x;
    cout << "ORIGINY: " << _origin.y;
}

vector<sf::Vector2f> Graph::plot(){
    bool debug = true;
    vector<sf::Vector2f> graphCoordinates;
    float lo = _graphRange.x;
    float hi = _graphRange.y;

    float pointsInRange = hi - lo;
    float incrementBy = pointsInRange/NUMOFPOINTS;              // calculates all the x,y values from the given equation/function

    while (lo <= hi){   // if inclusive, numOfpoints + 1;
        Queue<Token*> postFix = toPostFix(_function);
        double x = lo;
        float y = eval(postFix, x);
//        float y = sin(cos(1/x));

        graphCoordinates.push_back(sf::Vector2f(x, y)); // stores set of coordinates into a vector
        lo +=incrementBy;
    }
    return graphCoordinates;
}

vector<sf::Vector2f> Graph::translate(){
    vector<sf::Vector2f> toTranslate = plot();
    vector<sf::Vector2f> translatedCoordinates;
    float graphUnit = WORK_PANEL/((_graphRange.y) - (_graphRange.x));
    for (float i = 0; i < NUMOFPOINTS; i++)                                 // converts graph coordinates from plot function to screen coordinates
    {
        float x = (toTranslate[i].x * graphUnit) + (_origin.x);
        float y = (_origin.y) - (toTranslate[i].y * graphUnit);
        translatedCoordinates.push_back(sf::Vector2f(x, y));
    }
    return translatedCoordinates;
}
