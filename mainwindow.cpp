#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "my_qlabel.h"


MainWindow::MainWindow(QWidgetWindow *parent)  :  ui(new Ui::MainWindow), finding_match(false)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    timer->setInterval(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(TimerTick()));




    this->SetupGame();



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetupGame(){
    srand(time(NULL));
    QList<QString>* animalEmoji = NULL;
    animalEmoji = new QList<QString>(std::initializer_list<QString>
                               {
                                   "🤑","🤑",
                                   "😥","😥",
                                   "😴","😴",
                                   "😤","😤",
                                   "😰","😰",
                                   "😵‍💫","😵‍💫",
                                   "🥶","🥶",
                                   "😂","😂",

                               });

    QString nextEmoji = NULL;
    int index;

    for (auto button : this->findChildren<QPushButton*>())
    {
       button->setVisible(true);
       index = rand() % animalEmoji->count();
       nextEmoji = (*animalEmoji)[index];
       button->setText(nextEmoji);
       animalEmoji->removeAt(index);
       //connect(button, SIGNAL(NULL), this, SLOT(NULL));
       if(matchesFound != 8){
             connect(button, SIGNAL(clicked()), this, SLOT(ButtonClicked()));
       }



       //connect(ui->label, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_Pressed()));


    }




    timer->start();
    tensthsOfSecondsElapsed = 0;
    matchesFound = 0;

    delete animalEmoji;


}


void MainWindow::TimerTick()
{

    tensthsOfSecondsElapsed++;

    ui->label->setText(QString::number(tensthsOfSecondsElapsed/10.0F, 'f', 1));

    if (matchesFound == 8)
    {
        timer->stop();
        ui->label->setText("Your Time is " +
                           QString::number(tensthsOfSecondsElapsed/10.0F, 'f', 1) +
                           " seconds!");
        connect(ui->label, SIGNAL(Mouse_Pressed()), this, SLOT(Mouse_Pressed()));


    }

}
void MainWindow::ButtonClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if(finding_match == false)
    {
        button->setVisible(false);
        lastEmojiClicked = button;
        finding_match = true;

    }
    else if (button->text() == lastEmojiClicked->text()){
        button->setText("✅");
        lastEmojiClicked->setVisible(true);
        lastEmojiClicked->setText("✅");
        finding_match = false;
        matchesFound++;
    }
    else
    {
        lastEmojiClicked->setVisible(true);
        finding_match = false;
    }
}

void MainWindow::Mouse_Pressed()
{
    if (matchesFound == 8)
    {




        finding_match = false;

        timer = new QTimer(this);
        timer->setInterval(100);
        connect(timer, SIGNAL(timeout()), this, SLOT(TimerTick()));

        this->SetupGame();

    }
}
