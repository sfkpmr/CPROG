#include "GameState.h"
#include <iostream>
#include "Engine.h"

namespace cwing {

	void GameState::setNextState(std::unique_ptr<GameState> state) {
		nextState = std::move(state);
	}

	void GameState::changeState() {
		if (nextState != nullptr) { //kollar om det finns ett state att byta till
			ge.getCurrentState()->exitState(); //går ur current state
			ge.setCurrentState(std::move(nextState)); //byter till ny current state
			ge.getCurrentState()->enterState(); //anropar ny state entersState funktionen och påbörjar den
		}
	}

	GameState::~GameState() {
		std::cout << "GameState dest" << std::endl;
	}
}