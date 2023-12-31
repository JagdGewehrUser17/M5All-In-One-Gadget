#include "AppControl.h"
#include <Arduino.h>
#include <M5Stack.h>

MdLcd mlcd;
MdWBGTMonitor mwbgt;
MdMusicPlayer mmplay;
MdMeasureDistance mmdist;
MdDateTime mdtime;

const char* g_str_orange[] = {
    COMMON_ORANGE0_IMG_PATH,
    COMMON_ORANGE1_IMG_PATH,
    COMMON_ORANGE2_IMG_PATH,
    COMMON_ORANGE3_IMG_PATH,
    COMMON_ORANGE4_IMG_PATH,
    COMMON_ORANGE5_IMG_PATH,
    COMMON_ORANGE6_IMG_PATH,
    COMMON_ORANGE7_IMG_PATH,
    COMMON_ORANGE8_IMG_PATH,
    COMMON_ORANGE9_IMG_PATH,
};

const char* g_str_blue[] = {
    COMMON_BLUE0_IMG_PATH,
    COMMON_BLUE1_IMG_PATH,
    COMMON_BLUE2_IMG_PATH,
    COMMON_BLUE3_IMG_PATH,
    COMMON_BLUE4_IMG_PATH,
    COMMON_BLUE5_IMG_PATH,
    COMMON_BLUE6_IMG_PATH,
    COMMON_BLUE7_IMG_PATH,
    COMMON_BLUE8_IMG_PATH,
    COMMON_BLUE9_IMG_PATH,
};

void AppControl::setBtnAFlg(bool flg)
{
    m_flag_btnA_is_pressed = flg;
}

void AppControl::setBtnBFlg(bool flg)
{
    m_flag_btnB_is_pressed = flg;
}

void AppControl::setBtnCFlg(bool flg)
{
    m_flag_btnC_is_pressed = flg;
}

void AppControl::setBtnAllFlgFalse()
{
    m_flag_btnA_is_pressed = false;
    m_flag_btnB_is_pressed = false;
    m_flag_btnC_is_pressed = false;
}

State AppControl::getState()
{
    return m_state;
}

void AppControl::setState(State state)
{
    m_state = state;
}

Action AppControl::getAction()
{
    return m_action;
}

void AppControl::setAction(Action action)
{
    m_action = action;
}

void AppControl::setStateMachine(State state, Action action)
{
    setState(state);
    setAction(action);
}

FocusState AppControl::getFocusState()
{
    return m_focus_state;
}

void AppControl::setFocusState(FocusState fs)
{
    m_focus_state = fs;
}

void AppControl::displayTitleInit()
{
    mlcd.displayJpgImageCoordinate(TITLE_IMG_PATH, TITLE_X_CRD, TITLE_Y_CRD);
}

void AppControl::displayMenuInit()
{
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, MENU_UP_X_CRD, MENU_UP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, MENU_DECIDE_X_CRD, MENU_DECIDE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, MENU_DOWN_X_CRD, MENU_DOWN_Y_CRD);
}

void AppControl::focusChangeImg(FocusState current_state, FocusState next_state)
{
    switch (current_state) {
        case MENU_WBGT:
            mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
            break;
        case MENU_MUSIC:
            mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
            break;
        case MENU_MEASURE:
            mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
            break;
        case MENU_DATE:
            mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
            break;
        default:
            break;
    }
    switch (next_state) {
        case MENU_WBGT:
            mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
            break;
        case MENU_MUSIC:
            mlcd.displayJpgImageCoordinate(MENU_MUSIC_FOCUS_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
            break;
        case MENU_MEASURE:
            mlcd.displayJpgImageCoordinate(MENU_MEASURE_FOCUS_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
            break;
        case MENU_DATE:
            mlcd.displayJpgImageCoordinate(MENU_DATE_FOCUS_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
            break;
        default:
            break;
    }
}

void AppControl::displayWBGTInit()
{
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(WBGT_TEMPERATURE_IMG_PATH, WBGT_TEMPERATURE_X_CRD, WBGT_TEMPERATURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_ORANGEDOT_IMG_PATH, WBGT_TDOT_X_CRD, WBGT_TDOT_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_DEGREE_IMG_PATH, WBGT_DEGREE_X_CRD, WBGT_DEGREE_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_HUMIDITY_IMG_PATH, WBGT_HUMIDITY_X_CRD, WBGT_HUMIDITY_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, WBGT_HDOT_X_CRD, WBGT_HDOT_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_PERCENT_IMG_PATH, WBGT_PERCENT_X_CRD, WBGT_PERCENT_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, WBGT_BACK_X_CRD, WBGT_BACK_Y_CRD);
    displayTempHumiIndex();
}

void AppControl::displayTempHumiIndex()
{
    mwbgt.getWBGT(&m_temperature, &m_humidity, &m_index);
    int temp = int(m_temperature * 10);
    String str_temp =  String(temp);
    int length_tem = str_temp.length();
    int i_tem, j_tem;
    char tem;
    
    for (i_tem = 0, j_tem = length_tem - 1; i_tem < j_tem; i_tem++, j_tem--) {
        tem = str_temp[i_tem];
        str_temp[i_tem] = str_temp[j_tem];
        str_temp[j_tem] = tem;
    }
    switch(str_temp.charAt(0)){
        case '0': mlcd.displayJpgImageCoordinate(COMMON_ORANGE0_IMG_PATH, WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);
        break;
        case '1': mlcd.displayJpgImageCoordinate(COMMON_ORANGE1_IMG_PATH, WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);
        break;
        case '2': mlcd.displayJpgImageCoordinate(COMMON_ORANGE2_IMG_PATH, WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);
        break;
        case '3': mlcd.displayJpgImageCoordinate(COMMON_ORANGE3_IMG_PATH, WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);
        break;
        case '4': mlcd.displayJpgImageCoordinate(COMMON_ORANGE4_IMG_PATH, WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);
        break;
        case '5': mlcd.displayJpgImageCoordinate(COMMON_ORANGE5_IMG_PATH, WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);
        break;
        case '6': mlcd.displayJpgImageCoordinate(COMMON_ORANGE6_IMG_PATH, WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);
        break;
        case '7': mlcd.displayJpgImageCoordinate(COMMON_ORANGE7_IMG_PATH, WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);
        break;
        case '8': mlcd.displayJpgImageCoordinate(COMMON_ORANGE8_IMG_PATH, WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);
        break;
        case '9': mlcd.displayJpgImageCoordinate(COMMON_ORANGE9_IMG_PATH, WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);
        break;
        default: mlcd.displayJpgImageCoordinate(COMMON_ORANGE0_IMG_PATH, WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);
        break;
        }
    switch(str_temp.charAt(1)){
        case '0': mlcd.displayJpgImageCoordinate(COMMON_ORANGE0_IMG_PATH, WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);
        break;
        case '1': mlcd.displayJpgImageCoordinate(COMMON_ORANGE1_IMG_PATH, WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);
        break;
        case '2': mlcd.displayJpgImageCoordinate(COMMON_ORANGE2_IMG_PATH, WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);
        break;
        case '3': mlcd.displayJpgImageCoordinate(COMMON_ORANGE3_IMG_PATH, WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);
        break;
        case '4': mlcd.displayJpgImageCoordinate(COMMON_ORANGE4_IMG_PATH, WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);
        break;
        case '5': mlcd.displayJpgImageCoordinate(COMMON_ORANGE5_IMG_PATH, WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);
        break;
        case '6': mlcd.displayJpgImageCoordinate(COMMON_ORANGE6_IMG_PATH, WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);
        break;
        case '7': mlcd.displayJpgImageCoordinate(COMMON_ORANGE7_IMG_PATH, WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);
        break;
        case '8': mlcd.displayJpgImageCoordinate(COMMON_ORANGE8_IMG_PATH, WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);
        break;
        case '9': mlcd.displayJpgImageCoordinate(COMMON_ORANGE9_IMG_PATH, WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);
        break;
        default: mlcd.displayJpgImageCoordinate(COMMON_ORANGE0_IMG_PATH, WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);
        break;
        }
    switch(str_temp.charAt(2)){
        case '0': mlcd.displayJpgImageCoordinate(COMMON_ORANGE0_IMG_PATH, WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
        break;
        case '1': mlcd.displayJpgImageCoordinate(COMMON_ORANGE1_IMG_PATH, WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
        break;
        case '2': mlcd.displayJpgImageCoordinate(COMMON_ORANGE2_IMG_PATH, WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
        break;
        case '3': mlcd.displayJpgImageCoordinate(COMMON_ORANGE3_IMG_PATH, WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
        break;
        case '4': mlcd.displayJpgImageCoordinate(COMMON_ORANGE4_IMG_PATH, WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
        break;
        case '5': mlcd.displayJpgImageCoordinate(COMMON_ORANGE5_IMG_PATH, WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
        break;
        case '6': mlcd.displayJpgImageCoordinate(COMMON_ORANGE6_IMG_PATH, WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
        break;
        case '7': mlcd.displayJpgImageCoordinate(COMMON_ORANGE7_IMG_PATH, WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
        break;
        case '8': mlcd.displayJpgImageCoordinate(COMMON_ORANGE8_IMG_PATH, WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
        break;
        case '9': mlcd.displayJpgImageCoordinate(COMMON_ORANGE9_IMG_PATH, WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
        break;
        default: mlcd.displayJpgImageCoordinate(COMMON_ORANGEFILLWHITE_IMG_PATH, WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
        break;
        }
    int humi = int(m_humidity * 10);
    String str_humi =  String(humi);
    int length_hum = str_humi.length();
    int i_hum, j_hum;
    char hum;
    
    for (i_hum = 0, j_hum = length_hum - 1; i_hum < j_hum; i_hum++, j_hum--) {
        hum = str_humi[i_hum];
        str_humi[i_hum] = str_humi[j_hum];
        str_humi[j_hum] = hum;
    }
    switch(str_humi.charAt(0)){
        case '0': mlcd.displayJpgImageCoordinate(COMMON_BLUE0_IMG_PATH, WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);
        break;
        case '1': mlcd.displayJpgImageCoordinate(COMMON_BLUE1_IMG_PATH, WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);
        break;
        case '2': mlcd.displayJpgImageCoordinate(COMMON_BLUE2_IMG_PATH, WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);
        break;
        case '3': mlcd.displayJpgImageCoordinate(COMMON_BLUE3_IMG_PATH, WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);
        break;
        case '4': mlcd.displayJpgImageCoordinate(COMMON_BLUE4_IMG_PATH, WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);
        break;
        case '5': mlcd.displayJpgImageCoordinate(COMMON_BLUE5_IMG_PATH, WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);
        break;
        case '6': mlcd.displayJpgImageCoordinate(COMMON_BLUE6_IMG_PATH, WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);
        break;
        case '7': mlcd.displayJpgImageCoordinate(COMMON_BLUE7_IMG_PATH, WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);
        break;
        case '8': mlcd.displayJpgImageCoordinate(COMMON_BLUE8_IMG_PATH, WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);
        break;
        case '9': mlcd.displayJpgImageCoordinate(COMMON_BLUE9_IMG_PATH, WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);
        break;
        default: mlcd.displayJpgImageCoordinate(COMMON_BLUE0_IMG_PATH, WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);
        break;
        }
    switch(str_humi.charAt(1)){
        case '0': mlcd.displayJpgImageCoordinate(COMMON_BLUE0_IMG_PATH, WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);
        break;
        case '1': mlcd.displayJpgImageCoordinate(COMMON_BLUE1_IMG_PATH, WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);
        break;
        case '2': mlcd.displayJpgImageCoordinate(COMMON_BLUE2_IMG_PATH, WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);
        break;
        case '3': mlcd.displayJpgImageCoordinate(COMMON_BLUE3_IMG_PATH, WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);
        break;
        case '4': mlcd.displayJpgImageCoordinate(COMMON_BLUE4_IMG_PATH, WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);
        break;
        case '5': mlcd.displayJpgImageCoordinate(COMMON_BLUE5_IMG_PATH, WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);
        break;
        case '6': mlcd.displayJpgImageCoordinate(COMMON_BLUE6_IMG_PATH, WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);
        break;
        case '7': mlcd.displayJpgImageCoordinate(COMMON_BLUE7_IMG_PATH, WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);
        break;
        case '8': mlcd.displayJpgImageCoordinate(COMMON_BLUE8_IMG_PATH, WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);
        break;
        case '9': mlcd.displayJpgImageCoordinate(COMMON_BLUE9_IMG_PATH, WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);
        break;
        default: mlcd.displayJpgImageCoordinate(COMMON_BLUE0_IMG_PATH, WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);
        break;
        }
    switch(str_humi.charAt(2)){
        case '0': mlcd.displayJpgImageCoordinate(COMMON_BLUE0_IMG_PATH, WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
        break;
        case '1': mlcd.displayJpgImageCoordinate(COMMON_BLUE1_IMG_PATH, WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
        break;
        case '2': mlcd.displayJpgImageCoordinate(COMMON_BLUE2_IMG_PATH, WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
        break;
        case '3': mlcd.displayJpgImageCoordinate(COMMON_BLUE3_IMG_PATH, WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
        break;
        case '4': mlcd.displayJpgImageCoordinate(COMMON_BLUE4_IMG_PATH, WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
        break;
        case '5': mlcd.displayJpgImageCoordinate(COMMON_BLUE5_IMG_PATH, WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
        break;
        case '6': mlcd.displayJpgImageCoordinate(COMMON_BLUE6_IMG_PATH, WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
        break;
        case '7': mlcd.displayJpgImageCoordinate(COMMON_BLUE7_IMG_PATH, WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
        break;
        case '8': mlcd.displayJpgImageCoordinate(COMMON_BLUE8_IMG_PATH, WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
        break;
        case '9': mlcd.displayJpgImageCoordinate(COMMON_BLUE9_IMG_PATH, WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
        break;
        default: mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
        break;
        }
    switch(m_index){
        case SAFE: mlcd.displayJpgImageCoordinate(WBGT_SAFE_IMG_PATH, WBGT_X_CRD, WBGT_Y_CRD);
        break;
        case ATTENTION: mlcd.displayJpgImageCoordinate(WBGT_ATTENTION_IMG_PATH, WBGT_X_CRD, WBGT_Y_CRD);
        break;
        case ALERT: mlcd.displayJpgImageCoordinate(WBGT_ALERT_IMG_PATH, WBGT_X_CRD, WBGT_Y_CRD);
        break;
        case HIGH_ALERT: mlcd.displayJpgImageCoordinate(WBGT_HIGH_ALERT_IMG_PATH, WBGT_X_CRD, WBGT_Y_CRD);
        break;
        case DANGER: mlcd.displayJpgImageCoordinate(WBGT_DANGER_IMG_PATH, WBGT_X_CRD, WBGT_Y_CRD);
        break;
        default:
        break;
        }
        delay(200);
}

void AppControl::displayMusicInit()
{
    mlcd.fillBackgroundWhite();
}
void AppControl::displayMusicStop()
{
   mlcd.displayJpgImageCoordinate(MUSIC_NOWSTOPPING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_PLAY_IMG_PATH, MUSIC_PLAY_STOP_X_CRD, MUSIC_PLAY_STOP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MUSIC_BACK_X_CRD, MUSIC_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_NEXT_IMG_PATH, MUSIC_NEXT_X_CRD, MUSIC_NEXT_Y_CRD);
    mlcd.displayText(mmplay.getTitle(), MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD); 
}

void AppControl::displayMusicTitle()
{
    mlcd.displayText(mmplay.getTitle(), MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD);
}

void AppControl::displayNextMusic()
{
    mmplay.selectNextMusic();
    mlcd.displayText("             ", MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD);
    mlcd.displayText(mmplay.getTitle(), MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD);
}

void AppControl::displayMusicPlay()
{
    mlcd.displayJpgImageCoordinate(MUSIC_NOWPLAYING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_STOP_IMG_PATH, MUSIC_PLAY_STOP_X_CRD, MUSIC_PLAY_STOP_Y_CRD);
}

void AppControl::displayMeasureInit(){
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(MEASURE_NOTICE_IMG_PATH, MEASURE_NOTICE_X_CRD, MEASURE_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MEASURE_BACK_X_CRD, MEASURE_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, MEASURE_DOT_X_CRD, MEASURE_DOT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MEASURE_CM_IMG_PATH, MEASURE_CM_X_CRD, MEASURE_CM_Y_CRD);
    displayMeasureDistance();
}

void AppControl::displayMeasureDistance(){
    double distance = mmdist.getDistance();
    if(distance > 400){
        distance = 0;
    }
    int dist = int(distance * 10);
    String str_dis =  String(dist);
    int length = str_dis.length();
    int i_dis, j_dis;
    char dis;
    
    for (i_dis = 0, j_dis = length - 1; i_dis < j_dis; i_dis++, j_dis--) {
        dis = str_dis[i_dis];
        str_dis[i_dis] = str_dis[j_dis];
        str_dis[j_dis] = dis;
    }
    switch(str_dis.charAt(0)){
        case '0': mlcd.displayJpgImageCoordinate(COMMON_BLUE0_IMG_PATH, MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
        break;
        case '1': mlcd.displayJpgImageCoordinate(COMMON_BLUE1_IMG_PATH, MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
        break;
        case '2': mlcd.displayJpgImageCoordinate(COMMON_BLUE2_IMG_PATH, MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
        break;
        case '3': mlcd.displayJpgImageCoordinate(COMMON_BLUE3_IMG_PATH, MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
        break;
        case '4': mlcd.displayJpgImageCoordinate(COMMON_BLUE4_IMG_PATH, MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
        break;
        case '5': mlcd.displayJpgImageCoordinate(COMMON_BLUE5_IMG_PATH, MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
        break;
        case '6': mlcd.displayJpgImageCoordinate(COMMON_BLUE6_IMG_PATH, MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
        break;
        case '7': mlcd.displayJpgImageCoordinate(COMMON_BLUE7_IMG_PATH, MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
        break;
        case '8': mlcd.displayJpgImageCoordinate(COMMON_BLUE8_IMG_PATH, MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
        break;
        case '9': mlcd.displayJpgImageCoordinate(COMMON_BLUE9_IMG_PATH, MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
        break;
        default: mlcd.displayJpgImageCoordinate(COMMON_BLUE0_IMG_PATH, MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
        break;
        }
    switch(str_dis.charAt(1)){
        case '0': mlcd.displayJpgImageCoordinate(COMMON_BLUE0_IMG_PATH, MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
        break;
        case '1': mlcd.displayJpgImageCoordinate(COMMON_BLUE1_IMG_PATH, MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
        break;
        case '2': mlcd.displayJpgImageCoordinate(COMMON_BLUE2_IMG_PATH, MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
        break;
        case '3': mlcd.displayJpgImageCoordinate(COMMON_BLUE3_IMG_PATH, MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
        break;
        case '4': mlcd.displayJpgImageCoordinate(COMMON_BLUE4_IMG_PATH, MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
        break;
        case '5': mlcd.displayJpgImageCoordinate(COMMON_BLUE5_IMG_PATH, MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
        break;
        case '6': mlcd.displayJpgImageCoordinate(COMMON_BLUE6_IMG_PATH, MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
        break;
        case '7': mlcd.displayJpgImageCoordinate(COMMON_BLUE7_IMG_PATH, MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
        break;
        case '8': mlcd.displayJpgImageCoordinate(COMMON_BLUE8_IMG_PATH, MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
        break;
        case '9': mlcd.displayJpgImageCoordinate(COMMON_BLUE9_IMG_PATH, MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
        break;
        default: mlcd.displayJpgImageCoordinate(COMMON_BLUE0_IMG_PATH, MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
        break;
        }
    switch(str_dis.charAt(2)){
        case '0': mlcd.displayJpgImageCoordinate(COMMON_BLUE0_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        break;
        case '1': mlcd.displayJpgImageCoordinate(COMMON_BLUE1_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        break;
        case '2': mlcd.displayJpgImageCoordinate(COMMON_BLUE2_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        break;
        case '3': mlcd.displayJpgImageCoordinate(COMMON_BLUE3_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        break;
        case '4': mlcd.displayJpgImageCoordinate(COMMON_BLUE4_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        break;
        case '5': mlcd.displayJpgImageCoordinate(COMMON_BLUE5_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        break;
        case '6': mlcd.displayJpgImageCoordinate(COMMON_BLUE6_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        break;
        case '7': mlcd.displayJpgImageCoordinate(COMMON_BLUE7_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        break;
        case '8': mlcd.displayJpgImageCoordinate(COMMON_BLUE8_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        break;
        case '9': mlcd.displayJpgImageCoordinate(COMMON_BLUE9_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        break;
        default: mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        break;
        }
    switch(str_dis.charAt(3)){
        case '0': mlcd.displayJpgImageCoordinate(COMMON_BLUE0_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        break;
        case '1': mlcd.displayJpgImageCoordinate(COMMON_BLUE1_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        break;
        case '2': mlcd.displayJpgImageCoordinate(COMMON_BLUE2_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        break;
        case '3': mlcd.displayJpgImageCoordinate(COMMON_BLUE3_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        break;
        case '4': mlcd.displayJpgImageCoordinate(COMMON_BLUE4_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        break;
        case '5': mlcd.displayJpgImageCoordinate(COMMON_BLUE5_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        break;
        case '6': mlcd.displayJpgImageCoordinate(COMMON_BLUE6_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        break;
        case '7': mlcd.displayJpgImageCoordinate(COMMON_BLUE7_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        break;
        case '8': mlcd.displayJpgImageCoordinate(COMMON_BLUE8_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        break;
        case '9': mlcd.displayJpgImageCoordinate(COMMON_BLUE9_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        break;
        default: mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        break;
        }
        delay(250);
}

void AppControl::displayDateInit()
{
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(DATE_NOTICE_IMG_PATH, DATE_NOTICE_X_CRD, DATE_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, DATE_BACK_X_CRD, DATE_BACK_Y_CRD);
}

void AppControl::displayDateUpdate()
{
    mlcd.displayDateText(mdtime.readDate(), DATE_YYYYMMDD_X_CRD, DATE_YYYYMMDD_Y_CRD);
    mlcd.displayDateText(mdtime.readTime(), DATE_HHmmSS_X_CRD, DATE_HHmmSS_Y_CRD);
    delay(100);
}

void AppControl::controlApplication()
{
    mmplay.init();

    while (1) {

        switch (getState()) {
        case TITLE:
            switch (getAction()) {
            case ENTRY:
                displayTitleInit();
                setStateMachine(TITLE, DO);
                break;

            case DO:
                if(m_flag_btnA_is_pressed || m_flag_btnB_is_pressed || m_flag_btnC_is_pressed){
                    setStateMachine(TITLE, EXIT);
                    setBtnAllFlgFalse();
                }
                
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;

        case MENU:

            switch (getAction()) {
            case ENTRY:
                displayMenuInit();
                setFocusState(MENU_WBGT);
                setStateMachine(MENU, DO);
                break;

            case DO:
                if(m_flag_btnA_is_pressed){
                    
                    if(m_focus_state == MENU_WBGT){
                        focusChangeImg(m_focus_state, MENU_DATE);
                        setFocusState(MENU_DATE);
                    }else if(m_focus_state == MENU_DATE){
                        focusChangeImg(m_focus_state, MENU_MEASURE);
                        setFocusState(MENU_MEASURE);
                    }else if(m_focus_state == MENU_MEASURE){
                        focusChangeImg(m_focus_state, MENU_MUSIC);
                        setFocusState(MENU_MUSIC);
                    }else if(m_focus_state == MENU_MUSIC){
                        focusChangeImg(m_focus_state, MENU_WBGT);
                        setFocusState(MENU_WBGT);
                    }else{}
                }else if(m_flag_btnB_is_pressed){
                    setStateMachine(MENU, EXIT);
                }else if(m_flag_btnC_is_pressed){
                    
                    if(m_focus_state == MENU_WBGT){
                        focusChangeImg(m_focus_state, MENU_MUSIC);
                        setFocusState(MENU_MUSIC);
                    }else if(m_focus_state == MENU_MUSIC){
                        focusChangeImg(m_focus_state, MENU_MEASURE);
                        setFocusState(MENU_MEASURE);
                    }else if(m_focus_state == MENU_MEASURE){
                        focusChangeImg(m_focus_state, MENU_DATE);
                        setFocusState(MENU_DATE);
                    }else if(m_focus_state == MENU_DATE){
                        focusChangeImg(m_focus_state, MENU_WBGT);
                        setFocusState(MENU_WBGT);
                    }else{}
                }else{}
                setBtnAllFlgFalse();
                break;

            case EXIT:
                if(m_focus_state == MENU_WBGT){
                    setStateMachine(WBGT, ENTRY);
                }else if(m_focus_state == MENU_MUSIC){
                    setStateMachine(MUSIC_STOP, ENTRY);
                }else if(m_focus_state == MENU_MEASURE){
                    setStateMachine(MEASURE, ENTRY);
                }else if(m_focus_state == MENU_DATE){
                    setStateMachine(DATE, ENTRY);
                }else{}
                break;

            default:
                break;
            }

            break;

        case WBGT:

            switch (getAction()) {
            case ENTRY:
                mwbgt.init();
                displayWBGTInit();
                setStateMachine(WBGT, DO);
                break;

            case DO:
                displayTempHumiIndex();
                if(m_flag_btnB_is_pressed){
                    setStateMachine(WBGT, EXIT);
                    setBtnAllFlgFalse();
                }
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;

        case MUSIC_STOP:
            switch (getAction()) {
            case ENTRY:
                displayMusicInit();
                displayMusicStop();
                displayMusicTitle();
                setStateMachine(MUSIC_STOP, DO);
                break;

            case DO:
                if(m_flag_btnA_is_pressed){
                    m_mu_play_flg = true;
                    setStateMachine(MUSIC_STOP, EXIT);
                    setBtnAllFlgFalse();
                }
                if(m_flag_btnC_is_pressed){
                    displayNextMusic();
                    setBtnAllFlgFalse();
                }
                if(m_flag_btnB_is_pressed){
                    setStateMachine(MUSIC_STOP, EXIT);
                    setBtnAllFlgFalse();
                }
                break;

            case EXIT:
                if(m_mu_play_flg){
                    setStateMachine(MUSIC_PLAY, ENTRY);
                }else{
                    setStateMachine(MENU, ENTRY);
                }
                break;

            default:
                break;
            }

            break;

        case MUSIC_PLAY:

            switch (getAction()) {
            case ENTRY:
                displayMusicInit();
                displayMusicPlay();
                setStateMachine(MUSIC_PLAY, DO);
                mmplay.prepareMP3();
                break;

            case DO:
                m_mu_play_flg = mmplay.isRunningMP3();
                m_mu_play_flg = mmplay.playMP3();
                if(m_flag_btnA_is_pressed){
                    m_mu_play_flg = false;
                }
                if(!m_mu_play_flg){
                    mmplay.stopMP3();
                    setStateMachine(MUSIC_PLAY, EXIT);
                }
                break;

            case EXIT:
                setBtnAllFlgFalse();
                setStateMachine(MUSIC_STOP, ENTRY);
                break;

            default:
                break;
            }

            break;

        case MEASURE:

            switch (getAction()) {
            case ENTRY:
                displayMeasureInit();
                displayMeasureDistance();
                setStateMachine(MEASURE, DO);
                break;

            case DO:
                displayMeasureDistance();
                if(m_flag_btnB_is_pressed){
                    setStateMachine(MEASURE, EXIT);
                    setBtnAllFlgFalse();
                }
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;

        case DATE:

            switch (getAction()) {
            case ENTRY:
                displayDateInit();
                displayDateUpdate();
                setStateMachine(DATE, DO);
                break;

            case DO:
                displayDateUpdate();
                if(m_flag_btnB_is_pressed){
                    setStateMachine(DATE, EXIT);
                    setBtnAllFlgFalse();
                }
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

        default:
            break;
        }
    }
}
