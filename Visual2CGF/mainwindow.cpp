#include "mainwindow.h"
#include "optionswindow.h"
#include "Settings.h"
#include "DirIterator.h"

#include <qfiledialog.h>
#include <qmessagebox.h>


#include <Windows.h>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <boost/date_time.hpp>
namespace PT = boost::posix_time;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), m_nmgr(nullptr) {
    ui.setupUi(this);

    //Connections
    connect(ui.actionSettings, SIGNAL(triggered()), this, SLOT(showOptions()));
    connect(ui.actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui.maintype_select, SIGNAL(currentIndexChanged(int)), this, SLOT(findFltFiles(int)));
    connect(ui.model_list, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(onModelDoubleClick(QListWidgetItem*)));
    connect(ui.actionSave_console, SIGNAL(triggered()), this, SLOT(saveConsole()));
    connect(ui.btn_clear, SIGNAL(clicked()), this, SLOT(clearConsole()));

    // Locate local model dir, or connect to remote dbdev2
    Settings settings;
    std::stringstream ss;
    boost::filesystem::path p;
    m_nmgr = new NetworkManager(L"\\\\dbdev2\\Data3", L"visdbdev", L"v1sdb@ATTS");
    //Path local repository s checked out
    if ( !settings.path_to_repo().empty() ) {
        mPath = settings.path_to_repo();
        ss << "Moving models repository checked out locally at: " << mPath;
        write_msg(ConsoleMessage(ss.str()));
    }
    //dbdev2\Data3 drive is connected
    else if ( !settings.path_to_data3().empty() ) {
        mPath = settings.path_to_data3();
        ss << "Connection to \\\\dbdev2\\Data3 connected at: " << mPath;
        write_msg(ConsoleMessage(ss.str()));
    }
    // Connect to dbdev2\Data3
    else {
        m_nmgr->connect();
        switch ( m_nmgr->status() ) {
        case NO_ERROR:
            ss << "Connected to " << m_nmgr->drive();
            write_msg(ConsoleMessage(ss.str()));
            break;
        case ERROR_INVALID_FUNCTION:
            ss << "Connection to " << m_nmgr->drive() << " succeeded with errors, ERROR_INVALID_FUNCTION";
            write_msg(ConsoleMessage(ss.str(), MESSAGE_WARNING));
            break;
        case ERROR_BAD_DEVICE:
            ss << "Connection to " << m_nmgr->drive() << " failed, ERROR_BAD_DEVICE";
            write_msg(ConsoleMessage(ss.str(), MESSAGE_ERROR));
            return;
        default:
            ss << "Connection to " << m_nmgr->drive() << " failed (error code 0x" << std::hex << m_nmgr->status() << ")";
            write_msg(ConsoleMessage(ss.str(), MESSAGE_ERROR));
            return;
        }
        mPath = settings.drive_letter().toStdString();
        mPath.make_preferred();
    }

    // Parse flt files
    findFltFiles(ui.maintype_select->currentIndex());
}

MainWindow::~MainWindow() {
    delete m_nmgr;
}

void MainWindow::write_msg(const ConsoleMessage msg) {
    std::stringstream ss;
    ss << msg.time() << msg.deletimiter() << msg.text();
    QListWidgetItem *it = new QListWidgetItem(QIcon(msg.icon().c_str()), ss.str().c_str());
    messages.push_back(msg);
    ui.console->addItem(it);
    ui.console->scrollToBottom();
}

void MainWindow::findFltFiles(int type) {
    // Show mouse waiting cursor while loading files
    QApplication::setOverrideCursor(Qt::BusyCursor);

    // Clear mat and gui lists before adding any others
    ui.model_list->clear();
    models.clear();

    // Set path to correct category
    boost::filesystem::path p = mPath;
    switch ( type ) {
    case MainWindow::FixedWing:
        p.append("/AIR_MOVING_MODELS/FIXED_WING_MODELS");
        break;
    case MainWindow::LifeForm:
        p.append("/LIFEFORM");
        break;
    case MainWindow::Weapons:
        p.append("/EXTERNAL_STORE_MODELS");
        break;
    case MainWindow::RotaryWing:
        p.append("/AIR_MOVING_MODELS/HELICOPTER_MODELS");
        break;
    case MainWindow::Submersible:
        p.append("/NAVAL_MOVING_MODELS/MAN_OF_WAR/SUBMARINES");
        break;
    case MainWindow::Surface:
        p.append("/NAVAL_MOVING_MODELS");
        break;
    case MainWindow::Land:
        p.append("/LAND_MOVING_MODELS");
        break;
    default:
        return;
    }
    p.make_preferred();

    //poulate list
    std::vector < std::string > vec;
    DirIterator it;
    it.find_files(".flt", p, vec, true);
    for ( std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it ) {

        // Create Model, if opening fails, proceed to next Model, do not create list entry
        OpenFlight::Model *mm = new OpenFlight::Model(it->c_str());
        write_msg(mm->filename());

        // If Model opens successfully, make list entry
        QListWidgetItem *lwi = new QListWidgetItem(mm->filename().c_str());
        

        return;
    }

    //Reset mouse cursor
    QApplication::restoreOverrideCursor();
}

void MainWindow::showOptions() {
    OptionsWindow *o = new OptionsWindow(this);
    o->show();
}

void MainWindow::onModelDoubleClick(QListWidgetItem *item) {

}

void MainWindow::saveConsole() {
    if ( messages.empty() ) {
        QMessageBox qmb(QMessageBox::Icon::Information, "Console export", "Console is empty, nothing to export.");
        qmb.exec();
        return;
    }
    std::string file = QFileDialog::getSaveFileName(this, "Save console log", "", "Text file (*.txt);;All Files (*.*)").toStdString();
    if ( !file.empty() ) {
        file = QDir::toNativeSeparators(file.c_str()).toStdString();
    }
    else return;
    std::ofstream of(file);
    of << "Visual2CGF console log generated " << ConsoleMessage::current_time() << "." << std::endl << std::endl;
    for ( msg_list_it it = messages.begin(); it != messages.end(); ++it ) {
        switch ( it->type() ) {
        case MESSAGE_INFO:
            of << "I: ";
            break;
        case MESSAGE_WARNING:
            of << "W: ";
            break;
        case MESSAGE_ERROR:
            of << "E: ";
            break;
        default:
            of << "   ";
            break;
        }
        of << it->time() << it->deletimiter() << it->text() << std::endl;
    }
    of.close();
}

void MainWindow::clearConsole() {
    ui.console->clear();
    messages.clear();
}
