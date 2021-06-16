void voronoi_simple(cv::Mat image, std::vector<std::vector<int>> centroids, int distanceMeasure) {
    for (int row = 0; row < image.rows; row++) {
        for (int col = 0; col < image.cols; col++) {
            double smallestDistance = -1.0;
            int color[3] = {0, 0, 0};

            for (auto centroid : centroids) {
                double distance;

                if (distanceMeasure == 1) {
                    distance = euclidean_distance(centroid[0], centroid[1], row, col);
                } else if (distanceMeasure == 2) {
                    distance = manhattan_distance(centroid[0], centroid[1], row, col);
                }

                if (row == centroid[0] && col == centroid[1]) {
                    color[0] = 0;
                    color[1] = 0;
                    color[2] = 0;

                    break;
                } else if ((smallestDistance == -1 || distance < smallestDistance)) {
                    color[0] = centroid[2];
                    color[1] = centroid[3];
                    color[2] = centroid[4];

                    smallestDistance = distance;
                }
            }

            image.at<cv::Vec3b>(row, col) = cv::Vec3b(color[2], color[1], color[0]);
        }
    }
}