#pragma once
#include "MainFrm.h"
class MySphere
{
private:
	int radius;
	int cx;
	int cy;
public:
	MySphere();
	MySphere(int cx,int cy, int radius);
	int GetRadius() const;
	CPoint GetPosition() const;

	void SetRadius(int radius);
	void SetPosition(int cx, int cy);
	void Draw(CDC* pDC);
	virtual ~MySphere();


};

