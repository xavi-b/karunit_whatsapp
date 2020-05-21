#include "plugin.h"

QString KU_WhatsApp_Plugin::name() const
{
    return "WhatsApp";
}

QString KU_WhatsApp_Plugin::id() const
{
    return "WhatsApp.me";
}

KU::PLUGIN::PluginVersion KU_WhatsApp_Plugin::version() const
{
    return { 1, 0, 0 };
}

QString KU_WhatsApp_Plugin::license() const
{
    return "LGPL";
}

QIcon KU_WhatsApp_Plugin::icon() const
{
    return QIcon(":/karunit_whatsapp/WhatsApp");
}

bool KU_WhatsApp_Plugin::initialize()
{
    return true;
}

bool KU_WhatsApp_Plugin::stop()
{
    return true;
}

QWidget* KU_WhatsApp_Plugin::createWidget()
{
    //QtWebEngine::initialize();
    QWebEngineView* view = new QWebEngineView;
    view->page()->profile()->setHttpUserAgent(view->page()->profile()->httpUserAgent().remove(QRegExp("QtWebEngine\\/\\S{1,} ")));
    view->setUrl(QUrl("https://web.whatsapp.com/"));
    qDebug() << view->page()->profile()->httpUserAgent();
    return view;
}

QWidget* KU_WhatsApp_Plugin::createSettingsWidget()
{
    return new QLabel("WhatsApp");
}

bool KU_WhatsApp_Plugin::loadSettings()
{
    return true;
}

bool KU_WhatsApp_Plugin::saveSettings() const
{
    return KU::Settings::instance()->status() == QSettings::NoError;
}
