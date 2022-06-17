#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

   ui->setupUi(this);

   ui->comboBox->addItem(QIcon(":/united_kingdom_flag.png"), "English", QVariant("en")); // добавляем элементы в выпадающий список вместе с данными пользователя
   ui->comboBox->addItem(QIcon(":/russia_flag.png"), "Русский", QVariant("ru"));
   ui->comboBox->addItem(QIcon(":/germany_flag.png"), "Deutsch", QVariant("de"));
   ui->comboBox->addItem(QIcon(":/Flag_of_Tatarstan.svg.png"), "Татар", QVariant("tt"));
   ui->comboBox->addItem(QIcon(":/china_flag.png"), "中文", QVariant("zh"));

    connect(ui->comboBox, static_cast<void (QComboBox::*)(const QString &)>(&QComboBox::currentIndexChanged),
            [this](const QString &str) {

        auto lang = ui->comboBox->itemData(ui->comboBox->currentIndex(), Qt::UserRole).toString();
//        qDebug() << lang.toString();

        qtLanguageTranslator.load(":/helloUser_" + lang);   // Загружаем перевод
       // qtLanguageTranslator.load("helloUser_" + str,  QApplication::applicationDirPath() );   // Загружаем перевод

        qApp->installTranslator(&qtLanguageTranslator);        // Устанавливаем перевод в приложение
    }); // соединяем сигнал со слотом (лямбда-функция)

    this->updateTime(); // устанавливаем время и английский язык по умолчанию


}

void MainWindow::changeEvent(QEvent *event)
{
    // В случае получения события изменения языка приложения
    if (event->type() == QEvent::LanguageChange) {
        this->updateTime();
    }
}

void MainWindow::updateTime()
{
    this->setWindowTitle(tr("Hello"));
    ui->labelLang->setText(tr("Select language:"));

    QTime time = QTime::currentTime(); // получение даты по системным часам в местном часовом поясе
    ui->labelDate->setText(tr("Time: ") + time.toString("hh:mm")); // извлечение часов из даты

    // Для переводов используется Qt Linquist

    int hour = time.hour();

    if (hour >= 5 && hour < 12)
    {
       ui->labelHello->setText(tr("Good Morning!")); // базовый язык в приложении - Английский
    }
    else if (hour >= 12 && hour < 18)
    {
       ui->labelHello->setText(tr("Good Day!"));
    }
    else if (hour >= 18 && hour < 23)
    {
       ui->labelHello->setText(tr("Good Evening!"));
    }
    else
    {
       ui->labelHello->setText(tr("Good Night!"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

