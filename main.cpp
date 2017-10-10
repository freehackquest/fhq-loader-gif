#include <QApplication>
#include <QString>
#include <QMap>
#include <QDir>
#include <QImage>
#include <QTime>
#include <QFont>
#include <QList>
#include <QPainter>
#include <QVector>
#include <QImage>
#include <QColor>
#include <iostream>
#include <math.h>

int normalizeP(int x, int w){
	x = x - w/2;
	x = x < 0 ? 0 : x;
	x = x + w > 300 ? 300 - w : x;
	return x;
}


int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	
	const QImage imgF(":/images/f.png");
	const QImage imgH(":/images/h.png");
	const QImage imgQ(":/images/q.png");

	int w = 300;
	int h = 300;

	int center_x = w/2;
	int center_y = h/2;

	int F_w = imgF.width();
	int F_h = imgF.height();
	
	int H_w = imgH.width();
	int H_h = imgH.height();
	
	int Q_w = imgQ.width();
	int Q_h = imgQ.height();
	
	int centerF_x = 10 + F_w/2;
	int centerF_y = 10 + F_h/2;
	double F_d = std::sqrt(std::pow(center_x - centerF_x,2) + std::pow(center_y - centerF_y,2));
	
	int centerH_x = 130 + H_w/2;
	int centerH_y = 50 + H_w/2;
	int H_d = std::sqrt(std::pow(center_x - centerH_x,2) + std::pow(center_y - centerH_y,2));
	
	int centerQ_x = 20 + Q_w/2;
	int centerQ_y = 130 + Q_h/2;
	int Q_d = std::sqrt(std::pow(center_x - centerQ_x,2) + std::pow(center_y - centerQ_y,2));
	
	std::cout << "center_x = " << center_x << "\n";
	std::cout << "center_y = " << center_y << "\n";
	std::cout << "centerF_x = " << centerF_x << "\n";
	std::cout << "centerF_y = " << centerF_y << "\n";
	std::cout << "centerH_x = " << centerH_x << "\n";
	std::cout << "centerH_y = " << centerH_y << "\n";
	std::cout << "centerQ_x = " << centerQ_x << "\n";
	std::cout << "centerQ_y = " << centerQ_y << "\n";
	
	std::cout << "F_d = " << F_d << "\n";
	std::cout << "H_d = " << H_d << "\n";
	std::cout << "Q_d = " << Q_d << "\n";
	
	int i = 0;
	float startF_a = 3.9;
	float startH_a = -0.3;
	float startQ_a = 2.2;
	for(float a = 0; a < 6.28; a = a + 6.28/25){
		
		QImage *pImgResult = new QImage(w,h, QImage::Format_ARGB32);
		pImgResult->fill(qRgba(0, 0, 0, 0));
		
		QPainter *pPainter = new QPainter(pImgResult);
		
		int newF_x = center_x + F_d*std::cos(startF_a + a);
		int newF_y = center_y + F_d*std::sin(startF_a + a);
		int newH_x = center_x + H_d*std::cos(startH_a + a);
		int newH_y = center_y + H_d*std::sin(startH_a + a);
		int newQ_x = center_x + Q_d*std::cos(startQ_a + a);
		int newQ_y = center_y + Q_d*std::sin(startQ_a + a);
		
		newF_x = normalizeP(newF_x, F_w);
		newF_y = normalizeP(newF_y, F_h);

		newH_x = normalizeP(newH_x, H_w);
		newH_y = normalizeP(newH_y, H_h);
		
		newQ_x = normalizeP(newQ_x, Q_w);
		newQ_y = normalizeP(newQ_y, Q_h);
		
		pPainter->drawImage(newF_x, newF_y, imgF);
		pPainter->drawImage(newH_x, newH_y, imgH);
		pPainter->drawImage(newQ_x, newQ_y, imgQ);
		
		pImgResult->save("gif/loader_"  + QString::number(i) + ".png");
		i++;
	}

	return 0;
}


