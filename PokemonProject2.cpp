//
// Created by Paulo Drefahl on 9/7/2022.
//

// Demonstrate sprite drawing in SFML
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "iostream"

void renderBattle();


int main(int argc, char ** argv) {
    //Variables
    int mousePosX, mousePosY;

    //Window config
    sf::RenderWindow renderWindow(sf::VideoMode(1200, 800),
                                  "Pokemon by Paulo Drefahl, Erik Rodriguez, Henrique Baggio, Kevin Kostage");
    //Event Variables
    sf::Event event;
    sf::Event event1;

    //Text Config
    sf::Text text;
    sf::Font font;
    if (!font.loadFromFile("C:/Users/Paulo Drefahl/Desktop/hellosfml/PKMNRBYGSC.ttf")) {
        std::cout << "font error";
    }
    text.setFont(font);
    text.setString("Select  Pokemon...");
    text.setCharacterSize(29); // in pixels, not points!
    text.setPosition(402, 645);
    text.setFillColor(sf::Color::Black);

// Images, Sprites
    sf::Texture mainMenuImg;
    sf::Texture pokemonSelectionImg;
    pokemonSelectionImg.loadFromFile("C:/Users/Paulo Drefahl/Desktop/hellosfml/Poke_Select_3.png");
    mainMenuImg.loadFromFile("C:/Users/Paulo Drefahl/Desktop/hellosfml/Poke_Menu_WIP.png");
    sf::Sprite sprite(mainMenuImg);
    sf::Sprite sprite2(pokemonSelectionImg);


    while (renderWindow.isOpen()) {
        while (renderWindow.pollEvent(event)) {
            if (event.type == sf::Event::EventType::Closed)
                renderWindow.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    mousePosX = event.mouseButton.x;
                    mousePosY = event.mouseButton.y;
                    std::cout << "X: " << mousePosX << " Y: " << mousePosY;


                    if (mousePosX > 209 && mousePosX < 411 && mousePosY < 678 && mousePosY > 640) {
                        std::cout << "Start game" << std::endl;
                        renderWindow.close();


                        sf::RenderWindow renderSelection(sf::VideoMode(1200, 800),
                                                         "Pokemon by Paulo Drefahl, Erik Rodriguez, Henrique Baggio");
                        while (renderSelection.isOpen()) {
                            while (renderSelection.pollEvent(event1)) {
                                if (event1.type == sf::Event::EventType::Closed)
                                    renderSelection.close();

                                if (event1.type == sf::Event::MouseButtonPressed) {
                                    if (event1.mouseButton.button == sf::Mouse::Left) {
                                        int mousePos1X = event1.mouseButton.x;
                                        int mousePos1Y = event1.mouseButton.y;
                                        std::cout << "X: " << mousePos1X << std::endl;
                                        std::cout << "Y:" << mousePos1Y << std::endl;

                                        if (mousePos1X > 927 && mousePos1X < 1163 && mousePos1Y > 113 && mousePos1Y < 181) {
                                            std::cout << "Pokemon selected" << std::endl;
                                            text.setString("Charmander  Selected.");
                                        }

                                        if (mousePos1X > 927 && mousePos1X < 1163 && mousePos1Y > 279 && mousePos1Y < 339) {
                                            std::cout << "Pokemon selected" << std::endl;
                                            text.setString("Bulbasaur  Selected.");
                                        }

                                        if (mousePos1X > 927 && mousePos1X < 1163 && mousePos1Y > 437 && mousePos1Y < 499) {
                                            std::cout << "Pokemon selected" << std::endl;
                                            text.setString("Squirtle  Selected.");
                                        }
                                        if (mousePos1X > 952 && mousePos1X < 1148 && mousePos1Y > 638 && mousePos1Y < 690) {
                                            std::cout << "Battle Started" << std::endl;
                                            renderSelection.close();
                                            renderBattle();
                                        }
                                    }
                                }

                                renderSelection.clear();
                                renderSelection.draw(sprite2);
                                renderSelection.draw(text);
                                renderSelection.display();
                            }
                        }
                    }

                    if (mousePosX > 513 && mousePosX < 659 && mousePosY < 678 && mousePosY > 640) {
                        std::cout << "Exit game" << std::endl;
                        renderWindow.close();
                    }

                }
            }
            renderWindow.clear();
            renderWindow.draw(sprite);
            renderWindow.display();
        }
    }
}

void renderBattle(){
    sf::RenderWindow renderBattleScreen(sf::VideoMode(1200, 800),
                                                        "Pokemon by Paulo Drefahl, Erik Rodriguez, Henrique Baggio");
    sf::Event eventBattle;
    sf::Texture BattleBackground;

    BattleBackground.loadFromFile("C:/Users/Paulo Drefahl/Desktop/hellosfml/pixil-frame-0-2.png");
    sf::Sprite sprite3(BattleBackground);

    while (renderBattleScreen.isOpen()) {
        while (renderBattleScreen.pollEvent(eventBattle)) {
            if (eventBattle.type == sf::Event::EventType::Closed)
                renderBattleScreen.close();
            }
        renderBattleScreen.clear();
        renderBattleScreen.draw(sprite3);

        renderBattleScreen.display();

    }


}
