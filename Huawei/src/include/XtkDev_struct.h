#pragma once

#ifndef XTKDEV_STRUCT_H
#define XTKDEV_STRUCT_H

//==============================================================================
//== XIC Tool Kit Struct
//==============================================================================

struct XtkDev
{
    //General info
    char            ScannerManufacturer [XTK_MAX_STRLEN];
    char            SofwareVersion      [XTK_MAX_STRLEN];
    char            ScannerModel        [XTK_MAX_STRLEN];
    char            message             [XTK_MAX_STRLEN];


    //XIC configuration file
    char            xcf_file_name       [XTK_MAX_STRLEN];
    char            xcf_ver             [XTK_MAX_STRLEN];


    //PC interface setting
    char            intf_cfg            [XTK_MAX_STRLEN];
    char            intf_dll            [XTK_MAX_STRLEN];
    char            intf_path           [XTK_MAX_STRLEN];
    void            *intf_p;

    unsigned short  lines_per_frame;
    unsigned short  frame_fifo_pos;
    unsigned char*  RawData;
    unsigned char*  RawLineData;


    //Timing
    float           master_clk;
    float           pixel_clk;
    unsigned char   clk_div;
    float           clk_div_mult;
    float           sample_ratio;
    float           timing_ratio;
    bool            cmos_rst_edge;
    bool            FFFlag;

    //Register Setting
    unsigned char   set_register_flag;
    unsigned char   register_mode;
    unsigned char   other_num_reg;
    unsigned char*  other_addr;
    unsigned char*  other_reg;
    unsigned char*  other_val;


    //FPGA Setting
    unsigned char   fpga_addr;
    unsigned char   fpga_num_reg;
    unsigned char*  fpga_reg;
    unsigned char*  fpga_val;

    unsigned char   rst_time_man;
    unsigned char   rst_time_exp;
    unsigned char   int_time_man;
    unsigned char   int_time_exp;
    unsigned char   rden_delay_man;
    unsigned char   rden_delay_exp;
    unsigned char   rden_pulse_man;
    unsigned char   rden_pulse_exp;
    unsigned char   FFrst_man;
    unsigned char   FFrst_exp;
    unsigned char   FFint_man;
    unsigned char   FFint_exp;

    unsigned char   posenc;
    unsigned char   gpreg0;
    unsigned char   gpreg1;
    unsigned char   gpreg2;

    unsigned short  control_bits;

    unsigned char   sen_num_sel;
    unsigned char   sen_num_bit;
    unsigned char*  sen_bit_loc;

    unsigned char   res_num_sel;
    float*          res_sel_array;
    float           resolution;
    unsigned short* pixels_per_module_array;
    unsigned short  pixels_per_module;
    unsigned short  pixels_per_array;
    unsigned char   res_num_bit;
    unsigned char*  res_bit_loc;

    unsigned char   dir_num_sel;
    unsigned char   dir_num_bit;
    unsigned char*  dir_bit_loc;


    //ADC Setting
    unsigned short  bytes_per_adc_write;
    unsigned long   bytes_per_adc_smp;
    unsigned long   adc_writes_per_line;
    unsigned long   bytes_per_line;

    unsigned char   num_adc_branch;
    unsigned char*  adc_per_branch;
    unsigned char*  adc_r1;
    unsigned char*  adc_r2;
    unsigned char*  adc_r3;
    unsigned char*  adc_r9;
    unsigned char*  adc_r0;

    unsigned char   num_adcs;
    unsigned char*  adc_addr;
    unsigned short* adc_bytes_shift;
    unsigned short* channel_bytes_shift;
    unsigned char*  modules_per_channel;
    unsigned short  modules_per_array;
    unsigned long*  module_jump;


    //Decoding
    unsigned char   decode_algorithm;
    unsigned short  bytes_offset;
    unsigned char*  ln_cnt_offset;

    unsigned short  num_mp;
    unsigned short* mp_a;

    unsigned short  num_itpl;
    unsigned short* itpl_p;
    unsigned short* itpl_l;
    unsigned short* itpl_r;
    double*         itpl_wl;
    double*         itpl_wr;

    unsigned short  LogMode;
};


#endif