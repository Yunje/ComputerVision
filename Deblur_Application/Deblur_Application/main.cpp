#include <atlstr.h>
#include <iostream>
#include "MatCalc.hpp"
#include "deconv.hpp"

using namespace std;

int main()
{
	Mat blurredimg = imread("C:\\Users\\yunje\\Documents\\MATLAB\\deblur_practice\\blurred.bmp");
	Mat psf = ( Mat_<float>(5, 5) <<
		0.0005f, 0.0050f, 0.0109f, 0.0050f, 0.0005f,
		0.0050f, 0.0522f, 0.1141f, 0.0522f, 0.0050f,
		0.0109f, 0.1141f, 0.2491f, 0.1141f, 0.0109f,
		0.0050f, 0.0522f, 0.1141f, 0.0522f, 0.0050f,
		0.0005f, 0.0050f, 0.0109f, 0.0050f, 0.0005f );
	
	/*cout << "m1=" << psf << endl;*/
	Mat f_psf;
	deconv::Dft2D(psf, &f_psf);
	Mat psf_back;
	deconv::InvDft2D(f_psf, &psf_back);
	Mat psf_rearrange;
	deconv::RearrangeAfterFilter(psf_back, &psf_rearrange, 5);
	cout << psf_back << endl;
	cout << psf_rearrange << endl;
	imshow("result", psf_back);

	Mat deblurred;
	imwrite("C:\\Users\\yunje\\Documents\\MATLAB\\deblur_practice\\psf_back.bmp", 255*psf_back);
	//waitKey(0);
	return 0;
}
