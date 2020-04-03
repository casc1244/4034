
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;



int main()
{

	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("D:\\360downloads\\7.png", 1);

	const cv::Point2f pts1[] = {
		cv::Point2f(150,150),
		cv::Point2f(150,300),
		cv::Point2f(3500,300),
		cv::Point2f(350,150),
	};
	const cv::Point2f pts2[] = {
		cv::Point2f(200,150),
		cv::Point2f(200,300),
		cv::Point2f(340,270),
		cv::Point2f(340,180),
	};//透视变换行列
	cv::Mat perspective_matrix = cv::getPerspectiveTransform(pts1, pts2);
	cv::warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());
	imshow("原", srcMat);
	imshow("换", dstMat);


	// 等待用户按任意按键退出程序
	waitKey(0);

	return 0;
}
