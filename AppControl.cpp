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
}

void AppControl::displayTempHumiIndex()
{
}

void AppControl::displayMusicInit()
{
}

void AppControl::displayMusicStop()
{
}

void AppControl::displayMusicTitle()
{
}

void AppControl::displayNextMusic()
{
}

void AppControl::displayMusicPlay()
{
}

void AppControl::displayMeasureInit()
{
}

void AppControl::displayMeasureDistance()
{
}

void AppControl::displayDateInit()
{
}

void AppControl::displayDateUpdate()
{
}

void AppControl::controlApplication()
{
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
                }
                
                break;

            case EXIT:
                setBtnAllFlgFalse();
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;

        case MENU:

            switch (getAction()) {
            case ENTRY:
                mlcd.fillBackgroundWhite();
                displayMenuInit();
                setStateMachine(MENU, DO);
                break;

            case DO:
                if(m_flag_btnA_is_pressed){
                    getFocusState();
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
                    getFocusState();
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
                getFocusState();
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

                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

            break;

        case MUSIC_STOP:
            switch (getAction()) {
            case ENTRY:
                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

            break;

        case MUSIC_PLAY:

            switch (getAction()) {
            case ENTRY:
                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

            break;

        case MEASURE:

            switch (getAction()) {
            case ENTRY:
                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

            break;

        case DATE:

            switch (getAction()) {
            case ENTRY:
                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

        default:
            break;
        }
    }
}