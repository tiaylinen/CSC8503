#pragma once
#include "GameTechRenderer.h"
#include "../CSC8503Common/PhysicsSystem.h"
#include "StateGameObject.h"
#include "StateEnemy.h"

namespace NCL {
	namespace CSC8503 {
		class TutorialGame		{
		public:
			TutorialGame();
			~TutorialGame();

			virtual void UpdateGame(float dt);

		protected:
			void InitialiseAssets();

			void InitCamera();
			void UpdateKeys();

			void InitWorld();
			void InitWorldSingle();

			void InitGameExamples();

			void InitSphereObstacle(int numRows, int numCols, float rowSpacing, float colSpacing, float radius);
			void InitMixedGridWorld(int numRows, int numCols, float rowSpacing, float colSpacing);
			void InitCubeGridWorld(int numRows, int numCols, float rowSpacing, float colSpacing, const Vector3& cubeDims);
			void InitDefaultFloor();
			void BridgeConstraintTest();
	
			bool SelectObject();
			void DebugObjectMovement();
			void LockedObjectMovement();

			void TeleportAI(StateEnemy*, GameObject*);

			GameObject* AddFloorToWorld(const Vector3& position, float friction);
			GameObject* AddWallToWorld(const Vector3& position);
			GameObject* AddSphereToWorld(const Vector3& position, float radius, float elasticity, float inverseMass);
			GameObject* AddCubeToWorld(const Vector3& position, Vector3 dimensions, float inverseMass = 10.0f);
			
			GameObject* AddCapsuleToWorld(const Vector3& position, float halfHeight, float radius, float inverseMass = 10.0f);

			//GameObject* AddPlaneToWorld(const Vector3& position, float size);

			GameObject* AddPlayerToWorld(const Vector3& position);
			StateEnemy* AddEnemyToWorld(const Vector3& position);
			StateEnemy* enemyStateObject = nullptr;
			GameObject* AddBonusToWorld(const Vector3& position);

			StateGameObject* AddStateObjectToWorld(const Vector3& position);
			StateGameObject* testStateObject1 = nullptr;;
			StateGameObject* testStateObject2 = nullptr;;
			StateGameObject* testStateObject3 = nullptr;;


			GameTechRenderer*	renderer;
			PhysicsSystem*		physics;
			GameWorld*			world;

			bool useGravity;
			bool gameRunning;
			bool goalReached;
			bool inSelectionMode;

			int timer = 2500;

			float		forceMagnitude;

			GameObject* selectionObject = nullptr;

			OGLMesh*	capsuleMesh = nullptr;
			OGLMesh*	cubeMesh	= nullptr;
			OGLMesh*	sphereMesh	= nullptr;
			OGLTexture* basicTex	= nullptr;
			OGLTexture* pinkTex = nullptr;
			OGLTexture* yellowTex = nullptr;
			OGLTexture* blueTex = nullptr;
			OGLShader*	basicShader = nullptr;

			//Coursework Meshes
			OGLMesh*	charMeshA	= nullptr;
			OGLMesh*	charMeshB	= nullptr;
			OGLMesh*	enemyMesh	= nullptr;
			OGLMesh*	bonusMesh	= nullptr;
			OGLMesh*	planeMesh	= nullptr;

			//Coursework Additional functionality	
			GameObject* lockedObject	= nullptr;
			Vector3 lockedOffset		= Vector3(0, 14, 20);
			void LockCameraToObject(GameObject* o) {
				lockedObject = o;
			}

			bool GameCompleted();

		};
	}
}

