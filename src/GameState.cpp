#include "GameState.h"
#include <iostream>
#include "Engine.h"

namespace cwing {

	void GameState::setNextState(std::unique_ptr<GameState> state) {
		nextState = std::move(state);
	}

	//GameState* GameState::getNextState() const {
	//	return nextState;
	//}

	//GameState* GameState::getCurrentState() {
	//	return currentState;
	//}

	//void GameState::setCurrentState(GameState* state) {
	//	currentState = state;
	//}

	void GameState::changeState() {
		if (nextState != nullptr) { //kollar om det finns ett state att byta till
			//std::cout << "change state" << std::endl;
			//getCurrentState->exitState(); //anropar exitState funktionen hos nuvarande state och avslutar den
			ge.getCurrentState()->exitState();
			ge.setCurrentState(std::move(nextState));
			ge.getCurrentState()->enterState(); //anropar ny state entersState funktionen och påbörjar den
			//currentState = nextState; //sparar nya staten
			//nextState.release(); //gör om nextState till NULL tills nuvarande state är klar
			//nextState.release();
		}
	}

	GameState::~GameState() {
		std::cout << "GS dest" << std::endl;
		//delete nextState;
	}
}