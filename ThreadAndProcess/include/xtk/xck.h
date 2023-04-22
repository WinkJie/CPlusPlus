#pragma once

#ifndef XCK_H
#define XCK_H


//==============================================================================
//== CONSTANT 
//==============================================================================
#define XCK_VER                             "v4.0.0"
#define PNU_VER                             "pnu_ver = v1.5"
#define XCK_MAX_STRLEN                      1024
#define XCK_PERFORM_DRK                     0x0001
#define XCK_PERFORM_BRI                     0x0002
#define XCK_PERFORM_AUTOPOLY                0x0004
#define XCK_PERFORM_MANUALPOLY              0x0008
#define AUTOPOLYFIT                         1
#define MANUALPOLYFIT                       2
#define XCK_UPPER_RANGE                     65534
#define XCK_SUCCESS                         0
#define XCK_FAILURE                         1


//==============================================================================
//== XCK API
//==============================================================================
#include "../xtk.h"
#include "XckDev_struct.h"

extern "C++" {

//Initialization at the beginning
__declspec(dllexport) XckDev* xck_init(unsigned short pixels_per_array);


//Calibration process
//either load a previous calibration
__declspec(dllexport) char xck_load_calibration(XckDev* xck_p,
                                                char* pnu_file_name);

//or perform a new calibration
__declspec(dllexport) char xck_set_calibration_mode(XckDev* xck_p,
                                                    unsigned short mode);

__declspec(dllexport) char xck_set_lines_avg(XckDev* xck_p,
                                             unsigned short lines_to_avg);

    //two-point calibration
__declspec(dllexport) char xck_set_drk_level(XckDev* xck_p,
                                             double drk_level);

__declspec(dllexport) char xck_set_bri_level(XckDev* xck_p,
                                             double bri_level);

__declspec(dllexport) char xck_set_keep_gain_flag(XckDev* xck_p,
                                                  bool flag);

    //polyfit calibration

__declspec(dllexport) char xck_set_upper_range(XckDev* xck_p,
                                               unsigned long upper_range);
__declspec(dllexport) char xck_set_yval(XckDev* xck_p, 
                                        int y_val);
__declspec(dllexport) char xck_set_polyorder(XckDev* xck_p,
                                             unsigned char polyorder);

__declspec(dllexport) char xck_set_num_levels_auto(XckDev* xck_p,
                                                   unsigned char num_levels);

__declspec(dllexport) char xck_set_num_levels_manual(XckDev* xck_p,
                                                     unsigned char num_levels);

    //two ways to peform calibration

__declspec(dllexport) char xck_perform_calibration(XtkDev* xtk_p,
                                                   XckDev* xck_p);
                                                   
__declspec(dllexport) char xck_perform_calibration(XtkDev* xtk_p,
                                                   XckDev* xck_p,
                                                   char* pnu_file_name);

//save the current calibration when finish
__declspec(dllexport) char xck_save_calibration(XckDev* xck_p,
                                                char* pnu_file_name);

//or simply just reset the current calibration
__declspec(dllexport) char xck_reset_2pt_cal(XckDev* xck_p);

__declspec(dllexport) char xck_reset_all_cal(XckDev* xck_p);


//To calibrate data
__declspec(dllexport) char xck_calibrate(unsigned short* PixelsData,
                                         XckDev* xck_p,
                                         unsigned short* CalibratedPixelsData);


//Free memory in the end
__declspec(dllexport) void xck_close(XckDev* xck_p);


//Get last error message
__declspec(dllexport) char* xck_get_last_error_message(XckDev* xck_p);


//Message indication & Callback function
__declspec(dllexport) char xck_set_xray_indication_message(XckDev* xck_p,
                                                           char* turn_on_xray,
                                                           char* turn_off_xray);

__declspec(dllexport) char xck_set_xray_set_level_message(XckDev* xck_p,
                                                          char* set_xray_level);

__declspec(dllexport) char xck_set_msgbox_title(XckDev* xck_p,
                                                char* title);

__declspec(dllexport) char xck_set_msgbox_function(XckDev* xck_p,
                                                   MsgBox msgbox);

//Example for call back function
//void message(char * message, char *title);

__declspec(dllexport) char xck_set_drk_cal_ack_function(XckDev* xck_p,
                                                        DrkAck drkack);

__declspec(dllexport) char xck_set_bri_cal_ack_function(XckDev* xck_p,
                                                        BriAck briack);

__declspec(dllexport) char xck_set_poly_cal_ack_function(XckDev* xck_p,
                                                         PolyAck polyack);

}


#endif