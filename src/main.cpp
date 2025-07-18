#include <opencv2/opencv.hpp>
#include "segmentation.h"

int main() {
    // 1. Load healthy reference and patient CT slice (grayscale)
    cv::Mat healthy = cv::imread("data/ct_slice_healthy.png", cv::IMREAD_GRAYSCALE);
    cv::Mat patient = cv::imread("data/ct_slice_patient.png", cv::IMREAD_GRAYSCALE);
    if (healthy.empty() || patient.empty()) {
        std::cerr << "Failed to load images.\n";
        return -1;
    }

    // 2. Resize patient slice to match reference dimensions
    cv::resize(patient, patient, healthy.size());

    // 3. Segment the patient lungs
    cv::Mat patient_mask = segmentLungs(patient);

    // 4. Superimpose (blend) healthy and patient slices
    cv::Mat blended;
    cv::addWeighted(healthy, 0.5, patient, 0.5, 0.0, blended);

    // 5. Save outputs
    cv::imwrite("results/patient_mask.png", patient_mask);
    cv::imwrite("results/superimposed.png", blended);
    return 0;
}
