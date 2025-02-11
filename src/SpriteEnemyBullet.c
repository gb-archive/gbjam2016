#pragma bank 2
#include "SpriteEnemyBullet.h"
UINT8 bank_SPRITE_ENEMY_BULLET = 2;

#include "../res/src/enemybullet.h"
#include "SpriteManager.h"
#include "GBJAM2016.h"
#include "Sound.h"

struct EnemyBulletCustomData {
	INT8 vx;
	INT8 vy;
};

void CreateEnemyBullet(UINT16 x, UINT16 y, INT8 vx, INT8 vy){
	struct Sprite* spr = SpriteManagerAdd(SPRITE_ENEMY_BULLET, x, y);
	struct EnemyBulletCustomData* data = (struct EnemyBulletCustomData*)spr->custom_data;

	data->vx = vx;
	data->vy = vy;

	PlayFx(CHANNEL_1, 10, 0x2C, 0xD8, 0xF3, 0x62, 0xC7);
}

void Start_SPRITE_ENEMY_BULLET() {
	THIS->coll_x = 2u;
	THIS->coll_w = 4u;
	THIS->coll_y = 6u;
	THIS->coll_h = 4u;
}

void Update_SPRITE_ENEMY_BULLET() {
	struct EnemyBulletCustomData* data = (struct EnemyBulletCustomData*)THIS->custom_data;
	
	THIS->x += (INT16)data->vx << delta_time;
	THIS->y += (INT16)data->vy << delta_time;
}

void Destroy_SPRITE_ENEMY_BULLET() {
}
