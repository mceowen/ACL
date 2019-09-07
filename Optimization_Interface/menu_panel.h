// TITLE:   Optimization_Interface/menu_panel.h
// AUTHORS: Daniel Sullivan, Miki Szmuk
// LAB:     Autonomous Controls Lab (ACL)
// LICENSE: Copyright 2018, All Rights Reserved

// Main menu panel

#ifndef MENU_PANEL_H_
#define MENU_PANEL_H_

#include <QFrame>
#include <QToolButton>
#include <QSlider>
#include <QVector>
#include <QPushButton>
#include <QGroupBox>

#include "menu_button.h"
#include "math.h"


/*
#include <QNetworkSession>
#include <QElapsedTimer>

#include "canvas.h"
#include "constraint_model.h"
#include "path_graphics_item.h"
#include "drone_graphics_item.h"
#include "waypoints_graphics_item.h"
#include "point_graphics_item.h"
#include "port_dialog.h"
#include "item_server.h"
#include "cprs.h"
#include "algorithm.h"
#include "comm.h"
 */

namespace interface {

class MenuPanel : public QFrame {
 public:
    explicit MenuPanel(QWidget *parent, Qt::WindowFlags flags = Qt::Widget);
    ~MenuPanel();
    QToolButton *close_button_;
    QWidget *menu_;
    QSlider *zoom_slider_;
    QPushButton *exec_button_;
    QPushButton *sim_button_;
//    MenuButton *freeze_button_;
    QVector<MenuButton*> *menu_buttons_;

//    QGroupBox *opt_layout;
    QLabel *opt_finaltime_label_;
    QLabel *opt_horizon_label_;
    QLabel *opt_a_max_label_;
    QLabel *opt_theta_max_label_;
    QLabel *opt_q_max_label_;
    QLabel *opt_rfrelax_label_;

    //Note: these are scaled by a number (i.e. 10) b/c they are divided by that num in view.cpp setFinaltime etc fxns
    double_t finaltime_init_ = 3*10; //SKOI changed from 5s for testing purposes
    double_t a_max_init_ = 15*1; //m/s^2
    double_t theta_max_init_ = 60*1; //deg
    double_t q_max_init_ = 0.0*1;
    double_t rfrelax_init_ = 1000/10;
//    QPushButton *opt_horizon_minus;
//    QPushButton *opt_horizon_plus;
//    QPushButton *opt_finaltime_minus;
//    QPushButton *opt_finaltime_plus;

    QSlider *opt_finaltime_slider_;
    QSlider *opt_horizon_slider_;
    QSlider *opt_a_max_slider_;
    QSlider *opt_theta_max_slider_;
    QSlider *opt_q_max_slider_;
    QSlider *opt_rfrelax_slider_;

 private:
    void initialize();
    void initializeZoomSlider();
    void initializeWaypointButton();
    void initializeEraserButton();
    void initializePlaneButton();
    void initializePolygonButton();
    void initializePointButton();
    void initializeEllipseButton();
    void initializeFlipButton();
    void initializeExecButton();
    void initializeSimButton();
    void initializeFinaltimeSlider();
    void initializeHorizonSlider();
    void initializeAmaxSlider();
    void initializeThetaMaxSlider();
    void initializeQMaxSlider();
    void initializeRfrelaxSlider();
};

}  // namespace interface

#endif  // MENU_PANEL_H_
