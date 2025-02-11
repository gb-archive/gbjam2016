#pragma bank 2
#include "SpriteRoller.h"
UINT8 bank_SPRITE_ROLLER = 2;

#include "SpriteManager.h"
#include "Scroll.h"
#include "Math.h"
#include "Sprite.h"

const UINT8 roller_anim_roll[] = {4, 0, 1, 2, 3};

struct RollerCustomData {
	fixed tx, ty;
	fixed vx;
	fixed vy;
};

void Start_SPRITE_ROLLER() {
	struct RollerCustomData* data = (struct RollerCustomData*)THIS->custom_data;

	THIS->coll_y += 1;
	THIS->coll_h -= 1;
	

	data->vx.w = 0;
	data->vy.w = 0;
	data->tx.w = 0;
	data->ty.w = 0;
}

INT16 DispLeft(INT16 v, INT8 desp) {
	return v >> desp;
}

void Update_SPRITE_ROLLER() {
	struct RollerCustomData* data = (struct RollerCustomData*)THIS->custom_data;
	
	if(THIS->anim_data == 0) {
		if(U_LESS_THAN(DISTANCE(scroll_target->x + 8, THIS->x), 60)) {
			SetSpriteAnim(THIS, roller_anim_roll, 33);
		}
	} else {
		if(U_LESS_THAN(scroll_target->x, THIS->x)) {
			data->vx.w = data->vx.w - (INT16)(16 << delta_time);
		} else {
			data->vx.w = data->vx.w + (INT16)(16 << delta_time);
		}

		data->tx.w += data->vx.w;
		if(TranslateSprite(THIS, data->tx.b.h, 0)){
			data->vx.w = -data->vx.w;
			data->vx.w = DispLeft(data->vx.w, 1);
		}
		data->tx.b.h = 0;

		if(U_LESS_THAN(data->vy.w, 1200)) {
			data->vy.w += 32 << delta_time;
		}
		data->ty.w += data->vy.w;
		if(TranslateSprite(THIS, 0, data->ty.b.h)) {
			data->vy.w = -data->vy.w;
			data->vy.w = DispLeft(data->vy.w, 1);
		}		
		data->ty.b.h = 0;
	}
}

void Destroy_SPRITE_ROLLER() {
}
