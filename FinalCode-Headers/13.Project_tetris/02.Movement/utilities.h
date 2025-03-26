#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include "board.h"
#include "tetromino.h"

Tetromino spawn_new_tetromino() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(1, 7);
    return Tetromino(static_cast<Tetromino::Type>(dis(gen)));
}

void app(){
    sf::RenderWindow window(sf::VideoMode(Board::WIDTH * Board::BLOCK_SIZE, 
                            Board::HEIGHT * Board::BLOCK_SIZE), 
                            "Tetris");
    Board board;
    BoardEntity entity(board);
    Tetromino current_piece(Tetromino::Type::L);

    sf::Clock movement_clock;
    sf::Clock fall_clock;
    const float move_delay = 0.1f;    // Delay between movements
    const float fall_delay = 0.5f;    // Time between falls: bring this down to increase speed

    board.initialize();

    while ((window.isOpen()))
    {
        // Window events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Input handling with delay. The delay ensures that keypresses do not register 
        // too frequently when a player holds down a movement key. Without it, pressing 
        // and holding a key would move the piece too quickly, making the game unplayable.
        if(movement_clock.getElapsedTime().asSeconds() >= move_delay){
            // Save the current state in case a collision occurs.
            current_piece.backup_position();
            bool moved {false};

           if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                current_piece.move_left();
                moved = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                current_piece.move_right();
                moved = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                current_piece.move_down();
                moved = true;
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                current_piece.rotate();
                moved = true;
            }

            if(moved){
                if(board.is_collision(current_piece)){
                    current_piece.undo_move();
                }
                movement_clock.restart();
            }
        } // Movement

        //Automatic falling
        if(fall_clock.getElapsedTime().asSeconds() >= fall_delay){
            current_piece.backup_position();
            current_piece.move_down();

            if(board.is_collision(current_piece)){
                //Bring the piece back to its previous position, if it falls our of range
                current_piece.undo_move();

                //Lock it in place
                board.lock_current_piece(current_piece);

                //Spawn a new piece
                current_piece = spawn_new_tetromino();
            }
            fall_clock.restart();
        }

        board.update_tetromino(current_piece);
        window.clear(sf::Color::Black);
        entity.draw(window);
        window.display();
    }
}
