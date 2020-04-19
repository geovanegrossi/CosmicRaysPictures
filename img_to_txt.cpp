#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <fstream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
	//transforma uma imagens preto e branco em uma matrix para leitura no root
	ofstream myfile;
	int total_frames = 42442;	//número total de frames produzidos com o ffmpeg
	int image_array[1920][1080]; //resolução da camera
	Mat newimage;
    Mat image;
    int aux = 0;
    char bwfile[100];
    char imageName[100];
    int intensity, height, width;
    int pic = 1;
	int sum_x_images = 5; //vamos somar a intensidade de 5 frames
	int newframes = (int)total_frames / sum_x_images; //
		for(int k = 0; k<newframes; k++)
		{
		    sprintf(imageName,"/image_to_txt/%d.txt", k);  
			myfile.open (imageName);	
			while(aux<sum_x_images)
				{
				sprintf(bwfile,"/bwframes/%03dbw.png",pic);  
				image = imread(bwfile, IMREAD_GRAYSCALE);   // Read the file

					height = image.rows;
					width = image.cols;
										
					for(int i = 0; i < height; i++)
						{
						for(int j = 0; j < width; j++)
							{
								intensity = (int)image.at<uchar>(i,j);
								image_array[i][j] = image_array[i][j] + intensity;			
							}
						}	
				aux++;
				pic++;
				}
					for(int i = 0; i < height; i++)
						{
						for(int j = 0; j < width; j++)
							{
							
								image.at<uchar>(i,j) = image_array[i][j];
								if(image_array[i][j]!=0)myfile <<i<<" "<<j<<" "<<image_array[i][j]<<endl;
								image_array[i][j] = 0;									
							}
						}			
			aux=0;
			cout << "\r" <<k+1 <<"/"<<newframes<< " imagens completas."<< flush;
			myfile.close();
		}
	return 0;
}
