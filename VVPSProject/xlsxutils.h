#ifndef XLSXUTILS_H
#define XLSXUTILS_H

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

#define DATE_FIELD          0
#define EVENT_CONTEXT_FIELD 1
#define COMPONENT_FIELD     2
#define EVENT_NAME_FIELD    3
#define DESCRIPTION_FIELD   4

using namespace QXlsx;

class XlsxUtils
{
    bool success = false;
public:
    XlsxUtils(QString filePath);
    ~XlsxUtils();
    QVector<int> getUsers();

    bool loaded();
    Document* xlsx;
};

#endif // XLSXUTILS_H
