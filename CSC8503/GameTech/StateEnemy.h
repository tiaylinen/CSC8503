#pragma once
#include "..\CSC8503Common\GameObject.h"
namespace NCL {
	namespace CSC8503 {
		class StateMachine;
		class StateEnemy : public GameObject {

		public:
			StateEnemy();
			~StateEnemy();

			virtual void Update(float dt);

		protected:
			void MoveBack(float dt);
			void MoveForward(float dt);

			StateMachine* stateMachine;
			float counter;
		};
	}
}