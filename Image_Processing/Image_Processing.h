#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <QMainWindow>
#include <QFileDialog>
#include <QEvent>
#include <QMouseEvent>
#include <QLabel>
#include "ui_image_processing.h"

namespace Ui {
    class MainWindow;
}

class Image_Processing : public QMainWindow {
    Q_OBJECT

public:
    explicit Image_Processing(QWidget* parent = nullptr);
    ~Image_Processing();

protected:
    bool eventFilter(QObject* watched, QEvent* event) override;

private slots:
    void uploadImage(); // to open file dialog and allow upload
    

private:
    Ui::MainWindow* ui;
    QPixmap imagePixmap; // to store the uploaded image
};

#endif // IMAGE_PROCESSING_H
