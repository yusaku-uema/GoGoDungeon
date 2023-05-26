#include "SceneManager.h"
#include "DxLib.h"

//-----------------------------------
// XV
//-----------------------------------
AbstractScene* SceneManager::Update()
{

	AbstractScene* NextScene;

		NextScene = mScene->Update();
	
	if (NextScene != mScene)
	{
		delete mScene;
		mScene = NextScene;
	}

	return mScene;
}

//-----------------------------------
// •`‰æ
//-----------------------------------
void SceneManager::Draw() const
{

	mScene->Draw();
}