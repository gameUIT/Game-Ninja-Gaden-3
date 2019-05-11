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

		/* thời gian đổi frame mặc định của animation là 100 milis, cứ sau 120 milis thì animation sẽ đổi 1 frame */
		globalsConfigurationDouble->insert(pair<const char*, double>("object_animation_time_default", 120));

		/* trọng lực mặc định của đối tượng 80 (px/s^2) */
		globalsConfigurationDouble->insert(pair<const char*, double>("object_default_ay", -400));

		/* PLAYER */
		globalsConfigurationDouble->insert(pair<const char*, double>("player_vx", 110));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_vy_jump", 280)); //280
		globalsConfigurationDouble->insert(pair<const char*, double>("player_hit_vx", 100));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_hit_vy", 150));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_blink_time", 10));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_blink_delay", 1000));

		/*  PANTHER  */
		globalsConfigurationDouble->insert(pair<const char*, double>("panther_vx", 150));
		globalsConfigurationDouble->insert(pair<const char*, double>("panther_vy_jump", 50));
		globalsConfigurationDouble->insert(pair<const char*, double>("panther_distance_to_activate", 80));

		/*  SWORD MAN  */
		globalsConfigurationDouble->insert(pair<const char*, double>("swordman_vx", 80));
		globalsConfigurationDouble->insert(pair<const char*, double>("swordman_distance_to_activate", 200));

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
