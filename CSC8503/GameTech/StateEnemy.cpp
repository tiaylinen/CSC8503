#include "StateEnemy.h"
#include "../CSC8503Common/StateTransition.h"
#include "../CSC8503Common/StateMachine.h"
#include "../CSC8503Common/State.h"

using namespace NCL;
using namespace CSC8503;

StateEnemy::StateEnemy() {
	counter = 0.0f;
	stateMachine = new StateMachine();

	State* stateA = new State([&](float dt)->void
		{
			this->MoveBack(dt);
		}
	);
	State* stateB = new State([&](float dt)->void
		{
			this->MoveForward(dt);
		}
	);

	stateMachine->AddState(stateA);
	stateMachine->AddState(stateB);

	stateMachine->AddTransition(new StateTransition(stateA, stateB, [&]()->bool
		{
			return this->counter > 3.0f;
		}
	));

	stateMachine->AddTransition(new StateTransition(stateB, stateA, [&]()->bool
		{
			return this->counter < 0.0f;
		}
	));

}

StateEnemy ::~StateEnemy() {
	delete stateMachine;
}

void StateEnemy::Update(float dt) {
	stateMachine->Update(dt);
}

void StateEnemy::MoveBack(float dt) {
	GetPhysicsObject()->AddForce({ 0 , 0 , 5 });
	counter += dt;
}

void StateEnemy::MoveForward(float dt) {
	GetPhysicsObject()->AddForce({ 0, 0, -50 });
		counter -= dt;
}