#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <obs.h>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Obs *getObs() const;

private slots:
    void on_confirmButton_clicked();

    void on_input_textChanged();

    void on_belegen_clicked();

    void on_input_textChanged(const QString &arg1);

    void on_anzeigen_clicked();

private:
    Ui::MainWindow *ui;
    Obs* obs;
    QSharedPointer<Student> stud;
};

#endif // MAINWINDOW_H
