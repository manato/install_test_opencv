/* カメラから画像を取得するテストプログラム */
/* 引用元
   http://www.crystal-creation.com/software/technical-information/library/opencv/camera/
 */
/* 引用限その2(解像度変更について)
   http://chihara.naist.jp/opencv/?%B2%E8%C1%FC%A4%CE%A5%EA%A5%B5%A5%A4%A5%BA
 */

#include <stdio.h>
#include <highgui.h>
#include <cv.h>




main()
{
#if 1
    /* カメラからのビデオキャプチャを初期化 */
  CvCapture *videoCapture = cvCreateCameraCapture(0);
//    CvCapture *videoCapture = cvCreateCameraCapture(-1);
    if(videoCapture == NULL)
    {
        printf("no camera detected.\n");
	printf("the problem is detected\n");
        return -1;
    }
#endif
    /* ウィンドウを作成 */
    char windowName[] = "image from camera";
    cvNamedWindow(windowName, CV_WINDOW_AUTOSIZE);

    /* ウィンドウを作成(リサイズ後) */
    char windowName_resized[] = "resized image";
    cvNamedWindow(windowName_resized, CV_WINDOW_AUTOSIZE);


    /* 何かキーが押されるまでループを繰り返す */
//    while( cvWaitKey(1) == -1 )  /* cvWaitKeyの待ち時間が1(ミリ秒)だと短すぎてうまく行かない模様 */
    while( cvWaitKey(2) == -1 ) /* 2ミリ秒あればOKな模様 */
    {

#if 0
    /* カメラからのビデオキャプチャを初期化 */
    CvCapture *videoCapture = cvCreateCameraCapture(0);
//    CvCapture *videoCapture = cvCreateCameraCapture(-1);

    if(videoCapture == NULL)
    {
        printf("no camera detected.\n");
        return -1;
    }
#endif

        /* カメラから取得する画像 */
        IplImage *image = cvQueryFrame(videoCapture);

        /* リサイズ後の画像 */
        IplImage *resized_image = cvCreateImage(cvSize(640, 480), IPL_DEPTH_8U, 3);

        /* リサイズ */
        cvResize(image, resized_image, CV_INTER_CUBIC);

        /* ウィンドウに画像を表示する(カメラからのオリジナル画像) */
        cvShowImage(windowName, image);

        /* ウィンドウに画像を表示する(リサイズ後の画像) */
        cvShowImage(windowName_resized, resized_image);

#if 0
        /* ビデオキャプチャを解放 */
        cvReleaseCapture(&videoCapture);
#endif


    }

#if 1
    /* ビデオキャプチャを解放 */
    cvReleaseCapture(&videoCapture);
#endif
    /* ウィンドウを破棄する */
    cvDestroyWindow(windowName);
    cvDestroyWindow(windowName_resized);

    return 0;
}
