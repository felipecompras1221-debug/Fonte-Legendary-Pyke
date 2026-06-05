struct eColor {
	BYTE red;
	BYTE grn;
	BYTE blu;
	BYTE opl;
};

class eCustomFont
{
public:
	eCustomFont();
	~eCustomFont();
	void load();
	void Draw(HFONT font, int PosX, int PosY, DWORD color, DWORD bkcolor, int Width, int Height, BYTE Align, LPCTSTR Text, ...);
	void DrawMultipleColor(HFONT font, int PosX, int PosY, DWORD bkcolor, int Width, int Height, BYTE Align, LPCTSTR Text, ...);
	eColor	SinWaveColor(float frc1, float frc2, float frc3, BYTE phs1, BYTE phs2, BYTE phs3, BYTE center, BYTE width, BYTE step);

	HFONT	FontNormal;
	HFONT	FontBold10;
	HFONT	FontBold11;
	HFONT	FontBold12;
	HFONT	FontBold;
	HFONT	FontBold14;
	HFONT	FontBold15;
	HFONT	FontBold16;
	HFONT	FontBold17;
	HFONT	FontBold18;
	HFONT	FontBold19;
	HFONT	FontBold20;

	HFONT	FontSize10;
	HFONT	FontSize11;
	HFONT	FontSize12;
	HFONT	FontSize13;
	HFONT	FontSize14;
	HFONT	FontSize15;
	HFONT	FontSize16;
	HFONT	FontSize17;
	HFONT	FontSize18;
	HFONT	FontSize19;
	HFONT	FontSize20;
};

extern eCustomFont CustomFont;