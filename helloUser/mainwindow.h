#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDateTime>
#include <QDebug>
#include <QTranslator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    // Метод получения событий в главном окне приложения
    // В нём будет производиться проверка события смены перевода приложения
    void changeEvent(QEvent * event) override;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void updateTime();

private:
    Ui::MainWindow *ui;

    QTranslator qtLanguageTranslator;


};
#endif // MAINWINDOW_H
