#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
/*
#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QImage>
#include <QPixmap>
#include <QThread>
#include <QDebug>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}

class VideoPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit VideoPlayer(QWidget* parent = nullptr);
    ~VideoPlayer();

private:
    QLabel* m_videoLabel;
    QTimer* m_timer;
    AVFormatContext* m_formatCtx;
    AVCodecContext* m_codecCtx;
    AVCodec* m_codec;
    AVFrame* m_frame;
    AVFrame* m_rgbFrame;
    SwsContext* m_swsCtx;
    int m_videoStreamIndex;
    int m_videoWidth;
    int m_videoHeight;
    int m_frameRate;

private slots:
    void play();
    void displayVideo();
};

VideoPlayer::VideoPlayer(QWidget* parent)
    : QMainWindow(parent)
{
    m_videoLabel = new QLabel(this);
    setCentralWidget(m_videoLabel);

    m_formatCtx = nullptr;
    m_codecCtx = nullptr;
    m_codec = nullptr;
    m_frame = nullptr;
    m_rgbFrame = nullptr;
    m_swsCtx = nullptr;
    m_videoStreamIndex = -1;
    m_videoWidth = 0;
    m_videoHeight = 0;
    m_frameRate = 0;

    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(displayVideo()));
}

VideoPlayer::~VideoPlayer()
{
    if (m_rgbFrame) av_frame_free(&m_rgbFrame);
    if (m_frame) av_frame_free(&m_frame);
    if (m_codecCtx) avcodec_close(m_codecCtx);
    if (m_formatCtx) avformat_close_input(&m_formatCtx);
}

void VideoPlayer::play()
{
    // Open video file
    if (avformat_open_input(&m_formatCtx, "test.mp4", nullptr, nullptr) != 0) {
        qDebug() << "Failed to open video file";
        return;
    }

    // Retrieve stream information
    if (avformat_find_stream_info(m_formatCtx, nullptr) < 0) {
        qDebug() << "Failed to retrieve stream information";
        return;
    }

    // Find the first video stream
    for (int i = 0; i < m_formatCtx->nb_streams; i++) {
        if (m_formatCtx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            m_videoStreamIndex = i;
            break;
        }
    }

    if (m_videoStreamIndex == -1) {
        qDebug() << "Failed to find video stream";
        return;
    }

    // Get the codec parameters for the video stream
    AVCodecParameters* codecpar = m_formatCtx->streams[m_videoStreamIndex]->codecpar;

    // Find the decoder for the video stream
    m_codec = avcodec_find_decoder(codecpar->codec_id);
    if (!m_codec) {
        qDebug() << "Failed to find video codec";
        return;
    }

    // Allocate a codec context for the decoder
    m_codecCtx = avcodec_alloc_context3(m_codec);
    if (!m_codecCtx) {
        qDebug() << "Failed to allocate video codec context";
        return;
    }

    // Copy codec parameters to codec context
    if (avcodec_parameters_to_context(m_codecCtx, codecpar) < 0) {
        qDebug() << "Failed to copy video codec parameters to codec context";
        return;
    }

    // Open the codec for the video stream
    if (avcodec_open2(m_codecCtx, m_codec, nullptr) < 0) {
        qDebug() << "Failed to open video codec";
        return;
    }

    // Allocate a frame for the decoded video
    m_frame = av_frame_alloc();
    if (!m_frame) {
        qDebug() << "Failed to allocate video frame";
        return;
    }

    // Allocate a frame for the RGB video
    m_rgbFrame = av_frame_alloc();
    if (!m_rgbFrame) {
        qDebug() << "Failed to allocate RGB video frame";
        return;
    }

    // Determine the required buffer size for the RGB frame
    int numBytes = av_image_get_buffer_size(AV_PIX_FMT_RGB24, m_codecCtx->width, m_codecCtx->height, 1);

    // Allocate the buffer for the RGB frame
    uint8_t* buffer = (uint8_t*)av_malloc(numBytes * sizeof(uint8_t));
    if (!buffer) {
        qDebug() << "Failed to allocate RGB video buffer";
        return;
    }

    // Assign the buffer to the RGB frame
    av_image_fill_arrays(m_rgbFrame->data, m_rgbFrame->linesize, buffer, AV_PIX_FMT_RGB24, m_codecCtx->width, m_codecCtx->height, 1);

    // Initialize the SWS context for RGB conversion
    m_swsCtx = sws_getContext(m_codecCtx->width, m_codecCtx->height, m_codecCtx->pix_fmt, m_codecCtx->width, m_codecCtx->height, AV_PIX_FMT_RGB24, SWS_BILINEAR, nullptr, nullptr, nullptr);
    if (!m_swsCtx) {
        qDebug() << "Failed to initialize SWS context";
        return;
    }

    // Get the video width, height, and frame rate
    m_videoWidth = m_codecCtx->width;
    m_videoHeight = m_codecCtx->height;
    m_frameRate = av_q2d(m_formatCtx->streams[m_videoStreamIndex]->avg_frame_rate);

    // Start the timer to display video frames
    m_timer->start(1000 / m_frameRate);
}

void VideoPlayer::displayVideo()
{
    // Read a packet from the video stream
    AVPacket packet;
    av_init_packet(&packet);
    packet.data = nullptr;
    packet.size = 0;

    if (av_read_frame(m_formatCtx, &packet) < 0) {
        qDebug() << "Failed to read video packet";
        return;
    }

    if (packet.stream_index != m_videoStreamIndex) {
        av_packet_unref(&packet);
        return;
    }

    // Decode the video packet into a frame
    int ret = avcodec_send_packet(m_codecCtx, &packet);
    if (ret < 0) {
        qDebug() << "Failed to send video packet for decoding";
        av_packet_unref(&packet);
        return;
    }

    while (ret >= 0) {
        ret = avcodec_receive_frame(m_codecCtx, m_frame);
        if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF) {
            break;
        }
        else if (ret < 0) {
            qDebug() << "Failed to receive video frame";
            av_packet_unref(&packet);
            return;
        }

        // Convert the frame to RGB format
        sws_scale(m_swsCtx, m_frame->data, m_frame->linesize, 0, m_codecCtx->height, m_rgbFrame->data, m_rgbFrame->linesize);

        // Create a QImage from the RGB frame
        QImage image(m_rgbFrame->data[0], m_videoWidth, m_videoHeight, QImage::Format_RGB888);

        // Create a QPixmap from the QImage
        QPixmap pixmap = QPixmap::fromImage(image);

        // Display the QPixmap in the QLabel
        m_videoLabel->setPixmap(pixmap);
    }

    av_packet_unref(&packet);
}

int main(int argc, char* argv[])
{
    av_register_all();
    avformat_network_init();

    QApplication a(argc, argv);
    VideoPlayer w;
    w.play();
    w.show();
    return a.exec();
}
*/




//#include <afxmt.h>


//全局变量
//volatile int signalNum = 0;   //①


/*
通过互斥量实现线程间的同步，初始化为没有加锁的状态
*/
//HANDLE mutex = CreateMutex(NULL, FALSE, NULL);  //②：C和D为互斥量进行线程之间的通信


/*
使用信号量
参数2:当前可用的信号的量个数 范围为(0 - 参数3)
参数3:信号量的最大值
*/
//HANDLE signalSemaphore = CreateSemaphore(NULL, 1, 1, NULL);


//通过事件进行通信
/*创建事件CreateEvent
LPSECURITY_ATTRIBUTESlpEventAttributes,// 安全属性
BOOLbManualReset,// 复位方式,如果是TRUE，那么必须用ResetEvent函数来复原到无信号状态。FALSE自动将事件状态复原为无信号状态。
BOOLbInitialState,// 初始状态,TRUE有信号,FALESE无信号
LPCTSTRlpName // 对象名称
*/
//HANDLE ThreadEvent = CreateEvent(NULL, TRUE, FALSE, NULL);



/*
使用临界区   MFC中的通信方式
*/
//CCriticalSection cs;