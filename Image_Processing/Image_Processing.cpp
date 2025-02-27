#include "image_processing.h"
#include "ui_image_processing.h"

Image_Processing::Image_Processing(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->Widget_Org_Image->installEventFilter(this); // widget responsible for image upload
}

Image_Processing::~Image_Processing() {
    delete ui;
}

bool Image_Processing::eventFilter(QObject* watched, QEvent* event) {
    // Check if the event is from widget_3 and it's a double-click event
    if (watched == ui->Widget_Org_Image && event->type() == QEvent::MouseButtonDblClick) {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        if (mouseEvent->button() == Qt::LeftButton) {
            uploadImage();  // Call the function to upload an image
            return true;  // Mark event as handled
        }
    }
    return QMainWindow::eventFilter(watched, event);  // Pass to default event handler
}

void Image_Processing::uploadImage() {
    qDebug() << "INSIDE UPLOAD FUNCTION";
    /*ui->Widget_Org_Image->setAutoFillBackground(false);*/
    ui->Widget_Org_Image->setStyleSheet("background: transparent;");
    QString filePath = QFileDialog::getOpenFileName(
        this, "Select an Image", "", "Images (*.png *.jpg *.jpeg *.bmp *.gif)");

    if (!filePath.isEmpty()) {
        imagePixmap.load(filePath);

        // Set the background of widget_3 to the selected image
        QPalette palette;
        palette.setBrush(ui->Widget_Org_Image->backgroundRole(), QBrush(imagePixmap.scaled(
            ui->Widget_Org_Image->size(), Qt::KeepAspectRatioByExpanding, Qt::SmoothTransformation)));

        ui->Widget_Org_Image->setAutoFillBackground(true);
        ui->Widget_Org_Image->setPalette(palette);
        ui->Widget_Org_Image->update();
    }
}
