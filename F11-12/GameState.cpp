#include "GameState.h"
#include <iostream>
#include "Engine.h"
namespace cwing {

	void GameState::setNextState(GameState* state) {
		nextState = state;
	}

	//GameState* GameState::getCurrentState() {
	//	return currentState;
	//}

	//void GameState::setCurrentState(GameState* state) {
	//	currentState = state;
	//}

	void GameState::changeState() {
		if (nextState != NULL) { //kollar om det finns ett state att byta till
			//std::cout << "change state" << std::endl;
			//currentState->exitState(); //anropar exitState funktionen hos nuvarande state och avslutar den
			ge.getCurrentState()->exitState();
			nextState->enterState(); //anropar ny state entersState funktionen och påbörjar den
			//currentState = nextState; //sparar nya staten
			ge.setCurrentState(nextState);
			nextState = NULL; //gör om nextState till NULL tills nuvarande state är klar
		}
	}

	GameState::~GameState() {

	}
}