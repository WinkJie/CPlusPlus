#pragma once

#include <map>
#include <string>
#include <windef.h>
using namespace std;


// X光设置相关的参数
typedef struct tagXrayParam
{
	bool bIsUseXray;					// 是否使用光管
	bool bOpenXray;						//自动测试来料，自动开启X-Ray
	int iCom;							// 与Xray通信的COM口

	int iMaxKv;							// 电压值上限
	int iMinKv;							// 电压值下限
	int iActualKv;						// 实际电压值
	int iSetKv;							// 设置的电压值

	int iMaxUa;
	int iMinUa;
	int iActualUa;
	int iSetUa;

	UINT iNotWorkAndCloseXray;				// 设备不检测时自动关闭X光，单位为分钟
	UINT iDecvieNotWork;					// 设备不检查时提示对话框重启设备，单位分钟
	UINT iCurrentXrayIdleSeconds;			// 当前X光空闲的累计时间，单位为秒

	string strType;						//光管类型

	tagXrayParam()
	{
		bIsUseXray = true;
		bOpenXray = false;
		iCom = 1;

		iMaxKv = 90;
		iMinKv = 0;
		iActualKv = 0;
		iSetKv = 60;

		iMaxUa = 89;
		iMinUa = 0;
		iActualUa = 0;
		iSetUa = 60;

		iNotWorkAndCloseXray = 15;
		iDecvieNotWork = 120;
		iCurrentXrayIdleSeconds = 0;
		strType = "L11831";
	}
}
XrayParam;



// 相机设置相关的参数
enum eCameraMode
{
	MODE_BINNING = 0,
	MODE_NORMAL = 1,
	
};

typedef struct tagCameraParam
{
	bool bIsUse;						// 是否使用相机
	int csDeviceUserSN;						//SN号
	UINT iGrabImgTimeDelay;					// 采图延时，单位毫秒
	int iImageHeight;						// 相机采图宽度
	int iImageWidth;						// 相机采图高度

	eCameraMode CameraMode;					// 相机工作模式
	UINT iCameraFps;						// 相机的帧频
	UINT iCameraFrame;						// 相机采图的帧数
	UINT iGrayMin;							// 相机对图像灰度处理Min
	UINT iGrayMax;							// 相机对图像灰度处理Max

	UINT iBright;							// iBright 亮度
	UINT iContrast;							// iContrast 对比度


	UINT iRunDays;							// 相机校准运行天数

	//堡盟相机
	float fGain;							//增益
	int iExposure;							//曝光
	int iFilter;							//滤波
	int IsFilter;							//是否滤波

	tagCameraParam()
	{
		bIsUse = true;
		csDeviceUserSN = 0;
		iGrabImgTimeDelay = 0;
		iImageHeight = 1124;
		iImageWidth = 1000;
		CameraMode = MODE_BINNING;
		iCameraFps = 20;
		iCameraFrame = 6;
		iGrayMin = 10;
		iGrayMax = 1200;

		fGain = 1.0;
		iExposure = 400;
		iFilter = 1;

		iBright = 0;
		iContrast = 0;
		IsFilter = 0;
		iRunDays = 0;
	}
}
CameraParam;


// 图片保存参数设置
enum ePicFormat
{
	JPG = 0,
	BMP = 1,
};

typedef struct tagPicSaveParam
{
	bool bSaveSrcOKPic;						// OK图片保存设置，0不保存原始图片，1保存原始图片
	bool bSaveSrcNGPic;						// OK图片保存设置，0不保存原始图片，1保存原始图片
	ePicFormat srcPicFormat;					// 图片保存格式
	bool bSaveDesOKPic;						// 0不保存测试后的图片，1保存测试后的图片
	bool bSaveDesNGPic;						// 0不保存测试后的图片，1保存测试后的图片
	ePicFormat desPicFormat;
	string saveSrcPicPath;					// 保存原始图片初始路径
	string saveDesPicPath;					// 保存测试后的图片的路径
	string savePicPath;					// 保存自动测试的图片包括原图和测试后的图片

	bool saveManualSrcPic;					//手动测试相关参数
	ePicFormat srcManualPicFormat;
	bool saveManualDesPic;
	ePicFormat desManualPicFormat;
	string saveManualSrcPicPath;
	string saveManualDesPicPath;
	string saveManualPicPath;

	float fDeletePic;			//存储空间少于多少GB后删除图片

	tagPicSaveParam()
	{
		bSaveSrcOKPic = false;
		bSaveSrcNGPic = false;
		srcPicFormat = JPG;
		bSaveDesOKPic = true;
		bSaveDesNGPic = true;
		desPicFormat = JPG;
		saveSrcPicPath = ("D:\\PIC\\SRC");
		saveDesPicPath = ("D:\\PIC\\DES");	
		savePicPath = ("D:\\PIC");

		saveManualSrcPic = false;
		srcManualPicFormat = JPG;
		saveManualDesPic = false;
		desManualPicFormat = JPG;
		saveManualSrcPicPath = ("D:\\Manual\\SRC");
		saveManualDesPicPath = ("D:\\Manual\\DES");
		saveManualPicPath = ("D:\\Manual");

		fDeletePic = 10.0;
	}

	tagPicSaveParam operator = (const tagPicSaveParam temp)
	{
		bSaveSrcOKPic = temp.bSaveSrcOKPic;
		bSaveSrcNGPic = temp.bSaveSrcNGPic;
		srcPicFormat = temp.srcPicFormat;
		bSaveDesOKPic = temp.bSaveDesOKPic;
		bSaveDesNGPic = temp.bSaveDesNGPic;
		desPicFormat = temp.desPicFormat;
		saveSrcPicPath = temp.saveSrcPicPath;
		saveDesPicPath = temp.saveDesPicPath;	
		savePicPath = temp.savePicPath;

		saveManualSrcPic = temp.saveManualSrcPic;
		srcManualPicFormat = temp.srcManualPicFormat;
		saveManualDesPic = temp.saveManualDesPic;
		desManualPicFormat = temp.desManualPicFormat;
		saveManualSrcPicPath = temp.saveManualSrcPicPath;
		saveManualDesPicPath = temp.saveManualDesPicPath;
		saveManualPicPath = temp.saveManualPicPath;

		fDeletePic = temp.fDeletePic;

		return *this;
	}
}
PicSaveParam;


enum TASK_TYPE
{
	E_TASK_Unknown = -1,
	E_TASK_RunOne,
	E_TASK_RunTwo,
	E_TASK_OnAlgorithm1,
	E_TASK_OnAlgorithm2,
	E_TASK_RunOutConveyor,
	E_TASK_ScanBarcode,//
	E_TASK_CatchNgBattery,
	E_TASK_GetImage,	//拍照
	E_TASK_GetImageDis,	//打皱拍照
	E_TASK_RunAlgorithm,
	E_TASK_RunAlgorithmDis,
	E_TASK_VisualCalibration,// 视觉标定
	E_TASK_Result,// 结果触发
	E_TASK_Motion,//运动控制
	E_TASK_Manual_RunAlgorithm,//手动算法检测
	E_TASK_ManualPlan_GetImage,//手动规划路径拍照
	E_TASK_ManualPlan_RunAlgorithm,//手动规划路径算法处理
	E_TASK_MES,//上传MES
	E_TASK_SaveExcel,//保存数据表格
	E_TASK_MesUploadData,//上传MES数据
	E_TASK_MesUploadDataCSV,
	E_TASK_CCD,//上传MES数据
};
/*


*/
#define RESET_DONE  "ResetDone" //复位完成 16
#define SOFT_READY  "Ready"     //软件打开标志
#define PC_HEART  "Heart"		//心跳标志
#define XRAY_ON  "XRayOn"		// X光打开标志
#define XRAY_WARMMING  "XRayWarmming" //X光预热中
#define Barcode_OK  "GetBarcodeOK" //扫码完成
#define Angel_1_OK  "Angel1OK"	//角1拍照完成
#define Angel_2_OK  "Angel2OK"	//角2拍照完成
#define Angel_3_OK  "Angel3OK"	//角3拍照完成
#define Angel_4_OK  "Angel4OK"	//角4拍照完成
#define Dis_1_OK  "Dis1OK"			//打折拍照1完成
#define Dis_2_OK  "Dis2OK"			//打折拍照2完成
#define Dis_3_OK  "Dis3OK"			//打折拍照3完成
#define Dis_4_OK  "Dis4OK"			//打折拍照4完成
#define VisCal_1_OK  "VisCal1OK"//视觉标定1位完成
#define VisCal_2_OK  "VisCal2OK"//视觉标定2位完成
#define VisCal_3_OK  "VisCal3OK"//视觉标定3位完成
#define VisCal_4_OK  "VisCal4OK"//视觉标定4位完成
#define Battery_OK  "BatteryOK" //电池OK
#define Barcode_NG  "BarcodeNG" //扫码NG
#define Angels_NG  "AngelsNG" //电池角检测NG
#define Dis_NG  "DisNG" //电池打折检测NG
#define SET_XY_Pos  "SetXYPos" //给出位置信息

#define SET_PLC_PARAM  "SetPlcParam" //要求设置PLC
#define GET_PLC_PARAM_DONE  "SetPlcParamDone" //要求读取PLC设置完成
#define Get_PLC_PARAM  "Get_PLC_PARAM" //要求读取PLC设置

// 浮点
#define SET_X_Pos  "X" //给出位置信息
#define SET_Y_Pos  "Y" //给出位置信息

#define X_2_P_DIS  "X_2_P_DIS" //光管到平台的距离
#define X_2_C_DIS  "X_2_C_DIS" //光管到平板的距离

#define B_2_P_X_Pos  "B_2_P_X_Pos" //第一个电池扫码平台X轴位置
#define B_2_P_Y_Pos  "B_2_P_Y_Pos" //第一个电池扫码平台Y轴位置

#define Ang1_2_P_X_Pos  "Ang1_2_P_X_Pos" //第1个电池检测
#define Ang1_2_P_Y_Pos  "Ang1_2_P_Y_Pos" 
#define Ang2_2_P_X_Pos  "Ang2_2_P_X_Pos" //第2个电池检测
#define Ang2_2_P_Y_Pos  "Ang2_2_P_Y_Pos" 
#define Ang3_2_P_X_Pos  "Ang3_2_P_X_Pos" //第3个电池检测
#define Ang3_2_P_Y_Pos  "Ang3_2_P_Y_Pos" 
#define Ang4_2_P_X_Pos  "Ang4_2_P_X_Pos" //第4个电池检测
#define Ang4_2_P_Y_Pos  "Ang4_2_P_Y_Pos" 


#define Dis1_2_P_X_Pos  "Dis1_2_P_X_Pos" //第1个电池检测
#define Dis1_2_P_Y_Pos  "Dis1_2_P_Y_Pos" 


#define Ang_Z_Pos  "Ang_Z_Pos"  //电池角检测光管Z轴位置
#define Ang_Z1_Pos  "Ang_Z1_Pos" //电池角检测增强器Z1轴位置
#define Ang_Z2_Pos  "Ang_Z2_Pos" //电池角检测增强器Z2轴位置

#define Dis_Z_Pos  "Dis_Z_Pos"  //电池打折光管Z轴位置
#define Dis_Z1_Pos  "Dis_Z1_Pos" //电池打折增强器Z1轴位置
#define Dis_Z2_Pos  "Dis_Z2_Pos" //电池打折增强器Z2轴位置

#define Battery_ROWS  "Battery_ROWS" //电池行数
#define Battery_COLS  "Battery_COLS" //电池列数
#define Battery_ROWS_DIS  "Battery_ROWS_DIS" //电池行间距
#define Battery_COLS_DIS  "Battery_COLS_DIS" //电池列间距

#define Dis2_2_P_X_Pos  "Dis2_2_P_X_Pos" //第2个电池检测
#define Dis2_2_P_Y_Pos  "Dis2_2_P_Y_Pos" 
#define Dis3_2_P_X_Pos  "Dis3_2_P_X_Pos" //第3个电池检测
#define Dis3_2_P_Y_Pos  "Dis3_2_P_Y_Pos" 
#define Dis4_2_P_X_Pos  "Dis4_2_P_X_Pos" //第4个电池检测
#define Dis4_2_P_Y_Pos  "Dis4_2_P_Y_Pos" 

#define Battery_NEED_PUSH  "Battery_NEED_PUSH" //需要推出取放料
#define PRO_SN  "PRO_SN" //程序编号


/*
PC请求写入PLC参数 //23.0
PC读取PLC参数完成


光管到平台的距离 SOD //40.0
X_2_P_DIS
平板到平台的距离
光管到平板的距离 SID
X_2_C_DIS
倍率 SID/SOD




第一个电池扫码平台X轴位置 //72.0
B_2_P_X_Pos
第一个电池扫码平台Y轴位置
B_2_P_Y_Pos
第一个电池检测1角平台X轴位置
Ang1_2_P_X_Pos
第一个电池检测1角平台Y轴位置
Ang1_2_P_Y_Pos
第一个电池检测2角平台X轴位置
Ang2_2_P_X_Pos
第一个电池检测2角平台Y轴位置
Ang2_2_P_Y_Pos
第一个电池检测3角平台X轴位置
Ang3_2_P_X_Pos
第一个电池检测3角平台Y轴位置
Ang3_2_P_Y_Pos
第一个电池检测4角平台X轴位置
Ang4_2_P_X_Pos
第一个电池检测4角平台Y轴位置
Ang4_2_P_Y_Pos
第一个电池打折1平台X轴位置
Dis1_2_P_X_Pos
第一个电池打折1平台Y轴位置
Dis1_2_P_Y_Pos
电池角检测光管Z轴位置
Ang_Z_Pos
电池角检测增强器Z1轴位置
Ang_Z1_Pos
电池角检测增强器Z2轴位置
Ang_Z2_Pos
电池打折光管Z轴位置
Dis_Z_Pos
电池打折增强器Z1轴位置
Dis_Z1_Pos
电池打折增强器Z2轴位置
Dis_Z2_Pos
电池行数
Battery_ROWS
电池列数
Battery_COLS
电池行间距
Battery_ROWS_DIS
电池列间距
Battery_COLS_DIS
第一个电池打折2平台X轴位置
Dis2_2_P_X_Pos
第一个电池打折2平台Y轴位置
Dis2_2_P_Y_Pos
第一个电池打折3平台X轴位置
Dis3_2_P_X_Pos
第一个电池打折3平台Y轴位置
Dis3_2_P_Y_Pos
第一个电池打折4平台X轴位置
Dis4_2_P_X_Pos
第一个电池打折4平台Y轴位置
Dis4_2_P_Y_Pos
需要推出取放料
Battery_NEED_PUSH
程序编号
PRO_SN

*/

typedef struct ST_MachineTask
{
	int iType;
	void* userData;
	ST_MachineTask()
	{
		iType = E_TASK_Unknown;
		userData = NULL;
	}
}stMachineTask;
typedef struct tagPLCParam
{

	map<string, float> plc_param_value;
	tagPLCParam()
	{
		plc_param_value[X_2_P_DIS] = 0.0f;
		plc_param_value[X_2_C_DIS] = 0.0f;
		plc_param_value[B_2_P_X_Pos] = 0.0f;
		plc_param_value[B_2_P_Y_Pos] = 0.0f;
		plc_param_value[Ang1_2_P_X_Pos] = 0.0f;
		plc_param_value[Ang1_2_P_Y_Pos] = 0.0f;
		plc_param_value[Ang2_2_P_X_Pos] = 0.0f;
		plc_param_value[Ang2_2_P_Y_Pos] = 0.0f;
		plc_param_value[Ang3_2_P_X_Pos] = 0.0f;
		plc_param_value[Ang3_2_P_Y_Pos] = 0.0f;
		plc_param_value[Ang4_2_P_X_Pos] = 0.0f;
		plc_param_value[Ang4_2_P_Y_Pos] = 0.0f;

		plc_param_value[Dis1_2_P_X_Pos] = 0.0f;
		plc_param_value[Dis1_2_P_Y_Pos] = 0.0f;

		plc_param_value[Ang_Z_Pos] = 0.0f;
		plc_param_value[Ang_Z1_Pos] = 0.0f;
		plc_param_value[Ang_Z2_Pos] = 0.0f;
		plc_param_value[Dis_Z_Pos] = 0.0f;
		plc_param_value[Dis_Z1_Pos] = 0.0f;
		plc_param_value[Dis_Z2_Pos] = 0.0f;
		
		plc_param_value[Battery_ROWS] = 0.0f;
		plc_param_value[Battery_COLS] = 0.0f;
		plc_param_value[Battery_ROWS_DIS] = 0.0f;
		plc_param_value[Battery_COLS_DIS] = 0.0f;

		plc_param_value[Dis2_2_P_X_Pos] = 0.0f;
		plc_param_value[Dis2_2_P_Y_Pos] = 0.0f;
		plc_param_value[Dis3_2_P_X_Pos] = 0.0f;
		plc_param_value[Dis3_2_P_Y_Pos] = 0.0f;
		plc_param_value[Dis4_2_P_X_Pos] = 0.0f;
		plc_param_value[Dis4_2_P_Y_Pos] = 0.0f;

		plc_param_value[Battery_NEED_PUSH] = 0.0f;
		plc_param_value[PRO_SN] = 0.0f;
		
	}

	float GetValue(string name)
	{
		if (plc_param_value.find(name) == plc_param_value.end())
			return 0.0f;
		return plc_param_value[name];
	}
}PLCParam;

// 电池测试规格参数
enum eDetectionPosition //检测的四个角点标记
{
	DETECTION_UP_LEFT = 0,					//--头部左上角
	DETECTION_UP_RIGHT = 1,					//--头部右上角
	DETECTION_UP_LEFT_RIGHT = 2,			//--头部整个检测
	DETECTION_DOWN_LEFT = 3,				//--尾部左下角	
	DETECTION_DOWN_RIGHT = 4,				//--尾部右上角	
	DETECTION_DOWN_LEFT_RIGHT = 5			//--尾部整个检测
};
typedef struct tagBatteryDetectionParam
{
	string	testModelName;						// 检测型号名称
	bool bIsUsed;								//是否检测该位置
	
	int kind;									// 电池类型，如软包、铝壳。。。
	int detectionPosition;						// 检测极片位置
												//5200A系列是1,2,3,4角
	bool bVerticalPosition;						//竖直方向
	float fOverhangMin;							// 整齐度最小值
	float fOverhangMax;							// 整齐度最大值
	float fCheckDectHeigh;						//检测区域的高度单位毫米
	float fCheckDectWidth;
	float fBoundaryWidth;						// 边界宽度（mm）
	float fPoleWidth;							// 单层宽度（mm）
	float fMaxPoleWidth;						// 最大层宽
	float fPixToMM;								// 实际距离与像素的比值
	float fPixToMM_plc;								// 实际距离与像素的比值 from plc
	UINT iLayer;								// 测试电池的层数
	UINT iLayer_B;								// 测试电池的层数
	float fMaxDistPole;							//单层检测最大长度

	bool bIsDetectionDu;
	bool bIsDetectionTab;
	int iRivetWidth;							// 盖帽宽度
	int iRivetHeight;							// 盖帽高度
	float fkAreaRatio;							// K区域比例
	float fDu;									// 极芯与盖帽的距离阈值
	float fTab;

	bool bCheckAnodeRange;
	bool bCheckCathodeRange;
	float AnodeRangeMax;
	float CathodeRangeMax;

	double ToHatMin;
	double ToHatMax;
	float MinDist;	//阴极与阳极的最小落差
	float MaxDist;

	int iLackMin;		//碟片电池最小空缺
	int iLackOffset;	//碟片电池最小偏移量

	//滚槽长宽
	int GunCaoNG;		//连续几个滚槽NG报警
	double DepthMax; 
	double DepthMin;
	double HeightMax;
	double HeightMin;

	int iROIleft;	// 原图中的检测区域
	int iROItop;
	int iROIright;
	int iROIbottom;

	//极耳碰壁检测
	bool bCheckPoleToSide;
	double dPoleEarMax;		//极耳碰壁最大值
	double dPoleEarMin;
	float fEarToLeftSideThre;
	float fEarToRightSideThre;
	float fEarToTopSideThre;
	float fEarToBottomSideThre;
	float fSideShellWidth;

	float fCheckDectRectX;
	float fCheckDectRectY;
	float fCheckDectRectWeight;
	float fCheckDectRectHeight;

	float fMiddleRatio;				      
	int nGrayThreshold;			

	// 松下增加参数   20180506
	float fEarToLeftSideMaxThre;			// 极耳到左侧壁距离最大阈值
	float fEarToRightSideMaxThre;				// 极耳到右侧壁距离最大阈值

	bool bArcCorner;
	float iArcCornerMin;
	float iArcCornerMax;

	PLCParam m_plcParam;
	tagBatteryDetectionParam()
	{
		testModelName = ("18650");
		bIsUsed = true;
		kind = 1;
		fPixToMM = 0.01f;
		fPixToMM_plc = 0.02f;
		iLayer = 32;
		iLayer_B = 32;
		fOverhangMin = 0.1f;
		fOverhangMax = 20.0f;
		fCheckDectHeigh = 2500.0;
		fCheckDectWidth = 10.0;
		fDu = 2.0;
		fTab = 2.0;
		detectionPosition = DETECTION_UP_LEFT_RIGHT;// 算法处理下标下标。角度下标：plc实际下标，映射算法处理下标
		bVerticalPosition = false;
		bIsDetectionDu = false;
		bIsDetectionTab = false;
		fBoundaryWidth = 0.6f;
		fPoleWidth = 1500.0f;
		fMaxPoleWidth = 1.0f;
		iRivetWidth = 500;
		iRivetHeight = 200;
		fkAreaRatio = 0.25;

		fMaxDistPole = 22.0;

		bCheckAnodeRange = true;
		bCheckCathodeRange = true;
		AnodeRangeMax = 30;
		CathodeRangeMax = 30;

		ToHatMin = 0.2;
		ToHatMax = 1.0;
		MinDist = 1.0;
		MaxDist = 30;

		iLackMin = 12;
		iLackOffset = 240;

		GunCaoNG = 5;
		DepthMax = 1.0;
		DepthMin = 0.2;
		HeightMax = 1.0;
		HeightMin = 0.2;

		iROIleft = 50;
		iROItop = 100;
		iROIright = 950;
		iROIbottom = 800;
		bCheckPoleToSide = false;
		dPoleEarMax = 3;
		dPoleEarMin = 0;

		fEarToLeftSideThre = 0.1f;
		fEarToRightSideThre = 0.1f;
		fEarToTopSideThre = 0.1f;
		fEarToBottomSideThre = 0.1f;
		fSideShellWidth = 0.25f;

		fCheckDectRectX = 200.0;
		fCheckDectRectY = 200.0;
		fCheckDectRectWeight = 200.0;
		fCheckDectRectHeight = 200.0;

		fMiddleRatio = 0.25;
		nGrayThreshold = 80;

		fEarToLeftSideMaxThre = 1.5;
		fEarToRightSideMaxThre = 1.5;

		bArcCorner = false;
		iArcCornerMin = 0;
		iArcCornerMax = 0;
	}

	void init()
	{
		testModelName = ("18650");
		bIsUsed = true;
		kind = 1;
		fPixToMM = 0.01f;
		fPixToMM_plc = 0.02f;
		iLayer = 32;
		iLayer_B = 32;
		fOverhangMin = 0.1f;
		fOverhangMax = 20.0f;
		fCheckDectHeigh = 2500.0;
		fCheckDectWidth = 10.0;
		fDu = 2.0;
		fTab = 2.0;
		detectionPosition = DETECTION_UP_LEFT_RIGHT;// 算法处理下标下标。角度下标：plc实际下标，映射算法处理下标
		bVerticalPosition = false;
		bIsDetectionDu = false;
		bIsDetectionTab = false;
		fBoundaryWidth = 0.6f;
		fPoleWidth = 1500.0f;
		fMaxPoleWidth = 1.0f;
		iRivetWidth = 500;
		iRivetHeight = 200;
		fkAreaRatio = 0.25;

		fMaxDistPole = 22.0;

		bCheckAnodeRange = true;
		bCheckCathodeRange = true;
		AnodeRangeMax = 30;
		CathodeRangeMax = 30;

		ToHatMin = 0.2;
		ToHatMax = 1.0;
		MinDist = 1.0;
		MaxDist = 30;

		iLackMin = 12;
		iLackOffset = 240;

		GunCaoNG = 5;
		DepthMax = 1.0;
		DepthMin = 0.2;
		HeightMax = 1.0;
		HeightMin = 0.2;

		iROIleft = 50;
		iROItop = 100;
		iROIright = 950;
		iROIbottom = 800;
		bCheckPoleToSide = false;
		dPoleEarMax = 3;
		dPoleEarMin = 0;

		fEarToLeftSideThre = 0.1f;
		fEarToRightSideThre = 0.1f;
		fEarToTopSideThre = 0.1f;
		fEarToBottomSideThre = 0.1f;
		fSideShellWidth = 0.25f;

		fCheckDectRectX = 200.0;
		fCheckDectRectY = 200.0;
		fCheckDectRectWeight = 200.0;
		fCheckDectRectHeight = 200.0;

		fMiddleRatio = 0.25;
		nGrayThreshold = 80;

		fEarToLeftSideMaxThre = 1.5;
		fEarToRightSideMaxThre = 1.5;

		bArcCorner = false;
		iArcCornerMin = 0;
		iArcCornerMax = 0;
	}

	tagBatteryDetectionParam operator = (const tagBatteryDetectionParam temp)
	{
		testModelName = temp.testModelName;
		bIsUsed = temp.bIsUsed;
		kind = temp.kind;
		fPixToMM = temp.fPixToMM;
		iLayer = temp.iLayer;
		iLayer_B = temp.iLayer_B;
		fOverhangMin = temp.fOverhangMin;
		fOverhangMax = temp.fOverhangMax;
		fCheckDectHeigh = temp.fCheckDectHeigh;
		fCheckDectWidth = temp.fCheckDectWidth;
		fDu = temp.fDu;
		fTab = temp.fTab;
		detectionPosition = temp.detectionPosition;
		bVerticalPosition = temp.bVerticalPosition;
		bIsDetectionDu = temp.bIsDetectionDu;
		bIsDetectionTab = temp.bIsDetectionTab;
		fBoundaryWidth = temp.fBoundaryWidth;
		fPoleWidth = temp.fPoleWidth;
		fMaxPoleWidth = temp.fMaxPoleWidth;
		iRivetWidth = temp.iRivetWidth;
		iRivetHeight = temp.iRivetHeight;
		fkAreaRatio = temp.fkAreaRatio;

		fMaxDistPole = temp.fMaxDistPole;

		bCheckAnodeRange = temp.bCheckAnodeRange;
		bCheckCathodeRange = temp.bCheckCathodeRange;
		AnodeRangeMax = temp.AnodeRangeMax;
		CathodeRangeMax = temp.CathodeRangeMax;

		ToHatMin = temp.ToHatMin;
		ToHatMax = temp.ToHatMax;
		MinDist = temp.MinDist;
		MaxDist = temp.MaxDist;

		iLackMin = temp.iLackMin;
		iLackOffset = temp.iLackOffset;

		GunCaoNG = temp.GunCaoNG;
		DepthMax = temp.DepthMax;
		DepthMin = temp.DepthMin;
		HeightMax = temp.HeightMax;
		HeightMin = temp.HeightMin;

		fEarToLeftSideThre = temp.fEarToLeftSideThre;
		fEarToRightSideThre = temp.fEarToRightSideThre;
		fEarToTopSideThre = temp.fEarToTopSideThre;
		fEarToBottomSideThre = temp.fEarToBottomSideThre;
		fSideShellWidth = temp.fSideShellWidth;

		fCheckDectRectX = temp.fCheckDectRectX;
		fCheckDectRectY = temp.fCheckDectRectY;
		fCheckDectRectWeight = temp.fCheckDectRectWeight;
		fCheckDectRectHeight = temp.fCheckDectRectHeight;

		fMiddleRatio = temp.fMiddleRatio;
		nGrayThreshold = temp.nGrayThreshold;

		fEarToLeftSideMaxThre = temp.fEarToLeftSideMaxThre;
		fEarToRightSideMaxThre = temp.fEarToRightSideMaxThre;

		bArcCorner = temp.bArcCorner;
		iArcCornerMin = temp.iArcCornerMin;
		iArcCornerMax = temp.iArcCornerMax;

		return *this;
	}
}
BatteryDetectionParam;

typedef struct tagBatteryResult
{
	double dOHMax;
	double dOHMin;
	double dMax;
	double dMin;
	double dMean;
	double dNgDst;
	double dPosDst;
	double dPoleDst;		// 正负极差

	//尾部结果
	double dTailOHMax;
	double dTailOHMin;
	double dTailMax;
	double dTailMin;
	double dTailMean;
	double dTailNgDst;
	double dTailPosDst;
	double dTailPoleDst;		// 正负极差


	tagBatteryResult()
	{
		dOHMax = 0;
		dOHMin = 0;
		dMax = 0;
		dMin = 0;
		dMean = 0;
		dNgDst = 0;
		dPosDst = 0;
		dPoleDst = 0;

		dTailOHMax = 0;
		dTailOHMin = 0;
		dTailMax = 0;
		dTailMin = 0;
		dTailMean = 0;
		dTailNgDst = 0;
		dTailPosDst = 0;
		dTailPoleDst = 0;
	}

	tagBatteryResult operator = (const tagBatteryResult temp)
	{
		dOHMax = temp.dOHMax;
		dOHMin = temp.dOHMin;
		dMax = temp.dMax;
		dMin = temp.dMin;
		dMean = temp.dMean;
		dNgDst = temp.dNgDst;
		dPosDst = temp.dPosDst;
		dPoleDst = temp.dPoleDst;

		dTailOHMax = temp.dTailOHMax;
		dTailOHMin = temp.dTailOHMin;
		dTailMax = temp.dTailMax;
		dTailMin = temp.dTailMin;
		dMean = temp.dTailMean;
		dNgDst = temp.dTailNgDst;
		dPosDst = temp.dTailPosDst;
		dPoleDst = temp.dTailPoleDst;

		return *this;
	}
}
BatteryResult;

typedef struct tagATL_OEE
{
	int IsSendDataToServer;
	string strWSDL;
	string strUser;
	string strPasswd;
	int iTimeout;
	string strSite;
	string struser;
	string strResource;
	string strActivityId;
	int iStatusCode;


	tagATL_OEE()
	{
		IsSendDataToServer = 0;
		strWSDL = ("http://172.26.11.3:50000/atlmeswebservice/MachineIntegrationServiceService?wsdl");
		strUser = ("SUP_Test01");
		strPasswd = ("test12345");
		iTimeout = 5000;
		strSite = ("2001");
		struser = ("SUP_Test01");
		strResource = ("AXRX0001");
		strActivityId = ("EAP_WS");
		iStatusCode = 0;
	}

	tagATL_OEE operator = (const tagATL_OEE temp)
	{
		IsSendDataToServer = temp.IsSendDataToServer;
		strWSDL = temp.strWSDL;
		strUser = temp.strUser;
		strPasswd = temp.strPasswd;
		iTimeout = temp.iTimeout;
		strSite = temp.strSite;
		struser = temp.struser;
		strResource = temp.strResource;
		strActivityId = temp.strActivityId;
		iStatusCode = temp.iStatusCode;

		return *this;
	}
}
ATL_OEE;



typedef struct tagATL_DC
{
	int IsSendDataToServer;
	string strWSDL;
	int iTimeout;
	string strUser;
	string strPasswd;
	
	string strSite;
	string struser;
	string strOperation;
	string strOperationRevision;
	string strResource;
	string strActivityId;
	string strDcGroup;
	string strDcGroupRevision;
	int modeProcessSfc;


	tagATL_DC()
	{
		IsSendDataToServer = 0;
		strWSDL = ("http://172.26.11.3:50000/atlmeswebservice/MachineIntegrationServiceService?wsdl");
		strUser = ("SUP_Test01");
		strPasswd = ("test12345");
		iTimeout = 5000;

		strSite = ("2001");
		struser = ("SUP_Test01");
		strOperation = ("XRAYT1");
		strOperationRevision = ("#");
		strResource = ("AXRX0001");
		strActivityId = ("EAP_WS");
		strDcGroup = ("*");
		strDcGroupRevision = ("#");
		modeProcessSfc = 1;
		
	}

	tagATL_DC operator = (const tagATL_DC temp)
	{
		IsSendDataToServer = temp.IsSendDataToServer;
		strWSDL = temp.strWSDL;
		strUser = temp.strUser;
		strPasswd = temp.strPasswd;
		iTimeout = temp.iTimeout;

		strSite = temp.strSite;
		struser = temp.struser;
		strOperation = temp.strOperation;
		strOperationRevision = temp.strOperationRevision;
		strResource = temp.strResource;
		strActivityId = temp.strActivityId;
		strDcGroup = temp.strDcGroup;
		strDcGroupRevision = temp.strDcGroupRevision;
		modeProcessSfc = temp.modeProcessSfc;

		return *this;
	}
}
ATL_DC;


typedef struct tagATL_Resource
{
	int IsSendDataToServer;
	string strWSDL;
	string strUser;
	string strPasswd;
	int iTimeout;

	string strSite;
	string struser;
	string strResource;
	string strDcGroup;
	string strDcGroupRevision;


	tagATL_Resource()
	{
		IsSendDataToServer = 0;
		strWSDL = ("http://172.26.11.3:50000/atlmeswebservice/MachineIntegrationServiceService?wsdl");
		strUser = ("SUP_Test01");
		strPasswd = ("test12345");
		iTimeout = 5000;
		strSite = ("2001");
		struser = ("SUP_Test01");
		strResource = ("AXRX0001");
		strDcGroup = ("*");
		strDcGroupRevision = ("#");
	}

	tagATL_Resource operator = (const tagATL_Resource temp)
	{
		IsSendDataToServer = temp.IsSendDataToServer;
		strWSDL = temp.strWSDL;
		strUser = temp.strUser;
		strPasswd = temp.strPasswd;
		iTimeout = temp.iTimeout;
		strSite = temp.strSite;
		struser = temp.struser;
		strResource = temp.strResource;
		strDcGroup = temp.strDcGroup;
		strDcGroupRevision = temp.strDcGroupRevision;

		return *this;
	}
}
ATL_Resource;

typedef struct tagATL_WEB_LOG
{
	int IsSaveLog;
	string strPath;


	tagATL_WEB_LOG()
	{
		IsSaveLog = 1;
		strPath = ("D:\\WebServiceLog");
	}

	tagATL_WEB_LOG operator = (const tagATL_WEB_LOG temp)
	{
		IsSaveLog = temp.IsSaveLog;
		strPath = temp.strPath;
		
		return *this;
	}
}
ATL_WEB_LOG;

typedef struct tagATL_SFC_LOG
{
	int IsSaveLog;
	string strPath;


	tagATL_SFC_LOG()
	{
		IsSaveLog = 1;
		strPath = ("E:\\MESData");
	}

	tagATL_SFC_LOG operator = (const tagATL_SFC_LOG temp)
	{
		IsSaveLog = temp.IsSaveLog;
		strPath = temp.strPath;
		
		return *this;
	}
}
ATL_SFC_LOG;

typedef struct tagData_Save_Param
{
	int IsSaveData;
	string strPath;

	tagData_Save_Param()
	{
		IsSaveData = 1;
		strPath = ("D:\\DataFiles");
	}

	tagData_Save_Param operator = (const tagData_Save_Param temp)
	{
		IsSaveData = temp.IsSaveData;
		strPath = temp.strPath;

		return *this;
	}
}
Data_Save_Param;


//模拟PLC信号控制PC动作
typedef struct tagPCSignal
{
	bool ReadID1;
	bool ReadID2;
	bool CCD1Grab;
	bool CCD2Grab;
	bool CCD3Grab;
	bool CCD4Grab;
	bool Reset;
	bool CatchNg;
	tagPCSignal()
	{
		ReadID1 = false;
		ReadID2 = false;
		CCD1Grab = false;
		CCD2Grab = false;
		CCD3Grab = false;
		CCD4Grab = false;
		Reset = false;
		CatchNg = false;
	}
}
PCSignal;

typedef struct tagNavigationCAL
{
	POINT upLeft;
	POINT upLeftPulse;
	POINT downRight;
	POINT downRightPulse;

	float xRatio;
	float yRatio;
}
NavigationCAL;