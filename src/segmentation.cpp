#include <opencv2/opencv.hpp>
#include "segmentation.h"

cv::Mat segmentLungs(const cv::Mat& ct) {
    cv::Mat mask, opened;
    // 1. Threshold: everything below intensity 100 → lung region (white)
    cv::threshold(ct, mask, 100, 255, cv::THRESH_BINARY_INV);
    // 2. Morphological opening to remove small noise
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, {5, 5});
    cv::morphologyEx(mask, opened, cv::MORPH_OPEN, kernel);
    return opened;
}
