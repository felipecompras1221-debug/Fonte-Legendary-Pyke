#pragma once

class CLayout
{
public:
    CLayout();

    // Atualiza o estado do painel (toggle F4 e drag and drop)
    void UpdateLayoutPanelWindow();

    int DrawToolTip(int X, int Y, LPCSTR Text, ...);

    // Desenha o painel flutuante na posição atual
    void DrawLayoutPanelWindow();
};

extern CLayout gLayout;
