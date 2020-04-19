#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

char* changename(const char* colortitle)
{
  char* str = new char[100];
  char* dot;
  sprintf(str,"%s",colortitle);
  dot = strstr(str,".png");
  strcpy (dot,"bw.png");
  return str;
}


int main( int argc, char** argv )
{
	//transforma uma imagem colorida pelo celular em preto e branco, salvando em um novo arquivo.
    Mat image;
    Mat grayImage;
    
    char* imageName;
    
   for(int i=1;i<argc;i++)
  {
	imageName = changename(argv[i]);  
    image = imread(argv[i], CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout << "Could not open or find the image" << std::endl ;
        return -1;
	}
	
    else {
        int height = image.rows;
        int width = image.cols;

        cvtColor(image, grayImage, CV_BGR2GRAY);

		imwrite( imageName , grayImage );
		std::cout <<"Processando imagem "<< imageName << endl; 
		
		}
		
	}
	return 0;
}
