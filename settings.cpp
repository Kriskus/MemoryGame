#include "labelbutton.h"
#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    LabelButton* buttonDisney = new LabelButton("0", ":/disney/graphics/disney/16.jpg");
    LabelButton* buttonFrozen = new LabelButton("1", ":/frozen/graphics/frozen/Zrzut ekranu 2023-08-05 094058.png");
    LabelButton* buttonPony = new LabelButton("2", ":/pony/graphics/pony/Zrzut ekranu 2023-08-05 092249.png");
    LabelButton* buttonPawPatrol = new LabelButton("3", ":/pawpatrol/graphics/pawpatrol/sky.png");
    LabelButton* buttonAnimal = new LabelButton("4", ":/animal/graphics/animal/2.png");

    ui->gridLayout->addWidget(buttonDisney, 0, 0);
    ui->gridLayout->addWidget(buttonFrozen, 0, 1);
    ui->gridLayout->addWidget(buttonPony, 0, 2);
    ui->gridLayout->addWidget(buttonPawPatrol, 1, 0);
    ui->gridLayout->addWidget(buttonAnimal, 1, 2);

    connect(buttonDisney, &LabelButton::clicked, this, &Settings::setGraphics);
    connect(buttonFrozen, &LabelButton::clicked, this, &Settings::setGraphics);
    connect(buttonPony, &LabelButton::clicked, this, &Settings::setGraphics);
    connect(buttonPawPatrol, &LabelButton::clicked, this, &Settings::setGraphics);
    connect(buttonAnimal, &LabelButton::clicked, this, &Settings::setGraphics);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);
    emit closeWindow();
}

void Settings::setGraphics(int type)
{
    emit graphicsType(type);
    emit closeWindow();
}
