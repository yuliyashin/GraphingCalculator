#include "animate.h"
#include <iostream>
using namespace std;

animate::animate():sidebar(WORK_PANEL, SIDE_BAR), system()

{
    cout<<"animate CTOR: TOP"<<endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Julie Shin's Graphing Calculator");
    //VideoMode class has functions to detect screen size etc.
    //RenderWindow constructor has a third argumnet to set style
    //of the window: resize, fullscreen etc.

    //System will be implemented to manage a vector of objects to be animated.
    //  at that point, the constructor of the System class will take a vector
    //  of objects created by the animate object.
    //  animate will
    //    system = System();
    window.setFramerateLimit(60);

    mouseIn = true;

    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);

    cout<<"Geme CTOR. preparing to load the font."<<endl;
    //--- FONT ----------
    //font file must be in the "working directory:
    //      debug folder
    //Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    //font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("arial.ttf")){
        cout<<"animate() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }

        myTextLabel = sf::Text("Graphing Calculator", font);
        myTextLabel.setCharacterSize(20);
        myTextLabel.setStyle(sf::Text::Bold);
        myTextLabel.setColor(sf::Color::Green);
        myTextLabel.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-myTextLabel.getLocalBounds().height-5));


    cout<<"animate instantiated successfully."<<endl;
}

void animate::Draw(){
    //Look at the data and based on the data, draw shapes on window object.
    system.Draw(window);
    if (mouseIn){
        window.draw(mousePoint);
    }

    sidebar.draw(window);

    //- - - - - - - - - - - - - - - - - - -
    //getPosition() gives you screen coords, getPosition(window) gives you window coords
    //cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    //drawing Test: . . . . . . . . . . . .
    //This is how you draw text:)
    window.draw(myTextLabel);
    //. . . . . . . . . . . . . . . . . . .
}

void animate::update(){
    //cause changes to the data for the next frame
    system.Step(command);
    command = 0;
    if (mouseIn){
        //mousePoint red dot:
        mousePoint.setPosition(sf::Mouse::getPosition(window).x-5,
                               sf::Mouse::getPosition(window).y-5);

        //mouse location text for sidebar:
        sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);




    }
}
void animate::render(){
    window.clear();
    Draw();
    window.display();
}



void animate::processEvents()
{
    sf::Event event;
    float mouseX, mouseY;
    sf::Text playerText;
    playerText.setPosition(60,300);
    playerText.setColor(sf::Color::Red);
    string str;
    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
//        case sf::Event::TextEntered:
//            if (event.text.unicode < 128)
//                std::cout << "ASCII character typed: " << static_cast<char>(event.text.unicode) << std::endl;
//            cout << "Text entered!" << endl;
//            str += static_cast<char>(event.text.unicode);
//            playerText.setString(str);
//            myTextLabel = sf::Text(str, font);
//            // window closed
//            break;
        case sf::Event::Closed:
            window.close();
            break;

            // key pressed
        case sf::Event::KeyPressed:
            switch(event.key.code){
            case sf::Keyboard::Left:
                sidebar[SB_KEY_PRESSED] = "PAN LEFT";
                command = PANLEFT;
                break;
            case sf::Keyboard::Right:
                sidebar[SB_KEY_PRESSED] = "PAN RIGHT";
                command = PANRIGHT;
                break;
            case sf::Keyboard::Up:
                sidebar[SB_KEY_PRESSED] = "PAN UP";
                command = PANUP;
                break;
            case sf::Keyboard::Down:
                sidebar[SB_KEY_PRESSED] = "PAN DOWN";
                command = PANDOWN;
                break;
            case sf::Keyboard::Z:
                sidebar[SB_KEY_PRESSED] = "ZOOM IN";
                command = ZOOMIN;
                break;
            case sf::Keyboard::X:
                sidebar[SB_KEY_PRESSED] = "ZOOM OUT";
                command = ZOOMOUT;
                break;
            case sf::Keyboard::Space:
                sidebar[SB_KEY_PRESSED] = "INPUT";
                command = INPUT;
                break;
            }

            break;
        case sf::Event::MouseEntered:
            mouseIn = true;
            break;

        case sf::Event::MouseLeft:
            mouseIn = false;
            break;

        case sf::Event::MouseMoved:
            mouseX = event.mouseMove.x;
            mouseY = event.mouseMove.y;
            //Do something with it if you need to...
            break;
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                sidebar[SB_MOUSE_CLICKED] = "RIGHT CLICK " +
                        mouse_pos_string(window);

            }
            else{
                sidebar[SB_MOUSE_CLICKED] = "LEFT CLICK " +
                        mouse_pos_string(window);
            }
            break;

        default:
            break;
        }
    }
}
void animate::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render(); //clear/draw/display
    }
    cout<<endl<<"-------ANIMATE MAIN LOOP EXITING ------------"<<endl;
}

string mouse_pos_string(sf::RenderWindow& window){
    return "(" +
            to_string(sf::Mouse::getPosition(window).x) +
            ", " +
            to_string(sf::Mouse::getPosition(window).y) +
            ")";
}
