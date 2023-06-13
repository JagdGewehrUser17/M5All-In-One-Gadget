/* インクルードガード */
#pragma once

class MdWBGTMonitor // classの定義
{
private: // privateはクラス内からしかアクセスできない
public:
void init();
void getWBGT(double* temperature, double* humidity, WbgtIndex* index);
};
