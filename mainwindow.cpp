#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <obs.h>
#include <student.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), obs(new Obs) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

Obs *MainWindow::getObs() const { return obs; }

void MainWindow::on_confirmButton_clicked() {

  auto id = ui->input->text();
  auto student = dynamic_cast<Student *>(obs->findeBenutzer(id));
  if (student != nullptr){
    stud = QSharedPointer<Student>(student);
      ui->output->setText(QString("Student with id " + id + " found"));
  }
  ui->input->clear();
}

void MainWindow::on_input_textChanged() {}

void MainWindow::on_belegen_clicked() {
  if(ui->input->text()!=QString("") and stud!=nullptr){
      ui->output->setText(stud->belegen(ui->input->text()));
      ui->input->text().clear();
  }
}

void MainWindow::on_input_textChanged(const QString &arg1) {}

void MainWindow::on_anzeigen_clicked()
{
  for (const auto &b  : stud->getMeineBelegungen()){

    ui->output->setText(b->getBezeichnung());
  }
}

