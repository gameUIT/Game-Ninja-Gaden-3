#include "GameConfiguration.h"

/* Khi đặt static member phải khởi tạo như vậy */
map<const char*, double>* GameConfiguration::globalsConfigurationDouble = 0;
map<const char*, const char*>* GameConfiguration::globalsConfigurationString = 0;


/* Lấy 1 thống số ra từ 1 key cho trước */
double GameConfiguration::GetConfiguration(const char * key)
{
	if (globalsConfigurationDouble == 0)
	{
		globalsConfigurationDouble = new map<const char*, double>();

		/* kích thước cửa sổ */
		globalsConfigurationDouble->insert(pair<const char*, double>("window_width", 512));
		globalsConfigurationDouble->insert(pair<const char*, double>("window_height", 448));

		/* kích thước của backbuffer */
		globalsConfigurationDouble->insert(pair<const char*, double>("backbuffer_width", 256));
		globalsConfigurationDouble->insert(pair<const char*, double>("backbuffer_height", 224));

		/* frame_per_second */
		globalsConfigurationDouble->insert(pair<const char*, double>("fps", 70));

		globalsConfigurationDouble->insert(pair<const char*, double>("object_animation_time_default", 120));

		/* trọng lực mặc định của đối tượng 80 (px/s^2) */
		globalsConfigurationDouble->insert(pair<const char*, double>("object_default_ay", -400));

		/* PLAYER */
		globalsConfigurationDouble->insert(pair<const char*, double>("player_vx", 110));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_vy_jump", 280)); //280
		globalsConfigurationDouble->insert(pair<const char*, double>("player_hit_vx", 80)); //100
		globalsConfigurationDouble->insert(pair<const char*, double>("player_hit_vy", 150));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_blink_time", 10));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_blink_delay", 2000));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_invisible_delay", 1000));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_invisible_time", 30));
		
		/*  PANTHER  */
		globalsConfigurationDouble->insert(pair<const char*, double>("panther_vx", 150));
		globalsConfigurationDouble->insert(pair<const char*, double>("panther_vy_jump", 80));
		globalsConfigurationDouble->insert(pair<const char*, double>("panther_distance_to_activate", 200));

		/*  SWORD MAN  */
		globalsConfigurationDouble->insert(pair<const char*, double>("swordman_vx", 80));
		globalsConfigurationDouble->insert(pair<const char*, double>("swordman_distance_to_activate", 200));
		globalsConfigurationDouble->insert(pair<const char*, double>("runner_vx", 100));


		globalsConfigurationDouble->insert(pair<const char*, double>("bird_r", 1));
		globalsConfigurationDouble->insert(pair<const char*, double>("bird_visible", 200));
		globalsConfigurationDouble->insert(pair<const char*, double>("bird_min_x", 10));
		globalsConfigurationDouble->insert(pair<const char*, double>("bird_max_x", 50));

		globalsConfigurationDouble->insert(pair<const char*, double>("banshee_delta", 10));
		globalsConfigurationDouble->insert(pair<const char*, double>("banshee_vx", 80));
		globalsConfigurationDouble->insert(pair<const char*, double>("banshee_time_run", 2000));
		globalsConfigurationDouble->insert(pair<const char*, double>("banshee_time_fire", 1000));

		globalsConfigurationDouble->insert(pair<const char*, double>("banshee_weapon_vx", 80));
		globalsConfigurationDouble->insert(pair<const char*, double>("banshee_weapon_vy", 130));

		globalsConfigurationDouble->insert(pair<const char*, double>("shooter_run_delay", 1000));
		globalsConfigurationDouble->insert(pair<const char*, double>("shooter_delta_activ", 100));
		globalsConfigurationDouble->insert(pair<const char*, double>("shooter_fire_delay", 1000));
		globalsConfigurationDouble->insert(pair<const char*, double>("shooter_fire_time", 300));
		globalsConfigurationDouble->insert(pair<const char*, double>("shooter_vx", 80));

		globalsConfigurationDouble->insert(pair<const char*, double>("baazoka_fire_delay", 1500));
		globalsConfigurationDouble->insert(pair<const char*, double>("baazoka_fire_time", 1500));


		globalsConfigurationDouble->insert(pair<const char*, double>("shooter_bullet_vx", 200));

		globalsConfigurationDouble->insert(pair<const char*, double>("boss_vx", 150));
		globalsConfigurationDouble->insert(pair<const char*, double>("boss_vy", 230));

		globalsConfigurationDouble->insert(pair<const char*, double>("SHURIKENBIG_DX", 3));


	}
	/* trả ra giá trị cấu hình tại key */
	return globalsConfigurationDouble->at(key);
}

const char * GameConfiguration::GetConfigurationString(const char * key)
{
	if (globalsConfigurationString == 0)
	{
		globalsConfigurationString = new map<const char*, const char*>();

		/* Tiêu đề của cửa sổ */
		globalsConfigurationString->insert(pair<const char*, const char*>("window_title", "Ninja Gaiden"));
		globalsConfigurationString->insert(pair<const char*, const  char*>("window_class", "win_game"));

	}
	/* trả ra giá trị cấu hình tại key */
	return globalsConfigurationString->at(key);
}

GameConfiguration::GameConfiguration()
{
}

GameConfiguration::~GameConfiguration()
{
}
