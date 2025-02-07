#pragma bank 2
#include "GBJAM2016.h"
UINT8 init_bank = 2;

#include "StateMenu.h"
#include "StateGame.h"
#include "StateLiveLost.h"
#include "StateGameOver.h"
#include "StateStageIntro.h"
#include "StateWin.h"
#include "StateStageSelect.h"
#include "StateEnding.h"

#include "SpritePrincess.h"
#include "SpriteBullet.h"
#include "SpriteMushroom.h"
#include "SpriteEnemyBullet.h"
#include "SpriteCeilingShooter.h"
#include "SpriteShooter.h"
#include "SpriteEnemyParticle.h"
#include "SpritePrincessParticle.h"
#include "SpritePlatform.h"
#include "SpriteFly.h"
#include "SpriteRoller.h"
#include "SpriteOvni.h"
#include "SpriteMissile.h"

#include "../res/src/princess.h"
#include "../res/src/princessBullet.h"
#include "../res/src/princessParticle.h"
#include "../res/src/mushroom.h"
#include "../res/src/enemybullet.h"
#include "../res/src/ceilingshooter.h"
#include "../res/src/wallshooter.h"
#include "../res/src/enemyexplosion.h"
#include "../res/src/mobileplatform.h"
#include "../res/src/flyingbug.h"
#include "../res/src/weirdroller.h"
#include "../res/src/ovni.h"
#include "../res/src/missile.h"

UINT8 next_state = STATE_MENU;

SET_N_STATES(N_STATES);
SET_N_SPRITE_TYPES(N_SPRITE_TYPES);

void InitStates() {
	INIT_STATE(STATE_MENU);
	INIT_STATE(STATE_GAME);
	INIT_STATE(STATE_LIVELOST);
	INIT_STATE(STATE_GAMEOVER);
	INIT_STATE(STATE_STAGEINTRO);
	INIT_STATE(STATE_WIN);
	INIT_STATE(STATE_STAGE_SELECT);
	INIT_STATE(STATE_ENDING);
}                                         

void InitSprites() {
	INIT_SPRITE(SPRITE_PRINCESS,     spriteprincess,   3, FRAME_16x16, 11);
	INIT_SPRITE(SPRITE_BULLET,       princessBullet,   3,  FRAME_8x16,  1);
	INIT_SPRITE(SPRITE_PPARTICLE,    princessParticle, 3, FRAME_16x16,  2);
	INIT_SPRITE(SPRITE_MUSHROOM,     mushroom,         3, FRAME_16x16,  2);
	INIT_SPRITE(SPRITE_ENEMY_BULLET, enemyBullet,      3, FRAME_8x16,   1);
	INIT_SPRITE(SPRITE_CSHOOTER,     ceilingshooter,   3, FRAME_16x16,  2);
	INIT_SPRITE(SPRITE_SHOOTER,      wallshooter,      3, FRAME_16x16,  2); 
	INIT_SPRITE(SPRITE_EPARTICLE,    enemyexplosion,   3, FRAME_16x16,  4);
	INIT_SPRITE(SPRITE_PLATFORM,		 mobileplatform,   3, FRAME_16x16,  1);
	INIT_SPRITE(SPRITE_FLY,          flyingbug,        3, FRAME_16x16,  2);
	INIT_SPRITE(SPRITE_ROLLER,       weirdroller,      3, FRAME_16x16,  4);
	INIT_SPRITE(SPRITE_OVNI,         ovni,             3, FRAME_16x16,  1);
	INIT_SPRITE(SPRITE_MISSILE,      missile,          3, FRAME_16x16,  1);
}