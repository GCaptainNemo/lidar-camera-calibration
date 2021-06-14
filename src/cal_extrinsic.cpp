#include "../include/cal_calibration.h"
#include <vector>

void cal_calib() 
{
	double dist[5] = { -0.1942, 0.0140, -5.358e-4, 0.0016, 0.
	    };
	cv::Mat dist_array(5, 1, CV_64F, dist);
	double Intrinsic[3][3] = { 
		1915.49, 1.311865401806629, 977.23, 
		0., 1925.84, 538.86, 
		0.,  0.,  1.};
	cv::Mat Int(3, 3, CV_64F, Intrinsic);

	std::vector <cv::Point3f> vec_3d;
	cv::Mat mat_3d;
	vec_3d.clear();
	vec_3d.push_back(cv::Point3f(3040, 108, 401));
	vec_3d.push_back(cv::Point3f(2878, 119, -23));
	vec_3d.push_back(cv::Point3f(2907, -286, -11));
	vec_3d.push_back(cv::Point3f(3064, -292, 398));
	cv::Mat(vec_3d).convertTo(mat_3d, CV_32F);

	// /////////////////////////////////////////////////
	// vec img
	// /////////////////////////////////////////////////
	std::vector <cv::Point2f> vec_2d;
	cv::Mat mat_2d;
	vec_2d.clear();
	vec_2d.push_back(cv::Point2f(887, 279));
	vec_2d.push_back(cv::Point2f(882, 571));
	vec_2d.push_back(cv::Point2f(1168, 569));
	vec_2d.push_back(cv::Point2f(1156, 288));
	cv::Mat(vec_2d).convertTo(mat_2d, CV_32F);

	cv::Mat rvec;
	cv::Mat tvec;
	cv::solvePnP(mat_3d, mat_2d, Int, dist_array, rvec, tvec);
	cv::Mat rotM;
	Rodrigues(rvec, rotM);
	std::cout << "rvec = " << rvec << std::endl;
	std::cout << "tvec = " << tvec << std::endl;
	std::cout << "rotM = " << rotM << std::endl;

};