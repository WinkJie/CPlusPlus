#pragma once

#ifndef XTK_H
#define XTK_H


//==============================================================================
//== OS COMPATIBILITY
//==============================================================================
// determine platform
#ifdef TARGET_OS_MAC
#define TARGET_OS_UNIX
#elif defined __linux__
#define TARGET_OS_UNIX
#define TARGET_OS_LINUX
#elif defined _WIN32
#define TARGET_OS_WIN
#define TARGET_OS_WIN32
#elif defined _WIN64
#define TARGET_OS_WIN
#define TARGET_OS_WIN64
#else
#error "unknown platform"
#endif


// All UNIX including Apple Macintosh OS and Linux platforms
#ifdef TARGET_OS_UNIX
#include "dlfcn.h"
#define DECLSPEC
#define C_DECL
#define DLOPEN(a)                           dlopen(a, RTLD_LAZY)
#define DLFREE                              dlclose
#define DLSYMB                              dlsym
#define DLINST                              void *
#define SNPRINTF                            snprintf
#define PATH_SLASH                          "/"
#endif

// Apple Macintosh OS platform

// Linux platform

// MS Windows platform
#ifdef TARGET_OS_WIN
#include "windows.h"
#define DECLSPEC                            __declspec(dllexport)
#define C_DECL                              __cdecl
#define DLOPEN                              LoadLibrary
#define DLFREE                              FreeLibrary
#define DLSYMB                              GetProcAddress
#define DLINST                              HINSTANCE
#define SNPRINTF                            _snprintf
#define PATH_SLASH                          "\\"
#endif


//==============================================================================
//== CONSTANT
//==============================================================================
#define XTK_VER                             "v4.0"
#define XCF_VER                             "v2.0"
#define XTK_SUCCESS                         0
#define XTK_FAILURE                         1
#define XTK_MAX_STRLEN                      1024
#define XTK_DELIMITERS                      "= {} [] ,; \t\v\f\r\n"
#define XCF_COMMENT                         "#"
#define XTK_SERIAL_VALUE_LENGTH             10




//==============================================================================
//== XTK API
//==============================================================================
#include "XtkDev_struct.h"

extern "C" {

//main functions
DECLSPEC XtkDev* xtk_init(char* xcf_file_name);
DECLSPEC XtkDev* xtk_init_err(char* xcf_file_name, int* err_code);

DECLSPEC char xtk_config(XtkDev* xtk_p);

DECLSPEC char xtk_start(XtkDev* xtk_p);

DECLSPEC char xtk_flush_buffer(XtkDev* xtk_p);

DECLSPEC char xtk_get_frame(XtkDev* xtk_p, unsigned short** PixelsData, unsigned short frame_width, unsigned short* ln_cnt);
DECLSPEC char xtk_get_line(XtkDev* xtk_p, unsigned short* PixelsData);
DECLSPEC char xtk_get_line_timestamp(XtkDev* xtk_p, unsigned short* PixelsData, unsigned short* ln_cnt);

DECLSPEC char xtk_stop(XtkDev* xtk_p);

DECLSPEC char xtk_close(XtkDev* xtk_p);


//detector info
DECLSPEC char* xtk_get_last_error_message(XtkDev* xtk_p);

DECLSPEC char* xtk_get_info(XtkDev* xtk_p);

DECLSPEC long xtk_get_pixels_per_array(XtkDev* xtk_p);


//detector mode
DECLSPEC char xtk_set_sensitivity(XtkDev* xtk_p, unsigned char sen);
DECLSPEC char xtk_get_sensitivity(XtkDev* xtk_p);

DECLSPEC char xtk_set_resolution(XtkDev* xtk_p, unsigned char res);
DECLSPEC char xtk_get_resolution(XtkDev* xtk_p);
DECLSPEC float xtk_get_resolution_value(XtkDev* xtk_p);

DECLSPEC char xtk_set_direction(XtkDev* xtk_p, unsigned char dir);
DECLSPEC char xtk_get_direction(XtkDev* xtk_p);


//acquisition mode
DECLSPEC char xtk_set_posenc(XtkDev* xtk_p, unsigned char value);
DECLSPEC int xtk_get_posenc(XtkDev* xtk_p);


//timing
DECLSPEC char xtk_set_Tint(XtkDev* xtk_p, float Tint);
DECLSPEC float xtk_get_Tint(XtkDev* xtk_p);

DECLSPEC char xtk_set_LineRate(XtkDev* xtk_p, float LineRate);
DECLSPEC float xtk_get_LineRate(XtkDev* xtk_p);

//save detector setting
DECLSPEC char xtk_save_config_file(XtkDev* xtk_p, char* xcf_file_name);

//acquisition interface path
DECLSPEC char xtk_set_intf_path(XtkDev* xtk_p, char* intf_path);


//other
DECLSPEC unsigned char xtk_read_byte_raw(XtkDev* xtk_p, unsigned long index);

DECLSPEC char xtk_set_single_reg(XtkDev* xtk_p, unsigned char Address, unsigned char Reg, unsigned char Value);

DECLSPEC char xtk_serial_write(XtkDev* xtk_p, unsigned char Address, unsigned char Reg, unsigned char Value);
DECLSPEC char xtk_serial_read(XtkDev* xtk_p, unsigned char Address, unsigned char Reg, char* ValueHexStr);

DECLSPEC char xtk_set_pixel_clk(XtkDev* xtk_p, float value);
DECLSPEC float xtk_get_pixel_clk(XtkDev* xtk_p);

DECLSPEC char xtk_set_rst_time(XtkDev* xtk_p, unsigned char mantissa, unsigned char exponent);
DECLSPEC float xtk_get_rst_time(XtkDev* xtk_p);

DECLSPEC char xtk_set_int_time(XtkDev* xtk_p, unsigned char mantissa, unsigned char exponent);
DECLSPEC float xtk_get_int_time(XtkDev* xtk_p);

DECLSPEC float xtk_get_rden_delay(XtkDev* xtk_p);

DECLSPEC float xtk_get_rden_pulse(XtkDev* xtk_p);

DECLSPEC char xtk_save_config_file_mode(XtkDev *xtk_p, char *xcf_file_name, char* mode);

DECLSPEC char xtk_set_bytes_offset(XtkDev* xtk_p, unsigned short bytes_offset);

DECLSPEC long xtk_get_pixels_per_module(XtkDev* xtk_p);

DECLSPEC long xtk_get_modules_per_array(XtkDev* xtk_p);

DECLSPEC long xtk_get_adc_gain(XtkDev* xtk_p);

DECLSPEC long xtk_get_adc_offset(XtkDev* xtk_p);

DECLSPEC long xtk_get_adc_r1(XtkDev* xtk_p);

DECLSPEC long xtk_get_adc_r2(XtkDev* xtk_p);

DECLSPEC long xtk_get_adc_r3(XtkDev* xtk_p);

DECLSPEC void xtk_man_exp_ized(unsigned long number, unsigned char* man, unsigned char* exp);

DECLSPEC char* xtk_get_TimeStr();

DECLSPEC char xtk_rst_gen(XtkDev* xtk_p, unsigned char Val);

DECLSPEC char xtk_reset_system(XtkDev* xtk_p);

DECLSPEC char xtk_reset_LineCount(XtkDev* xtk_p);
}


#endif
