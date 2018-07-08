﻿#include "SkinBoxWidget.h"
#include <QStackedLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QSpacerItem>

SkinBoxWidget::SkinBoxWidget(QWidget *parent)
    : BesShadowWidget(parent)
{
    initLayout();
    connectAll();
}

SkinBoxWidget::~SkinBoxWidget()
{

}

void SkinBoxWidget::initLayout()
{
    frontLayer = new QWidget(this);
    mainLayer = new QWidget(this);

    btnCheckMark = new QPushButton(frontLayer); //具体位置交由paintEvent绘制

    QWidget* themeContainer = new QWidget(mainLayer);
    QWidget* pureColorContainer = new QWidget(mainLayer);

    btnTheme = new QPushButton(mainLayer);
    btnPureColor = new QPushButton(mainLayer);
    btnTheme->setText(tr("主题"));
    btnPureColor->setText(tr("纯色"));

    QHBoxLayout* layoutButtons = new QHBoxLayout();
    layoutButtons->addWidget(btnTheme);
    layoutButtons->addWidget(btnPureColor);
    layoutButtons->addSpacerItem(new QSpacerItem(20,25,
                              QSizePolicy::MinimumExpanding, QSizePolicy::Fixed));
    //
    btnBlack = new ButtonTheme(themeContainer, new QImage(":/resource/image/酷炫黑.png"),tr("酷炫黑"));
    btnRed = new ButtonTheme(themeContainer, new QImage(":/resource/image/官方红.png"),tr("官方红"));
    btnPink = new ButtonTheme(themeContainer, new QImage(":/resource/image/可爱粉.png"),tr("可爱粉"));
    btnBlue = new ButtonTheme(themeContainer, new QImage(":/resource/image/天际蓝.png"),tr("天际蓝"));
    btnGreen = new ButtonTheme(themeContainer, new QImage(":/resource/image/清新绿.png"),tr("清新绿"));
    btnGold = new ButtonTheme(themeContainer, new QImage(":/resource/image/土豪金.png"),tr("土豪金"));

    btnBlack->setMinimumSize(116,116);
    btnRed->setMinimumSize(116,116);
    btnPink->setMinimumSize(116,116);
    btnBlue->setMinimumSize(116,116);
    btnGreen->setMinimumSize(116,116);
    btnGold->setMinimumSize(116,116);
    btnBlack->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnRed->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnPink->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnBlue->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnGreen->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnGold->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QGridLayout* themeGridLayout = new QGridLayout();
    themeGridLayout->addWidget(btnBlack,0,0);
    themeGridLayout->addWidget(btnRed,0,1);
    themeGridLayout->addWidget(btnPink,0,2);
    themeGridLayout->addWidget(btnBlue,1,0);
    themeGridLayout->addWidget(btnGreen,1,1);
    themeGridLayout->addWidget(btnGold,1,2);

    themeContainer->setLayout(themeGridLayout);                 //主题页面

    //12种预选纯色
    btnPureColor1 = new QPushButton(pureColorContainer);
    btnPureColor2 = new QPushButton(pureColorContainer);
    btnPureColor3 = new QPushButton(pureColorContainer);
    btnPureColor4 = new QPushButton(pureColorContainer);
    btnPureColor5 = new QPushButton(pureColorContainer);
    btnPureColor6 = new QPushButton(pureColorContainer);
    btnPureColor7 = new QPushButton(pureColorContainer);
    btnPureColor8 = new QPushButton(pureColorContainer);
    btnPureColor9 = new QPushButton(pureColorContainer);
    btnPureColor10 = new QPushButton(pureColorContainer);
    btnPureColor11 = new QPushButton(pureColorContainer);
    btnPureColor12 = new QPushButton(pureColorContainer);

    btnPureColor1->setMinimumSize(55,55);
    btnPureColor2->setMinimumSize(55,55);
    btnPureColor3->setMinimumSize(55,55);
    btnPureColor4->setMinimumSize(55,55);
    btnPureColor5->setMinimumSize(55,55);
    btnPureColor6->setMinimumSize(55,55);
    btnPureColor7->setMinimumSize(55,55);
    btnPureColor8->setMinimumSize(55,55);
    btnPureColor9->setMinimumSize(55,55);
    btnPureColor10->setMinimumSize(55,55);
    btnPureColor11->setMinimumSize(55,55);
    btnPureColor12->setMinimumSize(55,55);
    btnPureColor1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnPureColor2->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnPureColor3->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnPureColor4->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnPureColor5->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnPureColor6->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnPureColor7->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnPureColor8->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnPureColor9->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnPureColor10->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnPureColor11->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    btnPureColor12->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QGridLayout* pureColorGridLayout = new QGridLayout();
    pureColorGridLayout->addWidget(btnPureColor1,0,0);
    pureColorGridLayout->addWidget(btnPureColor2,0,1);
    pureColorGridLayout->addWidget(btnPureColor3,0,2);
    pureColorGridLayout->addWidget(btnPureColor4,0,3);
    pureColorGridLayout->addWidget(btnPureColor5,0,4);
    pureColorGridLayout->addWidget(btnPureColor6,0,5);
    pureColorGridLayout->addWidget(btnPureColor7,1,0);
    pureColorGridLayout->addWidget(btnPureColor8,1,1);
    pureColorGridLayout->addWidget(btnPureColor9,1,2);
    pureColorGridLayout->addWidget(btnPureColor10,1,3);
    pureColorGridLayout->addWidget(btnPureColor11,1,4);
    pureColorGridLayout->addWidget(btnPureColor12,1,5);

    labelCustomizeColor = new QLabel(pureColorContainer);
    btnCustomizeColor=  new QPushButton(pureColorContainer);
    SliderColor=  new QSlider(pureColorContainer);
    SliderBrightness=  new QSlider(pureColorContainer);

    labelCustomizeColor->setText(tr("自定义颜色"));
    btnCustomizeColor->setMinimumSize(55,55);
    btnCustomizeColor->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    SliderColor->setOrientation(Qt::Horizontal);
    SliderBrightness->setOrientation(Qt::Horizontal);
    SliderColor->setMinimumHeight(25);
    SliderBrightness->setMinimumHeight(25);
    SliderColor->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    SliderBrightness->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
    QVBoxLayout * vSliderLayout = new QVBoxLayout();
    vSliderLayout->addWidget(SliderColor);
    vSliderLayout->addWidget(SliderBrightness);

    QHBoxLayout * hCustomizeColorLayout = new QHBoxLayout();
    hCustomizeColorLayout->addWidget(btnCustomizeColor);
    hCustomizeColorLayout->addLayout(vSliderLayout);

    QVBoxLayout * vPureColorLayout = new QVBoxLayout();     //纯色页面整体布局
    vPureColorLayout->addLayout(pureColorGridLayout);
    vPureColorLayout->addSpacerItem(new QSpacerItem(20,30, QSizePolicy::Fixed,QSizePolicy::Fixed));
    vPureColorLayout->addWidget(labelCustomizeColor);
    vPureColorLayout->addLayout(hCustomizeColorLayout);

    pureColorContainer->setLayout(vPureColorLayout);                 //纯色页面

    QStackedLayout* skinStack = new QStackedLayout();
    skinStack->setStackingMode(QStackedLayout::StackOne);
    skinStack->addWidget(themeContainer);
    skinStack->addWidget(pureColorContainer);
    skinStack->setCurrentIndex(0);

    QVBoxLayout* vMainLayout = new QVBoxLayout(mainLayer);
    vMainLayout->addLayout(layoutButtons);
    vMainLayout->addLayout(skinStack);

    QStackedLayout* mainStack = new QStackedLayout(this);
    mainStack->setStackingMode(QStackedLayout::StackAll);
    mainStack->addWidget(mainLayer);
    mainStack->addWidget(frontLayer);
    mainStack->setCurrentIndex(0);
}

void SkinBoxWidget::connectAll()
{

}