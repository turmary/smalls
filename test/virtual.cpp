#include <iostream>
#include <stdio.h>
#include <windows.h>

class CPoint {
public:
	int x, y;
	CPoint(int x = 100, int y = 100);
	virtual int GetX(void);
	virtual int GetY(void);
	virtual void SetX(int x);
	virtual void SetY(int y);
};

CPoint::CPoint(int x, int y) {
	printf("CPoint::CPoint(%d, %d)\n", x, y);
	this->x = x;
	this->y = y;
}

int CPoint::GetX(void) {
	printf("Point.GetX\n");
	return x;
}

int CPoint::GetY(void) {
	printf("Point.GetY\n");
	return y;
}

void CPoint::SetX(int x) {
	printf("Point.SetX\n");
	this->x = x;
}

void CPoint::SetY(int y) {
	printf("Point.SetY\n");
	this->y = y;
}

class CColorPoint: public CPoint {
public:
	int r, g, b;
	CPoint pt;
	CColorPoint();
	virtual int GetX(void);
	virtual int GetY(void);
	virtual void SetX(int x);
	virtual void SetY(int y);
};

CColorPoint::CColorPoint(): CPoint(0, 10), pt(20, 30) {
	printf("CColorPoint::CColorPoint()\n");
}

int CColorPoint::GetX(void) {
	printf("ColorPoint.GetX\n");
	return x;
}

int CColorPoint::GetY(void) {
	printf("ColorPoint.GetY\n");
	return y;
}

void CColorPoint::SetX(int x) {
	printf("ColorPoint.SetX\n");
	this->x = x;
}

void CColorPoint::SetY(int y) {
	printf("ColorPoint.SetY\n");
	this->y = y;
}

int (CPoint::* pfnGet)(void);


int main() {
	printf("Hello World!\n");

	CPoint pt(100, 90);
	CColorPoint cpt;

	CPoint* ppt;

	pt.x = 5;
	pt.y = 5;
	pfnGet = pt.GetX;
	printf("&X=%08X &Y=%08X\n", &pt.x, &pt.y);
	printf("&Point.GetX=%08X\n", pfnGet);
	pt.GetX();

	ppt = &pt;
	ppt->GetX();
	ppt->GetY();
	ppt->SetX(2);
	ppt->SetY(2);

	printf("&ColorPoint.GetX=%08X\n", cpt.GetX);
	cpt.GetX();

	ppt = &cpt;
	ppt->GetX();
	ppt->GetY();
	ppt->SetX(2);
	ppt->SetY(2);

	WriteProfileString("SectionVirtual", "Item", "ItemValue");
	char strItemVal[50];
	GetProfileString("SectionVirtual", "Item", "NULL", strItemVal, 50);
	printf("[SectionVirtual].Item=%s", strItemVal);
	return 0;
}

