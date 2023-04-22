#pragma once

#ifndef XCKDEV_STRUCT_H
#define XCKDEV_STRUCT_H

//Message box call back function
typedef void (__stdcall *MsgBox)(char* message, char* title);

//Acknowledge calibration call back function
typedef void (__stdcall *DrkAck)();
typedef void (__stdcall *BriAck)();
typedef void (__stdcall *PolyAck)();


//==============================================================================
//== XIC Calibration Kit Struct
//==============================================================================
struct XckDev
{    
    //data parameters
    unsigned short* PixelsData;
    unsigned short  pixels_per_array;


    //type of calibration
    char            drkcal;
    char            brical;
    char            autopolycal;
    char            manualpolycal;
    

    //2 point calibration
    unsigned short* PixelsData_drk;
    unsigned short* PixelsData_bri;
    double*         OffsetArray;
    double*         GainArray;
    bool            drkcomplete;
    bool            bricomplete;
    double          drk_level;
    double          bri_level;
    double          range;
    bool            same_gain_update_offset;


    //polynomial calibration
    double**        coeff;
    double**        DATA2D;
    char            polyorder;
    double*         lowerlimit;
    double*         upperlimit;
    double          mmse;
    
    double*         drkoffset;
    bool            polycomplete;
    unsigned char   num_levels_auto;
    unsigned char   num_levels_manual;
    int             num_levels;
    unsigned long   upper_range;
    int             y_val;


    //message buffer used for storing error messages
    char            message[XCK_MAX_STRLEN];


    //message to turn on or off xray
    char            turn_on_xray  [XCK_MAX_STRLEN];
    char            turn_off_xray [XCK_MAX_STRLEN];
    char            set_xray_level[XCK_MAX_STRLEN];
    char            msgbox_title  [XCK_MAX_STRLEN];
    MsgBox          msgbox;


    //calibration acknowledge function
    DrkAck          drkack;
    BriAck          briack;
    PolyAck         polyack;

    //progress
    float           percentcomplete;
    char            process[XCK_MAX_STRLEN];

    unsigned short  lines_to_avg;
};


#endif