/*
 * Copyright (C) 2019 Tianjin KYLIN Information Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/&gt;.
 *
 */

#ifndef MAINVIEWWIDGET_H
#define MAINVIEWWIDGET_H

#include <QWidget>
#include <QSpacerItem>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QToolButton>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QScrollBar>
#include <QFileSystemWatcher>
#include <QSettings>
#include "src/Interface/ukuimenuinterface.h"
#include "src/AppSearch/searchresultwidget.h"
#include "src/AppSearch/searchappthread.h"
#include "../FileSearch/searchfilethread.h"
#include "src/Style/style.h"
#include "src/FileSearch/filemodel.h"
#include "src/ControlCenterSettingsSearch/settingmodel.h"
#include <QTreeView>
#include "../WebSearch/websearch.h"
#include "../FileSearch/fileview.h"
#include "../ControlCenterSettingsSearch/settingview.h"
#include "src/SearchBar/inputbox.h"
#include <QVBoxLayout>
#include <QHeaderView>
#include "../FileSearch/searchfilewidget.h"
#include "../ControlCenterSettingsSearch/settingwidget.h"
class MainViewWidget : public QWidget
{
    Q_OBJECT

    /*
     * 负责与ukui桌面环境应用通信的dbus
     * 搜索框文本改变的时候发送信号
　　　*/
    Q_CLASSINFO("D-Bus Interface", "org.ukui.search.inputbox")

public:
    explicit MainViewWidget(QWidget *parent = nullptr);
    ~MainViewWidget();
    /**
     * @brief Load the default main view
     */
    void loadMinMainView();
    /**
     * @brief Initializes the interface state
     */
    void widgetMakeZero();

    void initSearchWidget();
    void AddSearchWidget();
    void searchContent(QString searchcontent);

private:
    QVBoxLayout* mainLayout;
    UKuiSeachBarWidget *m_topWidget=nullptr;
    //顶部搜索框所在的布局
    UkuiSearchBarHLayout *m_topLayout=nullptr;

    QSpacerItem *m_verticalSpacer=nullptr;

    UKuiSearchLineEdit *m_queryLineEdit=nullptr;
    UKuiSeachBar *m_queryWid=nullptr;
    bool m_isSearching;
    QString m_searchKeyWords;

    SearchResultWidget *m_searchResultWid=nullptr;
    SearchAppThread *m_searchAppThread=nullptr;


    int m_widgetState=1;//Classification window number
    int m_saveCurrentWidState=-1;//Store the current category window number

    bool m_isFullScreen=false;
    bool m_isHiden=false;

    QSettings *m_setting=nullptr;
    QGSettings *m_gsetting=nullptr;

    SearchFileWidget *m_fileview; //文件view
    SettingWidget *m_settingview;//设置view

    filemodel *m_filemodel;//文件model



    int appNum; //记录搜索出来的APP数量

    int SettingNum;//记录搜索出来的设置数量

    websearch *search_web_page;

protected:
    /**
     * @brief Initializes UI
     */
    void initUi();
    /**
     * @brief Add a top window control
     */
    void addTopControl();
    /**
     * @brief Initializes the query box
     */
    void initQueryLineEdit();



public Q_SLOTS:
    void lineEditTextChanged(QString arg);
    /**
     * @brief Load the full screen letter classification interface
     */
    /**
     * @brief Respond to search box
     * @param arg: Search keywords
     */








Q_SIGNALS:
    /**
     * @brief Send the search keyword to the SearchAppThread
     * @param arg: Search keyword
     */
    void sendSearchKeyword(QString arg);
    void textChanged(QString arg);
};

#endif // MAINVIEWWIDGET_H
