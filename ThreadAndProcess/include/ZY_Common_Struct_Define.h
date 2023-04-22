#pragma once

#include <map>
#include <string>
#include <windef.h>
using namespace std;


// X��������صĲ���
typedef struct tagXrayParam
{
	bool bIsUseXray;					// �Ƿ�ʹ�ù��
	bool bOpenXray;						//�Զ��������ϣ��Զ�����X-Ray
	int iCom;							// ��Xrayͨ�ŵ�COM��

	int iMaxKv;							// ��ѹֵ����
	int iMinKv;							// ��ѹֵ����
	int iActualKv;						// ʵ�ʵ�ѹֵ
	int iSetKv;							// ���õĵ�ѹֵ

	int iMaxUa;
	int iMinUa;
	int iActualUa;
	int iSetUa;

	UINT iNotWorkAndCloseXray;				// �豸�����ʱ�Զ��ر�X�⣬��λΪ����
	UINT iDecvieNotWork;					// �豸�����ʱ��ʾ�Ի��������豸����λ����
	UINT iCurrentXrayIdleSeconds;			// ��ǰX����е��ۼ�ʱ�䣬��λΪ��

	string strType;						//�������

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



// ���������صĲ���
enum eCameraMode
{
	MODE_BINNING = 0,
	MODE_NORMAL = 1,
	
};

typedef struct tagCameraParam
{
	bool bIsUse;						// �Ƿ�ʹ�����
	int csDeviceUserSN;						//SN��
	UINT iGrabImgTimeDelay;					// ��ͼ��ʱ����λ����
	int iImageHeight;						// �����ͼ���
	int iImageWidth;						// �����ͼ�߶�

	eCameraMode CameraMode;					// �������ģʽ
	UINT iCameraFps;						// �����֡Ƶ
	UINT iCameraFrame;						// �����ͼ��֡��
	UINT iGrayMin;							// �����ͼ��Ҷȴ���Min
	UINT iGrayMax;							// �����ͼ��Ҷȴ���Max

	UINT iBright;							// iBright ����
	UINT iContrast;							// iContrast �Աȶ�


	UINT iRunDays;							// ���У׼��������

	//�������
	float fGain;							//����
	int iExposure;							//�ع�
	int iFilter;							//�˲�
	int IsFilter;							//�Ƿ��˲�

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


// ͼƬ�����������
enum ePicFormat
{
	JPG = 0,
	BMP = 1,
};

typedef struct tagPicSaveParam
{
	bool bSaveSrcOKPic;						// OKͼƬ�������ã�0������ԭʼͼƬ��1����ԭʼͼƬ
	bool bSaveSrcNGPic;						// OKͼƬ�������ã�0������ԭʼͼƬ��1����ԭʼͼƬ
	ePicFormat srcPicFormat;					// ͼƬ�����ʽ
	bool bSaveDesOKPic;						// 0��������Ժ��ͼƬ��1������Ժ��ͼƬ
	bool bSaveDesNGPic;						// 0��������Ժ��ͼƬ��1������Ժ��ͼƬ
	ePicFormat desPicFormat;
	string saveSrcPicPath;					// ����ԭʼͼƬ��ʼ·��
	string saveDesPicPath;					// ������Ժ��ͼƬ��·��
	string savePicPath;					// �����Զ����Ե�ͼƬ����ԭͼ�Ͳ��Ժ��ͼƬ

	bool saveManualSrcPic;					//�ֶ�������ز���
	ePicFormat srcManualPicFormat;
	bool saveManualDesPic;
	ePicFormat desManualPicFormat;
	string saveManualSrcPicPath;
	string saveManualDesPicPath;
	string saveManualPicPath;

	float fDeletePic;			//�洢�ռ����ڶ���GB��ɾ��ͼƬ

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
	E_TASK_GetImage,	//����
	E_TASK_GetImageDis,	//��������
	E_TASK_RunAlgorithm,
	E_TASK_RunAlgorithmDis,
	E_TASK_VisualCalibration,// �Ӿ��궨
	E_TASK_Result,// �������
	E_TASK_Motion,//�˶�����
	E_TASK_Manual_RunAlgorithm,//�ֶ��㷨���
	E_TASK_ManualPlan_GetImage,//�ֶ��滮·������
	E_TASK_ManualPlan_RunAlgorithm,//�ֶ��滮·���㷨����
	E_TASK_MES,//�ϴ�MES
	E_TASK_SaveExcel,//�������ݱ��
	E_TASK_MesUploadData,//�ϴ�MES����
	E_TASK_MesUploadDataCSV,
	E_TASK_CCD,//�ϴ�MES����
};
/*


*/
#define RESET_DONE  "ResetDone" //��λ��� 16
#define SOFT_READY  "Ready"     //����򿪱�־
#define PC_HEART  "Heart"		//������־
#define XRAY_ON  "XRayOn"		// X��򿪱�־
#define XRAY_WARMMING  "XRayWarmming" //X��Ԥ����
#define Barcode_OK  "GetBarcodeOK" //ɨ�����
#define Angel_1_OK  "Angel1OK"	//��1�������
#define Angel_2_OK  "Angel2OK"	//��2�������
#define Angel_3_OK  "Angel3OK"	//��3�������
#define Angel_4_OK  "Angel4OK"	//��4�������
#define Dis_1_OK  "Dis1OK"			//��������1���
#define Dis_2_OK  "Dis2OK"			//��������2���
#define Dis_3_OK  "Dis3OK"			//��������3���
#define Dis_4_OK  "Dis4OK"			//��������4���
#define VisCal_1_OK  "VisCal1OK"//�Ӿ��궨1λ���
#define VisCal_2_OK  "VisCal2OK"//�Ӿ��궨2λ���
#define VisCal_3_OK  "VisCal3OK"//�Ӿ��궨3λ���
#define VisCal_4_OK  "VisCal4OK"//�Ӿ��궨4λ���
#define Battery_OK  "BatteryOK" //���OK
#define Barcode_NG  "BarcodeNG" //ɨ��NG
#define Angels_NG  "AngelsNG" //��ؽǼ��NG
#define Dis_NG  "DisNG" //��ش��ۼ��NG
#define SET_XY_Pos  "SetXYPos" //����λ����Ϣ

#define SET_PLC_PARAM  "SetPlcParam" //Ҫ������PLC
#define GET_PLC_PARAM_DONE  "SetPlcParamDone" //Ҫ���ȡPLC�������
#define Get_PLC_PARAM  "Get_PLC_PARAM" //Ҫ���ȡPLC����

// ����
#define SET_X_Pos  "X" //����λ����Ϣ
#define SET_Y_Pos  "Y" //����λ����Ϣ

#define X_2_P_DIS  "X_2_P_DIS" //��ܵ�ƽ̨�ľ���
#define X_2_C_DIS  "X_2_C_DIS" //��ܵ�ƽ��ľ���

#define B_2_P_X_Pos  "B_2_P_X_Pos" //��һ�����ɨ��ƽ̨X��λ��
#define B_2_P_Y_Pos  "B_2_P_Y_Pos" //��һ�����ɨ��ƽ̨Y��λ��

#define Ang1_2_P_X_Pos  "Ang1_2_P_X_Pos" //��1����ؼ��
#define Ang1_2_P_Y_Pos  "Ang1_2_P_Y_Pos" 
#define Ang2_2_P_X_Pos  "Ang2_2_P_X_Pos" //��2����ؼ��
#define Ang2_2_P_Y_Pos  "Ang2_2_P_Y_Pos" 
#define Ang3_2_P_X_Pos  "Ang3_2_P_X_Pos" //��3����ؼ��
#define Ang3_2_P_Y_Pos  "Ang3_2_P_Y_Pos" 
#define Ang4_2_P_X_Pos  "Ang4_2_P_X_Pos" //��4����ؼ��
#define Ang4_2_P_Y_Pos  "Ang4_2_P_Y_Pos" 


#define Dis1_2_P_X_Pos  "Dis1_2_P_X_Pos" //��1����ؼ��
#define Dis1_2_P_Y_Pos  "Dis1_2_P_Y_Pos" 


#define Ang_Z_Pos  "Ang_Z_Pos"  //��ؽǼ����Z��λ��
#define Ang_Z1_Pos  "Ang_Z1_Pos" //��ؽǼ����ǿ��Z1��λ��
#define Ang_Z2_Pos  "Ang_Z2_Pos" //��ؽǼ����ǿ��Z2��λ��

#define Dis_Z_Pos  "Dis_Z_Pos"  //��ش��۹��Z��λ��
#define Dis_Z1_Pos  "Dis_Z1_Pos" //��ش�����ǿ��Z1��λ��
#define Dis_Z2_Pos  "Dis_Z2_Pos" //��ش�����ǿ��Z2��λ��

#define Battery_ROWS  "Battery_ROWS" //�������
#define Battery_COLS  "Battery_COLS" //�������
#define Battery_ROWS_DIS  "Battery_ROWS_DIS" //����м��
#define Battery_COLS_DIS  "Battery_COLS_DIS" //����м��

#define Dis2_2_P_X_Pos  "Dis2_2_P_X_Pos" //��2����ؼ��
#define Dis2_2_P_Y_Pos  "Dis2_2_P_Y_Pos" 
#define Dis3_2_P_X_Pos  "Dis3_2_P_X_Pos" //��3����ؼ��
#define Dis3_2_P_Y_Pos  "Dis3_2_P_Y_Pos" 
#define Dis4_2_P_X_Pos  "Dis4_2_P_X_Pos" //��4����ؼ��
#define Dis4_2_P_Y_Pos  "Dis4_2_P_Y_Pos" 

#define Battery_NEED_PUSH  "Battery_NEED_PUSH" //��Ҫ�Ƴ�ȡ����
#define PRO_SN  "PRO_SN" //������


/*
PC����д��PLC���� //23.0
PC��ȡPLC�������


��ܵ�ƽ̨�ľ��� SOD //40.0
X_2_P_DIS
ƽ�嵽ƽ̨�ľ���
��ܵ�ƽ��ľ��� SID
X_2_C_DIS
���� SID/SOD




��һ�����ɨ��ƽ̨X��λ�� //72.0
B_2_P_X_Pos
��һ�����ɨ��ƽ̨Y��λ��
B_2_P_Y_Pos
��һ����ؼ��1��ƽ̨X��λ��
Ang1_2_P_X_Pos
��һ����ؼ��1��ƽ̨Y��λ��
Ang1_2_P_Y_Pos
��һ����ؼ��2��ƽ̨X��λ��
Ang2_2_P_X_Pos
��һ����ؼ��2��ƽ̨Y��λ��
Ang2_2_P_Y_Pos
��һ����ؼ��3��ƽ̨X��λ��
Ang3_2_P_X_Pos
��һ����ؼ��3��ƽ̨Y��λ��
Ang3_2_P_Y_Pos
��һ����ؼ��4��ƽ̨X��λ��
Ang4_2_P_X_Pos
��һ����ؼ��4��ƽ̨Y��λ��
Ang4_2_P_Y_Pos
��һ����ش���1ƽ̨X��λ��
Dis1_2_P_X_Pos
��һ����ش���1ƽ̨Y��λ��
Dis1_2_P_Y_Pos
��ؽǼ����Z��λ��
Ang_Z_Pos
��ؽǼ����ǿ��Z1��λ��
Ang_Z1_Pos
��ؽǼ����ǿ��Z2��λ��
Ang_Z2_Pos
��ش��۹��Z��λ��
Dis_Z_Pos
��ش�����ǿ��Z1��λ��
Dis_Z1_Pos
��ش�����ǿ��Z2��λ��
Dis_Z2_Pos
�������
Battery_ROWS
�������
Battery_COLS
����м��
Battery_ROWS_DIS
����м��
Battery_COLS_DIS
��һ����ش���2ƽ̨X��λ��
Dis2_2_P_X_Pos
��һ����ش���2ƽ̨Y��λ��
Dis2_2_P_Y_Pos
��һ����ش���3ƽ̨X��λ��
Dis3_2_P_X_Pos
��һ����ش���3ƽ̨Y��λ��
Dis3_2_P_Y_Pos
��һ����ش���4ƽ̨X��λ��
Dis4_2_P_X_Pos
��һ����ش���4ƽ̨Y��λ��
Dis4_2_P_Y_Pos
��Ҫ�Ƴ�ȡ����
Battery_NEED_PUSH
������
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

// ��ز��Թ�����
enum eDetectionPosition //�����ĸ��ǵ���
{
	DETECTION_UP_LEFT = 0,					//--ͷ�����Ͻ�
	DETECTION_UP_RIGHT = 1,					//--ͷ�����Ͻ�
	DETECTION_UP_LEFT_RIGHT = 2,			//--ͷ���������
	DETECTION_DOWN_LEFT = 3,				//--β�����½�	
	DETECTION_DOWN_RIGHT = 4,				//--β�����Ͻ�	
	DETECTION_DOWN_LEFT_RIGHT = 5			//--β���������
};
typedef struct tagBatteryDetectionParam
{
	string	testModelName;						// ����ͺ�����
	bool bIsUsed;								//�Ƿ����λ��
	
	int kind;									// ������ͣ�����������ǡ�����
	int detectionPosition;						// ��⼫Ƭλ��
												//5200Aϵ����1,2,3,4��
	bool bVerticalPosition;						//��ֱ����
	float fOverhangMin;							// �������Сֵ
	float fOverhangMax;							// ��������ֵ
	float fCheckDectHeigh;						//�������ĸ߶ȵ�λ����
	float fCheckDectWidth;
	float fBoundaryWidth;						// �߽��ȣ�mm��
	float fPoleWidth;							// �����ȣ�mm��
	float fMaxPoleWidth;						// �����
	float fPixToMM;								// ʵ�ʾ��������صı�ֵ
	float fPixToMM_plc;								// ʵ�ʾ��������صı�ֵ from plc
	UINT iLayer;								// ���Ե�صĲ���
	UINT iLayer_B;								// ���Ե�صĲ���
	float fMaxDistPole;							//��������󳤶�

	bool bIsDetectionDu;
	bool bIsDetectionTab;
	int iRivetWidth;							// ��ñ���
	int iRivetHeight;							// ��ñ�߶�
	float fkAreaRatio;							// K�������
	float fDu;									// ��о���ñ�ľ�����ֵ
	float fTab;

	bool bCheckAnodeRange;
	bool bCheckCathodeRange;
	float AnodeRangeMax;
	float CathodeRangeMax;

	double ToHatMin;
	double ToHatMax;
	float MinDist;	//��������������С���
	float MaxDist;

	int iLackMin;		//��Ƭ�����С��ȱ
	int iLackOffset;	//��Ƭ�����Сƫ����

	//���۳���
	int GunCaoNG;		//������������NG����
	double DepthMax; 
	double DepthMin;
	double HeightMax;
	double HeightMin;

	int iROIleft;	// ԭͼ�еļ������
	int iROItop;
	int iROIright;
	int iROIbottom;

	//�������ڼ��
	bool bCheckPoleToSide;
	double dPoleEarMax;		//�����������ֵ
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

	// �������Ӳ���   20180506
	float fEarToLeftSideMaxThre;			// ���������ھ��������ֵ
	float fEarToRightSideMaxThre;				// �������Ҳ�ھ��������ֵ

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
		detectionPosition = DETECTION_UP_LEFT_RIGHT;// �㷨�����±��±ꡣ�Ƕ��±꣺plcʵ���±꣬ӳ���㷨�����±�
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
		detectionPosition = DETECTION_UP_LEFT_RIGHT;// �㷨�����±��±ꡣ�Ƕ��±꣺plcʵ���±꣬ӳ���㷨�����±�
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
	double dPoleDst;		// ��������

	//β�����
	double dTailOHMax;
	double dTailOHMin;
	double dTailMax;
	double dTailMin;
	double dTailMean;
	double dTailNgDst;
	double dTailPosDst;
	double dTailPoleDst;		// ��������


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


//ģ��PLC�źſ���PC����
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