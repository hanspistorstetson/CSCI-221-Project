#include <zbar.h>
#include <iostream>
using namespace cv;
using namespace std;
using namespace zbar;

int main(int argc, char* argv[])
{
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cout << "Failed to open video source 0!" << endl;
        return -1;
    }

    ImageScanner scanner;
    scanner.set_config(ZBAR_NONE, ZBAR_CFG_ENABLE, 1);
    double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    cout << "Frame size : " << dWidth << " x " << dHeight << endl;
    namedWindow("BHDT QR Test",CV_WINDOW_AUTOSIZE);
    while (1)
    {
        Mat frame;
        bool read = cap.read(frame);
        if (!read) {
            cout << "Cannot read a frame from video stream" << endl;
            break;
        }
        Mat grey;
        cvtColor(frame,grey,CV_BGR2GRAY);
        int width = frame.cols;
        int height = frame.rows;
        uchar *raw = (uchar *)grey.data;
        Image image(width, height, "Y800", raw, width * height);
        int n = scanner.scan(image);
        for(Image::SymbolIterator symbol = image.symbol_begin(); symbol != image.symbol_end(); ++symbol) {
            vector<Point> vp;
            //print results for now
            cout << "Decoded " << symbol->get_type_name() << ". Data: " << symbol->get_data() << endl;
            int n = symbol->get_location_size();
            for(int i=0;i<n;i++) {
                vp.push_back(Point(symbol->get_location_x(i),symbol->get_location_y(i)));
            }
            RotatedRect r = minAreaRect(vp);
            Point2f pts[4];
            r.points(pts);
            for(int i=0;i<4;i++){
                line(frame,pts[i],pts[(i+1)%4],Scalar(255,0,0),3);
            }
        }
        imshow("BHDT QR Test", frame);
        if (waitKey(30) == 27) {
            cout << "Esc pressed. exiting..." << endl;
            break;
        }
    }
    return 0;
}
