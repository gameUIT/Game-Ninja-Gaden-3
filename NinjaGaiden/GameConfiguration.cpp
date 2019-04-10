#include "GameConfiguration.h"

/* Khi đặt static member phải khởi tạo như vậy */
map<const char*, double>* GameConfiguration::globalsConfigurationDouble = 0;
map<const char*, const char*>* GameConfiguration::globalsConfigurationString = 0;


/* Lấy 1 thống số ra từ 1 key cho trước */
double GameConfiguration::GetConfiguration(const char * key)
{
	/* Hướng dẫn: Đọc singleton pattern để hiểu cách viết này */
	if (globalsConfigurationDouble == 0)
	{
		globalsConfigurationDouble = new map<const char*, double>();

		/* window_width, window_height là kích thước cửa sổ */
		globalsConfigurationDouble->insert(pair<const char*, double>("window_width", 512));
		globalsConfigurationDouble->insert(pair<const char*, double>("window_height", 448));

		/* backbuffer_width, backbuffer_height là kích thước của backbuffer */
		globalsConfigurationDouble->insert(pair<const char*, double>("backbuffer_width", 256));
		globalsConfigurationDouble->insert(pair<const char*, double>("backbuffer_height", 224));

		/* fps là frame_per_second càng lớn càng mượt nhưng nó sử dụng nhiều cpu hơn */
		globalsConfigurationDouble->insert(pair<const char*, double>("fps", 70));

		/* thời gian đổi frame mặc định của animation là 100 milis, cứ sau 120 milis thì animation sẽ đổi 1 frame */
		globalsConfigurationDouble->insert(pair<const char*, double>("object_animation_time_default", 120));

		/* trọng lực mặc định của đối tượng 80 (px/s^2) */
		globalsConfigurationDouble->insert(pair<const char*, double>("object_default_ay", -400));

		globalsConfigurationDouble->insert(pair<const char*, double>("player_vx", 120));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_vy_jump", 280)); //280
		globalsConfigurationDouble->insert(pair<const char*, double>("player_blink_time", 10));
		globalsConfigurationDouble->insert(pair<const char*, double>("player_blink_delay", 1000));

		/* TODO tạo thêm các giá trị cấu hình double game tại đây
		Ví dụ: globalsConfiguration->insert(pair<const char*, double>("gia_tri_key", 10)); 10 la gia tri cua gia_tri_key
		*/

	}
	/* trả ra giá trị cấu hình tại key */
	return globalsConfigurationDouble->at(key);
}

const char * GameConfiguration::GetConfigurationString(const char * key)
{
	/* Hướng dẫn: Đọc singleton pattern để hiểu cách viết này */
	if (globalsConfigurationString == 0)
	{
		globalsConfigurationString = new map<const char*, const char*>();

		/* Tiêu đề của cửa sổ */
		globalsConfigurationString->insert(pair<const char*, const char*>("window_title", "Ninja Gaiden"));
		globalsConfigurationString->insert(pair<const char*, const  char*>("window_class", "win_game"));

		/* TODO tạo thêm các giá trị cấu hình string game tại đây
		Ví dụ: globalsConfiguration->insert(pair<const char*, const char*>("gia_tri_key", "value")); "value" la gia tri cua gia_tri_key
		*/

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
