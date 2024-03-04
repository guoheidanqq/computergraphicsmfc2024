#include "pch.h"
#include "MySphere.h"

MySphere::MySphere()
{
	this->radius = 5;
	this->cx = 5;
	this->cy = 5;
}

MySphere::MySphere( int cx, int cy, int radius)
{
	this->radius = radius;
	this->cx = cx;
	this->cy = cy;
}

int MySphere::GetRadius() const
{

	return this->radius;
}

CPoint MySphere::GetPosition() const
{
	return CPoint(this->cx,this->cy);
}

void MySphere::SetRadius(int radius)
{
	this->radius = radius;
}

void MySphere::SetPosition(int cx, int cy)
{
	this->cx = cx;
	this->cy = cy;
}

void MySphere::Draw(CDC * pDC)
{
	int cx = this->cx;
	int cy = this->cy;
	int r = this->radius;	
	CPoint p0(cx - r, cy - r);
	CPoint p1(cx + r, cy + r);
	pDC->Ellipse(CRect(p0, p1));


}

MySphere::~MySphere()
{
}
