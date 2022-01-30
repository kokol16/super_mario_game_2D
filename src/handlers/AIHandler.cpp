#include "engine/Game.h"

void Game::AIHandler(void) {

	for (Sprite *s : SpriteManager::GetSingleton().GetTypeList("slime")) {
		int *currX = &s->x;

		if (s->bLooking) {
			if (this->mMap->GetTileLayer()->GetGridLayer()->CanMoveRight(s->GetBox()))
				s->CallAction("run.right");
			else
				s->CallAction("run.left");
		}
		else {
			if (this->mMap->GetTileLayer()->GetGridLayer()->CanMoveLeft(s->GetBox()))
				s->CallAction("run.left");
			else
				s->CallAction("run.right");
		}
		//s->SetFrame((s->GetFrame() + 1) % s->currFilm->GetTotalFrames());
	}
	 
	for (Sprite* s : SpriteManager::GetSingleton().GetTypeList("goomba")) {
		if (s->bLooking) {
			if (this->mMap->GetTileLayer()->GetGridLayer()->CanMoveRight(s->GetBox())) {
				s->CallAction("run.right");
			}
			else {
				s->CallAction("run.left");
			}
		}
		else {
			if (this->mMap->GetTileLayer()->GetGridLayer()->CanMoveLeft(s->GetBox())) {
				s->CallAction("run.left");
			}
			else {
				s->CallAction("run.right");
			}
		}
		//s->SetFrame((s->GetFrame() + 1) % s->currFilm->GetTotalFrames());
	}

}