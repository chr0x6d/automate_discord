// Small style change to make tool-tips show with less delay

#include <QProxyStyle>

class MyProxyStyle : public QProxyStyle
{
public:
    using QProxyStyle::QProxyStyle;

    int styleHint(StyleHint hint, const QStyleOption* option = nullptr, const QWidget* widget = nullptr, QStyleHintReturn* returnData = nullptr) const override
    {
        if (hint == QStyle::SH_ToolTip_WakeUpDelay)
        {
            return 300;
        }

        return QProxyStyle::styleHint(hint, option, widget, returnData);
    }
};
